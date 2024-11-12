#include "ThanhToan.h"

ThanhToan::ThanhToan(int IdTT,int IdSan,int tt):IdThanhToan(IdTT),IdLichDatSan(IdSan),ThanhTien(tt){
}

string ThanhToan::getSTT(){
	return to_string(IdThanhToan) + "," + to_string(IdLichDatSan) + "," + to_string(ThanhTien);
}

string ThanhToan::getSTT2(){
	return to_string(IdLichDatSan) + "\t\t\t\t\t\t\t\t\t" + to_string(ThanhTien);
}

int ThanhToan::getIdLDS(){
	return IdLichDatSan;
}

int ThanhToan::getIdTT(){
	return IdThanhToan;
}

int ThanhToan::getTT(){
	return ThanhTien;
}
