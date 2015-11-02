#include <string>

#define JUCI_VERSION "0.9.4"

#define JUCI_ENV_SEARCH_LOCATIONS {"AppData", "HOME", "JUCI_HOME"}

const std::string configjson =
"{\n"
"    \"version\": \""+std::string(JUCI_VERSION)+"\",\n"
"    \"default_window_size\": {\n"
"        \"width\": 600,\n"
"        \"height\": 400\n"
"    },\n"
"    \"terminal_history_size\": 1000,\n"
"    \"gtk_theme\": {\n"
"        \"name_comment\": \"Use \\\"\\\" for default theme, At least these two exist on all systems: Adwaita, Raleigh\",\n"
"        \"name\": \"Adwaita\",\n"
"        \"variant_comment\": \"Use \\\"\\\" for default variant, and \\\"dark\\\" for dark theme variant\",\n"
"        \"variant\": \"\"\n"
"    },\n"
"    \"source\": {\n"
"        \"style_comment\": \"Use \\\"\\\" for default style, and for instance juci-dark or juci-dark-blue together with dark gtk_theme variant. Styles from normal gtksourceview install: classic, cobalt, kate, oblivion, solarized-dark, solarized-light, tango\",\n"
"        \"style\": \"juci-light\",\n"
"        \"font_comment\": \"Use \\\"\\\" for default font, and for instance \\\"Monospace 12\\\" to also set size\",\n"
#ifdef __APPLE__
"        \"font\": \"Menlo 11\",\n"
#else
#ifdef _WIN32
"        \"font\": \"Consolas\",\n"
#else
"        \"font\": \"Monospace\",\n"
#endif
#endif
"        \"show_map\": true,\n"
"        \"map_font_size\": \"1\",\n"
"        \"spellcheck_language_comment\": \"Use \\\"\\\" to set language from your locale settings\",\n"
"        \"spellcheck_language\": \"en_US\",\n"
"        \"auto_tab_char_and_size_comment\": \"Use false to always use default tab char and size\",\n"
"        \"auto_tab_char_and_size\": true,\n"
"        \"default_tab_char_comment\": \"Use \\\"\\t\\\" for regular tab\",\n"
"        \"default_tab_char\": \" \",\n"
"        \"default_tab_size\": 2,\n"
"        \"wrap_lines\": false,\n"
"        \"highlight_current_line\": true,\n"
"        \"show_line_numbers\": true,\n"
"        \"clang_types\": {\n"
"            \"8\": \"def:function\",\n"
"            \"21\": \"def:function\",\n"
"            \"22\": \"def:identifier\",\n"
"            \"24\": \"def:function\",\n"
"            \"25\": \"def:function\",\n"
"            \"43\": \"def:type\",\n"
"            \"44\": \"def:type\",\n"
"            \"45\": \"def:type\",\n"
"            \"46\": \"def:identifier\",\n"
"            \"109\": \"def:string\",\n"
"            \"702\": \"def:statement\",\n"
"            \"705\": \"def:comment\"\n"
"        },\n"
"        \"clang_format_style_comment\": \"IndentWidth, AccessModifierOffset and UseTab are set automatically. See http://clang.llvm.org/docs/ClangFormatStyleOptions.html\",\n"
"        \"clang_format_style\": \"ColumnLimit: 0, MaxEmptyLinesToKeep: 2\"\n"
"    },\n"
"    \"keybindings\": {\n"
"        \"preferences\": \"<primary>comma\",\n"
"        \"quit\": \"<primary>q\",\n"
"        \"new_file\": \"<primary>n\",\n"
"        \"new_folder\": \"<primary><shift>n\",\n"
"        \"open_file\": \"<primary>o\",\n"
"        \"open_folder\": \"<primary><shift>o\",\n"
"        \"save\": \"<primary>s\",\n"
"        \"save_as\": \"<primary><shift>s\",\n"
"        \"edit_undo\": \"<primary>z\",\n"
"        \"edit_redo\": \"<primary><shift>z\",\n"
"        \"edit_cut\": \"<primary>x\",\n"
"        \"edit_copy\": \"<primary>c\",\n"
"        \"edit_paste\": \"<primary>v\",\n"
"        \"edit_find\": \"<primary>f\",\n"
"        \"edit_set_tab\": \"\",\n"
"        \"source_spellcheck\": \"\",\n"
"        \"source_spellcheck_clear\": \"\",\n"
"        \"source_spellcheck_next_error\": \"<primary><shift>e\",\n"
"        \"source_indentation_set_buffer_tab\": \"\",\n"
"        \"source_indentation_auto_indent_buffer\": \"<primary><shift>i\",\n"
"        \"source_goto_line\": \"<primary>g\",\n"
"        \"source_center_cursor\": \"<primary>l\",\n"
"        \"source_find_documentation\": \"<primary><shift>d\",\n"
"        \"source_goto_declaration\": \"<primary>d\",\n"
"        \"source_goto_method\": \"<primary>m\",\n"
"        \"source_rename\": \"<primary>r\",\n"
"        \"source_goto_next_diagnostic\": \"<primary>e\",\n"
"        \"source_apply_fix_its\": \"<control>space\",\n"
"        \"compile_and_run\": \"<primary>Return\",\n"
"        \"compile\": \"<primary><shift>Return\",\n"
"        \"run_command\": \"<alt>Return\",\n"
"        \"kill_last_running\": \"<primary>Escape\",\n"
"        \"force_kill_last_running\": \"<primary><shift>Escape\",\n"
"        \"next_tab\": \"<primary><alt>Right\",\n"
"        \"previous_tab\": \"<primary><alt>Left\",\n"
"        \"close_tab\": \"<primary>w\"\n"
"    },\n"
"    \"project\": {\n"
#ifdef _WIN32
"        \"cmake_command\": \"cmake -G\\\"MSYS Makefiles\\\"\",\n"
#else
"        \"cmake_command\": \"cmake\",\n"
#endif
"        \"make_command\": \"make\"\n"
"    },\n"
"    \"documentation_searches\": {\n"
"        \"clang\": {\n"
"            \"separator\": \"::\",\n"
"            \"queries\": {\n"
"                \"@empty\": \"https://www.google.com/search?btnI&q=c%2B%2B+\",\n"
"                \"std\": \"https://www.google.com/search?btnI&q=site:http://www.cplusplus.com/reference/+\",\n"
"                \"boost\": \"https://www.google.com/search?btnI&q=site:http://www.boost.org/doc/libs/1_59_0/+\",\n"
"                \"Gtk\": \"https://www.google.com/search?btnI&q=site:https://developer.gnome.org/gtkmm/stable/+\",\n"
"                \"@any\": \"https://www.google.com/search?btnI&q=\"\n"
"            }\n"
"        }\n"
"    },\n"
"    \"directoryfilter\": {\n"
"        \"ignore\": [\n"
"        ],\n"
"        \"exceptions\": [\n"
"        ]\n"
"    }\n"
"}\n";

