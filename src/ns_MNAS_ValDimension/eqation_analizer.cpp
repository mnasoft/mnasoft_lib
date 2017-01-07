#include "eqation_analizer.h"
#include "eqation_el.h"
#include <iostream>
#include <string>

//#define NM_DEBUG
//#define NM_FULL_DEBUG

int tab_size = 0;
std::string tab_string;
std::ostream & tab_size_end ( std::ostream & );

using namespace std;

equation_analizer::equation_analizer()
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "equation_analizer::equation_analizer()"
		<< "\t" << "start..." << endl;
	}
#endif

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "equation_analizer::equation_analizer()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
}

equation_analizer::equation_analizer ( const QString & str )
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "equation_analizer::equation_analizer( const QString& str )"
		<< "\t" << "start..." << endl;
	}
#endif

	set_Equation ( str );

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "equation_analizer::equation_analizer( const QString& str )"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
}

equation_analizer::equation_analizer ( const equation_analizer & aEA, int operand )
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "equation_analizer::equation_analizer( const equation_analizer & aEA, int opeand )"
		<< "\t" << "start..." << endl;
	}
#endif

	set_Operand ( aEA, operand );

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "equation_analizer::equation_analizer( const equation_analizer & aEA, int operand )"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
}


equation_analizer::~equation_analizer()
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "equation_analizer::~equation_analizer()"
		<< "\t" << "start..." << endl;
	}
#endif

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "equation_analizer::~equation_analizer()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
}


int equation_analizer::bracketOpened()
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::bracketOpened()"
		<< "\t" << "start..." << endl;
	}
#endif
	int len = m_equation.length();
	int bracket = 0;
	QChar ch;
	for ( int i = 0;i < len;++i )
	{
		ch = m_equation[ i ];
		if ( ch == '(' ) ++bracket;
	}

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::bracketOpened()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif

	return bracket;
}

int equation_analizer::bracketClosed()
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::bracketClosed()"
		<< "\t" << "start..." << endl;
	}
#endif

	int len = m_equation.length();
	int bracket = 0;
	QChar ch;
	for ( int i = 0;i < len;++i )
	{
		ch = m_equation[ i ];
		if ( ch == ')' ) ++bracket;
	}

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::bracketClosed()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif

	return bracket;
}

int equation_analizer::bracketRange()
{

#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::bracketRange()"
		<< "\t" << "start..." << endl;
	}
#endif

	int len = m_equation.length();
	int bracket = 0;
	int range = 0;
	QChar ch;
	for ( int i = 0;i < len;++i )
	{
		ch = m_equation[ i ];
		if ( ch == '(' ) ++bracket;
		if ( ch == ')' ) --bracket;
		if ( range < bracket ) range = bracket;
	}

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::bracketRange()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif

	return range;
}

int equation_analizer::find_operation_hight_level()
{

#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::find_operation_hight_level()"
		<< "\t" << "start..." << endl;
	}
#endif

	QString str;
	eqation_el el;
	int op_number = -1; //порядковый номер опреации с наибольшим приоритетом.
	int op_level = -1; //уровень старшинства операции.(+-)=1;(*/)=2;(^)=3.
//	int op_code = 0; 
	for ( int i = 0; i < m_operands_lst.size(); ++i )
	{
		el = m_operands_lst.at ( i );
		//		el.lexem_level;
		if ( el.lexem_type == eqation_el::type_operation )
		{
			str = m_lexem_lst.at ( el.lexem_start );
			if ( str == "+" && op_level < eqation_el::op_plus_minus )
			{
				op_level = eqation_el::op_plus_minus;
				op_number = i;
			}
			else if ( str == "-" && op_level < eqation_el::op_plus_minus )
			{
				op_level = eqation_el::op_plus_minus;
				op_number = i;
			}
			else if ( str == "*" && op_level < eqation_el::op_mult_devide )
			{
				op_level = eqation_el::op_mult_devide;
				op_number = i;
			}
			else if ( str == "/" && op_level < eqation_el::op_mult_devide )
			{
				op_level = eqation_el::op_mult_devide;
				op_number = i;
			}
		}
	}

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::find_operation_hight_level()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif

	return op_number;
}

bool equation_analizer::culculate()
{

#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "bool equation_analizer::culculate()"
		<< "\t" << "start..." << endl;
	}
