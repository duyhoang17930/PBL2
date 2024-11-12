#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <locale>

#include <SFML/Graphics.hpp>

#include "Graphics\textbox.h"
#include "Graphics\button.h"


#include "Cpp\San.h"
#include "Cpp\KhachHang.h"
#include "Cpp\LichDatSan.h"
#include "Cpp\time.h"
#include "Cpp\date.h"
#include "Cpp\ThanhToan.h"
#include "Cpp\LinkList.h"
#include "Cpp\LinkList.cpp"

#define OPEN_TIME 6
#define CLOSE_TIME 22


int MaxSan,MaxKH,MaxLDS,MaxTT;

using namespace std;

const int Top=100;
const int Bot=550;
const float Left =125;


void run();
int GDThemKH(Font &a,string &tenKH,string &sdt);


void ghiFile(fstream& file,LinkedList<San> A){
		file.close();
		file.open("Data\\San.csv",ios::trunc|ios::out);
		for(int i=1;i<=A.size();i++){
			file<<A[i].thongTinSan()<<"\n";
		}
		file.close();
}

void ghiFile(fstream& file2,LinkedList<KhachHang> B){
		file2.close();
		file2.open("Data\\KhachHang.csv",ios::trunc|ios::out);
		for(int i=1;i<=B.size();i++){
			file2<<B[i].ThongTinKH()<<"\n";
		}
		file2.close();
}

void ghiFile(fstream& file4){
		file4.close();
		file4.open("Data\\MaxSKH.csv",ios::trunc|ios::out);
		file4<<MaxSan<<"\n"<<MaxKH<<"\n"<<MaxLDS<<"\n"<<MaxTT;
		file4.close();
}

void ghiFile(fstream& file3,LinkedList<LichDatSan> Lds){
	file3.close();
	file3.open("Data\\LichDatSan.csv",ios::trunc|ios::out);
	for(int i=1;i<=Lds.size();i++){
		file3<<Lds[i].getSLds()<<"\n";
	}
	file3.close();
}

void ghiFile(fstream& file5, LinkedList<ThanhToan> TToan){
	file5.close();
	file5.open("Data\\ThanhToan.csv",ios::trunc|ios::out);
	for(int i=1;i<=TToan.size();i++){
		file5<<TToan[i].getSTT()<<"\n";
	}
	file5.close();
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
            string tenKH,sdt;
            int MaKH;
            ss2>>MaKH;
            ss2.ignore();
            getline(ss2, tenKH, ',');
            getline(ss2, sdt, ',');
    		KhachHang a(MaKH,tenKH,sdt);
    		B.add(a);
        }
}

void docFile(fstream& file3,LinkedList<LichDatSan> &Lds){
	string line3;
    while (getline(file3, line3)) {
    		int maDS,maSan,maKH;
    		string BD,KT;
            string TT;
            stringstream ss3(line3);
            ss3>>maDS;
            ss3.ignore();
            ss3>>maSan;
            ss3.ignore();
            ss3>>maKH;
            ss3.ignore();
            getline(ss3, BD, ',');
            getline(ss3, KT, ',');
            getline(ss3, TT);
    		LichDatSan lds(Day(BD),Day(KT),TT,maDS,maSan,maKH);
    		Lds.add(lds);
        }
}

void docFile(fstream& file5,LinkedList<ThanhToan> &TToan){
	string line5;
    while (getline(file5, line5)) {
            stringstream ss5(line5);
            
    		int IdSan,IdTT,TTien;
			ss5>>IdTT;
		    ss5.ignore();
		    ss5>>IdSan;
		    ss5.ignore();
		    ss5>>TTien;
		    ThanhToan tt(IdTT,IdSan,TTien);
		    TToan.add(tt);
     }
}

int GD_KH_DatSan(Font &a,LinkedList<KhachHang> &B,fstream& file2, string &SDT){
	RenderWindow NhapSdt(VideoMode(600, 400), "ThemKH", Style::Default);
	
	Textbox TBSdt(20,Color::White,false,&a,{170,200});
	
	Button BSdt("",Vector2f(300.f, 40.f),30,Color::Blue,Color::White,{170,200},&a,{0,0});
	Button BTSdt("Nhap sdt khach hang",Vector2f(300.f, 40.f),30,Color::Black,Color::White,{170,100},&a,{180,100});
	Button BSubmit("Xac nhan",Vector2f(165.f, 70.f),30,Color::Blue,Color::White,{50,300},&a,{70,310});	
	Button BThemKH("Them Khach Hang",Vector2f(310.f, 70.f),30,Color::Blue,Color::White,{250,300},&a,{275,310});
	Button BHienThi("",Vector2f(300.f, 40.f),30,Color::Black,Color::White,{150,240},&a,{155,250});
	
	TBSdt.setLimit(true,10);
	
	while (NhapSdt.isOpen()) {
        Event event;
        while (NhapSdt.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                NhapSdt.close(); // Ðóng c?a s? khi nh?n nút dóng
                return 0;
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
					if(!BSdt.isMouseOver(NhapSdt)) TBSdt.setSelected(true);
					else TBSdt.setSelected(false);
					if(!BSubmit.isMouseOver(NhapSdt)){
						int MaKH=0;
						for(int i=1;i<=B.size();i++){
							if(B[i].getSdt()==TBSdt.getText()){
								MaKH=B[i].getTen();
							}
						}
						if(MaKH!=0){
							SDT=TBSdt.getText();
							return MaKH;
						} 
						else BHienThi.setText("Khong tim thay khach hang");
					}
					if(!BThemKH.isMouseOver(NhapSdt)){
						string ten,sdt;
						if(GDThemKH(a,ten,sdt)){
							KhachHang kh1(++MaxKH,ten,sdt);
							B.add(kh1);
							ghiFile(file2,B);
						}
					}
				}
				
			}
			if(event.type == Event::TextEntered){
				TBSdt.typeOn(event);
			}
    	}
    	if(TBSdt.getText()=="") BHienThi.setText("");
    	NhapSdt.clear();
    	BThemKH.drawTo(NhapSdt);
    	BTSdt.drawTo(NhapSdt);
    	BHienThi.drawTo(NhapSdt);
    	BSdt.drawTo(NhapSdt);
    	BSubmit.drawTo(NhapSdt);
    	TBSdt.drawTo(NhapSdt);
    	NhapSdt.display();
    	
	}
	return 0;
}

