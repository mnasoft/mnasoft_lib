/**
@author namatv <matveev@wildpark.net>
*/
#ifndef EQATION_EL_H
#define EQATION_EL_H

#include "mnasoft_lib_global.h"

#include <QString>
#include <iostream>
#include "nm_value.h"

///Одиночная лексема.
/**Используется внутренне анализатором лексем для построения и анализа выражения.
*/
class MNASOFT_EXPORT eqation_el
{
public:
	///Конструктор по умолчанию.
	eqation_el();
	///Конструктор
	eqation_el(int aType/**Тип лексемы*/, int aLevel /**Уровень лексемы*/, QString aEl_str/**Строка, представляюшая лексему*/);
	///Деструктор
	~eqation_el();
	///Коды типов лексемы.
	/**
	Тип лексемы может принимать значения:
	численное значение - type_value;
	операнд - type_operand;
	арифметическое действие - type_operation;
	составной операнд - type_operand_in_brackets;
	 */
	enum Lexem_Type
	{
		///Значение
		type_value=0,
		///Операнд
		type_operand=1,
		///Опреация
		type_operation=2,
		///Сложный операнд
		type_operand_in_brackets=3
	};
	///Порядок старшинства операций
	/**
	op_plus_minus=1  - операции сложения и вычитания;
	op_mult_devide=2 - операции умножения и деления;
	op_power=3       - операция возвеления в степень.
	*/
	enum Operation_Level
	{
		///операции сложения и вычитания;
		op_plus_minus=1, 
		///операции умножения и деления;
		op_mult_devide=2,
		/// операция возведения в степень. 
		op_power=3
	};
	///Код операции
	enum Operation_Code
	{
		///Неизвестная операция;
		code_unnoun=0,
		///
		code_plus=1,
		code_minus,
		code_mult,
		code_devide
	};

	///Тип лексемы.
	/**
	Тип лексемы может принимать значения:
	численное значение - type_value;
	операнд - type_operand;
	арифметическое действие - type_operation;
	составной операнд - type_operand_in_brackets;
	 */
	int lexem_type;
	
	///Старшинство лексемы. Операции.
	/**Арифметические знаки
	+ и - имеют уровень  1;
	* и / имеют уровень 2;
	^ имеет уровень старшинства 3.
	*/
	int lexem_level;
	///Начало лексемы.
	int lexem_start;
	///Конец лексемы.
	int lexem_end;
	///Строка лексемы.
	QString el_str;
	///Чсленное значение.
	nm_value nm_val;
	///Вывод полей лексемыв поток.
	friend std::ostream & operator <<( std::ostream & os , eqation_el const & el);
};

#endif

