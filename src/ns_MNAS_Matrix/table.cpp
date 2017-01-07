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
#include "table.h"

using namespace std;

using namespace ns_MNAS_Matrix;

namespace ns_MNAS_Matrix
{
    table::table()
    {}

    table::table( FMatrix X, FVector Y )
    {
        x = X;
        y = Y;
    }

    table::~table()
    {}

    int table::get_n_args() const
    {
        return x.cols();
    }

    int table::get_n_points() const
    {
        return x.rows();
    }

    bool table::culc_Polynom_Koeff( FPolynom &p )
    {
        int n_koeff = p.get_n_koeff();
        int n_args = p.get_n_args();
        int n_points = get_n_points();
        FMatrix matr( n_koeff, n_koeff );
        FVector vect( n_koeff );
        FMatrix p_matrix = p.get_matrix();

        for ( int i = 1 ; i <= n_koeff ; i++ )       //Цикл по строкам
        {
            FVector v_i = p_matrix.get_col( i );
            FPolynom poly_i( FVector ( 1.0 ), FMatrix( v_i, FMatrix::as_column ) );

            for ( int m = 1; m <= n_points ; m++ )     //Цикл по точкам таблицы
            {
                vect( i ) += poly_i.poly( get_args( m ) ) * get_rez( m );
            }
            for ( int j = 1 ; j <= n_koeff; j++ )       //Цикл по столбцам
            {
                FVector v_j = p_matrix.get_col( j );
                FVector v_ij = v_i + v_j;
                FPolynom poly_ij( FVector ( 1.0 ), FMatrix ( v_ij, FMatrix::as_column ) );

                for ( int n = 1; n <= n_points ; n++ )     //Цикл по точкам таблицы
                {
                    matr( i, j ) += poly_ij.poly( get_args( n ) );
                }
            }
        }
        FMatrix rez = matr.Obratn() * FMatrix( vect, FMatrix::as_column );
        p.set( rez.get_col( 1 ) );
        return true;
    }

    FVector table::get_args( int i ) const
    {
        return x.get_row( i );
    }

    double table::get_rez( int i ) const
    {
        return y( i );
    }

    ostream& operator<< ( ostream& ostr, table const &tbl )
    {
        ostr << tbl.get_n_points() << " " << tbl.get_n_args() << endl;
        for ( int i = 1; i <= tbl.get_n_points(); i++ )
        {
            for ( int j = 1; j <= tbl.get_n_args(); j++ )
            {
                ostr << tbl.x( i, j ) << " ";
            }
            ostr << tbl.y( i ) << endl;
        }
        return ostr;
    }

    istream& operator>> ( istream& istr, table &tbl )
    {
        int n_points = 0;
        int n_args = 0;
        istr >> n_points >> n_args;
        tbl.x.set_dims( n_points, n_args );
        tbl.y.set_size( n_points );
        for ( int i = 1; i <= tbl.get_n_points(); i++ )
        {
            for ( int j = 1; j <= tbl.get_n_args(); j++ )
            {
                istr >> tbl.x( i, j );
            }
            istr >> tbl.y( i );
        }
        return istr;
    }
};
