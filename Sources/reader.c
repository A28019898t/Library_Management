#include <stdio.h>
#include <string.h>

#include "..\Headers\reader.h"
#include "..\Headers\data.h"
#include "..\Headers\utils.h"

// XEM DANH SÁCH ĐỘC GIẢ TRONG THƯ VIỆN
// Hiển thị Header
void viewReaderHeader() {
    printf("%-10s", "id");
    printf("%-20s", "Ho va ten");
    printf("%-15s", "CMND/CCCD");
    printf("%-15s", "Ngay sinh");
    printf("%-10s", "Gioi tinh");
    printf("%-20s", "Email");
    printf("%-25s", "Dia chi");
    printf("%-15s", "Ngay lap the");
    printf("%-15s", "Ngay het han the");
    printf("\n");
}
// Hiển thị 1 đọc giả dựa trên index
void viewReader(int index) {
    printf("%-10s", IDS[index]); // id
    printf("%-20s", NAMES[index]); // Ho va ten
    printf("%-15s", CIC_NUMBERS[index]); // CMND/CCCD
    printf("%-15s", BIRTHDAYS[index]); // Ngay sinh
    printf("%-10s", (GENDERS[index] == 1) ? "Nam" : "Nu"); // Gioi tinh
    printf("%-20s", EMAILS[index]); // Email
    printf("%-25s", ADDRESSES[index]); // Dia chi
    printf("%-15s", ISSUE_DATES[index]); // Ngay lap the
    printf("%-15s", EXPIRY_DATES[index]); // Ngay het han the
    printf("\n");
}
// hiển thị toàn bộ đọc giả
void viewAllReaders() {
    viewReaderHeader();

    for(int i = 0; i < NUMBER_OF_READERS; i++) {
        viewReader(i);
    }
}

// THÊM ĐỘC GIẢ
// sinh ra mã đọc giả
void generateCodeReader(char* code) {
    char* lastReaderID = IDS[NUMBER_OF_READERS - 1];
    char sub[4];
    int num;

    strcpy(sub, lastReaderID + 2);
    
    sscanf(sub, "%d", &num);
    
    num++;
    intToString(sub, num);
    strcpy(code, "DG");
    // chia trường hợp để thêm số 0 vào trước mã
    if (num / 1000  < 0 && num / 100 > 1) { // sồ từ 100 - 999 không cần thủ tục thêm số 0
        strcat(code, sub);
    } else if (num / 100 < 0 && num / 10 > 1) { // số từ 10 - 99 thêm 1 số 0
        strcat(code, "0");
        strcat(code, sub);
    } else {
        strcat(code, "00");
        strcat(code, sub);
    }

}

// hàm nhập tên
void inputName(char* name, int size) {
    getchar();

    printf("Ho va ten: ");
    fgets(name, size, stdin);
    name[strcspn(name, "\n")] = '\0';
}

// hàm nhập CMND/CCCD
void inputCIC(char* cic, int size) {
    int valid;
    
    do {
        int index = 0;
        valid = 1;
        printf("CMND/CCCD: ");
        fgets(cic, size, stdin); // kiem tra tai sao khong nhap duoc bang bien cmnd
        cic[strcspn(cic, "\n")] = '\0'; // đổi ký tự \n thành \0 kết thúc chuỗi

            if (!isNumber(cic)) {
                valid = 0;
                index++;
                printf("CMND/CCCD phai la so");
                continue;
            }

            if (findReaderByCIC(cic) != -1) {
                valid = 0;
                printf("CMND/CCCD da ton tai trong thu vien");
                continue;
            }

            switch (strlen(cic)) {
                case 9: 
                case 12:
                    break;
                default:
                    valid = 0;
                    printf("CMND co 9 chu so, CCCD co 12 chu so");
            }

            // if (!valid) std::wcout << RESET << std::endl;

        } while(!valid);
}

// hàm nhập giới tính
int inputGender() {
    int choice;
    int valid;
    
    do {
        valid = 1;
        printf("Gioi tinh (Nam / Nu): \n");
        printf("\t[1]: Nam\n");
        printf("\t[2]: Nu\n");
        printf("\tNhap lua chon [ ? ]: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: 
                return 1;
                break;
            case 2:
                return 0;
                break;
            default:
                valid = 0;
                printf("Nhap sai lua chon. Moi nhap lai");
        }
    } while (!valid);

}