int GDThanhToan(fstream& file5,LinkedList<ThanhToan> &TToan,Font &a,LinkedList<LichDatSan> &Lds, fstream& file3,int SelectedI,Date HienThi,LinkedList<KhachHang> &B,LinkedList<San> &A,int SSan,string tt,fstream &file4){
	RenderWindow WinThanhToan(VideoMode(400, 600), "ThanhToan", Style::Default);
	
	string MaSan,TGEnd,TGSt,tenKH,loaiSan;
	int maKH;
	
	float Tong=0;
	int HT;
	
	::Time St((SelectedI-1)/2+6,((SelectedI-1)%2)*30,0);
	for(int i=1;i<=Lds.size();i++){
		if(Lds[i].getStTime().getTime()==St && Lds[i].getStTime().getDate()==HienThi && Lds[i].getMaSanBong()==SSan){
			Lds[i].setTT("DaThanhToan");
			MaSan=to_string(Lds[i].getMaSanBong());
			TGSt=Lds[i].getStTime().getTime().getTime();
			TGEnd=Lds[i].getEnTime().getSDay();
			maKH=Lds[i].getMaKhachHang();
			HT=i;
			break;
		}
	}
	for(int i=1;i<=B.size();i++){
		if(B[i].getTen()==maKH){
			tenKH=B[i].getTenKh();
		}
	}
	for(int i=1;i<=A.size();i++){
		if(A[i].getTen()==stoi(MaSan)){
			loaiSan=A[i].getLoaiSan();
		}
	}
	Tong=Lds[HT].tongGia(loaiSan);
	ThanhToan t(++MaxTT,Lds[HT].getMaDatSan(),Tong);
	TToan.add(t);
	
	Button BSan("San " + MaSan,Vector2f(100.f, 40.f),20,Color::Black,Color::White,{150,50},&a,{150,50});
	Button BLoaiSan("Loai san: " + loaiSan,Vector2f(300.f, 40.f),20,Color::Black,Color::White,{50,100},&a,{50,100});
	Button BThoiGian(TGSt+ " - " +TGEnd,Vector2f(300.f, 40.f),20,Color::Black,Color::White,{50,150},&a,{50,150});	
	Button BGia("Gia 1 gio:"+to_string(loaiSan=="San5"?160000:300000),Vector2f(300.f, 40.f),20,Color::Black,Color::White,{50,200},&a,{50,200});
	Button BThanhToan("thanhtoan: "+to_string(Tong),Vector2f(300.f, 40.f),20,Color::Black,Color::White,{50,250},&a,{50,250});
	Button BOK("ok",Vector2f(100.f, 40.f),30,Color::Blue,Color::White,{150,550},&a,{150,550});
	
	while (WinThanhToan.isOpen()) {
        Event event;
        while (WinThanhToan.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                WinThanhToan.close();
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
					if(!BOK.isMouseOver(WinThanhToan)){
						if(tt!="Toan"){
							ghiFile(file3,Lds);
							ghiFile(file4);
							ghiFile(file5,TToan);
							return Lds[HT].getMaDatSan();
							WinThanhToan.close();
						}
						else{
							return 0;
							WinThanhToan.close();
						}
						
					}
				}
				
			}
			
    	}
    	WinThanhToan.clear();
    	BSan.drawTo(WinThanhToan);
    	BLoaiSan.drawTo(WinThanhToan);
    	BThoiGian.drawTo(WinThanhToan);
    	BGia.drawTo(WinThanhToan);
    	BThanhToan.drawTo(WinThanhToan);
    	BOK.drawTo(WinThanhToan);
    	WinThanhToan.display();
    	
	}
	return 0;
}

