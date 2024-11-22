#include "core.h"

int MaxSan=0,MaxKH=0,MaxLDS=0,MaxTT=0;

const int Top=80;
const int Bot=755;
const int Left =202;

int GIA_5=0,GIA_7=0;

Sprite loadSprite(Texture& texture,const string& filepath,Vector2f pos) {
    if (!texture.loadFromFile(filepath)) {
        cerr << "Khong the load hinh anh " <<endl;
        return Sprite();
    }
    Sprite sprite;
    sprite.setTexture(texture); 
    sprite.setPosition(pos);
    return sprite;
}

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
	
	Textbox TBSdt(20,Color::White,false,&a,{225,150});
	
	Button BSdt("",Vector2f(215.f, 40.f),30,Color::Blue,Color::White,{190,140},&a,{0,0});
	Button BTSdt("Nhap sdt khach hang",Vector2f(300.f, 40.f),30,Color::Black,Color::White,{170,50},&a,{180,50});
	Button BSubmit("Xac nhan",Vector2f(245.f, 90.f),30,Color::Blue,Color::White,{25,260},&a,{70,310});	
	Button BThemKH("Them Khach Hang",Vector2f(245.f, 90.f),30,Color::Blue,Color::White,{325,260},&a,{275,310});
	Button BHienThi("",Vector2f(300.f, 40.f),30,Color::Black,Color::White,{150,200},&a,{155,250});
	
	TBSdt.setLimit(true,10);
	
	Texture TTGDDatSanKH;
	Sprite SPGDDatSanKH = loadSprite(TTGDDatSanKH,"D:\\cpp\\PBL2\\Pictures\\GDNhapKH\\GDNhapKH.png",{0,0});
	Texture TTTextSdt;
	Sprite SPTextSdt = loadSprite(TTTextSdt,"D:\\cpp\\PBL2\\Pictures\\GDNhapKH\\NhapSDTKH.png",{100,50});
	Texture TTBSdt;
	Sprite SPBSdt = loadSprite(TTBSdt,"D:\\cpp\\PBL2\\Pictures\\GDNhapKH\\ButtonTextbox.png",{190,140});
	Texture TTSubmit;
	Sprite SPSubmit = loadSprite(TTSubmit,"D:\\cpp\\PBL2\\Pictures\\GDNhapKH\\ButtonXacNhan.png",{25,260});
	Texture TTThemKh;
	Sprite SPThemKh = loadSprite(TTThemKh,"D:\\cpp\\PBL2\\Pictures\\GDNhapKH\\ButtonThemKH.png",{325,260});
	Texture TTHienThi;
	Sprite SPHienThi = loadSprite(TTHienThi,"D:\\cpp\\PBL2\\Pictures\\GDNhapKH\\KTTKH.png",{150,200});
	
	bool HT=false;
	
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
						else HT=true;
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
				TBSdt.typeOnNumber(event);
			}
    	}
    	if(TBSdt.getText()=="") HT=false;
    	
    	NhapSdt.clear();
    	
    	BThemKH.drawTo(NhapSdt);
    	BTSdt.drawTo(NhapSdt);
    	BHienThi.drawTo(NhapSdt);
    	BSdt.drawTo(NhapSdt);
    	BSubmit.drawTo(NhapSdt);
    	
    	NhapSdt.draw(SPGDDatSanKH);
    	if(HT) NhapSdt.draw(SPHienThi);
    	NhapSdt.draw(SPTextSdt);
    	NhapSdt.draw(SPBSdt);
    	NhapSdt.draw(SPSubmit);
    	NhapSdt.draw(SPThemKh);
    	
    	
    	TBSdt.drawTo(NhapSdt);
    	
    	NhapSdt.display();
    	
	}
	return 0;
}

void GetDL_GDThanhToan(LinkedList<LichDatSan> &Lds,Date HienThi,int SSan,int &HT,string &MaSan,string &TGSt,string &TGEnd,int &maKH,::Time St){
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
}

void SaveImageToFile(RenderWindow &WinThanhToan,Day &D){
	Texture texture;
    texture.create(WinThanhToan.getSize().x, WinThanhToan.getSize().y);
    texture.update(WinThanhToan);
    Image frameImage= texture.copyToImage();
    
    IntRect region(0, 0, 370, 690); // (x, y, width, height)
    Image croppedImage;
    croppedImage.create(region.width, region.height);
    croppedImage.copy(frameImage, 0, 0, region);
    
    string filename = "Bills/"+D.getCurrentDay().getDate().getSDate()+"_Bill_"+to_string(MaxTT)+".png";
    croppedImage.saveToFile(filename);
}

int GDThanhToan(fstream& file5,LinkedList<ThanhToan> &TToan,Font &a,LinkedList<LichDatSan> &Lds, fstream& file3,int SelectedI,Date HienThi,LinkedList<KhachHang> &B,LinkedList<San> &A,int SSan,string tt,fstream &file4){
	RenderWindow WinThanhToan(VideoMode(370, 745), "ThanhToan", Style::Default);
	
	string MaSan,TGEnd,TGSt,tenKH,loaiSan;
	int maKH;
	
	int Tong=0;
	int HT;
	
	::Time St((SelectedI-1)/2+6,((SelectedI-1)%2)*30,0);
	
	GetDL_GDThanhToan(Lds,HienThi,SSan,HT,MaSan,TGSt,TGEnd,maKH,St);
	
	for(int i=1;i<=B.size();i++){
		if(B[i].getTen()==maKH){
			tenKH=B[i].getTenKh();
		}
	}
	int giaThue;
	
	for(int i=1;i<=A.size();i++){
		if(A[i].getTen()==stoi(MaSan)){
			loaiSan=A[i].getLoaiSan();
			giaThue=A[i].getGia();
		}
	}
	Tong=Lds[HT].tongGia(giaThue);
	ThanhToan t(++MaxTT,Lds[HT].getMaDatSan(),Tong);
	TToan.add(t);
	
	Day D;
	
	Button BSoHD(to_string(MaxTT),Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{140,188},&a,{138,188});
	Button BTGIn(D.getCurrentDay().getSDay(),Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{135,225},&a,{138,225});
	Button BSan(MaSan,Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{60,265},&a,{60,263});
	Button BLoaiSan(loaiSan,Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{100,298},&a,{103,299});
	Button BThoiGian(TGSt+ " - " +TGEnd,Vector2f(300.f, 40.f),20,Color::Black,Color::Black,{20,339},&a,{20,337});	
	Button BGia(to_string(giaThue),Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{120,370},&a,{117,374});
	Button BTenKH(tenKH,Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{70,410},&a,{69,411});
	Button BThanhToan(to_string(Tong),Vector2f(150.f, 40.f),20,Color::Black,Color::Black,{180,458},&a,{180,450});
	Button BOK("ok",Vector2f(250.f, 45.f),30,Color::Blue,Color::White,{65,690},&a,{65,690});
	
	Texture TTGDThanhToan;
	Sprite SPGDThanhToan = loadSprite(TTGDThanhToan,"D:\\cpp\\PBL2\\Pictures\\GDThanhToan\\GDThanhToan.png",{0,0});
	Texture TTButtonXacNhan;
	Sprite SPButtonXacNhan = loadSprite(TTButtonXacNhan,"D:\\cpp\\PBL2\\Pictures\\GDThanhToan\\ButtonXacNhan.png",BOK.getPosition());
	Texture TTQR;
	Sprite SPQR = loadSprite(TTQR,"D:\\cpp\\PBL2\\Pictures\\GDThanhToan\\QR.jpg",{125,510});
	
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
							SaveImageToFile(WinThanhToan,D);
				            
							ghiFile(file3,Lds);
							ghiFile(file4);
							ghiFile(file5,TToan);
							WinThanhToan.close();
							return Lds[HT].getMaKhachHang();
							
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
    	BOK.drawTo(WinThanhToan);
    	WinThanhToan.draw(SPGDThanhToan);
    	BSan.drawTextTo(WinThanhToan);
    	BLoaiSan.drawTextTo(WinThanhToan);
    	BThoiGian.drawTextTo(WinThanhToan);
    	BGia.drawTextTo(WinThanhToan);
    	BTenKH.drawTextTo(WinThanhToan);
    	BThanhToan.drawTextTo(WinThanhToan);
    	WinThanhToan.draw(SPButtonXacNhan);
    	WinThanhToan.draw(SPQR);
    	BSoHD.drawTextTo(WinThanhToan);
    	BTGIn.drawTextTo(WinThanhToan);
    	WinThanhToan.display();
    	
	}
	return 0;
}

void setColor_GDDatSan(LinkedList<Button> &BTT,LinkedList<Button> &BTime,int SelectedI, int SelectedJ){
	for(int i=1;i<=BTT.size();i++){
		if(i>=SelectedI && i<=SelectedJ){
			BTT[i].setTextColor(Color::Red);
			BTime[i].setTextColor(Color::Red);
		}
		else{
			BTT[i].setTextColor(Color::Black);
			BTime[i].setTextColor(Color::Black);
		}
	}
}

void setAvailable_Draw_GDDatSan(LinkedList<::Time> LLTime,LinkedList<Button> &BTT,LinkedList<Button> &BTime,RenderWindow &DatSan,LinkedList<Sprite> &LL_SP){
	for(int i=1;i<=LLTime.size();i++){
		if(BTime[i].getTop()>Top && BTime[i].getBot()<Bot){
			DatSan.draw(LL_SP[i]);
			BTime[i].setIsAva(true);
			BTime[i].drawTextTo(DatSan);
			BTT[i].setIsAva(true);
			BTT[i].drawTextTo(DatSan);
		}
		else {
			BTime[i].setIsAva(false);
			BTT[i].setIsAva(false);
		}
	}
}

void PrintTT_GDDatSan(LinkedList<LichDatSan> &Lds,::Time tS,LinkedList<KhachHang> &B,LinkedList<Button> &BTT,int SSan,Date HienThi=Date::getCurrentDate()){
	for(int i=1;i<=Lds.size();i++){
		if(Lds[i].getStTime().getDate()==HienThi && Lds[i].getMaSanBong()==SSan &&Lds[i].getTT()!="DaHuy"){
			::Time T=Lds[i].getStTime().getTime()-tS;
			::Time E=Lds[i].getEnTime().getTime()-tS;
			for(int j=1+(T.getHour()*60+T.getMinute())/30;j<1+(E.getHour()*60+E.getMinute())/30;j++){
				BTT[j].setText(to_string(Lds[i].getMaDatSan())+ " - " + B[Lds[i].getMaKhachHang()].getSdt()+" " +Lds[i].getTT());
			}
		}
	}
}

