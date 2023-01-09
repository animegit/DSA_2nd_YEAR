#include <stdio.h>

typedef enum{
    lparen,rparen,plus,minus,times,operand,divide,eos,mod
}precedance;
int icp[]={20,19,12,12,13,13,13,0};
int isp[]={0,19,12,12,13,13,13,0};
char stack[100];
int top=0;
char expr[100];
void push(char item){
    stack[++top]=item;
}
char pop(){
    return stack[top--];
}

precedance gettoken(char *str,int *n){
    *str=expr[(*n)++];
    switch(*str){
        case '+':return plus;
        case'-':return minus;
        case '*':return times;
        case '/':return divide;
        case '%':return mod;
        case '\0':return eos;
        case')':return rparen;
        case '(':return lparen;
        default:return operand;
    }
}

precedance eqi(char s){
    switch(s){
         case '+':return plus;
        case'-':return minus;
        case '*':return times;
        case '/':return divide;
        case '%':return mod;
        case '\0':return eos;
        case')':return rparen;
        case '(':return lparen;
        default:return operand;
    }
}


void convert(){
    int n=0;
    char symbol;
    precedance token=gettoken(&symbol,&n);
    while(token!=eos){
        if(token==operand){
            printf("%c",symbol);
        }
        else if(token==rparen){
            while((stack[top])!='('){
                printf("%c",pop());
            }
            pop();
        }
        else{
            while(isp[eqi(stack[top])]>=icp[token])  printf("%c",pop());
              
              push(symbol);
        }
        token=gettoken(&symbol,&n);
    }
    
    while((symbol=pop())!='\0'){
        printf("%c",symbol);
    }
}

void main(){
    stack[0]='\0';
    printf("Enter the expression\n");
    scanf("%s",expr);
    convert();
    
}
