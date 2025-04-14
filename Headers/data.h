#ifndef DATA_H                          // Ngăn chặn việc bao gồm file header nhiều lần (include guard)
#define DATA_H                          // Định nghĩa macro để đánh dấu file header đã được bao gồm

// ĐỊNH NGHĨA CÁC HẰNG SỐ
#define MAX_READERS 9999                // Số lượng độc giả tối đa trong hệ thống
#define MAX_ID 10                       // Độ dài tối đa của ID độc giả (bao gồm ký tự null '\0')
#define MAX_NAME 50                     // Độ dài tối đa của tên độc giả (bao gồm ký tự null '\0')
#define MAX_CIC 20                      // Độ dài tối đa của CMND/CCCD (bao gồm ký tự null '\0')
#define MAX_DATE 11                     // Độ dài tối đa của chuỗi ngày "DD/MM/YYYY" (10 ký tự + '\0')
#define MAX_GENDER 2                    // Số lượng giới tính tối đa (nam, nữ)
#define MAX_EMAIL 50                    // Độ dài tối đa của email độc giả (bao gồm ký tự null '\0')
#define MAX_DISTRICTS 713               // Số lượng huyện/quận tối đa trong cơ sở dữ liệu
#define MAX_PROVINCE 63                 // Số lượng tỉnh/thành phố tối đa trong cơ sở dữ liệu

#define MAX_BOOKS 9999                  // Số lượng sách tối đa trong hệ thống
#define MAX_ISBN 20                     // Độ dài tối đa của mã ISBN sách (bao gồm ký tự null '\0')
#define MAX_TITLE 100                   // Độ dài tối đa của tiêu đề sách (bao gồm ký tự null '\0')
#define MAX_AUTHOR 50                   // Độ dài tối đa của tên tác giả (bao gồm ký tự null '\0')
#define MAX_PUBLISHERS 70               // Số lượng nhà xuất bản tối đa trong cơ sở dữ liệu
#define MAX_YEAR 5                      // Độ dài tối đa của năm xuất bản "YYYY" (4 ký tự + '\0')
#define MAX_GENRE 30                    // Độ dài tối đa của tên thể loại sách (bao gồm ký tự null '\0')

#define MAX_BORROW_TICKET 999           // Số lượng phiếu mượn tối đa trong hệ thống

// KHAI BÁO CÁC MẢNG CƠ SỞ DỮ LIỆU (extern để định nghĩa trong file .c)
extern char* PROVINCES_DB[MAX_PROVINCE];          // Mảng lưu tên các tỉnh/thành phố
extern char* DISTRICTS_DB[MAX_DISTRICTS];         // Mảng lưu tên các huyện/quận
extern int PROVINCE_START_INDEX[MAX_PROVINCE];    // Mảng lưu chỉ số bắt đầu của huyện đầu tiên mỗi tỉnh trong DISTRICTS_DB
extern char* GENDER_DB[MAX_GENDER];               // Mảng lưu danh sách giới tính (nam, nữ)
extern char* GENRES_DB[MAX_GENRE];                // Mảng lưu danh sách thể loại sách
extern int NUMBER_OF_GENRES;                      // Biến lưu số lượng thể loại sách hiện có
extern char* PUBLISHERS_DB[MAX_PUBLISHERS];       // Mảng lưu danh sách nhà xuất bản
extern int NUMBER_OF_PUBLISHERS;                  // Biến lưu số lượng nhà xuất bản hiện có
extern int NUMBER_OF_GENRES;                      // Biến lưu số lượng thể loại sách hiện có