const std::string juci_light_style =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"\n"
"<style-scheme id=\"juci-light\" _name=\"juci\" version=\"1.0\">\n"
"  <author>juCi++ team</author>\n"
"  <_description>Default juCi++ style</_description>\n"
"\n"
"  <!-- Palette -->\n"
"  <color name=\"white\"                       value=\"#FFFFFF\"/>\n"
"  <color name=\"black\"                       value=\"#000000\"/>\n"
"  <color name=\"gray\"                        value=\"#888888\"/>\n"
"  <color name=\"red\"                         value=\"#CC0000\"/>\n"
"  <color name=\"green\"                       value=\"#008800\"/>\n"
"  <color name=\"blue\"                        value=\"#0000FF\"/>\n"
"  <color name=\"dark-blue\"                   value=\"#002299\"/>\n"
"  <color name=\"yellow\"                      value=\"#FFFF00\"/>\n"
"  <color name=\"light-yellow\"                value=\"#FFFF88\"/>\n"
"  <color name=\"orange\"                      value=\"#FF8800\"/>\n"
"  <color name=\"purple\"                      value=\"#990099\"/>\n"
"\n"
"  <style name=\"text\"                        foreground=\"#000000\" background=\"#FFFFFF\"/>\n"
"  <style name=\"background-pattern\"          background=\"#rgba(0,0,0,.03)\"/>\n"
"  <style name=\"selection\"                   background=\"#4A90D9\"/>\n"
"\n"
"  <!-- Current Line Highlighting -->\n"
"  <style name=\"current-line\"                background=\"#rgba(0,0,0,.07)\"/>\n"
"\n"
"  <!-- Bracket Matching -->\n"
"  <style name=\"bracket-match\"               foreground=\"white\" background=\"gray\" bold=\"true\"/>\n"
"  <style name=\"bracket-mismatch\"            foreground=\"white\" background=\"#FF0000\" bold=\"true\"/>\n"
"\n"
"  <!-- Search Matching -->\n"
"  <style name=\"search-match\"                background=\"yellow\"/>\n"
"\n"
"  <!-- Language specifics -->\n"
"  <style name=\"def:builtin\"                 foreground=\"blue\"/>\n"
"  <style name=\"def:constant\"                foreground=\"blue\"/>\n"
"  <style name=\"def:boolean\"                 foreground=\"red\"/>\n"
"  <style name=\"def:decimal\"                 foreground=\"red\"/>\n"
"  <style name=\"def:base-n-integer\"          foreground=\"red\"/>\n"
"  <style name=\"def:floating-point\"          foreground=\"red\"/>\n"
"  <style name=\"def:complex\"                 foreground=\"red\"/>\n"
"  <style name=\"def:character\"               foreground=\"red\"/>\n"
"  <style name=\"def:special-char\"            foreground=\"red\"/>\n"
"\n\n"
"  <!-- Language specifics used by clang-parser in default config -->\n"
"  <style name=\"def:string\"                  foreground=\"red\"/>\n"
"  <style name=\"def:comment\"                 foreground=\"gray\"/>\n"
"  <style name=\"def:statement\"               foreground=\"blue\"/>\n"
"  <style name=\"def:type\"                    foreground=\"blue\"/>\n"
"  <style name=\"def:function\"                foreground=\"dark-blue\"/>\n"
"  <style name=\"def:identifier\"              foreground=\"purple\"/>\n"
"  <style name=\"def:preprocessor\"            foreground=\"green\"/>\n"
"  <style name=\"def:error\"                   foreground=\"red\"/>\n"
"  <style name=\"def:warning\"                 foreground=\"orange\"/>\n"
"  <style name=\"def:note\"                    foreground=\"black\" background=\"light-yellow\"/>\n"
"\n"
"</style-scheme>\n";

