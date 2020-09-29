#ifndef _AND_H
#define _AND_H

#include "gate.h"

class And : public Gate {
  public:
    //And();
    virtual Signal output() override;
};

#endif
