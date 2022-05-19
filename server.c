#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

void ilate (char u[],char v[])
{
   //char u[50];
   //char v[50];
   char *result;
   //printf("Enter first term:");
   //scanf("%[^\n]s", u);
   //fflush(stdin);
   //printf("Enter second term:");
   //scanf("%[^\n]s", v);
   //printf("u:%s\n", u) ;
   char new_u[100] ;
   char new_v[100] ;
   strcpy(new_u, u) ;
   strcpy(new_v, v) ;
   //printf("v:%s\n", v);
   if(!(strcmp(u, "logx")) || (!(strcmp(u, "logy"))))
   {
      //printf("Performing ilate with u as first term");
      perform_ilate(new_u, new_v, *integration, *differentiation);

   }

   else if(!(strcmp(u, "e^x")) || (!(strcmp(u, "e^y"))))
   {
      char temp = *u;
      *u = *v;
      *v = temp;
     // printf("Performing ilate after swapping");
      perform_ilate(new_u, new_v, *integration, *differentiation);

   }

   else if(!(strcmp(u, "sinx")) || (!(strcmp(u, "siny"))) || (!(strcmp(u, "cosx"))) || (!(strcmp(u, "cosy"))) || (!(strcmp(u, "tanx"))) || (!(strcmp(u, "tany"))) || (!(strcmp(u, "secx"))) || (!(strcmp(u, "secy"))) || (!(strcmp(u, "cosecx"))) || (!(strcmp(u, "cosecy"))) || (!(strcmp(u, "cotx"))) || (!(strcmp(u, "coty"))))
   {
      if((!(strcmp(v, "x"))) || (!(strcmp(v, "y"))) || (!(strcmp(u, "logx"))) || (!(strcmp(u, "logy"))))
      {
         char temp = *u;
         *u = *v;
         *v = temp;
         //printf("Ilate after swapping");
         perform_ilate(new_u, new_v, *integration, *differentiation);

      }
      else
      {
         //printf("ilate without modification");
         perform_ilate(new_u, new_v, *integration, *differentiation);

      }


   }
   else
   {
      if ((!(strcmp(v, "logx"))) ||(!(strcmp(v, "logy"))))
      {
         char temp = *u;
         *u = *v;
         *v = temp;
         //printf("Ilate after swapping");
         perform_ilate(new_u, new_v, *integration, *differentiation);

      }
      else if ((!(strcmp(v, "sinx"))) || (!(strcmp(v, "siny"))) || (!(strcmp(v, "cosx"))) || (!(strcmp(v, "cosy"))) || (!(strcmp(v, "tanx"))) || (!(strcmp(v, "tany"))) || (!(strcmp(v, "secx"))) || (!(strcmp(v, "secy"))) || (!(strcmp(v, "cosecx"))) || (!(strcmp(v, "cosecy"))) || (!(strcmp(v, "cotx"))) || (!(strcmp(v, "coty"))) || (!(strcmp(v, "e^x"))) || (!(strcmp(v, "e^y"))))
      {
         //printf("ilate without modification");
         perform_ilate(new_u, new_v, *integration, *differentiation);
      }
   }
}

void perform_ilate(char u[], char v[], char* (ptr)(char*), char* (ptr1)(char*))
{
   //printf("in perform_ilate\n");
   char res[50];
   char d_res[50];
   char i_res[50];
   char new_f[50];
   strcpy(new_f, u);
   //printf("in perform %s\n", new_u);
   //printf("in perform %s\n", u);
   //printf("%s\n", u);
   //strcat(new_f,"*(") ;
   //strcat(new_f, ptr(v));
   //strcat(new_f,")") ;
   //printf("%s\n", new_u[0]);
   //strcpy(res, new_f);

   //printf("%s\n", res);
   strcpy(d_res, ptr1(u));
   //printf("%s\n", d_res);
   strcpy(i_res, ptr(v));
   //printf("%s\n", i_res);
   //printf("printing the integral\n");
   printf("(%s)*(%s) - integral((%s)*(%s))",new_f, i_res, d_res, i_res);

}