void GDDatSan(Font &a,LinkedList<LichDatSan> &Lds,LinkedList<KhachHang> &B,RenderWindow &DatSan,int SSan, fstream& file3,fstream& file2,fstream& file4,fstream& file5,LinkedList<ThanhToan> &TToan,LinkedList<San> &A){
//	const int Top=100;
//	const int Bot=550;
//	const float Left =125;
    int SelectedI = 0,SelectedJ=0;
    
//	RenderWindow DatSan(VideoMode(960, 700), "DatSan", Style::Default);
	
	LinkedList<::Time> LLTime;
	
	::Time tS(OPEN_TIME);
	::Time tE(CLOSE_TIME);
	for(::Time i=tS;i!=tE;i=i+30){
		LLTime.add(i);
	}
	
	Date HienThi;
	HienThi=HienThi.getCurrentDate();
	
	RectangleShape WhiteBoard({650,Bot-Top});
	WhiteBoard.setPosition(100,Top);
	WhiteBoard.setFillColor(Color::White);
	
	Button BLen("Up",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,300},&a,{830,310});
	Button BXuong("Down",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,400},&a,{812,410});
	Button BNgay("Ngay",Vector2f(57.f, 30.f),20,Color::Black,Color::White,{300,50},&a,{300,50});
	Button BThang("Thang",Vector2f(57.f, 30.f),20,Color::Black,Color::White,{405,50},&a,{400,50});
	Button BNam("Nam",Vector2f(57.f, 30.f),20,Color::Black,Color::White,{520,50},&a,{520,50});
	Button BSearch("Search",Vector2f(150.f, 50.f),30,Color::Blue,Color::White,{650,40},&a,{670,40});
	Button BDat("Dat",Vector2f(200.f, 50.f),30,Color::Blue,Color::White,{100,600},&a,{165,600});
	Button BThanhToan("Thanh Toan",Vector2f(200.f, 50.f),30,Color::Blue,Color::White,{350,600},&a,{360,600});
	Button BHuy("Huy",Vector2f(200.f, 50.f),30,Color::Blue,Color::White,{600,600},&a,{665,600});
	Button BDay(HienThi.getCurrentDate().getDate(),Vector2f(150.f, 40.f),25,Color::Blue,Color::White,{100,40},&a,{110,40});
	Button BQuayLai("Quay Lai",{90,40},20,Color::Blue,Color::White,{0,0},&a,{5,2});
	Button BHienThiS("San "+to_string(SSan),Vector2f(120.f, 70.f),30,Color::Blue,Color::White,{800,200},&a,{820,210});
	
	Textbox TBNgay(20,Color::White,false,&a,{358,50});
	Textbox TBThang(20,Color::White,false,&a,{468,50});
	Textbox TBNam(20,Color::White,false,&a,{568,50});
	Button TBBNgay("",Vector2f(40.f, 30.f),20,Color::Blue,Color::White,{358,50},&a,{300,50});
	Button TBBThang("",Vector2f(40.f, 30.f),20,Color::Blue,Color::White,{468,50},&a,{400,50});
	Button TBBNam("",Vector2f(40.f, 30.f),20,Color::Blue,Color::White,{568,50},&a,{500,50});
	
	TBNgay.setLimit(true,1);
	TBThang.setLimit(true,1);
	TBNam.setLimit(true,3);
	
	LinkedList<Button> BTime;
	for(int i=1;i<=LLTime.size();i++){
		Button b(LLTime[i].getHaM(),{100,40},20,Color::Black,Color::White,{Left,float(120+50*(i-1))},&a,{Left+25,float(120+50*(i-1))});
		BTime.add(b);
	}
	
	LinkedList<Button> BTT;
	for(int i=1;i<=LLTime.size();i++){
		Button c("Con Trong",{500,40},20,Color::Black,Color::White,{Left+100+1,float(120+50*(i-1))},&a,{Left+125+1,float(120+50*(i-1))});
		BTT.add(c);
	}
	for(int i=1;i<=Lds.size();i++){
		if(Lds[i].getStTime().getDate()==HienThi.getCurrentDate() && Lds[i].getMaSanBong()==SSan &&Lds[i].getTT()!="DaHuy"){
			::Time T=Lds[i].getStTime().getTime()-tS;
			::Time E=Lds[i].getEnTime().getTime()-tS;
			for(int j=1+(T.getHour()*60+T.getMinute())/30;j<1+(E.getHour()*60+E.getMinute())/30;j++){
				BTT[j].setText(to_string(Lds[i].getMaDatSan())+ " - " + B[Lds[i].getMaKhachHang()].getSdt()+" " +Lds[i].getTT());
			}
		}
	}
	
	while (DatSan.isOpen()) {
        Event event;
        while (DatSan.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                DatSan.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(!(BTime[LLTime.size()].getTop()>Top && BTime[LLTime.size()].getBot()<Bot)){
           	 			if(!BXuong.isMouseOver(DatSan)){
           	 				for(int i=1;i<=LLTime.size();i++){
								BTime[i].setPosition({Left,float(BTime[i].getTop()-Bot+Top+50)});
								BTime[i].setTextPosition({Left+25,float(BTime[i].getTop())});
								BTT[i].setPosition({Left+100+1,float(BTT[i].getTop()-Bot+Top+50)});
							}
						}
					}
					if(!(BTime[1].getTop()>Top && BTime[1].getBot()<Bot)){
           	 			if(!BLen.isMouseOver(DatSan)){
           	 				for(int i=1;i<=LLTime.size();i++){
								BTime[i].setPosition({Left,float(BTime[i].getTop()+Bot-Top-50)});
								BTime[i].setTextPosition({Left+25,float(BTime[i].getTop())});
								BTT[i].setPosition({Left+100+1,float(BTT[i].getTop()+Bot-Top-50)});
							}
						}
					}
					for(int i=1;i<=BTT.size();i++){
           	 			if(!BTime[i].isMouseOver(DatSan) || !BTT[i].isMouseOver(DatSan)){
           	 				if(BTT[i].getText().getString()!="Con Trong"){
           	 					if(i>=SelectedI && i<=SelectedJ && SelectedI!=0){
           	 						SelectedI=0;
           	 						SelectedJ=0;
								}
								else{
									for(int ii=i;ii<=BTT.size();ii++){
										if(BTT[i].getText().getString()==BTT[ii].getText().getString()) SelectedJ=ii;
										else break;
									}
									for(int ij=i;ij>=1;ij--){
										if(BTT[i].getText().getString()==BTT[ij].getText().getString()) SelectedI=ij;
										else break;
									}
								}
							}
							else{
								if(SelectedI==i && SelectedJ==i && SelectedI!=0){
	           	 					SelectedI=0;
	           	 					SelectedJ=0;
								}
								else if(i==SelectedJ+1 && SelectedJ!=0 && BTT[SelectedJ].getText().getString()==BTT[i].getText().getString()) SelectedJ=i;
								else if(i==SelectedI-1 && BTT[SelectedI].getText().getString()==BTT[i].getText().getString()) SelectedI=i;
								else if(i==SelectedI) SelectedI++;
								else if(i==SelectedJ) SelectedJ--;
								else{
									SelectedI=i;
									SelectedJ=i;
								}	
							}
						}
					}
					if(!TBBNgay.isMouseOver(DatSan)) TBNgay.setSelected(true);
					else TBNgay.setSelected(false);
					if(!TBBThang.isMouseOver(DatSan)) TBThang.setSelected(true);
					else TBThang.setSelected(false);
					if(!TBBNam.isMouseOver(DatSan)) TBNam.setSelected(true);
					else TBNam.setSelected(false);
					if(!BSearch.isMouseOver(DatSan)){
						for(int i=1;i<=BTT.size();i++){
							BTT[i].setText("Con Trong");
						}
						Date D(stoi(TBNgay.getText()),stoi(TBThang.getText()),stoi(TBNam.getText()));
						if(D.isValid()){
							BDay.setText(D.getDate());
							for(int i=1;i<=Lds.size();i++){
								if(Lds[i].getStTime().getDate()==D && Lds[i].getMaSanBong()==SSan && Lds[i].getTT()!="DaHuy"){
									::Time T=Lds[i].getStTime().getTime()-tS;
									::Time E=Lds[i].getEnTime().getTime()-tS;
									for(int j=1+(T.getHour()*60+T.getMinute())/30;j<1+(E.getHour()*60+E.getMinute())/30;j++){
										BTT[j].setText(to_string(Lds[i].getMaDatSan())+ " - " +B[Lds[i].getMaKhachHang()].getSdt()+" " +Lds[i].getTT());
									}
								}
							}
						}
						SelectedI=0;
						SelectedJ=0;
					}
					if(!BQuayLai.isMouseOver(DatSan)){
						return;
					}
					if(!BDat.isMouseOver(DatSan)){
						if(SelectedI!=0 && SelectedJ!=0 ){
							if(BTT[SelectedI].getText().getString()=="Con Trong"){
								string SDT;
								int KH=GD_KH_DatSan(a,B,file2,SDT);
								if(KH!=0){
									Day StDay(HienThi,::Time((SelectedI-1)/2,((SelectedI-1)%2)*30,0)+tS);
									Day EnDay(HienThi,::Time((SelectedJ-1)/2,((SelectedJ-1)%2)*30,0)+tS+30);
									LichDatSan L(StDay,EnDay,"DangDuocDat",++MaxLDS,SSan,KH);
									Lds.add(L);
									for(int Se=SelectedI;Se<=SelectedJ;Se++){
										BTT[Se].setText(to_string(L.getMaDatSan())+ " - " +SDT+" Da Dat");
									}
									ghiFile(file4);
									ghiFile(file3,Lds);
								}
							}
						}
					}
					if(!BHuy.isMouseOver(DatSan)){
						string tt=BTT[SelectedI].getText().getString();
						int n=tt.length();
						if(tt!="Con Trong" && tt.substr(n - 4, 4)!="Toan"){
							for(int Se=SelectedI;Se<=SelectedJ;Se++){
								BTT[Se].setText("Con Trong");
							}
							for(int i=1;i<=Lds.size();i++){
								if(Lds[i].getStTime().getDate()==HienThi){
									if(::Time((SelectedI-1)/2,((SelectedI-1)%2)*30,0)+tS==Lds[i].getStTime().getTime()){
										Lds[i].setTT("DaHuy");
									}
								}
							}
							ghiFile(file3,Lds);
							
						}
					}
					if(!BThanhToan.isMouseOver(DatSan)){
						if(SelectedI!=0 && SelectedJ!=0 ){
							if(BTT[SelectedI].getText().getString()!="Con Trong"){
								string tt=BTT[SelectedI].getText().getString();
								int n=tt.length();
								tt=tt.substr(n - 4, 4);
								int k=GDThanhToan(file5,TToan,a,Lds,file3,SelectedI,HienThi,B,A,SSan,tt,file4);
								if(k!=0 && tt!="Toan"){
									int HT;
									for(int i=1;i<=B.size();i++){
										if(B[i].getTen()==k){
											HT=i;
											break;
										}
									}
									for(int j=SelectedI;j<=SelectedJ;j++){
										BTT[j].setText(to_string(k)+" - "+ B[HT].getSdt() +" DaThanhToan");
									}
								}
							}
						}
					}
				}
				
			}
			if(event.type == Event::TextEntered){
				TBNgay.typeOn(event);
				TBThang.typeOn(event);
				TBNam.typeOn(event);
			}
    	}
    	DatSan.clear();
		DatSan.draw(WhiteBoard);
		
		BHienThiS.drawTo(DatSan);
		BQuayLai.drawTo(DatSan);
    	BLen.drawTo(DatSan);
		BXuong.drawTo(DatSan);
		BNgay.drawTo(DatSan);
		BThang.drawTo(DatSan);
		BNam.drawTo(DatSan);
		BSearch.drawTo(DatSan);
		BDat.drawTo(DatSan);
		BHuy.drawTo(DatSan);
		BThanhToan.drawTo(DatSan);
		BDay.drawTo(DatSan);
		
		TBBNgay.drawTo(DatSan);
		TBBThang.drawTo(DatSan);
		TBBNam.drawTo(DatSan);
		
		TBNgay.drawTo(DatSan);
		TBThang.drawTo(DatSan);
		TBNam.drawTo(DatSan);
		
		for(int i=1;i<=BTT.size();i++){
			if(i>=SelectedI && i<=SelectedJ){
				BTT[i].setBackColor(Color::Red);
				BTime[i].setBackColor(Color::Red);
			}
			else{
				BTT[i].setBackColor(Color::Black);
				BTime[i].setBackColor(Color::Black);
			}
		}
		
    	for(int i=1;i<=LLTime.size();i++){
    		if(BTime[i].getTop()>Top && BTime[i].getBot()<Bot){
				BTime[i].setIsAva(true);
				BTime[i].drawTo(DatSan);
				BTT[i].setIsAva(true);
				BTT[i].drawTo(DatSan);
			}
			else {
				BTime[i].setIsAva(false);
				BTT[i].setIsAva(false);
			}
		}
		
    	DatSan.display();
    	
	}
}

