/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef N2_ATM_H
#define N2_ATM_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///N2 - атмосферный азот.
class MNASOFT_EXPORT N2_ATM : public teplojomkost
{
public:
    N2_ATM();
    ~N2_ATM();
    virtual string Name();
    virtual string Formula();
};
}

#endif //N2_ATM_H