const std::string juci_dark_style =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"\n"
"<style-scheme id=\"juci-dark\" _name=\"juci\" version=\"1.0\">\n"
"  <author>juCi++ team</author>\n"
"  <_description>Dark juCi++ style</_description>\n"
"\n"
"  <!-- Palette -->\n"
"  <color name=\"white\"                       value=\"#CCCCCC\"/>\n"
"  <color name=\"black\"                       value=\"#292929\"/>\n"
"  <color name=\"gray\"                        value=\"#888888\"/>\n"
"  <color name=\"red\"                         value=\"#FF9999\"/>\n"
"  <color name=\"green\"                       value=\"#AACC99\"/>\n"
"  <color name=\"blue\"                        value=\"#9090FF\"/>\n"
"  <color name=\"light-blue\"                  value=\"#AAAAFF\"/>\n"
"  <color name=\"purple\"                      value=\"#DD88DD\"/>\n"
"\n"
"  <style name=\"text\"                        foreground=\"white\" background=\"black\"/>\n"
"  <style name=\"background-pattern\"          background=\"#rgba(255,255,255,.04)\"/>\n"
"  <style name=\"selection\"                   background=\"#215D9C\"/>\n"
"\n"
"  <!-- Current Line Highlighting -->\n"
"  <style name=\"current-line\"                background=\"#rgba(255,255,255,.06)\"/>\n"
"\n"
"  <!-- Bracket Matching -->\n"
"  <style name=\"bracket-match\"               foreground=\"black\" background=\"gray\" bold=\"true\"/>\n"
"  <style name=\"bracket-mismatch\"            foreground=\"black\" background=\"#FF0000\" bold=\"true\"/>\n"
"\n"
"  <!-- Search Matching -->\n"
"  <style name=\"search-match\"                foreground=\"black\" background=\"white\"/>\n"
"\n"
"  <!-- Language specifics -->\n"
"  <style name=\"def:builtin\"                 foreground=\"blue\"/>\n"
"  <style name=\"def:constant\"                foreground=\"blue\"/>\n"
"  <style name=\"def:boolean\"                 foreground=\"red\"/>\n"
"  <style name=\"def:decimal\"                 foreground=\"red\"/>\n"
"  <style name=\"def:base-n-integer\"          foreground=\"red\"/>\n"
"  <style name=\"def:floating-point\"          foreground=\"red\"/>\n"
"  <style name=\"def:complex\"                 foreground=\"red\"/>\n"
"  <style name=\"def:character\"               foreground=\"red\"/>\n"
"  <style name=\"def:special-char\"            foreground=\"red\"/>\n"
"\n\n"
"  <!-- Language specifics used by clang-parser in default config -->\n"
"  <style name=\"def:string\"                  foreground=\"red\"/>\n"
"  <style name=\"def:comment\"                 foreground=\"gray\"/>\n"
"  <style name=\"def:statement\"               foreground=\"blue\"/>\n"
"  <style name=\"def:type\"                    foreground=\"blue\"/>\n"
"  <style name=\"def:function\"                foreground=\"light-blue\"/>\n"
"  <style name=\"def:identifier\"              foreground=\"purple\"/>\n"
"  <style name=\"def:preprocessor\"            foreground=\"green\"/>\n"
"  <style name=\"def:error\"                   foreground=\"#FF6666\"/>\n"
"  <style name=\"def:warning\"                 foreground=\"#FFE100\"/>\n"
"  <style name=\"def:note\"                    foreground=\"white\" background=\"#444444\"/>\n"
"\n"
"</style-scheme>\n";

