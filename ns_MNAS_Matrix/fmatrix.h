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
#ifndef FMATRIX_H
#define FMATRIX_H

#include "mnasoft_lib_global.h"

#include <iostream>
#include "fvector.h"

using namespace std;

namespace ns_MNAS_Matrix
{
    /**class FMatrix представляет собой математическое понятие матрицы.*/
    class MNASOFT_EXPORT FMatrix
    {
        protected:
            /**row - Количество строк в матрице.*/
            int row;
            /**col - Количество столбцов в матрице в матрице.*/
            int col;
            /**first - Указатель на первый элемент массива памяти, распределенной под элементы матрицы.*/
            double *first;
        public:
            /**Используется в конструкторе FMatrix(FVector const & a,  VectorToMatrixDirection)
            для интерпретации направления преобразования вектора в матрицу.*/
            enum VectorToMatrixDirection
            {
                as_column = 0,
                as_row = 1
        };
            /**Заглушка. Ссылку на нее может возвращать функция доступа к элементу массива если индекс
              находится за пределами диапазона допустимых значений.*/
            static double val;
            /**Конструктор по умолчанию. Создает вырожденную матрицу.*/
            FMatrix();
            /**Создает матрицу с количеством строк R и количеством столбцов C.
              Элементы матрицы обнуляются.*/
            FMatrix( int R, int C );
            /**Конструктор копирования.*/
            FMatrix( FMatrix const & a );
            /**Конструктор копирования.*/
            FMatrix( FVector const & a, VectorToMatrixDirection dir );
            /**Деструктор.*/
            ~FMatrix();
            /**Производит копирование матрицы.    */
            FMatrix& operator=( FMatrix const & Matr );
            /**Возвращает i-товую строку матрицы. i - должно принимать значение от 1 до rows().*/
            FVector get_row( int i ) const;
            /**Возвращает j-товый столбец матрицы. j - должно принимать значение от 1 до cols(). */
            FVector get_col( int j ) const;
            /**  Возврвщает элементы, расположенные на главной дагонали матрицы.*/
            FVector get_d() const;
            /**  Возвращает количество строк в матрице. */
            int rows() const
            {
                return row;
            }
            /**  Возвращает количество столбцов в матрице. */
            int cols() const
            {
                return col;
            }
            /**  Заполняет i-товую строку матрицы элементами, содержащимися в векторе v_row.*/
            FMatrix& set_row( int i, FVector const & v_row );
            /**  Заполняет j-товый столбец матрицы элементами, содержащимися в векторе v_col.*/
            FMatrix& set_col( int j, FVector const & v_col );
            /**Заполняет главную диагональ матрицы элементами, содержащимися в векторе v.*/
            FMatrix& set_d( FVector const & v );
            /**Задает элементам матрицы такие  значения, чтобы матрица стала единичной.*/
            FMatrix& set_E();
            /**Устанавливает новую метрику матрицы (размеры):
            Количество строк матрицы становится равным i;
            Количество матрицы столбцов становится равным j.
              Элементы матрицы при этом обнуляются.*/
            FMatrix& set_dims( int i, int j );

            /**Опреатор доступа к (i,j) элементу  матрицы.
              i может принимать значения в диапазоне 1...rows();
              j может принимать значения в диапазоне 1...cols().*/
            double& operator() ( int r,int c );

            /**Опреатор const - доступа к (i,j) элементу  матрицы.
              i может принимать значения в диапазоне 1...rows();
              j может принимать значения в диапазоне 1...cols().*/
            double& operator() ( int r,int c ) const;
            /**Вычисляет определитель матрицы.*/
            double Det() const;
            /**Возвращает матрицу построчно сведенную к треугольной.*/
            FMatrix Triang() const;
            /**Возвращает транспонированную матрицу.*/
            FMatrix Transp() const;
            /**Возвращает присодиненную матрицу.*/
            FMatrix Linkin() const;
            /**Возвращает матрицу, образуемую путем вычеркивания строки Row и колонки Col.*/
            FMatrix Vycher( int Row, int Col ) const;
            /**Возвращает матрицу, образуемую путем вычеркивания строки Row.*/
            FMatrix Obratn() const;
            /** Возвращает матрицу, образуемую путем вычеркивания строки R.*/
            FMatrix DelRow( int R );
            /** Возвращает матрицу, образуемую путем вычеркивания столбца C.*/
            FMatrix DelColumn( int C );
            /**Возвращает сумму двух матриц.*/
            friend FMatrix operator+ ( FMatrix const & Matr_1, FMatrix const & Matr_2 );
            /**Возвращает разность двух матриц.*/
            friend FMatrix operator- ( FMatrix const & Matr_1, FMatrix const & Matr_2 );
            /**Унарный минус.*/
            friend FMatrix operator- ( FMatrix const & Matr_1 );
            /**Произведение матриц*/
            friend FMatrix operator* ( FMatrix const & Matr_1, FMatrix const & Matr_2 );
            /**Умножение матрицы на число*/
            friend FMatrix operator* ( double Value, FMatrix const & Matr );
            /**Умножение матрицы на число*/
            friend FMatrix operator* ( FMatrix const & Matr, double Value );
            /**Деление матрицы на число*/
            friend FMatrix operator/ ( FMatrix const & Matr, double Value );
            /**Вывод матрицы в поток*/
            friend ostream& operator<< ( ostream& o, FMatrix const &a );
            /**Считывание матрицы из потока*/
            friend istream& operator>> ( istream& i, FMatrix &a );
    };
};


#endif //FMATRIX_H
