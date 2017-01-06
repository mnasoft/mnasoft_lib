#ifndef METHOD_HALF_DIV_H
#define METHOD_HALF_DIV_H

#include "mnasoft_lib_global.h"

#include "nm_value.h"

typedef double FF_double(double);
typedef nm_value FF_nm_value(const nm_value &);

///Метод половинного деления.
/** Выполняет поиск значения x в интервале (a, b) при котором значение функции FF_double(x) равно 0.*/
double MNASOFT_EXPORT Half_Div(double a /**Левая грани */,double b,double delta, FF_double);

///Метод половинного деления.
/** Выполняет поиск значения x в интервале (a, b) при котором значение функции FF_double(x) равно 0.*/
nm_value MNASOFT_EXPORT Half_Div(nm_value a, nm_value b, nm_value delta, FF_nm_value);

#endif //METHOD_HALF_DIV_H

