#include "..\Headers\data.h"    // Bao gồm file header chứa định nghĩa hằng số và khai báo biến extern

// KHỞI TẠO CÁC MẢNG CƠ SỞ DỮ LIỆU
char* PROVINCES_DB[MAX_PROVINCE] = {    // Mảng lưu danh sách tỉnh/thành phố tại Việt Nam
    "An Giang", "Ba Ria - Vung Tau", "Bac Giang", "Bac Kan", "Bac Lieu", "Bac Ninh",
    "Ben Tre", "Binh Dinh", "Binh Duong", "Binh Phuoc", "Binh Thuan", "Ca Mau",
    "Can Tho", "Cao Bang", "Da Nang", "Dak Lak", "Dak Nong", "Dien Bien",
    "Dong Nai", "Dong Thap", "Gia Lai", "Ha Giang", "Ha Nam", "Ha Noi",
    "Ha Tinh", "Hai Duong", "Hai Phong", "Hau Giang", "Hoa Binh", "Hung Yen",
    "Khanh Hoa", "Kien Giang", "Kon Tum", "Lai Chau", "Lam Dong", "Lang Son",
    "Lao Cai", "Long An", "Nam Dinh", "Nghe An", "Ninh Binh", "Ninh Thuan",
    "Phu Tho", "Phu Yen", "Quang Binh", "Quang Nam", "Quang Ngai", "Quang Ninh",
    "Quang Tri", "Soc Trang", "Son La", "Tay Ninh", "Thai Binh", "Thai Nguyen",
    "Thanh Hoa", "TP. Ho Chi Minh", "Thua Thien Hue", "Tien Giang", "Tra Vinh",
    "Tuyen Quang", "Vinh Long", "Vinh Phuc", "Yen Bai"
};

