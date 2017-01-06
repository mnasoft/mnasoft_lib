/********************************************************************************************************
 * PROGRAM      : temp_qmake_qregexp
 * DATE - TIME  : понедельник 28 мая 2007 - 10h52
 * AUTHOR       : matveev ( matveev@mksat.net )
 * FILENAME     : nm_value.cpp
 * LICENSE      : GPL
 * COMMENTARY   : 
 ********************************************************************************************************/

#include <QtCore>

#include "nm_value.h"
#include <math.h>

//#define debug_nm_value_cpp

///Стандартные потоки ввода и вывода.
MNASOFT_EXPORT QTextStream std_in ( stdin );
MNASOFT_EXPORT QTextStream std_out ( stdout );

bool nm_value::good = true ;

///Содержит строку с множителями для образования кратных единиц (английской язык).
QString nm_value::str_Mnozitel_C_en ;// "E|P|T|G|M|k|h|da|d|c|m|mk|n|p|f|a";
///Содержит строку с множителями для образования кратных единиц (русский язык).
QString nm_value::str_Mnozitel_C_ru ;// "Э|П|Т|Г|М|к|г|да|д|с|м|мк|н|п|ф|а";

///Содержит строку с обозначениями основных единиц системы Си (английской язык).
QString nm_value::str_Ed_Osnovn_C_en ;// QString::fromUtf8("m|g|s|A|K|cd|mol");
///Содержит строку с обозначениями основных единиц системы Си (русский язык).
QString nm_value::str_Ed_Osnovn_C_ru ;// QString::fromUtf8("м|г|с|А|К|кд|моль");

///Содержит строку с обозначениями производных единиц системы Си, имеющих самостоятельные названия (английской язык).
QString nm_value::str_Ed_Proizvodn_C_en ;// QString::fromUtf8("Hz|N|Pa|J|W|C|V|Om|S|F|Wb|H|T|lm|lx|Bq|Gy|Sv");
///Содержит строку с обозначениями производных единиц системы Си, имеющих самостоятельные названия (русский язык).
QString nm_value::str_Ed_Proizvodn_C_ru ;// QString::fromUtf8("Гц|Н|Па|Дж|Вт|Кл|В|Ом|См|Ф|Вб|Гн|Тл|лм|лк|Бк|Гр|Зв");

///Содержит строку с обозначениями внесистемных единиц (английский язык).
QString nm_value::str_Ed_Not_C_en ;// QString::fromUtf8("ts|gs|cal|St|mm_Hg|mm_H2O");
///Содержит строку с обозначениями внесистемных единиц (русский язык).
QString nm_value::str_Ed_Not_C_ru ;// QString::fromUtf8("тс|гс|кал|Ст|мм_рт\\.ст\\.|мм_вод\\.ст\\.");

///Хештаблица содержит приставки и соответствующие им множители для образования кратных и дольных единиц на en языке.
QHash<QString, double> nm_value::hash_Mnozitel_C_en;
///Хештаблица содержит приставки  и соответствующие им множители для образования кратных и дольных единиц на ru языке.
QHash<QString, double> nm_value::hash_Mnozitel_C_ru;

///Хештаблица содержит обозначения основных единиц системы Си (английской язык).
QHash<QString, nm_value> nm_value::hash_Ed_Osnovn_C_en;
///Хештаблица содержит обозначения основных единиц системы Си (русский язык).
QHash<QString, nm_value> nm_value::hash_Ed_Osnovn_C_ru;

///Хештаблица содержит обозначения производных единиц системы Си, имеющих самостоятельные названия (английской язык).
QHash<QString, nm_value> nm_value::hash_Ed_Proizvodn_C_en ;
///Хештаблица содержит обозначения производных единиц системы Си, имеющих самостоятельные названия (английской язык).
QHash<QString, nm_value> nm_value::hash_Ed_Proizvodn_C_ru ;

///Хештаблица содержит обозначения внесистемных единиц (английской язык).
QHash<QString, nm_value> nm_value::hash_Ed_Not_C_en ;
///Хештаблица содержит обозначения внесистемных единиц (русский язык).
QHash<QString, nm_value> nm_value::hash_Ed_Not_C_ru ;


QHash<QString, nm_value> nm_value::hash_name_ru ;
QHash<QString, nm_value> nm_value::hash_name_en ;

///Регулярное выражение, служащее для распознавания беззнакового целого чила.
QRegExp nm_value::rx_digit;
///Регулярное выражение, служащее для основных и производных единиц системы Си, а также, некоторых внесистемных en и ru единиц.
QRegExp nm_value::rx_Ed_O_P_C_en_ru;
///Регулярное выражение, служащее для основных и производных единиц системы Си, а также, некоторых внесистемных en и ru единиц.
QRegExp nm_value::rx_koeff_Ed_O_P_C_en_ru;

QRegExp rx_value ;

QRegExp rx_dim;

///Принимает значение true - если статические члены класса проинициализированы и false в противном случае.
bool	nm_value::is_inited=false;

void foo ( int stepen, QString str_stepen , QString & str_chisl, QString & str_znam );

nm_value::nm_value() : val ( 0.0e0 ) , m ( 0 ), kg ( 0 ), s ( 0 ), A ( 0 ), K ( 0 ), cd ( 0 ), mol ( 0 ), rad ( 0 ), sr ( 0 )
{
//	init_value();
}

nm_value::nm_value ( double a_val , int a_m , int a_kg , int a_s , int a_A , int a_K , int a_cd , int a_mol , int a_rad , int a_sr )
		: val ( a_val ), m ( a_m )	, kg ( a_kg ), s ( a_s ), A ( a_A ), K ( a_K ), cd ( a_cd ), mol ( a_mol ), rad ( a_rad ), sr ( a_sr )
{
//	init_value();
}

nm_value::nm_value ( double a_val, QString const & a_string )
		: val ( a_val ), m ( 0 ), kg ( 0 ), s ( 0 ), A ( 0 ), K ( 0 ), cd ( 0 ), mol ( 0 ), rad ( 0 ), sr ( 0 )
{
	init_value();
	set(a_val, a_string);
}

nm_value::nm_value ( QString const & a_string )
{
	init_value();
	set(a_string);
}

nm_value::nm_value ( nm_value const & a_val )
{
//	init_value();
	
	val = a_val.val;

	good = a_val.good;

	m = a_val.m;
	kg = a_val.kg;
	s = a_val.s;
	A = a_val.A;
	K = a_val.K;
	cd = a_val.cd;
	mol = a_val.mol;

	rad = a_val.rad;
	sr = a_val.sr;
}

nm_value::~nm_value()
{
}

nm_value & nm_value::operator = ( nm_value const & a_val )
{
	set(a_val);
	return *this;
}

void nm_value::set_dimensions ( nm_value const & a_val )
{
	m = a_val.m;
	kg = a_val.kg;
	s = a_val.s;
	A = a_val.A;
	K = a_val.K;
	cd = a_val.cd;
	mol = a_val.mol;

	rad = a_val.rad;
	sr = a_val.sr;
}

nm_value nm_value::operator * ( nm_value const & second ) const
{
	nm_value rez;

	rez.good = good && second.good;

	rez.val = val * second.val;

	rez.m = m + second.m;
	rez.kg = kg + second.kg;
	rez.s = s + second.s;
	rez.A = A + second.A;
	rez.K = K + second.K;
	rez.cd = cd + second.cd;
	rez.mol = mol + second.mol;

	rez.rad = rad + second.rad;
	rez.sr = sr + second.sr;
	return rez;
}

nm_value nm_value::operator / ( nm_value const & second ) const
{
	nm_value rez;

	rez.good = good && second.good;

	rez.val = val / second.val;

	rez.m = m - second.m;
	rez.kg = kg - second.kg;
	rez.s = s - second.s;
	rez.A = A - second.A;
	rez.K = K - second.K;
	rez.cd = cd - second.cd;
	rez.mol = mol - second.mol;

	rez.rad = rad - second.rad;
	rez.sr = sr - second.sr;
	return rez;
}


nm_value nm_value::operator + ( nm_value const &second ) const
{
	nm_value rez;

	good = good && is_same_type ( second );

	rez.val = val + second.val;

	rez.m = m;
	rez.kg = kg;
	rez.s = s;
	rez.A = A;
	rez.K = K;
	rez.cd = cd;
	rez.mol = mol;

	rez.rad = rad;
	rez.sr = sr;
	return rez;
}

