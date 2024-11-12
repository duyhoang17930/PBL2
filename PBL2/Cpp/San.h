#ifndef San_h
#define San_h
#include <iostream>
#include <string>
using namespace std;

//int GIA_5 = 160000;
//int GIA_7 = 300000;

class San{
private:
    int tenSan;	
    string loaiSan;
    int giaThue;
    bool tinhTrang; // true: available, false: not available
public:
	
    San(int =-1, string ="San5", int =160000, bool =true);
	~San();
	San(const San &,int );
	void suaThongTin();
    string thongTinSan();
    string thongTinSan2();
	bool setTT();
	bool getTT();
	int getTen();
	void doiTen(int);
	string getLoaiSan();
	
};
#endif
