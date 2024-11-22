#ifndef core_h
#define core_h

#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <locale>

#include <SFML/Graphics.hpp>
#include "..\Graphics\textbox.h"
#include "..\Graphics\button.h"

#include "San.h"
#include "KhachHang.h"
#include "LichDatSan.h"
#include "time.h"
#include "date.h"
#include "ThanhToan.h"
#include "LinkList.h"
#include "LinkList.cpp"

#define OPEN_TIME 6
#define CLOSE_TIME 22

extern int MaxSan,MaxKH,MaxLDS,MaxTT;

extern const int Top;
extern const int Bot;
extern const int Left;

extern int GIA_5,GIA_7;

using namespace std;
using namespace sf;


Sprite loadSprite(Texture&,const string&,Vector2f);

/*------------------------------------doc & ghi file---------------------------------------------*/
void ghiFile(fstream &, LinkedList<San> );
void ghiFile(fstream &, LinkedList<KhachHang> );
void ghiFile(fstream &);
void ghiFile(fstream &, LinkedList<LichDatSan>);
void ghiFile(fstream &, LinkedList<ThanhToan>);
void docFile(fstream &, LinkedList<San>&);
void docFile(fstream &, LinkedList<KhachHang>&);
void docFile(fstream &, LinkedList<LichDatSan>&);
void docFile(fstream &, LinkedList<ThanhToan>&);

/*----------------giao dien thanh toan, saveImage, giao dien khach hang dat san-------------------*/
int GD_KH_DatSan(Font&, LinkedList<KhachHang>&, fstream&, string&);
void GetDL_GDThanhToan(LinkedList<LichDatSan>&, Date, int, int&, string&, string&, string&, int&, ::Time);
void SaveImageToFile(RenderWindow &,Day &);
int GDThanhToan(fstream&, LinkedList<ThanhToan>&, Font&, LinkedList<LichDatSan>&, fstream&, int, Date, LinkedList<KhachHang>&, LinkedList<San>&, int, string, fstream&);

/*-------------------------------------giao dien dat san------------------------------------------*/
void setColor_GDDatSan(LinkedList<Button>&, LinkedList<Button>&, int, int);
void setAvailable_Draw_GDDatSan(LinkedList<::Time>, LinkedList<Button>&, LinkedList<Button>&, RenderWindow&,LinkedList<Sprite> &);
void PrintTT_GDDatSan(LinkedList<LichDatSan>&, ::Time, LinkedList<KhachHang>&, LinkedList<Button>&, int, Date);
void Bt_Up_Down_GDDatSan(LinkedList<Button>&, LinkedList<::Time>&, Button&, Button&, LinkedList<Button>&, RenderWindow&,LinkedList<Sprite> &);
void get_SelectedIJ_GDDatSan(LinkedList<Button>&, LinkedList<Button>&, RenderWindow&, int&, int&);
void BtDatSan_GDDatSan(int&, int&, ::Time, LinkedList<Button>&, LinkedList<LichDatSan>&, fstream&, fstream&, int&, Font&, LinkedList<KhachHang>&, fstream&, Date&);
void BtHuy_GDDatSan(int&, int&, ::Time, LinkedList<Button>&, LinkedList<LichDatSan>&, fstream&, Date&);
void BtThanhToan_GDDatSan(int&, int&, LinkedList<ThanhToan>&, LinkedList<Button>&, LinkedList<LichDatSan>&, fstream&, Date&, fstream&, fstream&, int&, LinkedList<KhachHang>&, LinkedList<San>&, Font&);
void GDDatSan(Font&, LinkedList<LichDatSan>&, LinkedList<KhachHang>&, RenderWindow&, int, fstream&, fstream&, fstream&, fstream&, LinkedList<ThanhToan>&, LinkedList<San>&);

/*--------------------------------------giao dien san---------------------------------------------*/
int GDThemSan(Font&, LinkedList<San>&);
void Bt_Up_Down_GDSan(LinkedList<San>&, LinkedList<Button>&, Button&, Button&, RenderWindow&,LinkedList<Sprite> &);
void setSelected_setColor_GDSan(LinkedList<San>&, LinkedList<Button>&, RenderWindow&, int&);
void BXoa_GDSan(LinkedList<San>&, LinkedList<Button>&, fstream&, int&,LinkedList<Sprite> &);
void BThemSan_GDSan(Font&, LinkedList<San>&, LinkedList<Button>&, fstream&, fstream&,LinkedList<Sprite> &);
void BSuaThongTin_GDSan(LinkedList<San>&, LinkedList<Button>&, fstream&, int&);
void BSua_GDSan(LinkedList<San>&, LinkedList<Button>&, fstream&, int&);
void drawButton_GDSan(LinkedList<Button>&, RenderWindow&,LinkedList<Sprite> &);
void GDSan(fstream&, LinkedList<San>&, RenderWindow&, LinkedList<LichDatSan>&, LinkedList<KhachHang>&, fstream&, fstream&, fstream&, fstream&, LinkedList<ThanhToan>&);

