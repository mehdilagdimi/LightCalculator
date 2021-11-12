#include <stdio.h>
//#include <math.h>
#include <string.h>

#define SIZE = 20;
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
void searchOperand(char operStr[]){
    //should I search the operand as a char or as an int?? check strch()
    char operands[4] = {'+', '-', '*', '/'};
    char* ch;
    for (int i = 0; i < 4;i++){  //4 possible operands in this program
        ch = strchar(operStr, operands[i]);
        if(ch == NULL) { continue;}
        else {
            arithmFunc(ch[0]);
            break; //is this necessary though??
        }
    }
}

void main(){
//    input();

    char operStr[SIZE];
    printf("Welcome to lightCalc!\n Please, type the arithmetic operation you want (please write it in this format XoperationY\n ex: 5+7\n");
    scanf(" %s", &operStr);
    searchOperand(operStr);
//    showResults();

}
