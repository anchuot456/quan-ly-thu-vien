#ifndef __THUVIEN_H__
#define __THUVIEN_H__
#include<Windows.h>

#include"DocGia.h"
#include"Phieu.h"
#include"Sach.h"
class ThuVien{
private:
	DanhSachDocGia person;
	DanhSachSach book;
	DanhSachPhieu phieu;
public:
	void work();
};




#endif