#include <stdio.h>              // Thư viện chuẩn cho nhập/xuất dữ liệu
#include <string.h>             // Thư viện xử lý chuỗi ký tự
#include <time.h>               // Thư viện xử lý thời gian (time_t)
#include <ctype.h>              // Thư viện xử lý ký tự (tolower)

#include "..\Headers\data.h"    // File header chứa định nghĩa dữ liệu và mảng toàn cục

int MONTHS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Số ngày trong 12 tháng (không nhuận)

// Hàm tiện ích chung

void setColor(int color) {      // Đặt màu chữ trên console (chưa triển khai)
    // TODO: Thêm logic thay đổi màu trên Windows/Linux nếu cần
}

void setUTF8ConsoleWindow() {   // Cài đặt console hỗ trợ UTF-8 trên Windows (chưa triển khai)
    // TODO: Thêm logic dùng SetConsoleOutputCP(65001) cho Windows
}

void intToString(char* str, int num) { // Chuyển số nguyên thành chuỗi
    sprintf(str, "%d", num);    // Dùng sprintf để định dạng số thành chuỗi
}

void intToPaddedString(char* dest, int num, int width) { // Chuyển số thành chuỗi với độ dài cố định (padding 0)
    sprintf(dest, "%0*d", width, num); // %0*d: thêm số 0 bên trái, width là độ dài
}

int isNumber(char* str) {       // Kiểm tra chuỗi chỉ chứa số
    for (int i = 0; i < strlen(str); i++) { // Duyệt qua từng ký tự
        if (str[i] < '0' || str[i] > '9') return 0; // Không phải số (ASCII 48-57)
    }
    return 1;                   // Chuỗi toàn số
}

// Hàm xử lý ngày tháng

int isLeapYear(int year) {      // Kiểm tra năm nhuận
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); // Điều kiện năm nhuận
}

int isDate(int day, int month, int year) { // Kiểm tra ngày hợp lệ
    if (isLeapYear(year)) MONTHS[1] = 29; // Cập nhật tháng 2 nếu năm nhuận
    if (day < 1 || day > MONTHS[month - 1]) return 0; // Ngày không hợp lệ
    if (month < 1 || month > 12) return 0; // Tháng không hợp lệ
    if (year <= 0) return 0;    // Năm không hợp lệ
    return 1;                   // Ngày hợp lệ
}

void getDate(char* str, int day, int month, int year) { // Tạo chuỗi ngày dạng DD/MM/YYYY
    char dayStr[3], monthStr[3], yearStr[5]; // Chuỗi tạm cho ngày, tháng, năm
    intToString(dayStr, day);   // Chuyển ngày thành chuỗi
    intToString(monthStr, month); // Chuyển tháng thành chuỗi
    intToString(yearStr, year); // Chuyển năm thành chuỗi
    
    str[0] = '\0';              // Khởi tạo chuỗi rỗng
    if (day < 10) strcat(str, "0"); // Thêm 0 nếu ngày < 10
    strcat(str, dayStr);        // Nối ngày
    strcat(str, "/");           // Nối dấu /
    if (month < 10) strcat(str, "0"); // Thêm 0 nếu tháng < 10
    strcat(str, monthStr);      // Nối tháng
    strcat(str, "/");           // Nối dấu /
    strcat(str, yearStr);       // Nối năm
}

void inputDay(char* date) {     // Nhập và kiểm tra ngày hợp lệ, trả về chuỗi DD/MM/YYYY
    int day, month, year;       // Biến lưu ngày, tháng, năm
    int valid;                  // Biến kiểm tra tính hợp lệ
    do {
        printf("\tNhap ngay: "); scanf("%d", &day); // Nhập ngày
        printf("\tNhap thang: "); scanf("%d", &month); // Nhập tháng
        printf("\tNhap nam: "); scanf("%d", &year); // Nhập năm
        valid = isDate(day, month, year); // Kiểm tra hợp lệ
        if (!valid) printf("Ngay, thang, nam khong hop le\n"); // Thông báo lỗi
    } while (!valid);           // Lặp lại nếu không hợp lệ
    getDate(date, day, month, year); // Tạo chuỗi ngày
}

