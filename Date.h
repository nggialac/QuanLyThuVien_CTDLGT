#include "Struct.h"
#include <time.h>
#include <iostream>
using namespace std;

#define NAM_MIN 1900
#define NAM_MAX 2200

bool isNamNhuan(int year);
bool isNgayDung(NTN d); //Kiem tra Input
void xuatNgayThang(NTN dt, int x, int y);
void layNgayGioHT(NTN &d); //Return ngay hien tai
int layNamHT();
int tinhNgay(NTN dt);
int khoangCachNgay(NTN nt1); //Tinh khoang cach 2 ngay
int soSanhNgay(NTN nt1, NTN nt2);
