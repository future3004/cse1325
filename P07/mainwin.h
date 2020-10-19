#ifndef _MAINWIN_H
#define _MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    // observable call backs
    void on_new_store_click(); // implement later
    void on_new_tool_click();
    void on_new_plant_click();
    void on_new_mulch_click();
    void on_view_products_click();
    void on_quit_click();
    
  private:
    Gtk::ToolButton* catalogue_button; 
    //Gtk::ToolButton *new_store_button;
    Gtk::Label* display;
    Store* store;

    int get_int(std::string value);
    double get_double(std::string value);
    std::string get_string(std::string value);
    Material get_material(int val);
    Exposure get_exposure(int val);
};


#endif
