#ifndef _OR_H
#define _OR_H

#include "gate.h"

class Or : public Gate{
  public:
    //Or();
    virtual Signal output() override;
};

#endif
