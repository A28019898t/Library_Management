#ifndef BOOK_H                  // Ngăn chặn việc bao gồm file header nhiều lần (include guard)
#define BOOK_H                  // Định nghĩa macro đánh dấu file header đã được bao gồm

// 2. QUẢN LÝ SÁCH

// 2.1. XEM DANH SÁCH SÁCH TRONG THƯ VIỆN

void viewBookHeader();          // Hiển thị tiêu đề bảng danh sách sách (ISBN, tiêu đề, tác giả, v.v.)

void viewBook(int index);       // Hiển thị thông tin một cuốn sách dựa trên chỉ số trong mảng ISBNs

void viewAllBooks();            // Hiển thị toàn bộ danh sách sách hiện có trong hệ thống

// 2.2. THÊM SÁCH

void addBook();                 // Thêm một cuốn sách mới vào các mảng dữ liệu toàn cục

// Hàm tìm kiếm hỗ trợ

int findBookByISBN(char* isbn); // Tìm sách theo ISBN, trả về chỉ số trong ISBNs hoặc -1 nếu không thấy

// 2.3. CHỈNH SỬA THÔNG TIN SÁCH

void editInfoBook();            // Chỉnh sửa thông tin sách (tiêu đề, tác giả, giá, v.v.) dựa trên tên sách

// 2.4. XÓA THÔNG TIN SÁCH

void deleteBook();              // Xóa một cuốn sách khỏi hệ thống theo tên hoặc ISBN, dịch chuyển mảng

// 2.5. TÌM KIẾM SÁCH THEO ISBN

void searchBookByISBN();        // Tìm và hiển thị sách theo ISBN nhập vào

// 2.6. TÌM KIẾM SÁCH THEO TÊN

void searchBookByTitle();       // Tìm và hiển thị danh sách sách theo tiêu đề (tìm chuỗi con)

#endif                          // Kết thúc include guard