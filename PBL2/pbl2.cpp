#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <locale>

#include <SFML/Graphics.hpp>

#include "Graphics\textbox.h"
#include "Graphics\button.h"


#include "Header\San.h"
#include "Header\KhachHang.h"
#include "Header\LinkList.h"
#include "Cpp\LinkList.cpp"

//#define GIA_T 100
//#define GIA_V 200


using namespace std;



class LichDatSan {
private:
    int maDatSan;
    int maSanBong;
    int maKhachHang;
    string thoiGianBatDau;
    string thoiGianKetThuc;
    string trangThai;    //0:Da huy, 1:Dang duoc dat

public:
    LichDatSan(int maDat, int maSan, int maKH, string batDau, string ketThuc, string trangThai)
        : maSanBong(maSan), maKhachHang(maKH), thoiGianBatDau(batDau), thoiGianKetThuc(ketThuc), trangThai(trangThai) {}
	~LichDatSan(){
	}
    void datSan(int maDat, int maSan, int maKH, string batDau, string ketThuc, string trangThaiMoi) {
        maDatSan = maDat;
        maSanBong = maSan;
        maKhachHang = maKH;
        thoiGianBatDau = batDau;
        thoiGianKetThuc = ketThuc;
        trangThai = trangThaiMoi;
    }

    void huyDatSan() {
        trangThai = "Da Huy";
    }

    void hienThiLichDatSan() {
        cout << "Ma Dat San: " << maDatSan << "\nMa San Bong: " << maSanBong
             << "\nMa Khach Hang: " << maKhachHang << "\nThoi Gian Bat Dau: " << thoiGianBatDau
             << "\nThoi Gian Ket Thuc: " << thoiGianKetThuc << "\nTrang Thai: " << trangThai << endl;
    }
};


class ThanhToan {
private:
    int maThanhToan;
    int maDatSan;
    double tongChiPhi;
    string phuongThucThanhToan;

public:
    ThanhToan(int maTT, int maDat, double chiPhi, string phuongThuc)
        : maThanhToan(maTT), maDatSan(maDat), tongChiPhi(chiPhi), phuongThucThanhToan(phuongThuc) {}

    double tinhChiPhi(double giaThue, double thoiGianThue) {
        return giaThue * thoiGianThue;
    }

    void thucHienThanhToan() {
        cout << "Thanh toan hoan tat voi tong chi phi: " << tongChiPhi << " bang " << phuongThucThanhToan << endl;
    }

    void inHoaDon() {
        cout << "Ma Thanh Toan: " << maThanhToan << "\nMa Dat San: " << maDatSan
             << "\nTong Chi Phi: " << tongChiPhi << "\nPhuong Thuc Thanh Toan: " << phuongThucThanhToan << endl;
    }
};


int nhap(){
	int n;
	cout<<"Nhap lua chon:";
	cin>>n;
	return n;
}


void ghiFile(fstream& file,LinkedList<San> A){
		file.close();
		file.open("D:\\cpp\\PBL2\\Data\\San.csv",ios::trunc|ios::out);
		for(int i=1;i<=A.size();i++){
			file<<A[i].thongTinSan()<<"\n";
		}
		file.close();
}

void ghiFile(fstream& file2,LinkedList<KhachHang> B){
		file2.close();
		file2.open("D:\\cpp\\PBL2\\Data\\KhachHang.csv",ios::trunc|ios::out);
		for(int i=1;i<=B.size();i++){
			file2<<B[i].ThongTinKH()<<"\n";
		}
		file2.close();
}

void docFile(fstream& file,LinkedList<San> &A){
	string line;
	while (getline(file, line)) {
            stringstream ss(line);  
            string loaiSan, trangThaiStr;
            int idStr,giaStr;
            ss>>idStr;
            ss.ignore();
            getline(ss, loaiSan, ',');
            ss>>giaStr;
            ss.ignore();
            getline(ss, trangThaiStr);
            bool trangThai = (trangThaiStr == "TRUE");
    		San a(idStr,loaiSan,giaStr,trangThai);
    		A.add(a);
        }
}

void docFile(fstream& file2,LinkedList<KhachHang> &B){
	string line2;
    while (getline(file2, line2)) {
            stringstream ss2(line2);  
            string tenKH,sdt,mail;
            int MaKH;
            ss2>>MaKH;
            ss2.ignore();
            getline(ss2, tenKH, ',');
            getline(ss2, sdt, ',');
            getline(ss2, mail);
    		KhachHang a(MaKH,tenKH,sdt,mail);
    		B.add(a);
        }
}


