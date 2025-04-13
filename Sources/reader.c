#include <stdio.h>              // Thư viện chuẩn cho nhập/xuất dữ liệu
#include <stdlib.h>             // Thư viện chuẩn cho quản lý bộ nhớ và hàm hệ thống
#include <string.h>             // Thư viện xử lý chuỗi ký tự
#include <ctype.h>              // Thư viện xử lý ký tự (isalnum, tolower, v.v.)

#include "..\Headers\reader.h"  // File header chứa khai báo hàm quản lý độc giả
#include "..\Headers\data.h"    // File header chứa định nghĩa dữ liệu và mảng toàn cục
#include "..\Headers\utils.h"   // File header chứa các hàm tiện ích (getDateFromKMonths, isNumber, v.v.)

// 1. QUẢN LÝ ĐỌC GIẢ

// 1.1. XEM DANH SÁCH ĐỘC GIẢ TRONG THƯ VIỆN

void viewReaderHeader() {       // Hiển thị tiêu đề danh sách độc giả
    printf("%-8s", "id");       // Cột ID: 8 ký tự, căn trái
    printf("%-28s", "Ho va ten"); // Cột Họ và tên: 28 ký tự, căn trái
    printf("%-14s", "CMND/CCCD"); // Cột CMND/CCCD: 14 ký tự, căn trái
    printf("%-12s", "Ngay sinh"); // Cột Ngày sinh: 12 ký tự, căn trái
    printf("%-12s", "Gioi tinh"); // Cột Giới tính: 12 ký tự, căn trái
    printf("%-28s", "Email");     // Cột Email: 28 ký tự, căn trái
    printf("%-35s", "Dia chi");   // Cột Địa chỉ: 35 ký tự, căn trái
    printf("%-15s", "Ngay lap the"); // Cột Ngày lập thẻ: 15 ký tự, căn trái
    printf("%-15s", "Ngay het han the"); // Cột Ngày hết hạn thẻ: 15 ký tự, căn trái
    printf("\n");                 // Xuống dòng sau khi in tiêu đề
}

void viewReader(int index) {    // Hiển thị thông tin một độc giả dựa trên chỉ số
    printf("%-8s", IDS[index]); // In ID độc giả từ mảng IDS
    printf("%-28s", NAMES[index]); // In tên độc giả từ mảng NAMES
    printf("%-14s", CIC_NUMBERS[index]); // In CMND/CCCD từ mảng CIC_NUMBERS
    printf("%-12s", BIRTHDAYS[index]); // In ngày sinh từ mảng BIRTHDAYS
    printf("%-12s", (GENDERS[index] == 1) ? "Nam" : "Nu"); // In giới tính: 1-Nam, 0-Nữ từ GENDERS
    printf("%-28s", EMAILS[index]); // In email từ mảng EMAILS
    
    int distance1 = strlen(DISTRICTS_DB[DISTRICTS[index]]); // Độ dài tên huyện/quận
    int distance2 = 35 - distance1 - 2; // Độ dài còn lại cho tỉnh, trừ 2 ký tự ", "
    printf("%-*s, %-*s", distance1, DISTRICTS_DB[DISTRICTS[index]], distance2, PROVINCES_DB[PROVINCES[index]]); // In địa chỉ: huyện, tỉnh
    printf("%-15s", ISSUE_DATES[index]); // In ngày lập thẻ từ mảng ISSUE_DATES
    
    char expiryDate[11];         // Chuỗi lưu ngày hết hạn thẻ (DD/MM/YYYY)
    getDateFromKMonths(expiryDate, ISSUE_DATES[index], 48); // Tính ngày hết hạn: +48 tháng từ ngày lập thẻ
    printf("%-15s", expiryDate); // In ngày hết hạn thẻ
    printf("\n");                // Xuống dòng sau khi in thông tin độc giả
}

