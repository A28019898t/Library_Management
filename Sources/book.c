#include <stdio.h>
#include <string.h>

#include "..\Headers\book.h"
#include "..\Headers\data.h"
#include "..\Headers\utils.h"

// XEM DANH SÁCH CÁC SÁCH TRONG THƯ VIỆN 
// Hiển thị Header
void viewBookHeader() {
    printf("%-20s", "id");
    printf("%-40s", "Ten sach");
    printf("%-15s", "Tac gia");
    printf("%-15s", "Nha xuat ban");
    printf("%-15s", "Nam xuat ban");
    printf("%-25s", "The loai");
    printf("%-15s", "Gia tien");
    printf("%-5s", "So luong");
    printf("\n");
}
// Hiển thị 1 đọc giả dựa trên index
void viewBook(int index) {
    printf("%-20s", ISBNs[index]);
    printf("%-40s", TITLES[index]);
    printf("%-15s", AUTHORS[index]);
    printf("%-15s", PUBLISHERS[index]);
    printf("%-15s", PUBLISH_YEARS[index]);
    printf("%-25s", GENRES[CATEGORIES[index]]);
    printf("%-15.0f", PRICES[index]*1000);
    printf("%-5d", STOCKS[index]);
    printf("\n");
}
// hiển thị toàn bộ đọc giả
void viewAllBooks() {
    viewBookHeader();

    for(int i = 0; i < NUMBER_OF_BOOKS; i++) {
        viewBook(i);
    }
}

// THÊM SÁCH
// Hàm nhập thể loại sách
int inputCategory(char* str) {
    int choice;
    printf("%s\n", str);

    for (int i = 0; i < NUMBER_OF_GENRES; i++) {
        printf("[%d]: %s\n", i + 1, GENRES[i]);
    }

   do {
        printf("Nhap lua chon [?]: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 10) {
            printf("Nhap sai lua chon. Moi nhap lai");
        }

   } while (choice < 1 || choice > 10);

   return choice - 1;
}

void addBook() {
    char isbn[MAX_ISBN]; // chưa tính
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char publisher[MAX_PUBLISHER];
    char publishYear[MAX_YEAR];
    int category;
    float price;
    int stock;

    getchar();

    inputString("Nhap ten sach: ", title, MAX_TITLE);
    inputString("Nhap ten tac gia: ", author, MAX_AUTHOR);
    inputString("Nhap ten nha xuat ban: ", publisher, MAX_PUBLISHER);
    inputString("Nhap nam xuat ban: ", publishYear, MAX_YEAR);
    category = inputCategory("Nhap the loai: ");
    printf("Nhap gia: ");
    scanf("%f", &price);
    printf("Nhap so luong: ");
    scanf("%d", &stock);

    if (NUMBER_OF_BOOKS < MAX_BOOKS) {
        strcpy(ISBNs[NUMBER_OF_BOOKS], "DG003"); //chưa tính
        strcpy(TITLES[NUMBER_OF_BOOKS], title);
        strcpy(AUTHORS[NUMBER_OF_BOOKS], author);
        strcpy(PUBLISHERS[NUMBER_OF_BOOKS], publisher);
        strcpy(PUBLISH_YEARS[NUMBER_OF_BOOKS], publishYear);
        CATEGORIES[NUMBER_OF_BOOKS] = category;
        PRICES[NUMBER_OF_BOOKS] = price;
        STOCKS[NUMBER_OF_BOOKS] = stock;

        NUMBER_OF_BOOKS++;
    } else {
        printf("Khong du bo nho\n");
    }

}

// Tìm sách dựa trên mã isbn của sách
int findBookByISBN(char* isbn){
    int index;

    for (int i = 0; i < NUMBER_OF_BOOKS; i++) {
        index = i;

        int valid = strcmp(isbn, ISBNs[i]);

        if (valid == 0) {
            break;
        } else {
            index = -1;
        }
    }

    return index;
}

