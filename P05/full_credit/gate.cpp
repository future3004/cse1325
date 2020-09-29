#include "gate.h"

Gate::Gate(): _input1{0}, _input2{0}, _to_gate{nullptr}, _to_pin{1}{
  // nothing in body
}

void Gate::connect(Gate& gate, Pin input_pin){
  _to_gate = gate;
  _to_pin = input_pin;
}

Signal Gate::input(Pin pin){
  return (pin == 1) ? _input1 : _input2;
}

void Gate::input(Pin pin, Signal signal){
  if(pin == 1){_input1 = signal;}
  else{_input2 = signal;}
  
  if(_to_gate){
    _to_gate-> input(_to_pin, output());
  }
}
