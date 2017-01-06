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

#ifndef TABLE_H
#define TABLE_H

#include "mnasoft_lib_global.h"

#include <iostream>

#include "fmatrix.h"
#include "fpolynom.h"

using namespace std;

using namespace ns_MNAS_Matrix;

namespace ns_MNAS_Matrix
{
    /**
    Представляет функциональную зависимость, задаваемую в табличной форме, для функции нескольких  переменных.
    Данный класс используется для хранения количества реперных точек.
    @author Матвеев Николай Анатольевич
    */
    class MNASOFT_EXPORT table
    {
        protected:
            /**Матрица аргументов.
            Каждая строка - сочетание аргументов.
            Количество строк опредеяет количество точек функциональной зависимости.
            Количество строк в матрице x должно быть равно количеству элементов вектора y.*/
            FMatrix x;
            /**Вектор результатов. Содержит табличные значения вектора результатов.
              Длина вектора y должна быть равна количеству строк матрицы  x.*/
            FVector y;
        public:
            /**Конструктор. Создает пустую таблицу.*/
            table();
            /**Конструктор. Строит зависимость по матрице X, содержащей таблицу сочетаний аргументов, и вектору Y, содержащему значения функции при данных сочетаниях аргументов.*/
            table( FMatrix X, FVector Y );
            /**Деструктор.*/
            ~table();
            /**Запись таблицы в поток.
            Вначале должны быть выведены два целых часла представляющих количество точек и количество аргументов таблицы.
            Затем построчно выводятся аргументы в i-товой точке и соответствующее им значение функции.*/
            friend ostream& operator<< ( ostream& ostr, table const &tbl );
            /**Считывание таблицы из потока .
            Вначале должны быть считаны два целых часла представляющих количество точек и количество аргументов таблицы.
            Затем построчно считываются аргументы в i-товой точке и соответствующее им значение функции.*/
            friend istream& operator>> ( istream& istr, table &tbl );
            /**Возвращает количество точек в таблице.*/
            int get_n_points() const;
            /**Возвращает количество аргументов от которых зависит функция.*/
            int get_n_args() const;
            /**Возвращает вектор аргументов, задаваемый в таблице в i-товой точке.*/
            FVector get_args( int i ) const;
            /**Возвращает значение функции, задаваемое в таблице в i-товой точке.*/
            double get_rez( int i ) const;
            /**Производит расчет коэффициентов интерполяционного полинома p.
            Возвращает true, если все в порядке(коэффициенты рассчитаны правильно) и false - в противном случае.*/
            bool culc_Polynom_Koeff( FPolynom &p );
    };
}

#endif //TABLE_H
