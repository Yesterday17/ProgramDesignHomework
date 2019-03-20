#include<stdio.h>
#include<string.h>
#include"find_name.h"
#include"data/purchase.h"
#include"data/component.h"
bool find_name(LinkedList *linkprime,char *wantname) 
{
    if(strcmp(linkprime->prime->name,wantname)==0)
      return true;
    else
   return false;

 }

