/********************************************************************************************************
 *
 * PROGRAM      : temp_qmake_qregexp
 * DATE - TIME  : понедельник 28 мая 2007 - 10h51
 * AUTHOR       :  matveev ( matveev@mksat.net )
 * FILENAME     : nm_value.h
 * LICENSE      : GPL
 * COMMENTARY   : 
 ********************************************************************************************************/
#ifndef NM_VALUE_H
#define NM_VALUE_H

#include "mnasoft_lib_global.h"

#include <QString>
#include <QTextStream>
#include <QHash>

///Число с размерностью (ЧсР).
/**
Класс ЧсР представляет число определенной размерности.\n
ЧсР представляется в виде совокупности вещественного значения (мантиссы) и 9-ти целых чисел,
определяющих степени, в которых находятся размерности данного числа.
Размерностями ЧсР являются:\n
1) метр    - [m];\n    2) килограмм - [kg];\n    3) секунда - [s];\n
4) ампер   - [A];\n    5) кельвин   - [K];\n     6) кандела - [cd];\n    7) моль - [mol];\n
8) радиан  - [rad];\n  9) стерадиан - [sr].\n
Класс определяет следующие операции над чисами с размерностью:\n
- арифметические операции (сложение, вычитание, умножение, деление, унарные плюс и минус);\n
- операци сравнения;\n
- возведение в целую степень.\n
*/

class MNASOFT_EXPORT nm_value
{
public:    
    
    double val;     ///Мантисса ЧсР.
    int m;          ///<Степень размерности [метр].
    int kg;         ///<Степень размерности [килограмм].
    int s;          ///<Степень размерности [секунда].
    int A;          ///<Степень размерности [ампер].
    int K;          ///<Степень размерности [кельвин].
    int cd;         ///<Степень размерности [кандела].
    int mol;        ///<Степень размерности [моль].
    int rad;        ///<Степень размерности [радиан].
    int sr;         ///<Степень размерности [стерадиан].
/*********************************************************************************************************************/
    nm_value();     ///<Конструктор по умолчанию. Создает безразмерное ЧсР мантисса которого равна нулю.

    nm_value 
    (
        double a_val     /** - мантисса числа;*/,
        int    a_m   = 0 /** - степень размерности [метр];*/,
        int    a_kg  = 0 /** - степень размерности [килограмм];*/,
        int    a_s   = 0 /** - степень размерности [секунда];*/,
        int    a_A   = 0 /** - степень размерности [ампер];*/,
        int    a_K   = 0 /** - степень размерности [кельвин];*/,
        int    a_cd  = 0 /** - степень размерности [кандела];*/,
        int    a_mol = 0 /** - степень размерности [моль];*/,
        int    a_rad = 0 /** - степень размерности [радиан];*/,
        int    a_sr  = 0 /** - степень размерности [стерадиан].*/ 
    );        ///<Конструктор.
    /**<Создает ЧсР с мантиссой равной a_val у которого все размерные степени равны соответствующим степеням целых чисел. */

    nm_value 
    (
        double a_val                  /** - мантисса числа;*/,
        QString const & dimension     /** - символьное представление размерности. */ 
    );        ///<Конструктор.
    /**<Создает ЧсР со значением равным a_val и размерностью, определяемой параметром a_string.\n
    Формат параметра a_string см. подробнее в описании функции set_dimensions(const QString &).
    Например:
    \code
    nm_value p (1.0, "MPa"); // p.val=1000000.;
    nm_value ro (0.835, "g/cm3"); // p.val=835.0;
    \endcode
    */
    
    nm_value (QString const & a_string);    ///<Конструктор.
    /**<Создает ЧсР исходя из его строкового представления.\n
    Например:
    \code
    nm_value g("9.81[m/s2]");
    nm_value fric("50[1/s]");
    \endcode
    */

    nm_value ( nm_value const & a_val );///<Конструктор копирования.
/*********************************************************************************************************************/
    ~nm_value();///<Деструктор
/*********************************************************************************************************************/
    nm_value & operator = ( nm_value const & a_val );///<Оператор присваивания.
    /**
    Например:
    \code
    nm_value a(1.0,2);
    nm_value b;
    b=a; //b="1.0[m2]"
    \endcode
    */

