/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     */

#ifndef FMERROR_H
#define FMERROR_H

#include "mnasoft_lib_global.h"

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

class MNASOFT_EXPORT FMalloc : public FMerror
{
  public:
    FMalloc(int e_mode=DONT_EXIT) : FMerror(e_mode) {}
    const char* getmsg(int err);
};

#endif //FMERROR_H
