#include"Phieu.h"
Date::Date(){

}
Date::Date(int a, int b, int c){
	day = a;
	month = b;
	year = c;
}
int Date::toInt(){
	if (month < 3) {
		year--;
		month += 12;
	}
	return 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
}
int Date::distance(Date other){
	return abs(this->toInt() - other.toInt());
}
void Date::xuat(){
	cout << day << "/" << month << "/" << year;
}
istream& operator >>(istream& in, Date&date){
	char c;
	in >> date.day >> c >> date.month >> c >> date.year;
	return in;
}
ostream& operator <<(ostream& out, const Date& date){
	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}

//phieu
Phieu::Phieu(){
	docGia = NULL;
	sach = NULL;
}
Phieu::~Phieu(){

}
void Phieu::nhap(DanhSachDocGia* person, DanhSachSach* book){
	string str;
	cout << "nhap ma doc gia: ";
	getline(cin, str);
	DocGia* p = person->tim(str);
	if (p == NULL){
		person->them(str);
		p = person->tim(str);
	}
	docGia = p;
	SachViet* q;
	while (1){
		cout << "nhap ma sach: ";
		getline(cin, str);
		q = book->tim(str);
		if (q != NULL){
			break;
		}
		cout << "ma sach khong ton tai!" << endl;
	}
	sach = q;
	int day, month, year;
	cout << "nhap ngay, thang, nam (muon): ";
	cin >> ngayMuon;
	fflush(stdin);
}
void Phieu::xuat(){
	cout << ma << "   " << docGia->getMa() << "   ";
	cout << sach->getMaSach() << "   ";
	ngayMuon.xuat();
	cout << endl;
}
string Phieu::getMa(){
	return ma;
}
void Phieu::setMa(string str){
	ma = str;
}
int Phieu::tienPhat(){
	time_t hientai;
	time(&hientai);
	tm TM;
	localtime_s(&TM, &hientai);
	Date date(TM.tm_mday, TM.tm_mon + 1, TM.tm_year+1900);
	int distance = date.distance(ngayMuon);
	if (distance > 7){
		distance -= 7;
		if (sach->InterfaceType()==typeid(SachViet)){
			return 10 * distance;
		}
		else{
			return 20 * distance;
		}
	}
	return 0;
}
DocGia* Phieu::getDocGia(){
	return docGia;
}
SachViet* Phieu::getSach(){
	return sach;
}
Date Phieu::getNgayMuon(){
	return ngayMuon;
}
void Phieu::setDocGia(DocGia*p){
	docGia = p;
}
void Phieu::setSach(SachViet*s){
	sach = s;
}
void Phieu::setNgayMuon(Date date){
	ngayMuon = date;
}

//Danh Sach Phieu
DanhSachPhieu::DanhSachPhieu(){
	list = NULL;
	soLuong = 0;
}
DanhSachPhieu::DanhSachPhieu(int n){
	soLuong = n;
	list = new Phieu*[n];
}
DanhSachPhieu::~DanhSachPhieu(){
	delete[]list;
}
void DanhSachPhieu::them(DanhSachDocGia*person,DanhSachSach*book){
	string str;
	Phieu*p;
	while (1){
		cout << "nhap ma phieu: ";
		getline(cin, str);
		p = tim(str);
		if (p == NULL){
			break;
		}
		cout << "ma phieu da ton tai!" << endl;
	}
	if (soLuong > 0){
		Phieu**temp = new Phieu*[soLuong];
		for (int i = 0; i < soLuong; i++){
			temp[i] = list[i];
		}
		soLuong++;
		list = new Phieu*[soLuong];
		for (int i = 0; i < soLuong - 1; i++){
			list[i] = temp[i];
		}
		delete[]temp;
	}
	else{
		list = new Phieu*[1];
		soLuong++;
	}
	list[soLuong - 1] = new Phieu();
	list[soLuong - 1]->setMa(str);
	list[soLuong - 1]->nhap(person,book);
}
void DanhSachPhieu::xoa(string str){
	for (int i = 0; i < soLuong; i++){
		if (list[i]->getMa() == str){
			delete list[i];
			for (int j = i; j < soLuong; j++){
				list[j] = list[j + 1];
			}
			soLuong--;
			return;
		}
	}
}
Phieu* DanhSachPhieu::tim(string str){
	for (int i = 0; i < soLuong; i++){
		if (list[i]->getMa() == str){
			return list[i];
		}
	}
	return NULL;
}
void DanhSachPhieu::danhSachPhat(){
	for (int i = 0; i < soLuong; i++){
		if (list[i]->tienPhat() != 0){
			cout << list[i]->getMa() << "   " << list[i]->tienPhat() << "000" << endl;
		}
	}
}
void DanhSachPhieu::luu(string fileName){
	ofstream fp;
	fp.open(fileName);
	if (!fp.fail()){
		for (int i = 0; i < soLuong; i++){
			fp << list[i]->getMa() << ",";
			fp << list[i]->getDocGia()->getMa() << ",";
			fp << list[i]->getSach()->getMaSach() << ",";
			fp << list[i]->getNgayMuon() << endl;
		}
	}
}
void DanhSachPhieu::doc(string fileName,DanhSachDocGia* person,DanhSachSach* book){
	ifstream fp;
	fp.open(fileName);
	if (!fp.fail()){
		while (!fp.eof()){
			if (soLuong > 0){
				Phieu**temp = new Phieu*[soLuong];
				for (int i = 0; i < soLuong; i++){
					temp[i] = list[i];
				}
				soLuong++;
				list = new Phieu*[soLuong];
				for (int i = 0; i < soLuong - 1; i++){
					list[i] = temp[i];
				}
				delete[]temp;
			}
			else{
				list = new Phieu*[1];
				soLuong++;
			}
			list[soLuong - 1] = new Phieu();
			string ma;
			getline(fp, ma, ',');
			list[soLuong - 1]->setMa(ma);
			getline(fp, ma, ',');
			DocGia*p = person->tim(ma);
			list[soLuong - 1]->setDocGia(p);
			getline(fp, ma, ',');
			SachViet*s = book->tim(ma);
			list[soLuong - 1]->setSach(s);
			Date date;
			fp >> date;
			list[soLuong - 1]->setNgayMuon(date);
			getline(fp, ma);
		}
		soLuong--;
	}
}
void DanhSachPhieu::xuat(){
	for (int i = 0; i < soLuong; i++){
		list[i]->xuat();
	}
}