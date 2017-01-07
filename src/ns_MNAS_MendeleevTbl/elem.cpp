#include "elem.h"

namespace ns_MNAS_MendeleevTbl
{
	elem::elem()
	{}

	elem::~elem()
	{}
	//********************************************************************************
	H::H(): elem()
	{
		n_pp=1;
		Oboznachenie="H";
		Naimenovanie="Водород";
		ro=0.08988;
		molekul_mass=1.007825;
		e_otr=2.100;
		t_plavlenija=-259.190;
		t_kipenija=-252.870;
	}

	H::~H()
	{}

	elem * H::Build_Copy(void)const
	{
		elem * p = new H;
		return p;
	}

	//********************************************************************************
	He::He(): elem()
	{
		n_pp =2;
		Oboznachenie="He";
		Naimenovanie="Гелий";
		ro=0.17847;
		molekul_mass=4.002602;
		e_otr=5.500;
		t_plavlenija=-271.15;
		t_kipenija=-268.935;
	}

	He::~ He()
	{}

	elem * He::Build_Copy(void)const
	{
		elem * p = new He;
		return p;
	}

	//********************************************************************************

	Li::Li(): elem()
	{
		n_pp =3;
		Oboznachenie="Li";
		Naimenovanie="Литий";
		ro=534.0;
		molekul_mass=6.941;
		e_otr=0.97000;
		t_plavlenija=180.5;
		t_kipenija=1336.6;
	}

	Li::~Li()
	{}
	elem * Li::Build_Copy(void)const
	{
		elem * p = new Li;
		return p;
	}

	//********************************************************************************
	Be::Be(): elem()
	{
		n_pp =4;
		Oboznachenie="Be";
		Naimenovanie="Бериллий";
		ro=1850.000;
		molekul_mass=9.012;
		e_otr=1.47;
		t_plavlenija=1287.0;
		t_kipenija=2471.0;
	}

	Be::~Be()
	{}

	elem * Be::Build_Copy(void)const
	{
		elem * p = new Be;
		return p;
	}
	//********************************************************************************
	B::B()
	{
		n_pp =5;
		Oboznachenie="B";
		Naimenovanie="Бор";
		ro=2340.0;
		molekul_mass=10.811;
		e_otr=2.01;
		t_plavlenija=2075.0;
		t_kipenija=3700.0;

	}

	B::~B()
	{}

	elem * B::Build_Copy(void)const
	{
		elem * p = new B;
		return p;
	}

	//********************************************************************************
	C::C()
	{
		n_pp =6;
		Oboznachenie="C";
		Naimenovanie="Углерод";
		ro=2270;
		molekul_mass=12.011;
		e_otr=2.500;
		t_plavlenija=4000;
		t_kipenija=4200;
	}

	C::~C()
	{}

	elem * C::Build_Copy(void)const
	{
		elem * p = new C;
		return p;
	}

	//********************************************************************************
	N::N()
	{
		n_pp =7;
		Oboznachenie="N";
		Naimenovanie="Азот";
		ro=1.25056;
		molekul_mass=14.0067;
		e_otr=3.070;
		t_plavlenija=-210.0;
		t_kipenija=-195.802;
	}

	N::~N(){}

	elem * N::Build_Copy(void)const
	{
		elem * p = new N;
		return p;
	}

	//********************************************************************************
	O::O()
	{
		n_pp =8;
		Oboznachenie="O";
		Naimenovanie="Кислород";
		ro=1.42895;
		molekul_mass=15.9994;
		e_otr=3.500;
		t_plavlenija=-218.7;
		t_kipenija=-182.962;
	}
	O::~O(){}

	elem * O::Build_Copy(void)const
	{
		elem * p = new O;
		return p;
	}

	//********************************************************************************
	F::F()
	{
		n_pp =9;
		Oboznachenie="F";
		Naimenovanie="Фтор";
		ro=1.696;
		molekul_mass=18.998404;
		e_otr=4.100;
		t_plavlenija=-219.699;
		t_kipenija=-188.200;
	}

	F::~F()
	{}

	elem * F::Build_Copy(void)const
	{
		elem * p = new F;
		return p;
	}

	//********************************************************************************
	Ne::Ne()
	{
		n_pp =10;
		Oboznachenie="Ne";
		Naimenovanie="Неон";
		ro=0.900350;
		molekul_mass=20.1797;
		e_otr=4.84;
		t_plavlenija=-248.6;
		t_kipenija=-246.048;
	}

	Ne::~Ne()
	{}

	elem * Ne::Build_Copy(void)const
	{
		elem * p = new Ne;
		return p;
	}

