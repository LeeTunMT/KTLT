#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Phanso {
	int tu;
	int mau;
};

int so_sanh(Phanso ps1, Phanso ps2);
void Nhap(Phanso phanso[], int& n);
void output(Phanso pso);
void xuat_danh_sach(Phanso pso[], int n);
void xuat_danh_sach(vector<Phanso> pso, int n);
vector <Phanso> nghich_dao(Phanso ps[100], int n);
int Ucln(int a, int b);
void rutgon(Phanso & pso);
Phanso cong_2_ps(Phanso ps1, Phanso ps2);
Phanso tong_cac_ps(Phanso ps[], int n);
Phanso tich_2_ps(Phanso ps1, Phanso ps2);
Phanso tich_cac_ps(Phanso ps[], int n);
Phanso max(Phanso ps[], int n);
Phanso min(Phanso ps[], int n);
void SelectionSort(Phanso pso[], int n);

int main() {
	int n;
	Phanso ps[100];
	Nhap(ps, n);

	cout << "Danh sach phan so: ";
	xuat_danh_sach(ps, n);

	cout << "Tong cac phan so la: ";
	output(tong_cac_ps(ps, n));

	cout << "Tich cac phan so la: ";
	output(tich_cac_ps(ps, n));

	cout << "Nghich dao cac gia tri phan so trong mang la: ";
	xuat_danh_sach(nghich_dao(ps, n), n);

	cout << "GTLN cac phan so la: ";
	output(max(ps, n));

	cout << "GTNN cac phan so la: ";
	output(min(ps, n));

	cout << "Sap xep mang phan so tang dan: ";
	SelectionSort(ps, n);
	xuat_danh_sach(ps, n);
	
	return 0;
}

int so_sanh(Phanso ps1, Phanso ps2) {
	if ((float)ps1.tu / ps1.mau > (float)ps2.tu / ps2.mau)
		return 1;
	if ((float)ps1.tu / ps1.mau < (float)ps2.tu / ps2.mau)
		return -1;
	return 0;
}

void Nhap(Phanso phanso[], int& n) {
	cout << "Nhap do dai cua mang phan so: ";
		cin >> n;
	cout << " Nhap " << n << " phan so: \n";
	for (int i = 0; i < n; i++)
		cin >> phanso[i].tu >> phanso[i].mau;
	for (int i = 0; i < n; i++)
		if (phanso[i].mau == 0)
			cout << "co phan so khong xac dinh";
}

void output(Phanso pso) {
	cout << pso.tu << "/" << pso.mau << "\n";
}

void xuat_danh_sach(Phanso pso[], int n) {
	if (n == 0)
		return;
	cout << pso[0].tu << "/" << pso[0].mau;
	for (int i = 1; i < n; i++) {
		cout << ", ";
		cout << pso[i].tu << "/" << pso[i].mau;
	}
	cout << endl;
}

void xuat_danh_sach(vector<Phanso> pso, int n) {
	if (n == 0) return;
	cout << pso[0].tu << "/" << pso[0].mau;
	for (int i = 1; i < n; i++) {
		cout << ", ";
		cout << pso[i].tu << "/" << pso[i].mau;
	}
	cout << endl;
}

vector <Phanso> nghich_dao(Phanso ps[100], int n) {
	Phanso nghich_dao;
	vector <Phanso> list_nghich_dao;
	for (int i = 0; i < n; i++) {
		nghich_dao.tu = ps[i].mau;
		nghich_dao.mau = ps[i].tu;
		list_nghich_dao.push_back(nghich_dao);
	}
	return list_nghich_dao;
}

int Ucln(int a, int b) {
	while (a != b) {
		if (a > b) a = a - ((a - 1) / b) * b;
		else b = b - ((b - 1) / a) * a;
	}
	return a;
}

void rutgon(Phanso & pso) {
	int ucln = Ucln(pso.tu, pso.mau);
	pso.tu /= ucln;
	pso.mau /= ucln;
}

Phanso cong_2_ps(Phanso ps1, Phanso ps2) {
	Phanso tong;
	tong.tu = ps1.tu * ps2.mau + ps2.tu * ps2.mau;
	tong.mau = ps1.mau * ps2.mau;
	rutgon(tong);
	return tong;
}


Phanso tong_cac_ps(Phanso ps[], int n) {
	Phanso tong = ps[0];
	for (int i = 1; i < n; i++) {
		tong = cong_2_ps(tong, ps[i]);
	}
	return tong;
}


Phanso tich_2_ps(Phanso ps1, Phanso ps2) {
	Phanso tich;
	tich.tu = ps1.tu * ps2.tu;
	tich.mau = ps1.mau * ps2.mau;
	rutgon(tich);
	return tich;
}

Phanso tich_cac_ps(Phanso ps[], int n) {
	Phanso tich = ps[0];
	for (int i = 1; i < n; i++) {
		tich = tich_2_ps(tich, ps[i]);
	}
	return tich;
}

Phanso max(Phanso ps[], int n) {
	Phanso max = ps[0];
	for (int i = 1; i < n; i++) {
		if (so_sanh(ps[i], max) == 1) {
			max = ps[i];
		}
	}
	return max;
}

Phanso min(Phanso ps[], int n) {
	Phanso min = ps[0];
	for (int i = 1; i < n; i++) {
		if (so_sanh(ps[i], min) == -1) {
			min = ps[i];
		}
	}
	return min;
}

void SelectionSort(Phanso pso[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int k = i;
		for (int j = i + 1; j < n; j++) {
			if (so_sanh(pso[j], pso[k]) == -1) k = j;
		}
		swap(pso[i], pso[k]);
	}
}
