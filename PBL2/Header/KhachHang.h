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
    void hienThiThongTin() ;
    void suaThongTin(int ) ;
    static KhachHang themKhachHang(int);
    static int xoaKhachHang();
    string ThongTinKH();
    void doiTen(int);
};
#endif