#endif

	bool ret_code = true;
	///Перед выполнением данной функции должен быть сформирован список лексем m_lexem_lst и список операндов_операций_значений m_operands_lst.

	int n_operation_hight_level;
	///Тип опреации унарная - 0; бинарная - 1;
//	int n_operation_type;

	nm_value nm_left;
	nm_value nm_right;
	nm_value nm_rez;

	equation_analizer oper_rez;

	eqation_el el_rez;

	while ( calc_operation_number() > 0 )
	{
		n_operation_hight_level = find_operation_hight_level();

		int n_left_operand = n_operation_hight_level - 1;
		int n_right_operand = n_operation_hight_level + 1;

		nm_left = culc_operand ( n_left_operand );
		nm_right = culc_operand ( n_right_operand );

		{ //Блок вычисления операции
			eqation_el el_operation;
			el_operation = m_operands_lst.at ( n_operation_hight_level );
			if ( el_operation.el_str == "+" )
			{
				nm_rez = nm_left + nm_right;
			}
			else if ( el_operation.el_str == "-" )
			{
				nm_rez = nm_left - nm_right;
			}
			else if ( el_operation.el_str == "*" )
			{
				nm_rez = nm_left * nm_right;
			}
			else if ( el_operation.el_str == "/" )
			{
				nm_rez = nm_left / nm_right;
			}
			else
			{
				nm_rez = 0.0;
			}
		} //Блок вычисления операции
		{ //Блок свертки списка опера(ций/торов)
			el_rez.nm_val = nm_rez;
			el_rez.lexem_type = eqation_el::type_value;
			el_rez.lexem_level = 0;
//			el_rez.lexem_start;
//			el_rez.lexem_end;
			el_rez.el_str = "";

			m_operands_lst.replace ( n_operation_hight_level, el_rez );

			if ( n_right_operand >= 0 && n_right_operand < m_operands_lst.size() )
				m_operands_lst.removeAt ( n_right_operand );
			if ( n_left_operand >= 0 && n_left_operand < m_operands_lst.size() )
				m_operands_lst.removeAt ( n_left_operand );
		} //Блок свертки списка операц(ий/торов)
	} //while((n_operations=calc_operation_number())>0)

	nm_rez = culc_operand ( 0 );
	m_value = nm_rez ;

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "bool equation_analizer::culculate()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif

	return ret_code;
}

void equation_analizer::print_Lexem_lst ( std::ostream & os )
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "void equation_analizer::print_Lexem_lst( std::ostream & os )"
		<< "\t" << "start..." << endl;
	}
#endif

	for ( int i = 0; i < m_lexem_lst.size(); ++i )
		os << m_lexem_lst.at ( i ).toStdString() << endl;
	os << endl;

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "void equation_analizer::print_Lexem_lst( std::ostream & os )"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
}


void equation_analizer::print_Lexem_lst_as_Sting ( std::ostream & os )
{

#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "void equation_analizer::print_Lexem_lst_as_Sting( std::ostream & os )"
		<< "\t" << "start..." << endl;
	}
#endif

	for ( int i = 0; i < m_lexem_lst.size(); ++i )
		os << m_lexem_lst.at ( i ).toStdString() << " ";
	os << endl;

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "void equation_analizer::print_Lexem_lst( std::ostream & os )"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
}

void equation_analizer::print_Operands_lst ( std::ostream & os )
{

#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "void equation_analizer::print_Operands_lst( std::ostream & os )"
		<< "\t" << "start..." << endl;
	}
#endif


	QString str;
	eqation_el el;
	for ( int i = 0; i < m_operands_lst.size(); ++i )
	{
		//		os << m_operands_lst.at( i ) << " ";
		el = m_operands_lst.at ( i );
		os << "\n" << i << " ";
		for ( int j = el.lexem_start;j <= el.lexem_end;++j )
		{
			str = m_lexem_lst.at ( j );
			os << str.toStdString() << " ";
		}
	}
	os << endl;

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "void equation_analizer::print_Operands_lst( std::ostream & os )"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
}

int equation_analizer::devide_on_lexem()
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::devide_on_lexem()"
		<< "\t" << "start..." << endl;
	}
#endif

