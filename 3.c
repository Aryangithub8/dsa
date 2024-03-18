#include<stdio.h>
#define MAX 10
int top=-1;
int overflow()
{
 if (top==MAX-1)
 return 1;
 else return 0;
}
int underflow()
{
 if (top==-1)
 return 1;
 else return 0;
}
void push(int *s,int ele)
{
 if(!overflow())
 s[++top]=ele;
 else
 printf("stack overflow\n");
}
int pop(int *s)
{
 if(!underflow())
 return(s[top--]);
 else
 printf("stack underflow\n");
 return(0);
}
void display(int *s)
{
 int i;
 if(underflow())
 { 
 printf("stack underflow\n");
 return;
 }
 printf("The stack contents are:\n");
 for(i=0;i<=top;i++)
 printf("%d\t",s[i]);
}
int palin(char *pal,int *s)
{
 int i;
 top=-1;
 for(i=0;pal[i]!='\0';i++)
 push(s,pal[i]-'0');
 for(i=0;pal[i]!='\0';i++)
if (pal[i]!=(pop(s)+'0'))
 return 0;
 return 1;
 }
int main()
{
 int stack[MAX],ch,i,j,ele,p;
 char str[10];
 while(1)
 {
printf("\nEnter your choice:\n1:PUSH\n2:POP\n3:CHECK 
PALINDROME\n4:DISPALY\n5.EXIT\n");
 scanf("%d",&ch); 
switch(ch)
 {
case 1: printf("\nEnter the element to be pushed: n");
scanf("%d",&ele);
push(stack,ele);
break;
case 2: ele=pop(stack);
if(ele!=0)
printf("\nThe deleted element is: %d\n",ele);
break;
case 3:printf("\nEnter the string ");
 fflush(stdin);
 gets(str);
p=palin(str,stack);
 if(p) 
printf("\nThe given string is Palindrome");
 else 
printf("\nThe given string is not a palindrome");
 break;
case 4:display(stack);
break;
 default:exit(0);
 }
 }
 return 0;
}
