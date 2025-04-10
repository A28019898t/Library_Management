#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "..\Headers\reader.h"
#include "..\Headers\data.h"
#include "..\Headers\utils.h"

// 1. QUẢN LÝ ĐỌC GIẢ

// 1.1. XEM DANH SÁCH ĐỘC GIẢ TRONG THƯ VIỆN

// Hiển thị hàng tiêu đề
void viewReaderHeader() {
    printf("%-8s", "id");
    printf("%-28s", "Ho va ten");
    printf("%-14s", "CMND/CCCD");
    printf("%-12s", "Ngay sinh");
    printf("%-12s", "Gioi tinh");
    printf("%-28s", "Email");
    printf("%-35s", "Dia chi");
    printf("%-15s", "Ngay lap the");
    printf("%-15s", "Ngay het han the");
    printf("\n");
}

// Hiển thị 1 đọc giả dựa trên index truyền vào
void viewReader(int index) {
    printf("%-8s", IDS[index]); // id
    printf("%-28s", NAMES[index]); // Ho va ten
    printf("%-14s", CIC_NUMBERS[index]); // CMND/CCCD
    printf("%-12s", BIRTHDAYS[index]); // Ngay sinh
    printf("%-12s", (GENDERS[index] == 1) ? "Nam" : "Nu"); // Gioi tinh
    printf("%-28s", EMAILS[index]); // Email
    int distance1 = strlen(DISTRICTS[ADDRESSES_DISTRICTS[index]]);
    int distance2 = 35 - distance1 - 2;

    printf("%-*s, %-*s", distance1, DISTRICTS[ADDRESSES_DISTRICTS[index]], distance2, PROVINCES[ADDRESSES_PROVINCES[index]]); // Dia chi
    printf("%-15s", ISSUE_DATES[index]); // Ngay lap the
    char expiryDate[11];
    getDateFromKMonths(expiryDate, ISSUE_DATES[index], 48);
    printf("%-15s", expiryDate); // Ngay het han the
    printf("\n");
}

// Hiển thị toàn bộ đọc giả
void viewAllReaders() {
    viewReaderHeader();

    for(int i = 0; i < NUMBER_OF_READERS; i++) {
        viewReader(i);
    }
}

// 1.2 THÊM ĐỘC GIẢ

// Hàm sinh mã độc giả
void generateCodeReader(char* code, const char* lastReaderID) {
    // Kiểm tra lastReaderID hợp lệ
    if (lastReaderID == NULL || strlen(lastReaderID) < 3 || strncmp(lastReaderID, "DG", 2) != 0) {
        strcpy(code, "DG0001"); // Mã mặc định nếu không có độc giả trước đó
        return;
    }

    // Lấy phần số từ lastReaderID (bỏ "DG")
    int num;
    sscanf(lastReaderID + 2, "%d", &num);
    num++; // Tăng số lên 1

    // Giới hạn số tối đa (ví dụ: 9999 cho mã 6 ký tự)
    if (num > 9999) {
        strcpy(code, "DG9999"); // Giới hạn tối đa
        printf("Canh bao: Da dat gioi han ma doc gia!\n");
        return;
    }

    // Tạo mã mới
    char temp[5]; // Đủ cho 4 chữ số (0001 -> 9999)
    intToPaddedString(temp, num, 4); // Chuyển thành chuỗi 4 chữ số, padding 0
    strcpy(code, "DG");              // Prefix
    strcat(code, temp);              // Nối số vào
}

// Hàm nhập tên đọc giả(tên đọc giả, kích thước)
void inputName(char* name, int size) {
    getchar();

    printf("Ho va ten: ");
    fgets(name, size, stdin);
    name[strcspn(name, "\n")] = '\0';
}

// Hàm nhập CMND/CCCD(CMND, kích thước)
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
                printf("CMND/CCCD phai la so\n");
                continue;
            }

            if (findReaderByCIC(cic) != -1) {
                valid = 0;
                printf("CMND/CCCD da ton tai trong thu vien\n");
                continue;
            }

            switch (strlen(cic)) {
                case 9: 
                case 12:
                    break;
                default:
                    valid = 0;
                    printf("CMND co 9 chu so, CCCD co 12 chu so\n");
            }

            // if (!valid) std::wcout << RESET << std::endl;

        } while(!valid);
}

// Hàm nhập giới tính
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
                printf("Nhap sai lua chon. Moi nhap lai\n");
        }
    } while (!valid);

}

