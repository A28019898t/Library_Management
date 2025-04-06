#ifndef STATISTICS_H
#define STATISTICS_H

// THỐNG KÊ SỐ LƯỢNG SÁCH TRONG THƯ VIỆN 
void countTotalBooks();

// THỐNG KÊ SỐ LƯỢNG SÁCH THEO THỂ LOẠI 
void countBookByCategory();

// THỐNG KÊ SỐ LƯỢNG ĐỘC GIẢ
void countTotalReaders();

// THỐNG KÊ SỐ LƯỢNG ĐỘC GIẢ THEO GIỚI TÍNH
void countTotalReadersByGender();

// THỐNG KÊ SỐ SÁCH ĐANG ĐƯỢC MƯỢN
void countTotalBorrowedBooks();

// THỐNG KÊ DANH SÁCH ĐỘC GIẢ BỊ TRỄ HẠN
void listOverdueReaders();

#endif