char* DISTRICTS_DB[MAX_DISTRICTS] = {   // Mảng lưu danh sách huyện/quận tại Việt Nam
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

int PROVINCE_START_INDEX[MAX_PROVINCE] = {  // Mảng lưu chỉ số bắt đầu của huyện đầu tiên mỗi tỉnh trong DISTRICTS_DB
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

char* GENDER_DB[MAX_GENDER] = {         // Mảng lưu danh sách giới tính
    "Nam",                              // Chỉ số 0: Nam
    "Nu"                                // Chỉ số 1: Nữ
};

char* GENRES_DB[MAX_GENRE] = {          // Mảng lưu danh sách thể loại sách
    "Triet hoc",                       // Triết học: nghiên cứu bản chất, tư duy, đạo đức
    "Tam ly hoc",                      // Tâm lý học: nghiên cứu hành vi, cảm xúc con người
    "Ton giao & Tam linh",             // Tôn giáo và tâm linh: đạo Phật, Thiên Chúa, v.v.
    "Khoa hoc xa hoi",                 // Khoa học xã hội: xã hội học, nhân học, chính trị
    "Ngon ngu hoc",                    // Ngôn ngữ học: ngữ pháp, ngôn ngữ học ứng dụng
    "Khoa hoc tu nhien",               // Khoa học tự nhiên: vật lý, hóa học, sinh học
    "Toan hoc",                        // Toán học: đại số, hình học, thống kê
    "Cong nghe thong tin",             // Công nghệ thông tin: lập trình, trí tuệ nhân tạo
    "Ky thuat & Co khi",               // Kỹ thuật và cơ khí: cơ khí, điện tử, xây dựng
    "Nghe thuat",                      // Nghệ thuật: hội họa, âm nhạc, điêu khắc
    "Giai tri & Am nhac",              // Giải trí và âm nhạc: phim ảnh, ca nhạc, gameshow
    "Van hoc viet nam",                // Văn học Việt Nam: tiểu thuyết, thơ ca trong nước
    "Van hoc nuoc ngoai",              // Văn học nước ngoài: văn học cổ điển, hiện đại
    "Lich su",                         // Lịch sử: lịch sử thế giới, Việt Nam, văn minh
    "Dia ly & Du lich",                // Địa lý và du lịch: địa lý tự nhiên, sách du lịch
    "Kinh te",                         // Kinh tế: kinh tế học, tài chính, thị trường
    "Quan tri kinh doanh",             // Quản trị kinh doanh: quản lý, khởi nghiệp, marketing
    "Ky nang song",                    // Kỹ năng sống: phát triển bản thân, giao tiếp
    "Y hoc & Suc khoe",                // Y học và sức khỏe: dinh dưỡng, chăm sóc sức khỏe
    "Sach thieu nhi"                   // Sách thiếu nhi: truyện tranh, sách giáo dục trẻ em
};

int NUMBER_OF_GENRES = 20;              // Số lượng thể loại sách hiện có trong GENRES_DB

char* PUBLISHERS_DB[MAX_PUBLISHERS] = { // Mảng lưu danh sách nhà xuất bản (đã bỏ dấu)
    "Giao duc Viet Nam",                // 0: NXB Giáo dục Việt Nam
    "Kim Dong",                         // 1: NXB Kim Đồng
    "Tre",                              // 2: NXB Trẻ
    "The Gioi",                         // 3: NXB Thế Giới
    "Hoi Nha Van",                      // 4: NXB Hội Nhà Văn
    "Lao Dong",                         // 5: NXB Lao Động
    "Tu Phap",                          // 6: NXB Tư Pháp
    "Khoa hoc va Ky thuat",             // 7: NXB Khoa học và Kỹ thuật
    "Chinh tri Quoc gia Su that",       // 8: NXB Chính trị Quốc gia Sự thật
    "Van Hoc",                          // 9: NXB Văn Học
    "Phu Nu Viet Nam",                  // 10: NXB Phụ Nữ Việt Nam
    "Tong hop TP.HCM",                  // 11: NXB Tổng hợp TP.HCM
    "Thong tin va Truyen thong",        // 12: NXB Thông tin và Truyền thông
    "Giao thong Van tai",               // 13: NXB Giao thông Vận tải
    "Y hoc",                            // 14: NXB Y học
    "The duc The thao",                 // 15: NXB Thể dục Thể thao
    "Nong nghiep",                      // 16: NXB Nông nghiệp
    "Van hoa - Van nghe",               // 17: NXB Văn hóa - Văn nghệ
    "Cong an Nhan dan",                 // 18: NXB Công an Nhân dân
    "Quan doi Nhan dan",                // 19: NXB Quân đội Nhân dân
    "Thanh Nien",                       // 20: NXB Thanh Niên
    "Tri Thuc",                         // 21: NXB Tri Thức
    "Dan Tri",                          // 22: NXB Dân Trí
    "Thoi Dai",                         // 23: NXB Thời Đại
    "Ha Noi",                           // 24: NXB Hà Nội
    "Dai hoc Quoc gia Ha Noi",          // 25: NXB Đại học Quốc gia Hà Nội
    "Dai hoc Quoc gia TP.HCM",          // 26: NXB Đại học Quốc gia TP.HCM
    "Dai hoc Su pham",                  // 27: NXB Đại học Sư phạm
    "San khau",                         // 28: NXB Sân khấu
    "My thuat"                          // 29: NXB Mỹ thuật
};

int NUMBER_OF_PUBLISHERS = 30;          // Số lượng nhà xuất bản hiện có trong PUBLISHERS_DB (đã cập nhật)

// KHỞI TẠO MẢNG LƯU THÔNG TIN ĐỘC GIẢ
char IDS[MAX_READERS][MAX_ID] = {       // Mảng 2D lưu ID độc giả
    "DG0001",                           // Độc giả 1
    "DG0002"                            // Độc giả 2
};

char NAMES[MAX_READERS][MAX_NAME] = {   // Mảng 2D lưu tên độc giả
    "Duong Quyen Tran",                 // Tên độc giả 1
    "Nguyen Tran Nhat Anh Bao"          // Tên độc giả 2
};

char CIC_NUMBERS[MAX_READERS][MAX_CIC] = { // Mảng 2D lưu số CMND/CCCD của độc giả
    "123456789",                        // CMND/CCCD độc giả 1
    "123456789012"                      // CMND/CCCD độc giả 2
};

char BIRTHDAYS[MAX_READERS][MAX_DATE] = { // Mảng 2D lưu ngày sinh độc giả (DD/MM/YYYY)
    "01/01/1990",                       // Ngày sinh độc giả 1
    "15/05/1995"                        // Ngày sinh độc giả 2
};

int GENDERS[MAX_READERS] = {            // Mảng lưu chỉ số giới tính độc giả (0: Nam, 1: Nữ)
    1,                                  // Giới tính độc giả 1: Nữ
    0                                   // Giới tính độc giả 2: Nam
};

char EMAILS[MAX_READERS][MAX_EMAIL] = { // Mảng 2D lưu email độc giả
    "daoduyanhdh23a@gmail.com",         // Email độc giả 1
    "b@gmail.com"                       // Email độc giả 2
};

int DISTRICTS[MAX_READERS] = {          // Mảng lưu chỉ số huyện/quận của độc giả (liên kết DISTRICTS_DB)
    3,                                  // Huyện/quận độc giả 1: Tan Chau (An Giang)
    4                                   // Huyện/quận độc giả 2: Phu Tan (An Giang)
};

int PROVINCES[MAX_READERS] = {          // Mảng lưu chỉ số tỉnh/thành phố của độc giả (liên kết PROVINCES_DB)
    1,                                  // Tỉnh/thành độc giả 1: Ba Ria - Vung Tau
    50                                  // Tỉnh/thành độc giả 2: Soc Trang
};

char ISSUE_DATES[MAX_READERS][MAX_DATE] = { // Mảng 2D lưu ngày lập thẻ độc giả (DD/MM/YYYY)
    "01/01/2022",                       // Ngày lập thẻ độc giả 1
    "10/02/2022"                        // Ngày lập thẻ độc giả 2
};

int NUMBER_OF_READERS = 2;              // Số lượng độc giả hiện có trong hệ thống

// KHỞI TẠO MẢNG LƯU THÔNG TIN SÁCH (100 QUYỂN)

char ISBNs[MAX_BOOKS][MAX_ISBN] = {     // Mảng 2D lưu mã ISBN của sách (định dạng 978-604-x-xxxxx-y)
    "978-604-1-10001-7",                // ISBN sách 1
    "978-604-2-10002-6",                // ISBN sách 2
    "978-604-3-10003-5",                // ISBN sách 3
    "978-604-4-10004-4",                // ISBN sách 4
    "978-604-5-10005-3",                // ISBN sách 5
    "978-604-6-10006-2",                // ISBN sách 6
    "978-604-7-10007-1",                // ISBN sách 7
    "978-604-8-10008-0",                // ISBN sách 8
    "978-604-9-10009-9",                // ISBN sách 9
    "978-604-0-10010-5",                // ISBN sách 10
    "978-604-1-10011-4",                // ISBN sách 11
    "978-604-2-10012-3",                // ISBN sách 12
    "978-604-3-10013-2",                // ISBN sách 13
    "978-604-4-10014-1",                // ISBN sách 14
    "978-604-5-10015-0",                // ISBN sách 15
    "978-604-6-10016-9",                // ISBN sách 16
    "978-604-7-10017-8",                // ISBN sách 17
    "978-604-8-10018-7",                // ISBN sách 18
    "978-604-9-10019-6",                // ISBN sách 19
    "978-604-0-10020-2",                // ISBN sách 20
    "978-604-1-10021-1",                // ISBN sách 21
    "978-604-2-10022-0",                // ISBN sách 22
    "978-604-3-10023-9",                // ISBN sách 23
    "978-604-4-10024-8",                // ISBN sách 24
    "978-604-5-10025-7",                // ISBN sách 25
    "978-604-6-10026-6",                // ISBN sách 26
    "978-604-7-10027-5",                // ISBN sách 27
    "978-604-8-10028-4",                // ISBN sách 28
    "978-604-9-10029-3",                // ISBN sách 29
    "978-604-0-10030-9",                // ISBN sách 30
    "978-604-1-10031-8",                // ISBN sách 31
    "978-604-2-10032-7",                // ISBN sách 32
    "978-604-3-10033-6",                // ISBN sách 33
    "978-604-4-10034-5",                // ISBN sách 34
    "978-604-5-10035-4",                // ISBN sách 35
    "978-604-6-10036-3",                // ISBN sách 36
    "978-604-7-10037-2",                // ISBN sách 37
    "978-604-8-10038-1",                // ISBN sách 38
    "978-604-9-10039-0",                // ISBN sách 39
    "978-604-0-10040-6",                // ISBN sách 40
    "978-604-1-10041-5",                // ISBN sách 41
    "978-604-2-10042-4",                // ISBN sách 42
    "978-604-3-10043-3",                // ISBN sách 43
    "978-604-4-10044-2",                // ISBN sách 44
    "978-604-5-10045-1",                // ISBN sách 45
    "978-604-6-10046-0",                // ISBN sách 46
    "978-604-7-10047-9",                // ISBN sách 47
    "978-604-8-10048-8",                // ISBN sách 48
    "978-604-9-10049-7",                // ISBN sách 49
    "978-604-0-10050-3",                // ISBN sách 50
    "978-604-1-10051-2",                // ISBN sách 51
    "978-604-2-10052-1",                // ISBN sách 52
    "978-604-3-10053-0",                // ISBN sách 53
    "978-604-4-10054-9",                // ISBN sách 54
    "978-604-5-10055-8",                // ISBN sách 55
    "978-604-6-10056-7",                // ISBN sách 56
    "978-604-7-10057-6",                // ISBN sách 57
    "978-604-8-10058-5",                // ISBN sách 58
    "978-604-9-10059-4",                // ISBN sách 59
    "978-604-0-10060-0",                // ISBN sách 60
    "978-604-1-10061-9",                // ISBN sách 61
    "978-604-2-10062-8",                // ISBN sách 62
    "978-604-3-10063-7",                // ISBN sách 63
    "978-604-4-10064-6",                // ISBN sách 64
    "978-604-5-10065-5",                // ISBN sách 65
    "978-604-6-10066-4",                // ISBN sách 66
    "978-604-7-10067-3",                // ISBN sách 67
    "978-604-8-10068-2",                // ISBN sách 68
    "978-604-9-10069-1",                // ISBN sách 69
    "978-604-0-10070-7",                // ISBN sách 70
    "978-604-1-10071-6",                // ISBN sách 71
    "978-604-2-10072-5",                // ISBN sách 72
    "978-604-3-10073-4",                // ISBN sách 73
    "978-604-4-10074-3",                // ISBN sách 74
    "978-604-5-10075-2",                // ISBN sách 75
    "978-604-6-10076-1",                // ISBN sách 76
    "978-604-7-10077-0",                // ISBN sách 77
    "978-604-8-10078-9",                // ISBN sách 78
    "978-604-9-10079-8",                // ISBN sách 79
    "978-604-0-10080-4",                // ISBN sách 80
    "978-604-1-10081-3",                // ISBN sách 81
    "978-604-2-10082-2",                // ISBN sách 82
    "978-604-3-10083-1",                // ISBN sách 83
    "978-604-4-10084-0",                // ISBN sách 84
    "978-604-5-10085-9",                // ISBN sách 85
    "978-604-6-10086-8",                // ISBN sách 86
    "978-604-7-10087-7",                // ISBN sách 87
    "978-604-8-10088-6",                // ISBN sách 88
    "978-604-9-10089-5",                // ISBN sách 89
    "978-604-0-10090-1",                // ISBN sách 90
    "978-604-1-10091-0",                // ISBN sách 91
    "978-604-2-10092-9",                // ISBN sách 92
    "978-604-3-10093-8",                // ISBN sách 93
    "978-604-4-10094-7",                // ISBN sách 94
    "978-604-5-10095-6",                // ISBN sách 95
    "978-604-6-10096-5",                // ISBN sách 96
    "978-604-7-10097-4",                // ISBN sách 97
    "978-604-8-10098-3",                // ISBN sách 98
    "978-604-9-10099-2",                // ISBN sách 99
    "978-604-0-10100-8"                 // ISBN sách 100
};

char TITLES[MAX_BOOKS][MAX_TITLE] = {   // Mảng 2D lưu tiêu đề sách
    "Lap trinh C++ tu co ban den nang cao", // Sách 1: Lập trình C++
    "Cau truc du lieu & Giai thuat",        // Sách 2: Cấu trúc dữ liệu
    "Hoc lap trinh Python",                 // Sách 3: Lập trình Python
    "Thiet ke va Phat trien Web",           // Sách 4: Thiết kế web
    "Tri tue nhan tao va Ung dung",         // Sách 5: Trí tuệ nhân tạo
    "Khoa hoc xa hoi Viet Nam",             // Sách 6: Khoa học xã hội
    "Van hoc Viet Nam the ky 20",           // Sách 7: Văn học Việt Nam
    "Ky nang giao tiep hieu qua",           // Sách 8: Kỹ năng giao tiếp
    "Suc khoe va dinh duong",               // Sách 9: Sức khỏe
    "Truyen tranh Doraemon tap 1",          // Sách 10: Sách thiếu nhi
    "Lich su the gioi co dai",              // Sách 11: Lịch sử
    "Tam ly hoc toi pham",                  // Sách 12: Tâm lý học
    "Toan cao cap tap 1",                   // Sách 13: Toán học
    "Nhap mon cong nghe thong tin",         // Sách 14: Công nghệ thông tin
    "Nghe thuat hoi hoa",                   // Sách 15: Nghệ thuật
    "Kinh te vi mo",                        // Sách 16: Kinh tế
    "Quan tri chien luoc",                  // Sách 17: Quản trị kinh doanh
    "Dia ly Viet Nam",                      // Sách 18: Địa lý
    "Ton giao va van hoa",                  // Sách 19: Tôn giáo
    "Hoc tieng Anh qua truyen",             // Sách 20: Ngôn ngữ học
    "Triet hoc phuong Dong",                // Sách 21: Triết học
    "Ky thuat dien tu",                     // Sách 22: Kỹ thuật
    "Truyen ngan Nam Cao",                  // Sách 23: Văn học Việt Nam
    "Van hoc My the ky 19",                 // Sách 24: Văn học nước ngoài
    "7 thoi quen hieu qua",                 // Sách 25: Kỹ năng sống
    "Hoc lap trinh Java",                   // Sách 26: Công nghệ thông tin
    "Suc manh cua tu duy tich cuc",         // Sách 27: Kỹ năng sống
    "Lich su Viet Nam thoi Ly",             // Sách 28: Lịch sử
    "Tam ly hoc hanh vi",                   // Sách 29: Tâm lý học
    "Toan roi rac",                         // Sách 30: Toán học
    "An ninh mang",                         // Sách 31: Công nghệ thông tin
    "Nghe thuat am nhac Viet Nam",          // Sách 32: Nghệ thuật
    "Kinh te vi mo tap 2",                  // Sách 33: Kinh tế
    "Quan tri nhan su",                     // Sách 34: Quản trị kinh doanh
    "Du lich Viet Nam",                     // Sách 35: Địa lý & Du lịch
    "Phat giao va doi song",                // Sách 36: Tôn giáo
    "Hoc tieng Nhat can ban",               // Sách 37: Ngôn ngữ học
    "Khoa hoc vat ly co ban",               // Sách 38: Khoa học tự nhiên
    "Truyen tranh Conan tap 1",             // Sách 39: Sách thiếu nhi
    "Triet hoc phuong Tay",                 // Sách 40: Triết học
    "Ky thuat co khi",                      // Sách 41: Kỹ thuật & Cơ khí
    "Tho ca Viet Nam",                      // Sách 42: Văn học Việt Nam
    "Tieu thuyet Nga",                      // Sách 43: Văn học nước ngoài
    "Tu tin buoc toi",                      // Sách 44: Kỹ năng sống
    "Hoc SQL co ban",                       // Sách 45: Công nghệ thông tin
    "Tam ly hoc gioi tinh",                 // Sách 46: Tâm lý học
    "Dai so tuyen tinh",                    // Sách 47: Toán học
    "Cong nghe Blockchain",                 // Sách 48: Công nghệ thông tin
    "Nghe thuat dieu khac",                 // Sách 49: Nghệ thuật
    "Kinh te chinh tri",                    // Sách 50: Kinh tế
    "Marketing 4.0",                        // Sách 51: Quản trị kinh doanh
    "Dia ly the gioi",                      // Sách 52: Địa lý & Du lịch
    "Dao giao va van hoa",                  // Sách 53: Tôn giáo
    "Hoc tieng Han qua bai hat",            // Sách 54: Ngôn ngữ học
    "Hoa hoc huu co",                       // Sách 55: Khoa học tự nhiên
    "Truyen tranh One Piece tap 1",         // Sách 56: Sách thiếu nhi
    "Triet hoc Marx-Lenin",                 // Sách 57: Triết học
    "Ky thuat xay dung",                    // Sách 58: Kỹ thuật & Cơ khí
    "Truyen dai Nguyen Du",                 // Sách 59: Văn học Việt Nam
    "Van hoc Anh the ky 18",                // Sách 60: Văn học nước ngoài
    "Quan ly thoi gian",                    // Sách 61: Kỹ năng sống
    "Lap trinh Android",                    // Sách 62: Công nghệ thông tin
    "Tam ly hoc tre em",                    // Sách 63: Tâm lý học
    "Xac suat thong ke",                    // Sách 64: Toán học
    "Hoc lap trinh R",                      // Sách 65: Công nghệ thông tin
    "Nghe thuat dien anh",                  // Sách 66: Nghệ thuật
    "Kinh te quoc te",                      // Sách 67: Kinh tế
    "Quan tri rui ro",                      // Sách 68: Quản trị kinh doanh
    "Du lich chau Au",                      // Sách 69: Địa lý & Du lịch
    "Thien Chua giao va van hoa",           // Sách 70: Tôn giáo
    "Hoc tieng Trung co ban",               // Sách 71: Ngôn ngữ học
    "Sinh hoc phan tu",                     // Sách 72: Khoa học tự nhiên
    "Truyen tranh Naruto tap 1",            // Sách 73: Sách thiếu nhi
    "Triet hoc nghe thuat",                 // Sách 74: Triết học
    "Ky thuat dien",                        // Sách 75: Kỹ thuật & Cơ khí
    "Tho Luc Van Doan",                     // Sách 76: Văn học Việt Nam
    "Tieu thuyet Phap",                     // Sách 77: Văn học nước ngoài
    "Tu duy phan bien",                     // Sách 78: Kỹ năng sống
    "Hoc lap trinh PHP",                    // Sách 79: Công nghệ thông tin
    "Tam ly hoc xa hoi",                    // Sách 80: Tâm lý học
    "Hinh hoc phang",                       // Sách 81: Toán học
    "Cong nghe IoT",                        // Sách 82: Công nghệ thông tin
    "Nghe thuat truyen thong",              // Sách 83: Nghệ thuật
    "Tai chinh doanh nghiep",               // Sách 84: Kinh tế
    "Quan tri cung ung",                    // Sách 85: Quản trị kinh doanh
    "Dia ly kinh te",                       // Sách 86: Địa lý & Du lịch
    "Tam linh phuong Dong",                 // Sách 87: Tôn giáo
    "Hoc tieng Duc qua phim",               // Sách 88: Ngôn ngữ học
    "Vat ly hat nhan",                      // Sách 89: Khoa học tự nhiên
    "Truyen tranh Dragon Ball tap 1",       // Sách 90: Sách thiếu nhi
    "Triet hoc phan tich",                  // Sách 91: Triết học
    "Ky thuat che tao",                     // Sách 92: Kỹ thuật & Cơ khí
    "Tieu thuyet Viet Nam",                 // Sách 93: Văn học Việt Nam
    "Van hoc Nhat Ban",                     // Sách 94: Văn học nước ngoài
    "Ky nang lanh dao",                     // Sách 95: Kỹ năng sống
    "Hoc lap trinh C#",                     // Sách 96: Công nghệ thông tin
    "Tam ly hoc nhan cach",                 // Sách 97: Tâm lý học
    "Giai tich toan hoc",                   // Sách 98: Toán học
    "Cong nghe may tinh",                   // Sách 99: Công nghệ thông tin
    "Nghe thuat thiet ke",                  // Sách 100: Nghệ thuật
};

char AUTHORS[MAX_BOOKS][MAX_AUTHOR] = { // Mảng 2D lưu tên tác giả của sách
    "Nguyen Van A",                     // Tác giả sách 1
    "Tran Thi B",                       // Tác giả sách 2
    "Le Van C",                         // Tác giả sách 3
    "Pham Thi D",                       // Tác giả sách 4
    "Hoang Van E",                      // Tác giả sách 5
    "Nguyen Thi F",                     // Tác giả sách 6
    "Tran Van G",                       // Tác giả sách 7
    "Le Thi H",                         // Tác giả sách 8
    "Pham Van I",                       // Tác giả sách 9
    "Fujiko F Fujio",                   // Tác giả sách 10
    "Nguyen Van J",                     // Tác giả sách 11
    "Tran Thi K",                       // Tác giả sách 12
    "Le Van L",                         // Tác giả sách 13
    "Pham Thi M",                       // Tác giả sách 14
    "Hoang Van N",                      // Tác giả sách 15
    "Nguyen Thi O",                     // Tác giả sách 16
    "Tran Van P",                       // Tác giả sách 17
    "Le Thi Q",                         // Tác giả sách 18
    "Pham Van R",                       // Tác giả sách 19
    "Nguyen Van S",                     // Tác giả sách 20
    "Tran Thi T",                       // Tác giả sách 21
    "Le Van U",                         // Tác giả sách 22
    "Pham Thi V",                       // Tác giả sách 23
    "Hoang Van W",                      // Tác giả sách 24
    "Nguyen Thi X",                     // Tác giả sách 25
    "Tran Van Y",                       // Tác giả sách 26
    "Le Thi Z",                         // Tác giả sách 27
    "Pham Van AA",                      // Tác giả sách 28
    "Nguyen Van AB",                    // Tác giả sách 29
    "Tran Thi AC",                      // Tác giả sách 30
    "Le Van AD",                        // Tác giả sách 31
    "Pham Thi AE",                      // Tác giả sách 32
    "Hoang Van AF",                     // Tác giả sách 33
    "Nguyen Thi AG",                    // Tác giả sách 34
    "Tran Van AH",                      // Tác giả sách 35
    "Le Thi AI",                        // Tác giả sách 36
    "Pham Van AJ",                      // Tác giả sách 37
    "Nguyen Van AK",                    // Tác giả sách 38
    "Aoyama Gosho",                     // Tác giả sách 39
    "Tran Thi AL",                      // Tác giả sách 40
    "Le Van AM",                        // Tác giả sách 41
    "Pham Thi AN",                      // Tác giả sách 42
    "Hoang Van AO",                     // Tác giả sách 43
    "Nguyen Thi AP",                    // Tác giả sách 44
    "Tran Van AQ",                      // Tác giả sách 45
    "Le Thi AR",                        // Tác giả sách 46
    "Pham Van AS",                      // Tác giả sách 47
    "Nguyen Van AT",                    // Tác giả sách 48
    "Tran Thi AU",                      // Tác giả sách 49
    "Le Van AV",                        // Tác giả sách 50
    "Pham Thi AW",                      // Tác giả sách 51
    "Hoang Van AX",                     // Tác giả sách 52
    "Nguyen Thi AY",                    // Tác giả sách 53
    "Tran Van AZ",                      // Tác giả sách 54
    "Le Thi BA",                        // Tác giả sách 55
    "Eiichiro Oda",                     // Tác giả sách 56
    "Pham Van BB",                      // Tác giả sách 57
    "Nguyen Van BC",                    // Tác giả sách 58
    "Tran Thi BD",                      // Tác giả sách 59
    "Le Van BE",                        // Tác giả sách 60
    "Pham Thi BF",                      // Tác giả sách 61
    "Hoang Van BG",                     // Tác giả sách 62
    "Nguyen Thi BH",                    // Tác giả sách 63
    "Tran Van BI",                      // Tác giả sách 64
    "Le Thi BJ",                        // Tác giả sách 65
    "Pham Van BK",                      // Tác giả sách 66
    "Nguyen Van BL",                    // Tác giả sách 67
    "Tran Thi BM",                      // Tác giả sách 68
    "Le Van BN",                        // Tác giả sách 69
    "Pham Thi BO",                      // Tác giả sách 70
    "Hoang Van BP",                     // Tác giả sách 71
    "Nguyen Thi BQ",                    // Tác giả sách 72
    "Masashi Kishimoto",                // Tác giả sách 73
    "Tran Van BR",                      // Tác giả sách 74
    "Le Thi BS",                        // Tác giả sách 75
    "Pham Van BT",                      // Tác giả sách 76
    "Nguyen Van BU",                    // Tác giả sách 77
    "Tran Thi BV",                      // Tác giả sách 78
    "Le Van BW",                        // Tác giả sách 79
    "Pham Thi BX",                      // Tác giả sách 80
    "Hoang Van BY",                     // Tác giả sách 81
    "Nguyen Thi BZ",                    // Tác giả sách 82
    "Tran Van CA",                      // Tác giả sách 83
    "Le Thi CB",                        // Tác giả sách 84
    "Pham Van CC",                      // Tác giả sách 85
    "Nguyen Van CD",                    // Tác giả sách 86
    "Tran Thi CE",                      // Tác giả sách 87
    "Le Van CF",                        // Tác giả sách 88
    "Pham Thi CG",                      // Tác giả sách 89
    "Akira Toriyama",                   // Tác giả sách 90
    "Hoang Van CH",                     // Tác giả sách 91
    "Nguyen Thi CI",                    // Tác giả sách 92
    "Tran Van CJ",                      // Tác giả sách 93
    "Le Thi CK",                        // Tác giả sách 94
    "Pham Van CL",                      // Tác giả sách 95
    "Nguyen Van CM",                    // Tác giả sách 96
    "Tran Thi CN",                      // Tác giả sách 97
    "Le Van CO",                        // Tác giả sách 98
    "Pham Thi CP",                      // Tác giả sách 99
    "Hoang Van CQ"                      // Tác giả sách 100
};

int PUBLISHERS[MAX_BOOKS] = {           // Mảng lưu chỉ số nhà xuất bản (liên kết PUBLISHERS_DB)
    0,                                  // Sách 1: Giao duc Viet Nam
    7,                                  // Sách 2: Khoa hoc va Ky thuat
    2,                                  // Sách 3: Tre
    3,                                  // Sách 4: The Gioi
    7,                                  // Sách 5: Khoa hoc va Ky thuat
    8,                                  // Sách 6: Chinh tri Quoc gia Su that
    9,                                  // Sách 7: Van Hoc
    11,                                 // Sách 8: Tong hop TP.HCM
    14,                                 // Sách 9: Y hoc
    1,                                  // Sách 10: Kim Dong
    4,                                  // Sách 11: Hoi Nha Van
    10,                                 // Sách 12: Phu Nu Viet Nam
    0,                                  // Sách 13: Giao duc Viet Nam
    7,                                  // Sách 14: Khoa hoc va Ky thuat
    17,                                 // Sách 15: Van hoa - Van nghe
    21,                                 // Sách 16: Tri Thuc
    11,                                 // Sách 17: Tong hop TP.HCM
    24,                                 // Sách 18: Ha Noi
    5,                                  // Sách 19: Lao Dong
    2,                                  // Sách 20: Tre
    8,                                  // Sách 21: Chinh tri Quoc gia Su that
    13,                                 // Sách 22: Giao thong Van tai
    9,                                  // Sách 23: Van Hoc
    4,                                  // Sách 24: Hoi Nha Van
    11,                                 // Sách 25: Tong hop TP.HCM
    7,                                  // Sách 26: Khoa hoc va Ky thuat
    10,                                 // Sách 27: Phu Nu Viet Nam
    4,                                  // Sách 28: Hoi Nha Van
    10,                                 // Sách 29: Phu Nu Viet Nam
    0,                                  // Sách 30: Giao duc Viet Nam
    7,                                  // Sách 31: Khoa hoc va Ky thuat
    17,                                 // Sách 32: Van hoa - Van nghe
    21,                                 // Sách 33: Tri Thuc
    11,                                 // Sách 34: Tong hop TP.HCM
    24,                                 // Sách 35: Ha Noi
    5,                                  // Sách 36: Lao Dong
    2,                                  // Sách 37: Tre
    0,                                  // Sách 38: Giao duc Viet Nam
    1,                                  // Sách 39: Kim Dong
    8,                                  // Sách 40: Chinh tri Quoc gia Su that
    13,                                 // Sách 41: Giao thong Van tai
    9,                                  // Sách 42: Van Hoc
    4,                                  // Sách 43: Hoi Nha Van
    11,                                 // Sách 44: Tong hop TP.HCM
    7,                                  // Sách 45: Khoa hoc va Ky thuat
    10,                                 // Sách 46: Phu Nu Viet Nam
    0,                                  // Sách 47: Giao duc Viet Nam
    7,                                  // Sách 48: Khoa hoc va Ky thuat
    17,                                 // Sách 49: Van hoa - Van nghe
    21,                                 // Sách 50: Tri Thuc
    11,                                 // Sách 51: Tong hop TP.HCM
    24,                                 // Sách 52: Ha Noi
    5,                                  // Sách 53: Lao Dong
    2,                                  // Sách 54: Tre
    0,                                  // Sách 55: Giao duc Viet Nam
    1,                                  // Sách 56: Kim Dong
    8,                                  // Sách 57: Chinh tri Quoc gia Su that
    13,                                 // Sách 58: Giao thong Van tai
    9,                                  // Sách 59: Van Hoc
    4,                                  // Sách 60: Hoi Nha Van
    11,                                 // Sách 61: Tong hop TP.HCM
    7,                                  // Sách 62: Khoa hoc va Ky thuat
    10,                                 // Sách 63: Phu Nu Viet Nam
    0,                                  // Sách 64: Giao duc Viet Nam
    7,                                  // Sách 65: Khoa hoc va Ky thuat
    17,                                 // Sách 66: Van hoa - Van nghe
    21,                                 // Sách 67: Tri Thuc
    11,                                 // Sách 68: Tong hop TP.HCM
    24,                                 // Sách 69: Ha Noi
    5,                                  // Sách 70: Lao Dong
    2,                                  // Sách 71: Tre
    0,                                  // Sách 72: Giao duc Viet Nam
    1,                                  // Sách 73: Kim Dong
    8,                                  // Sách 74: Chinh tri Quoc gia Su that
    13,                                 // Sách 75: Giao thong Van tai
    9,                                  // Sách 76: Van Hoc
    4,                                  // Sách 77: Hoi Nha Van
    11,                                 // Sách 78: Tong hop TP.HCM
    7,                                  // Sách 79: Khoa hoc va Ky thuat
    10,                                 // Sách 80: Phu Nu Viet Nam
    0,                                  // Sách 81: Giao duc Viet Nam
    7,                                  // Sách 82: Khoa hoc va Ky thuat
    17,                                 // Sách 83: Van hoa - Van nghe
    21,                                 // Sách 84: Tri Thuc
    11,                                 // Sách 85: Tong hop TP.HCM
    24,                                 // Sách 86: Ha Noi
    5,                                  // Sách 87: Lao Dong
    2,                                  // Sách 88: Tre
    0,                                  // Sách 89: Giao duc Viet Nam
    1,                                  // Sách 90: Kim Dong
    8,                                  // Sách 91: Chinh tri Quoc gia Su that
    13,                                 // Sách 92: Giao thong Van tai
    9,                                  // Sách 93: Van Hoc
    4,                                  // Sách 94: Hoi Nha Van
    11,                                 // Sách 95: Tong hop TP.HCM
    7,                                  // Sách 96: Khoa hoc va Ky thuat
    10,                                 // Sách 97: Phu Nu Viet Nam
    0,                                  // Sách 98: Giao duc Viet Nam
    7,                                  // Sách 99: Khoa hoc va Ky thuat
    17                                  // Sách 100: Van hoa - Van nghe
};

char PUBLISH_YEARS[MAX_BOOKS][MAX_YEAR] = { // Mảng 2D lưu năm xuất bản (YYYY)
    "2020",                             // Năm xuất bản sách 1
    "2019",                             // Năm xuất bản sách 2
    "2021",                             // Năm xuất bản sách 3
    "2022",                             // Năm xuất bản sách 4
    "2023",                             // Năm xuất bản sách 5
    "2018",                             // Năm xuất bản sách 6
    "2020",                             // Năm xuất bản sách 7
    "2021",                             // Năm xuất bản sách 8
    "2019",                             // Năm xuất bản sách 9
    "2022",                             // Năm xuất bản sách 10
    "2023",                             // Năm xuất bản sách 11
    "2020",                             // Năm xuất bản sách 12
    "2017",                             // Năm xuất bản sách 13
    "2021",                             // Năm xuất bản sách 14
    "2019",                             // Năm xuất bản sách 15
    "2022",                             // Năm xuất bản sách 16
    "2020",                             // Năm xuất bản sách 17
    "2018",                             // Năm xuất bản sách 18
    "2021",                             // Năm xuất bản sách 19
    "2023",                             // Năm xuất bản sách 20
    "2019",                             // Năm xuất bản sách 21
    "2020",                             // Năm xuất bản sách 22
    "2022",                             // Năm xuất bản sách 23
    "2021",                             // Năm xuất bản sách 24
    "2020",                             // Năm xuất bản sách 25
    "2018",                             // Năm xuất bản sách 26
    "2021",                             // Năm xuất bản sách 27
    "2019",                             // Năm xuất bản sách 28
    "2022",                             // Năm xuất bản sách 29
    "2023",                             // Năm xuất bản sách 30
    "2020",                             // Năm xuất bản sách 31
    "2017",                             // Năm xuất bản sách 32
    "2021",                             // Năm xuất bản sách 33
    "2019",                             // Năm xuất bản sách 34
    "2022",                             // Năm xuất bản sách 35
    "2018",                             // Năm xuất bản sách 36
    "2020",                             // Năm xuất bản sách 37
    "2023",                             // Năm xuất bản sách 38
    "2021",                             // Năm xuất bản sách 39
    "2019",                             // Năm xuất bản sách 40
    "2020",                             // Năm xuất bản sách 41
    "2022",                             // Năm xuất bản sách 42
    "2021",                             // Năm xuất bản sách 43
    "2020",                             // Năm xuất bản sách 44
    "2018",                             // Năm xuất bản sách 45
    "2021",                             // Năm xuất bản sách 46
    "2019",                             // Năm xuất bản sách 47
    "2022",                             // Năm xuất bản sách 48
    "2023",                             // Năm xuất bản sách 49
    "2020",                             // Năm xuất bản sách 50
    "2017",                             // Năm xuất bản sách 51
    "2021",                             // Năm xuất bản sách 52
    "2019",                             // Năm xuất bản sách 53
    "2022",                             // Năm xuất bản sách 54
    "2018",                             // Năm xuất bản sách 55
    "2020",                             // Năm xuất bản sách 56
    "2023",                             // Năm xuất bản sách 57
    "2021",                             // Năm xuất bản sách 58
    "2019",                             // Năm xuất bản sách 59
    "2020",                             // Năm xuất bản sách 60
    "2022",                             // Năm xuất bản sách 61
    "2021",                             // Năm xuất bản sách 62
    "2020",                             // Năm xuất bản sách 63
    "2018",                             // Năm xuất bản sách 64
    "2021",                             // Năm xuất bản sách 65
    "2019",                             // Năm xuất bản sách 66
    "2022",                             // Năm xuất bản sách 67
    "2023",                             // Năm xuất bản sách 68
    "2020",                             // Năm xuất bản sách 69
    "2017",                             // Năm xuất bản sách 70
    "2021",                             // Năm xuất bản sách 71
    "2019",                             // Năm xuất bản sách 72
    "2022",                             // Năm xuất bản sách 73
    "2018",                             // Năm xuất bản sách 74
    "2020",                             // Năm xuất bản sách 75
    "2023",                             // Năm xuất bản sách 76
    "2021",                             // Năm xuất bản sách 77
    "2019",                             // Năm xuất bản sách 78
    "2020",                             // Năm xuất bản sách 79
    "2022",                             // Năm xuất bản sách 80
    "2021",                             // Năm xuất bản sách 81
    "2020",                             // Năm xuất bản sách 82
    "2018",                             // Năm xuất bản sách 83
    "2021",                             // Năm xuất bản sách 84
    "2019",                             // Năm xuất bản sách 85
    "2022",                             // Năm xuất bản sách 86
    "2023",                             // Năm xuất bản sách 87
    "2020",                             // Năm xuất bản sách 88
    "2017",                             // Năm xuất bản sách 89
    "2021",                             // Năm xuất bản sách 90
    "2019",                             // Năm xuất bản sách 91
    "2020",                             // Năm xuất bản sách 92
    "2022",                             // Năm xuất bản sách 93
    "2021",                             // Năm xuất bản sách 94
    "2020",                             // Năm xuất bản sách 95
    "2018",                             // Năm xuất bản sách 96
    "2021",                             // Năm xuất bản sách 97
    "2019",                             // Năm xuất bản sách 98
    "2022",                             // Năm xuất bản sách 99
    "2023"                              // Năm xuất bản sách 100
};

int CATEGORIES[MAX_BOOKS] = {           // Mảng lưu chỉ số thể loại (liên kết GENRES_DB)
    7,                                  // Sách 1: Cong nghe thong tin
    7,                                  // Sách 2: Cong nghe thong tin
    7,                                  // Sách 3: Cong nghe thong tin
    7,                                  // Sách 4: Cong nghe thong tin
    7,                                  // Sách 5: Cong nghe thong tin
    3,                                  // Sách 6: Khoa hoc xa hoi
    11,                                 // Sách 7: Van hoc viet nam
    17,                                 // Sách 8: Ky nang song
    18,                                 // Sách 9: Y hoc & Suc khoe
    19,                                 // Sách 10: Sach thieu nhi
    13,                                 // Sách 11: Lich su
    1,                                  // Sách 12: Tam ly hoc
    6,                                  // Sách 13: Toan hoc
    7,                                  // Sách 14: Cong nghe thong tin
    9,                                  // Sách 15: Nghe thuat
    15,                                 // Sách 16: Kinh te
    16,                                 // Sách 17: Quan tri kinh doanh
    14,                                 // Sách 18: Dia ly & Du lich
    2,                                  // Sách 19: Ton giao & Tam linh
    4,                                  // Sách 20: Ngon ngu hoc
    0,                                  // Sách 21: Triet hoc
    8,                                  // Sách 22: Ky thuat & Co khi
    11,                                 // Sách 23: Van hoc viet nam
    12,                                 // Sách 24: Van hoc nuoc ngoai
    17,                                 // Sách 25: Ky nang song
    7,                                  // Sách 26: Cong nghe thong tin
    17,                                 // Sách 27: Ky nang song
    13,                                 // Sách 28: Lich su
    1,                                  // Sách 29: Tam ly hoc
    6,                                  // Sách 30: Toan hoc
    7,                                  // Sách 31: Cong nghe thong tin
    9,                                  // Sách 32: Nghe thuat
    15,                                 // Sách 33: Kinh te
    16,                                 // Sách 34: Quan tri kinh doanh
    14,                                 // Sách 35: Dia ly & Du lich
    2,                                  // Sách 36: Ton giao & Tam linh
    4,                                  // Sách 37: Ngon ngu hoc
    5,                                  // Sách 38: Khoa hoc tu nhien
    19,                                 // Sách 39: Sach thieu nhi
    0,                                  // Sách 40: Triet hoc
    8,                                  // Sách 41: Ky thuat & Co khi
    11,                                 // Sách 42: Van hoc viet nam
    12,                                 // Sách 43: Van hoc nuoc ngoai
    17,                                 // Sách 44: Ky nang song
    7,                                  // Sách 45: Cong nghe thong tin
    1,                                  // Sách 46: Tam ly hoc
    6,                                  // Sách 47: Toan hoc
    7,                                  // Sách 48: Cong nghe thong tin
    9,                                  // Sách 49: Nghe thuat
    15,                                 // Sách 50: Kinh te
    16,                                 // Sách 51: Quan tri kinh doanh
    14,                                 // Sách 52: Dia ly & Du lich
    2,                                  // Sách 53: Ton giao & Tam linh
    4,                                  // Sách 54: Ngon ngu hoc
    5,                                  // Sách 55: Khoa hoc tu nhien
    19,                                 // Sách 56: Sach thieu nhi
    0,                                  // Sách 57: Triet hoc
    8,                                  // Sách 58: Ky thuat & Co khi
    11,                                 // Sách 59: Van hoc viet nam
    12,                                 // Sách 60: Van hoc nuoc ngoai
    17,                                 // Sách 61: Ky nang song
    7,                                  // Sách 62: Cong nghe thong tin
    1,                                  // Sách 63: Tam ly hoc
    6,                                  // Sách 64: Toan hoc
    7,                                  // Sách 65: Cong nghe thong tin
    9,                                  // Sách 66: Nghe thuat
    15,                                 // Sách 67: Kinh te
    16,                                 // Sách 68: Quan tri kinh doanh
    14,                                 // Sách 69: Dia ly & Du lich
    2,                                  // Sách 70: Ton giao & Tam linh
    4,                                  // Sách 71: Ngon ngu hoc
    5,                                  // Sách 72: Khoa hoc tu nhien
    19,                                 // Sách 73: Sach thieu nhi
    0,                                  // Sách 74: Triet hoc
    8,                                  // Sách 75: Ky thuat & Co khi
    11,                                 // Sách 76: Van hoc viet nam
    12,                                 // Sách 77: Van hoc nuoc ngoai
    17,                                 // Sách 78: Ky nang song
    7,                                  // Sách 79: Cong nghe thong tin
    1,                                  // Sách 80: Tam ly hoc
    6,                                  // Sách 81: Toan hoc
    7,                                  // Sách 82: Cong nghe thong tin
    9,                                  // Sách 83: Nghe thuat
    15,                                 // Sách 84: Kinh te
    16,                                 // Sách 85: Quan tri kinh doanh
    14,                                 // Sách 86: Dia ly & Du lich
    2,                                  // Sách 87: Ton giao & Tam linh
    4,                                  // Sách 88: Ngon ngu hoc
    5,                                  // Sách 89: Khoa hoc tu nhien
    19,                                 // Sách 90: Sach thieu nhi
    0,                                  // Sách 91: Triet hoc
    8,                                  // Sách 92: Ky thuat & Co khi
    11,                                 // Sách 93: Van hoc viet nam
    12,                                 // Sách 94: Van hoc nuoc ngoai
    17,                                 // Sách 95: Ky nang song
    7,                                  // Sách 96: Cong nghe thong tin
    1,                                  // Sách 97: Tam ly hoc
    6,                                  // Sách 98: Toan hoc
    7,                                  // Sách 99: Cong nghe thong tin
    9                                   // Sách 100: Nghe thuat
};

float PRICES[MAX_BOOKS] = {             // Mảng lưu giá tiền sách (đơn vị: nghìn VNĐ)
    120,                                // Giá sách 1: Lập trình C++ - 120,000 VNĐ (Công nghệ thông tin)
    150,                                // Giá sách 2: Cấu trúc dữ liệu - 150,000 VNĐ (Công nghệ thông tin)
    130,                                // Giá sách 3: Python - 130,000 VNĐ (Công nghệ thông tin)
    180,                                // Giá sách 4: Thiết kế web - 180,000 VNĐ (Công nghệ thông tin)
    200,                                // Giá sách 5: Trí tuệ nhân tạo - 200,000 VNĐ (Công nghệ thông tin)
    100,                                // Giá sách 6: Khoa học xã hội VN - 100,000 VNĐ (Khoa học xã hội)
    170,                                // Giá sách 7: Văn học VN thế kỷ 20 - 170,000 VNĐ (Văn học Việt Nam)
    90,                                 // Giá sách 8: Kỹ năng giao tiếp - 90,000 VNĐ (Kỹ năng sống)
    140,                                // Giá sách 9: Sức khỏe và dinh dưỡng - 140,000 VNĐ (Y học & Sức khỏe)
    50,                                 // Giá sách 10: Doraemon tập 1 - 50,000 VNĐ (Sách thiếu nhi)
    160,                                // Giá sách 11: Lịch sử thế giới cổ đại - 160,000 VNĐ (Lịch sử)
    110,                                // Giá sách 12: Tâm lý học tội phạm - 110,000 VNĐ (Tâm lý học)
    200,                                // Giá sách 13: Toán cao cấp tập 1 - 200,000 VNĐ (Toán học)
    130,                                // Giá sách 14: Nhập môn CNTT - 130,000 VNĐ (Công nghệ thông tin)
    150,                                // Giá sách 15: Nghệ thuật hội họa - 150,000 VNĐ (Nghệ thuật)
    170,                                // Giá sách 16: Kinh tế vi mô - 170,000 VNĐ (Kinh tế)
    180,                                // Giá sách 17: Quản trị chiến lược - 180,000 VNĐ (Quản trị kinh doanh)
    120,                                // Giá sách 18: Địa lý Việt Nam - 120,000 VNĐ (Địa lý & Du lịch)
    140,                                // Giá sách 19: Tôn giáo và văn hóa - 140,000 VNĐ (Tôn giáo & Tâm linh)
    80,                                 // Giá sách 20: Tiếng Anh qua truyện - 80,000 VNĐ (Ngôn ngữ học)
    160,                                // Giá sách 21: Triết học phương Đông - 160,000 VNĐ (Triết học)
    190,                                // Giá sách 22: Kỹ thuật điện tử - 190,000 VNĐ (Kỹ thuật & Cơ khí)
    140,                                // Giá sách 23: Truyện ngắn Nam Cao - 140,000 VNĐ (Văn học Việt Nam)
    170,                                // Giá sách 24: Văn học Mỹ thế kỷ 19 - 170,000 VNĐ (Văn học nước ngoài)
    100,                                // Giá sách 25: 7 thói quen hiệu quả - 100,000 VNĐ (Kỹ năng sống)
    150,                                // Giá sách 26: Lập trình Java - 150,000 VNĐ (Công nghệ thông tin)
    90,                                 // Giá sách 27: Tư duy tích cực - 90,000 VNĐ (Kỹ năng sống)
    180,                                // Giá sách 28: Lịch sử VN thời Lý - 180,000 VNĐ (Lịch sử)
    120,                                // Giá sách 29: Tâm lý học hành vi - 120,000 VNĐ (Tâm lý học)
    200,                                // Giá sách 30: Toán rời rạc - 200,000 VNĐ (Toán học)
    140,                                // Giá sách 31: An ninh mạng - 140,000 VNĐ (Công nghệ thông tin)
    160,                                // Giá sách 32: Âm nhạc VN - 160,000 VNĐ (Nghệ thuật)
    180,                                // Giá sách 33: Kinh tế vi mô tập 2 - 180,000 VNĐ (Kinh tế)
    170,                                // Giá sách 34: Quản trị nhân sự - 170,000 VNĐ (Quản trị kinh doanh)
    110,                                // Giá sách 35: Du lịch Việt Nam - 110,000 VNĐ (Địa lý & Du lịch)
    130,                                // Giá sách 36: Phật giáo và đời sống - 130,000 VNĐ (Tôn giáo & Tâm linh)
    90,                                 // Giá sách 37: Tiếng Nhật căn bản - 90,000 VNĐ (Ngôn ngữ học)
    190,                                // Giá sách 38: Vật lý cơ bản - 190,000 VNĐ (Khoa học tự nhiên)
    60,                                 // Giá sách 39: Conan tập 1 - 60,000 VNĐ (Sách thiếu nhi)
    150,                                // Giá sách 40: Triết học phương Tây - 150,000 VNĐ (Triết học)
    200,                                // Giá sách 41: Kỹ thuật cơ khí - 200,000 VNĐ (Kỹ thuật & Cơ khí)
    140,                                // Giá sách 42: Thơ ca Việt Nam - 140,000 VNĐ (Văn học Việt Nam)
    160,                                // Giá sách 43: Tiểu thuyết Nga - 160,000 VNĐ (Văn học nước ngoài)
    100,                                // Giá sách 44: Tự tin bước tới - 100,000 VNĐ (Kỹ năng sống)
    130,                                // Giá sách 45: SQL cơ bản - 130,000 VNĐ (Công nghệ thông tin)
    110,                                // Giá sách 46: Tâm lý học giới tính - 110,000 VNĐ (Tâm lý học)
    180,                                // Giá sách 47: Đại số tuyến tính - 180,000 VNĐ (Toán học)
    150,                                // Giá sách 48: Blockchain - 150,000 VNĐ (Công nghệ thông tin)
    170,                                // Giá sách 49: Nghệ thuật điêu khắc - 170,000 VNĐ (Nghệ thuật)
    190,                                // Giá sách 50: Kinh tế chính trị - 190,000 VNĐ (Kinh tế)
    160,                                // Giá sách 51: Marketing 4.0 - 160,000 VNĐ (Quản trị kinh doanh)
    120,                                // Giá sách 52: Địa lý thế giới - 120,000 VNĐ (Địa lý & Du lịch)
    140,                                // Giá sách 53: Đạo giáo và văn hóa - 140,000 VNĐ (Tôn giáo & Tâm linh)
    90,                                 // Giá sách 54: Tiếng Hàn qua bài hát - 90,000 VNĐ (Ngôn ngữ học)
    200,                                // Giá sách 55: Hóa học hữu cơ - 200,000 VNĐ (Khoa học tự nhiên)
    60,                                 // Giá sách 56: One Piece tập 1 - 60,000 VNĐ (Sách thiếu nhi)
    150,                                // Giá sách 57: Triết học Marx-Lenin - 150,000 VNĐ (Triết học)
    190,                                // Giá sách 58: Kỹ thuật xây dựng - 190,000 VNĐ (Kỹ thuật & Cơ khí)
    140,                                // Giá sách 59: Truyện dài Nguyễn Du - 140,000 VNĐ (Văn học Việt Nam)
    160,                                // Giá sách 60: Văn học Anh thế kỷ 18 - 160,000 VNĐ (Văn học nước ngoài)
    100,                                // Giá sách 61: Quản lý thời gian - 100,000 VNĐ (Kỹ năng sống)
    130,                                // Giá sách 62: Lập trình Android - 130,000 VNĐ (Công nghệ thông tin)
    110,                                // Giá sách 63: Tâm lý học trẻ em - 110,000 VNĐ (Tâm lý học)
    180,                                // Giá sách 64: Xác suất thống kê - 180,000 VNĐ (Toán học)
    150,                                // Giá sách 65: Lập trình R - 150,000 VNĐ (Công nghệ thông tin)
    170,                                // Giá sách 66: Nghệ thuật điện ảnh - 170,000 VNĐ (Nghệ thuật)
    190,                                // Giá sách 67: Kinh tế quốc tế - 190,000 VNĐ (Kinh tế)
    160,                                // Giá sách 68: Quản trị rủi ro - 160,000 VNĐ (Quản trị kinh doanh)
    120,                                // Giá sách 69: Du lịch châu Âu - 120,000 VNĐ (Địa lý & Du lịch)
    140,                                // Giá sách 70: Thiên Chúa giáo - 140,000 VNĐ (Tôn giáo & Tâm linh)
    90,                                 // Giá sách 71: Tiếng Trung cơ bản - 90,000 VNĐ (Ngôn ngữ học)
    200,                                // Giá sách 72: Sinh học phân tử - 200,000 VNĐ (Khoa học tự nhiên)
    60,                                 // Giá sách 73: Naruto tập 1 - 60,000 VNĐ (Sách thiếu nhi)
    150,                                // Giá sách 74: Triết học nghệ thuật - 150,000 VNĐ (Triết học)
    190,                                // Giá sách 75: Kỹ thuật điện - 190,000 VNĐ (Kỹ thuật & Cơ khí)
    140,                                // Giá sách 76: Thơ Lục Vân Đ仙 - 140,000 VNĐ (Văn học Việt Nam)
    160,                                // Giá sách 77: Tiểu thuyết Pháp - 160,000 VNĐ (Văn học nước ngoài)
    100,                                // Giá sách 78: Tư duy phản biện - 100,000 VNĐ (Kỹ năng sống)
    130,                                // Giá sách 79: Lập trình PHP - 130,000 VNĐ (Công nghệ thông tin)
    110,                                // Giá sách 80: Tâm lý học xã hội - 110,000 VNĐ (Tâm lý học)
    180,                                // Giá sách 81: Hình học phẳng - 180,000 VNĐ (Toán học)
    150,                                // Giá sách 82: Công nghệ IoT - 150,000 VNĐ (Công nghệ thông tin)
    170,                                // Giá sách 83: Nghệ thuật truyền thông - 170,000 VNĐ (Nghệ thuật)
    190,                                // Giá sách 84: Tài chính doanh nghiệp - 190,000 VNĐ (Kinh tế)
    160,                                // Giá sách 85: Quản trị cung ứng - 160,000 VNĐ (Quản trị kinh doanh)
    120,                                // Giá sách 86: Địa lý kinh tế - 120,000 VNĐ (Địa lý & Du lịch)
    140,                                // Giá sách 87: Tâm linh phương Đông - 140,000 VNĐ (Tôn giáo & Tâm linh)
    90,                                 // Giá sách 88: Tiếng Đức qua phim - 90,000 VNĐ (Ngôn ngữ học)
    200,                                // Giá sách 89: Vật lý hạt nhân - 200,000 VNĐ (Khoa học tự nhiên)
    60,                                 // Giá sách 90: Dragon Ball tập 1 - 60,000 VNĐ (Sách thiếu nhi)
    150,                                // Giá sách 91: Triết học phân tích - 150,000 VNĐ (Triết học)
    190,                                // Giá sách 92: Kỹ thuật chế tạo - 190,000 VNĐ (Kỹ thuật & Cơ khí)
    140,                                // Giá sách 93: Tiểu thuyết VN - 140,000 VNĐ (Văn học Việt Nam)
    160,                                // Giá sách 94: Văn học Nhật Bản - 160,000 VNĐ (Văn học nước ngoài)
    100,                                // Giá sách 95: Kỹ năng lãnh đạo - 100,000 VNĐ (Kỹ năng sống)
    130,                                // Giá sách 96: Lập trình C# - 130,000 VNĐ (Công nghệ thông tin)
    110,                                // Giá sách 97: Tâm lý học nhân cách - 110,000 VNĐ (Tâm lý học)
    180,                                // Giá sách 98: Giải tích toán học - 180,000 VNĐ (Toán học)
    150,                                // Giá sách 99: Công nghệ máy tính - 150,000 VNĐ (Công nghệ thông tin)
    170                                 // Giá sách 100: Nghệ thuật thiết kế - 170,000 VNĐ (Nghệ thuật)
};

int STOCKS[MAX_BOOKS] = {               // Mảng lưu số lượng sách trong kho
    10,                                 // Số lượng sách 1: Lập trình C++
    7,                                  // Số lượng sách 2: Cấu trúc dữ liệu
    12,                                 // Số lượng sách 3: Python
    5,                                  // Số lượng sách 4: Thiết kế web
    8,                                  // Số lượng sách 5: Trí tuệ nhân tạo
    15,                                 // Số lượng sách 6: Khoa học xã hội VN
    6,                                  // Số lượng sách 7: Văn học VN thế kỷ 20
    20,                                 // Số lượng sách 8: Kỹ năng giao tiếp
    9,                                  // Số lượng sách 9: Sức khỏe và dinh dưỡng
    25,                                 // Số lượng sách 10: Doraemon tập 1
    4,                                  // Số lượng sách 11: Lịch sử thế giới cổ đại
    11,                                 // Số lượng sách 12: Tâm lý học tội phạm
    13,                                 // Số lượng sách 13: Toán cao cấp tập 1
    7,                                  // Số lượng sách 14: Nhập môn CNTT
    10,                                 // Số lượng sách 15: Nghệ thuật hội họa
    8,                                  // Số lượng sách 16: Kinh tế vi mô
    6,                                  // Số lượng sách 17: Quản trị chiến lược
    14,                                 // Số lượng sách 18: Địa lý Việt Nam
    9,                                  // Số lượng sách 19: Tôn giáo và văn hóa
    12,                                 // Số lượng sách 20: Tiếng Anh qua truyện
    5,                                  // Số lượng sách 21: Triết học phương Đông
    11,                                 // Số lượng sách 22: Kỹ thuật điện tử
    8,                                  // Số lượng sách 23: Truyện ngắn Nam Cao
    7,                                  // Số lượng sách 24: Văn học Mỹ thế kỷ 19
    15,                                 // Số lượng sách 25: 7 thói quen hiệu quả
    9,                                  // Số lượng sách 26: Lập trình Java
    18,                                 // Số lượng sách 27: Tư duy tích cực
    6,                                  // Số lượng sách 28: Lịch sử VN thời Lý
    10,                                 // Số lượng sách 29: Tâm lý học hành vi
    5,                                  // Số lượng sách 30: Toán rời rạc
    12,                                 // Số lượng sách 31: An ninh mạng
    8,                                  // Số lượng sách 32: Âm nhạc VN
    7,                                  // Số lượng sách 33: Kinh tế vi mô tập 2
    9,                                  // Số lượng sách 34: Quản trị nhân sự
    14,                                 // Số lượng sách 35: Du lịch Việt Nam
    10,                                 // Số lượng sách 36: Phật giáo và đời sống
    15,                                 // Số lượng sách 37: Tiếng Nhật căn bản
    6,                                  // Số lượng sách 38: Vật lý cơ bản
    20,                                 // Số lượng sách 39: Conan tập 1
    8,                                  // Số lượng sách 40: Triết học phương Tây
    5,                                  // Số lượng sách 41: Kỹ thuật cơ khí
    11,                                 // Số lượng sách 42: Thơ ca Việt Nam
    7,                                  // Số lượng sách 43: Tiểu thuyết Nga
    13,                                 // Số lượng sách 44: Tự tin bước tới
    9,                                  // Số lượng sách 45: SQL cơ bản
    10,                                 // Số lượng sách 46: Tâm lý học giới tính
    6,                                  // Số lượng sách 47: Đại số tuyến tính
    12,                                 // Số lượng sách 48: Blockchain
    8,                                  // Số lượng sách 49: Nghệ thuật điêu khắc
    7,                                  // Số lượng sách 50: Kinh tế chính trị
    9,                                  // Số lượng sách 51: Marketing 4.0
    14,                                 // Số lượng sách 52: Địa lý thế giới
    10,                                 // Số lượng sách 53: Đạo giáo và văn hóa
    15,                                 // Số lượng sách 54: Tiếng Hàn qua bài hát
    6,                                  // Số lượng sách 55: Hóa học hữu cơ
    20,                                 // Số lượng sách 56: One Piece tập 1
    8,                                  // Số lượng sách 57: Triết học Marx-Lenin
    5,                                  // Số lượng sách 58: Kỹ thuật xây dựng
    11,                                 // Số lượng sách 59: Truyện dài Nguyễn Du
    7,                                  // Số lượng sách 60: Văn học Anh thế kỷ 18
    13,                                 // Số lượng sách 61: Quản lý thời gian
    9,                                  // Số lượng sách 62: Lập trình Android
    10,                                 // Số lượng sách 63: Tâm lý học trẻ em
    6,                                  // Số lượng sách 64: Xác suất thống kê
    12,                                 // Số lượng sách 65: Lập trình R
    8,                                  // Số lượng sách 66: Nghệ thuật điện ảnh
    7,                                  // Số lượng sách 67: Kinh tế quốc tế
    9,                                  // Số lượng sách 68: Quản trị rủi ro
    14,                                 // Số lượng sách 69: Du lịch châu Âu
    10,                                 // Số lượng sách 70: Thiên Chúa giáo
    15,                                 // Số lượng sách 71: Tiếng Trung cơ bản
    6,                                  // Số lượng sách 72: Sinh học phân tử
    20,                                 // Số lượng sách 73: Naruto tập 1
    8,                                  // Số lượng sách 74: Triết học nghệ thuật
    5,                                  // Số lượng sách 75: Kỹ thuật điện
    11,                                 // Số lượng sách 76: Thơ Lục Vân Đ仙
    7,                                  // Số lượng sách 77: Tiểu thuyết Pháp
    13,                                 // Số lượng sách 78: Tư duy phản biện
    9,                                  // Số lượng sách 79: Lập trình PHP
    10,                                 // Số lượng sách 80: Tâm lý học xã hội
    6,                                  // Số lượng sách 81: Hình học phẳng
    12,                                 // Số lượng sách 82: Công nghệ IoT
    8,                                  // Số lượng sách 83: Nghệ thuật truyền thông
    7,                                  // Số lượng sách 84: Tài chính doanh nghiệp
    9,                                  // Số lượng sách 85: Quản trị cung ứng
    14,                                 // Số lượng sách 86: Địa lý kinh tế
    10,                                 // Số lượng sách 87: Tâm linh phương Đông
    15,                                 // Số lượng sách 88: Tiếng Đức qua phim
    6,                                  // Số lượng sách 89: Vật lý hạt nhân
    20,                                 // Số lượng sách 90: Dragon Ball tập 1
    8,                                  // Số lượng sách 91: Triết học phân tích
    5,                                  // Số lượng sách 92: Kỹ thuật chế tạo
    11,                                 // Số lượng sách 93: Tiểu thuyết VN
    7,                                  // Số lượng sách 94: Văn học Nhật Bản
    13,                                 // Số lượng sách 95: Kỹ năng lãnh đạo
    9,                                  // Số lượng sách 96: Lập trình C#
    10,                                 // Số lượng sách 97: Tâm lý học nhân cách
    6,                                  // Số lượng sách 98: Giải tích toán học
    12,                                 // Số lượng sách 99: Công nghệ máy tính
    8                                   // Số lượng sách 100: Nghệ thuật thiết kế
};

int NUMBER_OF_BOOKS = 100;                // Số lượng sách hiện có trong hệ thống (dựa trên ISBN)

// KHỞI TẠO MẢNG LƯU THÔNG TIN PHIẾU MƯỢN
int BORROW_IDS[MAX_BORROW_TICKET] = { // Mảng 2D lưu ID độc giả trong phiếu mượn
    0,                            // ID độc giả phiếu 1
    1,                            // ID độc giả phiếu 2
    0                             // ID độc giả phiếu 3
};

char BORROW_DATE[MAX_BORROW_TICKET][MAX_DATE] = { // Mảng 2D lưu ngày mượn sách (DD/MM/YYYY)
    "27/03/2025",                       // Ngày mượn phiếu 1
    "26/03/2025",                       // Ngày mượn phiếu 2
    "04/04/2025"                        // Ngày mượn phiếu 3
};

int BORROW_START[MAX_BORROW_TICKET] = { // Mảng lưu chỉ số bắt đầu của sách mượn trong BORROW_ISBN_BOOKS
    0,                                  // Phiếu 1: Bắt đầu từ sách 0
    2,                                  // Phiếu 2: Bắt đầu từ sách 2
    5                                   // Phiếu 3: Bắt đầu từ sách 5
};

int BORROW_BOOKS[MAX_BORROW_TICKET] = { // Mảng lưu ISBN sách mượn (danh sách dựa vào index của sách đã lưu trong ISBN sách)
    0,                // Sách mượn 0 (phiếu 1)
    1,                // Sách mượn 1 (phiếu 1)
    2,                // Sách mượn 2 (phiếu 2)
    3,                // Sách mượn 3 (phiếu 2)
    4,                // Sách mượn 4 (phiếu 2)
    2,                // Sách mượn 5 (phiếu 3)
    4                 // Sách mượn 6 (phiếu 3)
};

int NUMBER_OF_BORROW_TICKETS = 3;       // Số lượng phiếu mượn hiện có trong hệ thống

int NUMBER_OF_BORROW_BOOK = 7;            // Số lượng sách (ISBN) đang được mượn trong thư viện

int BLACK_LIST[MAX_READERS] = {0};       // Mảng lưu danh sách các đọc giả thường xuyên mất sách