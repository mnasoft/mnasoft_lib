///@author Матвеев Николай

#ifndef ELEM_H
#define ELEM_H

#include <string>
using namespace std;

namespace ns_MNAS_MendeleevTbl
{
	class MNASOFT_EXPORT elem
	{
	protected:
		elem();
		virtual	~elem();
	public:
		///Порядковый номер или заряд ядра.
		int n_pp;

		///Обозначение международное.
		string Oboznachenie;

		///Наименование русское.
		string Naimenovanie;

		///Плотность в нормальных условиях.
		double ro;

		///Молекулярная масса, кг/моль.
		double molekul_mass;

		///Температура плавления. Град. Цельсия.
		double t_plavlenija;

		///Температура кипения.  Град. Цельсия.
		double t_kipenija;

		///Электроотрицательность.
		double e_otr;

		///
		virtual elem * Build_Copy(void)const=0;
	};

///Элемент таблицы Менделеева - H  (водород).
	class H : public elem
	{
	public:
		H();
		~H();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - He  (гелий).
	class He : public elem
	{
	public:
		He();
		~He();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Li  (литий).
	class Li : public elem
	{
	public:
		Li();
		~Li();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Be  (бериллий).
	class Be : public elem
	{
	public:
		Be();
		~Be();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - B  (бор).
	class B : public elem
	{
	public:
		B();
		~B();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - C  (углерод).
	class C : public elem
	{
	public:
		C();
		~C();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - N  (азот).
	class N : public elem
	{
	public:
		N();
		~N();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - O  (кислород).
	class O : public elem
	{
	public:
		O();
		~O();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - F  (фтор).
	class F : public elem
	{
	public:
		F();
		~F();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Ne  (неон).
	class Ne : public elem
	{
	public:
		Ne();
		~Ne();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Na  (натрий).
	class Na : public elem
	{
	public:
		Na();
		~Na();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Mg  (магний).
	class Mg : public elem
	{
	public:
		Mg();
		~Mg();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Al  (алюминий).
	class Al : public elem
	{
	public:
		Al();
		~Al();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Si  (кремний).
	class Si : public elem
	{
	public:
		Si();
		~Si();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - P  (фосфор).
	class P : public elem
	{
	public:
		P();
		~P();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - S  (сера).
	class S : public elem
	{
	public:
		S();
		~S();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Cl  (хлор).
	class Cl : public elem
	{
	public:
		Cl();
		~Cl();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Ar  (аргон).
	class Ar : public elem
	{
	public:
		Ar();
		~Ar();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - K  (калий).
	class K : public elem
	{
	public:
		K();
		~K();
		elem * Build_Copy(void)const;
	};
///Элемент таблицы Менделеева - Ca  (кальций).
	class Ca : public elem
	{
	public:
		Ca();
		~Ca();
		elem * Build_Copy(void)const;
	};
};

#endif //ELEM_H