int GDThemSan(Font &a,LinkedList<San> &A){
	RenderWindow ThemSan(VideoMode(300, 400), "ThemSan", Style::Default);
	
	Button BSan5("San 5",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{100,100},&a,{110,110});
	Button BSan7("San 7",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{100,250},&a,{110,260});
	
	while (ThemSan.isOpen()) {
        Event event;
        while (ThemSan.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                ThemSan.close(); // Ðóng c?a s? khi nh?n nút dóng
                return 0;
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(!BSan5.isMouseOver(ThemSan)){
           				San c(++MaxSan,"San5",100,true);
           				A.add(c);
						return 1;
					}
					if(!BSan7.isMouseOver(ThemSan)){
           				San c(++MaxSan,"San7",200,true);
           				A.add(c);
						return 1;
					}
				}
				
			}
    	}
    	ThemSan.clear();
    	BSan5.drawTo(ThemSan);
    	BSan7.drawTo(ThemSan);
    	ThemSan.display();
    	
	}
	return 0;
}

void GDSan(fstream& file,LinkedList<San> &A,RenderWindow &MENU,LinkedList<LichDatSan> &Lds,LinkedList<KhachHang> &B, fstream& file3,fstream& file2,fstream& file4,fstream& file5,LinkedList<ThanhToan> &TToan){
//	const int Top=100;
//	const int Bot=550;
//	const float Left =125;
    int Selected = 0;
	
//	RenderWindow San(VideoMode(960, 700), "San", Style::Default);
	Font a;
	a.loadFromFile("Font\\arial.ttf");
	
	Button BThemSan("+",Vector2f(70.f, 70.f),50,Color::Blue,Color::White,{800,100},&a,{820,103});
	Button BXoaSan("-",Vector2f(70.f, 70.f),50,Color::Blue,Color::White,{800,200},&a,{827,200});
	Button BLen("Up",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,300},&a,{830,310});
	Button BXuong("Down",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,400},&a,{812,410});
	Button BSuaThongTin("Sua Thong Tin San",Vector2f(300.f, 70.f),30,Color::Blue,Color::White,{630,600},&a,{650,610});
	Button BSuaTrangThai("Sua Trang Thai San",Vector2f(300.f, 70.f),30,Color::Blue,Color::White,{50,600},&a,{70,610});
	Button BDatSan("Dat San",{250,70},30,Color::Blue,Color::White,{364,600},&a,{435,612});
	Button BQuayLai("Quay Lai",{120,50},20,Color::Blue,Color::White,{0,0},&a,{10,10});
	
	RectangleShape WhiteBoard({650,Bot-Top});
	WhiteBoard.setPosition(100,Top);
	WhiteBoard.setFillColor(Color::White);
	
	LinkedList<Button> BSan;
	for(int i=1;i<=A.size();i++){
		Button b(A[i].thongTinSan2(),{600,40},20,Color::Black,Color::White,{Left,float(120+50*(i-1))},&a,{Left,float(120+50*(i-1))});
		BSan.add(b);
	}
	
	while (MENU.isOpen()) {
        Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
            	ghiFile(file,A);
                MENU.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(A.size()!=0){
           				if(!(BSan[A.size()].getTop()>Top && BSan[A.size()].getBot()<Bot)){
	           	 			if(!BXuong.isMouseOver(MENU)){
	           	 				for(int i=1;i<=A.size();i++){
									BSan[i].setPosition({Left,float(BSan[i].getTop()-Bot+Top+50)});
								}
							}
						}
						if(!(BSan[1].getTop()>Top && BSan[1].getBot()<Bot)){
	           	 			if(!BLen.isMouseOver(MENU)){
	           	 				for(int i=1;i<=A.size();i++){
									BSan[i].setPosition({Left,float(BSan[i].getTop()+Bot-Top-50)});
								}
							}
						}
					}
           	 		
           	 		for(int i=1;i<=A.size();i++){
           	 			if(!BSan[i].isMouseOver(MENU)){
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
					if(!BXoaSan.isMouseOver(MENU)){
						if(Selected!=0){
							for(int i=Selected+1;i<=A.size();i++){
								BSan[i].setPosition({BSan[i].getPosition().x,BSan[i].getPosition().y-50});
							}
//							Vector2f p=BSan[Selected].getPosition();
//							BSan[A.size()].setPosition(p);
//							A[A.size()].doiTen(A[Selected].getTen());
//							BSan[A.size()].setText(A[A.size()].thongTinSan2());
							A.del(Selected-1);
							BSan.del(Selected-1);
							Selected=0;
							ghiFile(file,A);
						}
					}
					if(!BSuaTrangThai.isMouseOver(MENU)){
						if(Selected!=0){
							A[Selected].setTT();
							BSan[Selected].setText(A[Selected].thongTinSan2());
							ghiFile(file,A);
						}
					}
					if(!BThemSan.isMouseOver(MENU)){
						if(GDThemSan(a,A)){
							Button b(A[A.size()].thongTinSan2(),{600,40},20,Color::Black,Color::White,{Left,BSan[BSan.size()].getPosition().y+50},&a,{Left,BSan[BSan.size()].getPosition().y+50});
							BSan.add(b);
							ghiFile(file,A);
							ghiFile(file4);
						}
					}
					if(!BSuaThongTin.isMouseOver(MENU)){
						if(Selected!=0){
							A[Selected].suaThongTin();
							BSan[Selected].setText(A[Selected].thongTinSan2());
							ghiFile(file,A);
						}
					}
					if(!BQuayLai.isMouseOver(MENU)){
						return;
					}
					if(!BDatSan.isMouseOver(MENU)){
						if(Selected!=0 && A[Selected].getTT()==true){
							BQuayLai.setIsAva(false);
							GDDatSan(a,Lds,B,MENU,Selected,file3,file2,file4,file5,TToan,A);
							BQuayLai.setIsAva(true);
						}
					}
					
				}
			}
        }
		MENU.clear();
		BQuayLai.drawTo(MENU);
		BThemSan.drawTo(MENU);
		BXoaSan.drawTo(MENU);
		BLen.drawTo(MENU);
		BXuong.drawTo(MENU);
		BSuaThongTin.drawTo(MENU);
		BSuaTrangThai.drawTo(MENU);
		BDatSan.drawTo(MENU);
		MENU.draw(WhiteBoard);
		for(int i=1;i<=BSan.size();i++){
			if(BSan[i].getTop()>Top && BSan[i].getBot()<Bot){
				BSan[i].setIsAva(true);
				BSan[i].drawTo(MENU);
			}
			else BSan[i].setIsAva(false);
		}
        MENU.display();
    }
}

