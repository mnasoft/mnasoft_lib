/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef CO_H
#define CO_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///CO - угарный газ.
class MNASOFT_EXPORT CO : public teplojomkost
{
public:
    CO();
    ~CO();
    virtual string Name();
    virtual string Formula();
};
}

#endif //CO_H
