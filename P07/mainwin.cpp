#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin() : button{new Gtk::Button{"Run Prog"}} {
  set_default_size(400, 200);
  set_title("Sprint 07");
  add(*button);
  button->signal_clicked().connect([this] {this->on_button_click();});
  button->show();
}

Mainwin::~Mainwin() { }

void Mainwin::on_button_click() {
    EntryDialog edialog{*this, "<big>Enter Values</big>", true};
    edialog.set_secondary_text("<b>Tool Name</b>:", true);
    edialog.set_text("enter tool name...");
    edialog.run();

    Gtk::MessageDialog mdialog{*this, edialog.get_text()};
    mdialog.run();
}
