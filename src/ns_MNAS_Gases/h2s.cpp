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

#include "h2s.h"

namespace ns_MNAS_Gases
{
H2S::H2S() : teplojomkost()
{
    set_v_max( 24 );
    v_t(1) = 0; v_Cp( 1 ) = 0.237; v_Cv( 1 ) = 0.178; v_S( 1 ) = 0;
    v_t(2) = 100; v_Cp( 2 ) = 0.245; v_Cv( 2 ) = 0.186; v_S( 2 ) = 0;
    v_t(3) = 200; v_Cp( 3 ) = 0.255; v_Cv( 3 ) = 0.197; v_S( 3 ) = 0;
    v_t(4) = 300; v_Cp( 4 ) = 0.268; v_Cv( 4 ) = 0.209; v_S( 4 ) = 0;
    v_t(5) = 400; v_Cp( 5 ) = 0.28; v_Cv( 5 ) = 0.222; v_S( 5 ) = 0;
    v_t(6) = 500; v_Cp( 6 ) = 0.293; v_Cv( 6 ) = 0.234; v_S( 6 ) = 0;
    v_t(7) = 600; v_Cp( 7 ) = 0.304; v_Cv( 7 ) = 0.246; v_S( 7 ) = 0;
    v_t(8) = 700; v_Cp( 8 ) = 0.315; v_Cv( 8 ) = 0.257; v_S( 8 ) = 0;
    v_t(9) = 800; v_Cp( 9 ) = 0.325; v_Cv( 9 ) = 0.267; v_S( 9 ) = 0;
    v_t(10) = 900; v_Cp( 10 ) = 0.334; v_Cv( 10 ) = 0.276; v_S( 10 ) = 0;
    v_t(11) = 1000; v_Cp( 11 ) = 0.342; v_Cv( 11 ) = 0.283; v_S( 11 ) = 0;
    v_t(12) = 1100; v_Cp( 12 ) = 0.349; v_Cv( 12 ) = 0.29; v_S( 12 ) = 0;
    v_t(13) = 1200; v_Cp( 13 ) = 0.354; v_Cv( 13 ) = 0.296; v_S( 13 ) = 0;
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

H2S::~H2S()
{}

  string H2S::Name()
  {
  return "H2S";
  }
  string H2S::Formula()
  {
  return "H2S";
  }
}
