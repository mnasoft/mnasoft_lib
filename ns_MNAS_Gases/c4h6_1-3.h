/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef C4H6_1_3_H
#define C4H6_1_3_H

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