// Hàm kiểm tra email hợp lệ
int isValidEmail(char* email) {
    int len = strlen(email);
    int atCount = 0;      // Đếm số ký tự '@'
    int dotCount = 0;     // Đếm số ký tự '.' sau '@'
    int atIndex = -1;     // Vị trí của '@'
    int i;

    // Kiểm tra độ dài tối thiểu
    if (len < 6) { // Ví dụ: "a@b.c" là email ngắn nhất hợp lệ
        return 0;
    }

    // Kiểm tra ký tự đầu và cuối (không được là ký tự đặc biệt)
    if (!isalnum(email[0]) || !isalnum(email[len - 1])) {
        return 0;
    }

    // Duyệt qua từng ký tự trong email
    for (i = 0; i < len; i++) {
        char c = email[i];

        // Đếm '@' và ghi lại vị trí
        if (c == '@') {
            atCount++;
            atIndex = i;
        }
        // Đếm '.' sau '@'
        else if (c == '.' && atIndex != -1 && i > atIndex) {
            dotCount++;
        }
        // Kiểm tra ký tự hợp lệ: chữ cái, số, '@', '.', '-', '_'
        if (!(isalnum(c) || c == '@' || c == '.' || c == '-' || c == '_')) {
            return 0;
        }
    }

    // Kiểm tra điều kiện hợp lệ
    if (atCount != 1) { // Phải có đúng 1 '@'
        return 0;
    }
    if (atIndex < 1 || atIndex >= len - 3) { // '@' không được ở đầu hoặc gần cuối
        return 0;
    }
    if (dotCount < 1) { // Phải có ít nhất 1 '.' sau '@'
        return 0;
    }
    if (strstr(email, "..") || strstr(email, "@.") || strstr(email, ".@")) { // Không cho phép ".." hoặc "@." hoặc ".@"
        return 0;
    }

    return 1; // Email hợp lệ
}

// Hàm nhập email(email, kích thước)
void inputEmail(char* email, int size) {
    int valid;
    
    do {
        
        printf("Email: ");
        fgets(email, size, stdin);
        email[strcspn(email, "\n")] = '\0';
        
        valid = isValidEmail(email);

        if (!valid) {
            printf("Email khong hop le. Moi nhap lai\n");
        } 

    } while(!valid);
}

// Hàm nhập địa chỉ tỉnh(địa chỉ, kích thước)
int inputProvince() {

    int address;
    do {
        address = findItemByStr("Nhap tinh: ", PROVINCES, MAX_PROVINCE);

        if (address == -1) {
            printf("Khong co dia chi hop le. Moi nhap lai\n");
        }

    } while(address == -1);

    return address;
}

// Hàm nhập địa chỉ huyện(địa chỉ, kích thước)
int inputDistrict(int province) {
    int start = PROVINCE_START_INDEX[province];
    int end;

    if (province < MAX_PROVINCE - 1) {
        end = PROVINCE_START_INDEX[province + 1] - 1;
    } else {
        end = 712; // Dành cho tỉnh Yên Bái, tỉnh cuối cùng trong danh sách
    }

    for (int i = start; i <= end; i++) {
        printf("[%d]: %s\n", i % start + 1, DISTRICTS[i]);
    }

    int choice;
    printf("Chon: ");
    scanf("%d", &choice);
    return choice + start - 1;
}

// Thêm đọc giả
void addReader() {
    char readerID[MAX_ID];
    char name[MAX_NAME];
    char cic[MAX_CIC];
    int gender;
    char email[MAX_EMAIL];
    int province;
    int district;
    char birthDate[MAX_DATE];
    char issueDate[MAX_DATE];
    
    printf("THEM DOC GIA\n");

    generateCodeReader(readerID, IDS[NUMBER_OF_READERS - 1]);
    printf("%s\n", readerID); // for test
    
    inputName(name, MAX_NAME);
    printf("%s\n", name); // for test

    inputCIC(cic, MAX_CIC);
    printf("%s\n", cic); // for test
    
    gender = inputGender();
    printf("%d\n", gender); // for test

    inputEmail(email, MAX_EMAIL);
    printf("%s\n", email); // for test

    province = inputProvince();
    printf("%d\n", province); // for test

    district = inputDistrict(province);
    printf("%d\n", district); // for test

    printf("Ngay sinh: \n");
    inputDay(birthDate);
    printf("%s\n", birthDate); // for test

    getToday(issueDate);
    printf("issueDate: %s\n", issueDate); // for test

    if (NUMBER_OF_READERS < MAX_READERS) {

        strcpy(IDS[NUMBER_OF_READERS], readerID);
        strcpy(NAMES[NUMBER_OF_READERS], name);
        strcpy(CIC_NUMBERS[NUMBER_OF_READERS], cic);
        strcpy(BIRTHDAYS[NUMBER_OF_READERS], birthDate);
        GENDERS[NUMBER_OF_READERS] = gender;
        strcpy(EMAILS[NUMBER_OF_READERS], email);
        ADDRESSES_PROVINCES[NUMBER_OF_READERS] = province;
        ADDRESSES_DISTRICTS[NUMBER_OF_READERS] = district;
        strcpy(ISSUE_DATES[NUMBER_OF_READERS], issueDate);
        
        NUMBER_OF_READERS++;
        
        printf("Thanh cong\n");
    } else {
        printf("Khong du bo nho\n");
    }

}

