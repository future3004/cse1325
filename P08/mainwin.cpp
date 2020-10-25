#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin(): store{nullptr} {
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
  delete store;
  //Store::Store store{"Mavs Arboreta"};
  //Store my_store{"MavsArboreta"};
  store = new Store{"MavsArboreta"};
  
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


