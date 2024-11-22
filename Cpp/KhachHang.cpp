#include "KhachHang.h"
#include <string>
#include <iostream>
using namespace std;



KhachHang::KhachHang(int maKhachHang,string tenKH, string sdt)
        :maKhachHang(maKhachHang), ten(tenKH), soDienThoai(sdt) {};
	
KhachHang::~KhachHang(){
	};
KhachHang::KhachHang(const KhachHang &a,int k){
		this->maKhachHang=k;
		this->ten=a.ten;
		this->soDienThoai=a.soDienThoai;
	}

string KhachHang::ThongTinKH(){
    	return to_string(maKhachHang)+","+ten+","+soDienThoai;
	}
	
string KhachHang::ThongTinKH2(){
	return to_string(maKhachHang)+"\t\t\t"+ten+"\t\t\t\t\t\t\t\t"+soDienThoai;
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

string KhachHang::getSdt(){
	return soDienThoai;
}

string KhachHang::getTenKh(){
	return ten;
}