    nm_value operator * ( nm_value const & second ) const;///<Операция умножения.
    nm_value operator / ( nm_value const & second ) const;///<Операция деления.
    nm_value operator + ( nm_value const & second ) const;///<Операция сложения. Бинарный плюс.
    nm_value operator - ( nm_value const & second ) const;///<Операция вычитания. Бинарный минус.
    nm_value operator + () const;///<Унарный плюс.
    nm_value operator - () const;///<Унарный минус.
    
    double toDouble( ); 
/*********************************************************************************************************************/
    bool operator == ( const nm_value & second ) const;///<Проверка на равенство двух ЧсР.
    bool operator != ( const nm_value & second ) const;///<Проверка на неравенство двух ЧсР.
    
    bool operator > ( const nm_value & second ) const;///<Сравнение >.
    bool operator < ( const nm_value & second ) const;///<Сравнение <.
    
    bool operator >= ( const nm_value & second ) const;///<Сравнение >=.
    bool operator <= ( const nm_value & second ) const;///<Сравнение <=.
    
/*********************************************************************************************************************/
    nm_value & set
    (
        double a_val /** - мантисса числа;*/,
        int a_m = 0 /** - степень размерности [метр];*/,
        int a_kg = 0 /** - степень размерности [килограмм];*/,
        int a_s = 0 /** - степень размерности [секунда];*/,
        int a_A = 0 /** - степень размерности [ампер];*/,
        int a_K = 0 /** - степень размерности [кельвин];*/,
        int a_cd = 0 /** - степень размерности [кандела];*/,
        int a_mol = 0 /** - степень размерности [моль];*/,
        int a_rad = 0 /** - степень размерности [радиан];*/,
        int a_sr = 0 /** - степень размерности [стерадиан].*/ 
    );

    nm_value & set
    (
        double a_val    /** - мантисса числа;*/,    
        QString const & dimension /** - символьное представление размерности. */
    );        ///<Устанавливает значение ЧсР.
    /**<Символьное представление размерности - строка представляющая размерность.\n
    Например: 
    \code
    nm_value tmp;
    tmp.set(10, "km");        // "10000[m]"
    tmp.set(10, "[km]");        // "10000[m]"
    tmp.set(0.835, "g/cm3");    // "835[kg/m3]"
    tmp.set(835, "[kg/m3]");    // "835[kg/m3]"
    tmp.set(25, "[m/kg*cm]");    // "2500[1/кг]"
    tmp.set(25, "[1/Mg]");        
    tmp.set(25, "ms");        // "0.025[s]"
    tmp.set(25, "1");        // "25" - отвлеченное число
    \endcode
    */

    nm_value & set( QString const & a_string );///<Устанавливает значение ЧсР по его строковому представлению.
    /**<
    Строковое представление может быть представлено следующем виде:\n
    \code
    nm_value a;
    a.set("1.0e0[kg]");    // "1[kg]"
    a.set("2.0e1[1/m2]");    // "20[1/m2]"
    a.set("3.0[1]");    // "3[1]" - отвлененное (безразмерное) число.
    a.set("3.0[1/MPa]");
    a.set("3.0[cm]");    // "0.03[m]"
    \endcode
    */

    nm_value & set( nm_value const & a_val );///<Устанавливает значение ЧсР.
    /**<Производится копирование всех полей a_val в соответствующие поля *this.*/
/*********************************************************************************************************************/
    nm_value pownm ( const int n /**показатель степени*/) const; ///<Возведение ЧсР в степень.
    /**<Возводит ЧСР в целочисленную степень n.
    \code
    nm_value a = nm_value::get_m();
    nm_value b;
    b = a.pownm(3); // b="1[m3]"
    \endcode
    */
    nm_value pownm2 ( const int n /**показатель степени*/, const int m ) const; ///<Возведение ЧсР в степень.
    nm_value pown ( const double n /**показатель степени*/) const; ///<Возведение ЧсР в степень.

