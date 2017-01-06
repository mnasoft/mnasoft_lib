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
#include "fdigbase.h"

namespace ns_MNAS_Matrix
{
    FDig::FDig( ) : val( 0 ) , base ( 10 )
    {}

    FDig::FDig( int Val , int Base ) : val( Val ) , base ( 10 )
    {
        SetBase( Base );
    }

    FDig::~FDig()
    {}

    int FDig::Digit( int Razrjad ) const
    {
        int tmp = val;
        for ( int i = 0; i < Razrjad;i++ )
            tmp /= base;
        return tmp -( tmp / base ) * base ;
    }

    int FDig::DigitsSumm( void ) const
    {
        int tmp = val;
        int summ = 0;
        while ( tmp )
        {
            int tmp1 = tmp / base;
            summ += tmp - tmp1 * base;
            tmp = tmp1;
        }
        return summ;
    }

    int FDig::NonZeroDigitsSumm( void ) const
    {
        int tmp = val;
        int summ = 0;
        while ( tmp )
        {
            int tmp1 = tmp / base;
if(tmp - tmp1 * base)

            summ ++;
            tmp = tmp1;
        }
        return summ;
    }


    int FDig::SetBase( int Base )
    {
        if ( Base > 1 ) base = Base;
        return base;
    }

    int FDig::Razrjad( void ) const
    {
        int razr = 0;
        int tmp = val;
        while ( tmp )
        {
            razr++; tmp /= base;
        }
        return razr;
    }

    ostream& operator<<( ostream& o, FDig const & dig )
    {
        int n = dig.Razrjad();
        cout << dig.base << " " << dig.val << " ";
        if ( n == 0 )
            o << " " << 0 ;
        while ( n > 0 )
        {
            o << " " << dig.Digit( --n ) ;
        }
        return o;
    }

    istream& operator>>( istream& i, FDig & dig )
    {
        return i;
    }

};
