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

#include "co2.h"

namespace ns_MNAS_Gases
{
CO2::CO2() : teplojomkost()
{
    set_v_max( 26 );
    v_t( 1 ) = 0.0 ; v_Cp( 1 ) = 0.1946 ; v_Cv( 1 ) = 0.1495; v_S( 1 ) = 0.0;
    v_t( 2 ) = 100.0 ; v_Cp( 2 ) = 0.2182 ; v_Cv( 2 ) = 0.1731; v_S( 2 ) = 0.0;
    v_t( 3 ) = 200.0 ; v_Cp( 3 ) = 0.2371 ; v_Cv( 3 ) = 0.1920; v_S( 3 ) = 0.0;
    v_t( 4 ) = 300.0 ; v_Cp( 4 ) = 0.2524 ; v_Cv( 4 ) = 0.2073; v_S( 4 ) = 0.0;
    v_t( 5 ) = 400.0 ; v_Cp( 5 ) = 0.2652 ; v_Cv( 5 ) = 0.2200; v_S( 5 ) = 0.0;
    v_t( 6 ) = 500.0 ; v_Cp( 6 ) = 0.2758 ; v_Cv( 6 ) = 0.2307; v_S( 6 ) = 0.0;
    v_t( 7 ) = 600.0 ; v_Cp( 7 ) = 0.2847 ; v_Cv( 7 ) = 0.2395; v_S( 7 ) = 0.0;
    v_t( 8) = 700.0 ; v_Cp( 8 ) = 0.2921 ; v_Cv( 8 ) = 0.2470; v_S( 8 ) = 0.0;
    v_t( 9 ) = 800.0 ; v_Cp( 9 ) = 0.2984 ; v_Cv( 9 ) = 0.2532; v_S( 9 ) = 0.0;
    v_t( 10 ) = 900.0 ; v_Cp( 10 ) = 0.3037 ; v_Cv( 10 ) = 0.2585; v_S( 10 ) = 0.0;
    v_t( 11 ) = 1000.0 ; v_Cp( 11 ) = 0.3081 ; v_Cv( 11 ) = 0.2630; v_S( 11 ) = 0.0;
    v_t( 12 ) = 1100.0 ; v_Cp( 12 ) = 0.3119 ; v_Cv( 12 ) = 0.2668; v_S( 12 ) = 0.0;
    v_t( 13 ) = 1200.0 ; v_Cp( 13 ) = 0.3152 ; v_Cv( 13 ) = 0.2700; v_S( 13 ) = 0.0;
    v_t( 14 ) = 1300.0 ; v_Cp( 14 ) = 0.3180 ; v_Cv( 14 ) = 0.2728; v_S( 14 ) = 0.0;
    v_t( 15 ) = 1400.0 ; v_Cp( 15 ) = 0.3204 ; v_Cv( 15 ) = 0.2752; v_S( 15 ) = 0.0;
    v_t( 16 ) = 1500.0 ; v_Cp( 16 ) = 0.3224 ; v_Cv( 16 ) = 0.2773; v_S( 16 ) = 0.0;
    v_t( 17 ) = 1600.0 ; v_Cp( 17 ) = 0.3242 ; v_Cv( 17 ) = 0.2791; v_S( 17 ) = 0.0;
    v_t( 18 ) = 1700.0 ; v_Cp( 18 ) = 0.3257 ; v_Cv( 18 ) = 0.2806; v_S( 18 ) = 0.0;
    v_t( 19 ) = 1800.0 ; v_Cp( 19 ) = 0.3271 ; v_Cv( 19 ) = 0.2820; v_S( 19 ) = 0.0;
    v_t( 20 ) = 1900.0 ; v_Cp( 20 ) = 0.3282 ; v_Cv( 20 ) = 0.2831; v_S( 20 ) = 0.0;
    v_t( 21 ) = 2000.0 ; v_Cp( 21 ) = 0.3292 ; v_Cv( 21 ) = 0.2840; v_S( 21 ) = 0.0;
    v_t( 22 ) = 2100.0 ; v_Cp( 22 ) = 0.3300 ; v_Cv( 22 ) = 0.2848; v_S( 22 ) = 0.0;
    v_t( 23 ) = 2200.0 ; v_Cp( 23 ) = 0.3306 ; v_Cv( 23 ) = 0.2855; v_S( 23 ) = 0.0;
    v_t( 24 ) = 2300.0 ; v_Cp( 24 ) = 0.3311 ; v_Cv( 24 ) = 0.2860; v_S( 24 ) = 0.0;
    v_t( 25 ) = 2400.0 ; v_Cp( 25 ) = 0.3314 ; v_Cv( 25 ) = 0.2863; v_S( 25 ) = 0.0;
    v_t( 26 ) = 2500.0 ; v_Cp( 26 ) = 0.3315 ; v_Cv( 26 ) = 0.2864; v_S( 26 ) = 0.0;
     v_t=v_t/1000.0;
    reculc_polynoms();
    cout << p_t_Cp;
    cout << p_t_Cv ;
    cout << p_t_S ;
    int i =0;
    while (i<=2500)    {      cout << i <<"   "<<Cp(i)  <<"   "<< Cv(i) <<"   "<< S(i)<< endl;       i+=100;    }
}

CO2::~CO2()
{}
  string CO2::Name()
  {
  return "углекислый газ";
  }
  string CO2::Formula()
  {
  return "CO2";
  }
}
