#include "or.h"
#include "gate.h"
#include <iostream>

enum Signal sO;

Signal Or::output() {
  std::cout << "Output method = Or" << "\n" <<std::endl;
  if(_input1 || _input2 == 1){ sO = ON;}
  else sO = OFF;
  //sO = OFF;
  return sO;
}
