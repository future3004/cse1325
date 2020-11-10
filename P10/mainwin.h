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
    void on_new_store_click(bool untitled = false); 
    void on_new_tool_click();
    void on_new_plant_click();
    void on_new_mulch_click();
    void on_view_products_click();
    void on_view_customers_click();
    
    void on_new_customer_click();
    
    void on_save_click();
    void on_save_as_click();
    void on_open_click();
    void on_about_click();
    void on_quit_click();
    
    void on_new_order_click();
    void on_view_orders_click();
    
  private:
    Gtk::Label* display;
    Store* store;
    std::string filename;


    int get_int(std::string value);
    double get_double(std::string value);
    std::string get_string(std::string value);

    Material get_material(int val);
    Exposure get_exposure(int val);
};


#endif