    bool is_same_type ( const nm_value & second ) const;///<Проверка на равенство размерностей двух ЧсР.
    /**<Проверяет являются-ли значения this и second значениями одного и того же типа.*/

    bool is_good() const    { return good;}    ///<Возвращает статус того, произошла-ли ошибка в процессе вычислений.
/*********************************************************************************************************************/
    void set_dimensions 
    (
        int a_m = 0,    /**- степень размерности [метр];*/
        int a_kg = 0,    /**- степень размерности [килограмм];*/
        int a_s = 0,    /**- степень размерности [секунда];*/
        int a_A = 0,    /**- степень размерности [ампер];*/
        int a_K = 0,    /**- степень размерности [кельвин];*/
        int a_cd = 0,    /**- степень размерности [кандела];*/
        int a_mol = 0,    /**- степень размерности [моль];*/
        int a_rad = 0,    /**- степень размерности [радиан];*/
        int a_sr = 0    /**- степень размерности [стерадиан].*/
    );
    ///<Устанавливает размерность ЧсР.
    /**<Устанавливает степени размерностей ЧсР.\n
    Мантисса при этом не изменяется.*/

    void set_dimensions ( const nm_value & a_val );///<Устанавливает размерность ЧсР.
    /**Размерность становится такой-же как и у числа a_val. Мантисса при этом не изменяется.*/

    void set_dimensions 
    ( 
        const QString & Dimension /** - определяет символьное значение размерности.*/
    );///<Устанавливает размерность ЧсР.
    /**<Размерность устанавливается в соответствии со строкой Dimension. \n
    Формат строки должен быль одним из следующих: \n
    a) "[множитель]размерность[n][*[множитель]размерность[n]]...[/[множитель]размерность[n]][*[множитель]размерность[n]]" ;\n
    b) "1/[множитель]размерность[n][*[множитель]размерность[n]]";\n
    где :\n
    1. Размерность - строковое обозначение размерности международное или национальное. Поддерживаются следующие размерности:\n
        1.1 Основные единицы системы SI ():\n    1.1.1 "m" = "м" - метр;\n
        1.1.2 "kg" = "кг" - килограмм;\n    1.1.3 "s" = с" - секунда;\n
        1.1.4 "A" = "А" - ампер;\n        1.1.5 "K" = "К"  - кельвин;\n
        1.1.6 "cd" = "кд" - кандела;\n        1.1.7 "mol" = "моль" - моль;\n
        1.1.8 "rad" = "рад" - радиан;\n        1.1.9 "sr" = "ср" - стерадиан.\n
        1.2 Размерности системы SI, имеющие самостоятельные наименования;\n
        1.2.1 "Hz" - hertz;\n            1.2.2 "N" - newton;\n
        1.2.3 "Pa" - pascal;\n            1.2.4 "J" - joule;\n
        1.2.5 "W" - watt;\n            1.2.6 "C" - coulomb;\n
        1.2.7 "V" - volt;\n            1.2.8 "F" - farad;\n
        1.2.9 "Ω" - ohm;\n            1.2.10 "S" - siemens;\n
        1.2.11 "Wb" - weber;\n            1.2.12 "T" - tesla;\n
        1.2.13 "H" - henry;\n            1.2.14 "lm" - lumen;\n
        1.2.15 "lx" - lux;\n            1.2.16 "Bq" - becquerel;\n
        1.2.17 "Gy" - gray;\n            1.2.18 "Sv" - sievert;\n
        1.2.19 "kat" - katal.\n            1.3 Некоторые внесистемные единицы.\n
    2. n - целое положительное число, определяющее степень в которой находится соответствующая единица размерности;\n
    3. Множитель - одна из приставок, служащая для образования кратных и дольных единиц:\n
        3.1 "Y"=1e24;\n        3.2 "Z"=1e21;\n        3.3 "E"=1e18;\n        3.4 "P"=1e15;\n        3.5 "T"=1e12;\n
        3.6 "G"=1e9;\n        3.7 "M"=1e6;\n        3.8 "k"=1e3;\n        3.9 "h"=1e2;\n        3.10 "da"=1e1;\n
        3.11 "d"=1e-1;\n    3.12 "c"=1e-2;\n    3.13 "m"=1e-3;\n    3.14 "μ"=1e-6;\n    3.15 "n"=1e-9;\n
        3.16 "p"=1e-12;\n    3.17 "f"=1e-15;\n    3.18 "a"=1e-18.\n 
    4. "*" - знаки перемножения размерностей;\n
    5. "/" - знак разделяющий строку на числитель и знаменатель, должно быть не более одного знака / в формате строки.*/
/*********************************************************************************************************************/
    QString get_dimensions () const; ///<Возвращает строку с символьным представлением размерности ЧСР в системе Си.
    /**Причем строка представляющая размерность заключается в квадратные скобки.
    Например:
    \code
        // "[1]" - в случае безразмерной величины;
        // "[m]" - [метр]
        // "[Hz]" - [герц]
    \endcode
    */

