#include "DauSach.h"

bool checkEmpty_DauSach(List_DauSach listDS) {
	return (listDS.n == -1 ? 1:0);
}

bool checkFull_DauSach(List_DauSach listDS) {
	return (listDS.n == MAX_LIST_DAUSACH ? 1:0);
}

bool themDauSach(List_DauSach &listDS,  pDauSach &pDS) {
	if (checkFull_DauSach(listDS)) {
		return 0;
	}
	listDS.nodesDS[++listDS.n] = pDS;
	return 1;
}

void xoaDauSach_ViTri(List_DauSach &listDS, int viTri) {
	if (viTri > listDS.n  || checkEmpty_DauSach(listDS)  ||  checkFull_DauSach(listDS) || viTri < 0) {
		return;
	}
	// xoa vi tri cuoi mang
	if (viTri == listDS.n) {
		delete listDS.nodesDS[listDS.n];
		// tranh tinh trang con tro bi treo...
		listDS.nodesDS[listDS.n--] = NULL;
		return;
	}
	// ***NOTE
	delete listDS.nodesDS[viTri];
	for (int temp = viTri + 1; temp <= listDS.n; temp++) {
		listDS.nodesDS[temp - 1] = listDS.nodesDS[temp];
	}
	delete listDS.nodesDS[listDS.n--];
	// tranh tinh trang con tro bi treo...
	listDS.nodesDS[listDS.n--] = NULL;
	return;
}

void xoaDauSach_ISBN(List_DauSach &listDS, pDauSach pDS) {
	for (int i = 0; i < listDS.n; i++) {
		if (listDS.nodesDS[i]->ISBN == pDS->ISBN) { //(string)listDS.nodesDS[i]->ISBN == (string)pDS->ISBN
			if (i == listDS.n - 1) {
				//delete listDS.nodesDS[listDS.n - 1];
				// tranh tinh trang con tro bi treo...
				listDS.nodesDS[--listDS.n] = NULL;
				return;
			}
			for (int temp = i + 1; temp <= listDS.n; temp++) {
				listDS.nodesDS[temp - 1] = listDS.nodesDS[temp];
			}
			//delete lds.nodesDauSach[--lds.n];
			listDS.nodesDS[--listDS.n] = NULL;
		}
	}
}

bool searchDauSach_ISBN(List_DauSach listDS, string ISBN) {
	for (int i = 0; i < listDS.n; i++) {
		if (listDS.nodesDS[i]->ISBN == ISBN)
			return true;
	}
	return false;
}

pDauSach layDauSach_Ten(List_DauSach listDS, string tenSach) {
	pDauSach temp = NULL;
	for (int i = 0; i <= listDS.n; i++) {
		temp = listDS.nodesDS[i];
		if (temp->tenSach == tenSach)
			return temp;
	}
	return NULL;
}

List_DauSach layDauSach_TheLoai(List_DauSach &listDS, string theLoai) {
	List_DauSach listDSTemp;
	listDSTemp.n = 0;
	for (int i = 0; i < listDS.n; i++) {
		if (listDS.nodesDS[i]->theLoai == theLoai) {
			listDSTemp.nodesDS[listDSTemp.n] = listDS.nodesDS[i];
			listDSTemp.n++;
		}
	}
	return listDSTemp;
}

string getString(string a) {
	for (int i = 0; i < (int)a.length(); i++) {
		if (a[i] == ' ') {
			a.erase(i, 1);
			i--;
		}
	}
	return a;
}

//Sap xep Dau Sach
//COI LAI?
void swap_DS(pDauSach ds1, pDauSach ds2) {
	DauSach temp = *ds1;
	*ds1 = *ds2;
	*ds2 = temp;
}

void swap_ListDS(List_DauSach &a, List_DauSach &b) {
	List_DauSach temp;
	temp = a;
	a = b;
	b = temp;
}

void quickSortDS(List_DauSach &listDS, int left, int right) {
	dauSach key = *(listDS.nodesDS[(left + right) / 2]);
	dauSach tempDS;
	int i = left, j = right;
	do {
		while ((string)listDS.nodesDS[i]->tenSach < (string)key.tenSach)
			i++;
		while ((string)listDS.nodesDS[j]->tenSach > (string)key.tenSach)
			j--;
		if (i <= j) {
			if (i < j) {
				swap_DS(listDS.nodesDS[i], listDS.nodesDS[j]);
			}
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) quickSortDS(listDS, left, j);
	if (right > i) quickSortDS(listDS, i, right);
}
void testDS(List_DauSach &listDS, string theLoai) {
	List_DauSach listDSTemp = layDauSach_TheLoai(listDS, theLoai);
	quickSortDS(listDSTemp, 0, listDSTemp.n - 1);
}
//COI LAI?
void selectionSort_DS(List_DauSach &listDS) {
	int i, j, min_idx;
	string temp1, temp2;
	// One by one move boundary of unsorted subarray
	for (i = 0; i <=  listDS.n - 1; i++) {
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j <= listDS.n; j++) {
			temp1 = getString(listDS.nodesDS[j]->tenSach);
			temp2 = getString(listDS.nodesDS[min_idx]->tenSach);
			if (temp1 < temp2)
				min_idx = j;
		}
		// Swap the found minimum element with the first element
		swap_DS(listDS.nodesDS[min_idx],listDS.nodesDS[i]);
	}
}

///* This function takes last element as pivot, places
//the pivot element at its correct position in sorted
//array, and places all smaller (smaller than pivot)
//to left of pivot and all greater elements to right
//of pivot */
//int partition (int arr[], int low, int high) {
//	int pivot = arr[high]; // pivot
//	int i = (low - 1); // Index of smaller element
//
//	for (int j = low; j <= high - 1; j++) {
//		// If current element is smaller than the pivot
//		if (arr[j] < pivot) {
//			i++; // increment index of smaller element
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);
//	return (i + 1);
//}
//
///* The main function that implements QuickSort
//arr[] --> Array to be sorted,
//low --> Starting index,
//high --> Ending index */
//void quickSort(int arr[], int low, int high) {
//	if (low < high) {
//		/* pi is partitioning index, arr[p] is now
//		at right place */
//		int pi = partition(arr, low, high);
//
//		// Separately sort elements before
//		// partition and after partition
//		quickSort(arr, low, pi - 1);
//		quickSort(arr, pi + 1, high);
//	}
//}