// hàm nhập email
void inputEmail(char* email, int size) {
    int valid;
    int countAtSign;
    
    do {
        valid = 1;
        countAtSign = 0;
        printf("Email: ");
        fgets(email, size, stdin);
        email[strcspn(email, "\n")] = '\0';

        if (email[strcspn(email, " ")] != '\0') { // tim khoang trang den cuoi chuoi
            valid = 0;
            printf("Trong email khong co khoang trang");
            continue;
        }

        for (int i = 0; i < strlen(email); i++) {
            switch(email[i]) {
                case ' ':
                    valid = 0;
                    printf("Trong email khong co khoang trang");
                    break;
                case '@':
                    countAtSign++;
            }
        }

        if (countAtSign > 1 || countAtSign == 0) { // có trên 2 @ hoặc không có @ nào
            valid = 0;
            printf("Chi can co 1 dau @ trong email");
        }

    } while(!valid);
}


// hàm nhập địa chỉ
void inputAddress(char* address, int size) {

    printf("Dia chi: ");
    fgets(address, size, stdin);
    address[strcspn(address, "\n")] = '\0';
}


// thêm đọc giả
void addReader() {
    char readerID[MAX_ID];
    char name[MAX_NAME];
    char cic[MAX_CIC];
    int gender;
    char email[MAX_EMAIL];
    char address[MAX_ADDRESS];
    char birthDate[MAX_DATE];
    char issueDate[MAX_DATE];
    char expiryDate[MAX_DATE];
    
    printf("THEM DOC GIA\n");
    
    inputName(name, MAX_NAME);
    printf("%s\n", name); // for test

    inputCIC(cic, MAX_CIC);
    printf("%s\n", cic); // for test
    
    gender = inputGender();
    printf("%d\n", gender); // for test

    inputEmail(email, MAX_EMAIL);
    printf("%s\n", email); // for test

    inputAddress(address, MAX_ADDRESS);
    printf("%s\n", address); // for test

    printf("Ngay sinh: ");
    inputDay(birthDate);
    printf("%s\n", birthDate); // for test

    getToday(issueDate);
    printf("issueDate: %s\n", issueDate); // for test

    getDateFromKMonths(expiryDate, issueDate, 48);
    printf("expiryDate: %s\n", expiryDate); // for test

    // generateCodeReader(readerID);
    // printf("%s\n", readerID); // for test
    

    if (NUMBER_OF_READERS < MAX_READERS) {

        strcpy(IDS[NUMBER_OF_READERS], "DG003");
        strcpy(NAMES[NUMBER_OF_READERS], name);
        strcpy(CIC_NUMBERS[NUMBER_OF_READERS], cic);
        strcpy(BIRTHDAYS[NUMBER_OF_READERS], birthDate);
        GENDERS[NUMBER_OF_READERS] = gender;
        strcpy(EMAILS[NUMBER_OF_READERS], email);
        strcpy(ADDRESSES[NUMBER_OF_READERS], address);
        strcpy(ISSUE_DATES[NUMBER_OF_READERS], issueDate);
        strcpy(EXPIRY_DATES[NUMBER_OF_READERS], expiryDate);
        
        NUMBER_OF_READERS++;
        
        printf("Thanh cong\n");
    } else {
        printf("Khong du bo nho\n");
    }

}

// TÌM ĐỌC GIẢ BẰNG ID
int findReaderById(char* id) {
    int index = -1;

    for (int i = 0; i < NUMBER_OF_READERS; i++) {
        if (strcmp(id, IDS[i]) == 0) {
            index = i;
            break;
        }
    }

    return index;
}

// TÌM ĐỌC GIẢ BẰNG CHỨNG MINH NHÂN DÂN
int findReaderByCIC(char* cic) {
    int index;
    

    for (int i = 0; i < NUMBER_OF_READERS; i++) {
        index = i;

        int valid = strcmp(cic, CIC_NUMBERS[i]);

        if (valid == 0) {
            break;
        } else {
            index = -1;
        }
    }

    return index;
}

