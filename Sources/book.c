#include <stdio.h>              // Thư viện chuẩn cho nhập/xuất dữ liệu
#include <string.h>             // Thư viện xử lý chuỗi ký tự

#include "..\Headers\book.h"    // File header chứa khai báo hàm quản lý sách
#include "..\Headers\data.h"    // File header chứa định nghĩa dữ liệu và mảng toàn cục
#include "..\Headers\utils.h"   // File header chứa các hàm tiện ích (inputString, convertToLower, v.v.)

// 2. QUẢN LÝ SÁCH

// 2.1. XEM DANH SÁCH SÁCH TRONG THƯ VIỆN

void viewBookHeader() {         // Hiển thị tiêu đề bảng danh sách sách
    printf("%-20s", "id");      // Cột ISBN: 20 ký tự, căn trái
    printf("%-40s", "Ten sach"); // Cột Tên sách: 40 ký tự, căn trái
    printf("%-26s", "Tac gia"); // Cột Tác giả: 26 ký tự, căn trái
    printf("%-26s", "Nha xuat ban"); // Cột Nhà xuất bản: 26 ký tự, căn trái
    printf("%-8s", "Nam XB");   // Cột Năm xuất bản: 8 ký tự, căn trái
    printf("%-24s", "The loai"); // Cột Thể loại: 24 ký tự, căn trái
    printf("%-10s", "Gia tien"); // Cột Giá tiền: 10 ký tự, căn trái
    printf("%-5s", "So luong"); // Cột Số lượng: 5 ký tự, căn trái
    printf("\n");               // Xuống dòng sau khi in tiêu đề
}

void viewBook(int index) {      // Hiển thị thông tin một cuốn sách dựa trên chỉ số
    printf("%-20s", ISBNs[index]); // In ISBN từ mảng ISBNs
    printf("%-40s", TITLES[index]); // In tiêu đề từ mảng TITLES
    printf("%-26s", AUTHORS[index]); // In tác giả từ mảng AUTHORS
    printf("%-26s", PUBLISHERS_DB[PUBLISHERS[index]]); // In nhà xuất bản từ PUBLISHERS_DB
    printf("%-8s", PUBLISH_YEARS[index]); // In năm xuất bản từ PUBLISH_YEARS
    printf("%-24s", GENRES_DB[CATEGORIES[index]]); // In thể loại từ GENRES_DB
    printf("%-10.0f", PRICES[index] * 1000); // In giá tiền (nhân 1000 để ra VNĐ)
    printf("%-5d", STOCKS[index]); // In số lượng từ mảng STOCKS
    printf("\n");               // Xuống dòng sau khi in thông tin sách
}

void viewAllBooks() {           // Hiển thị toàn bộ danh sách sách
    viewBookHeader();           // Gọi hàm in tiêu đề
    for (int i = 0; i < NUMBER_OF_BOOKS; i++) { // Duyệt qua tất cả sách
        viewBook(i);            // Gọi hàm in thông tin từng cuốn sách
    }
}

// 2.2. THÊM SÁCH

void addBook() {                // Thêm một cuốn sách mới vào hệ thống
    char isbn[MAX_ISBN];        // Mã ISBN của sách (chưa xử lý tự động)
    char title[MAX_TITLE];      // Tiêu đề sách
    char author[MAX_AUTHOR];    // Tác giả sách
    int publisher;              // Chỉ số nhà xuất bản
    char publishYear[MAX_YEAR]; // Năm xuất bản
    int category;               // Chỉ số thể loại
    float price;                // Giá tiền (nghìn VNĐ)
    int stock;                  // Số lượng sách trong kho
    
    inputString("Nhap ten sach: ", title, MAX_TITLE); // Nhập tiêu đề
    inputString("Nhap ten tac gia: ", author, MAX_AUTHOR); // Nhập tác giả
    publisher = inputFromSelections("Nhap nha xuat ban: ", PUBLISHERS_DB, NUMBER_OF_PUBLISHERS); // Chọn NXB
    inputString("Nhap nam xuat ban: ", publishYear, MAX_YEAR); // Nhập năm xuất bản
    category = inputFromSelections("Nhap the loai: ", GENRES_DB, NUMBER_OF_GENRES); // Chọn thể loại
    printf("Nhap gia: ");       // Yêu cầu nhập giá
    scanf("%f", &price);        // Nhập giá tiền
    printf("Nhap so luong: ");  // Yêu cầu nhập số lượng
    scanf("%d", &stock);        // Nhập số lượng
    
    if (NUMBER_OF_BOOKS < MAX_BOOKS) { // Kiểm tra còn chỗ trống
        strcpy(ISBNs[NUMBER_OF_BOOKS], "DG003"); // Gán ISBN tạm (chưa tự động)
        strcpy(TITLES[NUMBER_OF_BOOKS], title); // Lưu tiêu đề
        strcpy(AUTHORS[NUMBER_OF_BOOKS], author); // Lưu tác giả
        PUBLISHERS[NUMBER_OF_BOOKS] = publisher; // Lưu chỉ số NXB
        strcpy(PUBLISH_YEARS[NUMBER_OF_BOOKS], publishYear); // Lưu năm xuất bản
        CATEGORIES[NUMBER_OF_BOOKS] = category; // Lưu chỉ số thể loại
        PRICES[NUMBER_OF_BOOKS] = price; // Lưu giá tiền
        STOCKS[NUMBER_OF_BOOKS] = stock; // Lưu số lượng
        
        NUMBER_OF_BOOKS++;      // Tăng số lượng sách
        printf("Them sach thanh cong\n"); // Thông báo thành công
    } else {
        printf("Khong du bo nho\n"); // Thông báo hết bộ nhớ
    }
}