nm_value nm_value::operator- ( nm_value const &second ) const
{
	nm_value rez;

	rez.good = good && second.good && is_same_type ( second );

	rez.val = val - second.val;

	rez.m = m;
	rez.kg = kg;
	rez.s = s;
	rez.A = A;
	rez.K = K;
	rez.cd = cd;
	rez.mol = mol;

	rez.rad = rad;
	rez.sr = sr;
	return rez;
}

nm_value nm_value::operator + () const
{
	nm_value rez;

	rez.val = val;

	rez.good = good;

	rez.m = m;
	rez.kg = kg;
	rez.s = s;
	rez.A = A;
	rez.K = K;
	rez.cd = cd;
	rez.mol = mol;

	rez.rad = rad;
	rez.sr = sr;
	return rez;
}

nm_value nm_value::operator-() const
{
	nm_value rez;

	rez.val = -val;

	rez.good = good;

	rez.m = m;
	rez.kg = kg;
	rez.s = s;
	rez.A = A;
	rez.K = K;
	rez.cd = cd;
	rez.mol = mol;

	rez.rad = rad;
	rez.sr = sr;
	return rez;
}

bool nm_value::operator == (const nm_value & second ) const
{
	/*
	if( ! is_same_type ( second ) )
	{
		QTextStream out (stdout);
		out << QString::fromUtf8("Операнды имеют разный тип").toLocal8Bit() << endl;
	}
	*/
	return val == second.val;
}

bool nm_value::operator != (const nm_value & second ) const
{
	return ! ( operator == ( second ) );
}

bool nm_value::operator > ( const nm_value & second ) const
{
	/*
	if( ! is_same_type ( second ) )
	{
		QTextStream out (stdout);
		out << QString("Операнды имеют разный тип").toLocal8Bit() << endl;
	}
	*/
	return val > second.val;
}

bool nm_value::operator < ( const nm_value & second ) const
{
	return  ( ! (operator == (second) ) ) && (!( operator > (second) ) );
}
	
bool nm_value::operator >= ( const nm_value & second ) const
{
	return (operator == (second) || operator > (second)) ; 
}

bool nm_value::operator <= ( const nm_value & second ) const
{
	return ! ( operator > (second) );
}

bool nm_value::is_same_type ( nm_value const & second ) const
{
	bool rez;
	rez =	m == second.m &&
		kg == second.kg &&
		s == second.s &&
		A == second.A &&
		K == second.K &&
		cd == second.cd &&
		mol == second.mol &&
		rad == second.rad &&
		sr == second.sr;
	return rez;
}

 QTextStream &  operator<< (QTextStream & os, nm_value& a_val )
{
		os << a_val.val;
		os << a_val.get_dimensions();
/*
		os << " good="<< a_val.good;
		os << " m=" << a_val.m;
		os << " kg=" << a_val.kg;
		os << " s="<< a_val.s;
		os << " A="<< a_val.A;
		os << " K="<< a_val.K;
		os << " cd=" << a_val.cd;
		os << " mol="<< a_val.mol;
		os << " rad="<< a_val.rad;
		os << " sr="<< a_val.sr;
*/
//	os << endl;
	return os;
}

QTextStream & operator>> (QTextStream & is, nm_value& a_val )
{
	QString qstr;
	is >> qstr;
	a_val = nm_value::fromQString ( qstr );
	return is;
}


void nm_value::set_dimensions (int a_m, int a_kg, int a_s, int a_A, int a_K, int a_cd, int a_mol, int a_rad, int a_sr)
{
	m = a_m ;
	kg = a_kg ;
	s = a_s;
	A = a_A;
	K = a_K;
	cd = a_cd;
	mol = a_mol ;
	rad = a_rad;
	sr = a_sr ;
}

nm_value nm_value :: pown ( const double n /**показатель степени*/) const
{
//Размерность числа при этом не изменяется.

	nm_value rez = *this;
	rez.val = pow ( val, n);
	return rez;
}

nm_value nm_value::pownm ( const int n) const
{
	nm_value tmp = *this;
	nm_value rez = 1.0;
	if ( n > 0 )
	{
		for ( int i = 0; i < n;++i )
			rez = rez * tmp;
	}
	else 
	if ( n < 0 )
	{
		for ( int i = 0; i > n;--i )
			rez = rez / tmp;
	}
	return rez;
}

nm_value nm_value::pownm2 ( const int n, const int am) const
{
	nm_value tmp = *this;
	nm_value rez = 1.0;
	if ( m == 1 )
	{
		if ( n > 0 )
		{
			for ( int i = 0; i < n;++i )
				rez = rez * tmp;
			return rez;
		}
		else if ( n < 0 )
		{
			for ( int i = 0; i > n;--i )
				rez = rez / tmp;
			return rez;
		}
	}
	
	rez.val = pow ( val , double (n) / double(am) );	///Мантисса ЧсР.
	rez.m = ( m * n ) / am;		///<Степень размерности [метр].
	rez.kg = ( kg * n ) / am;		///<Степень размерности [килограмм].
	rez.s = ( s * n ) / am;		///<Степень размерности [секунда].
	rez.A = ( A * n ) / am;		///<Степень размерности [ампер].
	rez.K = ( K * n ) / am;		///<Степень размерности [кельвин].
	rez.cd = ( cd * n ) / am;		///<Степень размерности [кандела].
	rez.mol = ( mol * n ) / am;		///<Степень размерности [моль].
	rez.rad = ( rad * n ) / am;		///<Степень размерности [радиан].
	rez.sr= ( sr * n ) / am;		///<Степень размерности [стерадиан].
	return rez;
}

///Устанавливает значение ЧсР.
/**
Устанавливает значение ЧсР.
*/
nm_value & nm_value::set(
	double a_val	/** - мантисса числа;*/,
	int a_m		/** - степень размерности [m];*/,
	int a_kg	/** - степень размерности [kg];*/,
	int a_s		/** - степень размерности [s];*/,
	int a_A		/** - степень размерности [A];*/,
	int a_K		/** - степень размерности [K];*/,
	int a_cd	/** - степень размерности [cd];*/,
	int a_mol	/** - степень размерности [mol];*/,
	int a_rad	/** - степень размерности [rad];*/,
	int a_sr	/** - степень размерности [sr].*/)
{
	val = a_val;

	good = true;

	m = a_m;
	kg = a_kg;
	s = a_s;
	A = a_A;
	K = a_K;
	cd = a_cd;
	mol = a_mol;

	rad = a_rad;
	sr = a_sr;
	return *this;
}

nm_value & nm_value::set(
	double a_val	/** - мантисса числа;*/,	
	QString const & a_string /** - символьное представление размерности. */ )
{
	val = a_val;
	set_dimensions();
	good = true;
	nm_value tmp = formQStringtoRazmernost ( a_string );
	*this = *this * tmp;
	return *this;
}

nm_value & nm_value::set( QString const & a_string )
{
	set( fromQString ( a_string ) );
	return *this;
}

nm_value & nm_value::set( nm_value const & a_val )
{
	val = a_val.val;

	good = a_val.good;

	m = a_val.m;
	kg = a_val.kg;
	s = a_val.s;
	A = a_val.A;
	K = a_val.K;
	cd = a_val.cd;
	mol = a_val.mol;

	rad = a_val.rad;
	sr = a_val.sr;
	return *this;
}
	
nm_value nm_value::fromQString ( const QString & str )
{
	init_value();
	QString str_value, str_dim, str_3;
	QString str_debug=str;
	double d_val;
	nm_value val;
	nm_value val_dim;


//	QRegExp rx_value ;//( "[\\+-]?\\d+\\.?\\d*([eE][\\+-]?\\d+)?" );
//	rx_value.setPattern ( "[\\+-]?\\d+\\.?\\d*([eE][\\+-]?\\d+)?" );
//	QRegExp rx_dim ( "\\[[^\\[\\]]+\\]" );


	rx_value.indexIn ( str, 0 );	str_value = rx_value.cap();
	d_val = str_value.toDouble();
	val = d_val;

	rx_dim.indexIn ( str, 0 );	str_dim = rx_dim.cap();
	val_dim = formQStringtoRazmernost ( str_dim );

	val = val * val_dim;
	return val;
}

