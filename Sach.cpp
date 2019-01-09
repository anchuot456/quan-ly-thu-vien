#include"Sach.h"

//Sach viet
void SachViet::nhap(){
	string str;
	int a;
	cout << "nhap ten sach: ";
	getline(cin, str);
	setTen(str);
	cout << "nhap ten tac gia: ";
	getline(cin, str);
	setTacGia(str);
	cout << "nhap ten nha xuat ban: ";
	getline(cin, str);
	setNhaXB(str);
	cout << "nhap gia sach: ";
	cin >> a;
	fflush(stdin);
	setGia(a);
}
void SachViet::xuat(){
	cout << maSach << "   " << ten << "   " << tacGia;
	cout << "   " << nhaxb << "   " << gia << endl;
}
void SachViet::setMaSach(string str){
	maSach = str;
}
void SachViet::setNhaXB(string str){
	nhaxb = str;
}
void SachViet::setTacGia(string str){
	tacGia = str;
}
void SachViet::setTen(string str){
	ten = str;
}
void SachViet::setGia(int n){
	gia = n;
}
void SachViet::setISBN(string str){

}
string SachViet::getTacGia(){
	return tacGia;
}
string SachViet::getNhaXB(){
	return nhaxb;
}
int SachViet::getGia(){
	return gia;
}
string SachViet::getMaSach(){
	return maSach;
}
string SachViet::getTen(){
	return ten;
}
const type_info& SachViet::InterfaceType(){
	return typeid(SachViet); 
}
string SachViet::getISBN(){
	return "";
}

//Sach Ngoai
void SachNgoai::nhap(){
	string str;
	SachViet::nhap();
	cout << "nhap ISBN: ";
	getline(cin, str);
	ISBN = str;
}
void SachNgoai::xuat(){
	cout << maSach << "   " << ten << "   " << tacGia;
	cout << "   " << nhaxb << "   " << gia << "   " << ISBN << endl;
}
const type_info& SachNgoai::InterfaceType(){
	return typeid(SachNgoai);
}
string SachNgoai::getISBN(){
	return ISBN;
}
void SachNgoai::setISBN(string str){
	ISBN = str;
}

