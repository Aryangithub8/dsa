#include<stdio.h>
#include<stdlib.h>

void findRep(char str[], char pat[], char rep[]){
    int i=0;
    while(str[i]!='\0'){
        for(int j=0; pat[j]!='\0'; j++){
            if(str[i]!=pat[j]){
                i++;
                break;
            }
            str[i++]=rep[j];
        }
    }
    printf("\nString after replacement: %s\n\n",str);
}

void main(){
    char str[20]="", pat[10]="", rep[10]="";
    printf("\nEnter str: ");
    scanf("%s",str);
    printf("\nEnter pat: ");
    scanf("%s",pat);
    printf("\nEnter rep: ");
    scanf("%S",rep);
    findRep(str,pat,rep);
}
