#pragma once
#include <iomanip>
#include "Date.h"

void xoa(char* s, int vitrixoa) {
	int n = strlen(s);
	for (int i = vitrixoa; i < n; i++)
		s[i] = s[i + 1];
	s[n - 1] = '\0';
}

char* ChuanHoaChar(char* result) {
	for (int i = 0; i < strlen(result); i++)
		if (result[i] == ' '&& result[i + 1] == ' ') {
			xoa(result, i);
			i--;
		}
	if (result[0] == ' ')
		xoa(result, 0);
	if (result[strlen(result) - 1] == ' ')
		xoa(result, strlen(result) - 1);
	return result;
}

char* toCharArray(string str) {
	char* c = new char(str.size() + 1);
	for (int i = 0; i < str.size() + 1; i++)
		c[i] = str[i];
	return c;
}
//CHARACTER

string ChuanHoaString(string result) {
	for (size_t i = 1; i < result.length(); i++) {
		if (result[0] == ' ') {
			result.erase(0, 1);
			i--;
		} else if (result[i - 1] == ' ' && result[i] == ' ') {
			result.erase(i - 1, 1);
			i--;
		} else if (result[result.length() - 1] == ' ') {
			result.erase(result.length() - 1, 1);
		}
	}
	return result;
}

void Nhap(unsigned int &result, int choice, int &ordinal, bool &isSave, bool &isEscape) {
	//cout << result;
	int count = 0;

	// giu lai vi tri ban dau
	int x = wherex() - 1, y = wherey() - 1;

	if (choice == 1 && result == 3) {
		result = 1;
		gotoxy(x, y);
		cout << result << ":  HOAT DONG ";
	}
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if ((kb_hit == 48 || kb_hit == 49) && count < 1) {
				count++;
				result = kb_hit - 48;
				if (choice == 0) {
					// xoa dong thong bao
					gotoxy(X_NOTIFY + 15, Y_NOTIFY);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);
					(result == 0) ? cout << result << ":  NAM" : cout << result << ":  NU    ";
				} else if (choice == 1) {
					// xoa dong thong bao
					gotoxy(X_NOTIFY + 15, Y_NOTIFY);
					cout << setw(42) << setfill(' ') << " ";
					gotoxy(x, y);
					(result == 0) ? cout << result << ":  KHOA      " : cout << result << ":  HOAT DONG ";
				}
			} else if (kb_hit == 224) {
				kb_hit = _getch();
				// cho nay xay ra hai truong hop
				if (choice == 0) {
					if (kb_hit == KEY_UP) {
						ordinal = 1;
						return;
					} else {
						ordinal = 3;
						return;
					}
				} else if (choice == 1) {
					if (kb_hit == KEY_UP) {
						ordinal = 2;
						return;
					} else {
						ordinal = 0;
						return;
					}
				}
			} else if (kb_hit == ENTER) {
				if (choice == 0) {
					ordinal = 3;
					return;
				} else if (choice == 1) {
					ordinal = 0;
					return;
				}
			} else if (kb_hit == BACKSPACE && count > 0) {
				gotoxy(x, y);
				result = 3;
				cout << " " << setw(15) << setfill(' ') << " ";
				count--;
				// chuyen ve vi tri ban dau.
				gotoxy(x, y);
			} else if (kb_hit == 0) {
				kb_hit = _getch();
				if (kb_hit == KEY_F10) {
					isSave = true;
					return;
				}
			} else if (kb_hit == ESC) {
				isEscape = true;
				return;
			} else {
				gotoxy(X_NOTIFY + 15, Y_NOTIFY);
				SetColor(BLUE);
				cout << "BAN HAY NHAP 0 HOAC 1,Backspace DE XOA !!!";
				//normalBGColor();
				SetColor(LIGHT_YELLOW);
				gotoxy(x, y);
			}
		}
	}
}


int InputMaThe(int &maThe) {
	hienConTro();
	int temp = maThe;
	int count = 0;

	// kiem tra maThe da duoc nhap chua
	while (temp != 0) {
		count++;
		temp /= 10;
	}
	if (count) {
		cout << maThe;
	}
	while (true) {
		while (_kbhit()) {
			int kb_hit = _getch();
			if ((kb_hit >= 48 && kb_hit <= 57) && (count <= 9 && count >= 0)) {
				int f = kb_hit - 48;
				cout << f;
				maThe = maThe * 10 + (f);
				count++;
			} else if (kb_hit == ENTER) {
				return 1;
			} else if (kb_hit == BACKSPACE && count > 0) {
				cout << "\b" << " " << "\b";
				count--;
				maThe /= 10;
			} else if (kb_hit == ESC) {
				return  -1;
			}
		}
	}
}

