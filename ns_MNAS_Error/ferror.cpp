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
#include "fmerror.h"

const char* FMalloc::getmsg( int err )
{
    switch ( err )
    {
    case 0 : return "No error.";
    case 1 : return "Memory allocate error.";
    default : return "0";
    }
}

void FMerror::setexitmode( int m )
{
    if ( ( m >= 0 ) && ( m <= 1 ) )
        exit_mode = m;
#ifdef __MYDEBUG__
    cout << "exit_mode is " << exit_mode << endl;
#endif
}

void FMerror::setstate( int err )
{
    err_state = err;
#ifdef __MYDEBUG__
    cout << "err_state is " << err_state << endl;
#endif
    if ( !err_state )
        if ( exit_mode == EXIT )
            throw err_state; //  exit(err_state);

}

int FMerror::getstate( void )
{
#ifdef __MYDEBUG__
    cout << "err_state is " << err_state << endl;
#endif
    if ( !err_state )
        if ( exit_mode == EXIT )
            throw err_state; // exit(err_state);
    return err_state;
}
