/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef C4H6_1_3_H
#define C4H6_1_3_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///C4H6_1_3 - бутан.
class MNASOFT_EXPORT C4H6_1_3
  : public teplojomkost
{
public:
        C4H6_1_3();
        ~C4H6_1_3();
      virtual string Name();
      virtual string Formula();
};
}

#endif //C4H6_1_3_H
