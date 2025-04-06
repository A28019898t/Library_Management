#include <stdio.h>
#include <string.h>

#include "..\Headers\data.h"
#include "..\Headers\utils.h"
#include "..\Headers\book.h"
#include "..\Headers\reader.h"

// LẬP PHIẾU MƯỢN SÁCH  
/* THẺ MƯỢN SÁCH
    1. Mã đọc giả
    2. Ngày mượn
    3. Ngày trả dự kiến (mỗi sách được mượn tối đa 7 ngày)
    4. Danh sách ISBN của các sách được mượn
*/
void createBorrowTicket() {
    char readerId[MAX_ID];
    char borrowDate[MAX_DATE];
    char returnDate[MAX_DATE];
    
    getchar();

    inputString("Nhap ma doc gia: ", readerId, MAX_ID);

    if (findReaderById(readerId) == - 1) {
        printf("Nhap sai ma doc gia\n");
        return;
    }
    strcpy(BORROW_IDS[NUMBER_OF_BORROW_TICKETS], readerId); // lưu id của đọc giả
    
    getToday(borrowDate);
    strcpy(BORROW_DATE[NUMBER_OF_BORROW_TICKETS], borrowDate); // lưu ngày mượn

    getDateFromKDays(borrowDate, returnDate, 7);
    strcpy(BORROW_DATE[NUMBER_OF_BORROW_TICKETS], borrowDate); // lưu ngày mượn strcpy(BORROW_RETURN_DATE[NUMBER_OF_BORROW_TICKETS], returnDate);  // lưu ngày trả dự kiến

    char title[MAX_TITLE];
    int saveIndex[20];
    int index;
    int valid;
    char isContinue;
    int count = 0;
    int end = BORROW_END[NUMBER_OF_BORROW_TICKETS - 1];

    do {
        index = 0; // khởi tạo số thứ tự cho sách
        printf("Nhap ten can sach: ");
        fgets(title, sizeof(title), stdin);
        title[strcspn(title, "\n")] = '\0';

        convertToLower(title, title);

        for (int i = 0; i < NUMBER_OF_BOOKS; i++) {
            char temp[MAX_TITLE];
            convertToLower(TITLES[i], temp);
            valid = findSubString(title, temp);
            
            if (valid != -1) {
                saveIndex[index++] = i;

                // hiển thị ra màn hình
                printf("%d. %s\n", index, TITLES[i] );
            }
        }

        if(index == 0) {
            printf("Khong co ten sach");
        } else {
            int choice;
            printf("Chon sach: ");
            scanf("%d", &choice);
            viewBookHeader();
            viewBook(saveIndex[choice - 1]);
            // Cập nhật dữ liệu cho các mảng sau
            if (count == 0) { // Cập nhật dữ liệu cho bất đầu
                BORROW_START[NUMBER_OF_BORROW_TICKETS] = end + 1; // Lưu vị trí bắt đầu của sách mượn ở id[start]
            }
            count++; // tăng lên 1 đơn vị đo

            if (STOCKS[choice - 1] > 0) {
                strcpy(BORROW_ISBN_BOOKS[end + count], ISBNs[choice - 1]);
                NUMBER_OF_ISBN_BOOK++; // lưu mã isbn của sách vào mảng lưu trữ
                STOCKS[choice - 1]--;
            } else {
                printf("Sach: %s da het", TITLES[choice - 1]);
            }
        }

        getchar();
        printf("Nhap then sach muon [?] (Y/N): ");
        scanf("%c", &isContinue);
        getchar();

    } while(isContinue == 'y' || isContinue == 'Y');


    // kết thúc chọn sách mượn
    BORROW_END[NUMBER_OF_BORROW_TICKETS] = end + count;

    printf("THE MUON SACH\n");
    printf("Ma doc gia: %s\n", BORROW_IDS[NUMBER_OF_BORROW_TICKETS]);
    printf("Ngay muon: %s\n", BORROW_DATE[NUMBER_OF_BORROW_TICKETS]);
    printf("Ngay tra du kien: %s\n", BORROW_RETURN_DATE[NUMBER_OF_BORROW_TICKETS]);
    // printf("%d\n", BORROW_START[NUMBER_OF_BORROW_TICKETS]);
    // printf("%d\n", BORROW_END[NUMBER_OF_BORROW_TICKETS]);

    printf("Sach da muon: \n");
    for (int i = BORROW_START[NUMBER_OF_BORROW_TICKETS]; i <= BORROW_END[NUMBER_OF_BORROW_TICKETS]; i++) {
        printf("%s\n", BORROW_ISBN_BOOKS[i]);
    }
    
    NUMBER_OF_BORROW_TICKETS++;
}   