void Bt_Up_Down_GDDatSan(LinkedList<Button> &BTime,LinkedList<::Time> &LLTime,Button &BLen,Button &BXuong,LinkedList<Button> &BTT,RenderWindow &DatSan,LinkedList<Sprite> &LL_SP){
	if(!(BTime[LLTime.size()].getTop()>Top && BTime[LLTime.size()].getBot()<Bot)){
		if(!BXuong.isMouseOver(DatSan)){
			for(int i=1;i<=LLTime.size();i++){
				LL_SP[i].setPosition({float(Left),float(LL_SP[i].getPosition().y-Bot+Top+80)});
				BTime[i].setPosition({float(Left),float(BTime[i].getTop()-Bot+Top+80)});
				BTime[i].setTextPosition({float(Left+15)+25,float(BTime[i].getTop()+18)});
				BTT[i].setPosition({float(Left)+100+1,float(BTT[i].getTop()-Bot+Top+80)});
				BTT[i].setTextPosition({float(Left+15)+125+1,float(BTT[i].getTop()+18)});
			}
		}
	}
	if(!(BTime[1].getTop()>Top && BTime[1].getBot()<Bot)){
		if(!BLen.isMouseOver(DatSan)){
			for(int i=1;i<=LLTime.size();i++){
				LL_SP[i].setPosition({float(Left),float(LL_SP[i].getPosition().y+Bot-Top-80)});
				BTime[i].setPosition({float(Left),float(BTime[i].getTop()+Bot-Top-80)});
				BTime[i].setTextPosition({float(Left+15)+25,float(BTime[i].getTop()+18)});
				BTT[i].setPosition({float(Left)+100+1,float(BTT[i].getTop()+Bot-Top-80)});
				BTT[i].setTextPosition({float(Left+15)+125+1,float(BTT[i].getTop()+18)});
			}
		}
	}
}

void get_SelectedIJ_GDDatSan(LinkedList<Button> &BTime,LinkedList<Button> &BTT,RenderWindow &DatSan,int &SelectedI, int &SelectedJ){
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
}

