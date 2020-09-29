#include "and.h"
#include "gate.h"
#include <iostream>

enum Signal sA;

Signal And::output() {
   std::cout << "Output method = And" << "\n" << std::endl;
   sA = ON;
  return sA;
}
