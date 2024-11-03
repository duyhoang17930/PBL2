#ifndef LichDatSan_h
#define LichDatSan_h

#include <string>
#include "DTime.h"

class LichDatSan {
private:
    int maDatSan;
    int maSanBong;
    int maKhachHang;
    Day thoiGianBatDau;
    Day thoiGianKetThuc;
    string tt; 
    

public:
    LichDatSan(Day batDau, Day ketThuc, string trangThai,int maDat=-1, int maSan=-1, int maKH=-1);
	~LichDatSan(){}
	int getMaSanBong();
	int getMaKhachHang();
	Day getStTime();
	Day getEnTime();
	string getTT();
	string getSLds();
	void setMaDatSan(int mDS);
	void setMaKhachHang(int mKH);
	void setStTime(Day StT);
	void setEnTime(Day EnT);
	void setTT(string tt);
};

#endif
