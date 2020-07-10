/*Thu vien:
	-Dau sach: DSTT 1 mang con tro (ISBN C6, Ten sach, So trang, Tac gia, Nam xuat ban, The loai, Con tro dms):
		+con tro tro den cac sach thuoc dau sach tuong ung
	-Danh muc sach: DSLK don (Ma sach, Trang thai, Vi tri)
		+Moi sach co 1 ma sach duy nhat
		+Trang thai sach:
			0: Cho muon duoc
			1: Da co doc gia muon
			2: Sach da thanh ly
	-Danh sach the doc gia: Cay NPTK (Ma the(so nguyen ngau nhien tu dong), Ho, Ten, Phai, Trang thai cua the, Con tro)
		+Con tro tro den danh sach cac cuon sach da va dang muon
	-Danh sach muon tra: DSLK kep (Ma sach, Ngay muon, Ngay tra, trang thai)
		+0: Sach dang muon (chua tra)
		+1: Da tra
		+2: Lam mat sach
*/
#pragma once
#include <iostream>
#include "mylib.h"

#define MAX_LIST_DAUSACH 10000

//constant
#define MAX_DAUSACH  100

// Cac HotKey
// Quay con tro ve 1 don vi char
#define BACKSPACE 8
// OK
#define ENTER 13
// thoat truc tiep va ve Menu chinh
#define ESC  27
// Di len
#define KEY_UP 72
// Di xuong
#define KEY_DOWN 80
// Di qua trai
#define KEY_LEFT 75
// Di qua phai 
#define KEY_RIGHT 77
// Luu
#define KEY_F2 60
// Xoa
#define KEY_F3 61
// Hieu chinh
#define KEY_F4 62
// Save
#define KEY_F10 68
// Cuon page xuong duoi
#define PAGE_DOWN 81
// Cuon page len tren
#define PAGE_UP 73
// Khoang trang
#define SPACE  32
//  Tim kiem
#define KEY_F9 67

// Tro ve
#define TAB 9

// thay unsigned int thanh uint
typedef unsigned int uint;

// ma mau
#define AQUA 3
#define PURPLE 5
#define LIGHT_AQUA 11
#define LIGHT_YELLOW 14
#define LIGHT_GREEN 10 
#define BLACK 0
#define WHITE 7
#define GREEN 2
#define BRIGHT_WHITE 15
#define BLUE 1
#define LIGHT_RED 12


// size man hinh
#define GWIDTH 1100
#define GHEIGHT 650

// vi tri in ten, mssv, lop
#define xTen 53
#define yTen 22

// vitri khung loading
#define xLoading 15
#define yLoading 33


// vi tri menu chinh
#define xMainMenu 10
#define yMainMenu 12

// vi tri dong chu chay
#define xChuChay 45
#define yChuChay 30

//toa do max
#define xMax 132
#define yMax 35

//goc toa do
#define xOrdinal 0
#define yOrdinal 0

// Max Ma doc gia
#define Max_MADG 99999
// Min Ma doc Gia
#define Min_MADG 0

// toa do x cua SubMainMenus
#define xSubMainMenus1 40
#define xSubMainMenus2 52
#define xSubMainMenus3 52


// toa do y cua  bang hien thi
#define yDisplay 2

#define yDisplayMT 18

#define yDisplayTop10 5

// toa do t cua cac hoat key F2, F3, F4, F10
#define yHotkey 35

// vi tri Tieu de 
#define xTitle 97
#define yTitle 5

// chieu dai dai nhat cua ten
#define MAX_TEN 7

// chieu dai dai nhat cua ho 
#define MAX_HO 16

//chieu dai dai nhat cua ten sach
#define MAX_TENSACH 24

// chieu dai dai nhat cua ten tac gia
#define MAX_TENTG 17

// chieu dai dai nhat cua ISBN
#define MAX_ISBN 6

// chieu dai dai nhat cua the loai sach
#define MAX_THELOAISACH 11

// the de nhap trang thai va nhap phai
#define NHAP_TRANG_THAI 1
#define NHAP_PHAI 0

// vi tri dong chu thong bao
#define X_NOTIFY 74
#define Y_NOTIFY 19

// vi tri subMainMenu4 

#define xINDOCGIA 80
#define yINDOCGIA 20


// so luong dong xuat hien trong 1 bang thong tin
#define NUMBER_LINES  29

using namespace std;

struct Ntn {
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
};
typedef struct Ntn NTN;
//*************
struct DMSach {
	string maSach;
	int trangThaiSach;
	string viTri;
};
struct NodeDMSach {
	DMSach info;
	NodeDMSach *next;
};
typedef struct NodeDMSach Node_DMS;
//*************
struct DauSach {
	char ISBN[7];
	string tenSach;
	string tacGia;
	string theLoai;
	unsigned int namXB;
	unsigned int soTrang;
	NodeDMSach *pDMS = NULL;
};
typedef struct DauSach dauSach;
typedef struct DauSach *pDauSach;
struct ListDauSach {
	int n;
	DauSach *nodesDS[MAX_LIST_DAUSACH];
};
typedef struct ListDauSach List_DauSach;
//*************
struct MuonTra {
	string maSach;
	int trangThai;
	NTN ngayMuon;
	NTN ngayTra;
};
struct NodeMuonTra {
	MuonTra info;
	NodeMuonTra *left, *right;
};
typedef struct NodeMuonTra Node_MT;
//*************
struct TheDocGia {
	string maThe;
	string ho;
	string ten;
	bool phai;
	int trangThaiThe;
	Node_MT *pMT = NULL;
};
struct NodeTheDocGia {
	int key;
	TheDocGia info;
	NodeTheDocGia *left, *right;
};
typedef struct NodeTheDocGia Tree_TDG;
//*************
struct TopBook {
	string tenSach;
	int soSachMuon;
};

