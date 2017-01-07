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

#include "c3h8.h"

namespace ns_MNAS_Gases
{
C3H8::C3H8() : teplojomkost()
{
    set_v_max( 13 );
    v_t(1) = 0; v_Cp( 1 ) = 0.3701; v_Cv( 1 ) = 0.325; v_S( 1 ) = 0;
    v_t(2) = 100; v_Cp( 2 ) = 0.4817; v_Cv( 2 ) = 0.4366; v_S( 2 ) = 0;
    v_t(3) = 200; v_Cp( 3 ) = 0.5871; v_Cv( 3 ) = 0.512; v_S( 3 ) = 0;
    v_t(4) = 300; v_Cp( 4 ) = 0.677; v_Cv( 4 ) = 0.6318; v_S( 4 ) = 0;
    v_t(5) = 400; v_Cp( 5 ) = 0.755; v_Cv( 5 ) = 0.7098; v_S( 5 ) = 0;
    v_t(6) = 500; v_Cp( 6 ) = 0.8237; v_Cv( 6 ) = 0.7786; v_S( 6 ) = 0;
    v_t(7) = 600; v_Cp( 7 ) = 0.8831; v_Cv( 7 ) = 0.838; v_S( 7 ) = 0;
    v_t(8) = 700; v_Cp( 8 ) = 0.9353; v_Cv( 8 ) = 0.8901; v_S( 8 ) = 0;
    v_t(9) = 800; v_Cp( 9 ) = 0.9775; v_Cv( 9 ) = 0.9323; v_S( 9 ) = 0;
    v_t(10) = 900; v_Cp( 10 ) = 1.0151; v_Cv( 10 ) = 0.97; v_S( 10 ) = 0;
    v_t(11) = 1000; v_Cp( 11 ) = 1.0496; v_Cv( 11 ) = 1.0044; v_S( 11 ) = 0;
    v_t(12) = 1100; v_Cp( 12 ) = 1.0811; v_Cv( 12 ) = 1.036; v_S( 12 ) = 0;
    v_t(13) = 1200; v_Cp( 13 ) = 1.1094; v_Cv( 13 ) = 1.0643; v_S( 13 ) = 0;
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

C3H8::~C3H8()
{}
  string C3H8::Name()
  {
  return "пропан";
  }
  string C3H8::Formula()
  {
  return "C3H8";
  }
}
