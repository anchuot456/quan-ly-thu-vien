#ifndef __SACH_H__
#define __SACH_H__
#include<iostream>
#include<string>
#include<typeinfo>
#include<fstream>
#include<Windows.h>
using namespace std;
class SachViet{
protected:
	string maSach;
	string ten;
	string tacGia;
	string nhaxb;
	int gia;
public:
	void setMaSach(string str);
	void setTen(string str);
	void setTacGia(string str);
	void setNhaXB(string str);
	void setGia(int n);
	virtual void setISBN(string str);
	virtual void nhap();
	virtual void xuat();
	string getTacGia();
	string getNhaXB();
	string getMaSach();
	string getTen();
	virtual string getISBN();
	int getGia();
	virtual const type_info& InterfaceType();
};
class SachNgoai :public SachViet{
private:
	string ISBN;
public:
	void setISBN(string str);
	void nhap();
	void xuat();
	const type_info& InterfaceType();
	string getISBN();
};
class DanhSachSach{
private:
	SachViet**list;
	int soLuong;
public:
	DanhSachSach();
	DanhSachSach(int n);
	~DanhSachSach();
	void them();
	void xuat();
	void xoa(string maSach);
	void sua(string maSach);
	SachViet* tim(string maSach);
	int getSoLuong();
	void luu(string fileName);
	void doc(string fileName);

};

#endif