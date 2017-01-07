/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef NO2_H
#define NO2_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///NO2 - закись азота.
class MNASOFT_EXPORT NO2
  : public teplojomkost
{
public:
    NO2();
    ~NO2();
    virtual string Name();
    virtual string Formula();
};
}

#endif //NO2_H
