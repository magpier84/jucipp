#include "python_interpreter.h"
#include "notebook.h"
#include "config.h"
#include <iostream>
#include <pygobject.h>
#include "menu.h"
#include "directories.h"

inline pybind11::module pyobject_from_gobj(gpointer ptr){
  auto obj=G_OBJECT(ptr);
  if(obj)
    return pybind11::module(pygobject_new(obj), false);
  return pybind11::module(Py_None, false);
}

Python::Interpreter::Interpreter(){
#ifdef _WIN32
  auto root_path=Config::get().terminal.msys2_mingw_path;
  append_path(root_path/"include/python3.5m");
  append_path(root_path/"lib/python3.5");
  long long unsigned size = 0L;
#else
  long unsigned size = 0L;
#endif
  auto init_juci_api=[](){
    pybind11::module(pygobject_init(-1,-1,-1),false);
    pybind11::module api("jucpp","Python bindings for juCi++");
    api.def("get_juci_home",[](){return Config::get().juci_home_path().string();})
    .def("get_plugin_folder",[](){return Config::get().python.plugin_directory;})
    .def("get_current_gtk_source_view",[](){
      auto view=Notebook::get().get_current_view();
      if(view)
        return pyobject_from_gobj(view->gobj());
      return pybind11::module(Py_None,false);
    })
    .def("get_gio_plugin_menu",[](){
      auto &plugin_menu=Menu::get().plugin_menu;
      if(!plugin_menu){
        plugin_menu=Gio::Menu::create();
        plugin_menu->append("<empty>");
        Menu::get().window_menu->append_submenu("_Plugins",plugin_menu);
      }
      return pyobject_from_gobj(plugin_menu->gobj());
    })
    .def("get_gio_window_menu",[](){return pyobject_from_gobj(Menu::get().window_menu->gobj());})
    .def("get_gio_juci_menu",[](){return pyobject_from_gobj(Menu::get().juci_menu->gobj());})
    .def("get_gtk_notebook",[](){return pyobject_from_gobj(Notebook::get().gobj());})
    .def_submodule("terminal")
      .def("get_gtk_text_view",[](){return pyobject_from_gobj(Terminal::get().gobj());})
      .def("println", [](const std::string &message){ Terminal::get().print(message +"\n"); });
    api.def_submodule("directories")
    .def("get_gtk_treeview",[](){return pyobject_from_gobj(Directories::get().gobj());})
    .def("open",[](const std::string &directory){Directories::get().open(directory);})
    .def("update",[](){Directories::get().update();});
    return api.ptr();
  };
  PyImport_AppendInittab("jucipp", init_juci_api);
  Config::get().load();
  auto plugin_path=Config::get().python.plugin_directory;
  add_path(Config::get().python.site_packages);
  add_path(plugin_path);
  Py_Initialize();
  argv=Py_DecodeLocale("",&size);
  PySys_SetArgv(0,&argv);
  boost::filesystem::directory_iterator end_it;
  for(boost::filesystem::directory_iterator it(plugin_path);it!=end_it;it++){
    auto module_name=it->path().stem().string();
    if(module_name!="__pycache__"){
      auto module=import(module_name);
      if(!module){
        auto err=std::string(Error());
        auto msg="Error loading plugin "+module_name+":\n";
        Terminal::get().print(msg,true);
        Terminal::get().print(err+"\n");
      }
    }
  }
}

pybind11::module Python::get_loaded_module(const std::string &module_name){
  return pybind11::module(PyImport_AddModule(module_name.c_str()), true);
}

pybind11::module Python::import(const std::string &module_name){
  return pybind11::module(PyImport_ImportModule(module_name.c_str()), false);
}

pybind11::module Python::reload(pybind11::module &module){
  return pybind11::module(PyImport_ReloadModule(module.ptr()),false);
}

void Python::Interpreter::add_path(const boost::filesystem::path &path){
  if(path.empty())
    return;
  std::wstring sys_path(Py_GetPath());
  if(!sys_path.empty())
#ifdef _WIN32
    sys_path += ';';
#else
    sys_path += ':';
#endif
  sys_path += path.generic_wstring();
  Py_SetPath(sys_path.c_str());
}

Python::Interpreter::~Interpreter(){
  auto err=Error();
  if(Py_IsInitialized())
    Py_Finalize();
  if(err)
    std::cerr << std::string(err) << std::endl;
}

pybind11::object Python::error_occured(){
  return pybind11::object(PyErr_Occurred(),true);
}

bool Python::thrown_exception_matches(Error::Type type){
  pybind11::object compare;
  switch(type){
    case Error::Type::Syntax : compare=pybind11::object(PyExc_SyntaxError,false);
    case Error::Type::Attribute : compare=pybind11::object(PyExc_AttributeError,false);
    case Error::Type::Import : compare=pybind11::object(PyExc_ImportError,false);
  }
  return PyErr_GivenExceptionMatches(Python::error_occured().ptr(), compare.ptr());
}

Python::Error::Error(){
  if(error_occured()){
    try{
      PyErr_Fetch(&exp.ptr(),&val.ptr(),&trace.ptr());
      PyErr_NormalizeException(&exp.ptr(),&val.ptr(),&trace.ptr());
    }catch(const std::exception &e) {
      Terminal::get().print(e.what());
    }
  }
}

Python::Error::operator std::string(){
  return std::string(exp.str())+"\n"+std::string(val.str())+"\n";
}

Python::SyntaxError::SyntaxError():Error(){
  if(val){
    _Py_IDENTIFIER(msg);
    _Py_IDENTIFIER(lineno);
    _Py_IDENTIFIER(offset);
    _Py_IDENTIFIER(text);
    exp=std::string(pybind11::str(_PyObject_GetAttrId(val.ptr(),&PyId_msg),false));
    text=std::string(pybind11::str(_PyObject_GetAttrId(val.ptr(),&PyId_text),false));
    pybind11::object py_line_number(_PyObject_GetAttrId(val.ptr(),&PyId_lineno),false);
    pybind11::object py_line_offset(_PyObject_GetAttrId(val.ptr(),&PyId_offset),false);
    line_number=pybind11::cast<int>(py_line_number);
    line_offset=pybind11::cast<int>(py_line_offset);
  }
}

Python::SyntaxError::operator std::string(){
  return exp+" ("+std::to_string(line_number)+":"+std::to_string(line_offset)+"):\n"+text;
}

Python::Error::operator bool(){
  return exp;
}
