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

#include "c2h6.h"

namespace ns_MNAS_Gases
{
C2H6::C2H6() : teplojomkost()
{
    set_v_max( 13 );
    v_t(1) = 0; v_Cp( 1 ) = 0.3934; v_Cv( 1 ) = 0.3274; v_S( 1 ) = 0;
    v_t(2) = 100; v_Cp( 2 ) = 0.4938; v_Cv( 2 ) = 0.4278; v_S( 2 ) = 0;
    v_t(3) = 200; v_Cp( 3 ) = 0.5947; v_Cv( 3 ) = 0.5287; v_S( 3 ) = 0;
    v_t(4) = 300; v_Cp( 4 ) = 0.6854; v_Cv( 4 ) = 0.6194; v_S( 4 ) = 0;
    v_t(5) = 400; v_Cp( 5 ) = 0.7676; v_Cv( 5 ) = 0.7016; v_S( 5 ) = 0;
    v_t(6) = 500; v_Cp( 6 ) = 0.8406; v_Cv( 6 ) = 0.7744; v_S( 6 ) = 0;
    v_t(7) = 600; v_Cp( 7 ) = 0.9045; v_Cv( 7 ) = 0.8385; v_S( 7 ) = 0;
    v_t(8) = 700; v_Cp( 8 ) = 0.9607; v_Cv( 8 ) = 0.8946; v_S( 8 ) = 0;
    v_t(9) = 800; v_Cp( 9 ) = 1.0069; v_Cv( 9 ) = 0.9408; v_S( 9 ) = 0;
    v_t(10) = 900; v_Cp( 10 ) = 1.0483; v_Cv( 10 ) = 0.9822; v_S( 10 ) = 0;
    v_t(11) = 1000; v_Cp( 11 ) = 1.0863; v_Cv( 11 ) = 1.0202; v_S( 11 ) = 0;
    v_t(12) = 1100; v_Cp( 12 ) = 1.1209; v_Cv( 12 ) = 1.0548; v_S( 12 ) = 0;
    v_t(13) = 1200; v_Cp( 13 ) = 1.1521; v_Cv( 13 ) = 1.0861; v_S( 13 ) = 0;
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

C2H6::~C2H6()
{}
  string C2H6::Name()
  {
  return "этан";
  }
  string C2H6::Formula()
  {
  return "C2H6";
  }
}
