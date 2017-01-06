/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef C2H5OH_H
#define C2H5OH_H

#include "mnasoft_lib_global.h"

#include <teplojomkost.h>

namespace ns_MNAS_Gases
{
///C2H5OH - этиловый спирт.
class MNASOFT_EXPORT C2H5OH : public teplojomkost
{
public:
        C2H5OH();
        ~C2H5OH();
      virtual string Name();
      virtual string Formula();
};
}

#endif //C2H5OH_H
