/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef C2H2_H
#define C2H2_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///C2H2 - ацэтилен.
class MNASOFT_EXPORT C2H2 : public teplojomkost
{
public:
    C2H2();
    ~C2H2();
    virtual string Name();
    virtual string Formula();
};
}

#endif //C2H2_H
