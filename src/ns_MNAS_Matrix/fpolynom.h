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
#ifndef FPOLYNOM_H
#define FPOLYNOM_H

#include "mnasoft_lib_global.h"

#include "fmatrix.h"
#include "fvector.h"

using namespace std;

namespace ns_MNAS_Matrix
{
	/**
	FPoilynom - произвольный полином.
	Функция get_n_args() возвращает  количество аргументов от которых зависит полином.
	Функция get_n_koeff() возвращает количество коэффициентов полинома.
	Коэффициенты полинома сохраняются в  векторе FVector K.
	Функция FVector get_koeff( void ) const возвращает вектор коэффициентов полинома.
	Вид полиномиальной зависимости определяет  матрица вида полинома FMatrix M.
	Функция FMatrix get_matrix( void ) const возвращает матрицу FMatrix M.
	Функция double poly( FVector const &x ) const возвращает  значение полинома (сумма произведений  коэффициентов и произвольного сочетания аргументов возведенных в произвольную степень.)
	Значение_полинома(x)=Сумма[i=1..get_n_koeff]( K[i] * Произведение[j=1..get_n_args()] (x[i]**M[i,j]    )  ).
	@author matveev
	*/
	class MNASOFT_EXPORT FPolynom
	{
		protected:
			/**Вектор коэффициентов.
			Количество коэффициентов в векторе K
			должно совпадать с количеством столбцов в матрице M.*/
			FVector K;
			/**Матрица вида полинома - определяющая  вид полиномиальной зависимости.
			Количетво столбцов матрицы определяет количество сумм в полиномиальной зависимости.
			Количество строк определяет количество аргументов от которых зависит полином.
			*/
			FMatrix M;
		public:
			/**Конструктор по умолчанию.*/
			FPolynom();
			/**Создает полином, зависящий от  n_param параметров, который имеет  n_koeff коэффициентов.
			Вектор коэффициентов содержит нули. Матрица вида полинома содержит нули.
			*/
			FPolynom( int n_param, int n_koeff );

			/**Создает полином,  зависящий от  n_param параметров,
			степень которого равна stepen,
			при каждом коэффициенте которого, стоит не более args_in_one_koeff коэффициентов
			(args_in_one_koeff <=stepen&&args_in_one_koeff <=n_param).*/
			FPolynom( int n_param, int stepen, int args_in_one_koeff );

			/**Создает полином с вектором коэффициентов v и матрицей вида полинома m.
			Количество элементов в векторе v должно совпадать с числом столбцов в матрице m.*/
			FPolynom( FVector const & v, FMatrix const & m );

			/**Конструктор копирования.*/
			FPolynom( FPolynom const & poly );

			/**Конструктор копирования.*/
			FPolynom( string const & str );

			/**Деструктор.*/
			~FPolynom();

			/**Задает вектор коэффициентов.
			    Количество элементов в векторе коэффициентов K должно быть равно количеству столбцов в матрице вида полинома M.*/
			void set
				( FVector const & v );
			/**Задает матрицу вида полинома M.*/
			void set
				( FMatrix const & m );
			/**Производит копирование в полином вектор коеффициентов и матрицу формы полинома из полинома p.*/
			void set
				( FPolynom const & p );
			/**Возвращает вектор коэффициентов.*/
			FVector get_koeff( void ) const;
			/**Возвращает матрицу, определяющую вид полинома.*/
			FMatrix get_matrix( void ) const;
			/**
			  Вычисляет значение полинома.
			  Вектор X служит для задания аргументов от которых зависит полином.
			  Коэффициенты полинома содержатся в векторе K.
			  Вид полинома определяется матрицей M.
			  Количество строк матрицы M должно быть равно размеру вектора x.
			  Количество столбцов матрицы M должно быть равно размеру вектора K.*/
			double poly( FVector const &x ) const;
			/**Оператор присваивания.*/
			FPolynom & operator=( FPolynom const & poly );

			/**Возвращает количество коэффициентов полинома.*/
			int get_n_koeff( void ) const;

			/**Возвращает количество аргументов, от которых зависит полином.*/
			int get_n_args( void ) const;

			/**Выводит полином в поток в символьном представлении.
			     Это символьное представление в последующем может быть считано функцией read().*/
			ostream& write( ostream& ) const;

			/**Строит по символьному представлению полинома его вектор коэффициентов K и матрицу M.*/
			istream& read( istream& );

			/**Строит по символьному представлению полинома его вектор коэффициентов K и матрицу M.*/
			void read( string const & a );

			/**Возвращает полином представляющий первую производную от полинома this .*/
			FPolynom Derive(int arg_no) const;

			/**Возвращает полином представляющий первообразную от полинома this.*/
			FPolynom Integral(int arg_no) const;

			/**Вывод полинома в поток.*/
			friend ostream& operator<< ( ostream & o, FPolynom const & p );

			/**Чтение полинома из потока.*/
			friend istream& operator>> ( istream & is, FPolynom & p );
	};
}

#endif //FPOLYNOM_H
