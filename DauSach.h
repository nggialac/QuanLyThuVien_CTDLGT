#pragma once
#include "Struct.h"

//Dau Sach
bool checkEmpty_DauSach(List_DauSach listDS);
bool checkFull_DauSach(List_DauSach listDS);
bool themDauSach(List_DauSach &listDS,  pDauSach &pDS);
void xoaDauSach_ViTri(List_DauSach &listDS, int viTri);
void xoaDauSach_ISBN(List_DauSach &listDS, pDauSach pDS);
bool searchDauSach_ISBN(List_DauSach listDS, string ISBN);
pDauSach layDauSach_Ten(List_DauSach listDS, string tenSach);
List_DauSach layDauSach_TheLoai(List_DauSach &listDS, string theLoai);

//
string getString(string a);
void swap_DS(pDauSach ds1, pDauSach ds2);
void swap_ListDS(List_DauSach &a, List_DauSach &b);
void quickSortDS(List_DauSach &listDS, int left, int right);
void testDS(List_DauSach &listDS, string theLoai);
void selectionSort_DS(List_DauSach &listDS);

