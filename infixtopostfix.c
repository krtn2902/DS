    #include "stack_operations_char.h"
    int precedence(char);
    void infix_to_postfix(char exp[]);
    int main(){
        char exp[30];
        printf("Enter the expression to convert: ");
        scanf("%s",exp);
        infix_to_postfix(exp);
    }
    int precedence(char c){
        if(c=='+' || c=='-') return 1;  
        else if(c=='*' || c=='/') return 2; 
        return 0;
    }
    void infix_to_postfix(char exp[]){
        char postfix[20];
        stack s=initialize();
        int j=0;
        char token,temp;
        for(int i=0; exp[i]!='\0'; i++){
            token=exp[i];
            if(token=='('){
                push(&s, token);
            }
            else if(token==')'){
                while(s.item[s.top]!='('){
                    postfix[j++]=pop(&s);
                }
                temp=pop(&s);
            }
            else if(precedence(token)==0){
                postfix[j++]=token;
            }
            else if(precedence(token)<=precedence(s.item[s.top])) {
                while(precedence(token)<=(precedence(s.item[s.top]) && !isEmpty(&s))){
                    postfix[j++]=pop(&s);
                }
                push(&s,token);
            }
            else 
            {
                push(&s,token);
            }
        
        }
        while(!isEmpty(&s)){
            postfix[j++]=pop(&s);
        }

        postfix[j]='\0';
        printf("The converted postfix expression is %s", postfix);
    }