int GDThemKH(Font &a,string &tenKH,string &sdt){
	RenderWindow ThemKH(VideoMode(600, 500), "ThemKH", Style::Default);
	
	Textbox TBTenKH(20,Color::White,false,&a,{220,100});
	Textbox TBSdt(20,Color::White,false,&a,{220,200});
	
	Button BTenKH("",Vector2f(300.f, 40.f),30,Color::Blue,Color::White,{220,100},&a,{0,0});
	Button BSdt("",Vector2f(300.f, 40.f),30,Color::Blue,Color::White,{220,200},&a,{0,0});
	Button BSubmit("Xac nhan",Vector2f(250.f, 70.f),30,Color::Blue,Color::White,{200,400},&a,{255,410});
	
	TBTenKH.setLimit(true,25);
	TBSdt.setLimit(true,10);
	
	Text TTenKH;
	Text TSdt;
	
	TTenKH.setFont(a);
	TSdt.setFont(a);
	
	TTenKH.setCharacterSize(20);
	TSdt.setCharacterSize(20);
	
	TTenKH.setString("Ten Khach Hang:");
	TSdt.setString("So Dien Thoat:");
	
	TTenKH.setFillColor(Color::White);
	TSdt.setFillColor(Color::White);
	
	TTenKH.setPosition({50,100});
	TSdt.setPosition({50,200});
	
	
	while (ThemKH.isOpen()) {
        Event event;
        while (ThemKH.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                ThemKH.close(); // Ðóng c?a s? khi nh?n nút dóng
                return 0;
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(!BTenKH.isMouseOver(ThemKH)) TBTenKH.setSelected(true);
					else TBTenKH.setSelected(false);
					if(!BSdt.isMouseOver(ThemKH)) TBSdt.setSelected(true);
					else TBSdt.setSelected(false);
					if(!BSubmit.isMouseOver(ThemKH)){
						tenKH=TBTenKH.getText();
						sdt=TBSdt.getText();
						return 1;
					}
				}
				
			}
			if(event.type == Event::TextEntered){
				TBTenKH.typeOn(event);
				TBSdt.typeOn(event);
			}
    	}
    	ThemKH.clear();
    	BTenKH.drawTo(ThemKH);
    	BSdt.drawTo(ThemKH);
    	BSubmit.drawTo(ThemKH);
    	TBTenKH.drawTo(ThemKH);
    	TBSdt.drawTo(ThemKH);
    	ThemKH.draw(TTenKH);
    	ThemKH.draw(TSdt);
    	ThemKH.display();
    	
	}
	return 0;
}