void GiaodienSan(fstream& file,LinkedList<San> &A){
	const int Top=100;
	const int Bot=550;
	const float Left =125;
    int Selected = 0;
	
	RenderWindow San(VideoMode(960, 700), "San", Style::Default);
	Font a;
	a.loadFromFile("Font\\arial.ttf");
	
	Button BThemSan("+",Vector2f(70.f, 70.f),50,Color::Blue,Color::White,{800,100},&a,{820,103});
	Button BXoaSan("-",Vector2f(70.f, 70.f),50,Color::Blue,Color::White,{800,200},&a,{827,200});
	Button BLen("Up",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,300},&a,{830,310});
	Button BXuong("Down",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,400},&a,{812,410});
	Button BSuaThongTin("Sua Thong Tin San",Vector2f(300.f, 70.f),30,Color::Blue,Color::White,{500,600},&a,{520,610});
	Button BSuaTrangThai("Sua Trang Thai San",Vector2f(300.f, 70.f),30,Color::Blue,Color::White,{100,600},&a,{120,610});
	
	RectangleShape WhiteBoard({650,Bot-Top});
	WhiteBoard.setPosition(100,Top);
	WhiteBoard.setFillColor(Color::White);
	
	LinkedList<Button> BSan;
	for(int i=1;i<=A.size();i++){
		Button b(A[i].thongTinSan2(),{600,40},20,Color::Black,Color::White,{Left,float(120+50*(i-1))},&a,{Left,float(120+50*(i-1))});
		BSan.add(b);
	}
	
	while (San.isOpen()) {
        Event event;
        while (San.pollEvent(event)) {
            if (event.type == Event::Closed) {
            	ghiFile(file,A);
                San.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(!BThemSan.isMouseOver(San)){
           	 		}
           	 		if(!(BSan[A.size()].getTop()>Top && BSan[A.size()].getBot()<Bot)){
           	 			if(!BXuong.isMouseOver(San)){
           	 				for(int i=1;i<=A.size();i++){
								BSan[i].setPosition({Left,float(BSan[i].getTop()-Bot+Top+50)});
							}
						}
					}
					if(!(BSan[1].getTop()>Top && BSan[1].getBot()<Bot)){
           	 			if(!BLen.isMouseOver(San)){
           	 				for(int i=1;i<=A.size();i++){
								BSan[i].setPosition({Left,float(BSan[i].getTop()+Bot-Top-50)});
							}
						}
					}
           	 		for(int i=1;i<=A.size();i++){
           	 			if(!BSan[i].isMouseOver(San)){
           	 				if(Selected!=i){
           	 					if(Selected!=0) BSan[Selected].setBackColor(Color::Black);
           	 					Selected=i;
								BSan[i].setBackColor(Color::Red);
							}
							else{
								Selected=0;
								BSan[i].setBackColor(Color::Black);
							}
						}
					}
//					if(!BXoaSan.isMouseOver(San)){
////						Vector2f p=BSan[Selected].getPosition();
////						BSan[A.size()].setPosition(p);
//						for(int i=Selected+1;i<=A.size();i++){
//							BSan[i].setPosition({Left,BSan[i].getTop()-50});
//						}
//						A.del(Selected-1);
//						BSan.del(Selected-1);
//					}
				}
			}
        }
		San.clear();
		BThemSan.drawTo(San);
		BXoaSan.drawTo(San);
		BLen.drawTo(San);
		BXuong.drawTo(San);
		BSuaThongTin.drawTo(San);
		BSuaTrangThai.drawTo(San);
		San.draw(WhiteBoard);
		for(int i=1;i<=A.size();i++){
			if(BSan[i].getTop()>Top && BSan[i].getBot()<Bot) BSan[i].drawTo(San);
		}
        San.display();
    }
}

void run(){
	setlocale(LC_ALL, "");
	
	LinkedList<San> A;
    
	fstream file;
	file.open("D:\\cpp\\PBL2\\Data\\San.csv",ios::in|ios::out);
	docFile(file,A);
        
    LinkedList<KhachHang> B;
    
    fstream file2;
    file2.open("D:\\cpp\\PBL2\\Data\\KhachHang.csv",ios::in|ios::out);
    docFile(file2,B);
	
	RenderWindow MENU(VideoMode(960, 700), "Main Menu", Style::Default);
    
    Font a;
    a.loadFromFile("Font\\arial.ttf");
    
    Button BSan("Sân",Vector2f(250.f, 25.f),15,Color::Blue,Color::White,{350,250},&a,{460,250});
	Button BKhachHang("Khách Hàng",Vector2f(250.f, 25.f),15,Color::Blue,Color::White,{350,300},&a,{440,300});
	Button BDatSan("Dat san",Vector2f(250.f, 25.f),15,Color::Blue,Color::White,{350,350},&a,{450,350});
	Button BThanhToan("ThanhToan",Vector2f(250.f, 25.f),15,Color::Blue,Color::White,{350,400},&a,{440,400});
	Button BThoat("Thoat",Vector2f(250.f, 25.f),15,Color::Blue,Color::White,{350,450},&a,{455,450});
	
	
    while (MENU.isOpen()) {
        Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
           	if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(!BSan.isMouseOver(MENU)){
           	 			GiaodienSan(file,A);
					} 
					else if(!BKhachHang.isMouseOver(MENU)){
           	 			
					} 
					else if(!BDatSan.isMouseOver(MENU)){
           	 			
					} 
					else if(!BThanhToan.isMouseOver(MENU)){
           	 			
					} 
					else if(!BThoat.isMouseOver(MENU)){
           	 			
					} 
				}
			}
        }
		MENU.clear();
		BSan.drawTo(MENU);
		BKhachHang.drawTo(MENU);
		BDatSan.drawTo(MENU);
		BThanhToan.drawTo(MENU);
		BThoat.drawTo(MENU);
        MENU.display();
    }
    
    file.close();
	file2.close();
}

int main(){
	run();
	return 0;
}
