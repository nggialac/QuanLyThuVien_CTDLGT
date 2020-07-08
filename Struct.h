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

#include <iostream>
#include "mylib.h"

#define MAX_LIST_DAUSACH 10000

using namespace std;

struct NTN {
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
};

struct DMSach {
	string maSach;
	int trangThaiSach = 0;
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
	unsigned int namXB = 0;
	unsigned int soTrang;
	NodeDMSach *pDMS = NULL;
};
struct ListDauSach {
	int n = 0;
	DauSach *nodesDS[MAX_LIST_DAUSACH];
};
typedef struct ListDauSach List_DauSach;
//*************
struct MuonTra {
	string maSach;
	int trangThai = 0;
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
	int trangThaiThe = 0;
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
	int soSachMuon = 0;
};