char * separation(char * str)
{

    char str_no_spc[100];
    int i=0, j=0 ;
    //Excluding brackets
    while(str[i] != '\0')
    {
        if(str[i] != '(' &&  str[i] != ')')
        {
            str_no_spc[j++] = str[i];
        }
        i++;
    }
    str_no_spc[j] = '\0';
    //printf("The string after removing all brackets is:\n%s\n", str_no_spc);
    int k = 0, l = 0;
	while (str_no_spc[k])
	{
		if (str_no_spc[k] != ' ' )
          str_no_spc[l++] = str_no_spc[k];
		k++;
	}
	str_no_spc[l] = '\0';
	//printf("The string after removing all the spaces is:\n%s\n", str_no_spc);
    char * result;
    result=(char *)malloc(50*sizeof(char));
	char * yexp3= strtok(str_no_spc, "=");
	char * xexp3= strtok(NULL, "d");
    char * yexp2= strtok(yexp3, "d");
    //printf("y:%s\n",yexp2);
    //printf("x:%s\n",xexp3);
    //now, yexp2 has the y equation and xexp3 has the x equation, strtok based on + and -
    int par_y_count=0, par_x_count=0 ;
    int parity_y_count = 0;
    int parity_x_count = 0;
    while(yexp2[par_y_count]!='\0')
    {
        if(yexp2[par_y_count]=='+')
        {
            parity_y[parity_y_count].parity = '+';
            parity_y_count ++;
            //printf("Parity of y1:%c %d \n", parity_y[parity_y_count].parity,par_y_count);
        }
        else if(yexp2[par_y_count]=='-')
        {
            parity_y[parity_y_count].parity = '-';
            parity_y_count ++;
            //printf("Parity of y2:%c %d \n", parity_y[parity_y_count].parity,par_y_count);
        }
        par_y_count++ ;
    }
    while(xexp3[par_x_count]!='\0')
    {
        if(xexp3[par_x_count]=='+')
        {
            parity_x[parity_x_count].parity = '+';
            parity_x_count ++;
            //printf("Parity of x1:%c %d \n", parity_x[parity_x_count].parity,par_x_count);
        }
        else if(xexp3[par_x_count]=='-')
        {
            parity_x[parity_x_count].parity = '-';
            parity_x_count ++;
            //printf("Parity of x1:%c %d \n", parity_x[parity_x_count].parity,par_x_count);
        }
        par_x_count+=1 ;
    }
    //printf("Parity of y3:%c\n", parity_y[0].parity);
    //printf("Parity of y3:%c\n", parity_y[1].parity);
    //printf("Parity of x3:%c\n", parity_x[0].parity);
    //printf("Parity of x3:%c\n", parity_x[1].parity);
    char * t1= strtok(yexp2, "+-");
    int x=0;
    while(t1 !=NULL)
    {
        //printf("y term:%s\n",t1); //testing
        strcpy(yterms[x].yterm, t1);
        t1=strtok(NULL, "+-");
        x+=1 ;
    }
    char * t2= strtok(xexp3, "+-");
    int y=0 ;
    while(t2 !=NULL)
    {
        //printf("x term:%s\n",t2); //testing
        strcpy(xterms[y].xterm, t2);
        t2=strtok(NULL, "+-");
        y+=1 ;
    }
    //updations
    int travy=0, travx=0;
    //printf("y:%d\n", y); //testing
    //printf("x:%d\n", x); //testing
    printf("The solution to the entered variable separable differential equation is:\n") ;
    while(travy <x)
    {
        char *tester_y = strchr(yterms[travy].yterm, '*') ;
        if(tester_y!= NULL)
        {
            char *u= strtok(yterms[travy].yterm, "*");
            char *v= strtok(NULL,"\0") ;
            ilate(u,v) ;
           // printf("Ilate tbd") ;
            printf("%c",parity_y[travy].parity);
        }
        else
        {
            printf("(%s)", integration(yterms[travy].yterm)); //testing
            printf("%c",parity_y[travy].parity);
        }
        travy+=1 ;
    }
    printf("=") ;
    while(travx <y)
    {
        char *tester_x = strchr(xterms[travx].xterm, '*') ;
        if(tester_x!= NULL)
        {
            char *u= strtok(xterms[travx].xterm, "*");
            char *v= strtok(NULL,"\0") ;
            ilate(u,v) ;
            //printf("Ilate tbd") ;
            printf("%c",parity_x[travx].parity);
        }
        else
        {
            printf("(%s)", integration(xterms[travx].xterm)); //testing
            printf("%c",parity_x[travx].parity);
        }
        travx+=1 ;
    }
    result= " " ;
    return result;
}