//int InputNgayThang(NTN &date, int x, int y) {
//	//hienConTro();
//	int flag = 2;
//	layNgayGioHT(date);
//	NTN tempDate;
//	tempDate.ngay = date.ngay;
//	tempDate.thang = date.thang;
//	tempDate.nam = date.nam;
//
//	//gotoxy(123, 37);
//	gotoxy(x, y);
//	cout << date.ngay << " /" << date.thang << " /" << date.nam;
//
//	while (true) {
//		while (_kbhit()) {
//			int kb_hit = _getch();
//			if (kb_hit >= 48 && kb_hit <= 57) {
//				if (flag == 0) {
//					int f = kb_hit - 48;
//					tempDate.ngay = tempDate.ngay * 10 + (f);
//					if (tempDate.ngay > 31) {
//						tempDate.ngay /= 10;
//						continue;
//					}
//					gotoxy(x, y);
//					cout << tempDate.ngay;
//				} else if (flag == 1) {
//
//					int f = kb_hit - 48;
//					tempDate.thang = tempDate.thang * 10 + (f);
//					if (tempDate.thang > 12) {
//						tempDate.thang /= 10;
//						continue;
//					}
//					gotoxy(x + 4, y);
//					cout << tempDate.thang;
//				} else if (flag == 2) {
//
//					int f = kb_hit - 48;
//					tempDate.nam = tempDate.nam * 10 + (f);
//					if (tempDate.nam > 9999) {
//						tempDate.nam /= 10;
//						continue;
//					}
//					gotoxy(x + 7, y);
//					cout << tempDate.nam;
//				}
//			}
//			else if (kb_hit == ENTER) {
//				if (flag == 0) {
//
//					gotoxy(x + 4, y);
//					cout << tempDate.thang;
//					flag = 1;
//				} else if (flag == 1) {
//
//					gotoxy(x + 7, y);
//					cout << tempDate.nam;
//					flag = 2;
//				} else if (flag == 2) {
//
//					gotoxy(x, y);
//					cout << tempDate.ngay;
//					flag = 0;
//				}
//			} else if (kb_hit == BACKSPACE && tempDate.ngay > 0 && tempDate.thang > 0 && tempDate.nam > 0) {
//				cout << "\b" << " " << "\b";
//				if (flag == 0) {
//					tempDate.ngay /= 10;
//				}
//
//				else if (flag == 1) {
//					tempDate.thang /= 10;
//				} else if (flag == 2) {
//					tempDate.nam /= 10;
//				}
//			} else if (kb_hit == 0) {
//				kb_hit = _getch();
//				if (kb_hit == KEY_F10) {
//
//					flag = isNgayDung(tempDate);
//					if (flag == 3) {
//						// xoa nhung noi dung khong duoc su dung
//						gotoxy(x - 19, y - 2);
//						cout << "                                                  ";
//						gotoxy(x, y);
//						cout << "                     ";
//						gotoxy(x - 3, y + 2);
//						cout << "                     ";
//
//						// kiem tra ngay nhap lon hon ngay hien tai
//						if (khoangCachNgay(tempDate) < 0) {
//							return 1;
//						} else {
//							date = tempDate;
//							return 2;
//						}
//					} else if (flag == 0) {
//						gotoxy(x - 3, y + 2);
//						cout << "Sai ngay. Nhap lai!";
//						gotoxy(x, y);
//						cout << tempDate.ngay;
//						continue;
//					} else if (flag == 1) {
//						gotoxy(x - 3, y + 2);
//						cout << "Sai thang. Nhap lai!";
//						gotoxy(x + 4, y);
//						cout << tempDate.thang;
//						continue;
//					} else if (flag == 2) {
//						gotoxy(x - 3, y + 2);
//						cout << "Sai nam. Nhap lai!";
//						gotoxy(x + 7, y);
//						cout << tempDate.nam;
//						continue;
//					}
//
//				}
//			} else if (kb_hit == ESC) {
//				// xoa nhung noi dung khong duoc su dung
//				gotoxy(x - 19, y - 2);
//				cout << "                                                  ";
//				gotoxy(x, y);
//				cout << "                     ";
//				gotoxy(x - 3, y + 2);
//				cout << "                     ";
//				return -1;
//			}
//		}
//	}
//}

int main() {
	string m = "             h e          llo w    orld  %";
	string n = ChuanHoaString(m);
	cout<<n;
//	int maThe = 2;
//	InputMaThe(maThe);
//	InputNgayThang(d,10,10);
	return 0;
}

