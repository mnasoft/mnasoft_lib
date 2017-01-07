/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef C6H6_H
#define C6H6_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///C6H6 - бензол.
class MNASOFT_EXPORT C6H6
  : public teplojomkost
{
public:
        C6H6();
        ~C6H6();
	virtual string Name();
	virtual string Formula();
};
}

#endif //C6H6_H
