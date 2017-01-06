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

#include "h2.h"

namespace ns_MNAS_Gases
{
H2::H2() : teplojomkost()
{
    set_v_max( 28 );
    v_t(1) = 0; v_Cp( 1 ) = 3.3904; v_Cv( 1 ) = 2.4053; v_S( 1 ) = 0;
    v_t(2) = 100; v_Cp( 2 ) = 3.4509; v_Cv( 2 ) = 2.4658; v_S( 2 ) = 0;
    v_t(3) = 200; v_Cp( 3 ) = 3.4643; v_Cv( 3 ) = 2.4792; v_S( 3 ) = 0;
    v_t(4) = 300; v_Cp( 4 ) = 3.4712; v_Cv( 4 ) = 2.4861; v_S( 4 ) = 0;
    v_t(5) = 400; v_Cp( 5 ) = 3.4826; v_Cv( 5 ) = 2.4975; v_S( 5 ) = 0;
    v_t(6) = 500; v_Cp( 6 ) = 3.502; v_Cv( 6 ) = 2.5169; v_S( 6 ) = 0;
    v_t(7) = 600; v_Cp( 7 ) = 3.5298; v_Cv( 7 ) = 2.5446; v_S( 7 ) = 0;
    v_t(8) = 700; v_Cp( 8 ) = 3.566; v_Cv( 8 ) = 2.5808; v_S( 8 ) = 0;
    v_t(9) = 800; v_Cp( 9 ) = 3.6101; v_Cv( 9 ) = 2.625; v_S( 9 ) = 0;
    v_t(10) = 900; v_Cp( 10 ) = 3.6572; v_Cv( 10 ) = 2.6721; v_S( 10 ) = 0;
    v_t(11) = 1000; v_Cp( 11 ) = 3.7063; v_Cv( 11 ) = 2.7212; v_S( 11 ) = 0;
    v_t(12) = 1100; v_Cp( 12 ) = 3.7584; v_Cv( 12 ) = 2.7733; v_S( 12 ) = 0;
    v_t(13) = 1200; v_Cp( 13 ) = 3.8095; v_Cv( 13 ) = 2.8241; v_S( 13 ) = 0;
    v_t(14) = 1300; v_Cp( 14 ) = 3.8611; v_Cv( 14 ) = 2.876; v_S( 14 ) = 0;
    v_t(15) = 1400; v_Cp( 15 ) = 3.9097; v_Cv( 15 ) = 2.9246; v_S( 15 ) = 0;
    v_t(16) = 1500; v_Cp( 16 ) = 3.9563; v_Cv( 16 ) = 2.9712; v_S( 16 ) = 0;
    v_t(17) = 1600; v_Cp( 17 ) = 4.0000; v_Cv( 17 ) = 3.0149; v_S( 17 ) = 0;
    v_t(18) = 1700; v_Cp( 18 ) = 4.0417; v_Cv( 18 ) = 3.0563; v_S( 18 ) = 0;
    v_t(19) = 1800; v_Cp( 19 ) = 4.0808; v_Cv( 19 ) = 3.0957; v_S( 19 ) = 0;
    v_t(20) = 1900; v_Cp( 20 ) = 4.1185; v_Cv( 20 ) = 3.1334; v_S( 20 ) = 0;
    v_t(21) = 2000; v_Cp( 21 ) = 4.1533; v_Cv( 21 ) = 3.1681; v_S( 21 ) = 0;
    v_t(22) = 2100; v_Cp( 22 ) = 4.186; v_Cv( 22 ) = 3.2009; v_S( 22 ) = 0;
    v_t(23) = 2200; v_Cp( 23 ) = 4.2182; v_Cv( 23 ) = 3.2331; v_S( 23 ) = 0;
    v_t(24) = 2300; v_Cp( 24 ) = 4.2475; v_Cv( 24 ) = 3.2624; v_S( 24 ) = 0;
    v_t(25) = 2400; v_Cp( 25 ) = 4.2758; v_Cv( 25 ) = 3.2907; v_S( 25 ) = 0;
    v_t(26) = 2500; v_Cp( 26 ) = 4.3026; v_Cv( 26 ) = 3.3175; v_S( 26 ) = 0;
    v_t(27) = 2600; v_Cp( 27 ) = 4.3279; v_Cv( 27 ) = 3.3428; v_S( 27 ) = 0;
    v_t(28) = 2700; v_Cp( 28 ) = 4.3517; v_Cv( 28 ) = 3.3666; v_S( 28 ) = 0;
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

H2::~H2()
{}

  string H2::Name()
  {
  return "водород";
  }
  string H2::Formula()
  {
  return "H2";
  }
}
