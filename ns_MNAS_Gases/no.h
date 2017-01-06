/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef NO_H
#define NO_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///NO - окид азота.
class MNASOFT_EXPORT NO
  : public teplojomkost
{
public:
    NO();
    ~NO();
    virtual string Name();
    virtual string Formula();
};
}

#endif //NO_H
