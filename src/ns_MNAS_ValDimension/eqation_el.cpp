#include "eqation_el.h"

eqation_el::eqation_el()
{
}

eqation_el::eqation_el(int aType, int aLevel, QString aEl_str)
{
	lexem_type=aType;
	lexem_level=aLevel;
	el_str=aEl_str;
	nm_val=0.0;
}


eqation_el::~eqation_el()
{
}

std::ostream & operator <<( std::ostream & os , eqation_el const & el)
{
	os
			<<"el.lexem_start="<<el.lexem_start
			<<"\nel.lexem_end="<<el.lexem_end
			<<"\nel.lexem_type="<<el.lexem_type
			<<"\nel.el_str="<<el.el_str.toStdString()<<std::endl;
	return os;
}



