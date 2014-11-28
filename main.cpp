#include <stdio.h>

double GetG0(char**);

double GetE(char**);

double GetT(char**);

double GetP(char**);

double GetN(char**);

double GetM(char**);//minus

double GetF(char**);//division

double GetG0(char** s)
{
    return GetE(s);
}

double GetE(char** s)
{

    double val= GetM(s);
    while(**s=='+'){(*s)++;val+=GetM(s);}
    return val;
}

double GetM(char** s)
{

    double val= GetT(s);
    while(**s=='-'){(*s)++;val-=GetT(s);}
    return val;
}

double GetT(char** s)
{

    double val= GetF(s);//getP
    while(**s=='*'){(*s)++;val*=GetF(s);}
    return val;
}

double GetF(char** s)
{

    double val= GetP(s);//getT
    while(**s=='/'){(*s)++;val/=GetP(s);}
    return val;
}

double GetP(char** s)
{
    if (**s=='(')
    {
        (*s)++;
        double val=GetE(s);
        (*s)++;
        return val;
    }
    else return GetN(s);
}

double GetN(char** s)
{
    double val=0;
    while (**s>='0'&&**s<='9'){val=val*10+**s-'0';(*s)++;}
    return val;
}

int main()
{
char* c="2-1*(12+23)*(2+2/1)";
printf("%s=",c);
printf("%lg",GetG0(&c));
}
