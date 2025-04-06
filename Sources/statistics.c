#include <stdio.h>

#include "..\Headers\data.h"

// THỐNG KÊ SỐ LƯỢNG SÁCH TRONG THƯ VIỆN 
void countTotalBooks() {
    int total = 0;

    for (int i = 0; i < NUMBER_OF_BOOKS; i++) {
        total += STOCKS[i];
    }
    printf("TONG SO SACH TRONG THU VIEN LA: %d\n", total);
}

// THỐNG KÊ SỐ LƯỢNG SÁCH THEO THỂ LOẠI 
void countBookByCategory(){
    int totals[10]; // dựa vào số thể loại trong data
    for (int i = 0; i < 10; i++)  {
        totals[i] = 0;
    }

    for (int i = 0; i < NUMBER_OF_BOOKS; i++) {
        totals[CATEGORIES[i]]++;
        printf("%d\n", totals[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("%s co so luong sach: %d\n", GENRES[i], totals[i]);
    }
}

// THỐNG KÊ SỐ LƯỢNG ĐỘC GIẢ
void countTotalReaders(){
    printf("Tong so doc gia: %d\n", NUMBER_OF_READERS);
}

// THỐNG KÊ SỐ LƯỢNG ĐỘC GIẢ THEO GIỚI TÍNH
void countTotalReadersByGender(){
    int males = 0;
    int females = 0;

    for (int i = 0; i < NUMBER_OF_READERS; i++) {
        if (GENDERS[i] == 1) {
            males++;
        } else {
            females++;
        }
    }

    printf("Tong so doc gia la nam: %d\n", males);
    printf("Tong so doc gia la nu: %d\n", females);
}

// THỐNG KÊ SỐ SÁCH ĐANG ĐƯỢC MƯỢN
void countTotalBorrowedBooks(){\
    printf("Tong so sach dang duoc muon: %d\n", NUMBER_OF_ISBN_BOOK);
}

// THỐNG KÊ DANH SÁCH ĐỘC GIẢ BỊ TRỄ HẠNs
void listOverdueReaders(){
    printf("listOverdueReaders");
}