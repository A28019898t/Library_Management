#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "..\Headers\data.h"

int MONTHS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Set màu cho chữ trên console
void setColor(int color) {

}

// Set up console để hiện thị Tiếng Việt cho Console Windows(chỉ cho win) 
void setUTF8ConsoleWindow() {

}

// chuyển đổi int thành string
void intToString(char* str, int num) {
    sprintf(str, "%d", num);
}

// kiểm tra chuỗi ký tự có là đại diện cho só không
int isNumber(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < 48 || str[i] > 57) return 0; // trong ascii/ unicode thì mã của 0-9 <-> 48-57
    }

    return 1;
}

// Kiểm tra năm nhuận
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return 1;
    return 0;
}

// Kiểm tra có phải ngày hợp lệ
int isDate(int day, int month, int year)  {
    if (isLeapYear(year)) {
        MONTHS[1] = 29;
    }
    if (day < 1 || day > 31 || day > MONTHS[month - 1]) return 0;
    if (month < 1 || month > 12) return 0;
    if (year <= 0) return 0;

    return 1;
}

// Lấy ngày tháng năm định dạng dd/mm/yyyy dưới định dạng string
void getDate(char* str, int day, int month, int year) {
    char dayStr[3];
    char MONTHStr[3];
    char yearStr[5];

    // chuyển đổi ngày sang chuỗi
    intToString(dayStr, day);
    intToString(MONTHStr, month);
    intToString(yearStr, year);

    str[0] = '\0'; 

    if (day / 10) {
        strcat(str, dayStr);
    } else {
        strcat(str, "0");
        strcat(str, dayStr);
    }

        strcat(str, "/");

    if (month / 10) {
        strcat(str, MONTHStr);
    } else {
        strcat(str, "0");
        strcat(str, MONTHStr);
        
    }

    strcat(str, "/");
        
    strcat(str, yearStr);
}

// Nhập ngày tháng năm
void inputDay(char* date) {
    int day, month, year;
    int valid = 1;
    do {

        printf("Nhap ngay: ");
        scanf("%d", &day);
        printf("Nhap thang: ");
        scanf("%d", &month);
        printf("Nhap nam: ");
        scanf("%d", &year);
        valid = isDate(day, month, year);
        if(!valid) {
            printf("Ngay, thang, nam khong hop le");
        }

    } while (!valid);

    getDate(date, day, month, year); // định dạng ngày cho ngày sinh
    
}

// Lấy ngày hiện tại với định dạng string
void getToday(char* str) {
    time_t t = time(NULL);

    int year = 1970;
    long int days = t / 86400 + 1; // không hiểu sao khi tính nó bị thiếu 01 ngày

    while(days >= ((isLeapYear(year)) ? 366 : 365)) {
        days -= isLeapYear(year) ? 366 : 365;
    
        year++;
    }

    if (isLeapYear(year)) {
        MONTHS[1] = 29;
    }


    int month = 1;
    while(days > MONTHS[month - 1]) {
        days -= MONTHS[month - 1];
        month++;
    }
    
    getDate(str, days, month, year);
}


// Chuyển chuổi char thành in thường
void convertToLower(char* source, char* destination) {
    for (int i = 0; i < strlen(source); i++) {
        destination[i] = tolower(source[i]);
    }
}

// Hàm nhập dữ liệu string
void inputString(char* str, char* data, int size) {
    printf("%s", str);

    fgets(data, size, stdin);
    data[strcspn(data, "\n")] = '\0';
}

// Tìm chuỗi trong chuỗi mẫu
int findSubString(char* subStr, char* sourceStr) {
    int subStrLen = strlen(subStr);
    int sourceStrlen = strlen(sourceStr);

    for (int i = 0; i <= sourceStrlen - subStrLen; i++) {
        
        if (strncmp(&sourceStr[i], subStr, subStrLen) == 0) {
            return i;
        }
    }

    return - 1;
}

// Tách định dạng ngày thành dạng chuỗi số nguyên dương có 3 thành phần (ngày, tháng, năm)
void convertDateToInt(char* date, int* day, int* month, int* year) {

    char dayStr[3];
    dayStr[0] = date[0];
    dayStr[1] = date[1];
    dayStr[2] = '\0';



    char monthStr[3];
    monthStr[0] = date[3];
    monthStr[1] = date[4];
    monthStr[2] = '\0';

    char yearStr[5];
    int index = 0;
    for (int i = 6; i < strlen(date); i++) {
        yearStr[index++] = date[i];
    }
    yearStr[index] = '\0';

    sscanf(dayStr, "%d", day); // tính sau
    sscanf(monthStr, "%d", month); // tính sau
    sscanf(yearStr, "%d", year);
}

// Lấy ngày cần tìm cách k tháng cho trước
void getDateFromKMonths(char* destination, char* source, int numberOfMonth) {
    int day, month, year;

    convertDateToInt(source, &day, &month, &year);

    year += 4;

    getDate(destination, day, month, year);
} 

// Lấy ngày cần tìm cách k ngày cho trước
void getDateFromKDays(char* date, char* result, int kDays) {
    int day, month, year;

    convertDateToInt(date, &day, &month, &year);

    if (isLeapYear(year)) {
        MONTHS[1] = 29; // Năm nhuận
    }

    if (day + kDays <= MONTHS[month - 1]) {
        day = day + kDays;
    } else {

        if (month == 12) {
            month = 1;
            year++;
        } else {
            month++;
        }
        day = day + kDays - MONTHS[month - 1];
    }

    getDate(result, day, month, year);
}