	//********************************************************************************
	Na::Na()
	{
		n_pp =11;
		Oboznachenie="Na";
		Naimenovanie="Натрий";
		ro=968.0;
		molekul_mass=22.98977;
		e_otr=0.93;
		t_plavlenija=97.83;
		t_kipenija=886.0;
	}
	Na::~Na(){}

	elem * Na::Build_Copy(void)const
	{
		elem * p = new Na;
		return p;
	}
	//********************************************************************************
	Mg::Mg()
	{
		n_pp =12;
		Oboznachenie="Na";
		Naimenovanie="Магний";
		ro=1737.0;
		molekul_mass=24.305;
		e_otr=1.230;
		t_plavlenija=648.0;
		t_kipenija=1095.0;
	}

	Mg::~Mg()
	{}

	elem * Mg::Build_Copy(void)const
	{
		elem * p = new Mg;
		return p;
	}
	//********************************************************************************
	Al::Al()
	{
		n_pp =13;
		Oboznachenie="Al";
		Naimenovanie="Алюминий";
		ro=2702.0;
		molekul_mass=26.98154;
		e_otr=1.470;
		t_plavlenija=660.37;
		t_kipenija=2500.0;
	}

	Al::~Al()
	{}

	elem * Al::Build_Copy(void)const
	{
		elem * p = new Al;
		return p;
	}

	//********************************************************************************
	Si::Si()
	{
		n_pp =14;
		Oboznachenie="Si";
		Naimenovanie="Кремний";
		ro=2330.0;
		molekul_mass=28.0855;
		e_otr=2.250;
		t_plavlenija=1415.0;
		t_kipenija=3250.0;
	}

	Si::~Si()
	{}

	elem * Si::Build_Copy(void)const
	{
		elem * p = new Si;
		return p;
	}

	//********************************************************************************
	P::P()
	{
		n_pp =15;
		Oboznachenie="P";
		Naimenovanie="Фосфор";
		ro=1820.0; //(белый)
		ro=2340.0;//(красный)
		molekul_mass=30.97376;
		e_otr=2.32;
		t_plavlenija=593.0;//(красный)
		t_plavlenija=44.14;//(белый)
		t_kipenija=287.3;//(белый)
	}

	P::~P()
	{}

	elem * P::Build_Copy(void)const
	{
		elem * p = new P;
		return p;
	}
	//********************************************************************************
	S::S()
	{
		n_pp =16;
		Oboznachenie="S";
		Naimenovanie="Сера";
		ro=2070.0;//(a)
		ro=1960.0;//(b);
		molekul_mass=32.066;
		e_otr=2.60;
		t_plavlenija=119.3;
		t_kipenija=444.674;
	}

	S::~S()
	{}

	elem * S::Build_Copy(void)const
	{
		elem * p = new S;
		return p;
	}
	//********************************************************************************
	Cl::Cl()
	{
		n_pp =17;
		Oboznachenie="Cl";
		Naimenovanie="Хлор";
		ro=3.214;
		molekul_mass=35.4527;
		e_otr=2.83;
		t_plavlenija=-101.03;
		t_kipenija=-34.1;
	}

	Cl::~Cl()
	{}

	elem * Cl::Build_Copy(void)const
	{
		elem * p = new Cl;
		return p;
	}

	//********************************************************************************
	Ar::Ar()
	{
		n_pp =18;
		Oboznachenie="Ar";
		Naimenovanie="Аргон";
		ro=1.7837;
		molekul_mass=39.48;
		e_otr=3.20;
		t_plavlenija=-189.34;
		t_kipenija=-185.86;
	}

	Ar::~Ar()
	{}

	elem * Ar::Build_Copy(void)const
	{
		elem * p = new Ar;
		return p;
	}

	//********************************************************************************
	K::K()
	{
		n_pp =19;
		Oboznachenie="K";
		Naimenovanie="Калий";
		ro=862.9;
		molekul_mass=39.0983;
		e_otr=0.91;
		t_plavlenija=63.51;
		t_kipenija=760.0;
	}

	K::~K()
	{}

	elem * K::Build_Copy(void)const
	{
		elem * p = new K;
		return p;
	}

	//********************************************************************************
	Ca::Ca()
	{
		n_pp =20;
		Oboznachenie="Ca";
		Naimenovanie="Кальций";
		ro=1540.0;
		molekul_mass=40.078;
		e_otr=1.04;
		t_plavlenija=842.0;
		t_kipenija=1495.0;
	}

	Ca::~Ca()
	{}

	elem * Ca::Build_Copy(void)const
	{
		elem * p = new Ca;
		return p;
	}

};