const std::string juci_dark_blue_style =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"\n"
"<style-scheme id=\"juci-dark-blue\" _name=\"juci\" version=\"1.0\">\n"
"  <author>juCi++ team</author>\n"
"  <_description>Dark blue juCi++ style based on the Emacs deeper blue theme</_description>\n"
"\n"
"  <!-- Palette -->\n"
"  <color name=\"white\"                       value=\"#D6D6D6\"/>\n"
"  <color name=\"dark-blue\"                   value=\"#202233\"/>\n"
"  <color name=\"gray\"                        value=\"#919191\"/>\n"
"  <color name=\"red\"                         value=\"#FF7777\"/>\n"
"  <color name=\"yellow\"                      value=\"#FFE100\"/>\n"
"  <color name=\"light-yellow\"                value=\"#EAC595\"/>\n"
"  <color name=\"light-blue\"                  value=\"#00CCFF\"/>\n"
"  <color name=\"green\"                       value=\"#14ECA8\"/>\n"
"  <color name=\"blue\"                        value=\"#282A40\"/>\n"
"  <color name=\"orange\"                      value=\"#FF8800\"/>\n"
"  <color name=\"light-green\"                 value=\"#A0DB6B\"/>\n"
"\n"
"  <style name=\"text\"                        foreground=\"white\" background=\"dark-blue\"/>\n"
"  <style name=\"background-pattern\"          background=\"#rgba(255,255,255,.04)\"/>\n"
"  <style name=\"selection\"                   background=\"#215D9C\"/>\n"
"\n"
"  <!-- Current Line Highlighting -->\n"
"  <style name=\"current-line\"                background=\"#rgba(255,255,255,.05)\"/>\n"
"\n"
"  <!-- Bracket Matching -->\n"
"  <style name=\"bracket-match\"               foreground=\"dark-blue\" background=\"gray\" bold=\"true\"/>\n"
"  <style name=\"bracket-mismatch\"            foreground=\"dark-blue\" background=\"#FF0000\" bold=\"true\"/>\n"
"\n"
"  <!-- Search Matching -->\n"
"  <style name=\"search-match\"                foreground=\"dark-blue\" background=\"white\"/>\n"
"\n"
"  <!-- Language specifics -->\n"
"  <style name=\"def:builtin\"                 foreground=\"light-blue\"/>\n"
"  <style name=\"def:constant\"                foreground=\"light-blue\"/>\n"
"  <style name=\"def:boolean\"                 foreground=\"light-yellow\"/>\n"
"  <style name=\"def:decimal\"                 foreground=\"light-yellow\"/>\n"
"  <style name=\"def:base-n-integer\"          foreground=\"light-yellow\"/>\n"
"  <style name=\"def:floating-point\"          foreground=\"light-yellow\"/>\n"
"  <style name=\"def:complex\"                 foreground=\"light-yellow\"/>\n"
"  <style name=\"def:character\"               foreground=\"light-yellow\"/>\n"
"  <style name=\"def:special-char\"            foreground=\"light-yellow\"/>\n"
"\n\n"
"  <!-- Language specifics used by clang-parser in default config -->\n"
"  <style name=\"def:string\"                  foreground=\"light-yellow\"/>\n"
"  <style name=\"def:comment\"                 foreground=\"gray\"/>\n"
"  <style name=\"def:statement\"               foreground=\"light-blue\"/>\n"
"  <style name=\"def:type\"                    foreground=\"light-blue\"/>\n"
"  <style name=\"def:function\"                foreground=\"green\"/>\n"
"  <style name=\"def:identifier\"              foreground=\"light-green\"/>\n"
"  <style name=\"def:preprocessor\"            foreground=\"yellow\"/>\n"
"  <style name=\"def:error\"                   foreground=\"red\"/>\n"
"  <style name=\"def:warning\"                 foreground=\"yellow\"/>\n"
"  <style name=\"def:note\"                    foreground=\"white\" background=\"#404466\"/>\n"
"\n"
"</style-scheme>\n";

