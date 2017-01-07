/**
@author Николай Матвеев <matveev@mksat.net>
*/

#ifndef EQATION_ANALIZER_H
#define EQATION_ANALIZER_H

#include "mnasoft_lib_global.h"

#include <QStringList>
#include <QString>
#include <QStack>

#include "nm_value.h"
#include "eqation_el.h"

#include <iostream>

///Анализатор лексем.
/**
Обеспечивает функциональность для разбора и вычисления арифметических выражений с числами, имеющими размерность.
*/
class MNASOFT_EXPORT equation_analizer
{
public:
///Конструктор по умолчанию.
/**
Задает пустое выражение. Значением этого выражения является безразмерный 0.
*/
	equation_analizer();
///Конструктор.
/**
Задает строковое представление выражения. Затем пытается определить его значение.
*/
	equation_analizer(const QString& str );
///Деструктор.
	~equation_analizer();
///Производит вычисление выражения.
	bool culculate();
///Возвращает значение объекта.
	nm_value get_Value() const;
///Вывод списка лексем в поток в несколько строк.
	void print_Lexem_lst( std::ostream & os );
///Вывод списка лексем в поток в одну строку.
	void print_Lexem_lst_as_Sting( std::ostream & os );
///Вывод списка опреандов в поток.
	void print_Operands_lst( std::ostream & os );
///Проверка баланса скобок.
/**
Функция возвращает разность между количеством открытых и закрытых скобок.
Если скобки в выражении сбалансированы функция возвращает 0.
*/
	int is_bracketBalanced();
///Возвращает количество открытых скобок.
	int bracketOpened();
///Возвращает количество закрытых скобок.
	int bracketClosed();
///Возвращает максимальную глубину вложенности скобок.
	int bracketRange();
///Возвращает текущее состояние объекта.
	int get_State() const;


	void set_Equation( const QString& theValue );
	QString get_Equation() const;
	
///Возвращает статус ошибки.
	QString get_Error_string() const;
	
protected:
///Состояние в котором находится объект.
/**
st_clear - значение не присвоено;
st_lexem_analis - в процессе вычисления значения;
st_value_good - значение выражения вычислено;
st_value_error - произошла ошибка в процессе вычисления выражения.
*/
	int m_state;
///Значение выражения.
	nm_value m_value;
///Строковое представление выражения.
/**
Например:
"10.5[mm]+20*(55[mm]/20.23)"; "10.5"; "10.5[m*s^-1]".
*/
	QString m_equation;
///Список лексем
/**
Лексемы включают в себя:
1) знаки арифметических операций: "+" "-" "* "/".
2) простые операнды - числа или числа с размерностью.
3) знаки открывающихся и закрывающихся круглых скобок.
 */
	QStringList m_lexem_lst;
///Содержит список операций, операндов и сложных операндов (операндов заключенных в круглые скобки).
/**
Каждому элементу в этом списке соответствует один или несколько элементов в списке лексем m_equation.
*/
	QList<eqation_el> m_operands_lst;
	///Содержит строку состояния ошибки.
	QString m_error_string;
	
protected:	
/**
Возвращает номер первого операнда в списке операндов встретившегося при проходе слева направо
по списку лексем и имеющего наивысший приоритет.
*/
	int find_operation_hight_level();
///Подсчет количества операций в списке m_operands_lst.
	int calc_operation_number();
///Разбиение строкового представления выражения на лексемы.
/**
После выполнения данной функции переменная m_lexem_lst становится заполненной лексемами.
Возвращает количество прочитанных лексем.
*/
	int devide_on_lexem();
///Строит сопряженный со списком лексем список опреандов.
	int build_operands_lst();
///Проверка выражения на корректность.
/**
1) Проверяется баланс открытых и закрытых скобок.
2) Выполняется проверка того, чтобы две или более операции не следовали одна за другой.
3) Выполняется проверка того, чтобы два или более простых операнда не следовали один за другим.
*/
	int validate();
///Конструирует выражение для разбора, одного операнда.
	void set_Operand( const equation_analizer & aEA, int operand );
///Выполняет вычисление опреанда под номером n
/**
0 - первый операнд; 1 - второй; итд.
*/
	nm_value culc_operand(int operand/**порядковый номер операнда*/);
	
private:
	enum CharacterDividers
	{
		ch_open_bracket = '(',
		ch_close_bracket = ')',
		ch_puls = '+',
		ch_minus = '-',
		ch_mult = '*',
		ch_dev = '/',
		ch_space = ' '
	};
	/** StateConditions
	st_clear - значение не присвоено;
	st_lexem_analis - в процессе вычисления значения;
	st_value_good - значение выражения вычислено;
	st_value_error - произошла ошибка в процессе вычисления выражения.
	*/
	enum StateConditions
	{
		st_clear = 0,
		st_lexem_analis,
		st_value_good,
		st_value_error
	};
	///Конструирует выражение для разбора, одного операнда.
	/**Используется внутренне.*/
	equation_analizer( const equation_analizer & aEA, int operand );
};

#endif // EQATION_ANALIZER_H
