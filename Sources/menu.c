#include <stdio.h>
#include <stdlib.h>

#include "..\Headers\reader.h"
#include "..\Headers\book.h"
#include "..\Headers\statistics.h"
#include "..\Headers\borrowReturn.h"

void print5Choices(char* input[], void f1(), void f2(), void f3(), void f4(), void f5()) {
    
    int choice;
    
    do {
        system("cls");
        printf("\n");
        printf("%s\n", input[0]);
        for (int i = 1; i < 6; i++) {
            printf("[%d]: %s \n", i, input[i]);   
        }

        printf("[0]: %s \n", input[6]);

        printf("Nhap lua chon [?]: ");
        scanf("%d", &choice);
        
        system("cls");
        switch(choice) {
            case 1:
                f1();
                break;
            case 2:
                f2();
                break;
            case 3:
                f3();
                break;
            case 4:
                f4();
                break;
            case 5:
                f5();
                break;
            case 0:
                choice = 0;
                break;
            default:
                printf("Nhap sai lua chon, Moi ban nhap lai\n");
        }
    } while (choice != 0);
}

void print6Choices(char* input[], void f1(), void f2(), void f3(), void f4(), void f5(), void f6()) {
    
    int choice;
    
    do {
        system("cls");
        printf("\n");
        printf("%s\n", input[0]);
        for (int i = 1; i < 7; i++) {
            printf("[%d]: %s \n", i, input[i]);   
        }

        printf("[0]: %s \n", input[7]);

        printf("Nhap lua chon [?]: ");
        scanf("%d", &choice);
        
        system("cls");
        switch(choice) {
            case 1:
                f1();
                break;
            case 2:
                f2();
                break;
            case 3:
                f3();
                break;
            case 4:
                f4();
                break;
            case 5:
                f5();
                break;
            case 6:
                f6();
                break;
            case 0:
                choice = 0;
                break;
            default:
                printf("Nhap sai lua chon, Moi ban nhap lai\n");
        }
        system("pause");
    } while (choice != 0);
}


// Hiển thị menu đọc giả
void readerMenu() {
    char* ReadersManagement[8] = {"QUAN LY DOC GIA", 
                                        "Xem danh sach doc gia trong thu vien", 
                                        "Them doc gia", 
                                        "Chinh sua thong tin mot doc gia", 
                                        "Xoa thong tin mot doc gia", 
                                        "Tim kiem doc gia theo CMND", 
                                        "Tim kiem doc gia theo ho ten", 
                                        "Quay lai"};
    print6Choices(ReadersManagement,viewAllReaders, addReader, editReaderInfor, deleteReader, searchReaderByCIC, searchReaderByName);   
}

// Hiển thị menu sách
void bookMenu() {
    char* booksManagement[8] = {"QUAN LY SACH", 
        "Xem danh sach cac sach trong thu vien", 
        "Them sach", 
        "Chinh sua thong tin mot quyen sach", 
        "Xoa thong tin sach", 
        "Tim kiem sach theo ISBN", 
        "Tim kiem sach theo ten sach",
        "Quay lai"};
    print6Choices(booksManagement,viewAllBooks, addBook, editInfoBook, deleteBook, searchBookByISBN, searchBookByTitle);
}

// Hiển thị menu thống kê
void statisticsMenu() {
    char* statisticsManagement[8] = {"CAC THONG KE CO BAN", 
                                            "Thong ke so luong sach trong thu vien", 
                                            "Thong ke so luong sach theo the loai", 
                                            "Thong ke so luong doc gia",
                                            "Thong ke so luong doc gia theo gioi tinh",
                                            "Thong ke so sach dang duoc muon", 
                                            "Thong ke danh sach doc gia bi tre han", 
                                            "Quay lai"};
    print6Choices(statisticsManagement,countTotalBooks, countBookByCategory, countTotalReaders, countTotalReadersByGender, countTotalBorrowedBooks, listOverdueReaders);
}

// Hiển thị menu chính
void mainMenu() {
    char* libraryManagement[7] = {"QUAN LY THU VIEN", 
        "Quan ly doc gia", 
        "Quan ly sach", 
        "Lap phieu muon sach", 
        "Lap phieu tra sach", 
        "Cac thong ke co ban", 
        "Thoat"};

    // dùng hàm printInput đã tạo trong Utils.h để hiển thị màn hình nhập lựa chọn
    print5Choices(libraryManagement, readerMenu, bookMenu, createBorrowTicket, createReturnTicket, statisticsMenu);
}
