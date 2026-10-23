
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

int isValid(char exp[])
{
    int i;
    char c;

    for(i = 0; exp[i] != '\0'; i++)
    {
        c = exp[i];

        if(c == '(' || c == '[' || c == '{')
            stack[++top] = c;

        else if(c == ')' || c == ']' || c == '}')
        {
            if(top == -1)
                return 0;

            if((c == ')' && stack[top] != '(') ||
               (c == ']' && stack[top] != '[') ||
               (c == '}' && stack[top] != '{'))
                return 0;

            top--;
        }
    }

    return top == -1;
}

int main()
{
    char exp[MAX];

    printf("Enter parentheses: ");
    scanf("%99s", exp);

    top = -1;

    if(isValid(exp))
        printf("Valid Parentheses\n");
    else
        printf("Invalid Parentheses\n");

    return 0;
}
