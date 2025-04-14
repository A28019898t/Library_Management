#include <stdio.h>              // Thư viện chuẩn cho nhập/xuất dữ liệu
#include <stdlib.h>             // Thư viện hỗ trợ lệnh system (cls, pause)
#include <string.h>             // Thư viện xử lý chuỗi ký tự

#include "..\Headers\data.h"    // File header chứa định nghĩa dữ liệu và mảng toàn cục
#include "..\Headers\utils.h"   // File header chứa các hàm tiện ích (getToday, findSubString, v.v.)
#include "..\Headers\book.h"    // File header chứa hàm quản lý sách
#include "..\Headers\reader.h"  // File header chứa hàm quản lý độc giả

// 4. QUẢN LÝ MƯỢN TRẢ SÁCH

// 4.1. LẬP PHIẾU MƯỢN SÁCH

void createBorrowTicket() {     // Tạo phiếu mượn sách mới
    char readerId[MAX_ID];      // Mã độc giả
    char borrowDate[MAX_DATE];  // Ngày mượn
    char returnDate[MAX_DATE];  // Ngày trả dự kiến
    int indexReaderID;
    
    inputString("Nhap ma doc gia: ", readerId, MAX_ID); // Nhập mã độc giả
    indexReaderID = findReaderById(readerId);
    if (indexReaderID == -1) { // Kiểm tra mã độc giả tồn tại
        printf("Nhap sai ma doc gia\n"); // Thông báo lỗi
        system("pause");        // Tạm dừng để xem kết quả (Windows)
        return;
    }
    
    BORROW_IDS[NUMBER_OF_BORROW_TICKETS] = indexReaderID; // Lưu mã độc giả vào mảng
    getToday(borrowDate);       // Lấy ngày hiện tại làm ngày mượn
    strcpy(BORROW_DATE[NUMBER_OF_BORROW_TICKETS], borrowDate); // Lưu ngày mượn
    
    char title[MAX_TITLE];      // Chuỗi tên sách cần tìm
    int saveIndex[20];          // Mảng lưu chỉ số sách tìm thấy
    int index;                  // Số lượng sách tìm thấy
    char isContinue;            // Biến quyết định tiếp tục mượn
    int count = 0;              // Số sách mượn trong phiếu
    int end = (NUMBER_OF_BORROW_TICKETS == 0) ? -1 : (NUMBER_OF_BORROW_BOOK - 1); // Vị trí kết thúc của phiếu trước
     
    do {
        index = 0;              // Đặt lại số lượng sách tìm thấy
        printf("Nhap ten can sach: "); // Yêu cầu nhập tên sách
        fgets(title, sizeof(title), stdin); // Nhập chuỗi tên
        title[strcspn(title, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
        
        convertToLower(title, title); // Chuyển tên nhập vào thành chữ thường
        
        for (int i = 0; i < NUMBER_OF_BOOKS; i++) { // Duyệt qua danh sách sách
            char temp[MAX_TITLE]; // Chuỗi tạm lưu tên sách
            convertToLower(TITLES[i], temp); // Chuyển tên sách thành chữ thường
            if (findSubString(title, temp) != -1) { // Kiểm tra tên nhập vào có trong tên sách
                saveIndex[index++] = i; // Lưu chỉ số sách
                printf("[%d]: %s\n", index, TITLES[i]); // In số thứ tự và tên sách
            }
        }
        
        if (index == 0) {       // Nếu không tìm thấy sách
            printf("Khong co ten sach\n"); // Thông báo không có kết quả
        } else {                // Nếu tìm thấy
            int choice;         // Lựa chọn sách
            printf("Chon sach: "); // Yêu cầu chọn
            scanf("%d", &choice); // Nhập lựa chọn
            getchar();              // Xóa ký tự thừa
            viewBookHeader();   // In tiêu đề bảng sách
            viewBook(saveIndex[choice - 1]); // In thông tin sách được chọn
            
            if (count == 0) {   // Nếu là sách đầu tiên trong phiếu
                BORROW_START[NUMBER_OF_BORROW_TICKETS] = end + 1; // Lưu vị trí bắt đầu
            }
            count++;            // Tăng số sách mượn
            
            if (STOCKS[saveIndex[choice - 1]] > 0) { // Kiểm tra còn sách trong kho
                BORROW_BOOKS[end + count] = saveIndex[choice - 1]; // Lưu ISBN
                NUMBER_OF_BORROW_BOOK++; // Tăng tổng số sách đang mượn
                STOCKS[saveIndex[choice - 1]]--; // Giảm số lượng trong kho
            } else {            // Nếu hết sách
                printf("Sach: %s da het\n", TITLES[saveIndex[choice - 1]]); // Thông báo lỗi
            }
        }
        
        printf("Nhap them sach muon [?] (Y/N): "); // Hỏi tiếp tục mượn
        scanf("%c", &isContinue); // Nhập lựa chọn Y/N
        getchar();              // Xóa ký tự thừa
    } while (isContinue == 'y' || isContinue == 'Y'); // Lặp lại nếu chọn Y
    
    printf("THE MUON SACH\n"); // In thông tin phiếu mượn
    printf("Ma doc gia: %s\n", IDS[BORROW_IDS[NUMBER_OF_BORROW_TICKETS]]); // In mã độc giả
    printf("Ngay muon: %s\n", BORROW_DATE[NUMBER_OF_BORROW_TICKETS]); // In ngày mượn
    getDateFromKDays(BORROW_DATE[NUMBER_OF_BORROW_TICKETS], returnDate, 7); // Tính ngày trả dự kiến (7 ngày sau)
    printf("Ngay tra du kien: %s\n", returnDate); // In ngày trả
    printf("Sach da muon: \n"); // In danh sách sách mượn
    for (int i = BORROW_START[NUMBER_OF_BORROW_TICKETS]; i <NUMBER_OF_BORROW_BOOK; i++) {
        printf("[%d]: %s\n", i - BORROW_START[NUMBER_OF_BORROW_TICKETS] + 1, TITLES[BORROW_BOOKS[i]]); // In từng ISBN
    }
    
    NUMBER_OF_BORROW_TICKETS++; // Tăng số lượng phiếu mượn
    system("pause");        // Tạm dừng để xem kết quả (Windows)

}

// Hàm hỗ trợ quản lý mượn trả

int findReaderBorrowBooksByID(char* id, int result[]) { // Tìm phiếu mượn của độc giả theo ID
    int index = 0;              // Số lượng phiếu tìm thấy
    int indexReaderID = findReaderById(id);
    if(indexReaderID == -1) return -1;
    for (int i = 0; i < NUMBER_OF_BORROW_TICKETS; i++) { // Duyệt qua danh sách phiếu mượn
        if (indexReaderID == BORROW_IDS[i]) { // So sánh mã độc giả
            result[index++] = i; // Lưu chỉ số phiếu
        }
    }
    return index;               // Trả về số lượng phiếu tìm thấy
}

void deleteBorrowTicketByIndex(int index) { // Xóa phiếu mượn tại chỉ số index
    int start = BORROW_START[index]; // Vị trí bắt đầu của sách mượn
    int end = BORROW_START[index + 1] - 1; // Vị trí kết thúc của sách mượn
    
    // Dịch chuyển dữ liệu từ phiếu cuối cùng để thay thế
    BORROW_IDS[index] = BORROW_IDS[NUMBER_OF_BORROW_TICKETS - 1]; // Dịch mã độc giả
    strcpy(BORROW_DATE[index], BORROW_DATE[NUMBER_OF_BORROW_TICKETS - 1]); // Dịch ngày mượn
    BORROW_START[index] = BORROW_START[NUMBER_OF_BORROW_TICKETS - 1]; // Dịch vị trí bắt đầu
    
    // Dịch chuyển danh sách ISBN sách mượn
    for (int i = start; i < end; i++) { // Duyệt từ start đến end
        for (int j = i; j < NUMBER_OF_BORROW_BOOK - 1; j++) { // Dịch các phần tử sau
            BORROW_BOOKS[j] = BORROW_BOOKS[j + 1]; // Dịch ISBN
        }
    }
    NUMBER_OF_BORROW_BOOK -= (end - start + 1); // Giảm số lượng sách mượn
    NUMBER_OF_BORROW_TICKETS--; // Giảm số lượng phiếu mượn
}


int removeElementBorrowBook(char arr[][MAX_ISBN], int length, int position) { // Xóa phần tử trong mảng BORROW_BOOKS
    if (position < 0 || position >= length) return length; // Kiểm tra vị trí hợp lệ
    for (int i = position; i < length - 1; i++) { // Dịch chuyển các phần tử sau
        strcpy(arr[i], arr[i + 1]); // Dịch ISBN
    }
    return length - 1;          // Trả về độ dài mới
}

int removeElementBorrowReader(char arr[][MAX_ID], int length, int position) { // Xóa phần tử trong mảng BORROW_IDS
    if (position < 0 || position >= length) return length; // Kiểm tra vị trí hợp lệ
    for (int i = position; i < length - 1; i++) { // Dịch chuyển các phần tử sau
        strcpy(arr[i], arr[i + 1]); // Dịch mã độc giả
    }
    return length - 1;          // Trả về độ dài mới
}

int removeElementBorrowPos(int arr[], int length, int position) { // Xóa phần tử trong mảng BORROW_START/END
    if (position < 0 || position >= length) return length; // Kiểm tra vị trí hợp lệ
    for (int i = position; i < length - 1; i++) { // Dịch chuyển các phần tử sau
        arr[i] = arr[i + 1];    // Dịch vị trí
    }
    return length - 1;          // Trả về độ dài mới
}

void viewBorrowHeader() { // Hiển thị dòng tiêu đề của danh sách mượn sách
    printf("%-5s", "STT");
    printf("%-20s", "ISBN");
    printf("%-40s", "Ten sach");
    printf("%-20s", "Ngay muon sach");
    printf("%-20s", "Ngay tra sach");
    printf("%-20s", "Tinh trang");
    printf("%-15s", "So ngay tre");
    printf("%-10s", "Tien phat tre han");
    printf("\n");
} 

int viewBorrowBook(int seq, char* isbn, char* title, char* borrowDate) {  // Hiển thị sách đã mượn

    printf("%-5d", seq);
    printf("%-20s", isbn);
    printf("%-40s", title);
    printf("%-20s", borrowDate);
    char returnDate[MAX_DATE];
    getDateFromKDays(borrowDate, returnDate, 7);
    printf("%-20s", returnDate);

    char today[MAX_DATE];
    getToday(today);
    int late = dateDifference(borrowDate, today) - 7;
    printf("%-20s", (late > 0) ? "Tre " : "Trong han");

    printf("%-15d", (late > 0) ? late : 0);

    printf("%-10ld", (late > 0) ? late * 5000 : 0);

    printf("\n");

    return late;
}

// 4.2. LẬP PHIẾU TRẢ SÁCH

void createReturnTicket() {     // Tạo phiếu trả sách
    int choice;                 // Lựa chọn menu
    int valid;
    printf("TAO PHIEU TRA SACH\n"); // Tiêu đề
    printf("[1]: Nhap thong tin tra sach\n"); // Lựa chọn nhập thông tin
    printf("[0]: Thoat\n");     // Lựa chọn thoát
    printf("Nhap lua chon [?]: "); // Yêu cầu nhập
    valid = scanf("%d", &choice);       // Nhập lựa chọn
    getchar();                  // Xóa ký tự thừa
    
    if (choice == 1 && valid) {          // Nếu chọn nhập thông tin trả sách
        char readerId[MAX_ID];  // Mã độc giả
        printf("Nhap ma doc gia: "); // Yêu cầu nhập mã
        fgets(readerId, MAX_ID, stdin); // Nhập chuỗi mã
        readerId[strcspn(readerId, "\n")] = '\0'; // Loại bỏ ký tự xuống dòng
        
        int readerBorrows[20];  // Mảng lưu chỉ số phiếu mượn của độc giả
        int isInBorrowTickets = findReaderBorrowBooksByID(readerId, readerBorrows); // Tìm phiếu mượn
        
        if (isInBorrowTickets) { // Nếu độc giả có phiếu mượn
            char selection;     // Biến quyết định tiếp tục trả
            char isLost;        // Biến quyết định sách có bị mất
            int lates[100];     // Mảng lưu số ngày trễ
            int lost[100];      // Mảng lưu sách có bị mất
            int ans[100];       // Mảng lưu lựa chọn sách trả
            int countPos = 0;   // Số lượng sách trong tất cả phiếu mượn
            int countAns = 0;   // Số lượng sách chọn trả
            int temp[100];      // Mảng lưu chỉ số sách trong BOOKS
            int pos[100];       // Mảng lưu vị trí thực trong BORROW_BOOKS
            int ids[100];       // Mảng lưu chỉ số phiếu mượn
            
            printf("THONG TIN MUON SACH\n"); // Tiêu đề thông tin mượn
            viewBorrowHeader();
            for (int i = 0; i < isInBorrowTickets; i++) { // Duyệt qua các phiếu mượn
                int limit = (readerBorrows[i] + 1 == NUMBER_OF_BORROW_TICKETS) ? NUMBER_OF_BORROW_BOOK : BORROW_START[readerBorrows[i] + 1];
                for (int j = BORROW_START[readerBorrows[i]]; j < limit; j++) { // Duyệt qua sách mượn
                    int bookIndex = BORROW_BOOKS[j]; // Tìm chỉ số sách
                    int late = viewBorrowBook(countPos + 1, ISBNs[bookIndex], TITLES[bookIndex], BORROW_DATE[readerBorrows[i]]);
                    lates[countPos] = late;
                    pos[countPos] = j; // Lưu vị trí trong BORROW_BOOKS
                    temp[countPos] = bookIndex; // Lưu chỉ số trong BOOKS
                    ids[countPos] = readerBorrows[i]; // Lưu chỉ số phiếu mượn
                    countPos++;    // Tăng số lượng sách

                }
            }
            
            do {                // Lặp để chọn sách trả
                printf("Chon sach tra [?]: "); // Yêu cầu chọn sách
                scanf("%d", &choice); // Nhập lựa chọn
                getchar();      // Xóa ký tự thừa
                
                if (choice < 1 || choice > countPos) { // Kiểm tra lựa chọn hợp lệ
                    printf("Nhap sai lua chon. Xin moi nhap lai\n"); // Thông báo lỗi
                    continue;
                }

                if (choice == ans[countAns - 1]) {
                    printf("Sach da duoc chon. Moi nhap lai\n");
                    continue;
                }

                printf("Sach co bi mat [?] (y/n): ");
                scanf("%c", &isLost);
                getchar();
                
                lost[countAns] = (isLost == 'y' || isLost == 'Y') ? 1 : 0;
                ans[countAns++] = choice; // Lưu lựa chọn sách trả
                
                printf("Tiep tuc tra sach? [?] (Y/N): "); // Hỏi tiếp tục trả
                scanf("%c", &selection); // Nhập lựa chọn Y/N
                getchar();      // Xóa ký tự thừa
            } while (selection == 'y' || selection == 'Y'); // Lặp lại nếu chọn Y
            
            int lengthOfIsbnBook = NUMBER_OF_BORROW_BOOK; // Độ dài mảng BORROW_BOOKS
            printf("\nTien hanh cap nhap lai du lieu:\n"); // Thông báo cập nhật
            
            for (int i = 0; i < countAns; i++) { // Xóa sách khỏi BORROW_BOOKS
                lengthOfIsbnBook = removeElementInArray(BORROW_BOOKS, lengthOfIsbnBook, pos[ans[i] - 1] - i); // Xóa và điều chỉnh vị trí
                STOCKS[temp[ans[i] - 1]]++; // Tăng số lượng sách trong kho
            }
            NUMBER_OF_BORROW_BOOK = lengthOfIsbnBook; // Cập nhật tổng số sách mượn
            
            for (int i = 0; i < countAns; i++) { // Điều chỉnh BORROW_START và BORROW_END
                for (int j = ids[ans[i] - 1] + 1; j < NUMBER_OF_BORROW_TICKETS; j++) { // Giảm start của các phiếu sau
                    BORROW_START[j]--;
                }
            }
            
            int lengthOfTickets = NUMBER_OF_BORROW_TICKETS; // Độ dài mảng phiếu mượn

            for (int i = 0; i < countAns; i++) { // Kiểm tra và xóa phiếu rỗng
                if (BORROW_START[ids[ans[i] - 1]] == -1) { // Nếu phiếu không còn sách
                    removeElementBorrowPos(BORROW_START, lengthOfTickets, ids[ans[i] - 1]); // Xóa start
                    lengthOfTickets = removeElementInArray(BORROW_IDS, lengthOfTickets, ids[ans[i] - 1]); // Xóa mã độc giả
                }
            }
            NUMBER_OF_BORROW_TICKETS = lengthOfTickets; // Cập nhật số lượng phiếu mượn
            
            printf("TRA SACH THANH CONG\n");

            // in phiếu trả sách, tính tiền phạt
            // Ngày trả thực tế
            // Danh sách sách trả
            // Số tiền phạt nếu có
            // Lưu dữ liệu các đọc giả bị phạt đề làm cơ sở thống kê black list
            char today[MAX_DATE];
            getToday(today);
            int total = 0;
            int blackList = 0;
            printf("PHIEU TRA SACH\n");
            printf("Ngay tra thuc te: %s\n", today);
            printf("Danh sach sach tra: \n"); // sử dụng mảng temp: mảng lưu chỉ số index sách đã mượn, ans: mảng lưu chỉ số trả
            for(int i = 0; i < countAns; i++) {
                int lateReturn = lates[ans[i] - 1];
                int penalty = lateReturn * 5000 + ((lost[ans[i] - 1]) ? PRICES[temp[ans[i] - 1]] * 2000 : 0 );
                total += penalty;
                blackList += lost[ans[i] - 1];
                printf("[%d]: %-40s Tre: %-3d ngay; Mat: %d Phat: %-10ld \n", i + 1, TITLES[temp[ans[i] - 1]], lateReturn, lost[ans[i] - 1], penalty); // in danh sách đã trả
            }
            printf("Tong tien phat la: %d", total);

            // Cập nhật blackList
            if(total > 0) {
                int indexReader = findReaderById(readerId);
                BLACK_LIST[indexReader] += total;
            }

        } else {            
                // Nếu không có phiếu mượn
            if (findReaderById(readerId) == -1) { // Kiểm tra mã độc giả tồn tại
                printf("Id khong ton tai\n"); // Thông báo lỗi
            } else {
                printf("Ma doc gia sai hoac khong co trong danh sach muon sach\n"); // Thông báo lỗi
            }
        }
    } else if (choice != 1 && !valid) {
        printf("Nhap sai lua chon\n");
    }
    system("pause");        // Tạm dừng để xem kết quả (Windows)
}