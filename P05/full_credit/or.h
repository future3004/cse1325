#ifndef _OR_H
#define _OR_H

#include "gate.h"

class Or : virtual public Gate{
  public:
    Or();
    //virtual Signal output() override;
    virtual void output() override;
};

#endif
