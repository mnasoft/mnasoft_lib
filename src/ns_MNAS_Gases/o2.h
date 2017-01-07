/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef O2_H
#define O2_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///O2 - кислород.
class MNASOFT_EXPORT O2 : public teplojomkost
{
public:
    O2();
    ~O2();
    virtual string Name();
    virtual string Formula();
};
}

#endif //O2_H