// Tìm đọc giả bằng id (id): hàm trả về index của đọc giả
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

// Tìm đọc giả bằng CMND/CCCD(CMND/CCCD): hàm trả về index của đọc giả
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

// 1.3. CHỈNH SỬA THÔNG TIN MỘT ĐỘC GIẢ 
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
            system("cls");

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
                    ADDRESSES_PROVINCES[index] = inputProvince();
                    ADDRESSES_DISTRICTS[index] = inputDistrict(ADDRESSES_PROVINCES[index]);
                    break;
                default:
                    printf("Nhap sai lua chon. Moi ban nhap lai\n");
            }
        } while (choice != 0);   
    }
}

// 1.4. XÓA THÔNG TIN MỘT ĐỘC GIẢ 
void deleteReader() {
    char id[MAX_ID];

    getchar();
    printf("Nhap ID cua doc gia: ");

    fgets(id, MAX_ID, stdin);
    id[strcspn(id, "\n")] = '\0';

    int index = findReaderById(id);

    if (index != -1) {
        // xoá không duy trì thứ tự trong mảng
        // Xoá duy trì thứ tự trong mảng
        for (int i = index; i < NUMBER_OF_READERS - 1; i++) {
            strcpy( IDS[index], IDS[i  + 1]);
            strcpy( NAMES[index], NAMES[i  + 1]);
            strcpy( CIC_NUMBERS[index], CIC_NUMBERS[i  + 1]);
            strcpy( BIRTHDAYS[index], BIRTHDAYS[i  + 1]);
            GENDERS[index] = GENDERS[i  + 1];
            strcpy( EMAILS[index], EMAILS[i  + 1]);
            ADDRESSES_PROVINCES[index] = ADDRESSES_PROVINCES[i  + 1];
            ADDRESSES_DISTRICTS[index] = ADDRESSES_DISTRICTS[i  + 1];
            strcpy( ISSUE_DATES[index], ISSUE_DATES[i  + 1]);
        }
    
        NUMBER_OF_READERS--;

        printf("Xoa thanh cong doc gia %s\n", id);
    } else {
        printf("Khong tim thay doc gia co ID: %s\n", id);
    }
}

// 1.5. TÌM KIẾM ĐỘC GIẢ THEO CMND (CIC: Tiếng Anh của CMND/CCCD)
void searchReaderByCIC() {
    char cic[13];

    getchar();
    printf("Nhap CMND cua doc gia: ");
    fgets(cic, sizeof(cic), stdin);
    cic[strcspn(cic, "\n")] = '\0';

    printf("%s\n", cic);
    
    int index = findReaderByCIC(cic);

    printf("KET QUA\n");

    if (index != -1) {
        viewReaderHeader();
        viewReader(index);

    printf("\n");
    } else {
        printf("Khong tim thay doc gia co CMND/CCCD: %s\n", cic);
    }
}

// 1.6. TÌM KIẾM SÁCH THEO HỌ TÊN
void searchReaderByName() {
    char source[20];
    char des[20];
    int saveIndex[20];
    int index = 0;
    int valid;

    getchar();
    printf("Nhap ten doc gia: ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = '\0';

    convertToLower(source, des);

    for (int i = 0; i < MAX_PROVINCE; i++) {
        char temp[20];
        convertToLower(NAMES[i], temp);

        valid = findSubString(des, temp);

        if (valid != -1) {
            saveIndex[index++] = i;

            // hiển thị ra màn hình
            printf("%d. %s\n", index, NAMES[i] );
        }

    }

    if(index == 0) {
        printf("Khong co\n");
    } else {
        int choice;
        printf("Chon doc gia: ");
        scanf("%d", &choice);
        viewReaderHeader();
        viewReader(saveIndex[choice - 1]);
    }
}
