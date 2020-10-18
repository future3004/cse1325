#ifndef _MAINWIN_H
#define _MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    //void on_button_click();  // delete
    
    // observable call backs
    void on_new_store_click();
    void on_new_tool_click();
    void on_new_plant_click();
    void on_new_mulch_click();
    void on_view_products_click();
    void on_quit_click();
    
  private:
    //Gtk::Button* button;  // delete
    Gtk::Label* display;
    Store* store;
    int get_int(std::string prompt);
    double get_double(std::string prompt);
    std::string get_string(std::string prompt);
};


#endif
