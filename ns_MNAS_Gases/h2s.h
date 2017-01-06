/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef H2S_H
#define H2S_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///H2S - сероводород.
class MNASOFT_EXPORT H2S : public teplojomkost
{
public:
    H2S();
    ~H2S();
    virtual string Name();
    virtual string Formula();
};
}

#endif //H2S_H
