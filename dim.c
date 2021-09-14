#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50

void push(long int symbol);
long int pop();
void infix_to_postfix();
long int eval_post();
int priority(char symbol);
int isEmpty();
int white_space(char );
void find_top();
void push_1(char);
void pop_1();
void main_1();

char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

int main()
{
        long int value;
        top=-1;
        printf("Enter infix : ");
        gets(infix);
        main_1();
        infix_to_postfix();
        printf("Postfix : %s\n",postfix);
        value=eval_post();
        printf("Value of expression : %ld\n",value);

        return 0;

}/*End of main()*/


void infix_to_postfix()
{
        unsigned int i,p=0;
        char next;
        char symbol;
        for(i=0;i<strlen(infix);i++)
        {
                symbol=infix[i];
                if(!white_space(symbol))
                {
                        switch(symbol)
                        {
                        case '(':
                                push(symbol);
                                break;
                        case ')':
                                while((next=pop())!='(')
                                        postfix[p++] = next;
                                break;
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '%':
                        case '^':
                                while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
                                        postfix[p++]=pop();
                                push(symbol);
                                break;
                        default: /*if an operand comes*/
                             postfix[p++]=symbol;
                        }
                }
        }
        while(!isEmpty( ))
                postfix[p++]=pop();
        postfix[p]='\0'; /*End postfix with'\0' to make it a string*/
}/*End of infix_to_postfix()*/

/*This function returns the priority of the operator*/
int priority(char symbol)
{
        switch(symbol)
        {
        case '(':
                return 0;
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
        case '%':
                return 2;
        case '^':
                return 3;
        default :
                return 0;
        }
}/*End of priority()*/

void push(long int symbol)
{

        if(top>MAX)
        {
                printf("Stack overflow\n");
                exit(1);
        }
        stack[++top]=symbol;
}/*End of push()*/

long int pop()
{
        if( isEmpty() )
        {
                printf("Stack underflow\n");
                exit(1);
        }
        return (stack[top--]);
}/*End of pop()*/
int isEmpty()
{
        if(top==-1)
                return 1;
        else
                return 0;
}/*End of isEmpty()*/

int white_space(char symbol)
{
        if( symbol == BLANK || symbol == TAB )
                return 1;
        else
                return 0;
}/*End of white_space()*/

long int eval_post()
{
        long int a,b,temp,result;
        unsigned int i;

        for(i=0;i<strlen(postfix);i++)
        {
                if(postfix[i]<='9' && postfix[i]>='0')
                        push(postfix[i]-'0');
                else
                {
                        a=pop();
                        b=pop();
                        switch(postfix[i])
                        {
                        case '+':
                                temp=b+a; break;
                        case '-':
                                temp=b-a;break;
                        case '*':
                                temp=b*a;break;
                        case '/':
                                temp=b/a;break;
                        case '%':
                                temp=b%a;break;
                        case '^':
                                temp=pow(b,a);
                        }
                        push(temp);
                }
        }
        result=pop();
        return result;
}/*End of eval_post */

void main_1()
{
	int i;
	char a[100];
	printf("enter expression\n");
	scanf("%s", &a);
	for (i = 0; a[i] != '\0';i++)
	{
		if (a[i] == '(')
		{
			push(a[i]);
		}
		else if (a[i] == ')')
		{
			pop();
		}
	}
	find_top();
}

// to push elements in stack
void push_1(char a)
{
	stack[top] = a;
	top++;
}

// to pop elements from stack
void pop_1()
{
	if (top == -1)
	{
		printf("expression is invalid\n");
		exit(0);
	}
	else
	{
		top--;
	}
}

// to find top element of stack
void find_top()
{
	if (top == -1)
		printf("\nexpression is valid\n");
	else
		printf("\nexpression is invalid\n");
}
