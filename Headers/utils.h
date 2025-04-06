#ifndef UTILS_H
#define UTILS_H
// định nghĩa các màu cho chữ hiện thị trên console
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// Set màu cho chữ trên console
void setColor(int color);

// Set up console để hiện thị Tiếng Việt cho Console Windows(chỉ cho win) 
void setUTF8ConsoleWindow();

// chuyển đổi int thành string
void intToString(char* str, int num);

// kiểm tra chuỗi ký tự có là đại diện cho só không
int isNumber(char* str);

// Kiểm tra năm nhuận
int isLeapYear(int year);

// Kiểm tra có phải ngày hợp lệ
int isDate(int day, int month, int year);

// Lấy ngày tháng năm định dạng dd/mm/yyyy dưới định dạng string
void getDate(char* str, int day, int month, int year);

// Nhập ngày tháng năm
void inputDay(char* str);

// Lấy ngày hiện tại với định dạng string
void getToday(char* str);

// Chuyển chuổi char thành in thường
void convertToLower(char* source, char* destination);

// Hàm nhập dữ liệu string
void inputString(char* str, char* data, int size);

// Tìm chuỗi trong chuỗi mẫu
int findSubString(char* subStr, char* sourceStr);

// Tách định dạng ngày thành dạng chuỗi số nguyên dương có 3 thành phần (ngày, tháng, năm)
void convertDateToInt(char* date, int* day, int* month, int* year);

// Lấy ngày cần tìm cách k tháng cho trước
void getDateFromKMonths(char* destination, char* source, int numberOfMonth);

// Lấy ngày cần tìm cách k ngày cho trước
void getDateFromKDays(char* date, char* result, int kDays);

// Trừ hai ngày
int dateDifference(char* date1, char* date2);

// In dấu phẩy
char* addComma(int num);


#endif