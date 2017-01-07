/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef C2H4_H
#define C2H4_H

#include "mnasoft_lib_global.h"

#include <teplojomkost.h>

namespace ns_MNAS_Gases
{
///C2H4 - этилен.
class MNASOFT_EXPORT C2H4 : public teplojomkost
{
public:
        C2H4();
        ~C2H4();
      virtual string Name();
      virtual string Formula();
};
}

#endif //C2H4_H
