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

#include "no2.h"

namespace ns_MNAS_Gases
{
NO2::NO2() : teplojomkost()
{
    set_v_max( 24 );
    v_t(1) = 0; v_Cp( 1 ) = 0.203; v_Cv( 1 ) = 0.158; v_S( 1 ) = 0;
    v_t(2) = 50; v_Cp( 2 ) = 0.216; v_Cv( 2 ) = 0.171; v_S( 2 ) = 0;
    v_t(3) = 100; v_Cp( 3 ) = 0.227; v_Cv( 3 ) = 0.182; v_S( 3 ) = 0;
    v_t(4) = 150; v_Cp( 4 ) = 0.237; v_Cv( 4 ) = 0.192; v_S( 4 ) = 0;
    v_t(5) = 200; v_Cp( 5 ) = 0.246; v_Cv( 5 ) = 0.201; v_S( 5 ) = 0;
    v_t(6) = 250; v_Cp( 6 ) = 0.254; v_Cv( 6 ) = 0.209; v_S( 6 ) = 0;
    v_t(7) = 300; v_Cp( 7 ) = 0.261; v_Cv( 7 ) = 0.216; v_S( 7 ) = 0;
    v_t(8) = 350; v_Cp( 8 ) = 0.268; v_Cv( 8 ) = 0.223; v_S( 8 ) = 0;
    v_t(9) = 400; v_Cp( 9 ) = 0.274; v_Cv( 9 ) = 0.229; v_S( 9 ) = 0;
    v_t(10) = 450; v_Cp( 10 ) = 0.28; v_Cv( 10 ) = 0.235; v_S( 10 ) = 0;
    v_t(11) = 500; v_Cp( 11 ) = 0.285; v_Cv( 11 ) = 0.24; v_S( 11 ) = 0;
    v_t(12) = 550; v_Cp( 12 ) = 0.29; v_Cv( 12 ) = 0.245; v_S( 12 ) = 0;
    v_t(13) = 600; v_Cp( 13 ) = 0.294; v_Cv( 13 ) = 0.249; v_S( 13 ) = 0;
    v_t(14) = 650; v_Cp( 14 ) = 0.298; v_Cv( 14 ) = 0.253; v_S( 14 ) = 0;
    v_t(15) = 700; v_Cp( 15 ) = 0.302; v_Cv( 15 ) = 0.257; v_S( 15 ) = 0;
    v_t(16) = 750; v_Cp( 16 ) = 0.305; v_Cv( 16 ) = 0.26; v_S( 16 ) = 0;
    v_t(17) = 800; v_Cp( 17 ) = 0.308; v_Cv( 17 ) = 0.263; v_S( 17 ) = 0;
    v_t(18) = 850; v_Cp( 18 ) = 0.311; v_Cv( 18 ) = 0.266; v_S( 18 ) = 0;
    v_t(19) = 900; v_Cp( 19 ) = 0.314; v_Cv( 19 ) = 0.269; v_S( 19 ) = 0;
    v_t(20) = 950; v_Cp( 20 ) = 0.317; v_Cv( 20 ) = 0.272; v_S( 20 ) = 0;
    v_t(21) = 1000; v_Cp( 21 ) = 0.319; v_Cv( 21 ) = 0.274; v_S( 21 ) = 0;
    v_t(22) = 1050; v_Cp( 22 ) = 0.321; v_Cv( 22 ) = 0.276; v_S( 22 ) = 0;
    v_t(23) = 1100; v_Cp( 23 ) = 0.323; v_Cv( 23 ) = 0.279; v_S( 23 ) = 0;
    v_t(24) = 1150; v_Cp( 24 ) = 0.325; v_Cv( 24 ) = 0.28; v_S( 24 ) = 0;
     v_t=v_t/1000.0;
    reculc_polynoms();        
    
    cout 
    << Name() << endl
    << Formula() << endl;
    cout << p_t_Cp;
    cout << p_t_Cv ;
    cout << p_t_S ;
    int i =0;
    while (i<=1150)    {      cout << i <<"   "<<Cp(i)  <<"   "<< Cv(i) <<"   "<< S(i)<< endl;       i+=50;    }
}

NO2::~NO2()
{}
  string NO2::Name()
  {
  return "NO2";
  }
  string NO2::Formula()
  {
  return "NO2";
  }
}