void BtDatSan_GDDatSan(int &SelectedI, int &SelectedJ,::Time tS,LinkedList<Button> &BTT,LinkedList<LichDatSan> &Lds,fstream &file4, fstream& file3,int &SSan,Font &a,LinkedList<KhachHang> &B,fstream &file2,Date &HienThi){
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

void BtHuy_GDDatSan(int &SelectedI, int &SelectedJ,::Time tS,LinkedList<Button> &BTT,LinkedList<LichDatSan> &Lds, fstream& file3,Date &HienThi){
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

void BtThanhToan_GDDatSan(int &SelectedI, int &SelectedJ,LinkedList<ThanhToan> &TToan,LinkedList<Button> &BTT,LinkedList<LichDatSan> &Lds, fstream& file3,Date &HienThi, fstream& file5, fstream& file4,int &SSan,LinkedList<KhachHang> &B,LinkedList<San> &A,Font &a){
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

void GDDatSan(Font &a,LinkedList<LichDatSan> &Lds,LinkedList<KhachHang> &B,RenderWindow &DatSan,int SSan, fstream& file3,fstream& file2,fstream& file4,fstream& file5,LinkedList<ThanhToan> &TToan,LinkedList<San> &A){
	
    int SelectedI = 0,SelectedJ=0;
	
	LinkedList<::Time> LLTime;
	
	::Time tS(OPEN_TIME);
	::Time tE(CLOSE_TIME);
	for(::Time i=tS;i!=tE;i=i+30){
		LLTime.add(i);
	}
	
	Date HienThi;
	HienThi=HienThi.getCurrentDate();
	
	Button BLen("Up",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1090,250},&a,{1100,250});
	Button BXuong("Down",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1090,356},&a,{1100,356});
	Button BNgay("Ngày",Vector2f(57.f, 30.f),20,Color(0,0,0),Color::White,{470,30},&a,{475,30});
	Button BThang("Tháng",Vector2f(57.f, 30.f),20,Color(0,0,0),Color::White,{605,30},&a,{603,30});
	Button BNam("Nam",Vector2f(57.f, 30.f),20,Color(0,0,0),Color::White,{730,30},&a,{740,30});
	Button BSearch("Search",Vector2f(130.f, 56.f),30,Color::Blue,Color::White,{900,16},&a,{900,16});
	Button BDat("Dat",Vector2f(147.f, 101.f),30,Color::Blue,Color::White,{323,734},&a,{335,734});
	Button BThanhToan("Thanh Toan",{188,101},30,Color::Blue,Color::White,{507,734},&a,{515,734});
	Button BHuy("Huy",Vector2f(152.f, 101.f),30,Color::Blue,Color::White,{733,734},&a,{745,734});
	Button BDay(HienThi.getCurrentDate().getDate(),Vector2f(150.f, 40.f),25,Color::Blue,Color::White,{230,25},&a,{230,25});
	Button BQuayLai("Quay Lai",{135,50},20,Color::Blue,Color::White,{0,0},&a,{10,10});
	Button BHienThiS("San "+to_string(SSan),Vector2f(115.f, 85.f),30,Color::Blue,Color::White,{1062,123},&a,{1082,145});
	
	Textbox TBNgay(25,Color::White,false,&a,{535,30});
	Textbox TBThang(25,Color::White,false,&a,{672,30});
	Textbox TBNam(25,Color::White,false,&a,{808,30});
	Button TBBNgay("",Vector2f(50.f, 53.f),20,Color::Blue,Color::White,{525,16},&a,{530,30});
	Button TBBThang("",Vector2f(50.f, 53.f),20,Color::Blue,Color::White,{665,16},&a,{670,30});
	Button TBBNam("",Vector2f(100.f, 53.f),20,Color::Blue,Color::White,{790,16},&a,{795,30});
	
	TBNgay.setLimit(true,1);
	TBThang.setLimit(true,1);
	TBNam.setLimit(true,3);
	
	Texture TTGDSan;
	Sprite SPGDSan = loadSprite(TTGDSan,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\GDDatSan.png",{0,0});
	Texture TTButtonHTSan;
	Sprite SPButtonHTSan = loadSprite(TTButtonHTSan,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonHTSan.png",BHienThiS.getPosition());
	Texture TTButtonHTDate;
	Sprite SPButtonHTDate = loadSprite(TTButtonHTDate,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonHTDate.png",{185,16});
	Texture TTButtonLen;
	Sprite SPButtonLen = loadSprite(TTButtonLen,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonLen.png",BLen.getPosition());
	Texture TTButtonXuong;
	Sprite SPButtonXuong = loadSprite(TTButtonXuong,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonXuong.png",BXuong.getPosition());
	Texture TTButtonHuy;
	Sprite SPButtonHuy = loadSprite(TTButtonHuy,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonHuy.png",BHuy.getPosition());
	Texture TTButtonTT;
	Sprite SPButtonTT = loadSprite(TTButtonTT,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonTT2.png",BThanhToan.getPosition());
	Texture TTButtonSearch;
	Sprite SPButtonSearch = loadSprite(TTButtonSearch,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonSearch.png",BSearch.getPosition());
	Texture TTButtonDat;
	Sprite SPButtonDat = loadSprite(TTButtonDat,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonDat.png",BDat.getPosition());
	Texture TTButtonNgay;
	Sprite SPButtonNgay = loadSprite(TTButtonNgay,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonDay.png",TBBNgay.getPosition());
	Texture TTButtonThang;
	Sprite SPButtonThang = loadSprite(TTButtonThang,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonDay.png",TBBThang.getPosition());
	Texture TTButtonNam;
	Sprite SPButtonNam = loadSprite(TTButtonNam,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonYear.png",TBBNam.getPosition());
	Texture TTButtonQuayLai;
	Sprite SPButtonQuayLai = loadSprite(TTButtonQuayLai,"D:\\cpp\\PBL2\\Pictures\\GDDatSan\\ButtonQuayLai.png",{0,0});
	
	
	Texture Mid;
	if (!Mid.loadFromFile("D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonTT.png")) {
        cerr << "Khong the load hinh anh " <<endl;
    }
    
	
	LinkedList<Button> BTime;
	for(int i=1;i<=LLTime.size();i++){
		Button b(LLTime[i].getHaM(),{100,62},20,Color::Black,Color::White,{float(Left),float(102+85*(i-1))},&a,{float(Left+15)+25,float(120+85*(i-1))});
		BTime.add(b);
	}
	LinkedList<Sprite> LL_SP;
    for(int i=1;i<=BTime.size();i++){
    	Sprite Sp;
    	Sp.setTexture(Mid);
    	Sp.setPosition(BTime[i].getPosition());
    	LL_SP.add(Sp);
	}
	
	LinkedList<Button> BTT;
	for(int i=1;i<=LLTime.size();i++){
		Button c("Con Trong",{710,62},20,Color::Black,Color::White,{float(Left)+100+1,float(102+85*(i-1))},&a,{float(Left+15)+125+1,float(120+85*(i-1))});
		BTT.add(c);
	}
	
	PrintTT_GDDatSan(Lds,tS,B,BTT,SSan);
	
	while (DatSan.isOpen()) {
        Event event;
        while (DatSan.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                DatSan.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			
           			Bt_Up_Down_GDDatSan(BTime,LLTime,BLen,BXuong,BTT,DatSan,LL_SP);
           			
           			get_SelectedIJ_GDDatSan(BTime,BTT,DatSan,SelectedI,SelectedJ);
					
					if(!TBBNgay.isMouseOver(DatSan)) TBNgay.setSelected(true);
					else TBNgay.setSelected(false);
					if(!TBBThang.isMouseOver(DatSan)) TBThang.setSelected(true);
					else TBThang.setSelected(false);
					if(!TBBNam.isMouseOver(DatSan)) TBNam.setSelected(true);
					else TBNam.setSelected(false);
					if(!BSearch.isMouseOver(DatSan)){
						int ngay,thang,nam;
						try{
							for(int i=1;i<=BTT.size();i++){
								BTT[i].setText("Con Trong");
							}
							ngay=stoi(TBNgay.getText());
							thang=stoi(TBThang.getText());
							nam=stoi(TBNam.getText());
							Date D(stoi(TBNgay.getText()),stoi(TBThang.getText()),stoi(TBNam.getText()));
							if(D.isValid()){
								HienThi=D;
								BDay.setText(D.getDate());
								
								PrintTT_GDDatSan(Lds,tS,B,BTT,SSan,D);
							}
							SelectedI=0;
							SelectedJ=0;
						}
						catch(invalid_argument &e){}
					}
					if(!BQuayLai.isMouseOver(DatSan)){
						return;
					}
					if(!BDat.isMouseOver(DatSan)){
						BtDatSan_GDDatSan(SelectedI,SelectedJ,tS,BTT,Lds,file4,file3,SSan,a,B,file2,HienThi);
					}
					if(!BHuy.isMouseOver(DatSan)){
						if(SelectedI!=0 && SelectedJ!=0){
							BtHuy_GDDatSan(SelectedI,SelectedJ,tS,BTT,Lds,file3,HienThi);
						}
					}
					if(!BThanhToan.isMouseOver(DatSan)){
						BtThanhToan_GDDatSan(SelectedI,SelectedJ,TToan,BTT,Lds,file3,HienThi,file5,file4,SSan,B,A,a);
					}
				}
				
			}
			if(event.type == Event::TextEntered){
				TBNgay.typeOnNumber(event);
				TBThang.typeOnNumber(event);
				TBNam.typeOnNumber(event);
			}
    	}
    	DatSan.clear();
    	
    	
		BQuayLai.drawTo(DatSan);
    	BLen.drawTo(DatSan);
		BXuong.drawTo(DatSan);
		BSearch.drawTo(DatSan);
		BDat.drawTo(DatSan);
		BHuy.drawTo(DatSan);
		BThanhToan.drawTo(DatSan);
		
    	TBBNgay.drawTo(DatSan);
		TBBThang.drawTo(DatSan);
		TBBNam.drawTo(DatSan);
    	
    	DatSan.draw(SPGDSan);
    	
    	DatSan.draw(SPButtonHTSan);
    	DatSan.draw(SPButtonHTDate);
    	DatSan.draw(SPButtonLen);
    	DatSan.draw(SPButtonXuong);
    	DatSan.draw(SPButtonHuy);
    	DatSan.draw(SPButtonTT);
    	DatSan.draw(SPButtonSearch);
    	DatSan.draw(SPButtonDat);
    	DatSan.draw(SPButtonNgay);
    	DatSan.draw(SPButtonThang);
    	DatSan.draw(SPButtonNam);
    	DatSan.draw(SPButtonQuayLai);
    	
    	BDay.drawTextTo(DatSan);
    	BHienThiS.drawTextTo(DatSan);
    	
    	BNgay.drawTextTo(DatSan);
		BThang.drawTextTo(DatSan);
		BNam.drawTextTo(DatSan);
		TBNgay.drawTo(DatSan);
		TBThang.drawTo(DatSan);
		TBNam.drawTo(DatSan);
		
		setColor_GDDatSan(BTT,BTime,SelectedI,SelectedJ);
		
    	setAvailable_Draw_GDDatSan(LLTime,BTT,BTime,DatSan,LL_SP);
		
    	DatSan.display();
    	
	}
}

int GDThemSan(Font &a,LinkedList<San> &A){
	RenderWindow ThemSan(VideoMode(300, 400), "ThemSan", Style::Default);
	
	Button BSan5("San 5",Vector2f(140.f, 80.f),30,Color::Blue,Color::White,{80,80},&a,{110,110});
	Button BSan7("San 7",Vector2f(140.f, 80.f),30,Color::Blue,Color::White,{80,240},&a,{110,260});
	
	Texture TTGDThemSan;
	Sprite SPGDThemSan = loadSprite(TTGDThemSan,"D:\\cpp\\PBL2\\Pictures\\GDThemSan\\GDThemSan.png",{0,0});
	Texture TTButtonSan5;
	Sprite SPButtonSan5 = loadSprite(TTButtonSan5,"D:\\cpp\\PBL2\\Pictures\\GDThemSan\\ButtonSan5.png",{80,80});
	Texture TTButtonSan7;
	Sprite SPButtonSan7 = loadSprite(TTButtonSan7,"D:\\cpp\\PBL2\\Pictures\\GDThemSan\\ButtonSan7.png",{80,240});
	
	
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
           				San c(++MaxSan,"San5",GIA_5,true);
           				A.add(c);
						return 1;
					}
					if(!BSan7.isMouseOver(ThemSan)){
           				San c(++MaxSan,"San7",GIA_7,true);
           				A.add(c);
						return 1;
					}
				}
				
			}
    	}
    	ThemSan.clear();
    	
    	BSan5.drawTo(ThemSan);
    	BSan7.drawTo(ThemSan);
    	
    	ThemSan.draw(SPGDThemSan);
    	ThemSan.draw(SPButtonSan5);
    	ThemSan.draw(SPButtonSan7);
    	
    	ThemSan.display();
    	
	}
	return 0;
}

void Bt_Up_Down_GDSan(LinkedList<San> &A,LinkedList<Button> &BSan,Button &BLen,Button &BXuong,RenderWindow &MENU,LinkedList<Sprite> &LL_SP){
	if(A.size()!=0){
		if(!(BSan[A.size()].getTop()>Top && BSan[A.size()].getBot()<Bot)){
 			if(!BXuong.isMouseOver(MENU)){
 				for(int i=1;i<=A.size();i++){
					BSan[i].setPosition({float(Left),float(BSan[i].getTop()-Bot+Top+80)});
					BSan[i].setTextPosition({float(Left+15),float(BSan[i].getTop()+18)});
					LL_SP[i].setPosition({float(Left),float(LL_SP[i].getPosition().y-Bot+Top+80)});
				}
			}
		}
		if(!(BSan[1].getTop()>Top && BSan[1].getBot()<Bot)){
 			if(!BLen.isMouseOver(MENU)){
 				for(int i=1;i<=A.size();i++){
					BSan[i].setPosition({float(Left),float(BSan[i].getTop()+Bot-Top-80)});
					BSan[i].setTextPosition({float(Left+15),float(BSan[i].getTop()+18)});
					LL_SP[i].setPosition({float(Left),float(LL_SP[i].getPosition().y+Bot-Top-80)});
				}
			}
		}
	}
}

void setSelected_setColor_GDSan(LinkedList<San> &A,LinkedList<Button> &BSan,RenderWindow &MENU,int &Selected){
	for(int i=1;i<=A.size();i++){
		if(!BSan[i].isMouseOver(MENU)){
			if(Selected!=i){
				if(Selected!=0) BSan[Selected].setTextColor(Color::Black);
				Selected=i;
				BSan[i].setTextColor(Color::Red);
			}
			else{
				Selected=0;
				BSan[i].setTextColor(Color::Black);
			}
		}
	}
}

void BXoa_GDSan(LinkedList<San> &A,LinkedList<Button> &BSan,fstream &file,int &Selected,LinkedList<Sprite> &LL_SP){
	if(Selected!=0){
		for(int i=Selected+1;i<=A.size();i++){
			BSan[i].setPosition({BSan[i].getPosition().x,BSan[i].getPosition().y-85});
			BSan[i].setTextPosition({float(Left+15),float(BSan[i].getTop()+18)});
			LL_SP[i].setPosition({LL_SP[i].getPosition().x,LL_SP[i].getPosition().y-85});
		}
		A.del(Selected-1);
		BSan.del(Selected-1);
		LL_SP.del(Selected-1);
		Selected=0;
		ghiFile(file,A);
	}
}

void BThemSan_GDSan(Font &a,LinkedList<San> &A,LinkedList<Button> &BSan,fstream &file,fstream &file4,LinkedList<Sprite> &LL_SP,Texture &Mid){
	if(GDThemSan(a,A)){	
		Button b(A[A.size()].thongTinSan2(),{810,62},20,Color::Black,Color::Black,{float(Left),BSan[BSan.size()].getPosition().y+85},&a,{float(Left+15),BSan[BSan.size()].getPosition().y+85+18});
		Sprite Sp;
		Sp.setTexture(Mid);
		Sp.setPosition(b.getPosition());
		LL_SP.add(Sp);
		BSan.add(b);
		ghiFile(file,A);
		ghiFile(file4);
	}
}

void BSuaThongTin_GDSan(LinkedList<San> &A,LinkedList<Button> &BSan,fstream &file,int &Selected){
	if(Selected!=0){
		if(A[Selected].getLoaiSan()=="San5"){
			A[Selected].setLoaiSan("San7");
			A[Selected].setGia(GIA_7);
		}
		else{
			A[Selected].setLoaiSan("San5");
			A[Selected].setGia(GIA_5);
		}
		BSan[Selected].setText(A[Selected].thongTinSan2());
		ghiFile(file,A);
	}
}

void BSua_GDSan(LinkedList<San> &A,LinkedList<Button> &BSan,fstream &file,int &Selected){
	if(Selected!=0){
		A[Selected].setTT();
		BSan[Selected].setText(A[Selected].thongTinSan2());
		ghiFile(file,A);
	}
}

void drawButton_GDSan(LinkedList<Button> &BSan,RenderWindow &MENU,LinkedList<Sprite> &LL_SP){
	for(int i=1;i<=BSan.size();i++){
		if(BSan[i].getTop()>Top && BSan[i].getBot()<Bot){
			BSan[i].setIsAva(true);
			MENU.draw(LL_SP[i]);
			BSan[i].drawTextTo(MENU);
		}
		else BSan[i].setIsAva(false);
	}
}

void GDSan(fstream& file,LinkedList<San> &A,RenderWindow &MENU,LinkedList<LichDatSan> &Lds,LinkedList<KhachHang> &B, fstream& file3,fstream& file2,fstream& file4,fstream& file5,LinkedList<ThanhToan> &TToan){

    int Selected = 0;
	
	Font a;
	a.loadFromFile("Font\\arial.ttf");
	
	Button BThemSan("+",Vector2f(82.f, 82.f),50,Color::Blue,Color::White,{1090,127},&a,{1100,130});
	Button BXoaSan("-",Vector2f(82.f, 82.f),50,Color::Blue,Color::White,{1090,233},&a,{1100,233});
	Button BLen("Up",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1090,339},&a,{1100,339});
	Button BXuong("Down",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1090,445},&a,{1100,445});
	Button BSuaThongTin("Sua Thong Tin San",Vector2f(269.f, 101.f),30,Color::Blue,Color::White,{725,734},&a,{725,734});
	Button BSuaTrangThai("Sua Trang Thai San",Vector2f(274.f, 101.f),30,Color::Blue,Color::White,{230,734},&a,{230,734});
	Button BDatSan("Dat San",{147,101},30,Color::Blue,Color::White,{541,734},&a,{541,734});
	Button BQuayLai("Quay Lai",{135,50},20,Color::Blue,Color::White,{0,0},&a,{10,10});
	
	LinkedList<Button> BSan;
	for(int i=1;i<=A.size();i++){
		Button b(A[i].thongTinSan2(),{810,62},20,Color::Black,Color::Black,{float(Left),float(102+85*(i-1))},&a,{float(Left+15),float(120+85*(i-1))});
		BSan.add(b);
	}
	
	Texture TTGDSan;
	Sprite SPGDSan = loadSprite(TTGDSan,"D:\\cpp\\PBL2\\Pictures\\GDSan\\GDSan.png",{0,0});
	Texture TTButtonQuayLai;
	Sprite SPButtonQuayLai = loadSprite(TTButtonQuayLai,"D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonQuayLai.png",BQuayLai.getPosition());
	Texture TTButtonThem;
	Sprite SPButtonThem = loadSprite(TTButtonThem,"D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonThem.png",BThemSan.getPosition());
	Texture TTButtonXoa;
	Sprite SPButtonXoa = loadSprite(TTButtonXoa,"D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonXoa.png",BXoaSan.getPosition());
	Texture TTButtonLen;
	Sprite SPButtonLen = loadSprite(TTButtonLen,"D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonLen.png",BLen.getPosition());
	Texture TTButtonXuong;
	Sprite SPButtonXuong = loadSprite(TTButtonXuong,"D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonXuong.png",BXuong.getPosition());
	Texture TTButtonSua;
	Sprite SPButtonSua = loadSprite(TTButtonSua,"D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonSua.png",BSuaTrangThai.getPosition());
	Texture TTButtonSuaTT;
	Sprite SPButtonSuaTT = loadSprite(TTButtonSuaTT,"D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonSuaTT.png",BSuaThongTin.getPosition());
	Texture TTButtonDat;
	Sprite SPButtonDat = loadSprite(TTButtonDat,"D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonDat.png",BDatSan.getPosition());
	
	Texture Mid;
	if (!Mid.loadFromFile("D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonTT.png")) {
        cerr << "Khong the load hinh anh " <<endl;
    }
    
    LinkedList<Sprite> LL_SP;
    for(int i=1;i<=A.size();i++){
    	Sprite Sp;
    	Sp.setTexture(Mid);
    	Sp.setPosition(BSan[i].getPosition());
    	LL_SP.add(Sp);
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
           			
           			Bt_Up_Down_GDSan(A,BSan,BLen,BXuong,MENU,LL_SP);
           	 		
           	 		setSelected_setColor_GDSan(A,BSan,MENU,Selected);
           	 		
					if(!BXoaSan.isMouseOver(MENU)){
						BXoa_GDSan(A,BSan,file,Selected,LL_SP);
					}
					if(!BSuaTrangThai.isMouseOver(MENU)){
						BSua_GDSan(A,BSan,file,Selected);
					}
					if(!BThemSan.isMouseOver(MENU)){
						BThemSan_GDSan(a,A,BSan,file,file4,LL_SP,Mid);
					}
					if(!BSuaThongTin.isMouseOver(MENU)){
						BSuaThongTin_GDSan(A,BSan,file,Selected);
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
		
		MENU.draw(SPGDSan);
		
		drawButton_GDSan(BSan,MENU,LL_SP);
		
		MENU.draw(SPButtonQuayLai);
		MENU.draw(SPButtonThem);
		MENU.draw(SPButtonXoa);
		MENU.draw(SPButtonLen);
		MENU.draw(SPButtonXuong);
		MENU.draw(SPButtonSua);
		MENU.draw(SPButtonSuaTT);
		MENU.draw(SPButtonDat);
		
        MENU.display();
    }
}

int GDThemKH(Font &a,string &tenKH,string &sdt){
	RenderWindow ThemKH(VideoMode(600, 500), "ThemKH", Style::Default);
	
	Textbox TBTenKH(20,Color::White,false,&a,{115,118});
	Textbox TBSdt(20,Color::White,false,&a,{115,225});
	
	Button BTenKH("",Vector2f(400.f, 45.f),30,Color::Blue,Color::White,{100,108},&a,{0,0});
	Button BSdt("",Vector2f(400.f, 45.f),30,Color::Blue,Color::White,{100,215},&a,{0,0});
	Button BSubmit("Xac nhan",Vector2f(270.f, 55.f),30,Color::Blue,Color::White,{170,335},&a,{255,410});
	
	TBTenKH.setLimit(true,30);
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
	
	TTenKH.setPosition({100,75});
	TSdt.setPosition({100,180});
	
	Texture TTGDThemKh;
	Sprite SPGDThemKH = loadSprite(TTGDThemKh,"D:\\cpp\\PBL2\\Pictures\\GDThemKH\\GDThemKH.png",{0,0});
	Texture TTSDT;
	Sprite SPSDT = loadSprite(TTSDT,"D:\\cpp\\PBL2\\Pictures\\GDThemKH\\SDT.png",{100,180});
	Texture TTTenKH;
	Sprite SPTenKH = loadSprite(TTTenKH,"D:\\cpp\\PBL2\\Pictures\\GDThemKH\\TenKH.png",{100,75});
	Texture TTSubmit;
	Sprite SPSubmit = loadSprite(TTSubmit,"D:\\cpp\\PBL2\\Pictures\\GDThemKH\\ButtonXacNhan.png",{170,335});
	Texture TTTextTenKH;
	Sprite SPTextTenKH = loadSprite(TTTextTenKH,"D:\\cpp\\PBL2\\Pictures\\GDThemKH\\Textbox.png",{100,108});
	Texture TTTextSDT;
	Sprite SPTextSDT = loadSprite(TTTextSDT,"D:\\cpp\\PBL2\\Pictures\\GDThemKH\\Textbox.png",{100,215});
	
	
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
				TBSdt.typeOnNumber(event);
			}
    	}
    	ThemKH.clear();
    	BTenKH.drawTo(ThemKH);
    	BSdt.drawTo(ThemKH);
    	BSubmit.drawTo(ThemKH);
    	
    	ThemKH.draw(TTenKH);
    	ThemKH.draw(TSdt);
    	
    	ThemKH.draw(SPGDThemKH);
    	ThemKH.draw(SPSDT);
    	ThemKH.draw(SPTenKH);
    	ThemKH.draw(SPSubmit);
    	ThemKH.draw(SPTextTenKH);
    	ThemKH.draw(SPTextSDT);
    	
    	
    	TBTenKH.drawTo(ThemKH);
    	TBSdt.drawTo(ThemKH);
    	
    	ThemKH.display();
    	
	}
	return 0;
}

void createLSDS_GDLichSuDatSan(int &i,LinkedList<Button> &LLB_LSDS,LinkedList<LichDatSan> &Lds,int KHDatSan,Font &a){
	for(int j=1;j<=Lds.size();j++){
		if(Lds[j].getMaKhachHang()==KHDatSan){
			++i;
			Button b(Lds[j].getLds2(),{810,62},20,Color::Black,Color::Black,{float(Left),float(102+85*(i-1))},&a,{float(Left+15),float(120+85*(i-1))});
			LLB_LSDS.add(b);
		}
	}
}

void Bt_Up_Down_GDLichSuDatSan(int &i,LinkedList<Button> &LLB_LSDS,Button &BLen,Button &BXuong,RenderWindow &LSDS,LinkedList<Sprite> &LL_SP){
	if(i!=0){
		if(!(LLB_LSDS[LLB_LSDS.size()].getTop()>Top && LLB_LSDS[LLB_LSDS.size()].getBot()<Bot)){
 			if(!BXuong.isMouseOver(LSDS)){;
 				for(int j=1;j<=LLB_LSDS.size();j++){
					LLB_LSDS[j].setPosition({float(Left),float(LLB_LSDS[j].getTop()-Bot+Top+80)});
					LLB_LSDS[j].setTextPosition({float(Left+15),float(LLB_LSDS[j].getTop()+18)});
					LL_SP[j].setPosition({float(Left),float(LL_SP[j].getPosition().y-Bot+Top+80)});
				}
			}
		}
	}
	if(i!=0){
		if(!(LLB_LSDS[1].getTop()>Top && LLB_LSDS[1].getBot()<Bot)){
 			if(!BLen.isMouseOver(LSDS)){
 				for(int j=1;j<=LLB_LSDS.size();j++){
					LLB_LSDS[j].setPosition({float(Left),float(LLB_LSDS[j].getTop()+Bot-Top-80)});
					LLB_LSDS[j].setTextPosition({float(Left+15),float(LLB_LSDS[j].getTop()+18)});
					LL_SP[j].setPosition({float(Left),float(LL_SP[j].getPosition().y+Bot-Top-80)});
				}
			}
		}
	}
}

void drawButton_GDLichSuDatSan(LinkedList<Button> &LLB_LSDS,RenderWindow &LSDS,int &i,LinkedList<Sprite> &LL_SP){
	for(int j=1;j<=i;j++){
		if(LLB_LSDS[j].getTop()>Top && LLB_LSDS[j].getBot()<Bot){
			LLB_LSDS[j].setIsAva(true);
			LSDS.draw(LL_SP[j]);
			LLB_LSDS[j].drawTextTo(LSDS);
		}
		else LLB_LSDS[j].setIsAva(false);
	}
}

void GDLichSuDatSan(Font &a,int KHDatSan,LinkedList<LichDatSan> &Lds,RenderWindow &LSDS){
	
	LinkedList<Button> LLB_LSDS;

	Button BLen("Up",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1085,122},&a,{1100,130});
	Button BXuong("Down",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1085,228},&a,{1100,233});
	Button BQuayLai("Quay Lai",{135,50},20,Color::Blue,Color::White,{0,0},&a,{10,10});
	
	int i=0;
	
	Texture TTGD_LSDS;
	Sprite SPGD_LSDS = loadSprite(TTGD_LSDS,"D:\\cpp\\PBL2\\Pictures\\GDLichSuDatSan\\GDLichSuDatSan.png",{0,0});
	Texture TTButtonQuayLai;
	Sprite SPButtonQuayLai = loadSprite(TTButtonQuayLai,"D:\\cpp\\PBL2\\Pictures\\GDLichSuDatSan\\ButtonQuayLai.png",BQuayLai.getPosition());
	Texture TTButtonLen;
	Sprite SPButtonLen = loadSprite(TTButtonLen,"D:\\cpp\\PBL2\\Pictures\\GDLichSuDatSan\\ButtonLen.png",BLen.getPosition());
	Texture TTButtonXuong;
	Sprite SPButtonXuong = loadSprite(TTButtonXuong,"D:\\cpp\\PBL2\\Pictures\\GDLichSuDatSan\\ButtonXuong.png",BXuong.getPosition());
	
	Texture Mid;
	if (!Mid.loadFromFile("D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\ButtonTT.png")) {
        cerr << "Khong the load hinh anh " <<endl;
    }
	
	createLSDS_GDLichSuDatSan(i,LLB_LSDS,Lds,KHDatSan,a);
	
	LinkedList<Sprite> LL_SP;
    for(int j=1;j<=LLB_LSDS.size();j++){
    	Sprite Sp;
    	Sp.setTexture(Mid);
    	Sp.setPosition(LLB_LSDS[j].getPosition());
    	LL_SP.add(Sp);
	}
	
	while (LSDS.isOpen()) {
        Event event;
        while (LSDS.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                LSDS.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			
           			Bt_Up_Down_GDLichSuDatSan(i,LLB_LSDS,BLen,BXuong,LSDS,LL_SP);
					
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
		
		LSDS.draw(SPGD_LSDS);
		LSDS.draw(SPButtonQuayLai);
		LSDS.draw(SPButtonLen);
		LSDS.draw(SPButtonXuong);
		
		drawButton_GDLichSuDatSan(LLB_LSDS,LSDS,i,LL_SP);
    	LSDS.display();
    	
	}
}

void Bt_Up_Down_GDKhachHang(LinkedList<KhachHang> &B,LinkedList<Button> &BKH,Button &BLen,Button &BXuong,RenderWindow &MENU,LinkedList<Sprite> &LL_SP){
	if(B.size()!=0){
		if(!(BKH[B.size()].getTop()>Top && BKH[B.size()].getBot()<Bot)){
 			if(!BXuong.isMouseOver(MENU)){
 				for(int i=1;i<=B.size();i++){
					BKH[i].setPosition({float(Left),float(BKH[i].getTop()-Bot+Top+80)});
					BKH[i].setTextPosition({float(Left+15),float(BKH[i].getTop()+18)});
					LL_SP[i].setPosition({float(Left),float(LL_SP[i].getPosition().y-Bot+Top+80)});
				}
			}
		}
		if(!(BKH[1].getTop()>Top && BKH[1].getBot()<Bot)){
 			if(!BLen.isMouseOver(MENU)){
 				for(int i=1;i<=B.size();i++){
					BKH[i].setPosition({float(Left),float(BKH[i].getTop()+Bot-Top-80)});
					BKH[i].setTextPosition({float(Left+15),float(BKH[i].getTop()+18)});
					LL_SP[i].setPosition({float(Left),float(LL_SP[i].getPosition().y+Bot-Top-80)});
				}
			}
		}
	}
}

void setSelected_setColor_GDKhachHang(LinkedList<KhachHang> &B,LinkedList<Button> &BKH,int &Selected,RenderWindow &MENU){
	for(int i=1;i<=B.size();i++){
		if(!BKH[i].isMouseOver(MENU)){
			if(Selected!=i){
				if(Selected!=0) BKH[Selected].setTextColor(Color::Black);
				Selected=i;
				BKH[i].setTextColor(Color::Red);
			}
			else{
				Selected=0;
				BKH[i].setTextColor(Color::Black);
			}
		}
	}
}

void BXoa_GDKhachHang(LinkedList<KhachHang> &B,LinkedList<Button> &BKH,int &Selected,fstream &file2){
	if(Selected!=0){
		for(int i=Selected+1;i<=B.size();i++){
			BKH[i].setPosition({BKH[i].getPosition().x,BKH[i].getPosition().y-50});
		}
		B.del(Selected-1);
		BKH.del(Selected-1);
		Selected=0;
		ghiFile(file2,B);
	}
}

void BThem_GDKhachHang(Font &a,LinkedList<KhachHang> &B,LinkedList<Button> &BKH,fstream &file2,fstream &file4,LinkedList<Sprite> &LL_SP,Texture &Mid){
	string ten,sdt;
	if(GDThemKH(a,ten,sdt)){
		KhachHang kh1(++MaxKH,ten,sdt);
		B.add(kh1);
		Button kh2(B[B.size()].ThongTinKH2(),{810,62},20,Color::Black,Color::Black,{float(Left),BKH[BKH.size()].getPosition().y+80},&a,{float(Left+15),BKH[BKH.size()].getPosition().y+80+18});
		BKH.add(kh2);
		Sprite Sp;
		Sp.setTexture(Mid);
		Sp.setPosition(kh2.getPosition());
		LL_SP.add(Sp);
		ghiFile(file2,B);
		ghiFile(file4);
	}
}

void BSua_GDKhachHang(Font &a,LinkedList<KhachHang> &B,LinkedList<Button> &BKH,fstream &file2,int &Selected){
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

void setAvailable_GDKhachHang(LinkedList<Button> &BKH,RenderWindow &MENU,LinkedList<Sprite> &LL_SP){
	for(int i=1;i<=BKH.size();i++){
		if(BKH[i].getTop()>Top && BKH[i].getBot()<Bot){
			BKH[i].setIsAva(true);
			MENU.draw(LL_SP[i]);
			BKH[i].drawTextTo(MENU);
		}
		else BKH[i].setIsAva(false);
	}
}

void GDKhachHang(fstream& file2,LinkedList<KhachHang> &B,RenderWindow &MENU,fstream &file4,LinkedList<LichDatSan> &Lds){

    int Selected = 0;
	
	Font a;
	a.loadFromFile("Font\\arial.ttf");
	
	Button BThemKH("+",Vector2f(82.f, 82.f),50,Color::Blue,Color::White,{1085,122},&a,{1100,130});
	Button BXoaKH("-",Vector2f(82.f, 82.f),50,Color::Blue,Color::White,{1085,228},&a,{1100,233});
	Button BLen("Up",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1085,334},&a,{1100,339});
	Button BXuong("Down",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1085,440},&a,{1100,445});
	Button BSuaThongTinKH("Sua Thong Tin Khach Hang",Vector2f(350.f, 110.f),30,Color::Blue,Color::White,{232,719},&a,{232,734});
	Button BLichSuDatSan("Lich Su Dat San",Vector2f(350.f, 110.f),30,Color::Blue,Color::White,{625,719},&a,{625,734});
	Button BQuayLai("Quay Lai",{135,50},20,Color::Blue,Color::White,{0,0},&a,{10,10});
	
	
	LinkedList<Button> BKH;
	for(int i=1;i<=B.size();i++){
		Button b(B[i].ThongTinKH2(),{810,62},20,Color::Black,Color::Black,{float(Left),float(102+85*(i-1))},&a,{float(Left+15),float(120+85*(i-1))});
		BKH.add(b);
	}
	
	Texture TTGDKhachHang;
	Sprite SPGDKhachHang = loadSprite(TTGDKhachHang,"D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\GDKhachHang.png",{0,0});
	Texture TTButtonQuayLai;
	Sprite SPButtonQuayLai = loadSprite(TTButtonQuayLai,"D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\ButtonQuayLai.png",BQuayLai.getPosition());
	Texture TTButtonThem;
	Sprite SPButtonThem = loadSprite(TTButtonThem,"D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\ButtonThem.png",BThemKH.getPosition());
	Texture TTButtonXoa;
	Sprite SPButtonXoa = loadSprite(TTButtonXoa,"D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\ButtonXoa.png",BXoaKH.getPosition());
	Texture TTButtonLen;
	Sprite SPButtonLen = loadSprite(TTButtonLen,"D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\ButtonLen.png",BLen.getPosition());
	Texture TTButtonXuong;
	Sprite SPButtonXuong = loadSprite(TTButtonXuong,"D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\ButtonXuong.png",BXuong.getPosition());
	Texture TTButtonSua;
	Sprite SPButtonSua = loadSprite(TTButtonSua,"D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\ButtonSua.png",BSuaThongTinKH.getPosition());
	Texture TTLSDS;
	Sprite SPLSDS = loadSprite(TTLSDS,"D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\LSDS.png",BLichSuDatSan.getPosition());
	
	
	Texture Mid;
	if (!Mid.loadFromFile("D:\\cpp\\PBL2\\Pictures\\GDKhachHang\\ButtonTT.png")) {
        cerr << "Khong the load hinh anh " <<endl;
    }
    
    LinkedList<Sprite> LL_SP;
    for(int i=1;i<=B.size();i++){
    	Sprite Sp;
    	Sp.setTexture(Mid);
    	Sp.setPosition(BKH[i].getPosition());
    	LL_SP.add(Sp);
	}
	
	while (MENU.isOpen()) {
        Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			
           			Bt_Up_Down_GDKhachHang(B,BKH,BLen,BXuong,MENU,LL_SP);
           	 		
           	 		setSelected_setColor_GDKhachHang(B,BKH,Selected,MENU);
           	 		
					if(!BXoaKH.isMouseOver(MENU)){
						BXoa_GDKhachHang(B,BKH,Selected,file2);
					}
					if(!BThemKH.isMouseOver(MENU)){
						BThem_GDKhachHang(a,B,BKH,file2,file4,LL_SP,Mid);
					}
					if(!BSuaThongTinKH.isMouseOver(MENU)){
						BSua_GDKhachHang(a,B,BKH,file2,Selected);
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
        MENU.clear();
        
        BQuayLai.drawTo(MENU);
        BThemKH.drawTo(MENU);
		BXoaKH.drawTo(MENU);
		BLen.drawTo(MENU);
		BXuong.drawTo(MENU);
		BSuaThongTinKH.drawTo(MENU);
		BLichSuDatSan.drawTo(MENU);
	
		
        MENU.draw(SPGDKhachHang);
        MENU.draw(SPButtonQuayLai);
        MENU.draw(SPButtonThem);
        MENU.draw(SPButtonXoa);
        MENU.draw(SPButtonLen);
        MENU.draw(SPButtonXuong);
        MENU.draw(SPButtonSua);
        MENU.draw(SPLSDS);
       	
    	setAvailable_GDKhachHang(BKH,MENU,LL_SP);
        MENU.display();
    }
}

void getDL_GD_TT_ThongKe(LinkedList<LichDatSan> &Lds,int &Selected,LinkedList<ThanhToan> &TToan,string &MaSan,string &TGEnd,string &TGSt,int &maKH,int &HT){
	int Id=TToan[Selected].getIdLDS();
	for(int j=1;j<=Lds.size();j++){
		if(Lds[j].getMaDatSan()==Id){
			MaSan=to_string(Lds[j].getMaSanBong());
			TGSt=Lds[j].getStTime().getTime().getTime();
			TGEnd=Lds[j].getEnTime().getSDay();
			maKH=Lds[j].getMaKhachHang();
			HT=j;
			break;
		}
	}
}

void GD_TT_ThongKe(Font &a,LinkedList<LichDatSan> &Lds,LinkedList<San> &A,LinkedList<KhachHang> &B,int Selected,LinkedList<ThanhToan> &TToan){
	RenderWindow WinThanhToan(VideoMode(370, 745), "ThanhToan", Style::Default);
	
	string MaSan,TGEnd,TGSt,tenKH,loaiSan;
	int maKH;
	
	int Tong=0;
	int HT;

	getDL_GD_TT_ThongKe(Lds,Selected,TToan,MaSan,TGEnd,TGSt,maKH,HT);
	
	for(int i=1;i<=B.size();i++){
		if(B[i].getTen()==maKH){
			tenKH=B[i].getTenKh();
		}
	}
	
	int giaThue;
	
	for(int i=1;i<=A.size();i++){
		if(A[i].getTen()==stoi(MaSan)){
			loaiSan=A[i].getLoaiSan();
			giaThue=A[i].getGia();
		}
	}
	Tong=TToan[Selected].getTT();
	
	Day D;
	
	Button BSoHD(to_string(MaxTT),Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{140,188},&a,{138,188});
	Button BTGIn(D.getCurrentDay().getSDay(),Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{135,225},&a,{138,225});
	Button BSan(MaSan,Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{60,265},&a,{60,263});
	Button BLoaiSan(loaiSan,Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{100,298},&a,{103,299});
	Button BThoiGian(TGSt+ " - " +TGEnd,Vector2f(300.f, 40.f),20,Color::Black,Color::Black,{20,339},&a,{20,337});	
	Button BGia(to_string(giaThue),Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{120,370},&a,{117,374});
	Button BTenKH(tenKH,Vector2f(100.f, 40.f),20,Color::Black,Color::Black,{70,410},&a,{69,411});
	Button BThanhToan(to_string(Tong),Vector2f(150.f, 40.f),20,Color::Black,Color::Black,{180,458},&a,{180,450});
	Button BOK("ok",Vector2f(250.f, 45.f),30,Color::Blue,Color::White,{65,690},&a,{65,690});
	
	Texture TTGDThanhToan;
	Sprite SPGDThanhToan = loadSprite(TTGDThanhToan,"D:\\cpp\\PBL2\\Pictures\\GDThanhToan\\GDThanhToan.png",{0,0});
	Texture TTButtonXacNhan;
	Sprite SPButtonXacNhan = loadSprite(TTButtonXacNhan,"D:\\cpp\\PBL2\\Pictures\\GDThanhToan\\ButtonXacNhan.png",BOK.getPosition());
	Texture TTQR;
	Sprite SPQR = loadSprite(TTQR,"D:\\cpp\\PBL2\\Pictures\\GDThanhToan\\QR.jpg",{125,510});
	
	while (WinThanhToan.isOpen()) {
        Event event;
        while (WinThanhToan.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                WinThanhToan.close();
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
					if(!BOK.isMouseOver(WinThanhToan)){
						WinThanhToan.close();
					}
				}
				
			}
			
    	}
    	WinThanhToan.clear();
    	BOK.drawTo(WinThanhToan);
    	WinThanhToan.draw(SPGDThanhToan);
    	BSan.drawTextTo(WinThanhToan);
    	BLoaiSan.drawTextTo(WinThanhToan);
    	BThoiGian.drawTextTo(WinThanhToan);
    	BGia.drawTextTo(WinThanhToan);
    	BTenKH.drawTextTo(WinThanhToan);
    	BThanhToan.drawTextTo(WinThanhToan);
    	WinThanhToan.draw(SPButtonXacNhan);
    	WinThanhToan.draw(SPQR);
    	BSoHD.drawTextTo(WinThanhToan);
    	BTGIn.drawTextTo(WinThanhToan);
    	WinThanhToan.display();
    	
	}
}

