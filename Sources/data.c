#include "..\Headers\data.h"

// khởi tạo các mảng lưu trữ cho thông tin đọc giả
// Sử dụng mảng 2D cho mảng các ký tự (chuỗi)
char IDS[MAX_READERS][MAX_ID] = {"DG0001", "DG0002"};
char NAMES[MAX_READERS][MAX_NAME] = {"Duong Quyen Tran", "Nguyen Tran Nhat Anh Bao"};
char CIC_NUMBERS[MAX_READERS][MAX_CIC] = {"123456789", "123456789012"};
char BIRTHDAYS[MAX_READERS][MAX_DATE] = {"01/01/1990", "15/05/1995"};
int GENDERS[MAX_READERS] = {1, 0};
char EMAILS[MAX_READERS][MAX_EMAIL] = {"daoduyanhdh23a@gmail.com", "b@gmail.com"};
int ADDRESSES_DISTRICTS[MAX_READERS] = {3, 4}; 
int ADDRESSES_PROVINCES[MAX_READERS] = {1, 50}; 
char ISSUE_DATES[MAX_READERS][MAX_DATE] = {"01/01/2022", "10/02/2022"};

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

char* GENRES[MAX_GENRE] = {
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

char* PROVINCES[MAX_PROVINCE] = {
    "An Giang",         "Ba Ria - Vung Tau", "Bac Giang",
    "Bac Kan",          "Bac Lieu",          "Bac Ninh",
    "Ben Tre",          "Binh Dinh",         "Binh Duong",
    "Binh Phuoc",       "Binh Thuan",        "Ca Mau",
    "Can Tho",          "Cao Bang",          "Da Nang",
    "Dak Lak",          "Dak Nong",          "Dien Bien",
    "Dong Nai",         "Dong Thap",         "Gia Lai",
    "Ha Giang",         "Ha Nam",            "Ha Noi",
    "Ha Tinh",          "Hai Duong",         "Hai Phong",
    "Hau Giang",        "Hoa Binh",          "Hung Yen",
    "Khanh Hoa",        "Kien Giang",        "Kon Tum",
    "Lai Chau",         "Lam Dong",          "Lang Son",
    "Lao Cai",          "Long An",           "Nam Dinh",
    "Nghe An",          "Ninh Binh",         "Ninh Thuan",
    "Phu Tho",          "Phu Yen",           "Quang Binh",
    "Quang Nam",        "Quang Ngai",        "Quang Ninh",
    "Quang Tri",        "Soc Trang",         "Son La",
    "Tay Ninh",         "Thai Binh",         "Thai Nguyen",
    "Thanh Hoa",        "TP. Ho Chi Minh",
    "Thua Thien Hue",   "Tien Giang",        "Tra Vinh",
    "Tuyen Quang",      "Vinh Long",         "Vinh Phuc",
    "Yen Bai"
};

char* DISTRICTS[MAX_DISTRICTS] = {
    // An Giang (11)
    "Long Xuyen", "Chau Doc", "An Phu", "Tan Chau", "Phu Tan", "Chau Phu", "Tinh Bien", 
    "Tri Ton", "Cho Moi", "Chau Thanh", "Thoai Son",
    
    // Ba Ria - Vung Tau (8)
    "Vung Tau", "Ba Ria", "Chau Duc", "Xuyen Moc", "Long Dien", "Dat Do", "Phuoc Binh", "Con Dao",
    
    // Bac Giang (10)
    "Bac Giang", "Hiep Hoa", "Lang Giang", "Luc Nam", "Luc Ngan", "Son Dong", "Tan Yen", 
    "Viet Yen", "Yen Dung", "Yen The",
    
    // Bac Kan (8)
    "Bac Kan", "Pac Nam", "Ba Be", "Ngan Son", "Bach Thong", "Cho Don", "Cho Moi", "Na Ri",
    
    // Bac Lieu (7)
    "Bac Lieu", "Hong Dan", "Phuoc Long", "Vinh Loi", "Gia Rai", "Dong Hai", "Hoa Binh",
    
    // Bac Ninh (8)
    "Bac Ninh", "Yen Phong", "Que Vo", "Tien Du", "Tu Son", "Thuan Thanh", "Gia Binh", "Luong Tai",
    
    // Ben Tre (9)
    "Ben Tre", "Chau Thanh", "Cho Lach", "Mo Cay Nam", "Mo Cay Bac", "Giong Trom", "Binh Dai", 
    "Ba Tri", "Thanh Phu",
    
    // Binh Dinh (11)
    "Quy Nhon", "An Lao", "Hoai An", "Hoai Nhon", "Phu Cat", "Phu My", "Tay Son", "Tuy Phuoc", 
    "Van Canh", "Vinh Thanh", "An Nhon",
    
    // Binh Duong (9)
    "Thu Dau Mot", "Bau Bang", "Dau Tieng", "Ben Cat", "Phu Giao", "Tan Uyen", "Di An", 
    "Thuan An", "Bac Tan Uyen",
    
    // Binh Phuoc (11)
    "Dong Xoai", "Phuoc Long", "Binh Long", "Bu Gia Map", "Bu Dop", "Chon Thanh", "Dong Phu", 
    "Hon Quan", "Loc Ninh", "Bu Dang", "Phu Rieng",
    
    // Binh Thuan (10)
    "Phan Thiet", "La Gi", "Tuy Phong", "Bac Binh", "Ham Thuan Bac", "Ham Thuan Nam", "Tan Linh", 
    "Ham Tan", "Phu Quy", "Duc Linh",
    
    // Ca Mau (9)
    "Ca Mau", "U Minh", "Thoi Binh", "Tran Van Thoi", "Cai Nuoc", "Dam Doi", "Nam Can", 
    "Phu Tan", "Ngoc Hien",
    
    // Can Tho (9)
    "Ninh Kieu", "O Mon", "Binh Thuy", "Cai Rang", "Thot Not", "Vinh Thanh", "Co Do", 
    "Phong Dien", "Thoi Lai",
    
    // Cao Bang (10)
    "Cao Bang", "Bao Lac", "Bao Lam", "Ha Quang", "Hoa An", "Nguyen Binh", "Phuc Hoa", 
    "Quang Hoa", "Thach An", "Trung Khanh",
    
    // Da Nang (8)
    "Hai Chau", "Thanh Khe", "Son Tra", "Ngu Hanh Son", "Lien Chieu", "Cam Le", "Hoa Vang", 
    "Hoang Sa",
    
    // Dak Lak (15)
    "Buon Ma Thuot", "Buon Ho", "Cu M'gar", "Cu Kuin", "Dak Mil", "Ea H'leo", "Ea Kar", 
    "Ea Sup", "Krong Ana", "Krong Buk", "Krong Nang", "Krong Pak", "Lak", "M'Drak", "Buon Don",
    
    // Dak Nong (8)
    "Gia Nghia", "Cu Jut", "Dak Glong", "Dak Mil", "Dak R'Lap", "Dak Song", "Krong No", "Tuy Duc",
    
    // Dien Bien (10)
    "Dien Bien Phu", "Muong Lay", "Muong Nhe", "Muong Cha", "Tua Chua", "Tuan Giao", "Dien Bien", 
    "Dien Bien Dong", "Muong Ang", "Nam Po",
    
    // Dong Nai (11)
    "Bien Hoa", "Long Khanh", "Cam My", "Dinh Quan", "Long Thanh", "Nhon Trach", "Tan Phu", 
    "Thong Nhat", "Trang Bom", "Vinh Cuu", "Xuan Loc",
    
    // Dong Thap (12)
    "Cao Lanh", "Sa Dec", "Hong Ngu", "Tan Hong", "Chau Thanh", "Lai Vung", "Lap Vo", "Tam Nong", 
    "Thanh Binh", "Thap Muoi", "Cao Lanh District", "Hong Ngu District",
    
    // Gia Lai (17)
    "Pleiku", "An Khe", "Ayun Pa", "Chu Pah", "Chu Prong", "Chu Se", "Dak Doa", "Dak Po", 
    "Duc Co", "Ia Grai", "Ia Pa", "K'Bang", "Kong Chro", "Krong Pa", "Mang Yang", "Phu Thien", "Chu Pu",
    
    // Ha Giang (11)
    "Ha Giang", "Dong Van", "Meo Vac", "Yen Minh", "Quan Ba", "Vi Xuyen", "Bac Me", "Hoang Su Phi", 
    "Xin Man", "Bac Quang", "Quang Binh",
    
    // Ha Nam (6)
    "Phu Ly", "Duy Tien", "Kim Bang", "Ly Nhan", "Thanh Liem", "Binh Luc",
    
    // Ha Noi (30)
    "Ba Dinh", "Hoan Kiem", "Tay Ho", "Long Bien", "Cau Giay", "Dong Da", "Hai Ba Trung", "Hoang Mai", 
    "Thanh Xuan", "Soc Son", "Dong Anh", "Gia Lam", "Nam Tu Liem", "Thanh Tri", "Bac Tu Liem", "Me Linh", 
    "Ha Dong", "Son Tay", "Ba Vi", "Phuc Tho", "Dan Phuong", "Hoai Duc", "Quoc Oai", "Thach That", 
    "Chuong My", "Thanh Oai", "Thuong Tin", "Phu Xuyen", "Ung Hoa", "My Duc",
    
    // Ha Tinh (13)
    "Ha Tinh", "Hong Linh", "Huong Son", "Duc Tho", "Vu Quang", "Nghi Xuan", "Can Loc", "Huong Khe", 
    "Thach Ha", "Cam Xuyen", "Ky Anh", "Loc Ha", "Ky Anh Town",
    
    // Hai Duong (12)
    "Hai Duong", "Chi Linh", "Nam Sach", "Kinh Mon", "Kim Thanh", "Thanh Ha", "Cam Giang", "Binh Giang", 
    "Gia Loc", "Tu Ky", "Ninh Giang", "Thanh Mien",
    
    // Hai Phong (15)
    "Hong Bang", "Ngo Quyen", "Le Chan", "Hai An", "Kien An", "Do Son", "Duong Kinh", "Thuy Nguyen", 
    "An Duong", "An Lao", "Kien Thuy", "Tien Lang", "Vinh Bao", "Cat Hai", "Bach Long Vi",
    
    // Hau Giang (8)
    "Vi Thanh", "Nga Bay", "Chau Thanh A", "Chau Thanh", "Long My", "Phung Hiep", "Vi Thuy", "Long My Town",
    
    // Hoa Binh (10)
    "Hoa Binh", "Da Bac", "Ky Son", "Luong Son", "Kim Boi", "Cao Phong", "Tan Lac", "Mai Chau", 
    "Lac Son", "Yen Thuy",
    
    // Hung Yen (10)
    "Hung Yen", "Van Lam", "Van Giang", "Yen My", "My Hao", "An Thi", "Khoai Chau", "Kim Dong", 
    "Tien Lu", "Phu Cu",
    
    // Khanh Hoa (9)
    "Nha Trang", "Cam Ranh", "Cam Lam", "Van Ninh", "Ninh Hoa", "Khanh Vinh", "Dien Khanh", 
    "Khanh Son", "Truong Sa",
    
    // Kien Giang (15)
    "Rach Gia", "Ha Tien", "Kien Luong", "Hon Dat", "Tan Hiep", "Chau Thanh", "Giong Rieng", 
    "Go Quao", "An Bien", "An Minh", "Vinh Thuan", "Phu Quoc", "Kien Hai", "U Minh Thuong", "Giang Thanh",
    
    // Kon Tum (10)
    "Kon Tum", "Dak Glei", "Ngoc Hoi", "Dak To", "Kon Plong", "Kon Ray", "Dak Ha", "Sa Thay", 
    "Tu Mo Rong", "Ia H'Drai",
    
    // Lai Chau (8)
    "Lai Chau", "Muong Te", "Nam Nhun", "Phong Tho", "Sin Ho", "Tam Duong", "Than Uyen", "Tan Uyen",
    
    // Lam Dong (12)
    "Da Lat", "Bao Loc", "Dam Rong", "Lac Duong", "Lam Ha", "Don Duong", "Duc Trong", "Di Linh", 
    "Bao Lam", "Da Huoai", "Da Teh", "Cat Tien",
    
    // Lang Son (11)
    "Lang Son", "Trang Dinh", "Binh Gia", "Van Lang", "Cao Loc", "Van Quan", "Bac Son", "Huu Lung", 
    "Chi Lang", "Loc Binh", "Dinh Lap",
    
    // Lao Cai (9)
    "Lao Cai", "Bat Xat", "Muong Khuong", "Si Ma Cai", "Bac Ha", "Bao Thang", "Bao Yen", "Sa Pa", 
    "Van Ban",
    
    // Long An (15)
    "Tan An", "Kien Tuong", "Moc Hoa", "Vinh Hung", "Ben Luc", "Thu Thua", "Tan Thanh", "Tan Tru", 
    "Can Duoc", "Can Giuoc", "Chau Thanh", "Duc Hue", "Duc Hoa", "Thanh Hoa", "Tan Hung",
    
    // Nam Dinh (10)
    "Nam Dinh", "My Loc", "Vu Ban", "Giao Thuy", "Yen Dinh", "Nghia Hung", "Nam Truc", "Truc Ninh", 
    "Xuan Truong", "Hai Hau",
    
    // Nghe An (21)
    "Vinh", "Cua Lo", "Thai Hoa", "Hoang Mai", "Que Phong", "Quy Chau", "Quy Hop", "Nghia Dan", 
    "Ky Son", "Tuong Duong", "Con Cuong", "Tan Ky", "Anh Son", "Dien Chau", "Yen Thanh", "Do Luong", 
    "Thanh Chuong", "Nghi Loc", "Nam Dan", "Hung Nguyen", "Quynh Luu",
    
    // Ninh Binh (8)
    "Ninh Binh", "Tam Diep", "Nho Quan", "Gia Vien", "Hoa Lu", "Yen Khanh", "Kim Son", "Yen Mo",
    
    // Ninh Thuan (7)
    "Phan Rang - Thap Cham", "Bac Ai", "Ninh Son", "Ninh Hai", "Ninh Phuoc", "Thuan Bac", "Thuan Nam",
    
    // Phu Tho (13)
    "Viet Tri", "Phu Tho", "Doan Hung", "Ha Hoa", "Lam Thao", "Song Lo", "Tam Nong", "Tan Son", 
    "Thanh Ba", "Thanh Son", "Thanh Thuy", "Yen Lap", "Cam Khe",
    
    // Phu Yen (9)
    "Tuy Hoa", "Song Cau", "Dong Hoa", "Dong Xuan", "Phu Hoa", "Son Hoa", "Song Hinh", "Tay Hoa", 
    "Tuy An",
    
    // Quang Binh (8)
    "Dong Hoi", "Minh Hoa", "Tuyen Hoa", "Quang Trach", "Bo Trach", "Quang Ninh", "Le Thuy", "Ba Don",
    
    // Quang Nam (18)
    "Tam Ky", "Hoi An", "Dai Loc", "Dien Ban", "Duy Xuyen", "Que Son", "Nam Giang", "Phuoc Son", 
    "Hiep Duc", "Thang Binh", "Tien Phuoc", "Bac Tra My", "Nam Tra My", "Nong Son", "Phu Ninh", 
    "Tay Giang", "Dong Giang", "Nui Thanh",
    
    // Quang Ngai (14)
    "Quang Ngai", "Binh Son", "Tra Bong", "Son Tinh", "Tu Nghia", "Son Ha", "Son Tay", "Minh Long", 
    "Nghia Hanh", "Mo Duc", "Duc Pho", "Ba To", "Ly Son", "Tay Tra",
    
    // Quang Ninh (14)
    "Ha Long", "Mong Cai", "Cam Pha", "Uong Bi", "Binh Lieu", "Tien Yen", "Dam Ha", "Hai Ha", 
    "Ba Che", "Van Don", "Dong Trieu", "Quang Yen", "Co To", "Hoanh Bo",
    
    // Quang Tri (10)
    "Dong Ha", "Quang Tri", "Vinh Linh", "Huong Hoa", "Gio Linh", "Da Krong", "Cam Lo", "Tri Zhao", 
    "Hai Lang", "Con Co",
    
    // Soc Trang (11)
    "Soc Trang", "Chau Thanh", "Ke Sach", "My Tu", "Cu Lao Dung", "Long Phu", "My Xuyen", "Nga Nam", 
    "Thanh Tri", "Vinh Chau", "Tran De",
    
    // Son La (12)
    "Son La", "Quynh Nhai", "Thuan Chau", "Muong La", "Bac Yen", "Phu Yen", "Moc Chau", "Yen Chau", 
    "Mai Son", "Song Ma", "Sop Cop", "Van Ho",
    
    // Tay Ninh (9)
    "Tay Ninh", "Tan Bien", "Tan Chau", "Duong Minh Chau", "Chau Thanh", "Hoa Thanh", "Go Dau", 
    "Ben Cau", "Trang Bang",
    
    // Thai Binh (8)
    "Thai Binh", "Quynh Phu", "Hung Ha", "Dong Hung", "Thai Thuy", "Tien Hai", "Kien Xuong", "Vu Thu",
    
    // Thai Nguyen (9)
    "Thai Nguyen", "Song Cong", "Dinh Hoa", "Phu Luong", "Dong Hy", "Vo Nhai", "Dai Tu", "Pho Yen", 
    "Phu Binh",
    
    // Thanh Hoa (27)
    "Thanh Hoa", "Bim Son", "Sam Son", "Muong Lat", "Quan Hoa", "Quan Son", "Lang Chanh", "Ngoc Lac", 
    "Cam Thuy", "Thach Thanh", "Ha Trung", "Vinh Loc", "Yen Dinh", "Tho Xuan", "Thuong Xuan", 
    "Nong Cong", "Dong Son", "Quang Xuong", "Nhu Thanh", "Nhu Xuan", "Trieu Son", "Thieu Hoa", 
    "Hoang Hoa", "Hau Loc", "Nga Son", "Tinh Gia", "Ba Thuoc",
    
    // Thanh pho Ho Chi Minh (24)
    "Quan 1", "Quan 2", "Quan 3", "Quan 4", "Quan 5", "Quan 6", "Quan 7", "Quan 8", "Quan 9", 
    "Quan 10", "Quan 11", "Quan 12", "Thu Duc", "Go Vap", "Binh Thanh", "Tan Binh", "Tan Phu", 
    "Phu Nhuan", "Binh Tan", "Cu Chi", "Hoc Mon", "Binh Chanh", "Nha Be", "Can Gio",
    
    // Thua Thien Hue (9)
    "Hue", "Phong Dien", "Quang Dien", "Phu Vang", "Phu Loc", "Nam Dong", "A Luoi", "Huong Tra", 
    "Huong Thuy",
    
    // Tien Giang (11)
    "My Tho", "Go Cong", "Cai Lay", "Cai Be", "Chau Thanh", "Cho Gao", "Go Cong Tay", "Go Cong Dong", 
    "Tan Phu Dong", "Tan Phu", "Cai Lay Town",
    
    // Tra Vinh (9)
    "Tra Vinh", "Cang Long", "Cau Ke", "Tieu Can", "Chau Thanh", "Cau Ngang", "Tra Cu", "Duyen Hai", 
    "Duyen Hai Town",
    
    // Tuyen Quang (7)
    "Tuyen Quang", "Lam Binh", "Na Hang", "Chiem Hoa", "Ham Yen", "Yen Son", "Son Duong",
    
    // Vinh Long (8)
    "Vinh Long", "Long Ho", "Mang Thit", "Vung Liem", "Tam Binh", "Binh Minh", "Tra On", "Binh Tan",
    
    // Vinh Phuc (9)
    "Vinh Yen", "Phuc Yen", "Lap Thach", "Tam Dao", "Tam Duong", "Vinh Tuong", "Yen Lac", "Binh Xuyen", 
    "Song Lo",
    
    // Yen Bai (9)
    "Yen Bai", "Nghia Lo", "Luc Yen", "Van Yen", "Mu Cang Chai", "Tran Yen", "Tram Tau", "Van Chan", 
    "Yen Binh"
};

// Mảng chứa chỉ số bắt đầu của huyện đầu tiên của mỗi tỉnh
int PROVINCE_START_INDEX[MAX_PROVINCE] = {
    0,    // An Giang: Long Xuyen
    11,   // Ba Ria - Vung Tau: Vung Tau
    19,   // Bac Giang: Bac Giang
    29,   // Bac Kan: Bac Kan
    37,   // Bac Lieu: Bac Lieu
    44,   // Bac Ninh: Bac Ninh
    52,   // Ben Tre: Ben Tre
    61,   // Binh Dinh: Quy Nhon
    72,   // Binh Duong: Thu Dau Mot
    81,   // Binh Phuoc: Dong Xoai
    92,   // Binh Thuan: Phan Thiet
    102,  // Ca Mau: Ca Mau
    111,  // Can Tho: Ninh Kieu
    120,  // Cao Bang: Cao Bang
    130,  // Da Nang: Hai Chau
    138,  // Dak Lak: Buon Ma Thuot
    153,  // Dak Nong: Gia Nghia
    161,  // Dien Bien: Dien Bien Phu
    171,  // Dong Nai: Bien Hoa
    182,  // Dong Thap: Cao Lanh
    194,  // Gia Lai: Pleiku
    211,  // Ha Giang: Ha Giang
    222,  // Ha Nam: Phu Ly
    228,  // Ha Noi: Ba Dinh
    258,  // Ha Tinh: Ha Tinh
    271,  // Hai Duong: Hai Duong
    283,  // Hai Phong: Hong Bang
    298,  // Hau Giang: Vi Thanh
    306,  // Hoa Binh: Hoa Binh
    316,  // Hung Yen: Hung Yen
    326,  // Khanh Hoa: Nha Trang
    335,  // Kien Giang: Rach Gia
    350,  // Kon Tum: Kon Tum
    360,  // Lai Chau: Lai Chau
    368,  // Lam Dong: Da Lat
    380,  // Lang Son: Lang Son
    391,  // Lao Cai: Lao Cai
    400,  // Long An: Tan An
    415,  // Nam Dinh: Nam Dinh
    425,  // Nghe An: Vinh
    446,  // Ninh Binh: Ninh Binh
    454,  // Ninh Thuan: Phan Rang - Thap Cham
    461,  // Phu Tho: Viet Tri
    474,  // Phu Yen: Tuy Hoa
    483,  // Quang Binh: Dong Hoi
    491,  // Quang Nam: Tam Ky
    509,  // Quang Ngai: Quang Ngai
    523,  // Quang Ninh: Ha Long
    537,  // Quang Tri: Dong Ha
    547,  // Soc Trang: Soc Trang
    558,  // Son La: Son La
    570,  // Tay Ninh: Tay Ninh
    579,  // Thai Binh: Thai Binh
    587,  // Thai Nguyen: Thai Nguyen
    596,  // Thanh Hoa: Thanh Hoa
    623,  // Thanh pho Ho Chi Minh: Quan 1
    647,  // Thua Thien Hue: Hue
    656,  // Tien Giang: My Tho
    667,  // Tra Vinh: Tra Vinh
    676,  // Tuyen Quang: Tuyen Quang
    683,  // Vinh Long: Vinh Long
    691,  // Vinh Phuc: Vinh Yen
    700   // Yen Bai: Yen Bai
};


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