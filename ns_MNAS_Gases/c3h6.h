/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef C3H6_H
#define C3H6_H

#include "mnasoft_lib_global.h"

#include <teplojomkost.h>

namespace ns_MNAS_Gases
{
///C3H6 - пропилен.
class MNASOFT_EXPORT C3H6 : public teplojomkost
{
public:
        C3H6();
        ~C3H6();
	virtual string Name();
      virtual string Formula();
};
}

#endif //C3H6_H