void Bt_Up_Down_GDThongKe(LinkedList<Button> &BTT,RenderWindow &ThongKe,Button &BLen,Button &BXuong,LinkedList<Sprite> &LL_SP){
	if(BTT.size()!=0){
		if(!(BTT[BTT.size()].getTop()>Top && BTT[BTT.size()].getBot()<Bot)){
 			if(!BXuong.isMouseOver(ThongKe)){
 				for(int i=1;i<=BTT.size();i++){
					BTT[i].setPosition({float(Left),float(BTT[i].getTop()-Bot+Top+80)});
					BTT[i].setTextPosition({float(Left+15),float(BTT[i].getTop()+18)});
					LL_SP[i].setPosition({float(Left),float(LL_SP[i].getPosition().y-Bot+Top+80)});
				}
			}
		}
		if(!(BTT[1].getTop()>Top && BTT[1].getBot()<Bot)){
 			if(!BLen.isMouseOver(ThongKe)){
 				for(int i=1;i<=BTT.size();i++){
					BTT[i].setPosition({float(Left),float(BTT[i].getTop()+Bot-Top-80)});
					BTT[i].setTextPosition({float(Left+15),float(BTT[i].getTop()+18)});
					LL_SP[i].setPosition({float(Left),float(LL_SP[i].getPosition().y+Bot-Top-80)});
				}
			}
		}
	}
}

