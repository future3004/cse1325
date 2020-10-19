#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin(): store{nullptr} {
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
   
  EntryDialog tdialog{*this, "<big>Tool Values</big>", true};
    tdialog.set_secondary_text("<b>Tool Name</b>:", true);
    tdialog.set_text("enter tool name..");
    tdialog.run();
    name = tdialog.get_text();
    
    //price
    EntryDialog pdialog{*this, "<big>Tool Values</big>", true};
    pdialog.set_secondary_text("<b>Tool Price</b>:", true);
    pdialog.set_text("enter tool price..");
    pdialog.run();
    price = get_double(pdialog.get_text());
    
    //description
    EntryDialog cdialog{*this, "<big>Tool Values</big>", true};
    cdialog.set_secondary_text("<b>Tool Description</b>:", true);
    cdialog.set_text("tool description..");
    cdialog.run();
    description = cdialog.get_text();
    
    // add tool to store
    Tool tool{name, price, description};
    store->add_product(tool);
}
void Mainwin::on_new_plant_click(){
    // plant values
    std::string name;
    double price;
    std::string description;
    std::string species;
    Exposure exposure;
    
  EntryDialog ndialog{*this, "<big>Plant Values</big>", true};
    ndialog.set_secondary_text("<b>Plant Name</b>:", true);
    ndialog.set_text("enter plant name...");
    ndialog.run();
    name = ndialog.get_text();
    
    //price
    EntryDialog pdialog{*this, "<big>Plant Values</big>", true};
    pdialog.set_secondary_text("<b>Plant Price</b>:", true);
    pdialog.set_text("enter plant price..");
    pdialog.run();
    price = get_double(pdialog.get_text());
    
    //description
    EntryDialog cdialog{*this, "<big>Plant Values</big>", true};
    cdialog.set_secondary_text("<b>Plant Description</b>:", true);
    cdialog.set_text("plant description..");
    cdialog.run();
    description = cdialog.get_text();
    
    //get species
    EntryDialog sdialog{*this, "<big>Plant Values</big>", true};
    sdialog.set_secondary_text("<b>Plant Species</b>:", true);
    sdialog.set_text("plant species..");
    sdialog.run();
    species = sdialog.get_text();
    
    // get exposure
    EntryDialog edialog{*this, "<big>Plant Values</big>", true};
    edialog.set_secondary_text("<b>Select Exposure: (1) Shade (2) Part Sun (3) Sun? </b>:", true);
    edialog.set_text("enter exposure..");
    edialog.run();
    exposure = get_exposure(get_int(edialog.get_text()));
    
    //add plant to store
    Plant plant{name, price, description, species, exposure};
    store->add_product(plant);

    //Gtk::MessageDialog mdialog{*this, edialog.get_text()};
    //mdialog.run();
}
void Mainwin::on_new_mulch_click(){
   // mulch values
   std::string name;
   double price;
   std::string description;
   int volume;
   Material material;
   
  EntryDialog ndialog{*this, "<big>Mulch Values</big>", true};
    ndialog.set_secondary_text("<b>Mulch Name</b>:", true);
    ndialog.set_text("enter mulch name...");
    ndialog.run();
    name = ndialog.get_text();
    
     //price
    EntryDialog pdialog{*this, "<big>Mulch Values</big>", true};
    pdialog.set_secondary_text("<b>Mulch Price</b>:", true);
    pdialog.set_text("enter mulch price..");
    pdialog.run();
    price = get_double(pdialog.get_text());
    
    //description
    EntryDialog cdialog{*this, "<big>Mulch Values</big>", true};
    cdialog.set_secondary_text("<b>Mulch Description</b>:", true);
    cdialog.set_text("mulch description..");
    cdialog.run();
    description = cdialog.get_text();
    
    //get volume
    EntryDialog vdialog{*this, "<big>Mulch Values</big>", true};
    vdialog.set_secondary_text("<b>Mulch Volume</b>:", true);
    vdialog.set_text("mulch volume..");
    vdialog.run();
    volume = get_int(vdialog.get_text());
    
    //get material type
    EntryDialog mdialog{*this, "<big>Mulch Values</big>", true};
    mdialog.set_secondary_text("<b>Select Material: (1) Rubber (2) Pine (3) Cedar (4) Hardwood? </b>:", true);
    mdialog.set_text("mulch material..");
    mdialog.run();
    material = get_material(get_int(mdialog.get_text()));

   //add mulch to store
    Mulch mulch{name, price, description, volume, material};
    store->add_product(mulch);
}
void Mainwin::on_view_products_click(){
     std::ostringstream oss;
     std::vector<Product*> products;
     int store_products = store->products();
    Glib::ustring s = "";
    //std::string output = "\nCurrent Catalog\n===============\n" + std::to_string(store_products);
    s += "\nCurrent Catalog\n===============\n";

    
    //std::string s = *(store->product(0)).to_string();
    products = store->get_products_vector();
    for(auto product : products){ 
      //std::cout << *product << "\n\n";
      oss << *product << "\n\n";
      //s += product->to_string() + "\n\n";
      s += oss.str();
    }
    
    //display->set_text(output);
    display->set_markup(s);
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
    //std::string s;
    //std::cout << prompt;
    //std::getline(std::cin, s);
    return value;
}

int Mainwin::get_int(std::string value) {
        try {
            return std::stoi(value);
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
            return 0;
        }
}

double Mainwin::get_double(std::string value) {
        try {
            return std::stod(value);
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
            return 0.0;
        }
}



