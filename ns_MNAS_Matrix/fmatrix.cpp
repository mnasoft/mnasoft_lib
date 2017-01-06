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

#include "fmatrix.h"

namespace ns_MNAS_Matrix
{
	double FMatrix::val = 0;
	FMatrix::FMatrix() : row( 0 ), col( 0 ), first( 0 ) {}
	FMatrix::FMatrix( int R, int C ) : row( R ), col( C ), first( 0 )
	{
		if ( row < 1 )
			row = 1;
		if ( col < 1 )
			col = 1;
		first = new double[ row * col ];
		if ( first )
		{
			int r, c;
			for ( r = 1;r <= row;r++ )
				for ( c = 1;c <= col;c++ )
					operator() ( r,c ) = 0;
		}
	}

	FMatrix::FMatrix( FMatrix const & a ) : row( a.row ), col( a.col ), first( 0 )
	{
		int r, c;
		first = new double [ row * col ];
		if ( first )
		{
			for ( r = 1;r <= row;r++ )
				for ( c = 1;c <= col;c++ )
					operator() ( r,c ) = a( r, c );
		}
	}

	FMatrix::FMatrix( FVector const & a, VectorToMatrixDirection dir ) : row( 0 ), col( 0 ), first( 0 )
	{
		int v_size = a.get_size();
		switch ( dir )
		{
		case as_row :
			set_dims( 1, v_size );
			set_row( 1, a );
			break;
		case as_column :
			set_dims( v_size, 1 );
			set_col( 1, a );
			break;
		}
	}

	FMatrix::~FMatrix()
	{
		if ( first )
			delete [] first;
	}

	FMatrix& FMatrix::operator=( FMatrix const & a )
	{
		if ( row * col != a.row * a.col )
		{
			row = a.row;
			col = a.col;
			delete [] first;
			first = 0;
			first = new double [ row * col ] ;
		}
		row = a.row;
		col = a.col;
		if ( first )
		{
			int r, c;
			for ( r = 1;r <= row;r++ )
				for ( c = 1;c <= col;c++ )
					operator() ( r,c ) = a( r, c );
		}
		return *this;
	}

	FMatrix operator+( FMatrix const & a, FMatrix const & b )
	{
		int r, c;

		if ( a.row > b.row )
			r = a.row;
		else
			r = b.row;
		if ( a.col > b.col )
			c = a.col;
		else
			c = b.col;

		FMatrix d( r, c );
		for ( r = 1;r <= d.row;r++ )
			for ( c = 1;c <= d.col;c++ )
			{
				d.val = 0;
				d( r, c ) = a( r, c ) + b( r, c );
			}
		return d;
	}

	FMatrix operator-( FMatrix const & a, FMatrix const & b )
	{
		int r, c;
		if ( a.row > b.row )
			r = a.row;
		else
			r = b.row;
		if ( a.col > b.col )
			c = a.col;
		else
			c = b.col;
		FMatrix d( r, c );
		for ( r = 1;r <= d.row;r++ )
			for ( c = 1;c <= d.col;c++ )
			{
				d.val = 0;
				d( r, c ) = a( r, c ) - b( r, c );
			}
		return d;
	}

	FMatrix operator-( FMatrix const & a )
	{
		int r, c;
		r = a.row;
		c = a.col;
		FMatrix d( r, c );
		for ( r = 1;r <= d.row;r++ )
			for ( c = 1;c <= d.col;c++ )
			{
				d.val = 0;
				d( r, c ) = -a( r, c );
			}
		return d;
	}

	FMatrix operator*( FMatrix const & a, FMatrix const & b )
	{
		int r = a.row, c = b.col;
		FMatrix d( r, c );
		int i, j, k;
		for ( i = 1;i <= r;i++ )
			for ( j = 1;j <= c;j++ )
			{
				double &s = d( i, j );
				for ( k = 1;k <= a.col;k++ )
				{
					FMatrix::val = 0;
					s += a( i, k ) * b( k, j );
				}
			}
		return d;
	}