    QString toQString (QString const & dimension /** - символьное представление размерности. */) const;
    ///<Возвращает символьное представление ЧСР.
    /**<Возвращает строку с символьным представлением ЧСР в размерности dimension или системе SI,\n
    если в указываемой размерности ЧСР представить не удалось.*/

    QString get_dimension_name_ru() const;///<Возвращает наименование размерности величины на ru языке.
    QString get_dimension_name_en() const;///<Возвращает наименование размерности величины на en языке.

/*********************************************************************************************************************/
    MNASOFT_EXPORT friend    QTextStream & operator<< (QTextStream & os, nm_value& a_val ); ///<Вывод числа с размерностью в поток.
    friend    QTextStream & operator>> (QTextStream & is, nm_value& a_val ); ///<Чтение числа с размерностью из потока.
/*********************************************************************************************************************/
    static nm_value fromQString ( QString const & str ); ///<Построение ЧСР по символьному представлению.
/*********************************************************************************************************************/
public:

    static nm_value  get_dimension_ru(QString const & name) ; ///<В
    static nm_value  get_dimension_en(QString const & name) ; ///<

    ///Возвращает число равное 1[m].
    static nm_value get_m() {nm_value rez ( 1.0 ); rez.set_dimensions ( 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[kg].
    static nm_value get_kg() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[s].
    static nm_value get_s() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[A].
    static nm_value get_A() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[K].
    static nm_value get_K() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[cd].
    static nm_value get_cd() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[mol].
    static nm_value get_mol() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[rad].
    static nm_value get_rad() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 ); return rez;}
    ///Возвращает число равное 1[sr].
    static nm_value get_sr() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 ); return rez;}

    ///Возвращает число равное 1[Hz].
    static nm_value get_Hz() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , -1 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[N].
    static nm_value get_N() {nm_value rez ( 1.0 ); rez.set_dimensions ( 1 , 1 , -2 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[Pa].
    static nm_value get_Pa() {nm_value rez ( 1.0 ); rez.set_dimensions ( -1 , 1 , -2 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[J].
    static nm_value get_J() {nm_value rez ( 1.0 ); rez.set_dimensions ( 2 , 1 , -2 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[W].
    static nm_value get_W() {nm_value rez ( 1.0 ); rez.set_dimensions ( 2 , 1 , -3 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[C].
    static nm_value get_C() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , 1 , 1 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[V].
    static nm_value get_V() {nm_value rez ( 1.0 ); rez.set_dimensions ( 2 , 1 , -3 , -1 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[Om].
    static nm_value get_Om() {nm_value rez ( 1.0 ); rez.set_dimensions ( 2 , 1 , -3 , -2 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[S].
    static nm_value get_S() {nm_value rez ( 1.0 ); rez.set_dimensions ( -2 , -1 , 3 , 2 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[F].
    static nm_value get_F() {nm_value rez ( 1.0 ); rez.set_dimensions ( -2 , -1 , 4 , 2 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[Wb].
    static nm_value get_Wb() {nm_value rez ( 1.0 ); rez.set_dimensions ( 2 , 1 , -2 , -1 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[H].
    static nm_value get_H() {nm_value rez ( 1.0 ); rez.set_dimensions ( 2 , 1 , -2 , 0 , -2 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[T].
    static nm_value get_T() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 1 , -2 , -1 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[lm].
    static nm_value get_lm() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 1 ); return rez;}
    ///Возвращает число равное 1[lx].
    static nm_value get_lx() {nm_value rez ( 1.0 ); rez.set_dimensions ( -2 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 1 ); return rez;}
    ///Возвращает число равное 1[Bq].
    static nm_value get_Bq() {nm_value rez ( 1.0 ); rez.set_dimensions ( 0 , 0 , -1 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[Gy].
    static nm_value get_Gy() {nm_value rez ( 1.0 ); rez.set_dimensions ( 2 , 0 , -2 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    ///Возвращает число равное 1[Sv].
    static nm_value get_Sv() {nm_value rez ( 1.0 ); rez.set_dimensions ( 2 , 0 , -2 , 0 , 0 , 0 , 0 , 0 , 0 ); return rez;}
    
    static void print_Monzitel(QTextStream & out);
    static void print_Monzitel_nativ(QTextStream & out);
    static void print_Ed_C(QTextStream & out);
    static void print_Ed_C_nativ(QTextStream & out);
    static void print_Ed_C_Proizvodn(QTextStream & out);
    static void print_Ed_C_Proizvodn_nativ(QTextStream & out);
    static void print_Ed_NON_C(QTextStream & out);
    static void print_Ed_NON_C_native(QTextStream & out);

protected:
    
    static    bool good ;    ///<Признак того, произошла-ли ошибка в процессе арифметических вычислений.
    /**<good=true - ошибки не было. \n good=false - произошла ошибка.*/
private:
    static QHash<QString, double> hash_Mnozitel_C_en;
    static QHash<QString, double> hash_Mnozitel_C_ru;
    
    static QHash<QString, nm_value> hash_Ed_Osnovn_C_en;
    static QHash<QString, nm_value> hash_Ed_Osnovn_C_ru;
    
    static QHash<QString, nm_value> hash_Ed_Proizvodn_C_en ;
    static QHash<QString, nm_value> hash_Ed_Proizvodn_C_ru ;

    static QHash<QString, nm_value> hash_Ed_Not_C_en ;
    static QHash<QString, nm_value> hash_Ed_Not_C_ru ;

    static bool    is_inited;
    static bool    init_value();

    static    QString str_Mnozitel_C_en;
    static    QString str_Mnozitel_C_ru;

    static    QString str_Ed_Osnovn_C_en;
    static    QString str_Ed_Osnovn_C_ru;

    static    QString str_Ed_Proizvodn_C_en;
    static    QString str_Ed_Proizvodn_C_ru;

    static    QString str_Ed_Not_C_en;
    static     QString str_Ed_Not_C_ru;

    static QHash<QString, nm_value> hash_name_ru ; ///<Хештаблица содержит наменования единиц (русский язык).
    static QHash<QString, nm_value> hash_name_en ; ///<Хештаблица содержит наменования единиц (английский язык).

private:
    static nm_value formQStringtoRazmernost ( QString const & str_dim ); ///<Разбор размерности ЧСР.
    /**
    Принимает на разбор строку размерности.\n
    Выполняет разделение строки на лексемы и вызывает fromQStringList() для их дальнейшего анализа.\n
    Например: при разборе символьного представления ЧСР str="10.[kPa*m/s2*kkal]" 
    функция примет на разбор str_dim = "[kPa*m/s2*kkal]";\n
    при str = "10[mm_Hg*kkal]" - str_dim = [mm_Hg*kkal].
    */

    static nm_value    fromQStringList ( QStringList  & lst );
    static double    formQStringtoMnozitel ( QString const & str );

    static nm_value    formSingleQStringtoRazmernost ( QString const & str );
    static QStringList formQStringtoQStringList ( const QString & str_dim );

    static void validate ( QStringList & str_lst );    
    
    static QRegExp rx_digit;
    static QRegExp rx_Ed_O_P_C_en_ru;
    static QRegExp rx_koeff_Ed_O_P_C_en_ru;
};

#endif //NM_VALUE_H
