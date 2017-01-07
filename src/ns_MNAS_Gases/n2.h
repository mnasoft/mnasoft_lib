/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef N2_H
#define N2_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///N2 - азот.
class MNASOFT_EXPORT N2 : public teplojomkost
{
public:
    N2();
    ~N2();
    virtual string Name();
    virtual string Formula();
};
}

#endif //N2_H