char* integration(char *ch)
{

  char * result;
  result=(char *)malloc(50*sizeof(char));
  //printf("The integral of %s is: ",ch);
  if(strcmp(ch,"sinx") == 0 || strcmp(ch,"siny") == 0)
  {
      if(!(strcmp(ch,"sinx")))
      {
          result= "- cos x";
      }
      else if(!(strcmp(ch,"siny")))
      {
          result="-cos y" ;
      }
  }
  else if(strcmp(ch,"cosx") == 0 || strcmp(ch,"cosy") == 0)
  {
      if(!(strcmp(ch,"cosx")))
      {
          result= "sin x";
      }
      else if(!(strcmp(ch,"cosy")))
      {
          result="sin y" ;
      }
  }
  else if(strcmp(ch,"tanx") == 0 || strcmp(ch,"tany") == 0)
  {
      if(!(strcmp(ch,"tanx")))
      {
          result= "- ln|cos x|";
      }
      else if(!(strcmp(ch,"tany")))
      {
          result="-ln|cos y|" ;
      }
  }
  else if(strcmp(ch,"secx") == 0 || strcmp(ch,"secy") == 0)
  {
      if(!(strcmp(ch,"secx")))
      {
          result= "ln|sec x + tan x|";
      }
      else if(!(strcmp(ch,"secy")))
      {
          result="ln|sec y + tan y|" ;
      }
  }
  else if(strcmp(ch,"cotx") == 0 || strcmp(ch,"coty") == 0)
  {
      if(!(strcmp(ch,"cotx")))
      {
          result= "ln|sin x|";
      }
      else if(!(strcmp(ch,"coty")))
      {
          result="ln|sin y|" ;
      }
  }
  else if(strcmp(ch,"cosecx") == 0 || strcmp(ch,"cosecy") == 0)
  {
      if(!(strcmp(ch,"cosecx")))
      {
          result= "-ln|cosec x + cot x|";
      }
      else if(!(strcmp(ch,"cosecy")))
      {
          result="-ln|cosec y + cot y|" ;
      }
  }
  else if(!(strcmp(ch, "e^x")) || !(strcmp(ch, "e^y")))
  {
      if(!(strcmp(ch,"e^x")))
      {
          result= "e^x";
      }
      else if(!(strcmp(ch,"e^y")))
      {
          result="e^y" ;
      }
  }
  else if(!(strcmp(ch, "logx")) || !(strcmp(ch, "logy")))
  {
      if(!(strcmp(ch,"logx")))
      {
          result= "x(logx-1)";
      }
      else if(!(strcmp(ch,"logy")))
      {
          result="y(logy-1)" ;
      }
  }
  else if(ch[0]=='x'|| ch[0]=='y')
  {
      const char delim[2]= "^" ;
      char * token ;
      token = strtok(ch, delim) ;
      token= strtok(NULL, delim) ;
      int pow ;
      pow=atoi(token) + 1 ;
      if(ch[0]=='x')
      {
               char res[100]= "x^" ;
               int j = 0;
               char buffer[50] ;
               itoa(pow, buffer,10) ;
               result[0]='x';
               result[1]='^';
               while(buffer[j]!='\0')
               {
                   result[j+2]= buffer[j];
                   j+=1 ;
               }
               result[j+2]='/' ;
               int i=0;
               while(buffer[i]!= '\0')
               {
                   result[j+3]= buffer[i];
                   i+=1 ;
                   j+=1 ;
               }
               result[j+3]= '\0' ;
               return result ;
      }
      else if(ch[0]=='y')
      {
               char res[100]= "y^" ;
               int j = 0;
               char buffer[50] ;
               itoa(pow, buffer,10) ;
               result[0]='y';
               result[1]='^';
               while(buffer[j]!='\0')
               {
                   result[j+2]= buffer[j];
                   j+=1 ;
               }
               result[j+2]='/' ;
               int i=0;
               while(buffer[i]!= '\0')
               {
                   result[j+3]= buffer[i];
                   i+=1 ;
                   j+=1 ;
               }
               result[j+3]= '\0' ;
               return result ;
      }

  }
  else
  {
      result="invalid input_int";
  }
  return result ;
  free(result) ;
}

