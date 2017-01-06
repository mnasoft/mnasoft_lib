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

#ifndef FVECTOR_H
#define FVECTOR_H

#include "mnasoft_lib_global.h"

#include <iostream>

using namespace std;

namespace ns_MNAS_Matrix
{
	///class FVector представляет из себя массив чисел double произвольной длиины.
	///При помощи функции operator()(int) можно получить доступ к произвольному элементу вектора.
	class MNASOFT_EXPORT FVector
	{
		protected:
			///Содержит количество элементов массива.
			int size;
			///Содержит указатель на первый элемент массива.
			double *first;
			///Прооизводит обнуление элементов вектора. Количество элементов приэтом не изменяется.
			void clean ( void );
		public:
			///Заглушка.
			///Служит для возврата ссылки на элемент вектора, когда значение индекса выходит за границы диапазона.
			static double val;
			/**Конструктор по умолчанию.*/
			FVector();
			///Создает вектор, состоящий из P элементов.
			FVector( int P );
			///Создает вектор, состоящий из P элементов.
			FVector( double d );
			///Конструктор копирования.
			FVector( FVector const & Vect );
			///Создает вектор длиной length, содержащий значения из массива array.
			FVector( double* array, int length = 1 );
			///Деструктор. Удаляет вектор.
			~FVector();
			///Возвращает количество элементоов вектора.
			int get_size( void ) const
			{
				return size;
			}
			///Устанавливает новую метрику вектора (новое количество элементов).
			///После чего элементы вектора обнуляются.
			void set_size( int s );
			///Нормализует вектор (масштабирует его таким образом, что его длина становится равной 1.0).
			FVector& normalize( void );
			///Возвращает сумму элементов вектора.
			double summ_of_elements( void ) const;

			/// Устанавливает значения элементов вектора какими что их сумма становится равной 1.0.
			FVector& patr_of_elements( void );

			///Позволяет получить доступ к элементу вектора.
			double& operator() ( int p );
			///Позволяет получить const-доступ к элементу вектора.
			double& operator() ( int p ) const;
			///Оператор копирования.
			///Возвращает вектор, элементы которого равны элементам вектора a.
			///Возвращаемый вектор имеет длину равную длине вектора a.
			FVector& operator=( FVector const & a );
			///Оператор копрования.
			///Возвращает вектор, состоящий из одного элемента значение которого равно элементу a.
			FVector& operator=( double a );
			/// Возвращает максимальное значение, содержащееся в векторе.
			double max( void ) const;
			///Возвращает минимальное значение, содержащееся в векторе.
			double min( void ) const;
			///Возвращает длину вектора (корень квадратный из суммы квадратов элементов).
			double norma() const;
			///Бинарный плюс.
			///Возвращается вектор каждый элемент которого равен сумме соответствуэщиих элементов  векторов Vect_1 и Vect_2.
			friend FVector operator+( FVector const & Vect_1, FVector const & Vect_2 );
			///Бинарный минус.
			///Возвращается вектор каждый элемент которого равен разности соответствуэщиих элементов  векторов Vect_1 и Vect_2.
			friend FVector operator-( FVector const & Vect_1, FVector const & Vect_2 );
			///Унарный минус.
			///При этом направление вкетора меняется на противоположное.
			friend FVector operator-( FVector const & Vect );
			///Унарный плюс.
			///Элементы вектора при этом не изменяются.
			friend FVector operator+( FVector const & Vect );
			///Возвращает вектор элементы которого равны произведению соответствующих элементов векторов Vect_1 и Vect_2.
			friend FVector operator*( FVector const & Vect_1, FVector const & Vect_2 );
			///Возвращает вектор элементы которого равны частному соответствующих элементов векторов Vect_1 и Vect_2.
			friend FVector operator/( FVector const & Vect_1, FVector const & Vect_2 );
			///Умножение вектора на число. Возвращает вектор каждый из элементов которого умножается на это число.
			friend FVector operator*( double Value, FVector const & Vect );
			///Умножение вектора на число.
			///Возвращает вектор каждый из элементов которого умножается на это число.
			friend FVector operator*( FVector const & Vect, double Value );
			///Деление вектора на число.
			///Возвращает вектор каждый из элементов которого делится на это число.
			///Если делитель Value=0.0 возвращается вектор, элементы которого равны элементам вектора-делимого.
			friend FVector operator/( FVector const & Vect, double Value );
			///Векторное перемножение векторов.
			///Имеет смысл при размере векторов равноом 3.
			friend FVector v_umn( FVector const & Vect_1, FVector const & Vect_2 );
			///Запись вектора в поток.
			///При этом сначала выводится количество элеменотов вектора, а затем его элементы.
			friend ostream& operator<<( ostream& o, FVector const & v );
			///Чтение вектора из потока.
			///При этом сначала считывается количество элеменотов вектора, а затем его элементы.
			friend istream& operator>>( istream& i, FVector & v );
	};
};

#endif //FVECTOR_H