void viewAllReaders() {         // Hiển thị toàn bộ danh sách độc giả
    viewReaderHeader();         // Gọi hàm in tiêu đề
    for (int i = 0; i < NUMBER_OF_READERS; i++) { // Duyệt qua tất cả độc giả
        viewReader(i);          // Gọi hàm in thông tin từng độc giả
    }
}

// 1.2. THÊM ĐỘC GIẢ

void generateCodeReader(char* code, const char* lastReaderID) { // Sinh mã ID độc giả mới
    if (lastReaderID == NULL || strlen(lastReaderID) < 3 || strncmp(lastReaderID, "DG", 2) != 0) { // Kiểm tra ID cuối cùng hợp lệ
        strcpy(code, "DG0001"); // Nếu không hợp lệ, trả về mã mặc định
        return;
    }
    
    int num;                // Số thứ tự trong ID
    sscanf(lastReaderID + 2, "%d", &num); // Lấy phần số từ ID (bỏ "DG")
    num++;                  // Tăng số thứ tự lên 1
    
    if (num > 9999) {       // Kiểm tra vượt quá giới hạn mã (DG9999)
        strcpy(code, "DG9999"); // Gán mã tối đa
        printf("Canh bao: Da dat gioi han ma doc gia!\n"); // Thông báo cảnh báo
        return;
    }
    
    char temp[5];           // Chuỗi tạm lưu số thứ tự (4 chữ số + '\0')
    intToPaddedString(temp, num, 4); // Chuyển số thành chuỗi, thêm 0 nếu cần
    strcpy(code, "DG");     // Gán tiền tố "DG"
    strcat(code, temp);     // Nối số thứ tự vào mã
}

