#ifndef KhachHang_h
#define KhachHang_h
#include <iostream>
#include <string>

using namespace std;

class KhachHang {
private:
	int maKhachHang;
    string ten;
    string soDienThoai;
    string email;
	
public:
    KhachHang(int =-1,string ="", string ="", string ="");
	~KhachHang();
	KhachHang(const KhachHang &,int );
    string ThongTinKH();
    string ThongTinKH2();
    int getTen();
    void doiTen(int);
    void setTen(string);
	void setSdt(string);
	void setEmail(string);
};
#endif
