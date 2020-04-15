#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 30

struct charStack {
    char hex[MAX];
    int top;
};

struct charStack *charStack = NULL;

struct stack {
    int data[MAX];
    int top;
};

struct stack *Stack = NULL;

void resetStack() {
    if(charStack != NULL || Stack != NULL){
        free(Stack);
        Stack = NULL;
        free(charStack);
        charStack = NULL;
    }
    Stack = (struct stack *) malloc(sizeof(struct stack));
    Stack->top = -1;
    charStack = (struct charStack *) malloc(sizeof(struct charStack));
    charStack->top = -1;
}

void push(int n) {
    Stack->data[++Stack->top] = n;
}

void pushChar(char a) {
    charStack->hex[++charStack->top] = a;
}

int pop() {
    int x = Stack->data[Stack->top];
    Stack->top--;
    return x;
}

char popChar() {
    char x = charStack->hex[charStack->top--];
    return x;
}

int empty() {
    if (Stack->top == -1)
        return (1);
    return (0);
}

void DecimaltoHexadecimalConvertor() {
    resetStack();
    char hexaDeciNum[MAX];
    int n;

    printf("Enter a decimal number:");
    scanf("%d", &n);

    int j = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;

        // check if temp < 10
        if (temp < 10) {
            pushChar(temp + 48);
        } else {
            pushChar(temp + 55);
        }

        n = n / 16;
    }


    while (charStack->top != -1) {
        hexaDeciNum[j] = popChar();
        j++;
    }
    hexaDeciNum[j] = '\0';
    printf("%s", hexaDeciNum);
}

void DecimaltoBinaryConvertor() {
    resetStack();
    int n;
    printf("Enter a Decimal number:");
    scanf("%d", &n);
    int tmp = n;
    while (tmp != 0) {
        push(tmp % 2);
        tmp = tmp / 2;
    }

    printf("\n");
    while (!empty()) {
        tmp = pop();
        printf("%d", tmp);
    }

}

void DecimaltoOctalConvertor() {
    resetStack();
    int n;
    printf("Enter a Decimal number:");
    scanf("%d", &n);
    int tmp = n;
    while (tmp != 0) {
        push(tmp % 8);
        tmp = tmp / 8;
    }
    printf("\n");
    while (!empty()) {
        tmp = pop();
        printf("%d", tmp);
    }
}

void BinarytoDecimalConvertor() {
    resetStack();
    char b[MAX];
    int binary[MAX], i, j, n, sum = 0;
    printf("Enter the binary number:");
    scanf("%s", b);
    n = strlen(b);
    strrev(b);
    for (i = 0, j = 0; i < n; i++) {
        if (isdigit(b[i]) != 0) {
            binary[j] = b[i] - 48;
            j++;
        }
    }
    for (i = 0; i < j; i++) {
        push(binary[i] * powf(2, i));
    }

    for (i = Stack->top; i >= 0; i--) {
        sum = sum + Stack->data[i];
    }
    printf("\nThe decimal value is:%d\n", sum);

}

void DtoO(int d) {
    resetStack();
    int o[MAX], i;
    int tmp = d;
    while (tmp != 0) {
        push(tmp % 8);
        tmp = tmp / 8;
    }
    printf("\n");
    printf("The octal form is ");
    for (i = Stack->top; i >= 0; i--) {
        tmp = pop();
        printf("%d", tmp);
    }
}

int BtoD(char *c) {
    resetStack();
    char b[MAX];
    int binary[MAX], i, j, n, sum = 0;
    n = strlen(c);
    strrev(c);
    for (i = 0, j = 0; i < n; i++) {
        if (isdigit(c[i]) != 0) {
            binary[j] = c[i] - 48;
            j++;
        }
    }
    for (i = 0; i < j; i++) {
        push(binary[i] * powf(2, i));
    }

    for (i = Stack->top; i >= 0; i--) {
        sum = sum + Stack->data[i];
    }

    return sum;

}

void DtoH(int n) {
    resetStack();
    char HexadecimalNumber[MAX];
    int j = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;

        // check if temp < 10
        if (temp < 10) {
            pushChar(temp + 48);
        } else {
            pushChar(temp + 55);
        }

        n = n / 16;
    }
    while (charStack->top != -1) {
        HexadecimalNumber[j] = popChar();
        j++;
    }
    HexadecimalNumber[j] = '\0';
    printf("%s", HexadecimalNumber);
}

void BinarytoHexadecimalConvertor() {
    resetStack();
    int d;
    char b[10];
    printf("Enter the binary number:");
    scanf("%s", b);
    d = BtoD(b);
    DtoH(d);
}

void BinaryToOctalConverter() {
    resetStack();
    int d;
    char b[MAX];
    printf("Enter the binary number:");
    scanf("%s", b);
    d = BtoD(b);
    DtoO(d);

}

