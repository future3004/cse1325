#ifndef _MAINWIN_H
#define _MAINWIN_H

#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_button_click();
  private:
    Gtk::Button* button;
};


#endif
