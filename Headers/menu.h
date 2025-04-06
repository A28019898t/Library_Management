#ifndef MENU_H
#define MENU_H


// Hàm để in các lựa chọn: 5 lựa chọn
void print5Choices(char* input[], void f1(), void f2(), void f3(), void f4(), void f5());
// Hàm để in các lựa chọn: 6 lựa chọn
void print6Choices(char* input[], void f1(), void f2(), void f3(), void f4(), void f5(), void f6());

// Hiển thị menu đọc giả
void readerMenu();

// Hiển thị menu sách
void bookMenu();

// Hiển thị menu thống kê
void statisticsMenu();

// Hiển thị menu chính
void mainMenu();


#endif