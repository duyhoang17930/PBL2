#include "D:\cpp\PBL2\Header\KhachHang.h"
#include <string>
#include <iostream>
using namespace std;



KhachHang::KhachHang(int maKhachHang,string tenKH, string sdt, string mail)
        :maKhachHang(maKhachHang), ten(tenKH), soDienThoai(sdt), email(mail) {};
	
KhachHang::~KhachHang(){
	};
KhachHang::KhachHang(const KhachHang &a,int k){
		this->maKhachHang=k;
		this->ten=a.ten;
		this->soDienThoai=a.soDienThoai;
		this->email=a.email;
	}
	
void KhachHang::hienThiThongTin() {
        cout <<"Ma Khach Hang: "<< maKhachHang << "\nTen Khach Hang: " << ten << "\nSo Dien Thoai: " << soDienThoai
             << "\nEmail: " << email << endl<<endl;
    }

void KhachHang::suaThongTin(int k) {
	
	string tenDoi,sdtDoi,emailDoi;
	cout<<"Nhap ten khach hang can doi (Nhap 0 de thoat):";
	cin>>tenDoi;
	if(tenDoi=="0") return;
	cout<<"Nhap sdt khach hang can doi (Nhap 0 de thoat):";
	cin>>sdtDoi;
	if(sdtDoi=="0") return;
	cout<<"Nhap mail khach hang can doi (Nhap 0 de thoat):";
	cin>>emailDoi;
	if(emailDoi=="0") return;
	
    maKhachHang=k;
    ten = tenDoi;
    soDienThoai = sdtDoi;
    email = emailDoi;
}

KhachHang KhachHang::themKhachHang(int k) {
			string tenThem,sdtThem,emailThem;
			cout<<"Nhap ten khach hang can them (Nhap 0 de thoat):";
			cin>>tenThem;
			if(tenThem=="0") exit(1) ;
			cout<<"Nhap sdt khach hang can them (Nhap 0 de thoat):";
			cin>>sdtThem;
			if(sdtThem=="0") exit(1) ;
			cout<<"Nhap mail khach hang can them (Nhap 0 de thoat):";
			cin>>emailThem;
			if(emailThem=="0") exit(1) ;
			KhachHang a(k,tenThem,sdtThem,emailThem);
			return a;

    }

int KhachHang::xoaKhachHang() {
		int k;
		cout<<"Nhap ma khach hang can xoa :";
		cin>>k;
		return k;
    }
string KhachHang::ThongTinKH(){
    	return to_string(maKhachHang)+","+ten+","+soDienThoai+","+email;
	}
	
void KhachHang::doiTen(int i){
	this->maKhachHang=i;
}

