#ifndef BOOK_H
#define BOOK_H

// XEM DANH SÁCH CÁC SÁCH TRONG THƯ VIỆN 
// Hiển thị Header
void viewBookHeader();
// Hiển thị 1 đọc giả dựa trên index
void viewBook(int index);
// hiển thị toàn bộ đọc giả
void viewAllBooks();

// THÊM SÁCH

// Hàm nhập thể loại sách
int inputCategory(char* str);

void addBook();

// Tìm sách dựa trên mã isbn của sách
int findBookByISBN(char* isbn);

// CHỈNH SỬA THÔNG TIN MỘT QUYỂN SÁCH 
void editInfoBook();

// XÓA THÔNG TIN SÁCH 
void deleteBook();

// TÌM KIẾM SÁCH THEO ISBN 
void searchBookByISBN();

// TÌM KIẾM SÁCH THEO TÊN SÁCH
void searchBookByTitle();

#endif