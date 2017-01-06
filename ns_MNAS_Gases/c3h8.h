/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef C3H8_H
#define C3H8_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///C3H8 - пропан.
class MNASOFT_EXPORT C3H8 : public teplojomkost
{
public:
        C3H8();
        ~C3H8();
	virtual string Name();
      virtual string Formula();
};
}

#endif //C3H8_H
