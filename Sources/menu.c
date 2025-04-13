#include <stdio.h>              // Thư viện chuẩn cho nhập/xuất dữ liệu
#include <stdlib.h>             // Thư viện hỗ trợ lệnh system (cls, pause)

#include "..\Headers\reader.h"  // File header chứa hàm quản lý độc giả
#include "..\Headers\book.h"    // File header chứa hàm quản lý sách
#include "..\Headers\statistics.h" // File header chứa hàm thống kê
#include "..\Headers\borrowReturn.h" // File header chứa hàm quản lý mượn trả

// Hàm hiển thị menu

void print5Choices(char* input[], void f1(), void f2(), void f3(), void f4(), void f5()) { // Hiển thị menu 5 lựa chọn
    int choice;                 // Biến lưu lựa chọn người dùng
    
    do {
        system("cls");          // Xóa màn hình console (Windows)
        printf("\n");           // Xuống dòng để đẹp giao diện
        printf("%s\n", input[0]); // In tiêu đề menu
        for (int i = 1; i < 6; i++) { // In 5 lựa chọn
            printf("[%d]: %s\n", i, input[i]); // In số thứ tự và nội dung
        }
        printf("[0]: %s\n", input[6]); // In lựa chọn thoát
        
        printf("Nhap lua chon [?]: "); // Yêu cầu nhập lựa chọn
        scanf("%d", &choice);   // Nhập lựa chọn
        getchar();              // Xóa ký tự thừa trong bộ đệm
        
        system("cls");          // Xóa màn hình trước khi thực thi
        switch (choice) {       // Xử lý lựa chọn
            case 1: f1(); break; // Gọi hàm 1
            case 2: f2(); break; // Gọi hàm 2
            case 3: f3(); break; // Gọi hàm 3
            case 4: f4(); break; // Gọi hàm 4
            case 5: f5(); break; // Gọi hàm 5
            case 0: break;       // Thoát menu
            default: printf("Nhap sai lua chon. Moi ban nhap lai\n"); // Thông báo lỗi
        }

    } while (choice != 0);      // Lặp lại cho đến khi chọn thoát
}

void print6Choices(char* input[], void f1(), void f2(), void f3(), void f4(), void f5(), void f6()) { // Hiển thị menu 6 lựa chọn
    int choice;                 // Biến lưu lựa chọn người dùng
    
    do {
        system("cls");          // Xóa màn hình console (Windows)
        printf("\n");           // Xuống dòng để đẹp giao diện
        printf("%s\n", input[0]); // In tiêu đề menu
        for (int i = 1; i < 7; i++) { // In 6 lựa chọn
            printf("[%d]: %s\n", i, input[i]); // In số thứ tự và nội dung
        }
        printf("[0]: %s\n", input[7]); // In lựa chọn thoát
        
        printf("Nhap lua chon [?]: "); // Yêu cầu nhập lựa chọn
        scanf("%d", &choice);   // Nhập lựa chọn
        getchar();              // Xóa ký tự thừa trong bộ đệm
        
        system("cls");          // Xóa màn hình trước khi thực thi
        switch (choice) {       // Xử lý lựa chọn
            case 1: f1(); break; // Gọi hàm 1
            case 2: f2(); break; // Gọi hàm 2
            case 3: f3(); break; // Gọi hàm 3
            case 4: f4(); break; // Gọi hàm 4
            case 5: f5(); break; // Gọi hàm 5
            case 6: f6(); break; // Gọi hàm 6
            case 0: break;      // Thoát menu
            default: printf("Nhap sai lua chon, Moi ban nhap lai\n"); // Thông báo lỗi
        }
        system("pause");        // Tạm dừng để xem kết quả (Windows)
    } while (choice != 0);      // Lặp lại cho đến khi chọn thoát
}

// Menu con

void readerMenu() {             // Hiển thị menu quản lý độc giả
    char* ReadersManagement[8] = { // Mảng chứa nội dung menu
        "QUAN LY DOC GIA",         // Tiêu đề
        "Xem danh sach doc gia trong thu vien", // Lựa chọn 1
        "Them doc gia",            // Lựa chọn 2
        "Chinh sua thong tin mot doc gia", // Lựa chọn 3
        "Xoa thong tin mot doc gia", // Lựa chọn 4
        "Tim kiem doc gia theo CMND", // Lựa chọn 5
        "Tim kiem doc gia theo ho ten", // Lựa chọn 6
        "Quay lai"                // Lựa chọn thoát
    };
    print6Choices(ReadersManagement, viewAllReaders, addReader, editReaderInfor, deleteReader, searchReaderByCIC, searchReaderByName); // Gọi hàm hiển thị menu
}

void bookMenu() {               // Hiển thị menu quản lý sách
    char* booksManagement[8] = { // Mảng chứa nội dung menu
        "QUAN LY SACH",           // Tiêu đề
        "Xem danh sach cac sach trong thu vien", // Lựa chọn 1
        "Them sach",              // Lựa chọn 2
        "Chinh sua thong tin mot quyen sach", // Lựa chọn 3
        "Xoa thong tin sach",     // Lựa chọn 4
        "Tim kiem sach theo ISBN", // Lựa chọn 5
        "Tim kiem sach theo ten sach", // Lựa chọn 6
        "Quay lai"               // Lựa chọn thoát
    };
    print6Choices(booksManagement, viewAllBooks, addBook, editInfoBook, deleteBook, searchBookByISBN, searchBookByTitle); // Gọi hàm hiển thị menu
}

void statisticsMenu() {         // Hiển thị menu thống kê
    char* statisticsManagement[8] = { // Mảng chứa nội dung menu
        "CAC THONG KE CO BAN",    // Tiêu đề
        "Thong ke so luong sach trong thu vien", // Lựa chọn 1
        "Thong ke so luong sach theo the loai", // Lựa chọn 2
        "Thong ke so luong doc gia", // Lựa chọn 3
        "Thong ke so luong doc gia theo gioi tinh", // Lựa chọn 4
        "Thong ke so sach dang duoc muon", // Lựa chọn 5
        "Thong ke danh sach doc gia bi tre han", // Lựa chọn 6
        "Quay lai"               // Lựa chọn thoát
    };
    print6Choices(statisticsManagement, countTotalBooks, countBookByCategory, countTotalReaders, countTotalReadersByGender, countTotalBorrowedBooks, listOverdueReaders); // Gọi hàm hiển thị menu
}

// Menu chính

void mainMenu() {               // Hiển thị menu chính của hệ thống
    char* libraryManagement[7] = { // Mảng chứa nội dung menu
        "QUAN LY THU VIEN",       // Tiêu đề
        "Quan ly doc gia",        // Lựa chọn 1
        "Quan ly sach",           // Lựa chọn 2
        "Lap phieu muon sach",    // Lựa chọn 3
        "Lap phieu tra sach",     // Lựa chọn 4
        "Cac thong ke co ban",    // Lựa chọn 5
        "Thoat"                  // Lựa chọn thoát
    };
    print5Choices(libraryManagement, readerMenu, bookMenu, createBorrowTicket, createReturnTicket, statisticsMenu); // Gọi hàm hiển thị menu
}