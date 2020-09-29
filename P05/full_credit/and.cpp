#include "and.h"

//enum Signal sA;

Signal And::output() {
   //std::cout << "Output method = And" << "\n" << std::endl;
   //if(_input1 && _input2){ sA = ON;}
   //else sA = OFF;
  return _input1 && _input2;
}
