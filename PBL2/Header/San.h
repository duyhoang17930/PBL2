#ifndef San_h
#define San_h
#include <iostream>
#include <string>
using namespace std;
#define GIA_T 100
#define GIA_V 200
class San{
private:
    int tenSan;	
    string loaiSan;
    int giaThue;
    bool tinhTrang; // true: available, false: not available
public:
	
    San(int =-1, string ="San5", int =GIA_T, bool =true);
	~San();
	San(const San &,int );
    void hienThiThongTin();
	void suaThongTin(int);
	static San themSan(int);
	static int xoaSan();
    string thongTinSan();
    string thongTinSan2();
	bool setTT();
	static int doiTT(int);
	void doiTen(int);
};
#endif