nm_value nm_value::formQStringtoRazmernost ( const QString & str_dim )
{
	nm_value val_dim;
	QStringList list=nm_value::formQStringtoQStringList(str_dim);
	if(list.isEmpty())
		val_dim=1.0;
	else
		val_dim = fromQStringList ( list );
	return val_dim;
}

///Разделяет строку размерностей на список лексем.
/**Возвращает список лексем.*/
QStringList nm_value::formQStringtoQStringList ( const QString & str_dim )
{
	init_value();
	QStringList list;
	QString str_rx3 = 
	"((" +
	str_Mnozitel_C_en + "|" + str_Mnozitel_C_ru + ")?" 
	+ "(" + str_Ed_Osnovn_C_en + "|" + str_Ed_Osnovn_C_ru
	+ "|" + str_Ed_Proizvodn_C_en + "|" + str_Ed_Proizvodn_C_ru
	+ "|" + str_Ed_Not_C_en + "|" + str_Ed_Not_C_ru + ")" +
	")|[\\*/]|\\d+";
#ifdef debug_nm_value_cpp
	std_out<<"formQStringtoRazmernost()"<<endl;
	std_out << "str_dim = " <<str_dim << endl;
	std_out << "str_rx3 = " << str_rx3 << endl;
#endif
	QRegExp rx3 ( str_rx3 );
	int pos = 0;
	QString str_debug;
	while ( ( pos = rx3.indexIn ( str_dim, pos ) ) != -1 )
	{
		str_debug=rx3.cap();
		list << rx3.cap();
		pos += rx3.matchedLength();
	}
//	nm_value::validate(list);
	return list;
}

///Осуществляет разбор списка лексем.
/**
Принимает на разбор список лексем. \n
При разборе строки str="10.[kPa*m/s2]" список будет таким: lst = { "kPa" ; "*" ; "m" ; "/" "s" "2"}; \n
str="10[mm_Hg*kkal]" - 	lst={"mm_Hg" ; "*" ; "kkal"}.
Возвращает ЧСР значением которого является безразсерная единица умноженная на, передаваемые в функцию размерности.
*/
nm_value nm_value::fromQStringList ( QStringList & lst )
{
	nm_value::validate(lst) ;
	nm_value rez = 1.0;
	nm_value v = 1.0;
	double koeff_v;
	int koeff_stepen = 1; //+-
	int stepen;
	QString at;
	QString str_koeff, str_zazm;
	
	QString str_k_ed_1, str_k_ed_2, str_ed_1;
	int len_cap_k_ed, len_cap_ed;
	bool b_k_ed, b_ed;

	int pos;
	for ( int i = 0; i < lst.size();++i )
	{
		at = lst.at ( i );
		b_k_ed = rx_koeff_Ed_O_P_C_en_ru.indexIn ( at )  != -1 ;
		b_ed = rx_Ed_O_P_C_en_ru.indexIn ( at )  != -1;
		if (b_k_ed && b_ed)
		{
			str_k_ed_1 = rx_koeff_Ed_O_P_C_en_ru.cap ( 1 );
			str_k_ed_2 = rx_koeff_Ed_O_P_C_en_ru.cap ( 2 );
			len_cap_k_ed=(str_k_ed_1+str_k_ed_2).length();
			
			str_ed_1 = rx_Ed_O_P_C_en_ru.cap ( 1 );
			len_cap_ed=str_ed_1.length();
			if(len_cap_ed>=len_cap_k_ed)
			{
				str_zazm = str_ed_1;
				koeff_v = 1.0;
				v = formSingleQStringtoRazmernost ( str_zazm ) * koeff_v;
			}
			else
			{
				str_koeff = str_k_ed_1;
				str_zazm = str_k_ed_2;
				koeff_v = formQStringtoMnozitel ( str_koeff );
				v = formSingleQStringtoRazmernost ( str_zazm ) * koeff_v;
			}
					
		}
		else if ( rx_koeff_Ed_O_P_C_en_ru.indexIn ( at )  != -1 )
		{
#ifdef debug_nm_value_cpp
			std_out<<"at=" << at << " - " << " rx_koeff_Ed_O_P_C_en_ru " << endl;
#endif
			str_koeff = rx_koeff_Ed_O_P_C_en_ru.cap ( 1 );
			str_zazm = rx_koeff_Ed_O_P_C_en_ru.cap ( 2 );
			koeff_v = formQStringtoMnozitel ( str_koeff );
			v = formSingleQStringtoRazmernost ( str_zazm ) * koeff_v;
		}
		else if ( rx_Ed_O_P_C_en_ru.indexIn ( at )  != -1 )
		{
#ifdef debug_nm_value_cpp
			std_out<<"at=" << at << " - " << " rx_Ed_O_P_C_en_ru " << endl;
#endif
			str_zazm = rx_Ed_O_P_C_en_ru.cap ( 1 );
			koeff_v = 1.0;
			v = formSingleQStringtoRazmernost ( str_zazm ) * koeff_v;
		}
		else if ( ( pos = rx_digit.indexIn ( at ) ) != -1 )
		{
#ifdef debug_nm_value_cpp
			std_out<<"at=" << at << " - " << " rx_digit" << endl;
#endif
			stepen = at.toInt();
			v = v.pownm ( stepen );
		}
		else if ( at == "*" )
		{
#ifdef debug_nm_value_cpp
			std_out<<"at=" << at << " - " << " * " << endl;
#endif
			if ( koeff_stepen == 1 )
				rez = rez * v;
			else if ( koeff_stepen == -1 )
				rez = rez / v;
		}
		else if ( at == "/" )
		{
#ifdef debug_nm_value_cpp
			std_out<<"at=" << at << " - " << " / " << endl;
#endif
			if ( koeff_stepen == 1 )
				rez = rez * v;
			else if ( koeff_stepen == -1 )
				rez = rez / v;
			koeff_stepen = -1;
		}
	}
	if ( koeff_stepen == 1 )
		rez = rez * v;
	else if ( koeff_stepen == -1 )
		rez = rez / v;
	return rez;
}


///Осуществляет разбор строки, пердставляющей множительную приставку для единицы системы Си.
/**
Принимает на анализ строку, пердставляющую множительную приставку для единицы системы Си. \n
Возвращает значение коэффициента, если такая приставка существует, или 1 в противном случае.*/
double nm_value::formQStringtoMnozitel ( QString const & str )
{
	QHash<QString, double>::iterator i_en, i_ru;
	i_en = hash_Mnozitel_C_en.find(str);
	i_ru = hash_Mnozitel_C_ru.find(str);
	
#ifdef debug_nm_value_cpp
	std_out<<"formQStringtoMnozitel()"<<endl;
	std_out << "str = "<< str << endl;
#endif
	
	if (i_en != hash_Mnozitel_C_en.end()) return i_en.value() ;
	if (i_ru != hash_Mnozitel_C_ru.end()) return i_ru.value() ;
	return 1.0e00;
}

///Производит разбор и вычисление значения одиночной размерности.
/**
Принимает на анализ строку, предсталяющую:\n
единицу системы Си | производную от системы Си единицу | внесистемную единицу, \n
не имеющую множителя - приставки.\n
Возвращает значение единицы, или безразмерню 1.*/
nm_value nm_value::formSingleQStringtoRazmernost ( QString const & str )
{
	nm_value rez = 1.0;
	QHash<QString, nm_value>::iterator i_OC_en, i_OC_ru, i_PC_en, i_PC_ru, i_NC_en, i_NC_ru;
#ifdef debug_nm_value_cpp
	std_out<<"formSingleQStringtoRazmernost()"<<endl;
	std_out << "str = "<< str << endl;
#endif
	i_OC_en = hash_Ed_Osnovn_C_en.find(str);
	i_OC_ru = hash_Ed_Osnovn_C_ru.find(str);
	i_PC_en = hash_Ed_Proizvodn_C_en.find(str);
	i_PC_ru = hash_Ed_Proizvodn_C_ru.find(str);
	i_NC_en = hash_Ed_Not_C_en.find(str);
	i_NC_ru = hash_Ed_Not_C_ru.find(str);
/*****/
	if (i_OC_en != hash_Ed_Osnovn_C_en.end()) 
		return i_OC_en.value();
	if (i_OC_ru != hash_Ed_Osnovn_C_ru.end()) 
		return i_OC_ru.value();
/*****/
	if (i_PC_en != hash_Ed_Proizvodn_C_en.end()) 
		return i_PC_en.value();
	if (i_PC_ru != hash_Ed_Proizvodn_C_ru.end()) 
		return i_PC_ru.value();
/*****/
	if (i_NC_en != hash_Ed_Not_C_en.end()) 
		return i_NC_en.value();
	if (i_NC_ru != hash_Ed_Not_C_ru.end()) 
		return i_NC_ru.value();
/*****/
	return rez;
}


