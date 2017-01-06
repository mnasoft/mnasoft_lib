/**
@author Матвеев Николай
*/

#include <Mnd_elem.h>

using namespace std;

namespace ns_MNAS_MendeleevTbl
{
	Mnd_elem::Mnd_elem()
	{
	}

	Mnd_elem::Mnd_elem(const elem & el):p_elem(0)
	{
		this->p_elem = el.Build_Copy();
	}

	Mnd_elem::Mnd_elem(const Mnd_elem & )
	{
	}

	Mnd_elem::~Mnd_elem()
	{}


	elem & Mnd_elem::get_elem(void)
	{
		return *p_elem;
	}

	bool Mnd_elem::operator == (const Mnd_elem & M_el)
	{
		return true;
	}

	bool Mnd_elem::operator < (const Mnd_elem & M_el)
	{
		return true;
	}

};
