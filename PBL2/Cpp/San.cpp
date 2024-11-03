#include "San.h"
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

void San::suaThongTin() {
		if(loaiSan=="San5"){
			loaiSan="San7";
			giaThue=GIA_V;
		}
		else{
			loaiSan="San5";
			giaThue=GIA_T;
		}
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
	
	
bool San::setTT(){
		return tinhTrang=tinhTrang?false:true;
	}
bool San::getTT(){
	return tinhTrang;
}


int San::getTen(){
	return tenSan;
}

void San::doiTen(int i){
	this->tenSan=i;
}
