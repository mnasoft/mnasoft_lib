/** @author Матвеев Николай Анатольевич */

#ifndef MND_ELEM_H
#define MND_ELEM_H

#include "mnasoft_lib_global.h"

#include <elem.h>

using namespace std;

namespace ns_MNAS_MendeleevTbl
{
	class MNASOFT_EXPORT Mnd_elem
	{
	protected:
		elem * p_elem;
	public:
		Mnd_elem();
		Mnd_elem(const elem & );
		Mnd_elem(const Mnd_elem & );
		~Mnd_elem();

		elem & get_elem(void);
		bool operator == (const Mnd_elem & M_el);
		bool operator < (const Mnd_elem & M_el);
	};
};

#endif //MND_ELEM_H
