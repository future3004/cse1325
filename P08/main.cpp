#include "tool.h"
#include "plant.h"
#include "mulch.h"
#include "mainwin.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));
    auto app = Gtk::Application::create(argc, argv, "P08.app");
    Mainwin win;
    app->run(win);
}
