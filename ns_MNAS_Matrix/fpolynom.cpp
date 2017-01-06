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

#include "fpolynom.h"
#include "fdigbase.h"

#include <sstream>
#include <math.h>

using namespace std;

namespace ns_MNAS_Matrix
{
FPolynom::FPolynom()
{}

FPolynom::FPolynom( int n_param, int n_koeff ) : K( n_koeff ), M( n_param, n_koeff )
{}

FPolynom::FPolynom( int n_param, int stepen, int args_in_one_koeff )
{
    if ( n_param < 1 )
        n_param = 1;
    if ( stepen < 1 )
        stepen = 1;
    /*Максимально возможное количество неповторяющихся сочетаний аргументов, каждый из которых может находиться в степени stepen.*/
    int koeff_max = 1;
    for ( int i = 0;i < n_param;i++ )
        koeff_max *= stepen + 1;
    args_in_one_koeff = args_in_one_koeff < min ( n_param, stepen ) ? args_in_one_koeff : min ( n_param, stepen );

    FDig a( koeff_max - 1, stepen + 1 );
    int koeff = koeff_max; //Количество неповторяющихся сочетаний аргументов, сумма степеней каждого из сочетаний не превышает stepen.*/
    while ( a.val >= 0 )
    {
        if ( a.DigitsSumm() > stepen || a.NonZeroDigitsSumm() > args_in_one_koeff )
            --koeff;
        --a.val;
    }
    K.set_size( koeff );
    M.set_dims( n_param, koeff );
    a.val = koeff_max - 1;
    int j = 0; //Текущий заполняемый столбец матрицы вида полинома.
    while ( a.val >= 0 )
    {
        if ( a.DigitsSumm() <= stepen && a.NonZeroDigitsSumm() <= args_in_one_koeff )
        {
            ++j;
            for ( int i = 1; i <= n_param;i++ )
            {
                M( i, j ) = a.Digit( i - 1 );
            }
        }
        --a.val;
    }

}

FPolynom::FPolynom( FVector const & v, FMatrix const & m ) : K( v ) , M( m )
{}

FPolynom::FPolynom( FPolynom const & poly ) : K( poly.K ) , M( poly.M )
{}

FPolynom::FPolynom( string const & str )
{
    read( str );
}

FPolynom::~FPolynom()
{}

void FPolynom::set
    ( FVector const & v )
{
    K = v;
}

void FPolynom::set
    ( FMatrix const & m )
{
    M = m;
}

void FPolynom::set
    ( FPolynom const & p )
{
    K = p.K;
    M = p.M;
}

FVector FPolynom::get_koeff( void ) const
{
    return K;
}

FMatrix FPolynom::get_matrix( void ) const
{
    return M;
}

double FPolynom::poly( FVector const &x ) const
{
    double summ = 0.0;
    int row = M.rows();
    int col = M.cols();
    for ( int j = 1; j <= col; j++ )
    {
        double porizveden = K( j );
        for ( int i = 1; i <= row; i++ )
        {
            if ( M( i, j ) <= 0.000001 && -0.000001 <= M( i, j ) )
                porizveden *= 1.0;
            else
                porizveden *= pow( x( i ), M( i, j ) );
        }
        summ += porizveden;
    }
    return summ;
}

FPolynom & FPolynom::operator=( FPolynom const & p )
{
    K = p.K;
    M = p.M;
}

int FPolynom::get_n_koeff( void ) const
{
    return M.cols();
}

int FPolynom::get_n_args( void ) const
{
    return M.rows();
}

ostream& FPolynom::write( ostream& os ) const
{
    int row = M.rows();
    int col = M.cols();
    for ( int j = 1; j <= col; j++ )
    {
        if ( j != 1 && K( j ) > 0.0 )
            os << "+";
        os << K( j );
        for ( int i = 1; i <= row; i++ )
        {
            if ( -0.000001 <= M( i, j ) && M( i, j ) <= 0.000001 )
                ;
            else if ( -0.000001 <= ( M( i, j ) - 1.0 ) && ( M( i, j ) - 1.0 ) <= 0.000001 )
            {
                os << "*x" << i;
            }
            else
            {
                os << "*x" << i;
                os << "^" << M( i, j );
            }
        }
    }
    os << endl;
    return os;
}

istream& FPolynom::read( istream& is )
{
    char buf[ 10000 ];
    int curr_pos = 0;
    int search_pos = 0;
    int search_pl_min;
    string b;
    //Условие выхода из цикла по разбору сумм.
    int doing = 1;
    //Порядковый номер разбиррраемоого коэффициента. И количество столбцов матрицы.
    int num_koeff = 0;
    // Количество аргументов полинома.
    int num_args = 0;
    FMatrix MM( 10, 10 );
    FVector KK( 10 );
    is.getline( buf, 9999 );
    string a = buf;
    do
    {
        search_pl_min = a.find_first_of( "+-", search_pos );
        if ( search_pl_min != string::npos )
        {
            b = a.substr( curr_pos, search_pl_min - curr_pos ) ;
            curr_pos = search_pl_min ;
            search_pos = curr_pos + 1;
        }
        else
        {
            doing = 0;
            b = a.substr( curr_pos ) ;
        }
        num_koeff++;
        istringstream i_str( b );
        double k;
        char ch;
        int x_number = 0;
        double pov_number = 1.0;
        i_str >> k;
        KK( num_koeff ) = k;
        int doing_2 = 1;
        do
        {
            i_str >> ch;
            if ( i_str )
            {
                switch ( ch )
                {
                case '*':
                    if ( x_number != 0 )
                    {
                        MM( x_number, num_koeff ) = pov_number;
                        num_args = max( num_args , x_number );
                    }
                    x_number = 0;
                    pov_number = 1.0;
                    break;
                case 'x':
                    i_str >> x_number;
                    break;
                case '^':
                    i_str >> pov_number;
                    break;
                default :
                    break;
                }
            }
            else
                doing_2 = 0;
        }
        while ( doing_2 );
        if ( x_number != 0 )
        {
            MM( x_number, num_koeff ) = pov_number;
            num_args = max( num_args , x_number );
        }
    }
    while ( doing );
    K.set_size( num_koeff );
    M.set_dims( num_args, num_koeff );
    for ( int i = 1; i <= num_koeff; i++ )
    {
        K( i ) = KK( i );
        for ( int j = 1; j <= num_args; j++ )
        {
            M( j, i ) = MM( j, i );
        }
    }
    return is;
}

void FPolynom::read( string const & a )
{
    int curr_pos = 0;
    int search_pos = 0;
    int search_pl_min;
    string b;
    int doing = 1;  //Условие выхода из цикла по разбору сумм.
    int num_koeff = 0;  //Порядковый номер разбираемого коэффициента. И количество столбцов матрицы.
    int num_args = 0;  // Количество аргументов полинома.
    FMatrix MM( 50, 50 );  //Матрица для временного хранения вида разбираемого полинома.
    FVector KK( 50 );  //Вектор для временного хранения коэффициентов разбираемого полинома.
    do
    {
        search_pl_min = a.find_first_of( "+-", search_pos );
        if ( search_pl_min != string::npos )
        {
            b = a.substr( curr_pos, search_pl_min - curr_pos ) ;
            curr_pos = search_pl_min ;
            search_pos = curr_pos + 1;
        }
        else
        {
            doing = 0;
            b = a.substr( curr_pos ) ;
        }
        num_koeff++;
        istringstream i_str( b );
        double k;
        char ch;
        int x_number = 0;
        double pov_number = 1.0;
        i_str >> k;
        KK( num_koeff ) = k;
        int doing_2 = 1;
        do
        {
            i_str >> ch;
            if ( i_str )
            {
                switch ( ch )
                {
                case '*':
                    if ( x_number != 0 )
                    {
                        MM( x_number, num_koeff ) = pov_number;
                        num_args = max( num_args , x_number );
                    }
                    x_number = 0;
                    pov_number = 1.0;
                    break;
                case 'x':
                    i_str >> x_number;
                    break;
                case '^':
                    i_str >> pov_number;
                    break;
                default :
                    break;
                }
            }
            else
                doing_2 = 0;
        }
        while ( doing_2 );
        if ( x_number != 0 )
        {
            MM( x_number, num_koeff ) = pov_number;
            num_args = max( num_args , x_number );
        }
    }
    while ( doing );
    K.set_size( num_koeff );
    M.set_dims( num_args, num_koeff );
    for ( int i = 1; i <= num_koeff; i++ )
    {
        K( i ) = KK( i );
        for ( int j = 1; j <= num_args; j++ )
        {
            M( j, i ) = MM( j, i );
        }
    }
    return ;
}

ostream& operator<< ( ostream & os, FPolynom const & p )
{
    os << p.K << p.M;
    return os;
}

istream& operator>>( istream & is, FPolynom & p )
{
    is >> p.K >> p.M;
    return is;
}

FPolynom FPolynom::Derive( int arg_no ) const
{
    FPolynom rez = *this;
    if ( arg_no <= rez.get_n_args() && 1 <= arg_no )
    {
        FVector v = rez.get_koeff();
        FMatrix m = rez.get_matrix();
        FVector v_row = m.get_row( arg_no );
        v = v*v_row;
        for ( int i = 1; i <= v_row.get_size(); i++ )
        {
            if( -0.0000001 <=v_row( i )&& v_row( i ) <=0.0000001 )
                ;
            else
                v_row( i ) -= 1.0;
        }
        rez.set( v );
        m.set_row( arg_no, v_row );
        rez.set( m );
    }
    return rez;
}

FPolynom FPolynom::Integral( int arg_no ) const
{
    FPolynom rez = *this;
    if ( arg_no <= rez.get_n_args() && 1 <= arg_no )
    {
        FVector v = rez.get_koeff();
        FMatrix m = rez.get_matrix();
        FVector v_row = m.get_row( arg_no );
        for ( int i = 1; i <= v_row.get_size(); i++ )
        {
            v_row( i ) += 1.0;
        }
        v = v / v_row;
        rez.set( v );
        m.set_row( arg_no, v_row );
        rez.set( m );
    }
    return rez;
}
};

