#include<stdio.h>
#include<stdlib.h>

void toh(int n, char s, char a, char d){
    if(n==1)
        printf("Moving disk 1 from %c to %c\n",s,d);
    else{
        toh(n-1,s,d,a);
        printf("Moving disk %d from %c to %c\n",n,s,d);
        toh(n-1,a,s,d);
    }
}

void main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("\n\nSource A, Auxilary B, Destination C\n\n");
    toh(n,'A','B','C');
    printf("\n\nMoved %d disks from A to C\n\n",n);
}

#include<stdio.h>
void tower(int n,int s,int t,int d)
{
    if(n==0)
    {
        return;
    }
    tower(n-1,s,d,t);
    printf("move disk %d from %c to %c\n",n,s,d);
    tower(n-1,t,s,d);
}
int main()
{
    int n;
    printf("enter no of disk: ");
    scanf("%d",&n);
    tower(n,'A','B','C');
    return 0;
}
