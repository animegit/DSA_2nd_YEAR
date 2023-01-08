#include<stdio.h>
#include<string.h>
int nfind(char *string,char *pat){
    int count=0;
    int lens=strlen(string);
    int lenp=strlen(pat);
    int start=0;
    for(int i=lenp-1;i<lens;i++){
        if(string[i]==pat[lenp-1]){
            for(int i=start,j=0;i<start+lenp-1;i++,j++){
                if(string[i]!=pat[j]){
                    count=0;
                    break;
                }
                else{
                    count++;
                }
                 if(count==lenp-1){
                return start;
            }
            }
           
        }
        start++;
    }
    return -1;
}

void main(){
    char str[100],pat[100];
    printf("Enter the string\n");
    scanf("%s",str);
    printf("Enter the pattern\n");
    scanf("%s",pat);
    int res=nfind(str,pat);
    if(res==-1){
        printf("Pattern not found");
    }
    else{
        printf("Pattern found at index:- %d",res);
    }
}