//	QRegExp rx ( "(((\\d+\\.?\\d*)(\\[[^\\[\\]]+\\])?)|(-)|(\\+)|(\\*)|(/)|(\\()|(\\)))" );
	QRegExp rx ( "(((\\d+\\.?\\d*([eE][\\+-]?\\d+)?)(\\[[^\\[\\]]+\\])?)|(-)|(\\+)|(\\*)|(/)|(\\()|(\\)))" );

	int pos = 0;
	int i = 0;

	while ( ( pos = rx.indexIn ( m_equation, pos ) ) != -1 )
	{
		++i;
		m_lexem_lst << rx.cap ( 1 );
		pos += rx.matchedLength();
	}

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::devide_on_lexem()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
	return i;
}

int equation_analizer::is_bracketBalanced()
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::is_bracketBalanced()"
		<< "\t" << "start..." << endl;
	}
#endif

	QString str;
	int bracket = 0;

	for ( int i = 0; i < m_lexem_lst.size(); ++i )
	{
		str = m_lexem_lst.at ( i ) ;
		if ( str == "(" )
			++bracket;
		if ( str == ")" )
			--bracket;
	}

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::is_bracketBalanced()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
	return bracket;
}

///Строит сопряженный со списком лексем список опреандов.
int equation_analizer::build_operands_lst()
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::build_operands_lst()"
		<< "\t" << "start..." << endl;
	}
#endif

	QString str;

	int bracket = 0; //Глубина вложенности скобок.
	m_operands_lst.clear();
	eqation_el el;

	for ( int i = 0; i < m_lexem_lst.size(); ++i )
	{
		str = m_lexem_lst.at ( i ) ;
		if ( str == "(" )
		{
			if ( bracket == 0 )
			{
				el.lexem_start = i;
			}
			++bracket;
		}
		else if ( str == ")" )
		{
			--bracket;
			if ( bracket == 0 )
			{
				el.lexem_end = i;
				el.lexem_type = eqation_el::type_operand_in_brackets;
				el.el_str = "()";
				el.lexem_level = 0;
				m_operands_lst.append ( el );
			}
		}
		else if ( bracket == 0 )
		{
			if ( str == "+" )
			{
				el.lexem_start = el.lexem_end = i;
				el.lexem_type = eqation_el::type_operation;
				el.el_str = "+";
				el.lexem_level = 0;
				m_operands_lst.append ( el );
			}
			else if ( str == "-" )
			{
				el.lexem_start = el.lexem_end = i;
				el.lexem_type = eqation_el::type_operation;
				el.lexem_level = 0;
				el.el_str = "-";
				m_operands_lst.append ( el );
			}
			else if ( str == "*" )
			{
				el.lexem_start = el.lexem_end = i;
				el.lexem_type = eqation_el::type_operation;
				el.el_str = "*";
				el.lexem_level = 0;
				m_operands_lst.append ( el );
			}
			else if ( str == "/" )
			{
				el.lexem_start = el.lexem_end = i;
				el.lexem_type = eqation_el::type_operation;
				el.el_str = "/";
				el.lexem_level = 0;
				m_operands_lst.append ( el );
			}
			else
			{
				el.lexem_start = el.lexem_end = i;
				el.lexem_type = eqation_el::type_operand;
				el.el_str = str;
				el.lexem_level = 0;
				m_operands_lst.append ( el );
			}
		} //if ( bracket == 0 )
	} //for ( int i = 0; i < m_lexem_lst.size(); ++i )

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::build_operands_lst()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif

	return 0;
}

int equation_analizer::get_State() const
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::get_State() const"
		<< "\t" << "start..." << endl;
	}
#endif

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::get_State() const"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
	return m_state;
}


nm_value equation_analizer::get_Value() const
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "nm_value equation_analizer::get_Value() const"
		<< "\t" << "start..." << endl;
	}
#endif

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "nm_value equation_analizer::get_Value() const"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
	return m_value;
}


QString equation_analizer::get_Error_string() const
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "QString equation_analizer::get_Error_string() const"
		<< "\t" << "start..." << endl;
	}
#endif

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "QString equation_analizer::get_Error_string() const"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
	return m_error_string;
}

int equation_analizer::calc_operation_number()
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::calc_operation_number()"
		<< "\t" << "start..." << endl;
	}
#endif

	QString str;
	eqation_el el;
	int op_count = 0;
	for ( int i = 0; i < m_operands_lst.size(); ++i )
	{
		el = m_operands_lst.at ( i );
		if ( el.lexem_type == eqation_el::type_operation )
		{
			++ op_count ;
		}
	}

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "int equation_analizer::calc_operation_number()"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
	return op_count ;
}

QString equation_analizer::get_Equation() const
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "QString equation_analizer::get_Equation() const"
		<< "\t" << "start..." << endl;
	}
