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

#include "air.h"

namespace ns_MNAS_Gases 
{
  Air::Air()  : teplojomkost()
  {
    set_v_max( 26 );
    v_t( 1 ) = 0.0; v_Cp( 1 ) = 0.2397; v_Cv( 1 ) = 0.1711; v_S( 1 ) = 0.0;
    v_t( 2 ) = 100.0 ; v_Cp( 2 ) = 0.2413 ; v_Cv( 2 ) = 0.1727; v_S( 2 ) = 0.0;
    v_t( 3 ) = 200.0 ; v_Cp( 3 ) = 0.2447 ; v_Cv( 3 ) = 0.1761; v_S( 3 ) = 0.0;
    v_t( 4 ) = 300.0 ; v_Cp( 4 ) = 0.2495 ; v_Cv( 4 ) = 0.1810; v_S( 4 ) = 0.0;
    v_t( 5 ) = 400.0 ; v_Cp( 5 ) = 0.2552 ; v_Cv( 5 ) = 0.1866; v_S( 5 ) = 0.0;
    v_t( 6 ) = 500.0 ; v_Cp( 6 ) = 0.2609 ; v_Cv( 6 ) = 0.1923; v_S( 6 ) = 0.0;
    v_t( 7 ) = 600.0 ; v_Cp( 7 ) = 0.2663 ; v_Cv( 7 ) = 0.1978; v_S( 7 ) = 0.0;
    v_t( 8 ) = 700.0 ; v_Cp( 8 ) = 0.2712 ; v_Cv( 8 ) = 0.2027; v_S( 8 ) = 0.0;
    v_t( 9 ) = 800.0 ; v_Cp( 9 ) = 0.2756 ; v_Cv( 9 ) = 0.2071; v_S( 9 ) = 0.0;
    v_t( 10 ) = 900.0 ; v_Cp( 10 ) = 0.2795 ; v_Cv( 10 ) = 0.2110; v_S( 10 ) = 0.0;
    v_t( 11 ) = 1000.0;  v_Cp( 11 ) = 0.2829 ; v_Cv( 11 ) = 0.2144; v_S( 11 ) = 0.0;
    v_t( 12 ) = 1100.0; v_Cp( 12 ) = 0.2859 ; v_Cv( 12 ) = 0.2174; v_S( 12 ) = 0.0;
    v_t( 13 ) = 1200.0; v_Cp( 13 ) = 0.2886 ; v_Cv( 13 ) = 0.2200; v_S( 13 ) = 0.0;
    v_t( 14 ) = 1300.0; v_Cp( 14 ) = 0.2909 ; v_Cv( 14 ) = 0.2224; v_S( 14 ) = 0.0;
    v_t( 15 ) = 1400.0; v_Cp( 15 ) = 0.2930 ; v_Cv( 15 ) = 0.2245; v_S( 15 ) = 0.0;
    v_t( 16 ) = 1500.0; v_Cp( 16 ) = 0.2949 ; v_Cv( 16 ) = 0.2264; v_S( 16 ) = 0.0;
    v_t( 17 ) = 1600.0; v_Cp( 17 ) = 0.2966 ; v_Cv( 17 ) = 0.2281; v_S( 17 ) = 0.0;
    v_t( 18 ) = 1700.0; v_Cp( 18 ) = 0.2982 ; v_Cv( 18 ) = 0.2296; v_S( 18 ) = 0.0;
    v_t( 19 ) = 1800.0;  v_Cp( 19 ) = 0.2996 ; v_Cv( 19 ) = 0.2311; v_S( 19 ) = 0.0;
    v_t( 20 ) = 1900.0;  v_Cp( 20 ) = 0.3010 ; v_Cv( 20 ) = 0.2324; v_S( 20 ) = 0.0;
    v_t( 21 ) = 2000.0;  v_Cp( 21 ) = 0.3022 ; v_Cv( 21 ) = 0.2337; v_S( 21 ) = 0.0;
    v_t( 22 ) = 2100.0;  v_Cp( 22 ) = 0.3034 ; v_Cv( 22 ) = 0.2348; v_S( 22 ) = 0.0;
    v_t( 23 ) = 2200.0;  v_Cp( 23 ) = 0.3045 ; v_Cv( 23 ) = 0.2359; v_S( 23 ) = 0.0;
    v_t( 24 ) = 2300.0;  v_Cp( 24 ) = 0.3055 ; v_Cv( 24 ) = 0.2369; v_S( 24 ) = 0.0;
    v_t( 25 ) = 2400.0;  v_Cp( 25 ) = 0.3065 ; v_Cv( 25 ) = 0.2379; v_S( 25 ) = 0.0;
    v_t( 26 ) = 2500.0;  v_Cp( 26 ) = 0.3074 ; v_Cv( 26 ) = 0.2388; v_S( 26 ) = 0.0;
    v_t=v_t/1000.0;
    reculc_polynoms();

    cout 
    << Name() << endl
    << Formula() << endl;
    cout << p_t_Cp;
    cout << p_t_Cv ;
    cout << p_t_S ;
    int i =0;
    while (i<=2500)    {      cout << i <<"   "<<Cp(i)  <<"   "<< Cv(i) <<"   "<< S(i)<< endl;       i+=100;    }
  }
  Air::~Air()
  {}
  string Air::Name()
  {
  return "Air";
  }
  string Air::Formula()
  {
  return "Air";
  }
};
