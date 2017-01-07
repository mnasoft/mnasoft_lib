/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef CO2_H
#define CO2_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///CO2 - ????? ??
class MNASOFT_EXPORT CO2
  : public teplojomkost
{
public:
    CO2();
    ~CO2();
    virtual string Name();
    virtual string Formula();
};
}

#endif //CO2_H
