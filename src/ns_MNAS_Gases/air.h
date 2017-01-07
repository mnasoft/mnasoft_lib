/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     *
 ***************************************************************************/

#ifndef AIR_H
#define AIR_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///Air - воздух.
class MNASOFT_EXPORT Air : public teplojomkost
{
public:
    Air();
    ~Air();
      virtual string Name();
      virtual string Formula();
};
}

#endif //AIR_H