void GDLichSuDatSan(Font &a,int KHDatSan,LinkedList<LichDatSan> &Lds,RenderWindow &LSDS){
//	const int Top=100;
//	const int Bot=550;
//	const float Left =125;
	
	LinkedList<Button> LLB_LSDS;
	
	RectangleShape WhiteBoard({650,Bot-Top});
	WhiteBoard.setPosition(100,Top);
	WhiteBoard.setFillColor(Color::White);
	
	Button BLen("Up",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,300},&a,{830,310});
	Button BXuong("Down",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,400},&a,{812,410});
	Button BQuayLai("Quay Lai",{120,50},20,Color::Blue,Color::White,{0,0},&a,{10,10});
	
	int i=0;
	for(int j=1;j<=Lds.size();j++){
		if(Lds[j].getMaKhachHang()==KHDatSan){
			++i;
			Button b(Lds[j].getLds2(),{600,40},20,Color::Black,Color::White,{Left,float(120+50*(i-1))},&a,{Left,float(120+50*(i-1))});
			LLB_LSDS.add(b);
		}
		
	}
	
	
	while (LSDS.isOpen()) {
        Event event;
        while (LSDS.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                LSDS.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(i!=0){
           				if(!(LLB_LSDS[i].getTop()>Top && LLB_LSDS[i].getBot()<Bot)){
	           	 			if(!BXuong.isMouseOver(LSDS)){
	           	 				for(int j=1;j<=i;j++){
									LLB_LSDS[j].setPosition({Left,float(LLB_LSDS[j].getTop()-Bot+Top+50)});
								}
							}
						}
					}
					if(i!=0){
						if(!(LLB_LSDS[1].getTop()>Top && LLB_LSDS[1].getBot()<Bot)){
	           	 			if(!BXuong.isMouseOver(LSDS)){
	           	 				for(int j=1;j<=i;j++){
									LLB_LSDS[j].setPosition({Left,float(LLB_LSDS[j].getTop()+Bot-Top-50)});
								}
							}
						}
					}
					
					if(!BQuayLai.isMouseOver(LSDS)){
						return;
					}
				}
				
			}
    	}
    	LSDS.clear();
		BLen.drawTo(LSDS);
		BXuong.drawTo(LSDS);
		BQuayLai.drawTo(LSDS);
		LSDS.draw(WhiteBoard);
		for(int j=1;j<i;j++){
			if(LLB_LSDS[j].getTop()>Top && LLB_LSDS[j].getBot()<Bot){
				LLB_LSDS[j].setIsAva(true);
				LLB_LSDS[j].drawTo(LSDS);
			}
			else LLB_LSDS[j].setIsAva(false);
		}
    	LSDS.display();
    	
	}
}

void GDKhachHang(fstream& file2,LinkedList<KhachHang> &B,RenderWindow &MENU,fstream &file4,LinkedList<LichDatSan> &Lds){
//	const int Top=100;
//	const int Bot=550;
//	const float Left =125;
    int Selected = 0;
	
//	RenderWindow KhachHangWin(VideoMode(960, 700), "KhachHang", Style::Default);
	
	Font a;
	a.loadFromFile("Font\\arial.ttf");
	
	Button BThemKH("+",Vector2f(70.f, 70.f),50,Color::Blue,Color::White,{800,100},&a,{820,103});
	Button BXoaKH("-",Vector2f(70.f, 70.f),50,Color::Blue,Color::White,{800,200},&a,{827,200});
	Button BLen("Up",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,300},&a,{830,310});
	Button BXuong("Down",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,400},&a,{812,410});
	Button BSuaThongTinKH("Sua Thong Tin Khach Hang",Vector2f(400.f, 70.f),30,Color::Blue,Color::White,{50,600},&a,{70,610});
	Button BLichSuDatSan("Lich Su Dat San",Vector2f(400.f, 70.f),30,Color::Blue,Color::White,{500,600},&a,{580,610});
	Button BQuayLai("Quay Lai",{120,50},20,Color::Blue,Color::White,{0,0},&a,{10,10});
	
	RectangleShape WhiteBoard({650,Bot-Top});
	WhiteBoard.setPosition(100,Top);
	WhiteBoard.setFillColor(Color::White);
	
	LinkedList<Button> BKH;
	for(int i=1;i<=B.size();i++){
		Button b(B[i].ThongTinKH2(),{600,40},20,Color::Black,Color::White,{Left,float(120+50*(i-1))},&a,{Left,float(120+50*(i-1))});
		BKH.add(b);
	}
	
	while (MENU.isOpen()) {
        Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(B.size()!=0){
           				if(!(BKH[B.size()].getTop()>Top && BKH[B.size()].getBot()<Bot)){
	           	 			if(!BXuong.isMouseOver(MENU)){
	           	 				for(int i=1;i<=B.size();i++){
									BKH[i].setPosition({Left,float(BKH[i].getTop()-Bot+Top+50)});
								}
							}
						}
						if(!(BKH[1].getTop()>Top && BKH[1].getBot()<Bot)){
	           	 			if(!BLen.isMouseOver(MENU)){
	           	 				for(int i=1;i<=B.size();i++){
									BKH[i].setPosition({Left,float(BKH[i].getTop()+Bot-Top-50)});
								}
							}
						}
					}
           	 		
           	 		for(int i=1;i<=B.size();i++){
           	 			if(!BKH[i].isMouseOver(MENU)){
           	 				if(Selected!=i){
           	 					if(Selected!=0) BKH[Selected].setBackColor(Color::Black);
           	 					Selected=i;
								BKH[i].setBackColor(Color::Red);
							}
							else{
								Selected=0;
								BKH[i].setBackColor(Color::Black);
							}
						}
					}
					if(!BXoaKH.isMouseOver(MENU)){
						if(Selected!=0){
							for(int i=Selected+1;i<=B.size();i++){
								BKH[i].setPosition({BKH[i].getPosition().x,BKH[i].getPosition().y-50});
							}
//							Vector2f p=BKH[Selected].getPosition();
//							BKH[B.size()].setPosition(p);
//							B[B.size()].doiTen(B[Selected].getTen());
//							BKH[B.size()].setText(B[B.size()].ThongTinKH2());
							B.del(Selected-1);
							BKH.del(Selected-1);
							Selected=0;
							ghiFile(file2,B);
						}
					}
					if(!BThemKH.isMouseOver(MENU)){
						string ten,sdt;
						if(GDThemKH(a,ten,sdt)){
							KhachHang kh1(++MaxKH,ten,sdt);
							B.add(kh1);
							Button kh2(B[B.size()].ThongTinKH2(),{600,40},20,Color::Black,Color::White,{Left,BKH[BKH.size()].getPosition().y+50},&a,{Left,BKH[BKH.size()].getPosition().y+50});
							BKH.add(kh2);
							ghiFile(file2,B);
							ghiFile(file4);
						}
					}
					if(!BSuaThongTinKH.isMouseOver(MENU)){
						if(Selected!=0){
							string ten,sdt;
							if(GDThemKH(a,ten,sdt)){
								B[Selected].setTen(ten);
								B[Selected].setSdt(sdt);
								BKH[Selected].setText(B[Selected].ThongTinKH2());
								ghiFile(file2,B);
							}
						}
					}
					if(!BQuayLai.isMouseOver(MENU)){
						return;
					}
					if(!BLichSuDatSan.isMouseOver(MENU)){
						if(Selected!=0){
							GDLichSuDatSan(a,Selected,Lds,MENU);
						}
					}
				}
			}
        }
       	MENU.draw(WhiteBoard);
       	BQuayLai.drawTo(MENU);
        BThemKH.drawTo(MENU);
		BXoaKH.drawTo(MENU);
		BLen.drawTo(MENU);
		BXuong.drawTo(MENU);
		BSuaThongTinKH.drawTo(MENU);
		BLichSuDatSan.drawTo(MENU);
		for(int i=1;i<=BKH.size();i++){
			if(BKH[i].getTop()>Top && BKH[i].getBot()<Bot){
				BKH[i].setIsAva(true);
				BKH[i].drawTo(MENU);
			}
			else BKH[i].setIsAva(false);
		}
        MENU.display();
    }
}

