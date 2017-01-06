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
#include "fvector.h"

namespace ns_MNAS_Matrix
{
double FVector::val = 0;

FVector::FVector() : size( 0 ), first( 0 )
{}

FVector::FVector( FVector const & a ) : size( a.size ), first( 0 )
{
        int p;
        if ( size > 0 )
                first = new double[ size ];
        if ( first )
                for ( p = 1;p <= size;p++ )
                        operator() ( p ) =a( p );
        else
                size = 0;
}


FVector::FVector( int P ) : first( 0 ), size( P )
{
        if ( size < 0 ) {
                size = 0;
                return ;
        }
        first = new double [ size ];
        if ( first )
                for ( int p = 1;p <= size;p++ )
                        operator() ( p ) =0.0;
        else
                size = 0;
}

FVector::FVector( double d ) : first( 0 ), size( 1 )
{
        first = new double [ size ];
        operator() ( 1 ) =d;
}

FVector::FVector( double* array, int P ) : first( 0 )
{
        if ( P > 0 ) {
                size = P;
                first = new double [ P ];
                if ( first )
                        for ( int p = 1;p <= size;p++ )
                                operator() ( p ) =array[ p ];
                else
                        size = 0;
        } else
                size = 0;
}

FVector::~FVector()
{
        if ( first )
                delete [] first;
}

FVector& FVector::operator=( FVector const & a )
{
        if ( size != a.size ) {
                size = a.size;
                delete [] first;
                first = 0;
                first = new double[ a.size ];
        }
        if ( first ) {
                for ( int p = 1;p <= size;p++ )
                        operator() ( p ) =a( p );
        } else
                size = 0;
        return *this;
}

FVector& FVector::operator=( double a )
{
        int p;
        for ( p = 1;p <= size;p++ )
                operator() ( p ) =a;
        return *this;
}


FVector operator+( FVector const & a, FVector const & b )
{
        int p;
        if ( a.size > b.size )
                p = a.size;
        else
                p = b.size;
        FVector d( p );
        for ( p = 1;p <= d.size;p++ ) {
                FVector ::val = 0;
                d( p ) = a( p ) + b( p );
        }
        return d;
}

FVector operator-( FVector const & a, FVector const & b )
{
        int p;
        if ( a.size > b.size )
                p = a.size;
        else
                p = b.size;
        FVector d( p );

        for ( p = 1;p <= d.size;p++ ) {
                FVector ::val = 0;
                d( p ) = a( p ) - b( p );
        }
        return d;
}

FVector operator-( FVector const & a )
{
        FVector d( a.size );
        for ( int p = 1;p <= d.size;p++ ) {
                FVector ::val = 0;
                d( p ) = -a( p );
        }
        return d;
}

FVector operator+( FVector const & a )
{
        FVector d = a;
        return d;
}

FVector operator*( FVector const & a, FVector const & b )
{
        int p = a.size;
        FVector d( p );
        int i;
        for ( i = 1;i <= p;i++ ) {
                FVector::val = 0;
                d( i ) = a( i ) * b( i );
        }
        return d;
}
FVector operator/( FVector const & a, FVector const & b )
{
        int p = a.size;
        FVector d( p );
        int i;
        for ( i = 1;i <= p;i++ ) {
                FVector::val = 0;
                d( i ) = a( i ) / b( i );
        }
        return d;
}

FVector v_umn( FVector const & a, FVector const & b )
{
        FVector d( 3 );
        FVector::val = 0;
        d( 1 ) = a( 2 ) * b( 3 ) - b( 2 ) * a( 3 );
        d( 2 ) = a( 3 ) * b( 1 ) - b( 3 ) * a( 1 );
        d( 3 ) = a( 1 ) * b( 2 ) - b( 1 ) * a( 2 );
        return d;
}

FVector operator*( double a, FVector const & v )
{
        FVector d = v;
        for ( int n = 1;n <= d.size;n++ ) {
                FVector::val = 0;
                d.first[ n - 1 ] *= a;
        }
        return d;
}

FVector operator*( FVector const & v, double a )
{
        FVector d = v;
        for ( int n = 1;n <= d.size;n++ ) {
                FVector::val = 0;
                d.first[ n - 1 ] *= a;
        }
        return d;
}

FVector operator/( FVector const & v, double a )
{
        FVector d = v;
        if ( a == 0. )
                a = 1.;
        for ( int n = 1;n <= d.size;n++ ) {
                FVector::val = 0;
                d.first[ n - 1 ] /= a;
        }
        return d;
}

ostream& operator<<( ostream& o, FVector const & v )
{
        o << v.size << "\n";
        for ( int p = 1;p <= v.size;p++ )
                o << v( p ) << " ";
        o << "\n";
        return o;
}

istream& operator>>( istream& i, FVector &v )
{
        int vector_length;
        i >> vector_length;
        if ( vector_length != v.size ) {
                if ( v.first ) {
                        delete [] v.first;
                        v.first = 0;
                }
                v.size = vector_length;
                v.first = new double [ v.size ];
        }

        if ( v.first ) {
                for ( int p = 1;p <= v.size;p++ )
                        i >> v( p );
        } else
                v.size = 0;
        return i;
}

double FVector::max( void ) const
{
        double mmax = -1.0e200;
        for ( int p = 1;p <= size;p++ ) {
                double aux = operator() ( p );
                if ( mmax<aux )
                        mmax = aux;
        }
        return mmax;
}

double FVector::min( void ) const
{
        double mmin = 1.0e200;
        for ( int p = 1;p <= size;p++ ) {
                double aux = operator() ( p );
                if ( mmin>aux )
                        mmin = aux;
        }
        return mmin;
}

double FVector::norma() const
{
        double summ = 0;
        for ( int p = 1; p <= size; p++ )
                summ += first[ p - 1 ] * first[ p - 1 ];
        return sqrt( summ );
}

void FVector::set_size( int s )
{
        if ( size != s ) {
                size = s;
                delete [] first;
                first = 0;
                first = new double[ size ];
        }
        if ( first == 0 ) {
                size = 0;
        }
        clean ();
}

void FVector::clean ( void )
{
        for ( int i = 1; i <= size; i++ )
                first[ i - 1 ] = 0.0;
}


FVector& FVector::normalize( void )
{
        double norm = norma();
        if ( norm >= 1e-20 )
                * this = *this / norm;
        else {
                clean();
        }
        return *this;
}


double FVector::summ_of_elements( void ) const
{
        double summ;
        for ( int i = 1; i <= this->get_size(); i++ ) {
                summ += operator() ( i );
        }
        return summ;
}


FVector& FVector::patr_of_elements( void )
{
        double summ = summ_of_elements();
        if ( summ >= 1e-20 )
                * this = *this / summ;
        else {
                clean();
        }
        return *this;
}

double& FVector::operator() ( int r )
{
        int ro=r - 1;
        if ( r < 1 || r > size )
                return val;
        return first[ ro ];
}

double& FVector::operator() ( int r ) const
{
        int ro=r - 1;
        if ( r < 1 || r > size )
                return val;
        return first[ ro ];
}

};

