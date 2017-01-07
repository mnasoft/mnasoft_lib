/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef CH4_H
#define CH4_H

#include "mnasoft_lib_global.h"

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///CH4 - метан.
class MNASOFT_EXPORT CH4
  : public teplojomkost
{
public:
        CH4();
        ~CH4();
	virtual string Name();
	virtual string Formula();
};
}

#endif //CH4_H