// CHỈNH SỬA THÔNG TIN MỘT ĐỘC GIẢ 
void editReaderInfor() {
    char id[MAX_ID];
    int choice;

    printf("Nhap id cua doc gia: ");
    scanf("%s", &id);
    getchar();

    int index = findReaderById(id);
    
    if (index == -1) {
        printf("Khong tim thay doc gia co id: %s\n", id);
    } else {
        do {
            printf("THONG TIN DOC GIA\n");
            viewReaderHeader();
            viewReader(index);
            printf("\n");

            printf("[1]: Ho va ten\n");
            printf("[2]: CMND/CCCD\n");
            printf("[3]: Ngay sinh\n");
            printf("[4]: Gioi tinh\n");
            printf("[5]: Email\n");
            printf("[6]: Dia chi\n");
            printf("[7]: Ngay lap the\n");
            printf("[0]: Thoat\n");

            printf("Chon muc can dieu chinh [ ? ]: ");
            scanf("%d", &choice);
            getchar();
            
            switch(choice) {
                case 0:
                    break;
                case 1:
                    printf("Ho va ten: ");
                    fgets(NAMES[index], MAX_NAME, stdin);
                    NAMES[index][strcspn(NAMES[index], "\n")] = '\0';
                    break;
                case 2:
                    printf("CMND/CCCD: ");
                    inputCIC(CIC_NUMBERS[index], MAX_CIC);
                    break;
                case 3:
                    printf("Ngay sinh: ");
                    inputDay(BIRTHDAYS[index]);
                    break;
                case 4:
                    printf("Gioi tinh: ");
                    GENDERS[index] = inputGender();
                    break;
                case 5:
                    printf("Email: ");
                    inputEmail(EMAILS[index], MAX_EMAIL);
                    break;
                case 6:
                    printf("Dia chi: ");
                    inputAddress(ADDRESSES[index], MAX_ADDRESS);
                    break;
                case 7:
                    printf("Ngay lap the: ");
                    inputDay(ISSUE_DATES[index]);
                    getDateFromKMonths(EXPIRY_DATES[index], ISSUE_DATES[index], 48);
                    break;
                default:
                    printf("Nhap sai lua chon. Moi ban nhap lai\n");
            }
        } while (choice != 0);   
    }
}

// XÓA THÔNG TIN MỘT ĐỘC GIẢ 
void deleteReader() {
    char id[MAX_ID];

    getchar();
    printf("Nhap ID cua doc gia: ");

    fgets(id, sizeof(id), stdin);

    int index = findReaderById(id);

    if (index != -1) {
        // xoá không duy trì thứ tự trong mảng
        strcpy( IDS[index], IDS[NUMBER_OF_READERS  - 1]);
        strcpy( NAMES[index], NAMES[NUMBER_OF_READERS  - 1]);
        strcpy( CIC_NUMBERS[index], CIC_NUMBERS[NUMBER_OF_READERS  - 1]);
        strcpy( BIRTHDAYS[index], BIRTHDAYS[NUMBER_OF_READERS  - 1]);
        GENDERS[index] = GENDERS[NUMBER_OF_READERS  - 1];
        strcpy( EMAILS[index], EMAILS[NUMBER_OF_READERS  - 1]);
        strcpy( ADDRESSES[index], ADDRESSES[NUMBER_OF_READERS  - 1]);
        strcpy( ISSUE_DATES[index], ISSUE_DATES[NUMBER_OF_READERS  - 1]);
        strcpy( EXPIRY_DATES[index], EXPIRY_DATES[NUMBER_OF_READERS  - 1]);
    
        NUMBER_OF_READERS--;
    } else {
        printf("Khong tim thay doc gia co ID: %s\n", id);
    }
}

// TÌM KIẾM ĐỘC GIẢ THEO CMND 
void searchReaderByCMND() {
    char cmnd[13];

    getchar();
    printf("Nhap CMND cua doc gia: ");
    fgets(cmnd, sizeof(cmnd), stdin);
    cmnd[strcspn(cmnd, "\n")] = '\0';

    printf("%s\n", cmnd);
    
    int index = findReaderByCIC(cmnd);

    printf("KET QUA\n");

    if (index != -1) {
        viewReaderHeader();
        viewReader(index);

    printf("\n");
    } else {
        printf("Khong tim thay doc gia co CMND/CCCD: %s\n", cmnd);
    }
}

// TÌM KIẾM SÁCH THEO HỌ TÊN
void searchReaderByName() {
    char name[20];
    int saveIndex[20];
    int index = 0;
    int valid;

    getchar();
    printf("Nhap ten can tim: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    convertToLower(name, name);

    for (int i = 0; i < NUMBER_OF_READERS; i++) {
        char temp[20];
        convertToLower(NAMES[i], temp);

        valid = findSubString(name, temp);

        if (valid != -1) {
            saveIndex[index++] = i;

            // hiển thị ra màn hình
            printf("%d. %s\n", index, NAMES[i] );
        }
    }

    if(index == 0) {
        printf("Khong co ten doc gia");
    } else {
        int choice;
        printf("Chon doc gia: ");
        scanf("%d", &choice);
        viewReaderHeader();
        viewReader(saveIndex[choice - 1]);
    }
}
