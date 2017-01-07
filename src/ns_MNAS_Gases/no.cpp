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

#include "no.h"

namespace ns_MNAS_Gases
{
NO::NO() : teplojomkost()
{
    set_v_max( 31 );
    v_t(1) = 0; v_Cp( 1 ) = 0.2386; v_Cv( 1 ) = 0.1724; v_S( 1 ) = 0;
    v_t(2) = 100; v_Cp( 2 ) = 0.2381; v_Cv( 2 ) = 0.1719; v_S( 2 ) = 0;
    v_t(3) = 200; v_Cp( 3 ) = 0.2414; v_Cv( 3 ) = 0.1752; v_S( 3 ) = 0;
    v_t(4) = 300; v_Cp( 4 ) = 5.2472; v_Cv( 4 ) = 0.181; v_S( 4 ) = 0;
    v_t(5) = 400; v_Cp( 5 ) = 0.2534; v_Cv( 5 ) = 0.1872; v_S( 5 ) = 0;
    v_t(6) = 500; v_Cp( 6 ) = 0.2594; v_Cv( 6 ) = 0.1932; v_S( 6 ) = 0;
    v_t(7) = 600; v_Cp( 7 ) = 0.2648; v_Cv( 7 ) = 0.1986; v_S( 7 ) = 0;
    v_t(8) = 700; v_Cp( 8 ) = 0.2695; v_Cv( 8 ) = 0.2033; v_S( 8 ) = 0;
    v_t(9) = 800; v_Cp( 9 ) = 0.2736; v_Cv( 9 ) = 0.2074; v_S( 9 ) = 0;
    v_t(10) = 900; v_Cp( 10 ) = 0.277; v_Cv( 10 ) = 0.2108; v_S( 10 ) = 0;
    v_t(11) = 1000; v_Cp( 11 ) = 0.2799; v_Cv( 11 ) = 0.2137; v_S( 11 ) = 0;
    v_t(12) = 1100; v_Cp( 12 ) = 0.2824; v_Cv( 12 ) = 0.2165; v_S( 12 ) = 0;
    v_t(13) = 1200; v_Cp( 13 ) = 0.2845; v_Cv( 13 ) = 0.2183; v_S( 13 ) = 0;
    v_t(14) = 1300; v_Cp( 14 ) = 0.2864; v_Cv( 14 ) = 0.2202; v_S( 14 ) = 0;
    v_t(15) = 1400; v_Cp( 15 ) = 0.2881; v_Cv( 15 ) = 0.2219; v_S( 15 ) = 0;
    v_t(16) = 1500; v_Cp( 16 ) = 0.2895; v_Cv( 16 ) = 0.2233; v_S( 16 ) = 0;
    v_t(17) = 1600; v_Cp( 17 ) = 0.2907; v_Cv( 17 ) = 0.2245; v_S( 17 ) = 0;
    v_t(18) = 1700; v_Cp( 18 ) = 0.2918; v_Cv( 18 ) = 0.2256; v_S( 18 ) = 0;
    v_t(19) = 1800; v_Cp( 19 ) = 0.2928; v_Cv( 19 ) = 0.2267; v_S( 19 ) = 0;
    v_t(20) = 1900; v_Cp( 20 ) = 0.2938; v_Cv( 20 ) = 0.2276; v_S( 20 ) = 0;
    v_t(21) = 2000; v_Cp( 21 ) = 0.2947; v_Cv( 21 ) = 0.2285; v_S( 21 ) = 0;
    v_t(22) = 2100; v_Cp( 22 ) = 0.2954; v_Cv( 22 ) = 0.2292; v_S( 22 ) = 0;
    v_t(23) = 2200; v_Cp( 23 ) = 0.296; v_Cv( 23 ) = 0.2299; v_S( 23 ) = 0;
    v_t(24) = 2300; v_Cp( 24 ) = 0.2967; v_Cv( 24 ) = 0.2305; v_S( 24 ) = 0;
    v_t(25) = 2400; v_Cp( 25 ) = 0.2973; v_Cv( 25 ) = 0.2311; v_S( 25 ) = 0;
    v_t(26) = 2500; v_Cp( 26 ) = 0.2978; v_Cv( 26 ) = 0.2317; v_S( 26 ) = 0;
    v_t(27) = 2600; v_Cp( 27 ) = 0.2984; v_Cv( 27 ) = 0.2322; v_S( 27 ) = 0;
    v_t(28) = 2700; v_Cp( 28 ) = 0.2989; v_Cv( 28 ) = 0.2323; v_S( 28 ) = 0;
    v_t(29) = 2800; v_Cp( 29 ) = 0.2994; v_Cv( 29 ) = 0.2333; v_S( 29 ) = 0;
    v_t(30) = 2900; v_Cp( 30 ) = 0.2999; v_Cv( 30 ) = 0.2338; v_S( 30 ) = 0;
    v_t(31) = 3000; v_Cp( 31 ) = 0.3004; v_Cv( 31 ) = 0.2342; v_S( 31 ) = 0;
     v_t=v_t/1000.0;
    reculc_polynoms();    
    
    cout 
    << Name() << endl
    << Formula() << endl;
    cout << p_t_Cp;
    cout << p_t_Cv ;
    cout << p_t_S ;
    int i =0;
    while (i<=3000)    {      cout << i <<"   "<<Cp(i)  <<"   "<< Cv(i) <<"   "<< S(i)<< endl;       i+=100;    }
}

NO::~NO()
{}

  string NO::Name()
  {
  return "NO";
  }
  string NO::Formula()
  {
  return "NO";
  }
}