void GDThongKe(Font &a,RenderWindow &ThongKe,LinkedList<ThanhToan> &TToan,LinkedList<LichDatSan> &Lds){
	int Selected=0;
	int Tong=0;
	
	Button BQuayLai("Quay Lai",{120,50},20,Color::Blue,Color::White,{0,0},&a,{10,10});
	Button BSearch("Search",Vector2f(150.f, 50.f),30,Color::Blue,Color::White,{650,40},&a,{670,40});
	Button BLen("Up",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,300},&a,{830,310});
	Button BXuong("Down",Vector2f(100.f, 70.f),30,Color::Blue,Color::White,{800,400},&a,{812,410});
	Button BXemThongTin("Xem Thong Tin",Vector2f(300.f, 70.f),30,Color::Blue,Color::White,{130,600},&a,{150,610});
	Button BNgay("Ngay",Vector2f(57.f, 30.f),20,Color::Black,Color::White,{300,50},&a,{300,50});
	Button BThang("Thang",Vector2f(57.f, 30.f),20,Color::Black,Color::White,{405,50},&a,{400,50});
	Button BNam("Nam",Vector2f(57.f, 30.f),20,Color::Black,Color::White,{520,50},&a,{520,50});
	Button BHTTong("Tong: " ,Vector2f(300.f, 70.f),30,Color::Blue,Color::White,{600,600},&a,{610,610});
	
	Textbox TBNgay(20,Color::White,false,&a,{358,50});
	Textbox TBThang(20,Color::White,false,&a,{468,50});
	Textbox TBNam(20,Color::White,false,&a,{568,50});
	Button TBBNgay("",Vector2f(40.f, 30.f),20,Color::Blue,Color::White,{358,50},&a,{300,50});
	Button TBBThang("",Vector2f(40.f, 30.f),20,Color::Blue,Color::White,{468,50},&a,{400,50});
	Button TBBNam("",Vector2f(40.f, 30.f),20,Color::Blue,Color::White,{568,50},&a,{500,50});
	
	TBNgay.setLimit(true,1);
	TBThang.setLimit(true,1);
	TBNam.setLimit(true,3);
	
	RectangleShape WhiteBoard({650,Bot-Top});
	WhiteBoard.setPosition(100,Top);
	WhiteBoard.setFillColor(Color::White);
	
	LinkedList<Button> BTT;
	

	
	while (ThongKe.isOpen()) {
        Event event;
        while (ThongKe.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                ThongKe.close(); 
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
					if(!BQuayLai.isMouseOver(ThongKe)){
						return;
					}
					if(BTT.size()!=0){
           				if(!(BTT[BTT.size()].getTop()>Top && BTT[BTT.size()].getBot()<Bot)){
	           	 			if(!BXuong.isMouseOver(ThongKe)){
	           	 				for(int i=1;i<=BTT.size();i++){
									BTT[i].setPosition({Left,float(BTT[i].getTop()-Bot+Top+50)});
								}
							}
						}
						if(!(BTT[1].getTop()>Top && BTT[1].getBot()<Bot)){
	           	 			if(!BLen.isMouseOver(ThongKe)){
	           	 				for(int i=1;i<=BTT.size();i++){
									BTT[i].setPosition({Left,float(BTT[i].getTop()+Bot-Top-50)});
								}
							}
						}
					}
					for(int i=1;i<=BTT.size();i++){
           	 			if(!BTT[i].isMouseOver(ThongKe)){
           	 				if(Selected!=i){
           	 					if(Selected!=0) BTT[Selected].setBackColor(Color::Black);
           	 					Selected=i;
								BTT[i].setBackColor(Color::Red);
							}
							else{
								Selected=0;
								BTT[i].setBackColor(Color::Black);
							}
						}
					}
					if(!BSearch.isMouseOver(ThongKe)){
						int ngay,thang,nam;
						string sngay=TBNgay.getText();
						string sthang=TBThang.getText();
						string snam=TBNam.getText();
						int k=0;
						
						if(sngay=="" && sthang=="" && stoi(snam)>0){
							nam=stoi(snam);
							for(int i=1;i<=TToan.size();i++){
								int Id=TToan[i].getIdLDS();
								for(int j=1;j<=Lds.size();j++){
									if(Lds[j].getMaDatSan()==Id){
										if(Lds[j].getStTime().getDate().getYear()==nam){
											k++;
											Button b("Lich dat san: "+TToan[i].getSTT2(),{600,40},20,Color::Black,Color::White,{Left,float(120+50*(k-1))},&a,{Left,float(120+50*(k-1))});
											BTT.add(b);
											Tong+=TToan[i].getTT();
										}
									}
								}
								
							}
						}
						else if(sngay=="" && stoi(sthang)>0 && stoi(sthang)<=12 && stoi(snam)>0){
							nam=stoi(snam);
							thang=stoi(sthang);
							for(int i=1;i<=TToan.size();i++){
								int Id=TToan[i].getIdLDS();
								for(int j=1;j<=Lds.size();j++){
									if(Lds[j].getMaDatSan()==Id){
										if(Lds[j].getStTime().getDate().getYear()==nam && Lds[j].getStTime().getDate().getMonth()==thang){
											k++;
											Button b("Lich dat san: "+TToan[i].getSTT2(),{600,40},20,Color::Black,Color::White,{Left,float(120+50*(k-1))},&a,{Left,float(120+50*(k-1))});
											BTT.add(b);
											Tong+=TToan[i].getTT();
										}
									}
								}
							}
						}
						else{
							nam=stoi(snam);
							thang=stoi(sthang);
							ngay=stoi(sngay);
							Date D(ngay,thang,nam);
							if(D.isValid()){
								for(int i=1;i<=TToan.size();i++){
									int Id=TToan[i].getIdLDS();
									for(int j=1;j<=Lds.size();j++){
										if(Lds[j].getMaDatSan()==Id){
											if(Lds[j].getStTime().getDate()==D){
												k++;
												Button b("Lich dat san: "+TToan[i].getSTT2(),{600,40},20,Color::Black,Color::White,{Left,float(120+50*(k-1))},&a,{Left,float(120+50*(k-1))});
												BTT.add(b);
												Tong+=TToan[i].getTT();
											}
										}
									}
								}
							}
						}
						BHTTong.setText("Tong: " + to_string(Tong));
						Tong=0;
						Selected=0;
					}
					if(!TBBNgay.isMouseOver(ThongKe)) TBNgay.setSelected(true);
					else TBNgay.setSelected(false);
					if(!TBBThang.isMouseOver(ThongKe)) TBThang.setSelected(true);
					else TBThang.setSelected(false);
					if(!TBBNam.isMouseOver(ThongKe)) TBNam.setSelected(true);
					else TBNam.setSelected(false);
				}
				
			}
			if(event.type == Event::TextEntered){
				TBNgay.typeOn(event);
				TBThang.typeOn(event);
				TBNam.typeOn(event);
			}
			
    	}
    	ThongKe.clear();
    	BQuayLai.drawTo(ThongKe);
    	ThongKe.draw(WhiteBoard);
    	BLen.drawTo(ThongKe);
		BXuong.drawTo(ThongKe);
		BSearch.drawTo(ThongKe);
		BNgay.drawTo(ThongKe);
		BThang.drawTo(ThongKe);
		BNam.drawTo(ThongKe);
		BXemThongTin.drawTo(ThongKe);
		BHTTong.drawTo(ThongKe);
		
		TBBNgay.drawTo(ThongKe);
		TBBThang.drawTo(ThongKe);
		TBBNam.drawTo(ThongKe);
		
		TBNgay.drawTo(ThongKe);
		TBThang.drawTo(ThongKe);
		TBNam.drawTo(ThongKe);
		
		for(int i=1;i<=BTT.size();i++){
			if(BTT[i].getTop()>Top && BTT[i].getBot()<Bot){
				BTT[i].setIsAva(true);
				BTT[i].drawTo(ThongKe);
			}
			else BTT[i].setIsAva(false);
		}
    	ThongKe.display();
    	
	}
}

