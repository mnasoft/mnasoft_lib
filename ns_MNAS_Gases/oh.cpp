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

#include "oh.h"

namespace ns_MNAS_Gases
{
OH::OH() : teplojomkost()
{
    set_v_max( 31 );
    v_t(1) = 0; v_Cp( 1 ) = 0.4212; v_Cv( 1 ) = 0.3044; v_S( 1 ) = 0;
    v_t(2) = 100; v_Cp( 2 ) = 0.4163; v_Cv( 2 ) = 0.2995; v_S( 2 ) = 0;
    v_t(3) = 200; v_Cp( 3 ) = 0.4143; v_Cv( 3 ) = 0.2975; v_S( 3 ) = 0;
    v_t(4) = 300; v_Cp( 4 ) = 0.4142; v_Cv( 4 ) = 0.2974; v_S( 4 ) = 0;
    v_t(5) = 400; v_Cp( 5 ) = 0.4157; v_Cv( 5 ) = 0.2989; v_S( 5 ) = 0;
    v_t(6) = 500; v_Cp( 6 ) = 0.4191; v_Cv( 6 ) = 0.3023; v_S( 6 ) = 0;
    v_t(7) = 600; v_Cp( 7 ) = 0.4237; v_Cv( 7 ) = 0.3069; v_S( 7 ) = 0;
    v_t(8) = 700; v_Cp( 8 ) = 0.4294; v_Cv( 8 ) = 0.3126; v_S( 8 ) = 0;
    v_t(9) = 800; v_Cp( 9 ) = 0.4358; v_Cv( 9 ) = 0.319; v_S( 9 ) = 0;
    v_t(10) = 900; v_Cp( 10 ) = 0.4424; v_Cv( 10 ) = 0.3256; v_S( 10 ) = 0;
    v_t(11) = 1000; v_Cp( 11 ) = 0.4489; v_Cv( 11 ) = 0.3321; v_S( 11 ) = 0;
    v_t(12) = 1100; v_Cp( 12 ) = 0.4553; v_Cv( 12 ) = 0.3385; v_S( 12 ) = 0;
    v_t(13) = 1200; v_Cp( 13 ) = 0.4615; v_Cv( 13 ) = 0.3447; v_S( 13 ) = 0;
    v_t(14) = 1300; v_Cp( 14 ) = 0.4674; v_Cv( 14 ) = 0.3506; v_S( 14 ) = 0;
    v_t(15) = 1400; v_Cp( 15 ) = 0.4728; v_Cv( 15 ) = 0.356; v_S( 15 ) = 0;
    v_t(16) = 1500; v_Cp( 16 ) = 0.4779; v_Cv( 16 ) = 0.3611; v_S( 16 ) = 0;
    v_t(17) = 1600; v_Cp( 17 ) = 0.4827; v_Cv( 17 ) = 0.3659; v_S( 17 ) = 0;
    v_t(18) = 1700; v_Cp( 18 ) = 0.4872; v_Cv( 18 ) = 0.3704; v_S( 18 ) = 0;
    v_t(19) = 1800; v_Cp( 19 ) = 0.4913; v_Cv( 19 ) = 0.3745; v_S( 19 ) = 0;
    v_t(20) = 1900; v_Cp( 20 ) = 0.4951; v_Cv( 20 ) = 0.3783; v_S( 20 ) = 0;
    v_t(21) = 2000; v_Cp( 21 ) = 0.4986; v_Cv( 21 ) = 0.3818; v_S( 21 ) = 0;
    v_t(22) = 2100; v_Cp( 22 ) = 0.502; v_Cv( 22 ) = 0.3852; v_S( 22 ) = 0;
    v_t(23) = 2200; v_Cp( 23 ) = 0.5051; v_Cv( 23 ) = 0.3883; v_S( 23 ) = 0;
    v_t(24) = 2300; v_Cp( 24 ) = 0.5031; v_Cv( 24 ) = 0.3913; v_S( 24 ) = 0;
    v_t(25) = 2400; v_Cp( 25 ) = 0.5109; v_Cv( 25 ) = 0.3941; v_S( 25 ) = 0;
    v_t(26) = 2500; v_Cp( 26 ) = 0.5137; v_Cv( 26 ) = 0.3969; v_S( 26 ) = 0;
    v_t(27) = 2600; v_Cp( 27 ) = 0.5194; v_Cv( 27 ) = 0.3996; v_S( 27 ) = 0;
    v_t(28) = 2700; v_Cp( 28 ) = 0.519; v_Cv( 28 ) = 0.4022; v_S( 28 ) = 0;
    v_t(29) = 2800; v_Cp( 29 ) = 0.5215; v_Cv( 29 ) = 0.4047; v_S( 29 ) = 0;
    v_t(30) = 2900; v_Cp( 30 ) = 0.5239; v_Cv( 30 ) = 0.4071; v_S( 30 ) = 0;
    v_t(31) = 3000; v_Cp( 31 ) = 0.5263; v_Cv( 31 ) = 0.4095; v_S( 31 ) = 0;
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
OH::~OH()
{}
  string OH::Name()
  {
  return "гидроксильная группа";
  }
  string OH::Formula()
  {
  return "OH";
  }
}
