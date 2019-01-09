#include"ThuVien.h"
void ThuVien::work(){
	person.doc("DocGia.txt");
	book.doc("sach.txt");
	phieu.doc("phieu.txt",&person,&book);
	while (1){
		cout << "***********Thu Vien Sinh Vien***********" << endl;
		cout << "0.Thoat" << endl;
		cout << "1.In Danh Sach Sach" << endl;
		cout << "2.Tim Sach" << endl;
		cout << "3.Them Sach" << endl;
		cout << "4.Xoa Sach" << endl;
		cout << "5.Sua Thong Tin Sach" << endl;
		cout << "6.In Danh Sach Doc Gia" << endl;
		cout << "7.Tim Doc Gia" << endl;
		cout << "8.Them Doc Gia" << endl;
		cout << "9.Xoa Doc Gia" << endl;
		cout << "10.Sua Thong Tin Doc Gia" << endl;
		cout << "11.In Danh Sach Phieu" << endl;
		cout << "12.Tim Phieu" << endl;
		cout << "13.Them Phieu Muon" << endl;
		cout << "14.Xoa Phieu Muon" << endl;
		cout << "15.In Danh Sach Cac Phieu Bi Phat" << endl;
		cout << "ban chon chuc nang: ";
		int k;
		cin >> k;
		fflush(stdin);
		string str;
		char c;
		switch (k)
		{
		case 0:
			person.luu("DocGia.txt");
			book.luu("sack.txt");
			phieu.luu("phieu.txt");
			return;
		case 1:
			system("cls");
			cout << "ma   ten   tac gia   nhaXB   gia   ISBN" << endl;
			book.xuat();
			while (1){
				cout << "ban da xem xong (y/n): ";
				cin >> c;
				if (c == 'y'){
					break;
				}
			}
			break;
		case 2:
			system("cls");
			SachViet*s;
			while (1){
				cout << "nhap ma so sach ban muon xoa: ";
				getline(cin, str);
				s = book.tim(str);
				if (s != NULL){
					break;;
				}
				cout << "ma sach khong ton tai" << endl;
			}
			cout << "ma   ten   tacgia    nhaXB    gia    ISBN" << endl;
			s->xuat();
			while (1){
				cout << "ban da xem xong (y/n): ";
				cin >> c;
				if (c == 'y'){
					break;
				}
			}
			break;
		case 3:
			system("cls");
			book.them();
			break;
		case 4:
			system("cls");
			while (1){
				cout << "nhap ma so sach ban muon xoa: ";
				getline(cin, str);
				SachViet*s = book.tim(str);
				if (s != NULL){
					break;;
				}
				cout << "ma sach khong ton tai" << endl;
			}
			book.xoa(str);
			break;
		case 5:
			system("cls");
			while (1){
				cout << "nhap ma so sach ban muon sua: ";
				getline(cin, str);
				SachViet*s = book.tim(str);
				if (s != NULL){
					break;;
				}
				cout << "ma sach khong ton tai" << endl;
			}
			book.sua(str);
			break;
		case 6:
			system("cls");
			cout << "ma   ten   tuoi" << endl;
			person.xuat();
			while (1){
				cout << "ban da xem xong (y/n): ";
				cin >> c;
				if (c == 'y'){
					break;
				}
			}
			break;
		case 7:
			system("cls");
			DocGia*p;
			while (1){
				cout << "nhap ma so doc gia ban muon xoa: ";
				getline(cin, str);
				p = person.tim(str);
				if (p != NULL){
					break;
				}
				cout << "ma so doc gia khong ton tai!" << endl;
			}
			cout << "ma   ten   tuoi" << endl;
			p->xuat();
			while (1){
				cout << "ban da xem xong (y/n): ";
				cin >> c;
				if (c == 'y'){
					break;
				}
			}
			break;
		case 8:
			system("cls");
			person.them();
			break;
		case 9:
			system("cls");
			while (1){
				cout << "nhap ma so doc gia ban muon xoa: ";
				getline(cin, str);
				DocGia*p = person.tim(str);
				if (p != NULL){
					break;
				}
				cout << "ma so doc gia khong ton tai!" << endl;
			}
			person.xoa(str);
			break;
		case 10:
			system("cls");
			while (1){
				cout << "nhap ma so doc gia ban muon xoa: ";
				getline(cin, str);
				DocGia*p = person.tim(str);
				if (p != NULL){
					break;
				}
				cout << "ma so doc gia khong ton tai!" << endl;
			}
			person.sua(str);
			break;
		case 11:
			system("cls");
			cout << "ma    doc gia    sach    ngay muon" << endl;
			phieu.xuat();
			while (1){
				cout << "ban da xem xong (y/n): ";
				cin >> c;
				if (c == 'y'){
					break;
				}
			}
			break;
		case 12:
			system("cls");
			Phieu*ph;
			while (1){
				cout << "nhap ma so phieu: ";
				getline(cin, str);
				ph = phieu.tim(str);
				if (ph != NULL){
					break;
				}
				cout << "ma phieu khong ton tai!" << endl;
			}
			cout << "ma    doc gia    sach    ngay muon" << endl;
			ph->xuat();
			while (1){
				cout << "ban da xem xong (y/n): ";
				cin >> c;
				if (c == 'y'){
					break;
				}
			}
			break;
		case 13:
			system("cls");
			phieu.them(&person, &book);
			break;
		case 14:
			system("cls");
			while (1){
				cout << "nhap ma so phieu ban muon xoa: ";
				getline(cin, str);
				Phieu* ph = phieu.tim(str);
				if (ph != NULL){
					break;
				}
				cout << "ma so phieu khong ton tai!" << endl;
			}
			phieu.xoa(str);
			break;
		default:
			system("cls");
			cout << "ma phieu   tien phat" << endl;
			phieu.danhSachPhat();
			while (1){
				cout << "ban da xem xong (y/n): ";
				cin >> c;
				if (c == 'y'){
					break;
				}
			}
			break;
		}
		system("cls");
	}
}