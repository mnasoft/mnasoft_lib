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

#include "so2.h"

namespace ns_MNAS_Gases
{
    SO2::SO2() : teplojomkost()
    {
        set_v_max(13);
        v_t( 1 ) = 0.0; v_Cp( 1 ) = 0.1450; v_Cv( 1 ) = 0.1140; v_S( 1 ) = 0.0;
        v_t( 2 ) = 100.0; v_Cp( 2 ) = 0.1580; v_Cv( 2 ) = 0.1270; v_S( 2 ) = 0.0;
        v_t( 3 ) = 200.0; v_Cp( 3 ) = 0.1700; v_Cv( 3 ) = 0.1390; v_S( 3 ) = 0.0;
        v_t( 4 ) = 300.0; v_Cp( 4 ) = 0.1800; v_Cv( 4 ) = 0.1490; v_S( 4 ) = 0.0;
        v_t( 5 ) = 400.0; v_Cp( 5 ) = 0.1870; v_Cv( 5 ) = 0.1560; v_S( 5 ) = 0.0;
        v_t( 6 ) = 500.0; v_Cp( 6 ) = 0.1930; v_Cv( 6 ) = 0.1620; v_S( 6 ) = 0.0;
        v_t( 7 ) = 600.0; v_Cp( 7 ) = 0.1970; v_Cv( 7 ) = 0.1660; v_S( 7 ) = 0.0;
        v_t( 8 ) = 700.0; v_Cp( 8 ) = 0.2000; v_Cv( 8 ) = 0.1690; v_S( 8 ) = 0.0;
        v_t( 9 ) = 800.0; v_Cp( 9 ) = 0.2030; v_Cv( 9 ) = 0.1720; v_S( 9 ) = 0.0;
        v_t( 10 ) = 900.0; v_Cp( 10 ) = 0.2050; v_Cv( 10 ) = 0.1740; v_S( 10 ) = 0.0;
        v_t( 11 ) = 1000.0; v_Cp( 11 ) = 0.2070; v_Cv( 11 ) = 0.1760; v_S( 11 ) = 0.0;
        v_t( 12 ) = 1100.0; v_Cp( 12 ) = 0.2080; v_Cv( 12 ) = 0.1770; v_S( 12 ) = 0.0;
        v_t( 13 ) = 1200.0; v_Cp( 13 ) = 0.2090; v_Cv( 13 ) = 0.1780; v_S( 13 ) = 0.0;
	v_t=v_t/1000.0;
    reculc_polynoms();
    
    cout 
    << Name() << endl
    << Formula() << endl;
    cout << p_t_Cp;
    cout << p_t_Cv ;
    cout << p_t_S ;
    int i =0;
    while (i<=1200)    {      cout << i <<"   "<<Cp(i)  <<"   "<< Cv(i) <<"   "<< S(i)<< endl;       i+=100;    }
    }

    SO2::~SO2()
    {}
      string SO2::Name()
  {
  return "диоксид серы";
  }
  string SO2::Formula()
  {
  return "SO2";
  }
}