// KHAI BÁO CÁC MẢNG LƯU THÔNG TIN ĐỘC GIẢ
extern char IDS[MAX_READERS][MAX_ID];             // Mảng 2D lưu ID của độc giả
extern char NAMES[MAX_READERS][MAX_NAME];         // Mảng 2D lưu tên của độc giả
extern char CIC_NUMBERS[MAX_READERS][MAX_CIC];    // Mảng 2D lưu số CMND/CCCD của độc giả
extern char BIRTHDAYS[MAX_READERS][MAX_DATE];     // Mảng 2D lưu ngày sinh của độc giả (định dạng DD/MM/YYYY)
extern int GENDERS[MAX_READERS];                  // Mảng lưu chỉ số giới tính của độc giả (liên kết với GENDER_DB)
extern char EMAILS[MAX_READERS][MAX_EMAIL];       // Mảng 2D lưu email của độc giả
extern int DISTRICTS[MAX_READERS];                // Mảng lưu chỉ số huyện/quận của độc giả (liên kết với DISTRICTS_DB)
extern int PROVINCES[MAX_READERS];                // Mảng lưu chỉ số tỉnh/thành phố của độc giả (liên kết với PROVINCES_DB)
extern char ISSUE_DATES[MAX_READERS][MAX_DATE];   // Mảng 2D lưu ngày lập thẻ độc giả (định dạng DD/MM/YYYY)
extern int NUMBER_OF_READERS;                     // Biến lưu số lượng độc giả hiện có trong hệ thống

// KHAI BÁO CÁC MẢNG LƯU THÔNG TIN SÁCH
extern char ISBNs[MAX_BOOKS][MAX_ISBN];           // Mảng 2D lưu mã ISBN của sách
extern char TITLES[MAX_BOOKS][MAX_TITLE];         // Mảng 2D lưu tiêu đề sách
extern char AUTHORS[MAX_BOOKS][MAX_AUTHOR];       // Mảng 2D lưu tên tác giả của sách
extern int PUBLISHERS[MAX_BOOKS];                 // Mảng lưu chỉ số nhà xuất bản của sách (liên kết với PUBLISHERS_DB)
extern char PUBLISH_YEARS[MAX_BOOKS][MAX_YEAR];   // Mảng 2D lưu năm xuất bản của sách (định dạng YYYY)
extern int CATEGORIES[MAX_BOOKS];                 // Mảng lưu chỉ số thể loại của sách (liên kết với GENRES_DB)
extern float PRICES[MAX_BOOKS];                   // Mảng lưu giá tiền của sách (đơn vị tiền tệ bất kỳ)
extern int STOCKS[MAX_BOOKS];                     // Mảng lưu số lượng sách trong kho
extern int NUMBER_OF_BOOKS;                       // Biến lưu số lượng sách hiện có (dựa trên ISBN)

// KHAI BÁO CÁC MẢNG LƯU THÔNG TIN PHIẾU MƯỢN
extern int BORROW_IDS[MAX_BORROW_TICKET];         // Mảng 2D lưu ID độc giả trong phiếu mượn
extern char BORROW_DATE[MAX_BORROW_TICKET][MAX_DATE];      // Mảng 2D lưu ngày mượn sách (định dạng DD/MM/YYYY)
extern int BORROW_START[MAX_BORROW_TICKET];                // Mảng lưu chỉ số bắt đầu của sách mượn trong BORROW_ISBN_BOOKS
extern int BORROW_BOOKS[MAX_BORROW_TICKET];                 // Mảng sách được mượn trong phiếu
extern int NUMBER_OF_BORROW_TICKETS;                       // Biến lưu số lượng phiếu mượn hiện có

// KHAI BÁO THÔNG TIN SÁCH ĐANG MƯỢN VÀ TRẢ SÁCH
extern int NUMBER_OF_BORROW_BOOK;                   // Biến lưu số lượng sách (ISBN) đang được mượn trong thư viện
extern int BLACK_LIST[];                     // Mảng lưu thông tin phiếu trả sách (chưa xác định kích thước)
extern int NUMBER_OF_BLACK_LIST;              // Biến lưu số lượng phiếu trả sách hiện có

#endif                                    // Kết thúc include guard