void nm_value::set_dimensions ( const QString & theValue )
{
	set_dimensions ( formQStringtoRazmernost ( theValue ) );
}

///Возвращает строку с символьным представлением размерности ЧСР в системе Си.
QString nm_value::get_dimensions () const
{
	QString rez;
	QString str_chisl;
	QString str_znam;
	if ( this->is_same_type ( get_Hz() ) ) {rez = QString::fromUtf8 ("[Hz]");}
	else if ( this->is_same_type ( get_N() ) ) {rez = QString::fromUtf8 ("[N]");}
	else if ( this->is_same_type ( get_Pa() ) ) {rez = QString::fromUtf8 ("[Pa]");}
	else if ( this->is_same_type ( get_J() ) ) {rez = QString::fromUtf8 ("[J]");}
	else if ( this->is_same_type ( get_W() ) ) {rez = QString::fromUtf8 ("[W]");}
	else if ( this->is_same_type ( get_C() ) ) {rez = QString::fromUtf8 ("[C]");}
	else if ( this->is_same_type ( get_V() ) ) {rez = QString::fromUtf8 ("[V]");}
	else if ( this->is_same_type ( get_Om() ) ) {rez = QString::fromUtf8 ("[Ω]");}
	else if ( this->is_same_type ( get_S() ) ) {rez = QString::fromUtf8 ("[S]");}
	else if ( this->is_same_type ( get_F() ) ) {rez = QString::fromUtf8 ("[F]");}
	else if ( this->is_same_type ( get_Wb() ) ) {rez = QString::fromUtf8 ("[Wb]");}
	else if ( this->is_same_type ( get_H() ) ) {rez = QString::fromUtf8 ("[H]");}
	else if ( this->is_same_type ( get_T() ) ) {rez = QString::fromUtf8 ("[T]");}
	else if ( this->is_same_type ( get_lm() ) ) {rez = QString::fromUtf8 ("[lm]");}
	else if ( this->is_same_type ( get_lx() ) ) {rez = QString::fromUtf8 ("[lx]");}
	else if ( this->is_same_type ( get_Bq() ) ) {rez = QString::fromUtf8 ("[Bq]");}
	else if ( this->is_same_type ( get_Gy() ) ) {rez = QString::fromUtf8 ("[Gy]");}
	else if ( this->is_same_type ( get_Sv() ) ) {rez = QString::fromUtf8 ("[Sv]");}
	else
	{
		if ( m == 0 && kg == 0 && s == 0 && A == 0 && K == 0 && cd == 0 && mol == 0 && rad == 0 && sr == 0 )
		{
			rez = "[1]";
		}
		else
		{
			foo ( m, "m" , str_chisl, str_znam );
			foo ( kg, "kg" , str_chisl, str_znam );
			foo ( s , "s" , str_chisl, str_znam );
			foo ( A, "A" , str_chisl, str_znam );
			foo ( K, "K" , str_chisl, str_znam );
			foo ( cd, "cd" , str_chisl, str_znam );
			foo ( mol , "mol" , str_chisl, str_znam );
			foo ( rad , "rad" , str_chisl, str_znam );
			foo ( sr , "sr" , str_chisl, str_znam );
			str_chisl = str_chisl.left ( str_chisl.size() - 1 );
			str_znam = str_znam.left ( str_znam.size() - 1 );
			if ( str_chisl.size() == 0 )
				str_chisl = "1";
			if ( str_znam.size() > 0 )
				rez = "[" + str_chisl + "/" + str_znam + "]";
			else
				rez = "[" + str_chisl + "]";
		}
	}
	return rez;
}

void foo ( int stepen, QString str_stepen , QString & str_chisl, QString & str_znam )
{
	if ( stepen > 1 )
	{
		str_chisl += str_stepen + QString::number ( stepen ) + "*";
	}
	else if ( stepen == 1 )
	{
		str_chisl += str_stepen + "*";
	}
	else if ( stepen == -1 )
	{
		str_znam += str_stepen + "*";
	}
	else if ( stepen < -1 )
	{
		str_znam += str_stepen + QString::number ( -stepen ) + "*";
	}
}

