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
#include "ch4.h"

namespace ns_MNAS_Gases
{
CH4::CH4() : teplojomkost()
{
    set_v_max( 13 );
    v_t(1) = 0; v_Cp( 1 ) = 0.5172; v_Cv( 1 ) = 0.3934; v_S( 1 ) = 0;
    v_t(2) = 100; v_Cp( 2 ) = 0.5848; v_Cv( 2 ) = 0.461; v_S( 2 ) = 0;
    v_t(3) = 200; v_Cp( 3 ) = 0.6704; v_Cv( 3 ) = 0.5466; v_S( 3 ) = 0;
    v_t(4) = 300; v_Cp( 4 ) = 0.7584; v_Cv( 4 ) = 0.6346; v_S( 4 ) = 0;
    v_t(5) = 400; v_Cp( 5 ) = 0.843; v_Cv( 5 ) = 0.7192; v_S( 5 ) = 0;
    v_t(6) = 500; v_Cp( 6 ) = 0.921; v_Cv( 6 ) = 0.7972; v_S( 6 ) = 0;
    v_t(7) = 600; v_Cp( 7 ) = 0.9919; v_Cv( 7 ) = 0.8681; v_S( 7 ) = 0;
    v_t(8) = 700; v_Cp( 8 ) = 1.056; v_Cv( 8 ) = 0.9322; v_S( 8 ) = 0;
    v_t(9) = 800; v_Cp( 9 ) = 1.1129; v_Cv( 9 ) = 0.9891; v_S( 9 ) = 0;
    v_t(10) = 900; v_Cp( 10 ) = 1.1638; v_Cv( 10 ) = 1.04; v_S( 10 ) = 0;
    v_t(11) = 1000; v_Cp( 11 ) = 1.2089; v_Cv( 11 ) = 1.0851; v_S( 11 ) = 0;
    v_t(12) = 1100; v_Cp( 12 ) = 1.2483; v_Cv( 12 ) = 1.1245; v_S( 12 ) = 0;
    v_t(13) = 1200; v_Cp( 13 ) = 1.282; v_Cv( 13 ) = 1.1582; v_S( 13 ) = 0;
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

CH4::~CH4()
{}
  string CH4::Name()
  {
  return "метан";
  }
  string CH4::Formula()
  {
  return "CH4";
  }
}
