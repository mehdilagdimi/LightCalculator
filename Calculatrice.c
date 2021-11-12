#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <string.h>

#define SIZE 20
// arithmetic functions
float arithmFunc(float x, float y, char oper){
    if (oper == '+') return x + y;
    else if (oper == '-') return x - y;
    else if (oper == '*' || oper == 'x') return x * y;
    else if (oper == '/') return x/y; // should I specify float(x) ?
}

//void input(){
//    char operStr[SIZE];
//    printf("Welcome to lightCalc!\n Please, type the arithmetic operation you want (please write it in this format XoperationY\n ex: 5+7\n");
//    scanf(" %s", &operStr);
//}
float searchOperator(char operStr[]){
    //should I search the operand as a char or as an int?? check strch()
    char operators[4] = {'+', '-', '*', '/'};
    char* ch;
    double vars[2];
    for (int i = 0; i < 4;i++){  //4 possible operands in this program
        ch = strchr(operStr, operators[i]);
        if(ch == NULL) { continue;}
        short j = 0;  /* this is to append vars array with input operands; It is possible to process more than 2 operands in this case
        though, we have to make the value 2 as a variable or another algorithm */
        while (ch != NULL && j < 2) {
            //perfom string splitting
            char* splitStr = strtok(operStr, ch);
            //convert string to float/double to pass it as argument to arithmFunc
            vars[j] = strtod(splitStr, NULL);
            j++;
        }
        }
        return (arithmFunc(vars[0], vars[1] ,ch[0]));
}

void main(){
//    input();
    float result;
    char operStr[SIZE];
    printf("Welcome to lightCalc!\n Please, type the arithmetic operation you want (please write it in this format XoperationY\n ex: 5+7\n");
    scanf(" %s", &operStr);
    result = searchOperator(operStr);
    printf("\n Result of operation : %f", result);

}