	FVector FMatrix::get_row( int r ) const
	{
		FVector d( cols() );
		for ( int i = 1;i <= col;i++ )
		{
			FVector::val = 0;
			FMatrix::val = 0;
			d( i ) = operator() ( r,i );
		}
		return d;
	}

	FVector FMatrix::get_col( int c ) const
	{
		FVector d( rows() );
		for ( int i = 1;i <= row;i++ )
		{
			FVector::val = 0;
			FMatrix::val = 0;
			d( i ) = operator() ( i,c );
		}
		return d;
	}

	FMatrix& FMatrix::set_row( int r, FVector const & v )
	{
		for ( int i = 1;i <= col;i++ )
		{
			FVector::val = 0;
			FMatrix::val = 0;
			operator() ( r,i ) = v( i );
		}
		return *this;
	}

	FMatrix& FMatrix::set_col( int c, FVector const &v )
	{
		for ( int i = 1;i <= row;i++ )
		{
			FVector::val = 0;
			FMatrix::val = 0;
			operator() ( i,c ) = v( i );
		}
		FVector::val = 0;
		FMatrix::val = 0;
		return *this;
	}

	FVector FMatrix::get_d() const
	{
		int n;
		if ( row < col )
			n = row;
		else
			n = col;
		FVector d( n );
		for ( int i = 1;i <= n;i++ )
		{
			FVector::val = 0;
			FMatrix::val = 0;
			d( i ) = operator() ( i,i );
		}
		return d;
	}

	FMatrix& FMatrix::set_d( FVector const &v )
	{
		int n = v.get_size();
		for ( int i = 1;i <= n;i++ )
		{
			FVector::val = 0;
			FMatrix::val = 0;
			operator() ( i,i ) = v( i );
		}
		return *this;
	}

	FMatrix operator*( double a, FMatrix const & b )
	{
		int r, c;
		FMatrix d = b;
		for ( r = 1;r <= b.row;r++ )
			for ( c = 1;c <= b.col;c++ )
			{
				FMatrix::val = 0;
				d( r, c ) *= a;
			}
		return d;
	}

	FMatrix operator*( FMatrix const & b, double a )
	{
		int r, c;
		FMatrix d = b;
		for ( r = 1;r <= d.row;r++ )
			for ( c = 1;c <= d.col;c++ )
			{
				FMatrix::val = 0;
				d( r, c ) *= a;
			}
		return d;
	}

	FMatrix operator/( FMatrix const & b, double a )
	{
		int r, c;
		FMatrix d = b;
		if ( a == 0 )
			a = 1.;
		for ( r = 1;r <= d.row;r++ )
			for ( c = 1;c <= d.col;c++ )
			{
				FMatrix::val = 0;
				d( r, c ) /= a;
			}
		return d;
	}

	FMatrix& FMatrix::set_E()
	{
		int r, c;
		for ( r = 1;r <= row;r++ )
			for ( c = 1;c <= col;c++ )
				operator() ( r,c ) = 0.0;

		int n = 0;
		if ( row < col )
			n = row;
		else
			n = col;

		for ( c = 1;c <= n;c++ )
			operator() ( c,c ) = 1.;
		return *this;
	}

	FMatrix& FMatrix::set_dims( int r, int c )
	{
		delete [] first;
		row = r;
		col = c;
		if ( row < 1 )
			row = 1;
		if ( col < 1 )
			col = 1;
		row = r;
		col = c;
		first = new double[ row * col ];
		for ( int i = 1;i <= row;i++ )
			for ( int j = 1;j <= col;j++ )
			{
				operator() ( i,j ) = 0.0;
			}
		return *this;
	}


