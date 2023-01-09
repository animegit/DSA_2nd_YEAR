#include<stdio.h>

typedef enum{
    lparen,rparen,plus,minus,mod,times,eos,div,operand
}token;
int stack[100];
int top=-1;
char expr[100];
void push(int item){
    stack[++top]=item;
}
int pop(){
    return stack[top--];
}
token gettoken(char *str, int *n){
  *str= expr[(*n)++];
  switch(*str){
    case '+':{return plus;}
    case '-':return minus;
    case '*':return times;
    case '/':return div;
    case '%':return mod;
    case ')':return rparen;
    case '(':return lparen;
    case '\0':return eos;
    default : return operand;
  }
}

int eval(){
    int n=0;
    char str;
    token sym=gettoken(&str,&n);
    while(sym!=eos){
        if(sym==operand){
            push(str-'0');
        }
        else{
            int op2=pop();
            int op1=pop();
            switch(sym){
                case plus:push(op1+op2);
                break;
                case minus:push(op1-op2);
                break;
                case times:push(op1*op2);
                break;
                case div:push(op1/op2);
                break;
                case mod:push(op1%op2);
                break;
                default:break;
        }
         
    }
   sym=gettoken(&str,&n);
 
    }
       return pop();
}
    


void main(){
    printf("Enter the expression\n");
    scanf("%s",&expr);
    int ans=eval();
    printf("Result after evalution is:- %d",ans);
}
