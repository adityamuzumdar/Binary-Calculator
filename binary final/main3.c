#include<stdio.h> 
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#include "main.h"
int main() { 
    int ch = 0, base = 0, choice = 0;
    char s[50] = {};
    list L;
    init(&L);

    printf("---------------------------------------------------------------------------------\n");
    printf("                                  BINARY CALCULATOR          \n");
    printf("---------------------------------------------------------------------------------\n");
    printf("BY ADITYA MUZUMDAR, MIS:112003002\n");
    printf("RULES:\n");
    printf("1. All inputs must be separated by one blank space.\n");
    printf("2. There should be no space after '(' and before ')'.\n");
    printf("3. All braces must be balanced.\n");
    printf("4. For negative numbers, there should be no space between the sign and the number.\n");
    printf("5. An input in any other format will cause an error message to be displayed and the program will terminate.\n");

    while(1) {

        init(&L);

        printf("\n\n");
        printf("0. Exit\n");
        printf("1. Calculator\n");
        printf("2. Base Change\n");
        
        printf("Choice: ");
        scanf("%d", &ch);
        getchar();
        printf("\n");

        if(ch <= 0 || ch > 3) {
            exit(0);
        }
        else if(ch == 1) {
            gets(s);            //Accepts the expression to be evaluated
            infix_eval(s);      //Evaluates the expression and displays the answer
        }
        else if(ch == 2){
            printf("\n");
            printf("Enter the base to be converted to (2 - 9): ");
            scanf("%d", &base);
            getchar();

            printf("\n");
            printf("Enter the number in decimal (base 10): ");

            if(base >= 2 && base <= 9) {
                gets(s);
                L = extract(s);
                change_base(L, base);       //Changes the base of the number and displays the answer
            }
            else {
                printf("Incorrect base\n");
                exit(1);
            }
        }
        
        
    }
    return 0;
}