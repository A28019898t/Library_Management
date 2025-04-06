#include <stdio.h>
#include <string.h>

void intToString(int num, char* str) {
    int i = 0;
    int negative = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    if (num < 0) {
        negative = 1;
        num = -num;
    }

    while(num != 0) {
        str[i++] = (num % 10) + '0';
        num = num / 10;
    }

    str[i] = '\0';
    int start = 0;
    int end = i - 1;

    while (start < end) {
        int temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* getDate(int day, int month, int year) {
    char dayStr[2], monthStr[2], yearStr[4];
    char result[10];

    intToString(day, dayStr);
    intToString(month, monthStr);
    intToString(year, yearStr);

    strcat(result, dayStr);
    strcat(result, "/");
    strcat(result, monthStr);
    strcat(result, "/");
    strcat(result, yearStr);
    
    return result;
}

int main() {
    int num = 123;
    char str[100];

    intToString(123, str);

    printf("%s", getDate(12, 12, 2025));

    return 0;
}