///Производит инициализацию статических членов класса nm_value.
bool nm_value::init_value()
{
	if(is_inited) 
		return is_inited;
	is_inited=true;
#ifdef win32
///Загрузка кодека для консоли Windows.
	QTextCodec *codec = QTextCodec::codecForName("CP866");
	std_out.setCodec(codec);
	std_in.setCodec(codec);
#endif
	{
		hash_Mnozitel_C_en[QString::fromUtf8("Y")]=1e24;
		hash_Mnozitel_C_en[QString::fromUtf8("Z")]=1e21;
		hash_Mnozitel_C_en[QString::fromUtf8("E")]=1e18;
		hash_Mnozitel_C_en[QString::fromUtf8("P")]=1e15;
		hash_Mnozitel_C_en[QString::fromUtf8("T")]=1e12;
		hash_Mnozitel_C_en[QString::fromUtf8("G")]=1e9;
		hash_Mnozitel_C_en[QString::fromUtf8("M")]=1e6;
		hash_Mnozitel_C_en[QString::fromUtf8("k")]=1e3;
		hash_Mnozitel_C_en[QString::fromUtf8("h")]=1e2;
		hash_Mnozitel_C_en[QString::fromUtf8("da")]=1e1;
		hash_Mnozitel_C_en[QString::fromUtf8("d")]=1e-1;
		hash_Mnozitel_C_en[QString::fromUtf8("c")]=1e-2;
		hash_Mnozitel_C_en[QString::fromUtf8("m")]=1e-3;
		hash_Mnozitel_C_en[QString::fromUtf8("μ")]=1e-6;
		hash_Mnozitel_C_en[QString::fromUtf8("n")]=1e-9;
		hash_Mnozitel_C_en[QString::fromUtf8("p")]=1e-12;
		hash_Mnozitel_C_en[QString::fromUtf8("f")]=1e-15;
		hash_Mnozitel_C_en[QString::fromUtf8("a")]=1e-18;
		hash_Mnozitel_C_ru[QString::fromUtf8("z")]=1e-21;
		hash_Mnozitel_C_ru[QString::fromUtf8("y")]=1e-24;
	}
	{
		hash_Mnozitel_C_ru[QString::fromUtf8("Э")]=1e18;
		hash_Mnozitel_C_ru[QString::fromUtf8("П")]=1e15;
		hash_Mnozitel_C_ru[QString::fromUtf8("Т")]=1e12;
		hash_Mnozitel_C_ru[QString::fromUtf8("Г")]=1e9;
		hash_Mnozitel_C_ru[QString::fromUtf8("М")]=1e6;
		hash_Mnozitel_C_ru[QString::fromUtf8("к")]=1e3;
		hash_Mnozitel_C_ru[QString::fromUtf8("г")]=1e2;
		hash_Mnozitel_C_ru[QString::fromUtf8("да")]=1e1;
		hash_Mnozitel_C_ru[QString::fromUtf8("д")]=1e-1;
		hash_Mnozitel_C_ru[QString::fromUtf8("с")]=1e-2;
		hash_Mnozitel_C_ru[QString::fromUtf8("м")]=1e-3;
		hash_Mnozitel_C_ru[QString::fromUtf8("мк")]=1e-6;
		hash_Mnozitel_C_ru[QString::fromUtf8("н")]=1e-9;
		hash_Mnozitel_C_ru[QString::fromUtf8("п")]=1e-12;
		hash_Mnozitel_C_ru[QString::fromUtf8("ф")]=1e-15;
		hash_Mnozitel_C_ru[QString::fromUtf8("а")]=1e-18;
	}
	{
		hash_Ed_Osnovn_C_en [QString::fromUtf8("m")]=get_m();
		hash_Ed_Osnovn_C_en [QString::fromUtf8("g")]=get_kg()/1000.0;
		hash_Ed_Osnovn_C_en [QString::fromUtf8("s")]=get_s();
		hash_Ed_Osnovn_C_en [QString::fromUtf8("A")]=get_A();
		hash_Ed_Osnovn_C_en [QString::fromUtf8("K")]=get_K();
		hash_Ed_Osnovn_C_en [QString::fromUtf8("cd")]=get_cd();
		hash_Ed_Osnovn_C_en [QString::fromUtf8("mol")]=get_mol();
		
		hash_Ed_Osnovn_C_en [QString::fromUtf8("rad")]=get_rad();
		hash_Ed_Osnovn_C_en [QString::fromUtf8("sr")]=get_sr();
	}

	{
		hash_Ed_Osnovn_C_ru [QString::fromUtf8("м")]=get_m();
		hash_Ed_Osnovn_C_ru [QString::fromUtf8("г")]=nm_value(0.001)*get_kg();
		hash_Ed_Osnovn_C_ru [QString::fromUtf8("с")]=get_s();
		hash_Ed_Osnovn_C_ru [QString::fromUtf8("А")]=get_A();
		hash_Ed_Osnovn_C_ru [QString::fromUtf8("К")]=get_K();
		hash_Ed_Osnovn_C_ru [QString::fromUtf8("кд")]=get_cd();
		hash_Ed_Osnovn_C_ru [QString::fromUtf8("моль")]=get_mol();				
	}
	{
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("Hz")]=get_Hz();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("N")]=get_N();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("Pa")]=get_Pa();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("J")]=get_J();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("W")]=get_W();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("C")]=get_C();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("V")]=get_V();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("Ω")]=get_Om();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("S")]=get_S();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("F")]=get_F();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("Wb")]=get_Wb();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("H")]=get_H();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("T")]=get_T();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("lm")]=get_lm();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("lx")]=get_lx();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("Bq")]=get_Bq();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("Gy")]=get_Gy();
		hash_Ed_Proizvodn_C_en[QString::fromUtf8("Sv")]=get_Sv();
	}
	{
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Гц")]=get_Hz();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Н")]=get_N();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Па")]=get_Pa();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Дж")]=get_J();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Вт")]=get_W();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Кл")]=get_C();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("В")]=get_V();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Ом")]=get_Om();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("См")]=get_S();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Ф")]=get_F();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Вб")]=get_Wb();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Гн")]=get_H();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Тл")]=get_T();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("лм")]=get_lm();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("лк")]=get_lx();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Бк")]=get_Bq();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Гр")]=get_Gy();
		hash_Ed_Proizvodn_C_ru[QString::fromUtf8("Зв")]=get_Sv();
	}
	{
		hash_Ed_Not_C_en [QString::fromUtf8("ts")]= nm_value(9806.65) * get_N();
		hash_Ed_Not_C_en [QString::fromUtf8("gs")]= nm_value(9.80665e-3) * get_N();
		hash_Ed_Not_C_en [QString::fromUtf8("cal")]= nm_value(4.1868)*get_J();
		hash_Ed_Not_C_en [QString::fromUtf8("St")] = nm_value(1.0e-4, 2 , 0 , -1 , 0 , 0 , 0 , 0 , 0 , 0 );
		hash_Ed_Not_C_en [QString::fromUtf8("m_Hg")]= nm_value(133322.0)*get_Pa();
		hash_Ed_Not_C_en [QString::fromUtf8("m_H2O")]= nm_value(9806.65)*get_Pa();
		
		hash_Ed_Not_C_en [QString::fromUtf8("ua")]= nm_value(1.49597870e11)*get_m();
		hash_Ed_Not_C_en [QString::fromUtf8("Å")]= nm_value(1.0e-10)*get_m();
		
		hash_Ed_Not_C_en [QString::fromUtf8("t")]= nm_value(1000.0)*get_kg();
		hash_Ed_Not_C_en [QString::fromUtf8("u")]= nm_value(1.6605402e-27)*get_kg();
		hash_Ed_Not_C_en [QString::fromUtf8("eV")]= nm_value(1.60217733e-19)*get_J();
		
		hash_Ed_Not_C_en [QString::fromUtf8("min")]= nm_value(60.0)*get_s();
		hash_Ed_Not_C_en [QString::fromUtf8("h")]= nm_value(3600.0)*get_s();
		hash_Ed_Not_C_en [QString::fromUtf8("d")]= nm_value(86400.0)*get_s();
		
		hash_Ed_Not_C_en [QString::fromUtf8("a")]= nm_value(100.0,2);
		hash_Ed_Not_C_en [QString::fromUtf8("b")]= nm_value(1.0e-28,2);
		
		hash_Ed_Not_C_en [QString::fromUtf8("knot")]= nm_value(1852.0/3600.0,1,0,-1);
		
		hash_Ed_Not_C_en [QString::fromUtf8("Gal")]= nm_value(1.0e-2,1,0,-2);
		
		hash_Ed_Not_C_en [QString::fromUtf8("bar")]= nm_value(1.0e5)*get_Pa();
		hash_Ed_Not_C_en [QString::fromUtf8("atm")]= nm_value(101325.0)*get_Pa();
		hash_Ed_Not_C_en [QString::fromUtf8("Torr")]= nm_value(101325.0/760.0)*get_Pa();
		
		hash_Ed_Not_C_en [QString::fromUtf8("kat")]= nm_value(1.0,0,0,-1,0,0,0,1);
		
	}
	{
		hash_Ed_Not_C_ru [QString::fromUtf8("тс")]  = nm_value(9806.65) * get_N();
		hash_Ed_Not_C_ru [QString::fromUtf8("гс")]  = nm_value(9.80665e-3) * get_N();
		hash_Ed_Not_C_ru [QString::fromUtf8("кал")] = nm_value(4.1868)*get_J();
		hash_Ed_Not_C_ru [QString::fromUtf8("Ст")]	 = nm_value(1.0e-4, 2 , 0 , -1 , 0 , 0 , 0 , 0 , 0 , 0 );
		hash_Ed_Not_C_ru [QString::fromUtf8("м_рт_ст")]= nm_value(133322.0)*get_Pa();
		hash_Ed_Not_C_ru [QString::fromUtf8("м_вод_ст")]= nm_value(9806.65)*get_Pa();
	}
	{
		hash_name_ru [QString::fromUtf8("длина")]= get_m();
		hash_name_en [QString::fromUtf8("length")]= get_m();
		hash_name_ru [QString::fromUtf8("масса")]= get_kg();
		hash_name_en [QString::fromUtf8("mass")]= get_kg();
		hash_name_ru [QString::fromUtf8("время")]=get_s();
		hash_name_en [QString::fromUtf8("time")]=get_s();
		hash_name_ru [QString::fromUtf8("сила тока")]=get_A();
		hash_name_en [QString::fromUtf8("electric current")]=get_A();
		hash_name_ru [QString::fromUtf8("температура")]=get_K();
		hash_name_en [QString::fromUtf8("temperature")]=get_K();
		hash_name_ru [QString::fromUtf8("количество вещества")]=get_mol();
		hash_name_en [QString::fromUtf8("amount of substance")]=get_mol();
		hash_name_ru [QString::fromUtf8("сила света")]=get_cd();
		hash_name_en [QString::fromUtf8("luminous intensity")]=get_cd();


		hash_name_ru [QString::fromUtf8("площадь")]= get_m().pownm(2) ;
		hash_name_en [QString::fromUtf8("area")]= get_m().pownm(2) ;
		hash_name_ru [QString::fromUtf8("объем")]= get_m().pownm(3) ;
		hash_name_en [QString::fromUtf8("volume")]= get_m().pownm(3) ;
		hash_name_ru [QString::fromUtf8("скорость")]= get_m()/get_s();	
		hash_name_en [QString::fromUtf8("velocity")]= get_m()/get_s();  // speed, velocity
		hash_name_ru [QString::fromUtf8("ускорение")]= get_m()/get_s().pownm(2);
		hash_name_en [QString::fromUtf8("acceleration")]= get_m()/get_s().pownm(2);
		hash_name_ru [QString::fromUtf8("волновое число")]=get_m().pownm(-1);
		hash_name_en [QString::fromUtf8("wave number")]=get_m().pownm(-1);
		hash_name_ru [QString::fromUtf8("плотность")]= get_kg()/get_m().pownm(3);
		hash_name_en [QString::fromUtf8("mass density")]= get_kg()/get_m().pownm(3);
		hash_name_ru [QString::fromUtf8("удельный объём")]= get_m().pownm(3)/get_kg();
		hash_name_en [QString::fromUtf8("specific volume")]= get_m().pownm(3)/get_kg();
		hash_name_ru [QString::fromUtf8("плотность электрического тока")]=get_A()/get_m().pownm(2);
		hash_name_en [QString::fromUtf8("current density")]=get_A()/get_m().pownm(2);
		hash_name_ru [QString::fromUtf8("напряжённость магнитного поля")]=get_A()/get_m();
		hash_name_en [QString::fromUtf8("magnetic field strength")]=get_A()/get_m();
		//****************************************************************************************************/
		hash_name_en [QString::fromUtf8("amount-of-substance concentration")]=get_mol()/get_m().pownm(3);
		hash_name_ru [QString::fromUtf8("яркость")]=get_cd()/get_m().pownm(2);
		hash_name_en [QString::fromUtf8("luminance")]=get_cd()/get_m().pownm(2);

		//"mass fraction"
		
		hash_name_ru [QString::fromUtf8("плоский угол")]=get_rad();
		hash_name_en [QString::fromUtf8("plane angle")]=get_rad();

		hash_name_ru [QString::fromUtf8("телесный угол")]=get_sr();
		hash_name_en [QString::fromUtf8("solid angle")]=get_sr();

		hash_name_ru [QString::fromUtf8("частота")]= get_Hz();
		hash_name_en [QString::fromUtf8("frequency")]= get_Hz();

		hash_name_ru [QString::fromUtf8("сила")]= get_N();
		hash_name_en [QString::fromUtf8("force")]= get_N();

		hash_name_ru [QString::fromUtf8("давление")]= get_N()/get_m().pownm(2); //давление, механическое напряжение
		hash_name_en [QString::fromUtf8("pressure")]= get_N()/get_m().pownm(2); //pressure, stress

		hash_name_ru [QString::fromUtf8("работа")]=get_J(); //работа, энергия, количество теплоты
		hash_name_en [QString::fromUtf8("work")]=get_J(); //energy, work, quantity of heat

		hash_name_ru [QString::fromUtf8("мощность")]=get_W(); //
		hash_name_en [QString::fromUtf8("power")]=get_W(); //power, radiant flux

		hash_name_ru [QString::fromUtf8("электрический заряд")]=get_C(); //электрический заряд, количество электричества
		hash_name_en [QString::fromUtf8("electric charge")]=get_C(); //electric charge, quantity of electricity

		hash_name_ru [QString::fromUtf8("электрическое напряжение")]=get_V(); //электрическое напряжение, электродвижущая сила
		hash_name_en [QString::fromUtf8("electric potential difference")]=get_V();//electric potential difference, electromotive force

		hash_name_ru [QString::fromUtf8("электрическая ёмкость")]=get_F();
		hash_name_en [QString::fromUtf8("capacitance")]=get_F();

		hash_name_ru [QString::fromUtf8("электрическое сопротивление")]=get_Om();
		hash_name_en [QString::fromUtf8("electric resistance")]=get_Om();

		hash_name_ru [QString::fromUtf8("электрическая проводимость")]=get_S();
		hash_name_en [QString::fromUtf8("electric conductance")]=get_S();

		hash_name_ru [QString::fromUtf8("магнитный поток")]=get_Wb();
		hash_name_en [QString::fromUtf8("magnetic flux")]=get_Wb();

		hash_name_ru [QString::fromUtf8("магнитная индукция")]=get_T();
		hash_name_en [QString::fromUtf8("magnetic flux density")]=get_T();

		hash_name_ru [QString::fromUtf8("индуктивность")]=get_H();
		hash_name_en [QString::fromUtf8("inductance")]=get_H();

		//Celsius temperature
		hash_name_ru [QString::fromUtf8("световой поток")]=get_lm();
		hash_name_en [QString::fromUtf8("luminous flux")]=get_lm();

		hash_name_ru [QString::fromUtf8("освещенность")]=get_lx();
		hash_name_en [QString::fromUtf8("illuminance")]=get_lx();

		hash_name_ru [QString::fromUtf8("активность нуклида")]=get_Bq(); //активность нуклида в радиоактивном источнике
		hash_name_en [QString::fromUtf8("activity")]=get_Bq(); //activity (of a radionuclide)

		hash_name_ru [QString::fromUtf8("эквивалентная доза излучения")]=get_Sv(); //поглощенная доза излучения, керма, показатель поглощенной дозы, эквивалентная доза излучения
		hash_name_en [QString::fromUtf8("dose equivalent")]=get_Sv(); //absorbed dose, specific energy (imparted), kerma, dose equivalent

		hash_name_ru [QString::fromUtf8("поглощенная доза излучения")]=get_Gy();
		hash_name_en [QString::fromUtf8("absorbed dose")]=get_Gy();

		hash_name_en [QString::fromUtf8("catalytic activity")]=get_mol()/get_s();

		hash_name_ru [QString::fromUtf8("динамическая вязкость")]=get_Pa()*get_s();
		hash_name_en [QString::fromUtf8("dynamic viscosity")]=get_Pa()*get_s();

		hash_name_ru [QString::fromUtf8("кинематическая вязкость")]=get_m().pownm(2)/get_s();
		hash_name_en [QString::fromUtf8("кинематическая вязкость")]=get_m().pownm(2)/get_s();

		hash_name_ru [QString::fromUtf8("момент силы")]=get_N()*get_m();
		hash_name_en [QString::fromUtf8("moment of force")]=get_N()*get_m();

		hash_name_ru [QString::fromUtf8("поверхностное натяжение")]=get_N()/get_m();
		hash_name_en [QString::fromUtf8("surface tension")]=get_N()/get_m();

		hash_name_ru [QString::fromUtf8("угловая скорость")] = get_rad()/get_s();
		hash_name_en [QString::fromUtf8("angular velocity")] = get_rad()/get_s();

		hash_name_ru [QString::fromUtf8("угловое ускорение")]=get_rad()/get_s().pownm(2);
		hash_name_en [QString::fromUtf8("angular acceleration")]=get_rad()/get_s().pownm(2);


		hash_name_en [QString::fromUtf8("тепловой поток")]=get_W()/get_m().pownm(2);
		hash_name_en [QString::fromUtf8("heat flux density")]=get_W()/get_m().pownm(2);

		hash_name_ru [QString::fromUtf8("энторопия")]=get_J()/get_K();
		hash_name_en [QString::fromUtf8("entropy")]=get_J()/get_K();

		hash_name_ru [QString::fromUtf8("удельная теплоемкость")]=get_J()/(get_kg()*get_K());
		hash_name_en [QString::fromUtf8("specific heat capacity")]=get_J()/(get_kg()*get_K());

		hash_name_ru [QString::fromUtf8("теплота сгорания")]=get_J()/get_kg();
		hash_name_en [QString::fromUtf8("specific energy")]=get_J()/get_kg();

		hash_name_ru [QString::fromUtf8("теплопроводность")]=get_W()/(get_m()*get_K());
		hash_name_en [QString::fromUtf8("thermal conductivity")]=get_W()/(get_m()*get_K());

		hash_name_ru [QString::fromUtf8("плотноть энергии")]=get_J()/get_m().pownm(3);
		hash_name_en [QString::fromUtf8("energy density")]=get_J()/get_m().pownm(3);

		hash_name_ru [QString::fromUtf8("напряженность электрического поля")]=get_V()/get_m();
		hash_name_en [QString::fromUtf8("electric field strength")]=get_V()/get_m();


		hash_name_en [QString::fromUtf8("electric charge density")]= get_C()/get_m().pownm(3);
		hash_name_en [QString::fromUtf8("electric flux density")]= get_C()/get_m().pownm(2);
		hash_name_en [QString::fromUtf8("permittivity")]= get_F()/get_m();
		hash_name_en [QString::fromUtf8("permeability")]= get_H()/get_m();
		hash_name_en [QString::fromUtf8("molar energy")]= get_J()/get_mol();
		hash_name_en [QString::fromUtf8("molar entropy")]= get_J()/(get_mol()*get_K()); //molar entropy, molar heat capacity

		hash_name_en [QString::fromUtf8("exposure")]= get_C()/get_kg();
		hash_name_en [QString::fromUtf8("absorbed dose rate")]= get_Gy()/get_s();

		hash_name_ru [QString::fromUtf8("сила излучения")]=get_W()/get_sr();
		hash_name_en [QString::fromUtf8("radiant intensity")]=get_W()/get_sr();

		hash_name_en [QString::fromUtf8("radiance")]= get_W()/(get_m().pownm(2)*get_sr());
//		hash_name_en [QString::fromUtf8("catalytic concentration")]= get_kat()/get_m().pownm(3);


		hash_name_ru [QString::fromUtf8("импульс")]=get_kg()*get_m()/get_s();
		hash_name_ru [QString::fromUtf8("импульс силы ")]=get_N()*get_s();
		hash_name_ru [QString::fromUtf8("момент инерции")]=get_kg()*get_m().pownm(2);
		hash_name_ru [QString::fromUtf8("магнитодвижушая сила")]=get_A();
/********************************************************************************************************************/
		hash_name_en [QString::fromUtf8("mass flow rate")] = get_kg()/get_s();
		hash_name_ru [QString::fromUtf8("массовый расход")] = get_kg()/get_s();

		hash_name_en [QString::fromUtf8("volumetric flow")] = get_m().pownm(3)/get_s();
		hash_name_ru [QString::fromUtf8("объёмный расход")] = get_m().pownm(3)/get_s();

		hash_name_en [QString::fromUtf8("flow rate")] = get_mol()/get_s();
		hash_name_ru [QString::fromUtf8("молекулярный расход")] = get_mol()/get_s();
		
		hash_name_en [QString::fromUtf8("molar weight")] = get_kg()/get_mol();
		hash_name_ru [QString::fromUtf8("молекулярный вес")] = get_kg()/get_mol();
	}
	{
//		QHash<QString, nm_value> nm_value::hash_name_en ;
	}
	QHash<QString, double>::const_iterator i, i_e ;
	i = hash_Mnozitel_C_ru.constBegin() ;	i_e = hash_Mnozitel_C_ru.constEnd() ;
	while (i != i_e) { str_Mnozitel_C_ru+=i++.key(); if(i != i_e) str_Mnozitel_C_ru+=QString::fromUtf8("|"); }
		
	i = hash_Mnozitel_C_en.constBegin() ; i_e =hash_Mnozitel_C_en.constEnd() ;
	while (i != i_e) { str_Mnozitel_C_en+=i++.key(); if(i != i_e) str_Mnozitel_C_en+=QString::fromUtf8("|"); }
		
	
	QHash<QString, nm_value>::const_iterator j, j_e;
	j = hash_Ed_Osnovn_C_en.constBegin(); j_e = hash_Ed_Osnovn_C_en.constEnd();
	while (j != j_e) { str_Ed_Osnovn_C_en+=j++.key(); if(j != j_e) str_Ed_Osnovn_C_en+=QString::fromUtf8("|"); }
	
	j = hash_Ed_Osnovn_C_ru.constBegin(); j_e = hash_Ed_Osnovn_C_ru.constEnd() ;
	while (j != j_e) { str_Ed_Osnovn_C_ru+=j++.key(); if(j != j_e) str_Ed_Osnovn_C_ru+=QString::fromUtf8("|"); }
	
	j = hash_Ed_Proizvodn_C_en.constBegin(); j_e = hash_Ed_Proizvodn_C_en.constEnd() ;
	while (j != j_e) { str_Ed_Proizvodn_C_en+=j++.key(); if(j != j_e) str_Ed_Proizvodn_C_en+=QString::fromUtf8("|"); }
	
	j = hash_Ed_Proizvodn_C_ru.constBegin(); j_e = hash_Ed_Proizvodn_C_ru.constEnd() ;
	while (j != j_e){ str_Ed_Proizvodn_C_ru+=j++.key(); if(j != j_e) str_Ed_Proizvodn_C_ru+=QString::fromUtf8("|"); }

	j = hash_Ed_Not_C_en.constBegin(); j_e = hash_Ed_Not_C_en.constEnd();
	while (j != j_e) { str_Ed_Not_C_en+=j++.key(); if(j != j_e) str_Ed_Not_C_en+=QString::fromUtf8("|"); }
	
	j = hash_Ed_Not_C_ru.constBegin(); j_e = hash_Ed_Not_C_ru.constEnd() ;
	while (j != j_e) { str_Ed_Not_C_ru+=j++.key(); if(j != j_e) str_Ed_Not_C_ru+=QString::fromUtf8("|"); }
