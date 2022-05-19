#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

char* separation(char *str) ;
char* integration(char *ch) ;
char* differentiation(char *ch);
void ilate (char u[],char v[]);
void perform_ilate(char u[], char v[], char* (*ptr)(char*), char* (*ptr1)(char*));
struct yterms1
{
    char yterm[50];
};
struct yterms1 yterms[100];
struct xterms1
{
    char xterm[50];
};
struct xterms1 xterms[100] ;
struct parity1
{
    char parity;
};
struct parity1 parity_y[50] ;
struct parity2
{
    char parity;
};
struct parity2 parity_x[50] ;

#endif // HEADER_H_INCLUDED