void HexadecimalToOctalConverter(){
    resetStack();
    char hexa[MAX],Binary_Value[MAX];
    int i, n;
    printf("Enter a hexadecimal number:");
    scanf("%s",hexa);
    for (i = (int)strlen(hexa); i>=0; i-=1) {
        switch (hexa[i-1]) {
            case '0':
                push(0);push(0);push(0);push(0);
                break;
            case '1':
                push(1);push(0);push(0);push(0);
                break;
            case '2':
                push(0);push(1);push(0);push(0);
                break;
            case '3':
                push(1);push(1);push(0);push(0);
                break;
            case '4':
                push(0);push(0);push(1);push(0);
                break;
            case '5':
                push(1);push(0);push(1);push(0);
                break;
            case '6':
                push(0);push(1);push(1);push(0);
                break;
            case '7':
                push(1);push(1);push(1);push(0);
                break;
            case '8':
                push(0);push(0);push(0);push(1);
                break;
            case '9':
                push(1);push(0);push(0);push(1);
                break;
            case 'A':
                push(0);push(1);push(0);push(1);
                break;
            case 'B':
                push(1);push(1);push(0);push(1);
                break;
            case 'C':
                push(0);push(0);push(1);push(1);
                break;
            case 'D':
                push(1);push(0);push(1);push(1);
                break;
            case 'E':
                push(0);push(1);push(1);push(1);
                break;
            case 'F':
                push(1);push(1);push(1);push(1);
                break;
            default:;
        }
    }
    i = 0;
    while (Stack->top >= 0) {
        n = pop();
        if(n == 1){
            Binary_Value[i] = '1';
        } else{
            Binary_Value[i] = '0';
        }
        i++;
    }

    n = BtoD(Binary_Value);
    DtoO(n);
}

void HexadecimalToDecimalConverter(){
    resetStack();
    char hexa[MAX],Binary_Value[MAX];
    int i, n;
    printf("Enter a hexadecimal number:");
    scanf("%s",hexa);
    for (i = (int)strlen(hexa); i>=0; i-=1) {
        switch (hexa[i-1]) {
            case '0':
                push(0);push(0);push(0);push(0);
                break;
            case '1':
                push(1);push(0);push(0);push(0);
                break;
            case '2':
                push(0);push(1);push(0);push(0);
                break;
            case '3':
                push(1);push(1);push(0);push(0);
                break;
            case '4':
                push(0);push(0);push(1);push(0);
                break;
            case '5':
                push(1);push(0);push(1);push(0);
                break;
            case '6':
                push(0);push(1);push(1);push(0);
                break;
            case '7':
                push(1);push(1);push(1);push(0);
                break;
            case '8':
                push(0);push(0);push(0);push(1);
                break;
            case '9':
                push(1);push(0);push(0);push(1);
                break;
            case 'A':
                push(0);push(1);push(0);push(1);
                break;
            case 'B':
                push(1);push(1);push(0);push(1);
                break;
            case 'C':
                push(0);push(0);push(1);push(1);
                break;
            case 'D':
                push(1);push(0);push(1);push(1);
                break;
            case 'E':
                push(0);push(1);push(1);push(1);
                break;
            case 'F':
                push(1);push(1);push(1);push(1);
                break;
            default:;
        }
    }
    i = 0;
    while (Stack->top >= 0) {
        n = pop();
        if(n == 1){
            Binary_Value[i] = '1';
        } else{
            Binary_Value[i] = '0';
        }
        i++;
    }

    n = BtoD(Binary_Value);
    printf("\nDecimal Value is %d",n);
}

void HexadecimalToBinaryConverter() {
    resetStack();
    char hexa[MAX];
    int i, n;
    printf("Enter a hexadecimal number:");
    scanf("%s",hexa);
    for (i = (int)strlen(hexa); i>=0; i-=1) {
        switch (hexa[i-1]) {
            case '0':
                push(0);push(0);push(0);push(0);
                break;
            case '1':
                push(1);push(0);push(0);push(0);
                break;
            case '2':
                push(0);push(1);push(0);push(0);
                break;
            case '3':
                push(1);push(1);push(0);push(0);
                break;
            case '4':
                push(0);push(0);push(1);push(0);
                break;
            case '5':
                push(1);push(0);push(1);push(0);
                break;
            case '6':
                push(0);push(1);push(1);push(0);
                break;
            case '7':
                push(1);push(1);push(1);push(0);
                break;
            case '8':
                push(0);push(0);push(0);push(1);
                break;
            case '9':
                push(1);push(0);push(0);push(1);
                break;
            case 'A':
                push(0);push(1);push(0);push(1);
                break;
            case 'B':
                push(1);push(1);push(0);push(1);
                break;
            case 'C':
                push(0);push(0);push(1);push(1);
                break;
            case 'D':
                push(1);push(0);push(1);push(1);
                break;
            case 'E':
                push(0);push(1);push(1);push(1);
                break;
            case 'F':
                push(1);push(1);push(1);push(1);
                break;
            default:;
        }
    }
    while (Stack->top >= 0) {
        printf("%d", pop());
    }
}

