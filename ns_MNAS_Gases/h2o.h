/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef H2O_H
#define H2O_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///H2O - вода.
class MNASOFT_EXPORT H2O : public teplojomkost
{
public:
    H2O();
    ~H2O();
    virtual string Name();
    virtual string Formula();
};
}

#endif //H2O_H
