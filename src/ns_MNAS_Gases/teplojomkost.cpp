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

#include <math.h>
#include "teplojomkost.h"
#include "table.h"

using namespace ns_MNAS_Matrix;

namespace ns_MNAS_Gases
{
teplojomkost::teplojomkost() : v_max( 0 )
{
    /*v_t, v_Cp, v_Cv, v_S, */
}

teplojomkost::~teplojomkost()
{}

void teplojomkost::set_v_max( int size )
{
    v_max = size;
    v_t.set_size( size );
    v_Cp.set_size( size );
    v_Cv.set_size( size );
    v_S.set_size( size );
}

void teplojomkost::reculc_polynoms( void )
{
    { /*Расчет коэффициентов полинома  для зависимости истинной изобарной теплоемкости от температуры.*/
        FPolynom p_t_Cp_tmp( 1, 6, 1 );
        FMatrix X( v_t, FMatrix :: as_column );
        FVector Y( v_Cp );
        table tbl( X, Y );
        tbl.culc_Polynom_Koeff( p_t_Cp_tmp );
        p_t_Cp = p_t_Cp_tmp;
    }
    { /*Расчет коэффициентов полинома  для зависимости истинной изохорной теплоемкости от температуры.*/
        FPolynom p_t_Cv_tmp( 1, 6, 1 );
        FMatrix X( v_t, FMatrix :: as_column );
        FVector Y( v_Cv );
        table tbl( X, Y );
        tbl.culc_Polynom_Koeff( p_t_Cv_tmp );
        p_t_Cv = p_t_Cv_tmp;
    }
    { /*Расчет коэффициентов полинома  для зависимости энторопии от температуры.*/
        FPolynom p_t_S_tmp( 1, 6, 1 );
        FMatrix X( v_t, FMatrix :: as_column );
        FVector Y( v_S );
        table tbl( X, Y );
        tbl.culc_Polynom_Koeff( p_t_S_tmp );
        p_t_S = p_t_S_tmp;
    }
    {/*Первообразная от полинома зависимости истинной изобарной теплоемкости от температуры.*/
        I_p_t_Cp=p_t_Cp.Integral(1);
    }
    {/*Первообразная от полинома зависимости истинной изохорной теплоемкости от температуры.*/
        I_p_t_Cv = p_t_Cv.Integral(1);
    }
}

double teplojomkost::I( double t )
{
    return Cpm(0.0, t)*t;
}

double teplojomkost::S( double t )
{
    return this->p_t_S.poly(t);
}

double teplojomkost::Cp( double t )
{
    return p_t_Cp.poly( t / 1000.0 );
}
double teplojomkost::Cv( double t )
{
    return p_t_Cv.poly( t / 1000.0 );
}

double teplojomkost::Cpm( double t1, double t2 )
{
    if((t2-t1)*(t2-t1)>=0.01)
    {
        double I_t2_Cp=I_p_t_Cp.poly(t2/1000.0);
        double I_t1_Cp=I_p_t_Cp.poly(t1/1000.0);
        double I_dt_Cp=I_t2_Cp-I_t1_Cp;
        double dt=(t2/1000.0-t1/1000.0);
        double rez = I_dt_Cp/dt;
        return rez;
    }
    else
        return p_t_Cp.poly((t2+t1)/1000.0/2.0);
}
double teplojomkost::Cvm( double t1, double t2 )
{
    if((t2-t1)*(t2-t1)>=0.01)
    {
        double I_t2_Cv=I_p_t_Cv.poly(t2/1000.0);
        double I_t1_Cv=I_p_t_Cv.poly(t1/1000.0);
        double I_dt_Cv=I_t2_Cv-I_t1_Cv;
        double dt=(t2/1000.0-t1/1000.0);
        double rez = I_dt_Cv/dt;
        return rez;
    }
    else
        return p_t_Cv.poly((t2+t1)/1000.0/2.0);
}
}
