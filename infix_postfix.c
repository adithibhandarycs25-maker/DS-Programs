
#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char exp[])
{
    int i;

    for(i = 0; exp[i] != '\0'; i++)
    {
        char c = exp[i];

        if(isspace(c))
            continue;

        if(isalnum(c))
            printf("%c", c);

        else if(c == '(')
            push(c);

        else if(c == ')')
        {
            while(top != -1 && stack[top] != '(')
                printf("%c", pop());

            if(top != -1)
                pop();
        }

        else
        {
            while(top != -1 && stack[top] != '(' &&
                  precedence(stack[top]) >= precedence(c))
                printf("%c", pop());

            push(c);
        }
    }

    while(top != -1)
        printf("%c", pop());

    printf("\n");
}

int main()
{
    char exp[MAX];

    printf("Enter infix expression: ");
    fgets(exp, MAX, stdin);

    printf("Postfix expression: ");
    infixToPostfix(exp);

    return 0;
}
A