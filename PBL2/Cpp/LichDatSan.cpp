#include "LichDatSan.h"
#include <string>

LichDatSan::LichDatSan(Day batDau,Day ketThuc,string trangThai,int maDat,int maSan,int maKH):thoiGianBatDau(batDau), thoiGianKetThuc(ketThuc), tt(trangThai), maDatSan(maDat), maSanBong(maSan), maKhachHang(maKH){};

string LichDatSan::getSLds(){
	return to_string(maDatSan)+","+to_string(maSanBong)+","+to_string(maKhachHang)+","+thoiGianBatDau.getSDay()+","+thoiGianKetThuc.getSDay()+","+tt;
}

int LichDatSan::getMaSanBong(){
	return maSanBong;
}

int LichDatSan::getMaKhachHang(){
	return maKhachHang;
}

Day LichDatSan::getStTime(){
	return thoiGianBatDau;
}

Day LichDatSan::getEnTime(){
	return thoiGianKetThuc;
}

string LichDatSan::getTT(){
	return tt;
}

void LichDatSan::setMaDatSan(int mDS){
	this->maDatSan=mDS;
}

void LichDatSan::setMaKhachHang(int mKH){
	this->maKhachHang=mKH;
}

void LichDatSan::setStTime(Day StT){
	this->thoiGianBatDau=StT;
}

void LichDatSan::setEnTime(Day EnT){
	this->thoiGianKetThuc=EnT;
}

void LichDatSan::setTT(string tt){
	this->tt=tt;
}
