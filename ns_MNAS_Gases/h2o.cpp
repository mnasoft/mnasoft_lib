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

#include "h2o.h"

namespace ns_MNAS_Gases
{
H2O::H2O() : teplojomkost()
{
    set_v_max( 30 );
    v_t( 1 ) = 0.0; v_Cp( 1 ) = 0.4441; v_Cv( 1 ) = 0.3339; v_S( 1 ) = 0.0;
    v_t( 2 ) = 100.0; v_Cp( 2 ) = 0.4515; v_Cv( 2 ) = 0.3413; v_S( 2 ) = 0.0;
    v_t( 3 ) = 200.0; v_Cp( 3 ) = 0.4635; v_Cv( 3 ) = 0.3533; v_S( 3 ) = 0.0;
    v_t( 4 ) = 300.0; v_Cp( 4 ) = 0.4778; v_Cv( 4 ) = 0.3675; v_S( 4 ) = 0.0;
    v_t( 5 ) = 400.0; v_Cp( 5 ) = 0.4931; v_Cv( 5 ) = 0.3828; v_S( 5 ) = 0.0;
    v_t( 6 ) = 500.0; v_Cp( 6 ) = 0.5092; v_Cv( 6 ) = 0.3989; v_S( 6 ) = 0.0;
    v_t( 7 ) = 600.0; v_Cp( 7 ) = 0.5258; v_Cv( 7 ) = 0.4156; v_S( 7 ) = 0.0;
    v_t( 8 ) = 700.0; v_Cp( 8 ) = 0.5429; v_Cv( 8 ) = 0.4327; v_S( 8 ) = 0.0;
    v_t( 9 ) = 800.0; v_Cp( 9 ) = 0.5601; v_Cv( 9 ) = 0.4499; v_S( 9 ) = 0.0;
    v_t( 10 ) = 900.0; v_Cp( 10 ) = 0.5769; v_Cv( 10 ) = 0.4666; v_S( 10 ) = 0.0;
    v_t( 11 ) = 1000.0; v_Cp( 11 ) = 0.5929; v_Cv( 11 ) = 0.4827; v_S( 11 ) = 0.0;
    v_t( 12 ) = 1100.0; v_Cp( 12 ) = 0.6080; v_Cv( 12 ) = 0.4977; v_S( 12 ) = 0.0;
    v_t( 13 ) = 1200.0; v_Cp( 13 ) = 0.6220; v_Cv( 13 ) = 0.5113; v_S( 13 ) = 0.0;
    v_t( 14 ) = 1300.0; v_Cp( 14 ) = 0.6350; v_Cv( 14 ) = 0.5248; v_S( 14 ) = 0.0;
    v_t( 15 ) = 1400.0; v_Cp( 15 ) = 0.6470; v_Cv( 15 ) = 0.5368; v_S( 15 ) = 0.0;
    v_t( 16 ) = 1500.0; v_Cp( 16 ) = 0.6581; v_Cv( 16 ) = 0.5479; v_S( 16 ) = 0.0;
    v_t( 17 ) = 1600.0; v_Cp( 17 ) = 0.6683; v_Cv( 17 ) = 0.5581; v_S( 17 ) = 0.0;
    v_t( 18 ) = 1700.0; v_Cp( 18 ) = 0.6779; v_Cv( 18 ) = 0.5677; v_S( 18 ) = 0.0;
    v_t( 19 ) = 1800.0; v_Cp( 19 ) = 0.6865; v_Cv( 19 ) = 0.5763; v_S( 19 ) = 0.0;
    v_t( 20 ) = 1900.0; v_Cp( 20 ) = 0.6944; v_Cv( 20 ) = 0.5842; v_S( 20 ) = 0.0;
    v_t( 21 ) = 2000.0; v_Cp( 21 ) = 0.7017; v_Cv( 21 ) = 0.5915; v_S( 21 ) = 0.0;
    v_t( 22 ) = 2100.0; v_Cp( 22 ) = 0.7086; v_Cv( 22 ) = 0.5984; v_S( 22 ) = 0.0;
    v_t( 23 ) = 2200.0; v_Cp( 23 ) = 0.7150; v_Cv( 23 ) = 0.6047; v_S( 23 ) = 0.0;
    v_t( 24 ) = 2300.0; v_Cp( 24 ) = 0.7208; v_Cv( 24 ) = 0.6106; v_S( 24 ) = 0.0;
    v_t( 25 ) = 2400.0; v_Cp( 24 ) = 0.7263; v_Cv( 25 ) = 0.6160; v_S( 25 ) = 0.0;
    v_t( 26 ) = 2500.0; v_Cp( 26 ) = 0.7313; v_Cv( 26 ) = 0.6211; v_S( 26 ) = 0.0;
    v_t( 27 ) = 2600.0; v_Cp( 24 ) = 0.7361; v_Cv( 27 ) = 0.6259; v_S( 27 ) = 0.0;
    v_t( 28 ) = 2700.0; v_Cp( 28 ) = 0.7406; v_Cv( 28 ) = 0.6304; v_S( 28 ) = 0.0;
    v_t( 29 ) = 2800.0; v_Cp( 29 ) = 0.7449; v_Cv( 29 ) = 0.6347; v_S( 29 ) = 0.0;
    v_t( 30 ) = 2900.0; v_Cp( 30 ) = 0.7489; v_Cv( 30 ) = 0.6387; v_S( 30 ) = 0.0;
    v_t=v_t/1000.0;
    reculc_polynoms();
    
    cout 
    << Name() << endl
    << Formula() << endl;
    cout << p_t_Cp;
    cout << p_t_Cv ;
    cout << p_t_S ;
    int i =0;
    while (i<=2900)    {      cout << i <<"   "<<Cp(i)  <<"   "<< Cv(i) <<"   "<< S(i)<< endl;       i+=100;    }
}

H2O::~H2O()
{}
  string H2O::Name()
  {
  return "вода";
  }
  string H2O::Formula()
  {
  return "H2O";
  }
}
