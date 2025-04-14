#ifndef BORROWRETURN_H            // Ngăn chặn việc bao gồm file header nhiều lần (include guard)
#define BORROWRETURN_H            // Định nghĩa macro đánh dấu file header đã được bao gồm

#include "..\Headers\data.h"      // File header chứa định nghĩa dữ liệu và mảng toàn cục

// 4. QUẢN LÝ MƯỢN TRẢ SÁCH

// 4.1. LẬP PHIẾU MƯỢN SÁCH

void createBorrowTicket();        // Tạo phiếu mượn sách mới, cập nhật BORROW_IDS, BORROW_ISBN_BOOKS, v.v.

// Hàm hỗ trợ quản lý mượn trả

int findReaderBorrowBooksByID(char* id, int result[]); // Tìm phiếu mượn của độc giả theo ID, trả về số lượng phiếu

void deleteBorrowTicketByIndex(int index); // Xóa phiếu mượn tại chỉ số index, dịch chuyển dữ liệu

int removeElementBorrowBook(char arr[][MAX_ISBN], int length, int position); // Xóa phần tử trong mảng BORROW_ISBN_BOOKS, trả về độ dài mới

int removeElementBorrowReader(char arr[][MAX_ID], int length, int position); // Xóa phần tử trong mảng BORROW_IDS, trả về độ dài mới

int removeElementBorrowPos(int arr[], int length, int position); // Xóa phần tử trong mảng BORROW_START/END, trả về độ dài mới

void viewBorrowHeader(); // Hiển thị dòng tiêu đề của danh sách mượn sách

int viewBorrowBook(int seq, char* isbn, char* title, char* borrowDate); // Hiển thị sách đã mượn

// 4.2. LẬP PHIẾU TRẢ SÁCH

void createReturnTicket();        // Tạo phiếu trả sách, xóa sách khỏi BORROW_ISBN_BOOKS và cập nhật kho

#endif                            // Kết thúc include guard