void getToday(char* str) {      // Lấy ngày hiện tại dạng DD/MM/YYYY
    time_t t = time(NULL);      // Lấy thời gian hiện tại (giây từ 1/1/1970)
    int year = 1970;            // Năm bắt đầu
    long int days = t / 86400 + 1; // Số ngày từ 1970 (cộng 1 để sửa lỗi thiếu ngày)
    
    while (days >= (isLeapYear(year) ? 366 : 365)) { // Tính năm
        days -= isLeapYear(year) ? 366 : 365; // Trừ số ngày của năm
        year++;                 // Tăng năm
    }
    if (isLeapYear(year)) MONTHS[1] = 29; // Cập nhật tháng 2 nếu năm nhuận
    
    int month = 1;              // Bắt đầu từ tháng 1
    while (days > MONTHS[month - 1]) { // Tính tháng
        days -= MONTHS[month - 1]; // Trừ số ngày của tháng
        month++;                // Tăng tháng
    }
    getDate(str, days, month, year); // Tạo chuỗi ngày
}

void convertDateToInt(char* date, int* day, int* month, int* year) { // Chuyển chuỗi DD/MM/YYYY thành số
    char dayStr[3] = {date[0], date[1], '\0'}; // Lấy 2 ký tự ngày
    char monthStr[3] = {date[3], date[4], '\0'}; // Lấy 2 ký tự tháng
    char yearStr[5];            // Chuỗi năm (4 ký tự + '\0')
    int i = 0;
    for (int j = 6; j < strlen(date); j++) { // Lấy ký tự năm từ vị trí 6
        yearStr[i++] = date[j];
    }
    yearStr[i] = '\0';          // Kết thúc chuỗi năm
    
    sscanf(dayStr, "%d", day);  // Chuyển ngày thành số
    sscanf(monthStr, "%d", month); // Chuyển tháng thành số
    sscanf(yearStr, "%d", year); // Chuyển năm thành số
}

void getDateFromKMonths(char* destination, char* source, int numberOfMonth) { // Tính ngày sau k tháng
    int day, month, year;       // Biến lưu ngày, tháng, năm
    convertDateToInt(source, &day, &month, &year); // Chuyển chuỗi ngày thành số
    
    year += numberOfMonth / 12; // Tăng năm dựa trên số tháng
    month += numberOfMonth % 12; // Tăng tháng
    if (month > 12) {           // Nếu vượt 12 tháng
        month -= 12;            // Giảm tháng về khoảng 1-12
        year++;                 // Tăng thêm 1 năm
    }
    if (day > MONTHS[month - 1]) day = MONTHS[month - 1]; // Điều chỉnh ngày nếu vượt giới hạn
    
    getDate(destination, day, month, year); // Tạo chuỗi ngày kết quả
}

void getDateFromKDays(char* date, char* result, int kDays) { // Tính ngày sau k ngày
    int day, month, year;       // Biến lưu ngày, tháng, năm
    convertDateToInt(date, &day, &month, &year); // Chuyển chuỗi ngày thành số
    
    if (isLeapYear(year)) MONTHS[1] = 29; // Cập nhật tháng 2 nếu năm nhuận
    
    day += kDays;               // Cộng số ngày
    while (day > MONTHS[month - 1]) { // Nếu vượt số ngày trong tháng
        day -= MONTHS[month - 1]; // Trừ đi số ngày của tháng hiện tại
        if (month == 12) {      // Nếu là tháng 12
            month = 1;          // Quay lại tháng 1
            year++;             // Tăng năm
            if (isLeapYear(year)) MONTHS[1] = 29; // Cập nhật tháng 2 nếu năm mới nhuận
        } else {                // Nếu không phải tháng 12
            month++;            // Tăng tháng
        }
    }
    getDate(result, day, month, year); // Tạo chuỗi ngày kết quả
}