void run(){
	setlocale(LC_ALL, "");
	
	LinkedList<San> A;
    
	fstream file;
	file.open("Data\\San.csv",ios::in|ios::out);
	docFile(file,A);
	if (!file.is_open()) {
        cerr << "Không the mo file san" << endl;
        return; 
    }
        
    LinkedList<KhachHang> B;
    
    fstream file2;
    file2.open("Data\\KhachHang.csv",ios::in|ios::out);
    docFile(file2,B);
    if (!file2.is_open()) {
        cerr << "Không the mo file khach hang" << endl;
        return; 
    }
    
    LinkedList<LichDatSan> Lds;
    
    fstream file3;
    file3.open("Data\\LichDatSan.csv",ios::in|ios::out);
    docFile(file3,Lds);
    if (!file3.is_open()) {
        cerr << "Không the mo file lich dat san" << endl;
        return; 
    }
    
    fstream file4;
    file4.open("Data\\MaxSKH.csv",ios::in|ios::out);
    file4>>MaxSan;
    file4.ignore();
    file4>>MaxKH;
    file4.ignore();
    file4>>MaxLDS;
    file4.ignore();
    file4>>MaxTT;
    
    LinkedList<ThanhToan> TToan;
    
    fstream file5;
    file5.open("Data\\ThanhToan.csv",ios::in|ios::out);
    docFile(file5,TToan);
    if (!file5.is_open()) {
        cerr << "Không the mo file thanh toan" << endl;
        return; 
    }
    
	
	RenderWindow MENU(VideoMode(960, 700), "Main Menu", Style::Default);
    
    Font a;
    if (!a.loadFromFile("Font\\arial.ttf")){
    	cout<<"Khong the load font!";
    	return ;
	}
    
    Button BSan("Sân",Vector2f(250.f, 25.f),15,Color::Blue,Color::White,{350,250},&a,{460,250});
	Button BKhachHang("Khách Hàng",Vector2f(250.f, 25.f),15,Color::Blue,Color::White,{350,300},&a,{440,300});
	Button BThongKe("Thong Ke",Vector2f(250.f, 25.f),15,Color::Blue,Color::White,{350,350},&a,{445,350});
	Button BThoat("Thoat",Vector2f(250.f, 25.f),15,Color::Blue,Color::White,{350,400},&a,{455,400});
	
	
    while (MENU.isOpen()) {
        Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
           	if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(!BSan.isMouseOver(MENU)){
           	 			GDSan(file,A,MENU,Lds,B,file3,file2,file4,file5,TToan);
					} 
					else if(!BKhachHang.isMouseOver(MENU)){
           	 			GDKhachHang(file2,B,MENU,file4,Lds);
					} 
					else if(!BThongKe.isMouseOver(MENU)){
           	 			GDThongKe(a,MENU,TToan,Lds);
					} 
					else if(!BThoat.isMouseOver(MENU)){
           	 			MENU.close();
					} 
				}
			}
        }
		MENU.clear();
		BSan.drawTo(MENU);
		BKhachHang.drawTo(MENU);
		BThongKe.drawTo(MENU);
		BThoat.drawTo(MENU);
        MENU.display();
    }
    
    file.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
}

int main(){
	run();
	return 0;
}
