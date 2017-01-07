#include "method_half_div.h"
#include <QTextStream>

double Half_Div(double a,double b,double delta,FF_double func)
{
    double f_a,f_b,f_c,c;
    if(a>b)
    {
        double temp;
        temp=b;
        b=a;
        a=temp;
    }
    f_a=func(a);
    f_b=func(b);
    if(f_a*f_b>0.0)
    {
        QTextStream out(stdout);
        out<<"Нет корней."<<endl;
        return 0.0;
    }
    do
    {
        c=(b+a)/2.0;
        f_c=func(c);
        if(f_a*f_c==0.0)
            return c;
        else if(f_a*f_c<0.0)
        {
            b=c;
            f_b=f_c;
        }
        else if(f_a*f_c>0.0)
        {
            a=c;
            f_a=f_c;
        }
    }while(b-a>delta);
    return c;
}

nm_value Half_Div(nm_value a, nm_value b, nm_value delta, FF_nm_value func)
{
    nm_value f_a,f_b,f_c,c;
    if(a>b)
    {
        nm_value temp;
        temp=b;
        b=a;
        a=temp;
    }
    f_a=func(a);
    f_b=func(b);
    if(f_a*f_b>0.0)
    {
        QTextStream out(stdout);
        out<<"Нет корней."<<endl;
        return 0.0;
    }
    do
    {
        c=(b+a)/2.0;
        f_c=func(c);
        if(f_a*f_c==0.0)
            return c;
        else if(f_a*f_c<0.0)
        {
            b=c;
            f_b=f_c;
        }
        else if(f_a*f_c>0.0)
        {
            a=c;
            f_a=f_c;
        }
    }while(b-a>delta);
    return c;
}