// Hàm xử lý chuỗi

void convertToLower(char* source, char* destination) { // Chuyển chuỗi thành chữ thường
    int i;
    for (i = 0; i < strlen(source); i++) { // Duyệt qua từng ký tự
        destination[i] = tolower(source[i]); // Chuyển thành chữ thường
    }
    destination[i] = '\0';      // Kết thúc chuỗi
}

void inputString(char* str, char* data, int size) { // Nhập chuỗi từ người dùng
    printf("%s", str);          // In thông báo yêu cầu
    fgets(data, size, stdin);   // Nhập chuỗi
    data[strcspn(data, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
}

int findSubString(char* subStr, char* sourceStr) { // Tìm vị trí chuỗi con trong chuỗi nguồn
    int subStrLen = strlen(subStr); // Độ dài chuỗi con
    int sourceStrLen = strlen(sourceStr); // Độ dài chuỗi nguồn
    
    for (int i = 0; i <= sourceStrLen - subStrLen; i++) { // Duyệt qua các vị trí có thể
        if (strncmp(&sourceStr[i], subStr, subStrLen) == 0) { // So sánh chuỗi con
            return i;           // Trả về vị trí đầu tiên tìm thấy
        }
    }
    return -1;                  // Trả về -1 nếu không tìm thấy
}

// Hàm hỗ trợ nhập liệu

int findItemByStr(char* str, char* arr[], int rows) { // Tìm và chọn mục từ mảng chuỗi
    char source[20];            // Chuỗi nhập vào
    char des[20];               // Chuỗi chữ thường của source
    int saveIndex[20];          // Mảng lưu chỉ số các mục tìm thấy
    int index = 0;              // Số lượng mục tìm thấy
    
    printf("%s", str);          // In thông báo yêu cầu
    fgets(source, sizeof(source), stdin); // Nhập chuỗi
    source[strcspn(source, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
    
    convertToLower(source, des); // Chuyển chuỗi nhập vào thành chữ thường
    
    for (int i = 0; i < rows; i++) { // Duyệt qua mảng chuỗi
        char temp[20];          // Chuỗi tạm lưu mục chữ thường
        convertToLower(arr[i], temp); // Chuyển mục thành chữ thường
        if (findSubString(des, temp) != -1) { // Kiểm tra chuỗi con
            saveIndex[index++] = i; // Lưu chỉ số mục
            printf("[%d]: %s\n", index, arr[i]); // In số thứ tự và mục
        }
    }
    
    if (index == 0) return -1;  // Trả về -1 nếu không tìm thấy
    int choice;                 // Lựa chọn của người dùng
    printf("Chon: ");           // Yêu cầu chọn
    scanf("%d", &choice);       // Nhập lựa chọn
    return saveIndex[choice - 1]; // Trả về chỉ số mục được chọn
}

int inputFromSelections(char* str, char* arr[], int size) { // Nhập lựa chọn từ danh sách
    int choice;                 // Lựa chọn của người dùng
    printf("%s\n", str);        // In thông báo yêu cầu
    
    for (int i = 0; i < size; i++) { // Hiển thị danh sách lựa chọn
        printf("[%d]: %s\n", i + 1, arr[i]); // In số thứ tự và mục
    }
    
    do {                        // Lặp để kiểm tra lựa chọn hợp lệ
        printf("Nhap lua chon [?]: "); // Yêu cầu nhập
        scanf("%d", &choice);   // Nhập lựa chọn
        getchar();              // Xóa ký tự thừa
        if (choice < 1 || choice > size) { // Kiểm tra hợp lệ
            printf("Nhap sai lua chon. Moi nhap lai\n"); // Thông báo lỗi
        }
    } while (choice < 1 || choice > size); // Lặp lại nếu không hợp lệ
    
    return choice - 1;          // Trả về chỉ số mục (bắt đầu từ 0)
}

int removeElementInArray(int arr[], int size, int postion) {
    if (postion > size - 1) {
        return -1;
    }

    for (int i = postion; i < size -1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}