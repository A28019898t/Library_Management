#include "..\Headers\data.h"

// khởi tạo các mảng lưu trữ cho thông tin đọc giả
char IDS[MAX_READERS][MAX_ID] = {"DG001", "DG002"};
char NAMES[MAX_READERS][MAX_NAME] = {"Dao Duy Anh", "Dao Van Minh"};
char CIC_NUMBERS[MAX_READERS][MAX_CIC] = {"0123456789", "0987654321"};
char BIRTHDAYS[MAX_READERS][MAX_DATE] = {"01/01/1990", "15/05/1995"};
int GENDERS[MAX_READERS] = {1, 0};
char EMAILS[MAX_READERS][MAX_EMAIL] = {"a@gmail.com", "b@gmail.com"};
char ADDRESSES[MAX_READERS][MAX_ADDRESS] = {"Ha Noi", "TP.HCM"};
char ISSUE_DATES[MAX_READERS][MAX_DATE] = {"01/01/2022", "10/02/2022"};
char EXPIRY_DATES[MAX_READERS][MAX_DATE] = {"01/01/2025", "10/02/2025"};

int NUMBER_OF_READERS = 2;

// khởi tạo các mảng lưu trữ thông tin cho sách của thư viện
char ISBNs[MAX_BOOKS][MAX_ISBN] = {
    "978-604-1-10423-7", "978-604-2-12345-6", "978-604-3-56789-0", 
    "978-604-4-98765-4", "978-604-5-24680-3"
};

char TITLES[MAX_BOOKS][MAX_TITLE] = {
    "Lap trinh C++ tu co ban den nang cao",
    "Cau truc du lieu & Giai thuat",
    "Hoc lap trinh Python",
    "Thiet ke va Phat trien Web",
    "Tri tue nhan tao va Ung dung"
};

char AUTHORS[MAX_BOOKS][MAX_AUTHOR] = {
    "Nguyen Van A", "Tran Thi B", "Le Van C", "Pham Thi D", "Hoang Van E"
};

char PUBLISHERS[MAX_BOOKS][MAX_PUBLISHER] = {
    "NXB Giao Duc", "NXB Khoa Hoc", "NXB Tre", "NXB Cong Nghe", "NXB Ky Thuat"
};

char PUBLISH_YEARS[MAX_BOOKS][MAX_YEAR] = {
    "2020", "2019", "2021", "2022", "2023"
};

int CATEGORIES[MAX_BOOKS] = {
    0, 2, 0, 3, 4
};

// Nhớ nhân 100 để ra giá tiền hàng nghìn VNĐ
float PRICES[MAX_BOOKS] = {
   120, 150, 130, 180, 200
};

int STOCKS[MAX_BOOKS] = {
    10, 7, 12, 5, 8
};

int NUMBER_OF_BOOKS = 5;

char GENRES[MAX_GENRE][MAX_CATEGORY] = {
    "Triet hoc & Tam ly hoc",
    "Ton giao",
    "Khoa hoc xa hoi",
    "Ngon ngu hoc",
    "KHTN & Toan hoc",
    "Cong nghe & Ky thuat",
    "Nghe thuat & Giai tri",
    "Van hoc",
    "Lich su & Dia ly",
    "QTKD & Kinh te"
};

int NUMBER_OF_GENRES = 10;

/* THẺ MƯỢN SÁCH
    1. Mã đọc giả
    2. Ngày mượn
    3. Ngày trả dự kiến (mỗi sách được mượn tối đa 7 ngày)
    4. Danh sách ISBN cảu các sách được mượn
*/

char BORROW_IDS[MAX_BORROW_TICKET][MAX_ID] = {"DG001", "DG002", "DG001"};
char BORROW_DATE[MAX_BORROW_TICKET][MAX_DATE] = {"25/03/2025", "26/03/2025", "04/04/2025"};
char BORROW_RETURN_DATE[MAX_BORROW_TICKET][MAX_DATE] = {"01/04/2025",  "02/04/2025", "11/04/2025"};
int BORROW_START[MAX_BORROW_TICKET] = {0, 2, 5}; // Lưu vị trí bắt đầu của sách mượn ở id[start]
int BORROW_END[MAX_BORROW_TICKET] = {1, 4, 6}; // Lưu vị trí kết thúc của sách mượn ở id[end]
char BORROW_ISBN_BOOKS[MAX_BORROW_TICKET][MAX_ISBN] = {"978-604-1-10423-7", "978-604-2-12345-6", 
                                                        "978-604-3-56789-0", "978-604-4-98765-4", "978-604-5-24680-3", 
                                                        "978-604-3-56789-0", "978-604-5-24680-3"
                                                        };

int NUMBER_OF_BORROW_TICKETS = 3;
int NUMBER_OF_ISBN_BOOK = 7;