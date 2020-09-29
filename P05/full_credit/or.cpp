#include "or.h"
#include "gate.h"
#include <iostream>

enum Signal sO;

Signal Or::output() {
  std::cout << "Output method = Or" << "\n" <<std::endl;
  sO = OFF;
  return sO;
}
