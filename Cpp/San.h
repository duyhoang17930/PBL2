#ifndef San_h
#define San_h
#include <iostream>
#include <string>
using namespace std;


class San{
private:
    int tenSan;	
    string loaiSan;
    int giaThue;
    bool tinhTrang; // true: available, false: not available
public:
	
    San(int =-1, string ="San5", int =0, bool =true);
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
	void setLoaiSan(string);
	void setGia(int);
	int getGia();
	
};
#endif
