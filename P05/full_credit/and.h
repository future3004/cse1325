#ifndef _AND_H
#define _AND_H

#include "gate.h"

class And : public Gate {
  public:
    virtual Signal output() override;
};

#endif
