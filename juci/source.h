#ifndef JUCI_SOURCE_H_
#define JUCI_SOURCE_H_

#include <iostream>
#include "gtkmm.h"

namespace Source {
  class View : public Gtk::TextView {
  public:
    View();
    void UpdateLine(Glib::RefPtr<Gtk::TextBuffer::Mark> mark);
  private:
    void UpdateSyntaxHighlighting(int line_number);
  };

  class Model{
  public:
    Model();
  };

  class Controller {
  public:
    Controller();
    std::shared_ptr<View> view();
    std::shared_ptr<Model> model();

  private:
    void OnLineEdit(Glib::RefPtr<Gtk::TextBuffer::Mark> mark);

  protected:
    View view_;
    Model model_;
  };  // class Controller
}  // namespace Source
#endif  // JUCI_SOURCE_H_
