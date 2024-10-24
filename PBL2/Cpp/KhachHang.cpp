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

string KhachHang::ThongTinKH(){
    	return to_string(maKhachHang)+","+ten+","+soDienThoai+","+email;
	}
	
string KhachHang::ThongTinKH2(){
	return to_string(maKhachHang)+"\t\t\t"+ten+"\t\t\t"+soDienThoai+"\t\t\t"+email;
}

int KhachHang::getTen(){
	return maKhachHang;
}
	
void KhachHang::doiTen(int i){
	this->maKhachHang=i;
}

void KhachHang::setTen(string ten){
	this->ten=ten;
}

void KhachHang::setSdt(string sdt){
	soDienThoai=sdt;
}

void KhachHang::setEmail(string email){
	this->email=email;
}
