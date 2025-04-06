#ifndef READER_H
#define READER_H

// XEM DANH SÁCH ĐỘC GIẢ TRONG THƯ VIỆN
// Hiển thị Header
void viewReaderHeader();
// Hiển thị 1 đọc giả dựa trên index
void viewReader(int index);
// hiển thị toàn bộ đọc giả
void viewAllReaders();

// THÊM ĐỘC GIẢ
// sinh ra mã đọc giả
void generateCodeReader(char* code);

// hàm nhập tên
void inputName(char* name, int size);

// hàm nhập CMND/CCCD
void inputCIC(char* cic, int size);

// hàm nhập giới tính
int inputGender();

// hàm nhập email
void inputEmail(char* email, int size);

// hàm nhập địa chỉ
void inputAddress(char* address, int size);

// thêm đọc giả
void addReader();

// TÌM ĐỌC GIẢ BẰNG ID
int findReaderById(char* id);

// TÌM ĐỌC GIẢ BẰNG CHỨNG MINH NHÂN DÂN
int findReaderByCIC(char* cic);

// CHỈNH SỬA THÔNG TIN MỘT ĐỘC GIẢ 
void editReaderInfor();

// XÓA THÔNG TIN MỘT ĐỘC GIẢ 
void deleteReader();

// TÌM KIẾM ĐỘC GIẢ THEO CMND 
void searchReaderByCMND();

// TÌM KIẾM SÁCH THEO HỌ TÊN
void searchReaderByName();

#endif