void OctalToHexadecimalConverter() {
    resetStack();
    char Binary_Value[MAX];
    int octal,i,n;
    printf("Enter a octal number:");
    scanf("%d", &octal);
    for (i = octal; i != 0;) {
        n = i % 10;
        switch (n) {
            case 0:
                push(0);push(0);push(0);
                break;
            case 1:
                push(1);push(0);push(0);
                break;
            case 2:
                push(0);push(1);push(0);
                break;
            case 3:
                push(1);push(1);push(0);
                break;
            case 4:
                push(0);push(0);push(1);
                break;
            case 5:
                push(1);push(0);push(1);
                break;
            case 6:
                push(0);push(1);push(1);
                break;
            case 7:
                push(1);push(1);push(1);
                break;
            default:;
        }
        i = i / 10;
    }
    i=0;
    while (Stack->top >= 0) {
        n = pop();
        if(n == 0){
            Binary_Value[i] = '0';
        }else{
            Binary_Value[i] = '1';
        }
        i++;
    }
    n = BtoD(Binary_Value);
    DtoH(n);
}

void OctalToDecimalConverter() {
    resetStack();
    char Binary_Value[MAX];
    int octal, i, n;
    printf("Enter an octal number:");
    scanf("%d", &octal);
    for (i = octal; i != 0;) {
        n = i % 10;
        switch (n) {
            case 0:
                push(0);push(0);push(0);
                break;
            case 1:
                push(1);push(0);push(0);
                break;
            case 2:
                push(0);push(1);push(0);
                break;
            case 3:
                push(1);push(1);push(0);
                break;
            case 4:
                push(0);push(0);push(1);
                break;
            case 5:
                push(1);push(0);push(1);
                break;
            case 6:
                push(0);push(1);push(1);
                break;
            case 7:
                push(1);push(1);push(1);
                break;
            default:;
        }
        i = i / 10;
    }
    i=0;
    while (Stack->top >= 0) {
        n = pop();
        if(n == 0){
            Binary_Value[i] = '0';
        }else{
            Binary_Value[i] = '1';
        }
        i++;
    }
    n = BtoD(Binary_Value);
    printf("Decimal Value is %d",n);
}

void OctalToBinaryConverter() {
    resetStack();
    int octal, i, n;
    printf("Enter an octal number:");
    scanf("%d", &octal);
    for (i = octal; i != 0;) {
        n = i % 10;
        switch (n) {
            case 0:
                push(0);push(0);push(0);
                break;
            case 1:
                push(1);push(0);push(0);
                break;
            case 2:
                push(0);push(1);push(0);
                break;
            case 3:
                push(1);push(1);push(0);
                break;
            case 4:
                push(0);push(0);push(1);
                break;
            case 5:
                push(1);push(0);push(1);
                break;
            case 6:
                push(0);push(1);push(1);
                break;
            case 7:
                push(1);push(1);push(1);
                break;
            default:;
        }
        i = i / 10;
    }
    while (Stack->top >= 0) {
        printf("%d", pop());
    }
}

int main() {
    int ch1;
    do {system("cls");
        printf("Enter the operation you want to perform:\n\n1.Decimal to Binary\t\t2.Decimal to Octal"
               "\n\n3.Decimal to Hexadecimal\n\n4.Binary to Decimal\t\t5.Binary to Octal\n\n6.Binary to Hexadecimal\n\n7.Octal to Binary\t\t8.Octal to Decimal\n\n9.Octal to Hexadecimal"
               "\t\t10.Hexadecimal to Binary\n\n11.Hexadecimal to Decimal\t12.Hexadecimal to Octal\n\n0.Exit\n\nEnter your choice:");
        scanf("%d", &ch1);
        switch (ch1) {
            case 1:DecimaltoBinaryConvertor();
                break;
            case 2:DecimaltoOctalConvertor();
                break;
            case 3:DecimaltoHexadecimalConvertor();
                break;
            case 4:BinarytoDecimalConvertor();
                break;
            case 5:BinaryToOctalConverter();
                break;
            case 6:BinarytoHexadecimalConvertor();
                break;
            case 7:OctalToBinaryConverter();
                break;
            case 8:OctalToDecimalConverter();
                break;
            case 9:OctalToHexadecimalConverter();
                break;
            case 10:HexadecimalToBinaryConverter();
                break;
            case 11:HexadecimalToDecimalConverter();
                break;
            case 12:HexadecimalToOctalConverter();
                break;
            case 0:
                exit(0);
            default:;
        }
        printf("\nEnter 0 to exit or 1 to continue\n");
        scanf("%d",&ch1);
    }while(ch1!=0);
    return 0;
}