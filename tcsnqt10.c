// coffee vending machine
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(int argc, char const *argv[])
{
    char c[50][30]={"Expresso coffee","Capacino coffee","Latte coffee"};
    char t[50][30]={"Plain Tea","Assam Tea","Ginger Tea"};
    char s[50][30]={"Hot and sour Soup","Veg Corn Soup","Tomato Soup"};
    char b[50][30]={"Hot Chocolate drink","Badam Drink","Badam Pista Drink"};
    char str[]="Welcome to CCD\nEnjoy your ";
    char ch;
    int item;
    scanf("%c%d",&ch,&item);
    if (ch!='C'&&ch!='T'&&ch!='S'&&ch!='B'&&ch!='c'&&ch!='t'&&ch!='s'&&ch!='b')
    {
        printf("Invalid Option\n");
    }
    else if (ch=='C'||ch=='c')
    {
        if (item<0||item>3)
        {
            printf("INVALID OUTPUT\n");
        }
        else
        {
            printf("%s %s",str,c[item-1]);
        }
        
    }
    else if (ch=='T'||ch=='t')
    {
        if (item<0||item>3)
        {
            printf("INVALID OUTPUT\n");
        }
        else
        {
            printf("%s %s",str,t[item-1]);
        }
        
    }
    else if (ch=='S'||ch=='s')
    {
        if (item<0||item>3)
        {
            printf("INVALID OUTPUT\n");
        }
        else
        {
            printf("%s %s",str,s[item-1]);
        }
        
    }

    return 0;
}