char* differentiation(char *ch)
{
  char * result;
  result=(char *)malloc(50*sizeof(char));
  //printf("The differentiation of %s is:", ch);
  if(!(strcmp(ch, "sinx")) || (!(strcmp(ch, "siny"))))
  {
      if(!(strcmp(ch,"sinx")))
            {
              result= "cos x";
            }
            else if(!(strcmp(ch,"siny")))
            {
              result="cos y" ;
            }
  }
  else if(!(strcmp(ch, "cosx")) || (!(strcmp(ch, "cosy"))))
  {
            if(!(strcmp(ch,"cosx")))
            {
              result= "- sinx";
            }
            else if(!(strcmp(ch,"cosy")))
            {
              result="-siny" ;
            }
  }
  else if(!(strcmp(ch, "tanx")) || (!(strcmp(ch, "tany"))))
  {
            if(!(strcmp(ch,"tanx")))
            {
               result= "sec^2 x";
            }
            else if(!(strcmp(ch,"siny")))
           {
               result="sec^2 y" ;
           }
  }
  else if(!(strcmp(ch, "secx")) || (!(strcmp(ch, "secy"))))
  {
            if(!(strcmp(ch,"secx")))
            {
               result= "secx tanx";
            }
            else if(!(strcmp(ch,"secy")))
            {
               result="secy tany" ;
            }
  }
  else if(!(strcmp(ch, "cotx")) || (!(strcmp(ch, "coty"))))
  {
      if(!(strcmp(ch,"cotx")))
            {
               result= "-cosec^2 x";
            }
            else if(!(strcmp(ch,"coty")))
            {
               result="-cosec^2 y" ;
            }
  }
  else if(!(strcmp(ch, "cosecx")) || (!(strcmp(ch, "cosecy"))))
  {
      if(!(strcmp(ch,"cosecx")))
            {
               result= "-cosecx cotx";
            }
            else if(!(strcmp(ch,"cosecy")))
            {
               result="-cosecy coty" ;
            }
  }
       else if(!(strcmp(ch, "e^x")) || !(strcmp(ch, "e^y")))
       {
          if(!(strcmp(ch,"e^x")))
          {
              result= "e^x";
          }
          else if(!(strcmp(ch,"e^y")))
          {
              result="e^y" ;
          }
       }
       else if(!(strcmp(ch, "logx")) || !(strcmp(ch, "logy")))
      {
          if(!(strcmp(ch,"logx")))
          {
              result= "1/x";
          }
          else if(!(strcmp(ch,"logy")))
          {
              result="1/y" ;
          }
      }
      else if(ch[0]=='x'|| ch[0]=='y')
      {
          const char delim[2]= "^" ;
          char * token ;
        token = strtok(ch, delim) ;
          token= strtok(NULL, delim) ;
          //printf("%s\n", token);
          int pow ;
          pow=atoi(token) - 1 ;
          if(ch[0]=='x')
          {
               int j = 4;
               int l;
               char buffer[50] ;
               itoa(pow, buffer,10);
               int n = strlen(token);
               printf("%d", n);
               for (l = 0; l<n ; l++)
               {
                  result[l] = token[l];
               }

               result[l] ='*';

               result[l+1] = 'x';
               result[l+2] = '^';
               int i = 0;
               while(buffer[i]!= '\0')
               {
                   result[l+3+i]= buffer[i];
                   i+=1 ;
               }
               result[l+3+i]= '\0' ;

               return result ;
          }
          else if(ch[0]=='y')
          {
               int j = 4;
               int l;
               char buffer[50] ;
               itoa(pow, buffer,10);
               int n = strlen(token);
               //printf("%d", n);
               for (l = 0; l<n ; l++)
               {
                  result[l] = token[l];
               }

               result[l] ='*';

               result[l+1] = 'y';
               result[l+2] = '^';
               int i = 0;
               while(buffer[i]!= '\0')
               {
                   result[l+3+i]= buffer[i];
                   i+=1 ;
               }
               result[l+3+i]= '\0' ;

               return result ;
          }

      }
      else
      {
          result="invalid input";
      }
      return result ;
      free(result) ;
}
