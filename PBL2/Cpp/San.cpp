#include "D:\cpp\PBL2\Header\San.h"
#include <string>
#include <iostream>
using namespace std;

#define GIA_5 100
#define GIA_7 200


San::San(int ten, string loai, int gia, bool trangThai)
        : tenSan(ten), loaiSan(loai), giaThue(gia), tinhTrang(trangThai) {};
	
	
San::~San(){};
San::San(const San &san,int k){
		this->tenSan=k;
		this->loaiSan=san.loaiSan;
		this->giaThue=san.giaThue;
		this->tinhTrang="TRUE";
	}
void San::hienThiThongTin() {
        cout << "Ten San: " << tenSan << "\nLoai San: " << loaiSan 
             << "\nGia Thue: " << giaThue 
             << "\nTinh Trang: " << (tinhTrang ? "San Co San" : "San Khong The Dat") << endl;
    }
void San::suaThongTin(int tendoi) {
		int loaidoi;
		cout<<"\nNhap loai san can doi(San5:0, San7:1):";
		cin>>loaidoi;
		int gia=loaidoi?GIA_7:GIA_5;
		string loai=loaidoi?"San7":"San5";
		
        tenSan = tendoi;
        loaiSan = loai;
        giaThue = gia;
        tinhTrang = true;
        cout<<"Doi thanh cong\n";
	}
	
San San::themSan(int SoSan){
	int loaithem;
	San b;
	cout<<"Nhap loai san can them(San5:0, San7:1):";
	cin>>loaithem;
	if(loaithem!=0 && loaithem!=1){
		cout<<"Khong hop le\n";
		exit(1);
	}
	else{
		string loai=loaithem?"San7":"San5";
		int gia=loaithem?GIA_7:GIA_5;
        San a(SoSan,loai,gia,true);
        b=a;
		cout<<"Them san thanh cong!\n";
	}
	return b;
}

int San::xoaSan(){
	int k;
	cout<<"Nhap san can xoa: ";
	cin>>k;
	return k;
}
	
string San::thongTinSan(){
    	string ten=to_string(tenSan);
    	string gia=(giaThue==GIA_5?to_string(GIA_5):to_string(GIA_7));
    	string tt=(tinhTrang?"TRUE":"FALSE");
		return ten+","+loaiSan+","+gia+","+tt;
	}
	
string San::thongTinSan2(){
    	string ten=to_string(tenSan);
    	string gia=(giaThue==GIA_5?to_string(GIA_5):to_string(GIA_7));
    	string tt=(tinhTrang?"Chua duoc dat":"Da duoc dat");
		return ten+"\t\t\t\t\t"+loaiSan+"\t\t\t\t\t"+gia+"\t\t\t\t\t"+tt;
	}
	
int San::doiTT(int i){
	int k;
   	cout<<"Nhap san can doi trang thai: ";
   	cin>>k;
   	if(k<1||k>i){
   		cout<<"Khong co san nay\n";
   		return 0;
	}
	return k;
}
	
bool San::setTT(){
		return tinhTrang=tinhTrang?false:true;
	}

void San::doiTen(int i){
	this->tenSan=i;
}
