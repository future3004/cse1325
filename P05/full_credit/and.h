#ifndef _AND_H
#define _AND_H

#include "gate.h"

class And : virtual public Gate{
  public:
    And();
    //virtual Signal output() override;
    virtual void output() override;
};

#endif