void setSelected_setColor_GDThongKe(LinkedList<Button> &BTT,RenderWindow &ThongKe,int &Selected){
	for(int i=1;i<=BTT.size();i++){
		if(!BTT[i].isMouseOver(ThongKe)){
			if(Selected!=i){
				if(Selected!=0) BTT[Selected].setTextColor(Color::Black);
				Selected=i;
				BTT[i].setTextColor(Color::Red);
			}
			else{
				Selected=0;
				BTT[i].setTextColor(Color::Black);
			}
		}
	}
}

void TKNam_GDThongKe(int &nam,string &snam,LinkedList<ThanhToan> &TToan,LinkedList<LichDatSan> &Lds,LinkedList<Button> &BTT,int &Tong,int &k,Font &a,LinkedList<Sprite> &LL_SP,Texture &Mid){
	nam=stoi(snam);
	for(int i=1;i<=TToan.size();i++){
		int Id=TToan[i].getIdLDS();
		for(int j=1;j<=Lds.size();j++){
			if(Lds[j].getMaDatSan()==Id){
				if(Lds[j].getStTime().getDate().getYear()==nam){
					k++;
					Button b("Lich dat san: "+TToan[i].getSTT2(),{810,62},20,Color::Black,Color::Black,{float(Left),float(102+85*(k-1))},&a,{float(Left),float(120+85*(k-1))});
					b.setTextPosition({float(Left+15),float(b.getTop()+18)});
					BTT.add(b);
					Sprite Sp;
			    	Sp.setTexture(Mid);
			    	Sp.setPosition(b.getPosition());
			    	LL_SP.add(Sp);
					Tong+=TToan[i].getTT();
				}
			}
		}
	}
}