#ifdef debug_nm_value_cpp
	std_out << "bool nm_value::init_value()" <<endl;
	std_out << str_Mnozitel_C_ru << endl ;
	std_out << str_Mnozitel_C_en << endl ;
	std_out << str_Ed_Osnovn_C_en << endl;
	std_out << str_Ed_Osnovn_C_ru << endl;
	std_out << str_Ed_Proizvodn_C_en  << endl;
	std_out << str_Ed_Proizvodn_C_ru << endl;
	std_out << str_Ed_Not_C_en << endl;
	std_out << str_Ed_Not_C_ru  << endl;
#endif
	rx_value.setPattern ( "[\\+-]?\\d+\\.?\\d*([eE][\\+-]?\\d+)?" );
	
	rx_dim.setPattern ( "\\[[^\\[\\]]+\\]" );
	
	rx_digit.setPattern("\\d+");
	
	QString str_Mnozitel_C_en_ru = "(" + str_Mnozitel_C_en + "|" + str_Mnozitel_C_ru + ")";
	QString str_rx_Ed_O_P_C_en_ru =
	    "("
	    + str_Ed_Osnovn_C_en + "|" + str_Ed_Osnovn_C_ru + 
	    "|" + str_Ed_Proizvodn_C_en + "|" + str_Ed_Proizvodn_C_ru + 
	    "|" + str_Ed_Not_C_en + "|" + str_Ed_Not_C_ru + 
	    ")";
	rx_Ed_O_P_C_en_ru.setPattern(str_rx_Ed_O_P_C_en_ru);
