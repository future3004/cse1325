#ifndef _GATE_H
#define _GATE_H

#include <iostream>

enum Pin{FIRST=1, SECOND};
enum Signal{OFF=100, ON};

class Gate{
  public:
    Gate();
    void connect(Gate& gate, Pin input_pin);
    void input(Pin pin, Signal signal);
    Signal input(Pin pin);
    //virtual Signal output() = 0;
    virtual void output() = 0;
  private:
    Signal _input1;
    Signal _input2;
    Gate* _to_gate;
    Pin _to_pin;
};

#endif
