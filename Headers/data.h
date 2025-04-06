#ifndef DATA_H
#define DATA_H

#define MAX_READERS 999   // Change this based on the number of readers
#define MAX_ID 10       // Define max length for ID
#define MAX_NAME 50     // Define max length for Name
#define MAX_CIC 20      // Define max length for CIC Number
#define MAX_DATE 11     // "DD/MM/YYYY" (10 chars + '\0')
#define MAX_EMAIL 50    // Max length for email
#define MAX_ADDRESS 100 // Max length for address

// khởi tạo các mảng lưu trữ cho thông tin đọc giả
extern char IDS[MAX_READERS][MAX_ID];
extern char NAMES[MAX_READERS][MAX_NAME];
extern char CIC_NUMBERS[MAX_READERS][MAX_CIC];
extern char BIRTHDAYS[MAX_READERS][MAX_DATE];
extern int GENDERS[MAX_READERS];
extern char EMAILS[MAX_READERS][MAX_EMAIL];
extern char ADDRESSES[MAX_READERS][MAX_ADDRESS];
extern char ISSUE_DATES[MAX_READERS][MAX_DATE];
extern char EXPIRY_DATES[MAX_READERS][MAX_DATE];
     
extern int NUMBER_OF_READERS;


#define MAX_BOOKS 999       // Maximum number of books
#define MAX_ISBN 20      // Maximum length for book ID (e.g., ISBN)
#define MAX_TITLE 100       // Maximum length for book title
#define MAX_AUTHOR 50       // Maximum length for author's name
#define MAX_PUBLISHER 50    // Maximum length for publisher name
#define MAX_YEAR 5          // "YYYY" format (4 chars + '\0')
#define MAX_CATEGORY 50     // Maximum length for book category
#define MAX_PRICE 15        // Maximum length for price (as a string)
#define MAX_STOCK 5         // Maximum length for stock quantity (as a string)
#define MAX_GENRE 20        // Maximum length for book genres (as a string)

// khởi tạo các mảng lưu trữ thông tin cho sách của thư viện
extern char ISBNs[MAX_BOOKS][MAX_ISBN];
extern char TITLES[MAX_BOOKS][MAX_TITLE];
extern char AUTHORS[MAX_BOOKS][MAX_AUTHOR];
extern char PUBLISHERS[MAX_BOOKS][MAX_PUBLISHER];
extern char PUBLISH_YEARS[MAX_BOOKS][MAX_YEAR];
extern int CATEGORIES[MAX_BOOKS];
extern float PRICES[MAX_BOOKS];
extern int STOCKS[MAX_BOOKS];

extern int NUMBER_OF_BOOKS;

extern char GENRES[MAX_GENRE][MAX_CATEGORY];

extern int NUMBER_OF_GENRES;

/* YÊU CẦU
Mỗi phiếu mượn/trả sách chứa thông tin về mã độc giả, ngày mượn, ngày trả dự
kiến, ngày trả thực tế và danh sách ISBN của các sách được mượn. Mỗi sách được
mượn tối đa trong 7 ngày, nếu quá hạn sẽ bị phạt tiền 5.000 đồng/ngày. Nếu sách
bị mất thì độc giả đó sẽ bị phạt số tiền tương ứng 200% giá sách.
*/

/* THẺ MƯỢN SÁCH
    1. Mã đọc giả
    2. Ngày mượn
    3. Ngày trả dự kiến (mỗi sách được mượn tối đa 7 ngày)
    4. Danh sách ISBN cảu các sách được mượn
*/

#define MAX_BORROW_TICKET 999

extern char BORROW_IDS[MAX_BORROW_TICKET][MAX_ID];
extern char BORROW_DATE[MAX_BORROW_TICKET][MAX_DATE];
extern char BORROW_RETURN_DATE[MAX_BORROW_TICKET][MAX_DATE];
extern int BORROW_START[MAX_BORROW_TICKET]; // Lưu vị trí bắt đầu của sách mượn ở id[start]
extern int BORROW_END[MAX_BORROW_TICKET]; // Lưu vị trí kết thúc của sách mượn ở id[end]
extern char BORROW_ISBN_BOOKS[MAX_BORROW_TICKET][MAX_ISBN];

extern int NUMBER_OF_BORROW_TICKETS;
extern int NUMBER_OF_ISBN_BOOK;

/* THẺ TRẢ SÁCH
    1. Mã đọc giả
    2. Ngày mượn
    3. Ngày trả dự kiến (mỗi sách được mượn tối đa 7 ngày)
    4. Ngày trả thực tế (lấy ngày hôm trả)
    5. Quá hạn bị phạt tiền 5.000 đồng / ngày
    6. Sách bị mất, phạt 200% giá sách
    4. Danh sách ISBN của các sách đang mượn
*/

extern char RETURN_TICKETS[];
extern int NUMBER_OF_RETURN_TICKETS;

#endif