	FMatrix FMatrix::Triang() const
	{
		FMatrix d = *this;
		FVector v1( col ), v2( col );
		double coeff = 1.;
		int c;
		for ( c = 1;c <= col;c++ )
		{
			int r, row_0 = row;
			for ( r = c;r <= row_0;r++ )
			{
				double l = d( r, c );
				if ( l * l > 1.0e-25 )
				{
					coeff *= l;
					v1 = d.get_row( r );
					v1 = v1 / l;
					d.set_row( r, v1 );
				}
				else if ( r < row_0 )
				{
					v1 = d.get_row( r );
					v2 = d.get_row( row_0 );
					d.set_row( r, v2 );
					d.set_row( row_0, v1 );
					coeff *= -1;
					r--;
					row_0--;
				}
				else
					row_0--;
			}
			for ( r = c + 1;r <= row_0;r++ )
			{
				v2 = d.get_row( r ) - d.get_row( c );
				d.set_row( r, v2 );
			}
		}
		v1 = d.get_row( row ) * coeff;
		d.set_row( row, v1 );
		return d;
	}



	FMatrix FMatrix::Transp() const
	{
		FMatrix d( col, row );
		FVector s( col );
		for ( int i = 1;i <= row;i++ )
		{
			s = get_row( i );
			d.set_col( i, s );
		}
		return d;
	}

	FMatrix FMatrix::Linkin() const
	{
		int r, c;
		FMatrix d( col, row );
		FMatrix s( row, col );
		for ( r = 1;r <= row;r++ )
			for ( c = 1;c <= col;c++ )
			{
				s = Vycher( r, c );
				double dd = s.Det();
				if ( ( r + c ) % 2 )
					d( c, r ) = -dd;
				else
					d( c, r ) = dd;
			}
		return d;
	}

	FMatrix FMatrix::Vycher( int i, int j ) const
	{
		if ( row <= 1 )
			return FMatrix( 1, 1 );
		if ( col <= 1 )
			return FMatrix( 1, 1 );
		int rrr = row, ccc = col;
		if ( 1 <= i && i <= row )
			rrr--;
		if ( 1 <= j && j <= col )
			ccc--;
		FMatrix d( rrr, ccc );
		int r, c, r2, c2;
		for ( r = 1, r2 = 1;r <= row;r++, r2++ )
		{
			if ( i == r )
				--r2;
			for ( c = 1, c2 = 1;c <= col;c++, c2++ )
			{
				if ( j == c )
					--c2;
				if ( r != i && c != j )
					d( r2, c2 ) = operator() ( r,c );
			}
		}
		return d;
	}

	FMatrix FMatrix::Obratn() const
	{
		int r, c;
		FMatrix d( col, row );
		FMatrix s( row, col );
		for ( r = 1;r <= row;r++ )
			for ( c = 1;c <= col;c++ )
			{
				s = Vycher( r, c );
				double dd = s.Det();
				if ( ( r + c ) % 2 )
					d( c, r ) = -dd;
				else
					d( c, r ) = dd;
			}
		return d / this->Det();
	}

	double FMatrix::Det() const
	{
		FMatrix d = Triang();
		FVector v = d.get_d();
		double rez = 1.;
		for ( int i = 1;i <= v.get_size();i++ )
		{
			rez *= v( i );
		}
		return rez;
	}

	ostream& operator<<( ostream& o, FMatrix const &a )
	{
		int r, c;
		o << a.row << " " << a.col << "\n";
		for ( r = 1;r <= a.row;r++ )
		{
			for ( c = 1;c <= a.col;c++ )
				o << a( r, c ) << " ";
			o << "\n";
		}
		return o;
	}

	istream& operator>>( istream& i, FMatrix &a )
	{
		delete [] a.first;
		i >> a.row >> a.col;
		a.first = new double [ a.row * a.col ];
		if ( a.first )
		{
			int r, c;
			for ( r = 1;r <= a.row;r++ )
				for ( c = 1;c <= a.col;c++ )
					i >> a( r, c );
		}
		return i;
	}

	double& FMatrix::operator() ( int r,int c )
	{
		int ro = r - 1, co = c - 1;
		if ( r < 1 || r > row )
			return val;
		if ( c < 1 || c > col )
			return val;
		return first[ ro * col + co ];
	}

	double& FMatrix::operator() ( int r,int c ) const
	{
		int ro = r - 1, co = c - 1;
		if ( r < 1 || r > row )
			return val;
		if ( c < 1 || c > col )
			return val;
		return first[ ro * col + co ];
	}

};
