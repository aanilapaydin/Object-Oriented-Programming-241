/*
 * File:  091044042HW01.cpp
 * Created by Ali Anıl APAYDIN
 *
 * Created on 03 Ekim 2012 Çarşamba, 00:30
 *
 * Description:This program solves simple cryptarithmatic problems
 * given by the user.
 *
 * Notes:CSE241_HW01_091044042
 *
 */

#include<iostream>                                                      /*including libraries*/
#include<cmath>
#include<cstring>
#include<cstdlib>

using namespace std;

#define MAX_CHAR_NUM 10

char a[10],b[10],c[11],ans[11];                                         /*Global variables declaration*/
int an,bn,cn;
int n[10];
int ct=0;
int maxchar;
int no[10];

void generate(int z,int avail[10]);                                     /*function implementations*/
void checkValue();
void calculate();
void setChar();

int main()                                                              /*main function*/
{
    int maxSize;

    do{                                                                 /*Getting strings and checking validity*/
        do{
            cout<<"Enter the first string:\n";
            cin>>a;
        }while(strlen(a)<1 || strlen(a)>10);

        do{
            cout<<"Enter the second string:\n";
            cin>>b;
        }while(strlen(b)<1 || strlen(b)>10);

        do{
            cout<<"Enter the sum string:\n";
            cin>>c;
        }while(strlen(c)<1 || strlen(c)>10);

        if(strlen(a)>=strlen(b))
            maxSize=strlen(a);
        else
            maxSize=strlen(b);

    }while(strlen(c)<maxSize ||
           strlen(c)>maxSize+1);

    setChar();                                                          /*setting different characters*/
    ans[maxchar]='\0';                                                  /*printing characters*/
    cout<<"Characters are:\n";
    cout<<ans;
    calculate();                                                        /*calculating the solution*/

    return 0;
}

void setChar()                                                          /*setting different character function*/
{                                                                       /*ans string has total different characters*/
    int i,j,
        flag,
        k=0;

    for (i=0;i<strlen(b);++i)
    {
        flag=0;
        for (j=0;j<k;++j)
            if (a[i]==ans[j])
                flag=1;
        if (flag==0)
            ans[k++]=a[i];
    }

    for (i=0;i<strlen(b);++i)
    {
        flag=0;
        for (j=0;j<k;++j)
            if (b[i]==ans[j])
                flag=1;
        if (flag==0)
            ans[k++]=b[i];
    }

    for (i=0;i<strlen(c);++i)
    {
        flag=0;
        for (j=0;j<k;++j)
            if (c[i]==ans[j])
                flag=1;
        if (flag==0)
            ans[k++]=c[i];
    }

    maxchar=k;                                                          /*maxchar=different character number*/
}

void generate(int z,int avail[10])
{
    if(z<maxchar)
    {
        int i;
        for(i=0;i<10;++i)
        {
            no[z]=i;
            if(avail[i]==1)
            {
                avail[i]=0;
                generate(z+1,avail);
                avail[i]=1;
            }
        }
    }
    if(z==maxchar)
      checkValue();                                                     /*checking the solution*/
}

void checkValue()                                                       /*checking and finding the solution*/
{
  an=bn=cn=0;
  int i,j;

  for(i=0;i<strlen(a);++i)
  {
       for(j=0;j<maxchar;++j)
       if(a[i]==ans[j])
       {
          if(i==0&&no[j]==0)
           return;
           an+=(floor(pow(10,strlen(a)-i-1)))*no[j];
       }
  }

  for(i=0;i<strlen(b);++i)
  {
       for(j=0;j<maxchar;++j)
       if(b[i]==ans[j])
       {
        if(i==0&&no[j]==0)
           return;
           bn+=(floor(pow(10,strlen(b)-i-1)))*no[j];
       }
  }
  for(i=0;i<strlen(c);++i)
  {
      for(j=0;j<maxchar;++j)
      if(c[i]==ans[j])
      {
        if(i==0&&no[j]==0)
           return;
           cn+=(floor(pow(10,strlen(c)-i-1)))*no[j];
      }
  }
  if(an+bn==cn)
  {
      cout<<"\n";
      for(i=0;i<maxchar;++i)
      {

          cout<<ans[i]<<"-"<<no[i]<<" ";
      }
      exit(0);
  }
  ct++;

}

void calculate()
{
  int i;
  if(maxchar>MAX_CHAR_NUM)                                              /*cheking different char number*/
  {
      cout<<"Invalid Input!!";
      return;
  }
  int avail[10];
  for(i=0;i<=9;++i)
    avail[i]=1;
  generate(0,avail);                                                    /*generating the solution*/

}
