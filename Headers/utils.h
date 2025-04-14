#ifndef UTILS_H                  // Ngăn chặn việc bao gồm file header nhiều lần (include guard)
#define UTILS_H                  // Định nghĩa macro đánh dấu file header đã được bao gồm

// Định nghĩa mã màu ANSI cho console (dùng trên hệ điều hành hỗ trợ ANSI như Linux)
#define RESET   "\033[0m"        // Đặt lại màu mặc định
#define RED     "\033[31m"       // Màu đỏ
#define GREEN   "\033[32m"       // Màu xanh lá
#define YELLOW  "\033[33m"       // Màu vàng
#define BLUE    "\033[34m"       // Màu xanh dương

// Hàm tiện ích chung

void setColor(int color);        // Đặt màu chữ trên console dựa trên mã màu (chưa triển khai đầy đủ)

void setUTF8ConsoleWindow();     // Cài đặt console hỗ trợ UTF-8 trên Windows (chưa triển khai đầy đủ)

void intToString(char* str, int num); // Chuyển số nguyên thành chuỗi

void intToPaddedString(char* dest, int num, int width); // Chuyển số thành chuỗi với độ dài cố định (padding 0)

int isNumber(char* str);         // Kiểm tra chuỗi có chỉ chứa số không, trả về 1 nếu đúng, 0 nếu sai

int findNumber(int arr[], int size, int num);

// Hàm xử lý ngày tháng

int isLeapYear(int year);        // Kiểm tra năm nhuận, trả về 1 nếu là năm nhuận, 0 nếu không

int isDate(int day, int month, int year); // Kiểm tra ngày hợp lệ, trả về 1 nếu đúng, 0 nếu sai

void getDate(char* str, int day, int month, int year); // Tạo chuỗi ngày dạng DD/MM/YYYY từ ngày, tháng, năm

void inputDay(char* str);        // Nhập và kiểm tra ngày hợp lệ, lưu vào chuỗi dạng DD/MM/YYYY

void getToday(char* str);        // Lấy ngày hiện tại dạng DD/MM/YYYY dựa trên thời gian hệ thống

void convertDateToInt(char* date, int* day, int* month, int* year); // Chuyển chuỗi DD/MM/YYYY thành số nguyên (ngày, tháng, năm)

void getDateFromKMonths(char* destination, char* source, int numberOfMonth); // Tính ngày sau k tháng từ ngày nguồn

void getDateFromKDays(char* date, char* result, int kDays); // Tính ngày sau k ngày từ ngày nguồn

int dateDifference(char* date1, char* date2); // Tính khoảng cách (số ngày) giữa hai ngày dạng DD/MM/YYYY

// Hàm xử lý chuỗi

void convertToLower(char* source, char* destination); // Chuyển chuỗi nguồn thành chữ thường, lưu vào đích

void inputString(char* str, char* data, int size); // Nhập chuỗi từ người dùng với thông báo và giới hạn kích thước

int findSubString(char* subStr, char* sourceStr); // Tìm vị trí chuỗi con trong chuỗi nguồn, trả về -1 nếu không thấy

// Hàm hỗ trợ nhập liệu

int findItemByStr(char* str, char* arr[], int rows); // Tìm và chọn mục từ mảng chuỗi, trả về chỉ số hoặc -1 nếu không thấy

int inputFromSelections(char* str, char* arr[], int size); // Hiển thị danh sách và nhập lựa chọn, trả về chỉ số (0-based)

int removeElementInArray(int arr[], int size, int postion);

#endif                           // Kết thúc include guard