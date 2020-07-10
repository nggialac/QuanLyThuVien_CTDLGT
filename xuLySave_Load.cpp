
#include "xuLySave_Load.h"

void Introduce() {
	system("color 3E");//Background xanh
	ShowCur(false);
	string a;

	// lay tu file o che do chi doc
	ifstream inFile("introduce.txt", ios::in);
	if (inFile.good()) { // Kiem tra xem file co ket noi duoc hay khong?
		while (!inFile.eof()) {
			getline(inFile, a);
			SetColor(LIGHT_AQUA); // Mau Load file
			Sleep(100);
			cout << a << endl;
		}
	} else { //Tra ve loi
		cout << "Lien ket voi File introduce khong thanh cong! " << "\n";
	}

	SetColor(LIGHT_GREEN);
	gotoxy(xTen, yTen);
	cout << "HOTEN : SINHVIEN";
	gotoxy(xTen, yTen + 1);
	cout << "MSSV  : N17";
	gotoxy(xTen, yTen + 2);
	cout << "LOP   : D17";
	//CayLoading(LIGHT_YELLOW);
	ShowCur(false);

	// nhan enter de thoat vong lap
	gotoxy(45, 35);
	SetBGColor(BLUE);
	cout << "Please ! Press ENTER to continue. ";
	//normalBGColor();
	SetColor(LIGHT_YELLOW);
	SetBGColor(AQUA);

	while (!_kbhit()) {
		gotoxy(35, 30);
		SetColor(1 + rand() % 15);
		Sleep(100);
		cout << "HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO TP HO CHI MINH";
	}
	SetBGColor(AQUA);
	SetColor(AQUA);
	cin.ignore();
	return;
}

void ManHinhChinh() {
	system("color 3E");
	clrscr();
	normalTextColor();
	ShowCur(false);
	VeKhungMenu();

	normalBGColor();
	MainMenu(keyMainMenu, 5);
	normalBGColor();

	string text;
	int y = 0;
	// lay tu file va chi doc
	ifstream inFile("QuanLyThuVien.txt", ios::in);
	// Kiem tra xem file co ket noi duoc hay khong?
	if (inFile.good()) {
		while (!inFile.eof()) {
			getline(inFile, text);
			SetColor(11);
			Sleep(100);
			gotoxy(25, y++);
			cout << text << endl;
		}
	} else { //Tra ve loi
		cout << "Lien ket voi File QuanlyThuVien khong thanh cong! " << "\n";
	}
	normalBGColor();
	SetBGColor(BLACK);
	// set khung
	gotoxy(xOrdinal + 44, yOrdinal + 34);
	cout << char(201) << setw(40) << setfill(char(205)) << char(187);

	gotoxy(xOrdinal + 44, yOrdinal + 35);
	cout << char(186) << setw(40) << setfill(' ') << char(186);

	gotoxy(xOrdinal + 44, yOrdinal + 36);
	cout << char(200) << setw(40) << setfill(char(205)) << char(188);

	chuChay(dongChuChay, xOrdinal + 45, yOrdinal + 35);
	return;
}

void Save_DS(List_DauSach listDS) {
	fstream outFile;
	outFile.open("DauSach.txt", ios::out );
	if (outFile.is_open()) {
		outFile << listDS.n + 1 << endl;
		for (int i = 0; i <= listDS.n; i++) {
			outFile << listDS.nodesDS[i]->tenSach << endl;
			outFile << listDS.nodesDS[i]->ISBN << endl;
			outFile << listDS.nodesDS[i]->tacGia << endl;
			outFile << listDS.nodesDS[i]->theLoai << endl;
			outFile << listDS.nodesDS[i]->soTrang << endl;
			outFile << listDS.nodesDS[i]->namXB << endl;
			//outFile << listDS.nodesDS[i]->pDMS.n << endl;
			for (Node_DMS* p  = listDS.nodesDS[i]->pDMS ; p != NULL ;  p = p->next ) {
				outFile << p->info.maSach << endl;
				outFile << p->info.trangThaiSach << endl;
				outFile << p->info.viTri << endl;
			}
		}
	} else {
		cout << "KET NOI VOI FILE DauSach THAT BAI! ";
	}
	outFile.close();
}

void Load_DS(List_DauSach &listDS) {
	fstream inFile;
	dauSach info;
	inFile.open("DauSach.txt", ios::in);
	pDauSach pDS;
	DMSach dms;
	int soDauSach, soSach;
	if (inFile.is_open()) {
		string temp;
		inFile >> soDauSach;
		getline(inFile, temp);
		for (int i = 0; i < soDauSach; i++) {
			pDS = new dauSach;
			if (pDS == NULL) continue;
			// load thong tin vao bien tam.
			getline(inFile, info.tenSach);
			//getline(inFile, info.ISBN); DOC KIEU STRING, CHAR bi loi 
			getline(inFile, info.tacGia);
			getline(inFile, info.theLoai);
			inFile >> info.soTrang;
			inFile >> info.namXB;
			// load thong tin vao dau sach
			*(pDS) = info;
			inFile >> soSach;
			getline(inFile, temp);
//			initList_DMS(pDS->dms);
//			for (int j = 0; j < sosach; j++) {
//				getline(inFile, dms.maSach);
//				inFile >> dms.ttSach;
//				getline(inFile, temp);
//				getline(inFile, dms.viTri);
//				AddTailList_DMS(pDS->dms, dms);
//			}
			themDauSach(listDS, pDS);
		}
	} else {
		cout << "KET NOI VOI FILE DocGia THAT BAI! ";
	}

	inFile.close();
}



int main() {
	resizeConsole(1100,700);
	//Introduce();
	//ManHinhChinh();
	return 0;
}
