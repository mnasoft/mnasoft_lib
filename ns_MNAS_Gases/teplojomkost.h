/***************************************************************************
 *   Copyright (C) 2005 by Матвеев Николай Анатольевич                     *
 *   matveev@mksat.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef TEPLOJOMKOST_H
#define TEPLOJOMKOST_H

#include "fvector.h"
#include "fpolynom.h"

using namespace std;

using namespace ns_MNAS_Matrix;

namespace ns_MNAS_Gases
{
///teplojomkost - Класс для определения теплоемкости.
class MNASOFT_EXPORT teplojomkost
{
protected:
    ///Содержит табличные значения температур  уменьшенные в 1000.0 раз  [гард. Цельсия].
    FVector v_t;
    ///Содержит табличные значения истинных изобарных теплоемкостей cp=[ккал/(кг*град)].
    FVector v_Cp;
    ///Содержит табличные значения истинных теплоемкостей cv=[ккал/(кг*град)].
    FVector v_Cv;
    ///Содержит табличные значения энтропий s=[ккал/(кг*град)].
    FVector v_S;
    ///Количество элементов в каждом из векторов: v_t, v_Cp, v_Cv, v_S.
    int v_max;
    ///Устанавливает длину векторов v_t, v_Cp, v_Cv, v_S равной length.
    void set_v_max(int length);
    ///Полином зависимости истинной изобарной теплоемкости от температуры.
    FPolynom p_t_Cp;
    ///Первообразная от полинома зависимости истинной изобарной теплоемкости от температуры.
    FPolynom I_p_t_Cp;
    ///Полином зависимости истинной изохорной теплоемкости от температуры.
    FPolynom p_t_Cv;
    ///Первообразная от полинома зависимости истинной изохорной теплоемкости от температуры.
    FPolynom I_p_t_Cv;
    ///Полином зависимости энторопии от температуры.
    FPolynom p_t_S;
    ///Производит вычисление коэффициентов полиномов p_t_Cp, p_t_Cv, p_t_S в зависимости от данных содержащихся в векторах v_t, v_Cp,  v_Cv, v_S.
    void reculc_polynoms(void);
    teplojomkost();
    virtual ~teplojomkost();
public:
    ///Возвращает истинную изобарную теплоемкость [ккал/(кг*град)] как функцию от температуры, выраженную в [град.Цельсия].
    virtual double Cp(double t);
    ///Возвращает истинную изохорную теплоемкость [ккал/(кг*град)] как функцию от температуры, выраженную в [град.Цельсия].
    virtual double Cv(double t);
    ///Возврвщает среднюю изобарную теплоемоксть [ккал/(кг*град)] в диапазоне температур от t1 до t2 [град.Цельсия].
    virtual double Cpm(double t1, double t2);
    ///Возврвщает среднюю изохорную теплоемоксть [ккал/(кг*град)] в диапазоне температур от t1 до t2 [град.Цельсия].
    virtual double Cvm(double t1, double t2);
    ///Возврвщает этальпию [ккал/кг] в зависимости от температуры t [град.Цельсия].
    virtual double I(double t);
    ///Возвращает энторопию [ккал/кг*град.Цельсия]??? в зависимости от температуры t [град.Цельсия].
    virtual double S(double t);
    ///Возвращает наименование газа.
    virtual string Name()=0;
    ///Химическая формула.
    virtual string Formula()=0;
};
}

#endif //TEPLOJOMKOST_H
