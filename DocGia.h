#ifndef __DOCGIA_H__
#define __DOCGIA_H__
#include<fstream>
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
class DocGia{
private:
	string ma;
	string ten;
	int tuoi;
public:
	void setMa(string str);
	void setTen(string str);
	void setTuoi(int n);
	string getMa();
	string getTen();
	int getTuoi();
	void nhap();
	void xuat();
};
class DanhSachDocGia{
private:
	DocGia**list;
	int soLuong;
public:
	DanhSachDocGia();
	DanhSachDocGia(int n);
	~DanhSachDocGia();
	void them();
	void them(string str);
	void xuat();
	void xoa(string str);
	void sua(string str);
	DocGia* tim(string ma);
	int getSoLuong();
	void luu(string nameFile);
	void doc(string nameFile);
};


#endif