// Hàm tìm kiếm hỗ trợ

int findBookByISBN(char* isbn) { // Tìm sách theo ISBN, trả về chỉ số
    for (int i = 0; i < NUMBER_OF_BOOKS; i++) { // Duyệt qua danh sách sách
        if (strcmp(isbn, ISBNs[i]) == 0) { // So sánh ISBN
            return i;           // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1;                  // Trả về -1 nếu không tìm thấy
}

// 2.3. CHỈNH SỬA THÔNG TIN SÁCH

void editInfoBook() {           // Chỉnh sửa thông tin một cuốn sách
    char title[MAX_TITLE];      // Chuỗi tên sách cần tìm
    int saveIndex[20];          // Mảng lưu chỉ số các sách tìm thấy
    int index = 0;              // Số lượng sách tìm thấy
    
    getchar();                  // Xóa ký tự thừa
    printf("Nhap ten can tim: "); // Yêu cầu nhập tên sách
    fgets(title, sizeof(title), stdin); // Nhập chuỗi tên
    title[strcspn(title, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
    
    convertToLower(title, title); // Chuyển tên nhập vào thành chữ thường
    
    for (int i = 0; i < NUMBER_OF_BOOKS; i++) { // Duyệt qua danh sách sách
        char temp[MAX_TITLE];   // Chuỗi tạm lưu tên sách (chữ thường)
        convertToLower(TITLES[i], temp); // Chuyển tên sách thành chữ thường
        if (findSubString(title, temp) != -1) { // Kiểm tra tên nhập vào có trong tên sách
            saveIndex[index++] = i; // Lưu chỉ số sách
            printf("[%d]: %s\n", index, TITLES[i]); // In số thứ tự và tên sách
        }
    }
    
    if (index == 0) {           // Nếu không tìm thấy
        printf("Khong co ten sach\n"); // Thông báo không có kết quả
    } else {                    // Nếu tìm thấy
        int choiceBook;         // Lựa chọn sách cần chỉnh sửa
        printf("Chon sach: ");  // Yêu cầu chọn sách
        scanf("%d", &choiceBook); // Nhập lựa chọn
        
        int selection;          // Lựa chọn mục cần chỉnh sửa
        do {
            printf("THONG TIN SACH\n"); // Tiêu đề
            viewBookHeader();   // In tiêu đề bảng
            viewBook(saveIndex[choiceBook - 1]); // In thông tin sách
            printf("\n");
            
            printf("[1]: Ten sach\n"); // Chỉnh tiêu đề
            printf("[2]: Tac gia\n");  // Chỉnh tác giả
            printf("[3]: Nha xuat ban\n"); // Chỉnh NXB
            printf("[4]: Nam xuat ban\n"); // Chỉnh năm XB
            printf("[5]: The loai\n");     // Chỉnh thể loại
            printf("[6]: Gia tien\n");     // Chỉnh giá tiền
            printf("[7]: So luong\n");     // Chỉnh số lượng
            printf("[0]: Thoat\n");        // Thoát menu
            
            printf("Chon muc can dieu chinh [ ? ]: "); // Yêu cầu nhập lựa chọn
            scanf("%d", &selection); // Nhập lựa chọn
            getchar();          // Xóa ký tự thừa
            
            switch (selection) { // Xử lý lựa chọn
                case 0: break;  // Thoát
                case 1: inputString("Nhap ten sach: ", TITLES[saveIndex[choiceBook - 1]], MAX_TITLE); break;
                case 2: inputString("Nhap ten tac gia: ", AUTHORS[saveIndex[choiceBook - 1]], MAX_AUTHOR); break;
                case 3: PUBLISHERS[saveIndex[choiceBook - 1]] = inputFromSelections("Nhap nha xuat ban: ", PUBLISHERS_DB, NUMBER_OF_PUBLISHERS); break;
                case 4: inputString("Nhap nam xuat ban: ", PUBLISH_YEARS[saveIndex[choiceBook - 1]], MAX_YEAR); break;
                case 5: CATEGORIES[saveIndex[choiceBook - 1]] = inputFromSelections("Nhap the loai: ", GENRES_DB, NUMBER_OF_GENRES); break;
                case 6: printf("Nhap gia tien: "); scanf("%f", &PRICES[saveIndex[choiceBook - 1]]); break;
                case 7: printf("Nhap so luong: "); scanf("%d", &STOCKS[saveIndex[choiceBook - 1]]); break;
                default: printf("Nhap sai lua chon. Moi ban nhap lai\n"); // Lựa chọn không hợp lệ
            }
        } while (selection != 0); // Lặp lại đến khi thoát
    }
}

// 2.4. XÓA THÔNG TIN SÁCH

void deleteBook() {             // Xóa một cuốn sách khỏi hệ thống
    char isbn[MAX_ISBN];        // Mã ISBN cần tìm
    int choice;                 // Lựa chọn cách tìm sách
    int index = -1;             // Chỉ số sách cần xóa
    
    do {
        getchar();              // Xóa ký tự thừa
        printf("CHON CACH TIM SACH\n"); // Tiêu đề menu
        printf("[1]: Tim bang ten sach\n"); // Tìm bằng tên
        printf("[2]: Tim bang ISBN sach\n"); // Tìm bằng ISBN
        printf("[0]: Thoat\n");     // Thoát menu
        printf("Nhap lua chon[?]: "); // Yêu cầu nhập lựa chọn
        if (scanf("%d", &choice) != 1) { // Nhập lựa chọn, kiểm tra hợp lệ
            printf("Nhap sai lua chon. Moi nhap lai\n"); // Thông báo lỗi
            choice = -1;        // Đặt lại choice để lặp
        }
        getchar();              // Xóa ký tự thừa
    } while (choice < 0);       // Lặp lại nếu nhập sai
    
    if (choice == 1) {          // Tìm bằng tên sách
        char title[MAX_TITLE];  // Chuỗi tên sách cần tìm
        int saveIndex[20];      // Mảng lưu chỉ số sách tìm thấy
        int count = 0;          // Số lượng sách tìm thấy
        
        printf("Nhap ten can tim: "); // Yêu cầu nhập tên
        fgets(title, sizeof(title), stdin); // Nhập chuỗi tên
        title[strcspn(title, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
        
        convertToLower(title, title); // Chuyển tên nhập vào thành chữ thường
        
        for (int i = 0; i < NUMBER_OF_BOOKS; i++) { // Duyệt qua danh sách sách
            char temp[MAX_TITLE]; // Chuỗi tạm lưu tên sách
            convertToLower(TITLES[i], temp); // Chuyển tên sách thành chữ thường
            if (findSubString(title, temp) != -1) { // Kiểm tra tên nhập vào có trong tên sách
                saveIndex[count++] = i; // Lưu chỉ số sách
                printf("%d. %s\n", count, TITLES[i]); // In số thứ tự và tên sách
            }
        }
        
        if (count == 0) {       // Nếu không tìm thấy
            printf("Khong co ten sach\n"); // Thông báo không có kết quả
        } else {                // Nếu tìm thấy
            int selection;      // Lựa chọn sách cần xóa
            printf("Chon sach: "); // Yêu cầu chọn
            scanf("%d", &selection); // Nhập lựa chọn
            getchar();          // Xóa ký tự thừa
            viewBookHeader();   // In tiêu đề bảng
            viewBook(saveIndex[selection - 1]); // In thông tin sách
            index = saveIndex[selection - 1]; // Gán chỉ số sách cần xóa
        }
    } else if (choice == 2) {   // Tìm bằng ISBN
        printf("Nhap isbn cua sach: "); // Yêu cầu nhập ISBN
        fgets(isbn, sizeof(isbn), stdin); // Nhập chuỗi ISBN
        isbn[strcspn(isbn, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
        
        index = findBookByISBN(isbn); // Tìm chỉ số sách theo ISBN
    }
    
    if (index != -1) {          // Nếu tìm thấy sách
        for (int i = index; i < NUMBER_OF_BOOKS - 1; i++) { // Dịch chuyển dữ liệu để xóa
            strcpy(ISBNs[i], ISBNs[i + 1]); // Dịch ISBN
            strcpy(TITLES[i], TITLES[i + 1]); // Dịch tiêu đề
            strcpy(AUTHORS[i], AUTHORS[i + 1]); // Dịch tác giả
            PUBLISHERS[i] = PUBLISHERS[i + 1]; // Dịch chỉ số NXB
            strcpy(PUBLISH_YEARS[i], PUBLISH_YEARS[i + 1]); // Dịch năm XB
            CATEGORIES[i] = CATEGORIES[i + 1]; // Dịch chỉ số thể loại
            PRICES[i] = PRICES[i + 1]; // Dịch giá tiền
            STOCKS[i] = STOCKS[i + 1]; // Dịch số lượng
        }
        NUMBER_OF_BOOKS--;      // Giảm số lượng sách
        printf("Xoa thanh cong\n"); // Thông báo thành công
    } else if (choice != 0) {   // Nếu không tìm thấy và không thoát
        printf("Xoa khong thanh cong\n"); // Thông báo thất bại
    }
}

// 2.5. TÌM KIẾM SÁCH THEO ISBN

void searchBookByISBN() {       // Tìm kiếm sách theo ISBN
    char isbn[MAX_ISBN];        // Chuỗi ISBN cần tìm
    
    getchar();                  // Xóa ký tự thừa
    printf("Nhap isbn cua sach: "); // Yêu cầu nhập ISBN
    fgets(isbn, sizeof(isbn), stdin); // Nhập chuỗi ISBN
    isbn[strcspn(isbn, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
    
    printf("%s\n", isbn);       // In ISBN (test)
    
    int index = findBookByISBN(isbn); // Tìm chỉ số sách
    printf("KET QUA\n");        // Tiêu đề kết quả
    
    if (index != -1) {          // Nếu tìm thấy
        viewBookHeader();       // In tiêu đề bảng
        viewBook(index);        // In thông tin sách
        printf("\n");
    } else {                    // Nếu không tìm thấy
        printf("Khong tim thay sach co isbn: %s\n", isbn); // Thông báo lỗi
    }
}

// 2.6. TÌM KIẾM SÁCH THEO TÊN

void searchBookByTitle() {      // Tìm kiếm sách theo tên
    char title[MAX_TITLE];      // Chuỗi tên sách cần tìm
    int saveIndex[20];          // Mảng lưu chỉ số các sách tìm thấy
    int index = 0;              // Số lượng sách tìm thấy
    
    printf("Nhap ten can tim: "); // Yêu cầu nhập tên
    fgets(title, sizeof(title), stdin); // Nhập chuỗi tên
    title[strcspn(title, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
    
    convertToLower(title, title); // Chuyển tên nhập vào thành chữ thường
    
    for (int i = 0; i < NUMBER_OF_BOOKS; i++) { // Duyệt qua danh sách sách
        char temp[MAX_TITLE];   // Chuỗi tạm lưu tên sách
        convertToLower(TITLES[i], temp); // Chuyển tên sách thành chữ thường
        if (findSubString(title, temp) != -1) { // Kiểm tra tên nhập vào có trong tên sách
            saveIndex[index++] = i; // Lưu chỉ số sách
            printf("%d. %s\n", index, TITLES[i]); // In số thứ tự và tên sách
        }
    }
    
    if (index == 0) {           // Nếu không tìm thấy
        printf("Khong co ten sach\n"); // Thông báo không có kết quả
    } else {                    // Nếu tìm thấy
        int choice;             // Lựa chọn sách
        printf("Chon sach: ");  // Yêu cầu chọn
        scanf("%d", &choice);   // Nhập lựa chọn
        viewBookHeader();       // In tiêu đề bảng
        viewBook(saveIndex[choice - 1]); // In thông tin sách được chọn
    }
}