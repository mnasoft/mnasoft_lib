/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef H2_H
#define H2_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///H2 - водород.
class MNASOFT_EXPORT H2
  : public teplojomkost
{
public:
    H2();
    ~H2();
    virtual string Name();
    virtual string Formula();
};
}

#endif //H2_H