const std::string pluginspy =
"#!/usr/bin/python \n"
"import juci_to_python_api as juci \n"
"import glob \n"
"\n"
"def loadplugins(): \n"
"    plugin_files = glob.glob(\"../plugins/*.py\") \n"
"    for current_file in plugin_files: \n"
"        juci.initPlugin(current_file) \n"
"loadplugins() \n";

const std::string snippetpy =
"#!/usr/bin/python \n"
"#snippet plugin \n"
"import juci_to_python_api as juci, inspect \n"
" \n"
"def initPlugin(): \n"
"    juci.addMenuElement(\"Snippet\") \n"
"    juci.addSubMenuElement(\"SnippetMenu\", #name of parent menu \n"
"                           \"Insert snippet\", #menu description \n"
"                           \"insertSnippet()\", #function to execute \n"
"                           inspect.getfile(inspect.currentframe()), #plugin path \n"
"                           \"<control><alt>space\") \n"
"snippets = {} \n"
" \n"
"snippets[\"for\"] = \"\"\"\\\n"
"for(int i=0; i<v.size(); i++) { \n"
"  // std::cout << v[i] << std::endl; \n"
"  // Write code here \n"
"} \n"
"\"\"\" \n"
" \n"
"snippets[\"if\"] = \"\"\"\\\n"
"if(true) { \n"
"    // Write code here \n"
"} \n"
"\"\"\" \n"
" \n"
"snippets[\"ifelse\"] = \"\"\"\\\n"
"if(false) { \n"
"    // Write code here \n"
"} else { \n"
"    // Write code here \n"
"} \n"
"\"\"\" \n"
" \n"
"snippets[\"while\"] = \"\"\"\\\n"
"while(condition) { \n"
"    // Write code here \n"
"} \n"
"\"\"\" \n"
" \n"
"snippets[\"main\"] = \"\"\"\\\n"
"int main(int argc, char *argv[]) { \n"
"    //Do something \n"
"} \n"
"\"\"\" \n"
" \n"
"snippets[\"hello\"] = \"\"\"\\\n"
"#include <iostream> \n"
" \n"
"int main(int argc, char *argv[]) { \n"
"    std::cout << \"Hello, world! << std::endl; \n"
"} \n"
"\"\"\" \n"
" \n"
"def getSnippet(word):     \n"
"    try: \n"
"        output = snippets[word] \n"
"    except KeyError: \n"
"        output = word \n"
"    return output \n"
" \n"
"def insertSnippet(): \n"
"    theWord=juci.getWord() \n"
"    output=getSnippet(theWord) \n"
"    juci.replaceWord(output) \n";