void TKThang_GDThongKe(int &thang,string &sthang,int &nam,string &snam,LinkedList<ThanhToan> &TToan,LinkedList<LichDatSan> &Lds,LinkedList<Button> &BTT,int &Tong,int &k,Font &a,LinkedList<Sprite> &LL_SP,Texture &Mid){
	nam=stoi(snam);
	thang=stoi(sthang);
	for(int i=1;i<=TToan.size();i++){
		int Id=TToan[i].getIdLDS();
		for(int j=1;j<=Lds.size();j++){
			if(Lds[j].getMaDatSan()==Id){
				if(Lds[j].getStTime().getDate().getYear()==nam && Lds[j].getStTime().getDate().getMonth()==thang){
					k++;
					Button b("Lich dat san: "+TToan[i].getSTT2(),{810,62},20,Color::Black,Color::Black,{float(Left),float(102+85*(k-1))},&a,{float(Left),float(120+85*(k-1))});
					b.setTextPosition({float(Left+15),float(b.getTop()+18)});
					BTT.add(b);
					Sprite Sp;
			    	Sp.setTexture(Mid);
			    	Sp.setPosition(b.getPosition());
			    	LL_SP.add(Sp);
					Tong+=TToan[i].getTT();
				}
			}
		}
	}
}

void TKNgay_GDThongKe(int &ngay,string &sngay,int &thang,string &sthang,int &nam,string &snam,LinkedList<ThanhToan> &TToan,LinkedList<LichDatSan> &Lds,LinkedList<Button> &BTT,int &Tong,int &k,Font &a,LinkedList<Sprite> &LL_SP,Texture &Mid){
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
						Button b("Lich dat san: "+TToan[i].getSTT2(),{810,62},20,Color::Black,Color::Black,{float(Left),float(102+85*(k-1))},&a,{float(Left),float(120+85*(k-1))});
						b.setTextPosition({float(Left+15),float(b.getTop()+18)});
						BTT.add(b);
						Sprite Sp;
				    	Sp.setTexture(Mid);
				    	Sp.setPosition(b.getPosition());
				    	LL_SP.add(Sp);
						Tong+=TToan[i].getTT();
					}
				}
			}
		}
	}
}

