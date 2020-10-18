#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin() {
  set_default_size(400, 200);
  set_title("Sprint 07");
  //add(*button);
  //button->signal_clicked().connect([this] {this->on_button_click();});
  //button->show();
  Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
  add(*vbox);
  
  // Menu
  Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
  vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
  
  //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    //menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
    
    //         Insert
    // Append insert to menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    //menuitem_new->signal_activate().connect([this] {this->on_new_game_click();});
    menubar->append(*menuitem_insert);
    // append tool, plant, mulch to insert
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);
    
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
    insertmenu->append(*menuitem_tool);
    
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
    insertmenu->append(*menuitem_plant);
    
    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    insertmenu->append(*menuitem_mulch);
    
//    // T O O L B A R
//    // Add a toolbar to the vertical box below the menu
//    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
//    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
//    
//    //     VIEW CATALOGUE
//    //Gtk::Image* button2_image = Gtk::manage(new Gtk::Image{"button2.png"});
//    //button2 = Gtk::manage(new Gtk::ToolButton(*button2_image));
//    Gtk::ToolButton *view_catalogue_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
//    view_catalogue_button->set_tooltip_markup("View all the products");
//    //view_catalogue_button->signal_clicked().connect([this] {this->on_new_game_click();});
//    toolbar->append(*view_catalogue_button);
    
    
    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

/*void Mainwin::on_button_click() {
    EntryDialog edialog{*this, "<big>Enter Values</big>", true};
    edialog.set_secondary_text("<b>Tool Name</b>:", true);
    edialog.set_text("enter tool name...");
    edialog.run();

    Gtk::MessageDialog mdialog{*this, edialog.get_text()};
    mdialog.run();
}*/
