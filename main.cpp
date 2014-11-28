#include <stdio.h>

double GetG0(char**);

double GetE(char**);

double GetT(char**);

double GetP(char**);

double GetN(char**);

double GetF(char**);

double GetM(char**);

double GetG0(char** s)
{
    return GetE(s);
}

double GetE(char** s)//sum
{

    double val= GetM(s);
    while(**s=='+'){(*s)++;val+=GetM(s);}
    return val;
}

double GetM(char** s)//minus
{

    double val= GetT(s);
    while(**s=='-'){(*s)++;val-=GetT(s);}
    return val;
}
double GetF(char** s)//div
{

    double val= GetP(s);
    while(**s=='/'){(*s)++;val/=GetP(s);}
    return val;
}

double GetT(char** s)//mul
{

    double val= GetF(s);
    while(**s=='*'){(*s)++;val*=GetF(s);}
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
char* c="1-2/2/2*(12+23)*(2+2/1)";
printf("%s=",c);
printf("%lg",GetG0(&c));
}