void inputName(char* name, int size) { // Nhập tên độc giả
    printf("Ho va ten: ");  // Yêu cầu nhập tên
    fgets(name, size, stdin); // Nhập chuỗi tên từ người dùng
    name[strcspn(name, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
}

void inputCIC(char* cic, int size) { // Nhập CMND/CCCD
    int valid;              // Biến kiểm tra tính hợp lệ
    do {
        valid = 1;          // Giả định đầu vào hợp lệ
        printf("CMND/CCCD: "); // Yêu cầu nhập CMND/CCCD
        fgets(cic, size, stdin); // Nhập chuỗi từ người dùng
        cic[strcspn(cic, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
        
        if (!isNumber(cic)) { // Kiểm tra chuỗi chỉ chứa số
            valid = 0;      // Không hợp lệ nếu có ký tự không phải số
            printf("CMND/CCCD phai la so\n"); // Thông báo lỗi
            continue;
        }
        
        if (findReaderByCIC(cic) != -1) { // Kiểm tra trùng lặp CMND/CCCD
            valid = 0;      // Không hợp lệ nếu đã tồn tại
            printf("CMND/CCCD da ton tai trong thu vien\n"); // Thông báo lỗi
            continue;
        }
        
        switch (strlen(cic)) { // Kiểm tra độ dài CMND/CCCD
            case 9:         // CMND: 9 số
            case 12:        // CCCD: 12 số
                break;
            default:        // Độ dài không hợp lệ
                valid = 0;
                printf("CMND co 9 chu so, CCCD co 12 chu so\n"); // Thông báo lỗi
        }
    } while (!valid);   // Lặp lại nếu không hợp lệ
}

int inputGender() {         // Nhập giới tính độc giả
    int choice;             // Lựa chọn của người dùng
    int valid;              // Biến kiểm tra tính hợp lệ
    do {
        valid = 1;          // Giả định đầu vào hợp lệ
        printf("Gioi tinh (Nam / Nu): \n"); // Yêu cầu nhập giới tính
        printf("\t[1]: Nam\n"); // Lựa chọn 1: Nam
        printf("\t[2]: Nu\n");  // Lựa chọn 2: Nữ
        printf("\tNhap lua chon [ ? ]: "); // Yêu cầu nhập số
        scanf("%d", &choice); // Nhập lựa chọn
        getchar();          // Xóa ký tự thừa trong bộ đệm
        
        switch (choice) {   // Xử lý lựa chọn
            case 1: return 1; // Nam: trả về 1
            case 2: return 0; // Nữ: trả về 0
            default:        // Lựa chọn không hợp lệ
                valid = 0;
                printf("Nhap sai lua chon. Moi nhap lai\n"); // Thông báo lỗi
        }
    } while (!valid);   // Lặp lại nếu không hợp lệ
    return 0;           // Giá trị mặc định (không bao giờ chạy đến đây)
}

int isValidEmail(char* email) { // Kiểm tra email hợp lệ
    int len = strlen(email);    // Độ dài email
    int atCount = 0;            // Số ký tự '@'
    int dotCount = 0;           // Số ký tự '.' sau '@'
    int atIndex = -1;           // Vị trí của '@'
    
    if (len < 6) return 0;      // Độ dài tối thiểu không đủ (ví dụ: a@b.c)
    if (!isalnum(email[0]) || !isalnum(email[len - 1])) return 0; // Ký tự đầu/cuối không phải chữ/số
    
    for (int i = 0; i < len; i++) { // Duyệt qua từng ký tự
        char c = email[i];
        if (c == '@') {         // Đếm và lưu vị trí '@'
            atCount++;
            atIndex = i;
        }
        else if (c == '.' && atIndex != -1 && i > atIndex) { // Đếm '.' sau '@'
            dotCount++;
        }
        if (!(isalnum(c) || c == '@' || c == '.' || c == '-' || c == '_')) { // Kiểm tra ký tự hợp lệ
            return 0;
        }
    }
    
    if (atCount != 1 || atIndex < 1 || atIndex >= len - 3) return 0; // '@' phải có 1 và ở vị trí hợp lệ
    if (dotCount < 1) return 0; // Phải có ít nhất 1 '.' sau '@'
    if (strstr(email, "..") || strstr(email, "@.") || strstr(email, ".@")) return 0; // Kiểm tra chuỗi lỗi
    
    return 1;               // Email hợp lệ
}

void inputEmail(char* email, int size) { // Nhập email độc giả
    int valid;              // Biến kiểm tra tính hợp lệ
    do {
        printf("Email: ");  // Yêu cầu nhập email
        fgets(email, size, stdin); // Nhập chuỗi từ người dùng
        email[strcspn(email, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
        
        valid = isValidEmail(email); // Kiểm tra email hợp lệ
        if (!valid) {       // Nếu không hợp lệ
            printf("Email khong hop le. Moi nhap lai\n"); // Thông báo lỗi
        }
    } while (!valid);   // Lặp lại nếu không hợp lệ
}

int inputProvince() {       // Nhập tỉnh/thành phố
    int address;            // Chỉ số tỉnh được chọn
    do {
        address = findItemByStr("Nhap tinh: ", PROVINCES_DB, MAX_PROVINCE); // Tìm tỉnh trong PROVINCES_DB
        if (address == -1) { // Nếu không tìm thấy
            printf("Khong co dia chi hop le. Moi nhap lai\n"); // Thông báo lỗi
        }
    } while (address == -1); // Lặp lại nếu không hợp lệ
    return address;         // Trả về chỉ số tỉnh
}

int inputDistrict(int province) { // Nhập huyện/quận dựa trên tỉnh
    int start = PROVINCE_START_INDEX[province]; // Chỉ số bắt đầu của huyện trong DISTRICTS_DB
    int end = (province < MAX_PROVINCE - 1) ? PROVINCE_START_INDEX[province + 1] - 1 : 712; // Chỉ số kết thúc (712 cho Yên Bái)
    
    for (int i = start; i <= end; i++) { // Hiển thị danh sách huyện/quận
        printf("[%d]: %s\n", i - start + 1, DISTRICTS_DB[i]); // In số thứ tự và tên huyện
    }
    
    int choice;             // Lựa chọn của người dùng
    printf("Chon: ");       // Yêu cầu nhập lựa chọn
    scanf("%d", &choice);   // Nhập số thứ tự huyện
    return start + choice - 1; // Trả về chỉ số huyện trong DISTRICTS_DB
}

void addReader() {          // Thêm một độc giả mới vào hệ thống
    char readerID[MAX_ID];  // Mã ID độc giả mới
    char name[MAX_NAME];    // Tên độc giả
    char cic[MAX_CIC];      // CMND/CCCD độc giả
    int gender;             // Giới tính độc giả
    char email[MAX_EMAIL];  // Email độc giả
    int province;           // Chỉ số tỉnh
    int district;           // Chỉ số huyện
    char birthDate[MAX_DATE]; // Ngày sinh độc giả
    char issueDate[MAX_DATE]; // Ngày lập thẻ
    
    printf("THEM DOC GIA\n"); // Tiêu đề chức năng
    
    generateCodeReader(readerID, IDS[NUMBER_OF_READERS - 1]); // Sinh mã ID dựa trên ID cuối cùng
    printf("%s\n", readerID); // In mã ID (test)
    
    inputName(name, MAX_NAME); // Nhập tên
    
    inputCIC(cic, MAX_CIC);   // Nhập CMND/CCCD
    
    gender = inputGender();   // Nhập giới tính
    
    inputEmail(email, MAX_EMAIL); // Nhập email
    
    province = inputProvince(); // Nhập tỉnh
    
    district = inputDistrict(province); // Nhập huyện
    
    printf("Nhap ngay sinh: \n");
    inputDay(birthDate);      // Nhập ngày sinh (hàm từ utils.h)
    
    getToday(issueDate);      // Lấy ngày hiện tại làm ngày lập thẻ
    
    if (NUMBER_OF_READERS < MAX_READERS) { // Kiểm tra còn chỗ trống
        strcpy(IDS[NUMBER_OF_READERS], readerID); // Lưu ID
        strcpy(NAMES[NUMBER_OF_READERS], name);   // Lưu tên
        strcpy(CIC_NUMBERS[NUMBER_OF_READERS], cic); // Lưu CMND/CCCD
        strcpy(BIRTHDAYS[NUMBER_OF_READERS], birthDate); // Lưu ngày sinh
        GENDERS[NUMBER_OF_READERS] = gender;      // Lưu giới tính
        strcpy(EMAILS[NUMBER_OF_READERS], email); // Lưu email
        PROVINCES[NUMBER_OF_READERS] = province;  // Lưu chỉ số tỉnh
        DISTRICTS[NUMBER_OF_READERS] = district;  // Lưu chỉ số huyện
        strcpy(ISSUE_DATES[NUMBER_OF_READERS], issueDate); // Lưu ngày lập thẻ
        
        NUMBER_OF_READERS++; // Tăng số lượng độc giả
        printf("Thanh cong\n"); // Thông báo thành công
    } else {
        printf("Khong du bo nho\n"); // Thông báo hết bộ nhớ
    }
}

// 1.3. CHỈNH SỬA THÔNG TIN ĐỘC GIẢ

int findReaderById(char* id) {  // Tìm độc giả theo ID, trả về chỉ số
    for (int i = 0; i < NUMBER_OF_READERS; i++) { // Duyệt qua danh sách độc giả
        if (strcmp(id, IDS[i]) == 0) { // So sánh ID
            return i;         // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1;                // Trả về -1 nếu không tìm thấy
}

int findReaderByCIC(char* cic) { // Tìm độc giả theo CMND/CCCD, trả về chỉ số
    for (int i = 0; i < NUMBER_OF_READERS; i++) { // Duyệt qua danh sách độc giả
        if (strcmp(cic, CIC_NUMBERS[i]) == 0) { // So sánh CMND/CCCD
            return i;         // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1;                // Trả về -1 nếu không tìm thấy
}

void editReaderInfor() {      // Chỉnh sửa thông tin độc giả
    char id[MAX_ID];          // ID độc giả cần chỉnh sửa
    int choice;               // Lựa chọn mục cần chỉnh sửa
    
    printf("Nhap id cua doc gia: "); // Yêu cầu nhập ID
    scanf("%s", id);          // Nhập ID
    getchar();                // Xóa ký tự thừa
    
    int index = findReaderById(id); // Tìm chỉ số độc giả
    if (index == -1) {        // Nếu không tìm thấy
        printf("Khong tim thay doc gia co id: %s\n", id); // Thông báo lỗi
        return;
    }
    
    do {                      // Menu chỉnh sửa
        system("cls");        // Xóa màn hình
        printf("THONG TIN DOC GIA\n"); // Tiêu đề
        viewReaderHeader();   // In tiêu đề bảng
        viewReader(index);    // In thông tin độc giả
        printf("\n");
        
        printf("[1]: Ho va ten\n"); // Lựa chọn chỉnh tên
        printf("[2]: CMND/CCCD\n"); // Lựa chọn chỉnh CMND/CCCD
        printf("[3]: Ngay sinh\n"); // Lựa chọn chỉnh ngày sinh
        printf("[4]: Gioi tinh\n"); // Lựa chọn chỉnh giới tính
        printf("[5]: Email\n");     // Lựa chọn chỉnh email
        printf("[6]: Dia chi\n");   // Lựa chọn chỉnh địa chỉ
        printf("[0]: Thoat\n");     // Thoát menu
        
        printf("Chon muc can dieu chinh [ ? ]: "); // Yêu cầu nhập lựa chọn
        scanf("%d", &choice); // Nhập lựa chọn
        getchar();            // Xóa ký tự thừa
        
        switch (choice) {     // Xử lý lựa chọn
            case 0: break;    // Thoát
            case 1:           // Chỉnh tên
                printf("Ho va ten: ");
                fgets(NAMES[index], MAX_NAME, stdin);
                NAMES[index][strcspn(NAMES[index], "\n")] = '\0';
                break;
            case 2:           // Chỉnh CMND/CCCD
                printf("CMND/CCCD: ");
                inputCIC(CIC_NUMBERS[index], MAX_CIC);
                break;
            case 3:           // Chỉnh ngày sinh
                printf("Ngay sinh: ");
                inputDay(BIRTHDAYS[index]);
                break;
            case 4:           // Chỉnh giới tính
                printf("Gioi tinh: ");
                GENDERS[index] = inputGender();
                break;
            case 5:           // Chỉnh email
                printf("Email: ");
                inputEmail(EMAILS[index], MAX_EMAIL);
                break;
            case 6:           // Chỉnh địa chỉ
                printf("Dia chi: ");
                PROVINCES[index] = inputProvince();
                DISTRICTS[index] = inputDistrict(PROVINCES[index]);
                break;
            default:          // Lựa chọn không hợp lệ
                printf("Nhap sai lua chon. Moi ban nhap lai\n");
        }
    } while (choice != 0); // Lặp lại đến khi thoát
}

// 1.4. XÓA THÔNG TIN ĐỘC GIẢ

void deleteReader() {         // Xóa một độc giả khỏi hệ thống
    char id[MAX_ID];          // ID độc giả cần xóa

    printf("Nhap ID cua doc gia: "); // Yêu cầu nhập ID
    fgets(id, MAX_ID, stdin); // Nhập ID
    id[strcspn(id, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
    
    int index = findReaderById(id); // Tìm chỉ số độc giả
    if (index == -1) {        // Nếu không tìm thấy
        printf("Khong tim thay doc gia co ID: %s\n", id); // Thông báo lỗi
        return;
    }
    
    for (int i = index; i < NUMBER_OF_READERS - 1; i++) { // Dịch chuyển dữ liệu để xóa
        strcpy(IDS[i], IDS[i + 1]); // Dịch ID
        strcpy(NAMES[i], NAMES[i + 1]); // Dịch tên
        strcpy(CIC_NUMBERS[i], CIC_NUMBERS[i + 1]); // Dịch CMND/CCCD
        strcpy(BIRTHDAYS[i], BIRTHDAYS[i + 1]); // Dịch ngày sinh
        GENDERS[i] = GENDERS[i + 1]; // Dịch giới tính
        strcpy(EMAILS[i], EMAILS[i + 1]); // Dịch email
        PROVINCES[i] = PROVINCES[i + 1]; // Dịch tỉnh
        DISTRICTS[i] = DISTRICTS[i + 1]; // Dịch huyện
        strcpy(ISSUE_DATES[i], ISSUE_DATES[i + 1]); // Dịch ngày lập thẻ
    }
    
    NUMBER_OF_READERS--;      // Giảm số lượng độc giả
    printf("Xoa thanh cong doc gia %s\n", id); // Thông báo thành công
}

// 1.5. TÌM KIẾM ĐỘC GIẢ THEO CMND/CCCD

void searchReaderByCIC() {    // Tìm kiếm độc giả theo CMND/CCCD
    char cic[13];             // Chuỗi lưu CMND/CCCD (tối đa 12 số + '\0')
    
    printf("Nhap CMND cua doc gia: "); // Yêu cầu nhập CMND/CCCD
    fgets(cic, sizeof(cic), stdin); // Nhập chuỗi
    cic[strcspn(cic, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
    
    printf("%s\n", cic);      // In CMND/CCCD (test)
    
    int index = findReaderByCIC(cic); // Tìm chỉ số độc giả
    printf("KET QUA\n");      // Tiêu đề kết quả
    
    if (index != -1) {        // Nếu tìm thấy
        viewReaderHeader();   // In tiêu đề bảng
        viewReader(index);    // In thông tin độc giả
        printf("\n");
    } else {                  // Nếu không tìm thấy
        printf("Khong tim thay doc gia co CMND/CCCD: %s\n", cic); // Thông báo lỗi
    }
}

// 1.6. TÌM KIẾM ĐỘC GIẢ THEO HỌ TÊN

void searchReaderByName() {   // Tìm kiếm độc giả theo tên
    char source[20];          // Chuỗi tên nhập vào
    char des[20];             // Chuỗi tên chuyển thành chữ thường
    int saveIndex[20];        // Mảng lưu chỉ số các độc giả tìm thấy
    int index = 0;            // Số lượng độc giả tìm thấy
    
    printf("Nhap ten doc gia: "); // Yêu cầu nhập tên
    fgets(source, sizeof(source), stdin); // Nhập chuỗi tên
    source[strcspn(source, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
    
    convertToLower(source, des); // Chuyển tên nhập vào thành chữ thường
    
    for (int i = 0; i < NUMBER_OF_READERS; i++) { // Duyệt qua danh sách độc giả
        char temp[20];        // Chuỗi tạm lưu tên độc giả (chữ thường)
        convertToLower(NAMES[i], temp); // Chuyển tên độc giả thành chữ thường
        
        if (findSubString(des, temp) != -1) { // Kiểm tra tên nhập vào có trong tên độc giả
            saveIndex[index++] = i; // Lưu chỉ số độc giả
            printf("%d. %s\n", index, NAMES[i]); // In số thứ tự và tên
        }
    }
    
    if (index == 0) {         // Nếu không tìm thấy
        printf("Khong co\n"); // Thông báo không có kết quả
    } else {                  // Nếu tìm thấy
        int choice;           // Lựa chọn độc giả
        printf("Chon doc gia: "); // Yêu cầu chọn
        scanf("%d", &choice); // Nhập lựa chọn
        viewReaderHeader();   // In tiêu đề bảng
        viewReader(saveIndex[choice - 1]); // In thông tin độc giả được chọn
    }
}