// tìm thông tin của đọc giả trong dữ liệu mượn sách.
int findReaderBorrowBooksByID(char* id, int result[]) {
    int index = 0;

    for (int i = 0; i < NUMBER_OF_BORROW_TICKETS; i++) {
        if (strcmp(id, BORROW_IDS[i]) == 0) {
            result[index++] = i;
        }
    }

    if (index == 0) {
        printf("Doc gia co id: %s chua muon sach\n", id);
    }

    return index;
}

// xoá thông tin trong danh sách mượn sách; và lưu thông tin trong danh sách trả sách để theo dõi và trích xuất thông tin khi cần thiết
void deleteBorrowTicketByIndex(int index) {
    int start = BORROW_START[index];
    int end = BORROW_END[index];
    
    strcpy(BORROW_IDS[index], BORROW_IDS[NUMBER_OF_BORROW_TICKETS - 1]);
    strcpy(BORROW_DATE[index], BORROW_DATE[NUMBER_OF_BORROW_TICKETS]); // lưu ngày mượn
    strcpy(BORROW_DATE[index], BORROW_DATE[NUMBER_OF_BORROW_TICKETS - 1]); // lưu ngày mượn
    BORROW_START[index] = BORROW_START[NUMBER_OF_BORROW_TICKETS - 1]; // Lưu vị trí bắt đầu của sách mượn ở id[start]
    BORROW_END[index] = BORROW_END[NUMBER_OF_BORROW_TICKETS - 1];

    for (int i = start; i < end; i++) {
        for (int j = i + 1; j < NUMBER_OF_ISBN_BOOK - (end - start) - 1; j++) {// .... [start .... end] .... (NUMBER_OF_ISBN_BOOK - 1)
            strcpy(BORROW_ISBN_BOOKS[i], BORROW_ISBN_BOOKS[j]);
        }
    }
}

// lưu vào trong mảng returnTickets
void storeReturnTicketData(char* readerId, char* bookId, char* borrowDate, char* returnDate, char* realReturnDate, wchar_t lossBook, int forfeit) {
    printf("storeReturnTicketData");
}

// Loại bỏ phẩn tử của BORROW_ISBN_BOOKS ở bất kỳ vị trí nào 
int removeElementBorrowBook(char arr[][MAX_ISBN], int length, int position) {

    if (position == length - 1) {
        return length - 1;
    }

    for (int i = position; i < length - 1; i++) {
        strcpy(arr[i], arr[i + 1]);
    }

    return length - 1;
}

// Loại bỏ phẩn tử của BOOK_IDS ở bất kỳ vị trí nào 
int removeElementBorrowReader(char arr[][MAX_ID], int length, int position) {
    
    if (position == length - 1) {
        return length - 1;
    }

    for (int i = position; i < length - 1; i++) {
        strcpy(arr[i], arr[i + 1]);
    }

    return length - 1;
}