#ifdef debug_nm_value_cpp	    
	std_out << "bool nm_value::init_value()" << endl;
	std_out << "str_rx_Ed_O_P_C_en_ru = "<< str_rx_Ed_O_P_C_en_ru << endl;
	std_out << "str_rx_koeff_Ed_O_P_C_en_ru = "<<	str_rx_koeff_Ed_O_P_C_en_ru  << endl;
	std_out << "str_rx_digit = "<<	str_rx_digit  << endl;
	for (int i = 0; i < lst.size(); ++i)
		std_out << lst.at(i) << endl;
#endif
	
	QString str_rx_koeff_Ed_O_P_C_en_ru = str_Mnozitel_C_en_ru + str_rx_Ed_O_P_C_en_ru;
	rx_koeff_Ed_O_P_C_en_ru.setPattern( str_rx_koeff_Ed_O_P_C_en_ru );
	return 0;
}

QString nm_value::toQString (QString const & dimension) const
{
	QString rez=""; QTextStream s_rez( &rez) ;
	QString dim_rez=""; QTextStream s_dim_rez( &dim_rez) ;
	QStringList lst;
	
	nm_value tmp = *this;
	lst=formQStringtoQStringList(dimension);
	nm_value::validate(lst);
	for (int i = 0; i < lst.size(); ++i) 
		s_dim_rez << lst.at(i) ;
	nm_value div_by = nm_value::formQStringtoRazmernost( dim_rez );
	if(is_same_type(div_by))
		s_rez << (tmp/div_by).val << "[" << dim_rez << "]";
	else
		s_rez << tmp.val << tmp.get_dimensions();
	return rez ;
}