void setAvailable_GDThongKe(LinkedList<Button> &BTT,RenderWindow &ThongKe,LinkedList<Sprite> &LL_SP){
	for(int i=1;i<=BTT.size();i++){
		if(BTT[i].getTop()>Top && BTT[i].getBot()<Bot){
			BTT[i].setIsAva(true);
			ThongKe.draw(LL_SP[i]);	
			BTT[i].drawTextTo(ThongKe);
		}
		else BTT[i].setIsAva(false);
	}
}

void GDThongKe(Font &a,RenderWindow &ThongKe,LinkedList<ThanhToan> &TToan,LinkedList<LichDatSan> &Lds,LinkedList<San> &A,LinkedList<KhachHang> &B){
	int Selected=0;
	int Tong=0;
	
	Button BQuayLai("Quay Lai",{135,50},20,Color::Blue,Color::White,{0,0},&a,{10,10});
	Button BSearch("Search",Vector2f(130.f, 56.f),30,Color::Blue,Color::White,{900,13},&a,{900,16});
	Button BLen("Up",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1087,247},&a,{1100,250});
	Button BXuong("Down",Vector2f(82.f, 82.f),30,Color::Blue,Color::White,{1087,353},&a,{1100,356});
	Button BXemThongTin("Xem Thong Tin",Vector2f(320.f, 100.f),30,Color::Blue,Color::White,{225,730},&a,{150,734});
	Button BNgay("Ngày",Vector2f(57.f, 30.f),20,Color(0,0,0),Color::White,{467,28},&a,{475,30});
	Button BThang("Tháng",Vector2f(57.f, 30.f),20,Color(0,0,0),Color::White,{600,25},&a,{603,30});
	Button BNam("Nam",Vector2f(57.f, 30.f),20,Color(0,0,0),Color::White,{725,25},&a,{740,30});
	Button BHTTong("" ,Vector2f(370.f, 100.f),30,Color::Blue,Color::White,{670,730},&a,{770,765});
	
	Textbox TBNgay(25,Color::White,false,&a,{535,27});
	Textbox TBThang(25,Color::White,false,&a,{672,27});
	Textbox TBNam(25,Color::White,false,&a,{808,27});
	Button TBBNgay("",Vector2f(50.f, 53.f),20,Color::Blue,Color::White,{525,13},&a,{530,30});
	Button TBBThang("",Vector2f(50.f, 53.f),20,Color::Blue,Color::White,{660,13},&a,{670,30});
	Button TBBNam("",Vector2f(100.f, 53.f),20,Color::Blue,Color::White,{785,13},&a,{795,30});
	
	TBNgay.setLimit(true,1);
	TBThang.setLimit(true,1);
	TBNam.setLimit(true,3);
	
	LinkedList<Button> BTT;
	
	Texture TTGDThongKe;
	Sprite SPGDThongKe = loadSprite(TTGDThongKe,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\GDThongKe.png",{0,0});
	Texture TTButtonLen;
	Sprite SPButtonLen = loadSprite(TTButtonLen,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\ButtonLen.png",BLen.getPosition());
	Texture TTButtonXuong;
	Sprite SPButtonXuong = loadSprite(TTButtonXuong,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\ButtonXuong.png",BXuong.getPosition());
	Texture TTButtonSearch;
	Sprite SPButtonSearch = loadSprite(TTButtonSearch,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\ButtonSearch.png",BSearch.getPosition());
	Texture TTButtonNgay;
	Sprite SPButtonNgay = loadSprite(TTButtonNgay,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\ButtonDay.png",TBBNgay.getPosition());
	Texture TTButtonThang;
	Sprite SPButtonThang = loadSprite(TTButtonThang,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\ButtonDay.png",TBBThang.getPosition());
	Texture TTButtonNam;
	Sprite SPButtonNam = loadSprite(TTButtonNam,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\ButtonYear.png",TBBNam.getPosition());
	Texture TTButtonQuayLai;
	Sprite SPButtonQuayLai = loadSprite(TTButtonQuayLai,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\ButtonQuayLai.png",{0,0});
	Texture TTButtonTong;
	Sprite SPButtonTong = loadSprite(TTButtonTong,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\ButtonTong.png",BHTTong.getPosition());
	Texture TTButtonXemTT;
	Sprite SPButtonXemTT = loadSprite(TTButtonXemTT,"D:\\cpp\\PBL2\\Pictures\\GDThongKe\\ButtonXemTT.png",BXemThongTin.getPosition());
	
	Texture Mid;
	if (!Mid.loadFromFile("D:\\cpp\\PBL2\\Pictures\\GDSan\\ButtonTT.png")) {
        cerr << "Khong the load hinh anh " <<endl;
    }
    
    LinkedList<Sprite> LL_SP;
	
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
					
					Bt_Up_Down_GDThongKe(BTT,ThongKe,BLen,BXuong,LL_SP);
					
					setSelected_setColor_GDThongKe(BTT,ThongKe,Selected);
					
					if(!BSearch.isMouseOver(ThongKe)){
						BTT.clear();
						int ngay,thang,nam;
						string sngay=TBNgay.getText();
						string sthang=TBThang.getText();
						string snam=TBNam.getText();
						int k=0;
						
						if(snam==""){
						}
						else if(snam!="" && sthang=="" && sngay!=""){
						}
						else if(sngay!="" && sthang!= "" && snam ==""){
						}
						else if(sngay=="" && sthang=="" && stoi(snam)>0){
							TKNam_GDThongKe(nam,snam,TToan,Lds,BTT,Tong,k,a,LL_SP,Mid);
						}
						else if(sngay=="" && stoi(sthang)>0 && stoi(sthang)<=12 && stoi(snam)>0){
							TKThang_GDThongKe(thang,sthang,nam,snam,TToan,Lds,BTT,Tong,k,a,LL_SP,Mid);
						}
						else{
							TKNgay_GDThongKe(ngay,sngay,thang,sthang,nam,snam,TToan,Lds,BTT,Tong,k,a,LL_SP,Mid);
						}
						BHTTong.setText(to_string(Tong));
						Tong=0;
						Selected=0;
					}
					if(!TBBNgay.isMouseOver(ThongKe)) TBNgay.setSelected(true);
					else TBNgay.setSelected(false);
					if(!TBBThang.isMouseOver(ThongKe)) TBThang.setSelected(true);
					else TBThang.setSelected(false);
					if(!TBBNam.isMouseOver(ThongKe)) TBNam.setSelected(true);
					else TBNam.setSelected(false);
					if(!BXemThongTin.isMouseOver(ThongKe)){
						if(Selected!=0){
							GD_TT_ThongKe(a,Lds,A,B,Selected,TToan);
						}
						
					}
				}
				
			}
			if(event.type == Event::TextEntered){
				TBNgay.typeOnNumber(event);
				TBThang.typeOnNumber(event);
				TBNam.typeOnNumber(event);
			}
			
    	}
    	ThongKe.clear();
    	
		BQuayLai.drawTo(ThongKe);
    	BLen.drawTo(ThongKe);
		BXuong.drawTo(ThongKe);
		BSearch.drawTo(ThongKe);
		BNgay.drawTo(ThongKe);
		BThang.drawTo(ThongKe);
		BNam.drawTo(ThongKe);
		BXemThongTin.drawTo(ThongKe);
		
		TBBNgay.drawTo(ThongKe);
		TBBThang.drawTo(ThongKe);
		TBBNam.drawTo(ThongKe);
		
		ThongKe.draw(SPGDThongKe);
		ThongKe.draw(SPButtonLen);
		ThongKe.draw(SPButtonXuong);
		ThongKe.draw(SPButtonSearch);
		ThongKe.draw(SPButtonNgay);
		ThongKe.draw(SPButtonThang);
		ThongKe.draw(SPButtonNam);
		ThongKe.draw(SPButtonQuayLai);
		ThongKe.draw(SPButtonTong);
		ThongKe.draw(SPButtonXemTT);
		
		BHTTong.drawTextTo(ThongKe);
		
		TBNgay.drawTo(ThongKe);
		TBThang.drawTo(ThongKe);
		TBNam.drawTo(ThongKe);
		
		setAvailable_GDThongKe(BTT,ThongKe,LL_SP);
    	ThongKe.display();
    	
	}
}

void docFile_run(LinkedList<San> &A,LinkedList<KhachHang> &B,LinkedList<LichDatSan> &Lds,LinkedList<ThanhToan> &TToan,fstream &file,fstream &file2,fstream &file3,fstream &file4,fstream &file5,fstream &file6){

	file.open("Data\\San.csv",ios::in|ios::out);
	docFile(file,A);
	if (!file.is_open()) {
        cerr << "Không the mo file san" << endl;
        return; 
    }
    
    file2.open("Data\\KhachHang.csv",ios::in|ios::out);
    docFile(file2,B);
    if (!file2.is_open()) {
        cerr << "Không the mo file khach hang" << endl;
        return; 
    }
    
    file3.open("Data\\LichDatSan.csv",ios::in|ios::out);
    docFile(file3,Lds);
    if (!file3.is_open()) {
        cerr << "Không the mo file lich dat san" << endl;
        return; 
    }
    
    file4.open("Data\\MaxSKH.csv",ios::in|ios::out);
    file4>>MaxSan;
    file4.ignore();
    file4>>MaxKH;
    file4.ignore();
    file4>>MaxLDS;
    file4.ignore();
    file4>>MaxTT;
    
    file5.open("Data\\ThanhToan.csv",ios::in|ios::out);
    docFile(file5,TToan);
    if (!file5.is_open()) {
        cerr << "Không the mo file thanh toan" << endl;
        return; 
    }
    
    file6.open("Data\\GiaThueSan.csv",ios::in|ios::out);
    file6>>GIA_5;
    file6.ignore();
    file6>>GIA_7;
}

int nhapGia_GDDoiGiaThue(RenderWindow &DoiGia,Font &a){
	int Gia;
	
	Textbox TBGia(20,Color::White,false,&a,{40,165});
	
	Button BGia("",Vector2f(250.f, 40.f),30,Color::Blue,Color::White,{23,157},&a,{0,0});
	Button BTGia("Nhap gia can doi",Vector2f(300.f, 40.f),30,Color::Black,Color::White,{20,50},&a,{25,100});
	Button BSubmit("Xac nhan",Vector2f(130.f, 75.f),30,Color::Blue,Color::White,{10,275},&a,{90,310});	
	Button BHuy("Huy",Vector2f(130.f, 75.f),30,Color::Blue,Color::White,{160,275},&a,{160,275});
	
	TBGia.setLimit(true,10);
	
	Texture TTGDDoiGia;
	Sprite SPGDDoiGia = loadSprite(TTGDDoiGia,"D:\\cpp\\PBL2\\Pictures\\GDDoiGia\\GDDoiGia.png",{0,0});
	Texture TTHienThi;
	Sprite SPHienThi = loadSprite(TTHienThi,"D:\\cpp\\PBL2\\Pictures\\GDDoiGia\\NhapGia.png",{20,50});
	Texture TTTextbox;
	Sprite SPTextbox = loadSprite(TTTextbox,"D:\\cpp\\PBL2\\Pictures\\GDDoiGia\\Textbox.png",{23,157});
	Texture TTSubmit;
	Sprite SPSubmit = loadSprite(TTSubmit,"D:\\cpp\\PBL2\\Pictures\\GDDoiGia\\ButtonSubmit.png",{10,275});
	Texture TTHuy;
	Sprite SPHuy = loadSprite(TTHuy,"D:\\cpp\\PBL2\\Pictures\\GDDoiGia\\ButtonHuy.png",{160,275});
	
	while(DoiGia.isOpen()){
		Event event;
		while(DoiGia.pollEvent(event)){
			if(event.type == Event::Closed){
				DoiGia.close();
				return 0;
			}
			if(event.type == Event::MouseButtonPressed){
				if(event.mouseButton.button == Mouse::Left){
					if(!BGia.isMouseOver(DoiGia)) TBGia.setSelected(true);
					else TBGia.setSelected(false);
					if(!BSubmit.isMouseOver(DoiGia)){
						try{
							Gia = stoi(TBGia.getText());
							if(Gia>0) return Gia;
						}
						catch (const invalid_argument& e){
						}
					}
					if(!BHuy.isMouseOver(DoiGia)){
						return 0;
					}
				}
			}
			if(event.type == Event::TextEntered){
				TBGia.typeOnNumber(event);
			}
		}
		DoiGia.clear();
		BHuy.drawTo(DoiGia);
		BTGia.drawTo(DoiGia);
		BGia.drawTo(DoiGia);
		BSubmit.drawTo(DoiGia);
		
		DoiGia.draw(SPGDDoiGia);
		DoiGia.draw(SPHienThi);
		DoiGia.draw(SPTextbox);
		DoiGia.draw(SPSubmit);
		DoiGia.draw(SPHuy);
		
		TBGia.drawTo(DoiGia);
		DoiGia.display();
	}
	return 0;
}

void GDDoiGiaThue(Font &a, fstream &file6,fstream &file,LinkedList<San> &A){
	RenderWindow DoiGia(VideoMode(300, 400), "DoiGia", Style::Default);
	
	Button BSan5("San 5",Vector2f(140.f, 80.f),30,Color::Blue,Color::White,{80,80},&a,{110,110});
	Button BSan7("San 7",Vector2f(140.f, 80.f),30,Color::Blue,Color::White,{80,240},&a,{110,260});
	
	Texture TTGDThemSan;
	Sprite SPGDThemSan = loadSprite(TTGDThemSan,"D:\\cpp\\PBL2\\Pictures\\GDThemSan\\GDThemSan.png",{0,0});
	Texture TTButtonSan5;
	Sprite SPButtonSan5 = loadSprite(TTButtonSan5,"D:\\cpp\\PBL2\\Pictures\\GDThemSan\\ButtonSan5.png",{80,80});
	Texture TTButtonSan7;
	Sprite SPButtonSan7 = loadSprite(TTButtonSan7,"D:\\cpp\\PBL2\\Pictures\\GDThemSan\\ButtonSan7.png",{80,240});
	
	while (DoiGia.isOpen()) {
        Event event;
        while (DoiGia.pollEvent(event)) {
        	if (event.type == Event::Closed) {
                DoiGia.close();
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(!BSan5.isMouseOver(DoiGia)){
           				int k=nhapGia_GDDoiGiaThue(DoiGia,a);
           				if(k!=0){
           					GIA_5=k;
           					file6.close();
							file6.open("Data\\GiaThueSan.csv",ios::trunc|ios::out);
							file6<<GIA_5<<"\n"<<GIA_7;
							file6.close();
							for(int i=1;i<=A.size();i++){
								if(A[i].getLoaiSan()=="San5") A[i].setGia(GIA_5);
							}
							ghiFile(file,A);
							DoiGia.close();
						}
					}
					if(!BSan7.isMouseOver(DoiGia)){
           				int k=nhapGia_GDDoiGiaThue(DoiGia,a);
           				if(k!=0){
           					GIA_7=k;
           					file6.close();
							file6.open("Data\\GiaThueSan.csv",ios::trunc|ios::out);
							file6<<GIA_5<<"\n"<<GIA_7;
							file6.close();
							for(int i=1;i<=A.size();i++){
								if(A[i].getLoaiSan()=="San7") A[i].setGia(GIA_7);
							}
							ghiFile(file,A);
							DoiGia.close();
						}
					}
				}
				
			}
    	}
    	DoiGia.clear();
    	
    	BSan5.drawTo(DoiGia);
    	BSan7.drawTo(DoiGia);
    	
    	DoiGia.draw(SPGDThemSan);
    	DoiGia.draw(SPButtonSan5);
    	DoiGia.draw(SPButtonSan7);
    	
    	DoiGia.display();
    	
	}
}

void run(){
	setlocale(LC_ALL, "");
	
	LinkedList<San> A;
	fstream file;
        
    LinkedList<KhachHang> B;
    fstream file2;
    
    LinkedList<LichDatSan> Lds;
    fstream file3;
    
    fstream file4;
    
    LinkedList<ThanhToan> TToan;
    fstream file5;
    
    fstream file6;
    
    docFile_run(A,B,Lds,TToan,file,file2,file3,file4,file5,file6);
    
	RenderWindow MENU(VideoMode(1200, 880), "Main Menu", Style::Default);
    
    Font a;
    if (!a.loadFromFile("Font\\arial.ttf")){
    	cout<<"Khong the load font!";
    	return ;
	}
	
    Button BSan("Sân",Vector2f(250.f, 51.f),15,Color::Blue,Color::White,{475,339},&a,{475,339});
	Button BKhachHang("Khách Hàng",Vector2f(250.f, 51.f),15,Color::Blue,Color::White,{475,409},&a,{475,409});
	Button BThongKe("Thong Ke",Vector2f(250.f, 51.f),15,Color::Blue,Color::White,{475,479},&a,{475,479});
	Button BDoiGiaThue("Doi Gia Thue",Vector2f(250.f, 51.f),15,Color::Blue,Color::White,{475,548},&a,{475,548});
	Button BThoat("Thoat",Vector2f(250.f, 51.f),15,Color::Blue,Color::White,{475,618},&a,{475,618});
	
	Texture TTGDChinh;
	Sprite SPGDChinh;
	if (!TTGDChinh.loadFromFile("D:\\cpp\\PBL2\\Pictures\\GDChinh\\GDChinh.png"))
	{
	    cout<<"Khong the load hinh anh";
	}
	SPGDChinh.setTexture(TTGDChinh);
	
	Texture TTButtonSan;
	Sprite SPButtonSan = loadSprite(TTButtonSan,"D:\\cpp\\PBL2\\Pictures\\GDChinh\\ButtonSan.png",{473,335});
	
	Texture TTButtonKhachHang;
	Sprite SPButtonKhachHang = loadSprite(TTButtonKhachHang,"D:\\cpp\\PBL2\\Pictures\\GDChinh\\ButtonKhachHang.png",{473,406});
	
	Texture TTButtonThongKe;
	Sprite SPButtonThongKe = loadSprite(TTButtonThongKe,"D:\\cpp\\PBL2\\Pictures\\GDChinh\\ButtonThongKe.png",{471,476});
	
	Texture TTButtonDoiGiaThue;
	Sprite SPButtonDoiGiaThue = loadSprite(TTButtonDoiGiaThue,"D:\\cpp\\PBL2\\Pictures\\GDChinh\\ButtonDoiGiaThue.png",{471,547});
	
	Texture TTButtonThoat;
	Sprite SPButtonThoate = loadSprite(TTButtonThoat,"D:\\cpp\\PBL2\\Pictures\\GDChinh\\ButtonThoat.png",{471,617});
 
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
           	 			GDThongKe(a,MENU,TToan,Lds,A,B);
					} 
					else if(!BDoiGiaThue.isMouseOver(MENU)){
           	 			GDDoiGiaThue(a,file6,file,A);
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
		BDoiGiaThue.drawTo(MENU);
		BThoat.drawTo(MENU);
		MENU.draw(SPGDChinh);
		
		MENU.draw(SPButtonSan);
		MENU.draw(SPButtonKhachHang);
		MENU.draw(SPButtonThongKe);
		MENU.draw(SPButtonDoiGiaThue);
		MENU.draw(SPButtonThoate);
		
		
        MENU.display();
    }
    
    file.close();
	file2.close();
	file3.close();
	file4.close();
	file5.close();
	file6.close();
}