// Loại bỏ phẩn tử của BORROW_START / END ở bất kỳ vị trí nào 
int removeElementBorrowPos(int arr[], int length, int position) {
       
    if (position == length - 1) {
        return length - 1;
    }

    for (int i = position; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return length - 1;
}

// LẬP PHIẾU TRẢ SÁCH
void createReturnTicket() {
    int choice;
    
    printf("TAO PHIEU TRA SACH\n");

    printf("[1]: Nhap thong tin tra sach\n");
    printf("[0]: Thoat\n");
    printf("Nhap lua chon [?]: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        char readerId[MAX_ID]; // cung cấp tìm kiếm đọc giả qua tên, cmnd, mã đọc giả
        int isInBorrowTickets;
        int tempBooks[10];

        printf("Nhap ma doc gia: ");
        fgets(readerId, MAX_ID, stdin);
        readerId[strcspn(readerId, "\n")] = '\0';

        int valid = findReaderById(readerId);

        if (valid == -1) {
            printf("Id khong ton tai\n");
            return;
        }

        int ReaderBorrows[20];
        isInBorrowTickets = findReaderBorrowBooksByID(readerId, ReaderBorrows); // kiểm tra đọc giả có trong dữ liệu mượn sách không

        if (isInBorrowTickets) {
            
            char selection;
            int ans[100];
            int countPos = 0;
            int countAns = 0;
            int temp[100];
            int pos[100];
            int ids[100];

            printf("THONG TIN MUON SACH\n");

            for (int i = 0; i < isInBorrowTickets; i++) {
                printf(" %s - %s\n", BORROW_DATE[ReaderBorrows[i]], BORROW_RETURN_DATE[ReaderBorrows[i]]);

                for (int j =  BORROW_START[ReaderBorrows[i]]; j <= BORROW_END[ReaderBorrows[i]]; j++) {
                    printf("[%d]: %s - ", countPos + 1, BORROW_ISBN_BOOKS[j]);
                    int book = findBookByISBN(BORROW_ISBN_BOOKS[j]);
                    pos[countPos] = j; // Lưu vị trí thật của các sách trong mảng ISBN mượn
                    temp[countPos] = book; // Lưu index của sách từ mảng ISBN vào mảng phụ để hiển thị thông tin của sách
                    ids[countPos] = ReaderBorrows[i];
                    countPos++;
                    printf("%s\n", TITLES[book]);
                    
                }
            }

            do {
    
                printf("Chon sach tra [?]: ");
                scanf("%d", &choice);
                getchar();

                if (choice > countPos) {
                    printf("Nhap sai lua chon. Xin moi nhap lai\n");
                    continue;
                }

                ans[countAns++] = choice; // lưu các lựa chọn dựa trên mảng temp

                
    
                printf("Test: %s %s (%d %d)\n", TITLES[temp[choice - 1]], BORROW_DATE[temp[choice - 1]], BORROW_START[pos[choice - 1]], BORROW_END[pos[choice - 1]]); 
                printf("Tiep tuc tra sach? [?] (Y/N): ");
                scanf("%c", &selection);
                getchar();

            } while(selection == 'y' || selection == 'Y' );
           
            // Tiến hành cập nhập dữ liệu theo lựa chọn dựa theo ans -> temp -> pos
            printf("temp array: ");
            for (int i = 0; i < countPos; i++) {
                printf("%d ", temp[i]);
            }
            printf("\npos array: ");
            for (int i = 0; i < countPos; i++) {
                printf("%d ", pos[i]);
            }
            printf("\nans array: ");
            for (int i = 0; i < countAns; i++) {
                printf("%d ", ans[i]);
            }
            printf("\nids borrow array: ");
            for (int i = 0; i < countAns; i++) {
                printf("%d ", ids[ans[i] - 1]);
            }
            
            int lengthOfIsbnBook = NUMBER_OF_ISBN_BOOK;

            printf("\nTien hanh cap nhap lai du lieu:\n");

            // Xoá các sách ra khỏi ISBN sách mượn
            for (int i = 0; i < countAns; i++) {
                lengthOfIsbnBook = removeElementBorrowBook(BORROW_ISBN_BOOKS, lengthOfIsbnBook, pos[ans[i] - 1] - i);
            }
            NUMBER_OF_ISBN_BOOK = lengthOfIsbnBook;

            for(int i = 0 ; i < countAns; i++) {
                // giảm các start từ id + 1 đến hết xuống 1
                for (int j = ids[ans[i] - 1] + 1; j < NUMBER_OF_BORROW_TICKETS; j++) {
                    BORROW_START[j]--;
                }
                // giảm các end từ id đến hết xuống 1
                for (int j = ids[ans[i] - 1]; j < NUMBER_OF_BORROW_TICKETS; j++) {
                    BORROW_END[j]--;
                }  
            }

            int lengthOfTickets = NUMBER_OF_BORROW_TICKETS;

            for (int i = 0; i < NUMBER_OF_BORROW_TICKETS; i++) {
                // nếu end < start thì tiến hành xoá đọc giả khỏi phiếu mượn luôn
                if (BORROW_END[ids[ans[i] - 1]] < BORROW_START[ids[ans[i] - 1]]) {
                    // Xoá đi start và end
                    removeElementBorrowPos(BORROW_START, lengthOfTickets, ids[ans[i] - 1]);
                    removeElementBorrowPos(BORROW_END, lengthOfTickets, ids[ans[i] - 1]);

                    // Xoá borrow_ids
                    lengthOfTickets = removeElementBorrowReader(BORROW_IDS, lengthOfTickets, ids[ans[i] - 1]);

                }
            }
            NUMBER_OF_BORROW_TICKETS = lengthOfTickets;

            printf("Borrow star-end: \n");
            for (int i = 0; i < NUMBER_OF_BORROW_TICKETS; i++) {
                printf("%d_%d\n", BORROW_START[i], BORROW_END[i]);
            }

            printf("Number of books in borrow ticket: %d\n", NUMBER_OF_ISBN_BOOK);
            for(int i = 0; i < NUMBER_OF_ISBN_BOOK; i++) {
                printf("%s \n", BORROW_ISBN_BOOKS[i]);
            }
            
        } else {  
            printf("Ma doc gia sai hoac khong co trong danh sach muon sach\n");
        }
    }
} 