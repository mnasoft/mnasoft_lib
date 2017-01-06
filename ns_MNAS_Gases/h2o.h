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
#ifndef H2O_H
#define H2O_H

#pragma once

#include "teplojomkost.h"

namespace ns_MNAS_Gases
{
///H2O - вода.
class MNASOFT_EXPORT H2O : public teplojomkost
{
public:
    H2O();
    ~H2O();
    virtual string Name();
    virtual string Formula();
};
}

#endif //H2O_H