/*---------------------------------giao dien lich su dat san---------------------------------------*/
int GDThemKH(Font&, string&, string&);
void createLSDS_GDLichSuDatSan(int&, LinkedList<Button>&, LinkedList<LichDatSan>&, int, Font&);
void Bt_Up_Down_GDLichSuDatSan(int&, LinkedList<Button>&, Button&, Button&, RenderWindow&,LinkedList<Sprite> &);
void drawButton_GDLichSuDatSan(LinkedList<Button>&, RenderWindow&, int&,LinkedList<Sprite> &);
void GDLichSuDatSan(Font&, int, LinkedList<LichDatSan>&, RenderWindow&);

/*-------------------------------------giao dien khach hang-------------------------------------------*/
void Bt_Up_Down_GDKhachHang(LinkedList<KhachHang>&, LinkedList<Button>&, Button&, Button&, RenderWindow&);
void setSelected_setColor_GDKhachHang(LinkedList<KhachHang>&, LinkedList<Button>&, int&, RenderWindow&);
void BXoa_GDKhachHang(LinkedList<KhachHang>&, LinkedList<Button>&, int&, fstream&);
void BThem_GDKhachHang(Font&, LinkedList<KhachHang>&, LinkedList<Button>&, fstream&, fstream&,LinkedList<Sprite> &,Texture &);
void BSua_GDKhachHang(Font&, LinkedList<KhachHang>&, LinkedList<Button>&, fstream&, int&);
void setAvailable_GDKhachHang(LinkedList<Button>&, RenderWindow&,LinkedList<Sprite> &);
void GDKhachHang(fstream&, LinkedList<KhachHang>&, RenderWindow&, fstream&, LinkedList<LichDatSan>&);

/*----------------------------------giao dien thanh toan thong ke------------------------------------*/
void getDL_GD_TT_ThongKe(LinkedList<LichDatSan>&, int&, LinkedList<ThanhToan>&, string&, string&, string&, int&, int&);
void GD_TT_ThongKe(Font&, LinkedList<LichDatSan>&, LinkedList<San>&, LinkedList<KhachHang>&, int, LinkedList<ThanhToan>&);

/*--------------------------------------giao dien thong ke------------------------------------------*/
void Bt_Up_Down_GDThongKe(LinkedList<Button>&, RenderWindow&, Button&, Button&,LinkedList<Sprite> &);
void setSelected_setColor_GDThongKe(LinkedList<Button>&, RenderWindow&, int&);
void TKNam_GDThongKe(int&, string&, LinkedList<ThanhToan>&, LinkedList<LichDatSan>&, LinkedList<Button>&, int&, int&, Font&,LinkedList<Sprite> &,Texture &);
void TKThang_GDThongKe(int&, string&, int&, string&, LinkedList<ThanhToan>&, LinkedList<LichDatSan>&, LinkedList<Button>&, int&, int&, Font&,LinkedList<Sprite> &,Texture &);
void TKNgay_GDThongKe(int&, string&, int&, string&, int&, string&, LinkedList<ThanhToan>&, LinkedList<LichDatSan>&, LinkedList<Button>&, int&, int&, Font&,LinkedList<Sprite> &,Texture &);
void setAvailable_GDThongKe(LinkedList<Button>&, RenderWindow&);
void GDThongKe(Font&, RenderWindow&, LinkedList<ThanhToan>&, LinkedList<LichDatSan>&, LinkedList<San>&, LinkedList<KhachHang>&,LinkedList<Sprite> &);

/*------------------------------------giao dien doi gia thue------------------------------------------*/
int nhapGia_GDDoiGiaThue(RenderWindow&,Font&);
void GDDoiGiaThue(Font&, fstream&,fstream&,LinkedList<San>&);

/*----------------------------------------giao dien chinh--------------------------------------------*/
void docFile_run(LinkedList<San>&, LinkedList<KhachHang>&, LinkedList<LichDatSan>&, LinkedList<ThanhToan>&, fstream&, fstream&, fstream&, fstream&, fstream&);
void run();

#endif
