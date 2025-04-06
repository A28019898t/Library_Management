#ifndef BORROWRETURN_H
#define BORROWRETURN_H

#include "..\Headers\data.h"


// LẬP PHIẾU MƯỢN SÁCH  
void createBorrowTicket();

// tìm thông tin của đọc giả trong dữ liệu mượn sách.
int findReaderBorrowBooksByID(char* id, int result[]);

// xoá thông tin trong danh sách mượn sách; và lưu thông tin trong danh sách trả sách để theo dõi và trích xuất thông tin khi cần thiết
void deleteBorrowTicketByIndex(int index);

// lưu vào trong mảng returnTickets
void storeReturnTicketData(char* readerId, char* bookId, char* borrowDate, char* returnDate, char* realReturnDate, wchar_t lossBook, int forfeit);

// Loại bỏ phẩn tử của BORROW_ISBN_BOOKS ở bất kỳ vị trí nào 
int removeElementBorrowBook(char arr[][MAX_ISBN], int length, int position);

// Loại bỏ phẩn tử của BOOK_IDS ở bất kỳ vị trí nào 
int removeElementBorrowReader(char arr[][MAX_ID], int length, int position);

// Loại bỏ phẩn tử của BORROW_START / END ở bất kỳ vị trí nào 
int removeElementBorrowPos(int arr[], int length, int position);


// LẬP PHIẾU TRẢ SÁCH
void createReturnTicket();

#endif