// CHỈNH SỬA THÔNG TIN MỘT QUYỂN SÁCH 
void editInfoBook() {
    char title[MAX_TITLE];
    int saveIndex[20];
    int index = 0;
    int valid;

    getchar();
    printf("Nhap ten can tim: ");
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
        int selection;
        printf("Chon sach: ");
        scanf("%d", &choice);
        

        do {
            printf("THONG TIN SACH\n");
            viewBookHeader();
            viewBook(saveIndex[choice - 1]);
            printf("\n");

            printf("[1]: Ten sach\n");
            printf("[2]: Tac gia\n");
            printf("[3]: Nha xuat ban\n");
            printf("[4]: Nam xuat ban\n");
            printf("[5]: The loai\n");
            printf("[6]: Gia tien\n");
            printf("[7]: So luong\n");
            printf("[0]: Thoat\n");

            printf("Chon muc can dieu chinh [ ? ]: ");
            scanf("%d", &selection);
            getchar();
            
            switch(selection) {
                case 0:
                    break;
                case 1:
                    inputString("Nhap ten sach: ", TITLES[saveIndex[choice - 1]], MAX_TITLE);
                    break;
                case 2:
                    inputString("Nhap ten tac gia: ", AUTHORS[saveIndex[choice - 1]], MAX_AUTHOR);
                    break;
                case 3:
                    inputString("Nhap ten nha xuat ban: ", PUBLISHERS[saveIndex[choice - 1]], MAX_PUBLISHER);
                    break;
                case 4:
                    inputString("Nhap nam xuat ban: ", PUBLISH_YEARS[saveIndex[choice - 1]], MAX_YEAR);
                    break;
                case 5:
                    CATEGORIES[saveIndex[choice - 1]] = inputCategory("Nhap the loai: ");
                    break;
                case 6:
                    printf("Nhap gia tien: ");
                    scanf("%f", &PRICES[saveIndex[choice - 1]]);
                    break;
                case 7:
                    printf("Nhap so luong: ");
                    scanf("%d", &STOCKS[saveIndex[choice - 1]]);
                    break;
                default:
                    printf("Nhap sai lua chon. Moi ban nhap lai\n");
            }
        } while (selection != 0); 
    }
}

// XÓA THÔNG TIN SÁCH 
void deleteBook() {
    char isbn[MAX_ISBN];

    getchar();
    printf("Nhap isbn cua cua sach: ");

    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';

    int index = findBookByISBN(isbn);

    if (index != -1) {
        // xoá không duy trì thứ tự trong mảng
        strcpy( ISBNs[index], ISBNs[NUMBER_OF_BOOKS  - 1]);
        strcpy( NAMES[index], NAMES[NUMBER_OF_BOOKS  - 1]);
        strcpy( TITLES[index], TITLES[NUMBER_OF_BOOKS  - 1]);
        strcpy( AUTHORS[index], AUTHORS[NUMBER_OF_BOOKS  - 1]);
        strcpy( PUBLISHERS[index], PUBLISHERS[NUMBER_OF_BOOKS  - 1]);
        strcpy( PUBLISH_YEARS[index], PUBLISH_YEARS[NUMBER_OF_BOOKS  - 1]);
        CATEGORIES[index] = CATEGORIES[NUMBER_OF_BOOKS  - 1];
        
        PRICES[index] = PRICES[NUMBER_OF_BOOKS  - 1];
        STOCKS[index] = STOCKS[NUMBER_OF_BOOKS  - 1];
    
        NUMBER_OF_BOOKS--;
    } else {
        printf("Khong tim thay sach co isbn: %s\n", isbn);
    }
}

// TÌM KIẾM SÁCH THEO ISBN 
void searchBookByISBN() {
    char isbn[MAX_ISBN];

    getchar();
    printf("Nhap isbn cua sach: ");
    fgets(isbn, sizeof(isbn), stdin);
    isbn[strcspn(isbn, "\n")] = '\0';

    printf("%s\n", isbn);
    
    int index = findBookByISBN(isbn);

    printf("KET QUA\n");

    if (index != -1) {
        viewBookHeader();
        viewBook(index);

    printf("\n");
    } else {
        printf("Khong tim thay sach co isbn: %s\n", isbn);
    }
}

// TÌM KIẾM SÁCH THEO TÊN SÁCH
void searchBookByTitle() {
    char title[MAX_TITLE];
    int saveIndex[20];
    int index = 0;
    int valid;

    getchar();
    printf("Nhap ten can tim: ");
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
    }
}
