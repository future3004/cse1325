#ifndef _GATE_H
#define _GATE_H

#include <iostream>

class Gate{
  public:
    Gate();
    void connect(Gate& gate, Pin input_pin);
    void input(Pin pin, Signal signal);
    Signal input(Pin pin);
    Signal output();
  private:
    Signal _input1;
    Signal _input2;
    Gate* _to_gate;
    Pin _to_pin;
};

#endif
