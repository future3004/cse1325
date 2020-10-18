#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin() {
  set_default_size(500, 350);
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
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
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
    menuitem_tool->signal_activate().connect([this] {this->on_new_tool_click();});
    insertmenu->append(*menuitem_tool);
    
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
    menuitem_plant->signal_activate().connect([this] {this->on_new_plant_click();});
    insertmenu->append(*menuitem_plant);
    
    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
    insertmenu->append(*menuitem_mulch);
    
    
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    
//     Add a new store
//    new_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
//    new_store_button->set_tooltip_markup("Create a new store");
//    new_store_button->signal_clicked().connect([this] {this->on_new_store_click();});
//    toolbar->append(*new_store_button);
    
    //     VIEW CATALOGUE
    Gtk::Image* button2_image = Gtk::manage(new Gtk::Image{"cat.png"});
    catalogue_button = Gtk::manage(new Gtk::ToolButton(*button2_image));
    catalogue_button->set_tooltip_markup("View all the products");
    catalogue_button->signal_clicked().connect([this] {this->on_view_products_click();});
    toolbar->append(*catalogue_button);
    
    // message label display
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->pack_start(*display, Gtk::PACK_SHRINK, 0);
    
    
    // Make the box and everything in it visible
    vbox->show_all();
    
    
    // create new store
    on_new_store_click();
}

Mainwin::~Mainwin() { }

void Mainwin::on_new_store_click(){
  //Store::Store store{"Mavs Arboreta"};
  //Store my_store{"MavsArboreta"};
  store = new Store{"MavsArboreta"};
  
} 

void Mainwin::on_new_tool_click(){
  EntryDialog tdialog{*this, "<big>Tool Values</big>", true};
    tdialog.set_secondary_text("<b>Tool Name</b>:", true);
    tdialog.set_text("enter tool name..");
    tdialog.run();
    
    //price
    EntryDialog pdialog{*this, "<big>Tool Values</big>", true};
    pdialog.set_secondary_text("<b>Tool Price</b>:", true);
    pdialog.set_text("enter tool price..");
    pdialog.run();
    
    //description
    EntryDialog cdialog{*this, "<big>Tool Values</big>", true};
    cdialog.set_secondary_text("<b>Tool Description</b>:", true);
    cdialog.set_text("tool description..");
    cdialog.run();

    //Gtk::MessageDialog mdialog{*this, tdialog.get_text() + pdialog.get_text()
    //+ cdialog.get_text()};
    //mdialog.run();
}
void Mainwin::on_new_plant_click(){
  EntryDialog ndialog{*this, "<big>Plant Values</big>", true};
    ndialog.set_secondary_text("<b>Plant Name</b>:", true);
    ndialog.set_text("enter plant name...");
    ndialog.run();
    
    //price
    EntryDialog pdialog{*this, "<big>Plant Values</big>", true};
    pdialog.set_secondary_text("<b>Plant Price</b>:", true);
    pdialog.set_text("enter plant price..");
    pdialog.run();
    
    //description
    EntryDialog cdialog{*this, "<big>Plant Values</big>", true};
    cdialog.set_secondary_text("<b>Plant Description</b>:", true);
    cdialog.set_text("plant description..");
    cdialog.run();
    
    //get species
    EntryDialog sdialog{*this, "<big>Plant Values</big>", true};
    sdialog.set_secondary_text("<b>Plant Species</b>:", true);
    sdialog.set_text("plant species..");
    sdialog.run();
    
    // get exposure
    EntryDialog edialog{*this, "<big>Plant Values</big>", true};
    edialog.set_secondary_text("<b>Exposure type:</b>:", true);
    edialog.set_text("exposure..");
    edialog.run();

    //Gtk::MessageDialog mdialog{*this, edialog.get_text()};
    //mdialog.run();
}
void Mainwin::on_new_mulch_click(){
  EntryDialog ndialog{*this, "<big>Mulch Values</big>", true};
    ndialog.set_secondary_text("<b>Mulch Name</b>:", true);
    ndialog.set_text("enter mulch name...");
    ndialog.run();
    
     //price
    EntryDialog pdialog{*this, "<big>Mulch Values</big>", true};
    pdialog.set_secondary_text("<b>Mulch Price</b>:", true);
    pdialog.set_text("enter mulch price..");
    pdialog.run();
    
    //description
    EntryDialog cdialog{*this, "<big>Mulch Values</big>", true};
    cdialog.set_secondary_text("<b>Mulch Description</b>:", true);
    cdialog.set_text("mulch description..");
    cdialog.run();
    
    //get volume
    EntryDialog vdialog{*this, "<big>Mulch Values</big>", true};
    vdialog.set_secondary_text("<b>Mulch Volume</b>:", true);
    vdialog.set_text("mulch volume..");
    vdialog.run();
    
    //get material type
    EntryDialog mdialog{*this, "<big>Mulch Values</big>", true};
    mdialog.set_secondary_text("<b>Mulch Material</b>:", true);
    mdialog.set_text("mulch material..");
    mdialog.run();

   // Gtk::MessageDialog mdialog{*this, edialog.get_text()};
   // mdialog.run();
}
void Mainwin::on_view_products_click(){
  //Gtk::MessageDialog mdialog{*this, "Need to show all products added"};
    //mdialog.run();
    Glib::ustring s = "Need to show all products added";
    display->set_markup(s);
}
void Mainwin::on_quit_click(){close();}

/*void Mainwin::on_button_click() {
    EntryDialog edialog{*this, "<big>Enter Values</big>", true};
    edialog.set_secondary_text("<b>Tool Name</b>:", true);
    edialog.set_text("enter tool name...");
    edialog.run();

    Gtk::MessageDialog mdialog{*this, edialog.get_text()};
    mdialog.run();
    
}*/



