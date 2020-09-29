#ifndef _AND_H
#define _AND_H

#include "gate.h"

class And : public Gate {
  public:
    //And();
    Signal output() override;
};

#endif
