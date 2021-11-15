#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <string.h>

#define SIZE 20
// arithmetic functions
double arithmFunc(double x, double y, char oper){
    if (oper == '+') return x + y;
    else if (oper == '-') return x - y;
    else if (oper == '*' || oper == 'x') return x * y;
    else if (oper == '/') return x/y; // should I specify float(x) ?
}

double searchOperands(char operStr[], int indexOfOperand){
    int numOfOperands = 2;
    int sizeArray = strlen(operStr); printf("2nd mesure of size of array %d : \n", sizeArray);
    //Let's try first the case where the user enters only two operands
    double vars[numOfOperands];
    char firstOperand[SIZE/2];
    char secondOperand[SIZE/2];
    for(int i = 0; i < indexOfOperand; i++){
        firstOperand[i] = operStr[i];
        printf("\ncharacter swapping : %c", operStr[i]);
        }
    firstOperand[indexOfOperand] = '\0';
    for(int i = (indexOfOperand + 1); i < sizeArray; i++){
        secondOperand[i] = operStr[i];
        printf("\ncharacter swapping :%c", operStr[i]);
        }
    secondOperand[sizeArray]= '\0';
    printf("\nFirst operand : %s \nSecond operand : %s\n", firstOperand, secondOperand);

    //convert string operands to double
    vars[0] = strtod(firstOperand, NULL); printf("first string to double %lf : \n", vars[0]);
    vars[1] = strtod(secondOperand, NULL); printf("second string to double %lf : \n", vars[1]);
    //call arithmfunc and pass the transformed operands into doubles and also the operator
    arithmFunc(vars[0], vars[1], operStr[indexOfOperand]);
}

double searchOperator(char operStr[]){
    //should I search the operand as a char or as an int?? check strch()
    char operators[4] = {'+', '-', '*', '/'};
    char* ch;
    for (int i = 0; i < 4; i++){  //4 possible operands stored in "operators" array
        ch = strchr(operStr, operators[i]);
        if(ch == NULL) {
            printf("%c operand not found, continue to check for other operands\n", operators[i]);
            continue;}
        else {
            int indexOfOperand = (int)(ch - operStr);
            printf("Operand %c found in the array, its index is %d \n",operators[i], indexOfOperand);
            return (searchOperands(operStr,indexOfOperand));
        }


//        else {
//            char splitStr1[10];
//            char splitStr2[10];
//            int finAdress = (int)(ch - operStr);
//            vars[0] = strtod(strncpy(splitStr1, &operStr[0], finAdress),  NULL);
//            vars[1] = strtod(strncpy(splitStr2, ch,   )
//        }
//        short j = 0;  /* this is to append vars array with input operands; It is possible to process more than 2 operands in this case
//        though, we have to make the value 2 as a variable or another algorithm */
//        while (ch != NULL && j < 2) {
////            perfom string splitting
//            char* splitStr = strtok(operStr, ch);
////            convert string to float/double to pass it as argument to arithmFunc
//            vars[j] = strtod(splitStr, NULL);
//            j++;
//        }
    }

}

void main(){
    double result;
    char operStr[SIZE];
    printf("Welcome to lightCalc!\n Please, type the arithmetic operation you want (please write it in this format XoperationY\n ex: 5+7\n");
    scanf("%s", &operStr);
    printf("First mesure of array size : %d\n", strlen(operStr));
    result = searchOperator(operStr);

    //results = arithmFunc();
    printf("\n Result of operation : %f", result);

}
