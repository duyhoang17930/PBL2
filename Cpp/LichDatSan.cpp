#include "LichDatSan.h"
#include <string>



LichDatSan::LichDatSan(Day batDau,Day ketThuc,string trangThai,int maDat,int maSan,int maKH):thoiGianBatDau(batDau), thoiGianKetThuc(ketThuc), tt(trangThai), maDatSan(maDat), maSanBong(maSan), maKhachHang(maKH){};

string LichDatSan::getSLds(){
	return to_string(maDatSan)+","+to_string(maSanBong)+","+to_string(maKhachHang)+","+thoiGianBatDau.getSDay()+","+thoiGianKetThuc.getSDay()+","+tt;
}

string LichDatSan::getLds2(){
	return "San "+to_string(maSanBong)+" - "+thoiGianBatDau.getSDay()+" - "+thoiGianKetThuc.getSDay()+" - "+tt;
}

int LichDatSan::getMaDatSan(){
	return maDatSan;
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

int LichDatSan::tongGia(int gia){
	float G=gia;

	::Time tN(TIME_NIGHT);
	::Time Mid;
	float time=0;
	if(thoiGianKetThuc.getTime().getHour()<TIME_NIGHT){
		Mid=thoiGianKetThuc.getTime()-thoiGianBatDau.getTime();
		time=Mid.getHour()+float(Mid.getMinute())/60;
	}
	else if(thoiGianBatDau.getTime().getHour()>=TIME_NIGHT){
		Mid=thoiGianKetThuc.getTime()-thoiGianBatDau.getTime();
		time=Mid.getHour()+float(Mid.getMinute())/60;
		time*=(1+Increase);
	}
	else{
		Mid=tN-thoiGianBatDau.getTime();
		time=Mid.getHour()+float(Mid.getMinute())/60;
		Mid=thoiGianKetThuc.getTime()-tN;
		time+=(Mid.getHour()+float(Mid.getMinute())/60)*(1+Increase);
	}
	return time*G;
}
