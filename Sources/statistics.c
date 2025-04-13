#include <stdio.h>              // Thư viện chuẩn cho nhập/xuất dữ liệu

#include "..\Headers\data.h"    // File header chứa định nghĩa dữ liệu và mảng toàn cục

// 3. THỐNG KÊ

// 3.1. THỐNG KÊ TỔNG SỐ SÁCH TRONG THƯ VIỆN

void countTotalBooks() {        // Đếm tổng số sách trong kho (tổng STOCKS)
    int total = 0;              // Biến lưu tổng số sách
    for (int i = 0; i < NUMBER_OF_BOOKS; i++) { // Duyệt qua tất cả sách
        total += STOCKS[i];     // Cộng số lượng sách từ mảng STOCKS
    }
    printf("TONG SO SACH TRONG THU VIEN LA: %d\n", total); // In tổng số sách
}

// 3.2. THỐNG KÊ SỐ LƯỢNG SÁCH THEO THỂ LOẠI

void countBookByCategory() {    // Đếm số lượng sách theo từng thể loại
    int totals[MAX_GENRE]; // Mảng lưu số lượng sách cho mỗi thể loại (10 từ data.h)
    for (int i = 0; i < NUMBER_OF_GENRES; i++) { // Khởi tạo mảng totals
        totals[i] = 0;          // Gán giá trị ban đầu bằng 0
    }
    
    for (int i = 0; i < NUMBER_OF_BOOKS; i++) { // Duyệt qua tất cả sách
        totals[CATEGORIES[i]]++; // Tăng số lượng cho thể loại tương ứng trong GENRES_DB
    }
    
    for (int i = 0; i < NUMBER_OF_GENRES; i++) { // In kết quả thống kê
        printf("%s co so luong sach: %d\n", GENRES_DB[i], totals[i]); // In tên thể loại và số lượng
    }
}

// 3.3. THỐNG KÊ TỔNG SỐ ĐỘC GIẢ

void countTotalReaders() {      // Đếm tổng số độc giả trong hệ thống
    printf("Tong so doc gia: %d\n", NUMBER_OF_READERS); // In số lượng từ biến toàn cục
}

// 3.4. THỐNG KÊ SỐ LƯỢNG ĐỘC GIẢ THEO GIỚI TÍNH

void countTotalReadersByGender() { // Đếm số lượng độc giả theo giới tính
    int males = 0;              // Biến đếm độc giả nam
    int females = 0;            // Biến đếm độc giả nữ
    
    for (int i = 0; i < NUMBER_OF_READERS; i++) { // Duyệt qua tất cả độc giả
        if (GENDERS[i] == 1) {  // Nếu giới tính là Nam (1 trong GENDER_DB)
            males++;            // Tăng số lượng nam
        } else {                // Nếu giới tính là Nữ (0 trong GENDER_DB)
            females++;          // Tăng số lượng nữ
        }
    }
    
    printf("Tong so doc gia la nam: %d\n", males);   // In số độc giả nam
    printf("Tong so doc gia la nu: %d\n", females);  // In số độc giả nữ
}

// 3.5. THỐNG KÊ SỐ SÁCH ĐANG ĐƯỢC MƯỢN

void countTotalBorrowedBooks() { // Đếm tổng số sách đang được mượn
    printf("Tong so sach dang duoc muon: %d\n", NUMBER_OF_ISBN_BOOK); // In số lượng từ biến toàn cục
}

// 3.6. THỐNG KÊ DANH SÁCH ĐỘC GIẢ BỊ TRỄ HẠN

void listOverdueReaders() {     // Liệt kê danh sách độc giả trễ hạn (chưa triển khai)
    printf("Danh sach doc gia tre han:\n"); // Tiêu đề danh sách
    // TODO: Thêm logic kiểm tra ngày trả (BORROW_RETURN_DATE) so với ngày hiện tại
    printf("Chuc nang chua duoc trien khai\n"); // Thông báo tạm thời
}