///Осуществляет проверку списка лексем, представляющих размерность ЧсР.
/**Принимает список лексем составляющих размерность: "*", "/", "размертность" , "целое полож. число".
Убирает лишние ошибочные лексемы.*/
void nm_value::validate ( QStringList & lst )
{
	init_value();	
	QStringList lst_valid; //Проверенный список
	
	QString dimens="";
	QString operation="";
	QString number="";
	QString at;

	int pos;
	bool was_devide = false ;
	
	int i = 0 ;
	while ( i < lst.size() )
	{
		at = lst.at ( i );
		++i;
		if ( ( rx_koeff_Ed_O_P_C_en_ru.indexIn ( at ) ) != -1 ) 
			dimens=at;
		else if ( ( rx_Ed_O_P_C_en_ru.indexIn ( at ) ) != -1 ) 
			dimens=at;
		else if ( ( pos = rx_digit.indexIn ( at ) ) != -1 ) 
			number=at;
		else if ( at == "*" ) 
		{
			operation=at;
			{ 
				if(!dimens.isEmpty())
				{
					lst_valid<<dimens;
					if(!number.isEmpty())
						lst_valid<<number;
					if(!operation.isEmpty())
						lst_valid<<operation;
				}
				dimens.clear(); number.clear(); operation.clear();
			}
		}
		else if ( at == "/" ) 
		{	if(was_devide) operation="*";
			else { operation=at ; was_devide=true; }			
			{ 
				if(!dimens.isEmpty())
				{
					lst_valid<<dimens;
					if(!number.isEmpty())
						lst_valid<<number;
					if(!operation.isEmpty())
						lst_valid<<operation;
				}
				else if(dimens.isEmpty()&&operation=="/"&&number=="1")
				{
					lst_valid<<number;
					lst_valid<<operation;
				}
				dimens.clear(); number.clear(); operation.clear();
			}
		}
		else
		{ dimens.clear(); number.clear(); operation.clear() ; }			
	}
	{ 
		if(!dimens.isEmpty())
		{
			lst_valid<<dimens;
			if(!number.isEmpty())
				lst_valid<<number;
			if(!operation.isEmpty())
				lst_valid<<operation;
		}
		dimens.clear(); number.clear(); operation.clear();
	}
	if(lst_valid.last()=="*"||lst_valid.last()=="/")
		lst_valid.removeLast ();
	lst=lst_valid;
	return ;
}

//QString nm_value::ValueName () const
QString nm_value::get_dimension_name_ru() const
{
	QHashIterator<QString, nm_value> i(hash_name_ru);
	while (i.hasNext()) 
	{
		i.next();
		if(is_same_type(i.value()))
		return i.key();
	}
	return "undefined";
}

QString nm_value::get_dimension_name_en() const
{
	QHashIterator<QString, nm_value> i(hash_name_en);
	while (i.hasNext()) 
	{
		i.next();
		if(is_same_type(i.value()))
		return i.key();
	}
	return "undefined";
}
/*
	"Hz"	"Гц"	"1/s"					rez.set_dimensions ( 0 , 0 ,-1 , 0 , 0 , 0 , 0 , 0 , 0 );
	"N"		"Н"		"kg*m/s^2"				rez.set_dimensions ( 1 , 1 ,-2 , 0 , 0 , 0 , 0 , 0 , 0 );
	"Pa"	"Па"	"kg/" "(m*s^2)"			rez.set_dimensions (-1 , 1 ,-2 , 0 , 0 , 0 , 0 , 0 , 0 );
	"J"		"Дж"	"kg*m^2/s^2"			rez.set_dimensions ( 2 , 1 ,-2 , 0 , 0 , 0 , 0 , 0 , 0 );
	"W"		"Вт"	"kg*m^2/s^3"			rez.set_dimensions ( 2 , 1 ,-3 , 0 , 0 , 0 , 0 , 0 , 0 );
	"C"		"Кл"	"A*c"					rez.set_dimensions ( 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 );
	"V"		"В"		"kg*m^2/(A*s^3)"		rez.set_dimensions ( 2 , 1 ,-3 ,-1 , 0 , 0 , 0 , 0 , 0 );
	"Om"	"Ом"	"kg*m^2/(A^2*s^3)"		rez.set_dimensions ( 2 , 1 ,-3 ,-2 , 0 , 0 , 0 , 0 , 0 );
	"S"		"См"	"kg^-1*m^-2*A^2*s^3"	rez.set_dimensions (-2 ,-1 , 3 , 2 , 0 , 0 , 0 , 0 , 0 );
	"F"		"Ф"		"kg^-1*m^-2*A^2*s^4"	rez.set_dimensions (-2 ,-1 , 4 , 2 , 0 , 0 , 0 , 0 , 0 );
	"Wb"	"Вб"	"kg*m^2/(A*s^2)"		rez.set_dimensions ( 2 , 1 ,-2 ,-1 , 0 , 0 , 0 , 0 , 0 );
	"H"		"Гн"	"kg*m^2/(A^2*s^2)"		rez.set_dimensions ( 2 , 1 ,-2 , 0 ,-2 , 0 , 0 , 0 , 0 );
	"T"		"Тл"	"kg/(A*s^2)"			rez.set_dimensions ( 0 , 1 ,-2 ,-1 , 0 , 0 , 0 , 0 , 0 );
	"lm"	"лм"	"cd*sr"					rez.set_dimensions ( 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 1 );
	"lx"	"лк"	"cd*sr/m^2"				rez.set_dimensions (-2 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 1 );
	"Bq"	"Бк"	"1/s"					rez.set_dimensions ( 0 , 0 ,-1 , 0 , 0 , 0 , 0 , 0 , 0 );
	"Gy"	"Гр"	"m^2/s^2"				rez.set_dimensions ( 2 , 0 ,-2 , 0 , 0 , 0 , 0 , 0 , 0 );
	"Sv"	"Зв"	"m^2/s^2"				rez.set_dimensions ( 2 , 0 ,-2 , 0 , 0 , 0 , 0 , 0 , 0 );
*/

///Выводит строку с множителями для образования кратных единиц (английской язык).
void nm_value::print_Monzitel(QTextStream & out)
{
	init_value();
	out<<str_Mnozitel_C_en;	
}

///Выводит строку с множителями для образования кратных единиц (русский язык).
void nm_value::print_Monzitel_nativ(QTextStream & out)
{
	init_value();
	out<<str_Mnozitel_C_ru;	
}

///Выводит строку с обозначениями основных единиц системы Си (английской язык).
void nm_value::print_Ed_C(QTextStream & out)
{
	init_value();
	out<<str_Ed_Osnovn_C_en;
}

///Выводит строку с обозначениями основных единиц системы Си (русский язык).
void nm_value::print_Ed_C_nativ(QTextStream & out)
{
	init_value();
	out<<str_Ed_Osnovn_C_ru;
}

///Выводит строку с обозначениями производных единиц системы Си, имеющих самостоятельные названия (английской язык).
void nm_value::print_Ed_C_Proizvodn(QTextStream & out)
{
	init_value();
	out<<str_Ed_Proizvodn_C_en;
}

///Выводит строку с обозначениями производных единиц системы Си, имеющих самостоятельные названия (русский язык).
void nm_value::print_Ed_C_Proizvodn_nativ(QTextStream & out)
{
	init_value();
	out<<str_Ed_Proizvodn_C_ru;
}

///Выводит строку с обозначениями внесистемных единиц (английский язык).
void nm_value::print_Ed_NON_C(QTextStream & out)
{
	init_value();
	out<<str_Ed_Not_C_en;
}

///Выводит строку с обозначениями внесистемных единиц (русский язык).
void nm_value::print_Ed_NON_C_native(QTextStream & out)
{
	init_value();
	out<<str_Ed_Not_C_ru;
}

nm_value nm_value::get_dimension_ru(QString const & name_ru) 
{
	nm_value tmp = nm_value::hash_name_ru[name_ru];
	return tmp;
}

nm_value nm_value::get_dimension_en(QString const & name_en) 
{
	nm_value tmp = nm_value::hash_name_en[name_en];
	return tmp;
}

double nm_value::toDouble( )
{
	return val;
}
