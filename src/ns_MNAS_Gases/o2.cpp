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

#include "o2.h"

namespace ns_MNAS_Gases
  {
  O2::O2() : teplojomkost()
    {
    set_v_max( 28 );
    v_t( 1 ) = 0.0;    v_Cp( 1 ) = 0.2185;    v_Cv( 1 ) = 0.1564;    v_S( 1 ) = 0.0;
    v_t( 2 ) = 100.0;    v_Cp( 2 ) = 0.2230;    v_Cv( 2 ) = 0.1609;    v_S( 2 ) = 0.0675;
    v_t( 3 ) = 200.0;    v_Cp( 3 ) = 0.2300;    v_Cv( 3 ) = 0.1679;    v_S( 3 ) = 0.1214;
    v_t( 4 ) = 300.0;    v_Cp( 4 ) = 0.2376;    v_Cv( 4 ) = 0.1755;    v_S( 4 ) = 0.1662;
    v_t( 5 ) = 400.0;    v_Cp( 5 ) = 0.2445;    v_Cv( 5 ) = 0.1824;    v_S( 5 ) = 0.2050;
    v_t( 6 ) = 500.0;    v_Cp( 6 ) = 0.2504;    v_Cv( 6 ) = 0.1833;    v_S( 6 ) = 0.2393;
    v_t( 7 ) = 600.0;    v_Cp( 7 ) = 0.2553;    v_Cv( 7 ) = 0.1932;    v_S( 7 ) = 0.2700;
    v_t( 8 ) = 700.0;    v_Cp( 8 ) = 0.2593;    v_Cv( 8 ) = 0.1973;    v_S( 8 ) = 0.2979;
    v_t( 9 ) = 800.0;    v_Cp( 9 ) = 0.2627;    v_Cv( 9 ) = 0.2007;    v_S( 9 ) = 0.3234;
    v_t( 10 ) = 900.0;    v_Cp( 10 ) = 0.2656;    v_Cv( 10 ) = 0.2035;    v_S( 10 ) = 0.3470;
    v_t( 11 ) = 1000.0;    v_Cp( 11 ) = 0.2682;    v_Cv( 11 ) = 0.2060;    v_S( 11 ) = 0.3688;
    v_t( 12 ) = 1100.0;    v_Cp( 12 ) = 0.2703;    v_Cv( 12 ) = 0.2082;    v_S( 12 ) = 0.3892;
    v_t( 13 ) = 1200.0;    v_Cp( 13 ) = 0.2723;    v_Cv( 13 ) = 0.2103;    v_S( 13 ) = 0.4082;
    v_t( 14 ) = 1300.0;    v_Cp( 14 ) = 0.2743;    v_Cv( 14 ) = 0.2122;    v_S( 14 ) = 0.4262;
    v_t( 15 ) = 1400.0;    v_Cp( 15 ) = 0.2762;    v_Cv( 15 ) = 0.2141;    v_S( 15 ) = 0.4432;
    v_t( 16 ) = 1500.0;    v_Cp( 16 ) = 0.2780;    v_Cv( 16 ) = 0.2159;    v_S( 16 ) = 0.4592;
    v_t( 17 ) = 1600.0;    v_Cp( 17 ) = 0.2797;    v_Cv( 17 ) = 0.2177;    v_S( 17 ) = 0.4745;
    v_t( 18 ) = 1700.0;    v_Cp( 18 ) = 0.2815;    v_Cv( 18 ) = 0.2194;    v_S( 18 ) = 0.4891;
    v_t( 19 ) = 1800.0;    v_Cp( 19 ) = 0.2832;    v_Cv( 19 ) = 0.2212;    v_S( 19 ) = 0.5031;
    v_t( 20 ) = 1900.0;    v_Cp( 20 ) = 0.2849;    v_Cv( 20 ) = 0.2229;    v_S( 20 ) = 0.5165;
    v_t( 21 ) = 2000.0;    v_Cp( 21 ) = 0.2867;    v_Cv( 21 ) = 0.2246;    v_S( 21 ) = 0.5293;
    v_t( 22 ) = 2100.0;    v_Cp( 22 ) = 0.2884;    v_Cv( 22 ) = 0.2263;    v_S( 22 ) = 0.5417;
    v_t( 23 ) = 2200.0;    v_Cp( 23 ) = 0.2900;    v_Cv( 23 ) = 0.2280;    v_S( 23 ) = 0.5536;
    v_t( 24 ) = 2300.0;    v_Cp( 24 ) = 0.2917;    v_Cv( 24 ) = 0.2296;    v_S( 24 ) = 0.5652;
    v_t( 25 ) = 2400.0;    v_Cp( 25 ) = 0.2933;    v_Cv( 25 ) = 0.2312;    v_S( 25 ) = 0.5763;
    v_t( 26 ) = 2500.0;    v_Cp( 26 ) = 0.2948;    v_Cv( 26 ) = 0.2328;    v_S( 26 ) = 0.5871;
    v_t( 27 ) = 2600.0;    v_Cp( 27 ) = 0.2964;    v_Cv( 27 ) = 0.2343;    v_S( 27 ) = 0.5976;
    v_t( 28 ) = 2700.0;    v_Cp( 28 ) = 0.2979;    v_Cv( 28 ) = 0.2358;    v_S( 28 ) = 0.6078;
    v_t=v_t/1000.0;
    reculc_polynoms();
    
    cout 
    << Name() << endl
    << Formula() << endl;
    cout << p_t_Cp;
    cout << p_t_Cv ;
    cout << p_t_S ;
    int i =0;
    
    while (i<=2700)    {      cout << i <<"   "<<Cp(i)  <<"   "<< Cv(i) <<"   "<< S(i)<< endl;       i+=100;    }
    }

  O2::~O2()
  {
  }
  string O2::Name()
  {    
    return "O2";
  }

  string O2::Formula()
  {
    return "O2";
  }
}
