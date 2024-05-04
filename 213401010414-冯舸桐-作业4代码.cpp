#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���������
int generateRandomNumber(int max) {
    return rand() % max + 1;
}

// ������������
char generateRandomOperator(char operators[], int numOperators) {
    return operators[rand() % numOperators];
}

// ��������������ʽ
void generateExpression(int numExpressions, int maxNumber, char operators[], int numOperators, int allowDecimal, int allowParentheses) {
    srand(time(NULL));
    int i;
    for (int i = 0; i < numExpressions; i++) {
        int num1 = generateRandomNumber(maxNumber);
        int num2 = generateRandomNumber(maxNumber);
        char op = generateRandomOperator(operators, numOperators);
        
        // �Ƿ���С��
        if (allowDecimal) {
            float decimalNum1 = num1 + (float)rand() / RAND_MAX;
            float decimalNum2 = num2 + (float)rand() / RAND_MAX;
            printf("%.2f %c %.2f = ", decimalNum1, op, decimalNum2);
        } else {
            printf("%d %c %d = ", num1, op, num2);
        }
        
        // �Ƿ�������
        if (allowParentheses && rand() % 2 == 0) {
            printf("(%d %c %d)", num1, op, num2);
        } else {
            printf("%d %c %d", num1, op, num2);
        }
        
        printf("\n");
    }
}

int main() {
    int numExpressions, maxNumber, allowDecimal, allowParentheses;
    char operators[] = {'+', '-', '*', '/'};
    int numOperators = sizeof(operators) / sizeof(operators[0]);
    
    printf("��������Ŀ������");
    scanf("%d", &numExpressions);
    printf("�������������");
    scanf("%d", &maxNumber);
    printf("�Ƿ�����С����(1: �ǣ�0: ��)��");
    scanf("%d", &allowDecimal);
    printf("�Ƿ��������ţ�(1: �ǣ�0: ��)��");
    scanf("%d", &allowParentheses);
    
    generateExpression(numExpressions, maxNumber, operators, numOperators, allowDecimal, allowParentheses);
    
    return 0;
}
