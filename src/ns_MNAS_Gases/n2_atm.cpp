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

#include "n2_atm.h"

namespace ns_MNAS_Gases
{
N2_ATM::N2_ATM() : teplojomkost()
{
    set_v_max( 26 );
    v_t(1) = 0; v_Cp( 1 ) = 0.2461; v_Cv( 1 ) = 0.1756; v_S( 1 ) = 0;
    v_t(2) = 100; v_Cp( 2 ) = 0.2469; v_Cv( 2 ) = 0.1763; v_S( 2 ) = 0;
    v_t(3) = 200; v_Cp( 3 ) = 0.2491; v_Cv( 3 ) = 0.1786; v_S( 3 ) = 0;
    v_t(4) = 300; v_Cp( 4 ) = 0.2532; v_Cv( 4 ) = 0.1827; v_S( 4 ) = 0;
    v_t(5) = 400; v_Cp( 5 ) = 0.2584; v_Cv( 5 ) = 0.1879; v_S( 5 ) = 0;
    v_t(6) = 500; v_Cp( 6 ) = 0.2641; v_Cv( 6 ) = 0.1935; v_S( 6 ) = 0;
    v_t(7) = 600; v_Cp( 7 ) = 0.2697; v_Cv( 7 ) = 0.1992; v_S( 7 ) = 0;
    v_t(8) = 700; v_Cp( 8 ) = 0.2749; v_Cv( 8 ) = 0.2044; v_S( 8 ) = 0;
    v_t(9) = 800; v_Cp( 9 ) = 0.2793; v_Cv( 9 ) = 0.2091; v_S( 9 ) = 0;
    v_t(10) = 900; v_Cp( 10 ) = 0.2833; v_Cv( 10 ) = 0.2132; v_S( 10 ) = 0;
    v_t(11) = 1000; v_Cp( 11 ) = 0.2874; v_Cv( 11 ) = 0.2169; v_S( 11 ) = 0;
    v_t(12) = 1100; v_Cp( 12 ) = 0.2907; v_Cv( 12 ) = 0.2202; v_S( 12 ) = 0;
    v_t(13) = 1200; v_Cp( 13 ) = 0.2935; v_Cv( 13 ) = 0.223; v_S( 13 ) = 0;
    v_t(14) = 1300; v_Cp( 14 ) = 0.295; v_Cv( 14 ) = 0.2255; v_S( 14 ) = 0;
    v_t(15) = 1400; v_Cp( 15 ) = 0.2982; v_Cv( 15 ) = 0.2277; v_S( 15 ) = 0;
    v_t(16) = 1500; v_Cp( 16 ) = 0.3001; v_Cv( 16 ) = 0.2296; v_S( 16 ) = 0;
    v_t(17) = 1600; v_Cp( 17 ) = 0.3018; v_Cv( 17 ) = 0.2313; v_S( 17 ) = 0;
    v_t(18) = 1700; v_Cp( 18 ) = 0.3033; v_Cv( 18 ) = 0.2328; v_S( 18 ) = 0;
    v_t(19) = 1800; v_Cp( 19 ) = 0.3047; v_Cv( 19 ) = 0.2341; v_S( 19 ) = 0;
    v_t(20) = 1900; v_Cp( 20 ) = 0.3059; v_Cv( 20 ) = 0.2354; v_S( 20 ) = 0;
    v_t(21) = 2000; v_Cp( 21 ) = 0.307; v_Cv( 21 ) = 0.2364; v_S( 21 ) = 0;
    v_t(22) = 2100; v_Cp( 22 ) = 0.308; v_Cv( 22 ) = 0.2374; v_S( 22 ) = 0;
    v_t(23) = 2200; v_Cp( 23 ) = 0.3089; v_Cv( 23 ) = 0.2383; v_S( 23 ) = 0;
    v_t(24) = 2300; v_Cp( 24 ) = 0.3097; v_Cv( 24 ) = 0.2392; v_S( 24 ) = 0;
    v_t(25) = 2400; v_Cp( 25 ) = 0.3105; v_Cv( 25 ) = 0.24; v_S( 25 ) = 0;
    v_t(26) = 2500; v_Cp( 26 ) = 0.3112; v_Cv( 26 ) = 0.2407; v_S( 26 ) = 0;
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

N2_ATM::~N2_ATM()
{}
  string N2_ATM::Name()
  {
  return "N2_ATM";
  }
  string N2_ATM::Formula()
  {
  return "";
  }
}