#endif

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "QString equation_analizer::get_Equation() const"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
	return m_equation;
}

void equation_analizer::set_Equation ( const QString& theValue )
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "void equation_analizer::set_Equation( const QString& theValue )"
		<< "\t" << "start..." << endl;
	}
#endif

	m_lexem_lst.clear();
	m_operands_lst.clear();
	m_error_string = "";
	m_state = equation_analizer::st_clear;
	m_value = 0.0;

	m_equation = theValue;
	devide_on_lexem();	//	print_Lexem_lst( cout );	//	print_Lexem_lst_as_Sting( cout );

	int brackets = is_bracketBalanced(); //Количество сбалансированных скобок.
	if ( brackets != 0 )
	{
#if defined NM_FULL_DEBUG
		cout << "Equation not balanced = " << brackets << "." << endl;
#endif
		m_state = equation_analizer::st_value_error;
		m_error_string = QString ( "Небаланс скобок в выражении: " ) + theValue ;
		return ;
	}
	build_operands_lst();

#if defined NM_FULL_DEBUG
	cout << "Equation balanced." << endl;
	print_Operands_lst ( cout );
#endif

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "void equation_analizer::set_Equation( const QString& theValue )"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
}

void equation_analizer::set_Operand ( const equation_analizer & aEA, int operand )
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "void equation_analizer::set_Operand( const equation_analizer & aEA, int operand )"
		<< "\t" << "start..." << endl;
	}
#endif
	QString str;
	eqation_el el;

	m_lexem_lst.clear();
	m_operands_lst.clear();
	m_error_string = "";
	m_state = equation_analizer::st_clear;
	m_value = 0.0;

	el = aEA.m_operands_lst.at ( operand );
	if ( el.lexem_type == eqation_el::type_operand_in_brackets )
	{
		for ( int j = el.lexem_start + 1;j < el.lexem_end;++j )
		{
			str = aEA.m_lexem_lst.at ( j );
			m_lexem_lst << str;
		}
	}
	else
		for ( int j = el.lexem_start;j <= el.lexem_end;++j )
		{
			str = aEA.m_lexem_lst.at ( j );
			m_lexem_lst << str;
		}
#if defined NM_FULL_DEBUG
	print_Lexem_lst_as_Sting ( cout );
#endif

	build_operands_lst();

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		print_Operands_lst ( cout );
		cout << endl << tab_string
		<< "void equation_analizer::set_Operand( const equation_analizer & aEA, int operand )"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif
}

nm_value equation_analizer::culc_operand ( int operand )
{
#if defined NM_DEBUG
	{
		++tab_size;
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "nm_value equation_analizer::culc_operand( int operand )"
		<< "\t" << "start..." << endl;
	}
#endif

	///Перед выполнением данной функции должен быть сформирован список лексем m_lexem_lst и список операндов_операций_значений m_operands_lst.
	nm_value nm_rez;
	eqation_el eq_elem;
	equation_analizer ea_sub_equation;

	if ( operand >= 0 && operand < m_operands_lst.size() )
	{
		eq_elem = m_operands_lst.at ( operand );
		switch ( eq_elem.lexem_type )
		{
			case eqation_el::type_value:
				nm_rez = eq_elem.nm_val;
				break;
			case eqation_el::type_operand:
#if defined NM_DEBUG
				cout << eq_elem.el_str.toStdString () << endl ;
#endif
				//nm_rez = eq_elem.el_str.toDouble();
				nm_rez = nm_value::fromQString(eq_elem.el_str);
				break;
			case eqation_el::type_operand_in_brackets:
				ea_sub_equation.set_Operand ( *this, operand );
				ea_sub_equation.culculate();
				nm_rez = ea_sub_equation.get_Value();
				break;
			default:
				nm_rez = 0.0; //Выражение неизвестного типа.
#if defined NM_DEBUG
				cout << "Выражение неизвестного типа." << endl ;
#endif
				break;
		}
	}
	else
	{ //error
		nm_rez = 0.0; //Выражение неизвестного типа.
	}

#if defined NM_DEBUG
	{
		tab_string="";
		for ( int i = 0; i<tab_size;++i ) tab_string+=" ";
		cout << endl << tab_string
		<< "nm_value equation_analizer::culc_operand( int operand )"
		<< "\t" << "ended." << endl;
		--tab_size;
	}
#endif

	return nm_rez;
}
