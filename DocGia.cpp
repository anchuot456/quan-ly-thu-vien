#include"DocGia.h"

//Doc gia
void DocGia::setMa(string str){
	ma = str;
}
void DocGia::setTen(string str){
	ten = str;
}
void DocGia::setTuoi(int n){
	tuoi = n;
}
string DocGia::getMa(){
	return ma;
}
string DocGia::getTen(){
	return ten;
}
int DocGia::getTuoi(){
	return tuoi;
}
void DocGia::nhap(){
	string str;
	int n;
	cout << "nhap ten: ";
	getline(cin, str);
	cout << "nhap tuoi: ";
	cin >> n;
	fflush(stdin);
	setTen(str);
	setTuoi(n);
}
void DocGia::xuat(){
	cout << ma << "   " << ten << "   " << tuoi << endl;
}

//Danh Sach doc gia
DanhSachDocGia::DanhSachDocGia(){
	list = NULL;
	soLuong = 0;
}
DanhSachDocGia::DanhSachDocGia(int n){
	soLuong = n;
	list = new DocGia*[n];
}
DanhSachDocGia::~DanhSachDocGia(){
	delete[]list;
}
void DanhSachDocGia::them(){
	string str;
	while (1){
		cout << "nhap ma so doc gia: ";
		getline(cin, str);
		int k = 1;
		for (int i = 0; i < soLuong; i++){
			if (str == list[i]->getMa()){
				k = 0;
				break;
			}
		}
		if (k){
			break;
		}
		cout << "ma so da ton tai!" << endl;
	}
	them(str);
}
void DanhSachDocGia::them(string str){
	if (soLuong > 0){
		DocGia**temp = new DocGia*[soLuong];
		for (int i = 0; i < soLuong; i++){
			temp[i] = list[i];
		}
		soLuong++;
		list = new DocGia*[soLuong];
		for (int i = 0; i < soLuong - 1; i++){
			list[i] = temp[i];
		}
		delete[]temp;
	}
	else{
		list = new DocGia*[1];
		soLuong++;
	}
	list[soLuong - 1] = new DocGia();
	list[soLuong - 1]->setMa(str);
	list[soLuong - 1]->nhap();
}
void DanhSachDocGia::xuat(){
	for (int i = 0; i < soLuong; i++){
		list[i]->xuat();
	}
}
DocGia* DanhSachDocGia::tim(string ma){
	for (int i = 0; i < soLuong; i++){
		if (list[i]->getMa() == ma){
			return list[i];
		}
	}
	return NULL;
}
int DanhSachDocGia::getSoLuong(){
	return soLuong;
}
void DanhSachDocGia::luu(string fileName){
	ofstream fp;
	fp.open(fileName);
	if (!fp.fail()){
		for (int i = 0; i < soLuong; i++){
			fp << list[i]->getMa() << ",";
			fp << list[i]->getTen() << ",";
			fp << list[i]->getTuoi() << endl;
		}
		fp.close();
	}
}
void DanhSachDocGia::doc(string fileName){
	ifstream fp;
	fp.open(fileName);
	if (!fp.fail()){
		while (!fp.eof()){
			if (soLuong > 0){
				DocGia**temp = new DocGia*[soLuong];
				for (int i = 0; i < soLuong; i++){
					temp[i] = list[i];
				}
				soLuong++;
				list = new DocGia*[soLuong];
				for (int i = 0; i < soLuong - 1; i++){
					list[i] = temp[i];
				}
				delete[]temp;
			}
			else{
				list = new DocGia*[1];
				soLuong++;
			}
			string ma, ten;
			int tuoi;
			getline(fp, ma, ',');
			getline(fp, ten, ',');
			fp >> tuoi;
			list[soLuong - 1] = new DocGia();
			list[soLuong - 1]->setMa(ma);
			list[soLuong - 1]->setTen(ten);
			list[soLuong - 1]->setTuoi(tuoi);
			getline(fp, ma);
		}
		soLuong--;
	}
}
void DanhSachDocGia::xoa(string str){
	for (int i = 0; i < soLuong; i++){
		if (list[i]->getMa() == str){
			delete list[i];
			for (int j = i; j < soLuong; j++){
				list[j] = list[j + 1];
			}
			return;
		}
	}
}
void DanhSachDocGia::sua(string str){
	DocGia*p = tim(str);
	if (p != NULL){
		while (1){
			cout << "1.Ten" << endl;
			cout << "2.Tuoi" << endl;
			cout << "Ban chon: ";
			int a;
			cin >> a;
			fflush(stdin);
			string str;
			if (a == 1){
				cout << "Nhap ten: ";
				getline(cin, str);
				p->setTen(str);
			}
			else{
				cout << "Nhap tuoi: ";
				cin >> a;
				fflush(stdin);
				p->setTuoi(a);
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
}