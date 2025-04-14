#ifndef STATISTICS_H             // Ngăn chặn việc bao gồm file header nhiều lần (include guard)
#define STATISTICS_H             // Định nghĩa macro đánh dấu file header đã được bao gồm

// 3. THỐNG KÊ

// 3.1. THỐNG KÊ TỔNG SỐ SÁCH TRONG THƯ VIỆN

void countTotalBooks();          // Đếm và in tổng số sách trong kho từ mảng STOCKS

// 3.2. THỐNG KÊ SỐ LƯỢNG SÁCH THEO THỂ LOẠI

void countBookByCategory();      // Đếm và in số lượng sách theo từng thể loại trong GENRES_DB

// 3.3. THỐNG KÊ TỔNG SỐ ĐỘC GIẢ

void countTotalReaders();        // In tổng số độc giả từ biến toàn cục NUMBER_OF_READERS

// 3.4. THỐNG KÊ SỐ LƯỢNG ĐỘC GIẢ THEO GIỚI TÍNH

void countTotalReadersByGender(); // Đếm và in số độc giả nam/nữ từ mảng GENDERS

// 3.5. THỐNG KÊ SỐ SÁCH ĐANG ĐƯỢC MƯỢN

void countTotalBorrowedBooks();   // In tổng số sách đang mượn từ biến toàn cục NUMBER_OF_ISBN_BOOK

// 3.6. THỐNG KÊ DANH SÁCH ĐỘC GIẢ BỊ TRỄ HẠN

void listOverdueReaders();        // Liệt kê độc giả trễ hạn dựa trên BORROW_RETURN_DATE (chưa hoàn thiện)

#endif                           // Kết thúc include guard