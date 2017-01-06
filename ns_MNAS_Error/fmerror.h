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
#ifndef FMERROR_H
#define FMERROR_H

enum  EXIT_MODE { DONT_EXIT=0, EXIT=1};
const int NUM_EXIT_MODE=1;

class MNASOFT_EXPORT FMerror
{
  private:
    int exit_mode;
    int err_state;
  public:
    FMerror(int e_mode=DONT_EXIT) : exit_mode(e_mode) {}
    void setexitmode(int m=DONT_EXIT);
    void setstate(int err);
    int  getstate(void);
    const char* getmsg(int err) { return "0"; }
};

class MNASOFT FMalloc : public FMerror
{
  public:
    FMalloc(int e_mode=DONT_EXIT) : FMerror(e_mode) {}
    const char* getmsg(int err);
};

#endif //FMERROR_H