//Danh Sach Sach
DanhSachSach::DanhSachSach(){
	soLuong = 0;
	list = NULL;
}
DanhSachSach::DanhSachSach(int n){
	soLuong = n;
	list = new SachViet*[n];
}
DanhSachSach::~DanhSachSach(){
	delete[]list;
}
void DanhSachSach::them(){
	string str;
	while (1){
		int k = 1;
		cout << "nhap ma sach: ";
		getline(cin, str);
		for (int i = 0; i < soLuong; i++){
			if (str == list[i]->getMaSach()){
				k = 0;
				break;
			}
		}
		if (k){
			break;
		}
		cout << "ma sach da ton tai!" << endl;
		cout << "nhap lai!" << endl;
	}
	if (soLuong > 0){
		SachViet**temp = new SachViet*[soLuong];
		for (int i = 0; i < soLuong; i++){
			temp[i] = list[i];
		}
		soLuong++;
		list = new SachViet*[soLuong];
		for (int i = 0; i < soLuong-1; i++){
			list[i] = temp[i];
		}
		delete[]temp;
	}
	else{
		list = new SachViet*[1];
		soLuong++;
	}
	int a;
	cout << "1.Sach Viet" << endl;
	cout << "2.Sach Ngoai" << endl;
	cout << "nhap loai sach: ";
	cin >> a;
	fflush(stdin);
	if (a == 1){
		list[soLuong - 1] = new SachViet();
	}
	else{
		list[soLuong - 1] = new SachNgoai();
	}
	list[soLuong - 1]->setMaSach(str);
	list[soLuong - 1]->nhap();
}
void DanhSachSach::xoa(string ma){
	for (int i = 0; i < soLuong; i++){
		if (ma == list[i]->getMaSach()){
			delete list[i];
			for (int j = i; j < soLuong-1; j++){
				list[j] = list[j + 1];
			}
			soLuong--;
			return;
		}
	}
	cout << "ma sach khong ton tai!" << endl;
}
SachViet* DanhSachSach::tim(string ma){
	for (int i = 0; i < soLuong; i++){
		if (ma == list[i]->getMaSach()){
			return list[i];
		}
	}
	return NULL;
}
void DanhSachSach::sua(string ma){
	SachViet*p = tim(ma);
	while (1){
		cout << "1.Ten" << endl;
		cout << "2.Tac gia" << endl;
		cout << "3.Nha xuat ban" << endl;
		cout << "4.Gia" << endl;
		cout << "ban muon sua thong tin: ";
		int a;
		cin >> a;
		fflush(stdin);
		string str;
		switch (a){
		case 1:
			cout << "nhap ten sach: ";
			getline(cin, str);
			p->setTen(str);
			break;
		case 2:
			cout << "nhap tac gia: ";
			getline(cin, str);
			p->setTacGia(str);
			break;
		case 3:
			cout << "nhap nha xuat ban: ";
			getline(cin, str);
			p->setNhaXB(str);
			break;
		default:
			int gia;
			cout << "nhap gia: ";
			cin >> gia;
			p->setGia(gia);
			break;
		}
		char c;
		cout << "Ban da sua xong(y/n): ";
		cin >> c;
		if (c == 'y'){
			return;
		}
		system("cls");
	}
}
int DanhSachSach::getSoLuong(){
	return soLuong;
}
void DanhSachSach::luu(string fileName){
	ofstream fp;
	fp.open("sach.txt");
	if (!fp.fail()){
		for (int i = 0; i < soLuong; i++){
			fp << list[i]->getMaSach() << ",";
			fp << list[i]->getTen() << ",";
			fp << list[i]->getTacGia() << ",";
			fp << list[i]->getNhaXB() << ",";
			fp << list[i]->getGia();
			if (list[i]->InterfaceType() == typeid(SachNgoai)){
				fp << "," << list[i]->getISBN();
			}
			fp << endl;
		}
		fp.close();
	}
}
void DanhSachSach::doc(string fileName){
	ifstream fp;
	fp.open(fileName);
	while (!fp.eof()){
		if (soLuong > 0){
			SachViet**temp = new SachViet*[soLuong];
			for (int i = 0; i < soLuong; i++){
				temp[i] = list[i];
			}
			soLuong++;
			list = new SachViet*[soLuong];
			for (int i = 0; i < soLuong - 1; i++){
				list[i] = temp[i];
			}
			delete[]temp;
		}
		else{
			list = new SachViet*[1];
			soLuong++;
		}
		string ma, ten, tacGia, nhaXB, ISBN;
		int gia;
		getline(fp, ma, ',');
		getline(fp, ten, ',');
		getline(fp, tacGia, ',');
		getline(fp, nhaXB, ',');
		fp >> gia;
		getline(fp, ISBN);
		if (ISBN!=""){
			ISBN.erase(0, 1);
			list[soLuong - 1] = new SachNgoai();
			list[soLuong - 1]->setMaSach(ma);
			list[soLuong - 1]->setTen(ten);
			list[soLuong - 1]->setTacGia(tacGia);
			list[soLuong - 1]->setNhaXB(nhaXB);
			list[soLuong - 1]->setGia(gia);
			list[soLuong - 1]->setISBN(ISBN);
		}
		else{
			list[soLuong - 1] = new SachViet();
			list[soLuong - 1]->setMaSach(ma);
			list[soLuong - 1]->setTen(ten);
			list[soLuong - 1]->setTacGia(tacGia);
			list[soLuong - 1]->setNhaXB(nhaXB);
			list[soLuong - 1]->setGia(gia);
		}
	}
	soLuong--;
}
void DanhSachSach::xuat(){
	for (int i = 0; i < soLuong; i++){
		list[i]->xuat();
	}
}
