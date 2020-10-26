#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin(): store{nullptr}, filename{"Untitled"} {
  set_default_size(500, 350);
  set_title("Sprint 08");
 
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
    
    //         NEW STORE
    // Append to the File menu
    Gtk::MenuItem *menuitem_store = Gtk::manage(new Gtk::MenuItem("_New Store", true));
    menuitem_store->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_store);
    //         SAVE AS
    // Append to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save As", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save); 
    //         OPEN
    // Append to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);
    
    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
    
    //         INSERT
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
    
    // append help to menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);
    Gtk::MenuItem *subitem_help = Gtk::manage(new Gtk::MenuItem("_About", true));
    subitem_help->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*subitem_help);
    
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
 
    // message label display
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    //vbox->pack_start(*display, Gtk::PACK_SHRINK, 0);
    vbox->add(*display);
    
    
    // Make the box and everything in it visible
    vbox->show_all();
    
    
    // create new store
    //on_new_store_click();
}

Mainwin::~Mainwin() { }

void Mainwin::on_new_store_click(){
  std::string store_name;
  delete store;
  //Store my_store{"MavsArboreta"};
   EntryDialog edialog(*this, "<big>New Store</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    edialog.set_secondary_text("Store name?", true);
    if(edialog.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    store_name = edialog.get_text();
  //store_name = get_string("New store name?");
  store = new Store{store_name};
  on_view_products_click();
  
} 

void Mainwin::on_new_tool_click(){
   // tool values
   std::string name; 
   double price; 
   std::string description;
   
   try {
        name = get_string("Name?");
        price = get_double("Price?");
        description = get_string("Description?");
        store->add_product(*(new Tool{name, price, description}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
    
    // add tool to store
    //Tool tool{name, price, description};
    //store->add_product(tool);
}
void Mainwin::on_new_plant_click(){
    // plant values
    std::string name;
    double price;
    std::string description;
    std::string species;
    Exposure exposure;
    
    try {
        name = get_string("Name?");
        price = get_double("Price?");
        description = get_string("Description?");
        species = get_string("Species?");
        double d = get_double("Exposure? (1) Shade (2) Part Sun (3) Sun");
        exposure = (d==1.0) ? Exposure::SHADE : ((d==3.0) ? Exposure::SUN : Exposure::PARTSUN);
        store->add_product(*(new Plant{name, price, description, species, exposure}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
    
}
void Mainwin::on_new_mulch_click(){
   // mulch values
   std::string name;
   double price;
   std::string description;
   int volume;
   Material material;
   
  try {
        name = get_string("Name?");
        price = get_double("Price?");
        description = get_string("Description?");
        volume = get_int("Volume (ft³)?");
        int i = get_int("Material? (1) Rubber (2) Pine (3) Cedar (4) Hardwood");
        material = get_material(i);
        //store->add_product(*(new Mulch{name, price, description, volume, material}));
        //add mulch to store
        Mulch mulch{name, price, description, volume, material};
        store->add_product(mulch);
        on_view_products_click();
    } catch(std::exception& e) {
      std::cerr << e.what();
    }
 
}
void Mainwin::on_view_products_click(){
     std::string s = "Current Products\n----------------\n\n";
    for(int i=0; i<store->products(); ++i) {
        std::ostringstream oss;
        oss << store->product(i) << '\n' << '\n';
        s += oss.str();
    }
    display->set_text(s);
}
void Mainwin::on_quit_click(){close();}

Material Mainwin::get_material(int val) {
    while(true) {
        switch (val) {
            case 1: return Material::RUBBER;
            case 2: return Material::PINE;
            case 3: return Material::CEDAR;
            case 4: return Material::HARDWOOD;
            default: std::cerr << "INVALID SELECTION\n" << std::endl;
        }
    }
} 

Exposure Mainwin::get_exposure(int val) {
   while(true){
        switch (val) {
            case 1: return Exposure::SHADE;
            case 2: return Exposure::PARTSUN;
            case 3: return Exposure::SUN;
            default: std::cerr << "INVALID SELECTION\n" << std::endl;
        }
      }  
} 

std::string Mainwin::get_string(std::string value) {
    EntryDialog edialog(*this, "<big>New Product</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    edialog.set_secondary_text(value, true);
    if(edialog.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    return edialog.get_text();
}


int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}

double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}


void Mainwin::on_save_as_click(){
  Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_manga = Gtk::FileFilter::create();
    filter_manga->set_name("MANGA files");
    filter_manga->add_pattern("*.manga");
    dialog.add_filter(filter_manga);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.manga");

    //Add response buttons to the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1) {
    // user wants to save
        try {
            std::ofstream ofs{dialog.get_filename()};
            //std::ostream& ost{dialog.get_filename()};
            store->save(ofs);
            //ofs << filename << std::endl;
            if(!ofs) throw std::runtime_error{"Error writing file"};
        } catch(std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to save game"}.run();
        }
    }
}

void Mainwin::on_open_click(){
  Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_manga = Gtk::FileFilter::create();
    filter_manga->set_name("MANGA files");
    filter_manga->add_pattern("*.manga");
    dialog.add_filter(filter_manga);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.manga");

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            delete store;
            std::ifstream ifs{dialog.get_filename()};
            //std::istream& ist{dialog.get_filename()};
            //nim = new Nim{ifs};
            store = new Store{ifs};
            //bool b;
            //ifs >> b;
            //computer_player->set_active(b);
            if(!ifs) throw std::runtime_error{"File contents bad"};
            on_view_products_click();
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open manga"}.run();
        }
    }
}

void Mainwin::on_about_click(){
  
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("MANGA");
    auto logo = Gdk::Pixbuf::create_from_file("logo.jpg");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.2.1");
    dialog.set_copyright("Copyright 2020-2025");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Richard Kalibbala"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by PIXXY, https://creativecommons.org/licenses/by-nc-nd/4.0/",
        "Logo, licensed for personal and commercial purposes with attribution https://pixy.org/1131433/"};
    dialog.set_artists(artists);
    dialog.run();
}






