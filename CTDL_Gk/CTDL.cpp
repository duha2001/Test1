#include <iostream>
#include <windows.h> 
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h> 
#include <stdio.h>
#include <ctime>
#include <unistd.h>
#define MAX_LENGTH 16
using namespace std;
int i = 1, o =0, u = 1, dem =0; 	
int choice;
int choiceSach;
int choicePMuon;
int back;
void gotoxy(int x, int y){
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void DangKyThanhVien();
void QuanLySach();
void QuanLyPhieuMuon();
void ManHinhMenuLuaChon(){
		choice=0;
		choiceSach=0;
		choicePMuon=0;
		gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
		gotoxy(40, 3);  cout << "*             MENU LUA CHON             *\n";
		gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
		gotoxy(48, 5);  cout << "|1| Quan Ly Sach";
		gotoxy(48, 6);  cout << "|2| Quan Ly Phieu Muon";
		gotoxy(48, 7);  cout << "|3| Dang Ky Thanh Vien";
		gotoxy(40, 8); cout << "Lua Chon:"; cin >> choice;
		if(choice == 1){
			system("cls");
			choice=0;
			choiceSach=0;
			choicePMuon=0;
			QuanLySach();
		}
		if(choice == 2){
			system("cls");
			choice=0;
			choiceSach=0;
			choicePMuon=0;
			QuanLyPhieuMuon();
		}
		if(choice == 3){
			system("cls");
			choice=0;
			choiceSach=0;
			choicePMuon=0;
			DangKyThanhVien();
		}
}
void ManHinhDangNhap(){
	string user;
	string pass;
	gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
	gotoxy(40, 3);  cout << "*           DANG NHAP HE THONG          *\n";
	gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
	gotoxy(48, 5);  cout << "User:";
	gotoxy(48, 6);  cout << "Password:";
	////////////////////////////////////
		//Kiem tra tk va mk co dung k

	ifstream f;
	f.open("C:/Users/admin/Desktop/CTDL/Admin.txt");

	string Fuser;
	string Fpass;
	f >> Fuser; //lay user tu File
	f >> Fpass; //lay pass tu File

	f.close();
	//Nhap tk va mk
	gotoxy(54, 5); cin >> user;
	gotoxy(58, 6);
	///////////////////MaHoa Pass//////////////////// nguon:https://pastebin.com/DDrgGuz4///////
	string password="";
    char keypressed;
 
    for (;;) {
        keypressed=getch(); //what key is pressed?
 
        if (password.size() < MAX_LENGTH && ((keypressed>=60 && keypressed<=90) || (keypressed>=97 && keypressed<=122) || (keypressed>=48 && keypressed<=57) || keypressed==32))
        {
            password+=keypressed; //add char to password
            cout<<"*";
            }
        else if (password.size()>0 && keypressed==8)
        {
            password.resize(password.size()-1); //delete last character of password
            gotoxy(58,6); //move cursor
            for (unsigned char l=0; l<password.size(); l++) cout<<"*"; //write all *
            cout<<" "; //clear last character
            gotoxy(58+password.size(),6); //move cursor to last character
            }
        else if (keypressed==13) break; //if ENTER is pressed
    }
    pass=password;
   	/////////////////////////////////////
	if (user != Fuser || user==Fuser && pass != Fpass) {
		dem++;
		gotoxy(30, 7); cout << "Ban da nhap sai thong tin tai khoan, vui long nhap lai !!!\n";
		system("pause");
		system("cls");
		if (dem == 3) {
			exit(0);
		}
		ManHinhDangNhap();
	}
	else {
		gotoxy(50, 7); cout << "Dang nhap thanh cong !!!\n";
		Sleep(1000);
		system("cls");
		ManHinhMenuLuaChon();
	}
	
}
void backSach(){
	cout<<"Nhap phim 1 de thoat chuong trinh,hoac phim 0 de quay lai Menu QUAN LY SACH: ";
	back=9999;
	cin>>back;
	if(back==1){
		exit(0);
	}
	else{
		choiceSach=0;
		i = 1;
		o = 0;
		u = 1;
		system("cls");
		QuanLySach();
	}
}
void backPMuon(){
	cout<<"Nhap phim 1 de thoat chuong trinh,hoac phim 0 de quay lai Menu QUAN PHIEU MUON: ";
	back=9999;
	cin>>back;
	if(back==1){
		exit(0);
	}
	else{
		choicePMuon=0;
		i = 1;
		o = 0;
		u = 1;
		system("cls");
		QuanLyPhieuMuon();
	}
}
	/////////////////          THANH VIEN      ///////////////////
class ThanhVien{
	private:
	string MaTV;
	string TenTV;
	string TimeTV;
	public:
	ThanhVien() {
		MaTV="";
		TenTV="";
		TimeTV="";
	}
	ThanhVien(string MaTV, string TenTV, string TimeTV){
		this->MaTV = MaTV;
		this->TenTV = TenTV;
		this->TimeTV = TimeTV;
	}
	~ThanhVien(){};
	friend ostream& operator<<(ostream& os, ThanhVien a) {
		os << a.MaTV << endl;
		os << a.TenTV << endl;
		os << a.TimeTV << endl;
		return os;
	}
	string GetMaTV(){
		return MaTV;
	}	
	string GetTenTV(){
		return TenTV;
	}	
	string GetTimeTV(){
		return TimeTV;
	}
};
ThanhVien arrTVien[10000];
void LayDuLieuTuFileThanhVien(){
	ifstream Book("C:/Users/admin/Desktop/CTDL/DanhSachThanhVien.txt");
	string MaTV;
	string TenTV;
	string TimeTV;
	while (!Book.eof()) {
		getline(Book, MaTV);
		getline(Book, TenTV);
		getline(Book, TimeTV);
		ThanhVien p(MaTV, TenTV, TimeTV);
		arrTVien[u] = p;
		u++;
	}
	Book.close();
}
string getDateTime(){
	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer[80];

  	time (&rawtime);
  	timeinfo = localtime(&rawtime);

  	strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
 	 std::string str(buffer);

  	return str;
}
string gen_random(const int len){
    
    string tmp_s;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    
    srand( (unsigned) time(NULL) * getpid());
    
    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    
    return tmp_s;
    
}

	/////////////////             SACH        ////////////////////
class Sach{
private:
	int MaSach;
	string TenSach;
	string TacGia;
	string NXB;
	int Gia;
	int Nam;
	int SoTrang;
	string NgayNhap;
	public:
	int TinhTrang;
public:
	Sach() {
		MaSach = 0;
		TenSach = "";
		TacGia = "";
		NXB = "";
		Gia = 0;
		Nam = 1999;
		SoTrang = 0;
		NgayNhap = "";
		TinhTrang = 0;
	}
	Sach(int MaSach, string TenSach, string TacGia, string NXB, int Gia, int Nam, int SoTrang, string NgayNhap, int TinhTrang) {
		this->MaSach = MaSach;
		this->TenSach = TenSach;
		this->TacGia = TacGia;
		this->NXB = NXB;
		this->Gia = Gia;
		this->Nam = Nam;
		this->SoTrang = SoTrang;
		this->NgayNhap = NgayNhap;
		this->TinhTrang = TinhTrang;
	}
	~Sach(){};
	friend istream& operator>>(istream& is, Sach& a) {
		is >> a.MaSach;
		is.ignore();
		getline(is, a.TenSach);
		getline(is, a.TacGia);
		getline(is, a.NXB);
		is >> a.Gia;
		is >> a.Nam;
		is >> a.SoTrang;
		is.ignore();
		is >> a.NgayNhap;
		is >> a.TinhTrang;
		return is;
	}
	friend ostream& operator<<(ostream& os, Sach a) {
		os << a.MaSach << endl;
		os << a.TenSach << endl;
		os << a.TacGia << endl;
		os << a.NXB << endl;
		os << a.Gia << endl;
		os << a.Nam << endl;
		os << a.SoTrang << endl;
		os << a.NgayNhap << endl;
		os << a.TinhTrang<<endl<<endl;
		return os;
	}
	int GetMaSach(){
		return MaSach;
	}
	string GetTenSach(){
		return TenSach;
	}	
	string GetTacGia(){
		return TacGia;
	}	
	string GetNXB(){
		return NXB;
	}
	int GetGia(){
		return Gia;
	}
	int GetNam(){
		return Nam;
	}
	int GetSoTrang(){
		return SoTrang;
	}
	string GetNgayNhap(){
		return NgayNhap;	
	}	
	int GetTinhTrang(){
		return TinhTrang;
	}
};
Sach arrSach[10000];
int vitrix(Sach m[], int n, int x){
    int vitrix = 0;
    for (int j = 1; j <= n; j++)
        if (m[j].GetMaSach() == x)
        {
            vitrix = j;
            return vitrix;
        }
}
void LayDuLieuTuFileSach(){
	ifstream Book("C:/Users/admin/Desktop/CTDL/Sach.txt");
	int MaSach;
	string TenSach;
	string TacGia;
	string NXB;
	int Gia;
	int Nam;
	int SoTrang;
	string NgayNhap;
	int TinhTrang;
	
	while (!Book.eof()) {
		Book >> MaSach;
		Book.ignore();
		getline(Book, TenSach);
		getline(Book, TacGia);
		getline(Book, NXB);
		Book >> Gia;
		Book >> Nam;
		Book >> SoTrang;
		Book.ignore();
		Book >> NgayNhap;
		Book >> TinhTrang;
		Sach p(MaSach, TenSach, TacGia, NXB, Gia, Nam, SoTrang, NgayNhap, TinhTrang);
		arrSach[i] = p;
		i++;
	}
	Book.close();
}
void XoaPhanTu(Sach a[], int &n, int pos){
    // Mang rong, khong the xoa.
    if(n <= 0){
        return;
    }
    // Neu pos <= 0 => Xoa dau
    if(pos < 0){
        pos = 0;
    }
    // Neu pos >= n => Xoa cuoi
    else if(pos >= n){
        pos = n-1;
    }
    // Dich chuyen mang
    for(int i = pos; i < n - 1; i++){
        a[i] = a[i+1];
    }
    // Giam so luong phan tu sau khi xoa.
    --n;
}
void CapNhatSach(int MaSach1){
	XoaPhanTu(arrSach,i,vitrix(arrSach,i,MaSach1));
	fstream Book("C:/Users/admin/Desktop/CTDL/Sach.txt",ios::out);
	for(int j = 1; j < i; j++){
		int MaSach=arrSach[j].GetMaSach();
		string TenSach=arrSach[j].GetTenSach();
		string TacGia=arrSach[j].GetTacGia();
		string NXB=arrSach[j].GetNXB();
		int Gia=arrSach[j].GetGia();
		int Nam=arrSach[j].GetNam();
		int SoTrang=arrSach[j].GetSoTrang();
		string NgayNhap=arrSach[j].GetNgayNhap();
		int TinhTrang=arrSach[j].GetTinhTrang();
	Sach p(MaSach, TenSach, TacGia, NXB, Gia, Nam, SoTrang, NgayNhap, TinhTrang);
		arrSach[j] = p;	
		Book << MaSach<<endl;
		Book << TenSach<<endl;
		Book << TacGia<<endl;
		Book << NXB<<endl;
		Book << Gia<<endl;
		Book << Nam<<endl;
		Book << SoTrang<<endl;
		Book << NgayNhap<<endl;
		if(j<i-1){
			Book << TinhTrang <<endl;
		}
		else Book << TinhTrang ;
	}	
	Book.close();
}
void HienThiThongTinSach(Sach arrSach[]){
	LayDuLieuTuFileSach();
		for (size_t j = 1; j < i; j++) {
			cout << arrSach[j];
		}	
	cout<<endl;
	backSach();
}
void ThemSach(Sach arrSach[]){
	fstream Book("C:/Users/admin/Desktop/CTDL/Sach.txt",ios::app);
	int MaSach;
	string TenSach;
	string TacGia;
	string NXB;
	int Gia;
	int Nam;
	int SoTrang;
	string NgayNhap;
	int TinhTrang = 0;
////////////Tao mang arrSach voi du lieu co trong file Sach.txt////////////
	LayDuLieuTuFileSach();
////////////Tien hanh them////////////
cout<<"Ma Sach (x): ";
		cin >> MaSach;
		cin.ignore();
cout<<"Ten Sach: ";
		getline(cin, TenSach);
cout<<"Tac Gia: ";
		getline(cin, TacGia);
cout<<"NXB: ";
		getline(cin, NXB);
cout<<"Gia: ";
		cin >> Gia;
cout<<"Nam: ";
		cin >> Nam;
cout<<"So Trang: ";
		cin >> SoTrang;
		cin.ignore();
cout<<"Ngay Nhap (dd/mm/yyyy): ";
		cin >> NgayNhap;
cout<<"Tinh Trang :" << TinhTrang << endl;

//////////////////////Kiem tra ma sach co trung khong////////////////////////////
int test=0;
	for(int j=1;j<=i;j++){
		if(MaSach==arrSach[j].GetMaSach()){
			cout<<"Them Sach Khong Thanh Cong" << endl;
			++test;
			break;
		}
	}
	
	if(test==0){
		cout<<"Them Sach Thanh Cong" << endl;
		Sach p(MaSach, TenSach, TacGia, NXB, Gia, Nam, SoTrang, NgayNhap, TinhTrang);
		arrSach[i] = p;
		i++;
		Book << endl;
		Book << MaSach<<endl;
		Book << TenSach<<endl;
		Book << TacGia<<endl;
		Book << NXB<<endl;
		Book << Gia<<endl;
		Book << Nam<<endl;
		Book << SoTrang<<endl;
		Book << NgayNhap<<endl;
		Book << TinhTrang;

	Book.close();
	}
	backSach();
}
void XoaSach(Sach arrSach[]){
	int MaSach;
	LayDuLieuTuFileSach();
	cout<<"Nhap Ma Sach ma ban muon xoa: ";
	cin>>MaSach;
	int dem2=0;
	if(arrSach[MaSach].GetTinhTrang()!=0){
		cout<<"Khong the xoa sach, do sach dang duoc muon!!!"<<endl;
	}
	else{
		for(int j=1;j<i;j++){
			if(arrSach[vitrix(arrSach,i,MaSach)].GetMaSach()==arrSach[j].GetMaSach()){
				CapNhatSach(MaSach);
				cout<<"Da xoa sach!" << endl;
				++dem2;	
				break;
			}
		}
		if(dem2==0){
			cout<<"Khong co sach de xoa!" << endl;
		}	
	}
	backSach();
}
	/////////////////          PHIEU MUON      ///////////////////
class PhieuMuon{
	private:
	int SoPMuon;
	string MaBDoc;
	int MaSach;
	int NgayMuon;
	int NgayTra;
	public:
	int TinhTrang;
public:
	PhieuMuon() {
		SoPMuon=0;
		MaBDoc="";
		MaSach=0;
		NgayMuon=0;
		NgayTra=7;
		TinhTrang=0;
	}
	PhieuMuon(int SoPMuon, string MaBDoc, int MaSach, int NgayMuon, int NgayTra, int TinhTrang){
		this->SoPMuon = SoPMuon;
		this->MaBDoc = MaBDoc;
		this->MaSach = MaSach;
		this->NgayMuon = NgayMuon;
		this->NgayTra = NgayTra;
		this->TinhTrang = TinhTrang;
	}
	~PhieuMuon(){};
	friend istream& operator>>(istream& is, PhieuMuon& a) {
		is >> a.SoPMuon;
		is.ignore();
		getline(is, a.MaBDoc);
		is >> a.MaSach;
		is >> a.NgayMuon;
		is >> a.NgayTra;
		is >> a.TinhTrang;
		return is;
	}
	friend ostream& operator<<(ostream& os, PhieuMuon a) {
		os << a.SoPMuon << endl;
		os << a.MaBDoc << endl;
		os << a.MaSach << endl;
		os << a.NgayMuon << endl;
		os << a.NgayTra << endl;
		os << a.TinhTrang<<endl<<endl;
		return os;
	}
	int GetSoPMuon(){
		return SoPMuon;
	}
	string GetMaBDoc(){
		return MaBDoc;
	}	
	int GetMaSach(){
		return MaSach;
	}	
	int GetNgayMuon(){
		return NgayMuon;
	}
	int GetNgayTra(){
		return NgayTra;
	}
	int GetTinhTrang(){
		return TinhTrang;
	}
};	
PhieuMuon arrPMuon[10000];
void LayDuLieuTuFilePhieuMuon(){
	ifstream Book("C:/Users/admin/Desktop/CTDL/PhieuMuon.txt");
	int SoPMuon;
	string MaBDoc;
	int MaSach;
	int NgayMuon;
	int NgayTra;
	int TinhTrang;
	while (!Book.eof()) {
		Book >> SoPMuon;
		Book.ignore();
		getline(Book, MaBDoc);
		Book >> MaSach;
		Book >> NgayMuon;
		Book >> NgayTra;
		Book >> TinhTrang;
		PhieuMuon p(SoPMuon, MaBDoc, MaSach, NgayMuon, NgayTra, TinhTrang);
		arrPMuon[o] = p;
		o++;
	}
	Book.close();
}
void HienThiThongTinPMuon(PhieuMuon arrPMuon[]){
	LayDuLieuTuFilePhieuMuon();
		for (size_t j = 0; j < o-1; j++) {
			cout << arrPMuon[j];
		}
	cout<<endl;
	backPMuon();
}
bool checkYear(int year) {
	return (((year % 4 == 0) && (year % 100 != 0)) || 
        (year % 400 == 0));
}
int KTDate(int a){
	
	time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
	int year = 1900 + local_time->tm_year;
    int month = 1 + local_time->tm_mon;
    int date = local_time->tm_mday;
	int kq=a;
	if(a+7>30&&(month==4||month==6||month==9||month==11)){
		kq=7-(30-a);
	}
	else if(a+7>31&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12)){
		kq=7-(31-a);
	}
	else if(checkYear(year) == true && month == 2 && a+7>29){
		kq=7-(29-a);
	}
	else if(checkYear(year) == false && month == 2 && a+7>28){
		kq=7-(28-a);
	}
	else kq+=7;
	return kq;
}
void ThemPMuon(int MSach, string MaTV){
	time_t ttime = time(0);  
	tm *local_time = localtime(&ttime);
	
	LayDuLieuTuFilePhieuMuon();
	int SoPMuon = o;
	string MaBDoc = MaTV;
	int MaSach = MSach;
	int NgayMuon = local_time->tm_mday;
	int NgayTra = KTDate(NgayMuon);
	int TinhTrang = 1;
	//Cap Nhat file Phieu Muon//
	fstream Book("C:/Users/admin/Desktop/CTDL/PhieuMuon.txt",ios::app);
	
	PhieuMuon p(SoPMuon, MaBDoc, MaSach, NgayMuon, NgayTra, TinhTrang);
		arrPMuon[o] = p;
		o++;
		Book << SoPMuon<<endl;
		Book << MaBDoc<<endl;
		Book << MaSach<<endl;
		Book << NgayMuon<<endl;
		Book << NgayTra<<endl;
		Book << TinhTrang<<endl;
	Book.close();
}
void CapNhatFileSach(int MaSach2){
	fstream Book("C:/Users/admin/Desktop/CTDL/Sach.txt",ios::out);
	//Cap Nhat//
	for(int j = 1; j < i; j++){
		if(arrSach[j].GetMaSach()==MaSach2){
			arrSach[j].TinhTrang=o-1;
			break;
		}
	}
	for(int j = 1; j < i; j++){
		int MaSach=arrSach[j].GetMaSach();
		string TenSach=arrSach[j].GetTenSach();
		string TacGia=arrSach[j].GetTacGia();
		string NXB=arrSach[j].GetNXB();
		int Gia=arrSach[j].GetGia();
		int Nam=arrSach[j].GetNam();
		int SoTrang=arrSach[j].GetSoTrang();
		string NgayNhap=arrSach[j].GetNgayNhap();
		int TinhTrang=arrSach[j].GetTinhTrang();
	Sach p(MaSach, TenSach, TacGia, NXB, Gia, Nam, SoTrang, NgayNhap, TinhTrang);
		arrSach[j] = p;	
		Book << MaSach<<endl;
		Book << TenSach<<endl;
		Book << TacGia<<endl;
		Book << NXB<<endl;
		Book << Gia<<endl;
		Book << Nam<<endl;
		Book << SoTrang<<endl;
		Book << NgayNhap<<endl;
		if(j<i-1){
			Book << TinhTrang <<endl;
		}
		else Book << TinhTrang ;
	}	
	Book.close();
}
void TaoPMuon(int MSach, string MaTV){
	
	LayDuLieuTuFileSach();
	LayDuLieuTuFileThanhVien();
	
	
	int flagS = 0;
	for(int a = 1;a < i; a++){
		if(arrSach[a].GetMaSach() == MSach&&arrSach[a].GetTinhTrang()==0){
			flagS++;
			break;
		}
	}
	int flagTV = 0;
	for(int a = 1;a < i; a++){
		if(arrTVien[a].GetMaTV() == MaTV){
			flagTV++;
			break;
		}
	}
	if(flagS == 1 && flagTV == 1){
		cout<<"Muon Sach Thanh Cong !!!";
		ThemPMuon(MSach,MaTV);
		CapNhatFileSach(MSach);
	}
	else 
	cout<<"Muon Sach Khong Thanh Cong !!!";

}
void MuonSach(PhieuMuon arrPMuon[]){
	int MaSach;  cout << "Nhap Ma Sach: "; cin>>MaSach; cin.ignore();
	string MaTV; cout << "Nhap Ma Thanh Vien: "; cin>>MaTV;
	TaoPMuon(MaSach,MaTV);
	cout<<endl;
	backPMuon();
}
void CapNhatFileSach2(int MaPMuon){
	fstream Book("C:/Users/admin/Desktop/CTDL/Sach.txt",ios::out);
	//Cap Nhat//
	for(int j = 1; j < i; j++){
		if(arrSach[j].TinhTrang==MaPMuon){
			arrSach[j].TinhTrang=0;
			break;
		}
	}
	for(int j = 1; j < i; j++){
		int MaSach=arrSach[j].GetMaSach();
		string TenSach=arrSach[j].GetTenSach();
		string TacGia=arrSach[j].GetTacGia();
		string NXB=arrSach[j].GetNXB();
		int Gia=arrSach[j].GetGia();
		int Nam=arrSach[j].GetNam();
		int SoTrang=arrSach[j].GetSoTrang();
		string NgayNhap=arrSach[j].GetNgayNhap();
		int TinhTrang=arrSach[j].GetTinhTrang();
	Sach p(MaSach, TenSach, TacGia, NXB, Gia, Nam, SoTrang, NgayNhap, TinhTrang);
		arrSach[j] = p;	
		Book << MaSach<<endl;
		Book << TenSach<<endl;
		Book << TacGia<<endl;
		Book << NXB<<endl;
		Book << Gia<<endl;
		Book << Nam<<endl;
		Book << SoTrang<<endl;
		Book << NgayNhap<<endl;
		if(j<i-1){
			Book << TinhTrang <<endl;
		}
		else Book << TinhTrang ;
	}	
	Book.close();
}
void CapNhatFilePMuon(int flag){
	fstream Book("C:/Users/admin/Desktop/CTDL/PhieuMuon.txt",ios::out);
	//Cap Nhat//
	arrPMuon[flag].TinhTrang=0;
	for(int j = 0; j < o-1; j++){
		int SoPMuon=arrPMuon[j].GetSoPMuon();
		string MaBDoc=arrPMuon[j].GetMaBDoc();
		int MaSach=arrPMuon[j].GetMaSach();
		int NgayMuon=arrPMuon[j].GetNgayMuon();
		int NgayTra=arrPMuon[j].GetNgayTra();
		int TinhTrang=arrPMuon[j].GetTinhTrang();
	PhieuMuon p(SoPMuon, MaBDoc, MaSach, NgayMuon, NgayTra, TinhTrang);
		arrPMuon[j] = p;	
		Book << SoPMuon<<endl;
		Book << MaBDoc<<endl;
		Book << MaSach<<endl;
		Book << NgayMuon<<endl;
		Book << NgayTra<<endl;
		if(j<o-1){
			Book << TinhTrang <<endl;
		}
		else Book << TinhTrang ;
	}	
	Book.close();
}
void TraSach(PhieuMuon arrPMuon[]){
	int MaPMuon;  
	cout << "Nhap So Thu Tu Phieu Muon: "; 
	cin>>MaPMuon; 
	LayDuLieuTuFilePhieuMuon();
	LayDuLieuTuFileSach();
	int flag=9090;
	for(int a=0;a<o-1;a++){
		if(arrPMuon[a].GetSoPMuon()==MaPMuon){
			flag = a;
			break;
		}
	}
	if(flag==9090){
		 cout<<"Tra Sach Khong Thanh Cong !!!"<<endl;
		 backPMuon();
	}
//	cout<<flag;
	else{
	if(arrPMuon[flag].GetTinhTrang()!=0){
		cout<<"Tra Sach Thanh Cong !!!"<<endl;
		CapNhatFileSach2(flag+1);
		CapNhatFilePMuon(flag);
	}
	else cout<<"Tra Sach Khong Thanh Cong !!!"<<endl;
	backPMuon();
	}
}
int main(){
	ManHinhDangNhap();
	if (choice == 1) {
		QuanLySach();
	}
	if (choice == 2){
		QuanLyPhieuMuon();
	}
	if (choice == 3){
		DangKyThanhVien();
	}
    return 0;
}
void DangKyThanhVien(){
	fstream Book("C:/Users/admin/Desktop/CTDL/DanhSachThanhVien.txt",ios::app);
	
	string CapMa= gen_random(6);// ham gen_random lay ngau nhien 1 chuoi bat ky
	string Ten; 
		
	gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
	gotoxy(40, 3);  cout << "*           DANG KY THANH VIEN          *\n";
	gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
		cout<<endl;
		
		gotoxy(40, 6); cout<<"Ma Ban Doc: "<< CapMa << endl;
		gotoxy(40, 7); cout<<"Nhap ho ten cua ban: "; 
		cin.ignore();
		getline(cin,Ten);
		string s = getDateTime();
		gotoxy(40, 8); cout<<"Ngay Tham Gia: "<< s <<endl; ///ham getDateTime tra ve ngay gio hien tai cua may tinh
		gotoxy(45, 9); cout<<"Dang Ky Thanh Vien Thanh Cong !!!"<<endl;
		gotoxy(57, 10); cout<<"*Luu y*"<<endl;
		gotoxy(39, 11);cout<<" Hay ghi nho Ma Ban Doc cua ban la: "<<CapMa<<endl;
	ThanhVien p(CapMa, Ten, s);
	arrTVien[u] = p;
	u++;
	Book << CapMa <<endl;
	Book <<Ten<<endl;
	Book <<s<<endl;
	Book.close();
		gotoxy(43, 12);	cout << "Bam Enter de quay lai MENU LUA CHON";
		cin.ignore();
		system("cls");
		ManHinhMenuLuaChon();
}
void QuanLySach(){
	gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
	gotoxy(40, 3);  cout << "*             Quan Ly Sach              *\n";
	gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
	gotoxy(48, 5);  cout << "|1| Hien Thi Thong Tin Sach";
	gotoxy(48, 6);  cout << "|2| Them Sach";
	gotoxy(48, 7);  cout << "|3| Xoa Sach";
	gotoxy(48, 8);  cout << "|4| Quay Lai MENU LUA CHON";
	gotoxy(40, 9);  cout << "Lua Chon:"; cin >> choiceSach;

	if (choiceSach == 1) {
		HienThiThongTinSach(arrSach);
	}
	if (choiceSach == 2) {
		ThemSach(arrSach);
	}
	if (choiceSach == 3) {
		XoaSach(arrSach);
	}
	if (choiceSach == 4) {
		system("cls");
		ManHinhMenuLuaChon();
	}
}
void QuanLyPhieuMuon(){
	gotoxy(40, 2);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
	gotoxy(40, 3);  cout << "*           Quan Ly Phieu Muon          *\n";
	gotoxy(40, 4);  cout << "* * * * * * * * * * * * * * * * * * * * *\n";
	gotoxy(48, 5);  cout << "|1| Hien Thi Thong Tin Phieu Muon";
	gotoxy(48, 6);  cout << "|2| Muon Sach";
	gotoxy(48, 7);  cout << "|3| Tra Sach";
	gotoxy(48, 8);  cout << "|4| Quay Lai MENU LUA CHON";
	gotoxy(40, 9);  cout << "Lua Chon:"; cin >> choicePMuon;
	if (choicePMuon == 1) {
		HienThiThongTinPMuon(arrPMuon);
	}
	if (choicePMuon == 2) {
		MuonSach(arrPMuon);
	}
	if (choicePMuon == 3) {
		TraSach(arrPMuon);
	}
	if (choicePMuon == 4) {
		system("cls");
		ManHinhMenuLuaChon();
	}
}
