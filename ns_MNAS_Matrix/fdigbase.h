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

#ifndef FDIG_H
#define FDIG_H

#include <iostream>
using namespace std;


namespace ns_MNAS_Matrix
{
  /**class FDig предоставляет набор функций для представления целочиленного значения val в произвольной системе счисления c основанием base.
  */
  class MNASOFT_EXPORT FDig
  {
  protected:
    /**Основание системы счисления.*/
    int base;
  public:
    /**Целочисленное значение, представляемое в системе счисления с основанием base.*/
    int val;
    /**Конструктор по умолчанию устанавливает  основание base=10, значение val=0.*/
    FDig( );
    /**Конструктор по устанавливает  основание base=Base, значение val=Val.
    Если Base<1, то base=10.*/
    FDig( int Val, int Base );
    /**Деструктор.*/
    ~FDig();
    /**Возвращает цифру, находящуюся в разряде Razrjad при представлении числа val в системе счисления с основанием base. Самая правая цифра (наименьший разряд) в представлении числа имеет разряд =0.*/
    int Digit( int Razrjad ) const;
    /**Возвращает сумму цифр в представлении числа val в системе счисления с основанием base.*/
    int DigitsSumm( void ) const;
    /**Возвращает количество ненулевых цифр в представлении числа val в системе счисления с основанием base.*/
    int NonZeroDigitsSumm( void ) const;
    /**Устанавливает:
    - новое значение для основания системы счисления base, если аргумент Base >1;
    - в противном случае base<=1 основание системы счисления не изменяется.
    Возвращает установленное основание сисемы счисления.*/
    int SetBase( int Base );
    /**Возврвщает основание системы счисления base.*/
    int GetBase( int Base ) const
    {
      return base;
    }
    /**Возврвщает количество цифр при представлении числа val в системе счисления с основанием base без учета знака. Если val=0, возвращается 0.*/
    int Razrjad( void ) const;
    /**Запись в поток.*/
    friend ostream& operator<<( ostream& o, FDig const & dig );
    /**Чтение из потока.*/
    friend istream& operator>>( istream& i, FDig & dig );
  };
};

#endif //FDIG_H
