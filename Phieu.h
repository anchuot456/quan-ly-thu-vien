#ifndef __PHIEU_H__
#define __PHIEU_H__
#include<math.h>
#include<time.h>
#include"DocGia.h"
#include"Sach.h"
class Date{
private:
	int day, month, year;
public:
	Date();
	Date(int day, int month, int year);
	int toInt();
	int distance(Date other);
	void xuat();
	friend istream& operator >>(istream& in, Date& date);
	friend ostream& operator<<(ostream& out, const Date& date);
};
class Phieu{
private:
	string ma;
	DocGia* docGia;
	SachViet* sach;
	Date ngayMuon;
public:
	Phieu();
	~Phieu();
	void setMa(string str);
	void nhap(DanhSachDocGia* person,DanhSachSach* book);
	void xuat();
	void setDocGia(DocGia*p);
	void setSach(SachViet*s);
	void setNgayMuon(Date date);
	string getMa();
	int tienPhat();
	DocGia* getDocGia();
	SachViet* getSach();
	Date getNgayMuon();
};
class DanhSachPhieu{
private:
	Phieu**list;
	int soLuong;
public:
	DanhSachPhieu();
	DanhSachPhieu(int n);
	~DanhSachPhieu();
	void them(DanhSachDocGia*person, DanhSachSach*book);
	void xuat();
	void xoa(string str);
	Phieu* tim(string ma);
	void danhSachPhat();
	void luu(string fileName);
	void doc(string fileName, DanhSachDocGia* person, DanhSachSach* book);
};


#endif