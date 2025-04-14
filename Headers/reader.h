#ifndef READER_H                  // Ngăn chặn việc bao gồm file header nhiều lần (include guard)
#define READER_H                  // Định nghĩa macro đánh dấu file header đã được bao gồm

// 1. QUẢN LÝ ĐỘC GIẢ

// 1.1. XEM DANH SÁCH ĐỘC GIẢ TRONG THƯ VIỆN

void viewReaderHeader();          // Hiển thị tiêu đề bảng danh sách độc giả (ID, tên, CMND, v.v.)

void viewReader(int index);       // Hiển thị thông tin một độc giả dựa trên chỉ số trong mảng IDS

void viewAllReaders();            // Hiển thị toàn bộ danh sách độc giả hiện có trong hệ thống

// 1.2. THÊM ĐỘC GIẢ

void generateCodeReader(char* code, const char* lastReaderID); // Sinh mã ID độc giả mới (DGxxxx) từ ID cuối cùng

void inputName(char* name, int size); // Nhập tên độc giả, giới hạn độ dài bởi size

void inputCIC(char* cic, int size);   // Nhập CMND/CCCD, kiểm tra hợp lệ (9 hoặc 12 số, không trùng)

int inputGender();                    // Nhập giới tính, trả về 1 (Nam) hoặc 0 (Nữ)

int isValidEmail(char* email);        // Kiểm tra email hợp lệ (có @, ., không ký tự đặc biệt)

void inputEmail(char* email, int size); // Nhập email, kiểm tra hợp lệ trước khi lưu

int inputProvince();                  // Nhập tỉnh/thành phố, trả về chỉ số trong PROVINCES_DB

int inputDistrict(int province);      // Nhập huyện/quận dựa trên tỉnh, trả về chỉ số trong DISTRICTS_DB

void addReader();                     // Thêm một độc giả mới vào các mảng dữ liệu toàn cục

// Hàm tìm kiếm hỗ trợ

int findReaderById(char* id);         // Tìm độc giả theo ID, trả về chỉ số hoặc -1 nếu không thấy

int findReaderByCIC(char* cic);       // Tìm độc giả theo CMND/CCCD, trả về chỉ số hoặc -1 nếu không thấy

// 1.3. CHỈNH SỬA THÔNG TIN ĐỘC GIẢ

void editReaderInfor();               // Chỉnh sửa thông tin độc giả (tên, CMND, email, v.v.) theo ID

// 1.4. XÓA THÔNG TIN ĐỘC GIẢ

void deleteReader();                  // Xóa một độc giả khỏi hệ thống theo ID, dịch chuyển mảng

// 1.5. TÌM KIẾM ĐỘC GIẢ THEO CMND/CCCD

void searchReaderByCIC();             // Tìm và hiển thị độc giả theo CMND/CCCD nhập vào

// 1.6. TÌM KIẾM ĐỘC GIẢ THEO HỌ TÊN

void searchReaderByName();            // Tìm và hiển thị danh sách độc giả theo tên (tìm chuỗi con)

#endif                            // Kết thúc include guard