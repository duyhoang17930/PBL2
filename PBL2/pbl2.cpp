#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

#define GIA_T 100
#define GIA_V 200
#define Max_arr 10
#define MaxKH 100

using namespace std;

string to_string(int number){
    char buffer[50];
    sprintf(buffer, "%d", number);
    string str(buffer); 
    return str;
}

class San{
private:
    int tenSan;	
    string loaiSan;
    int giaThue;
    bool tinhTrang; // true: available, false: not available
    static int SoSan;
public:
	
    San(int ten=-1, string loai="Thuong", int gia=GIA_T, bool trangThai=true)
        : tenSan(ten), loaiSan(loai), giaThue(gia), tinhTrang(trangThai) {}
	
	
	~San(){};
	San(const San &san,int k){
		this->tenSan=k;
		this->loaiSan=san.loaiSan;
		this->giaThue=san.giaThue;
		this->tinhTrang="TRUE";
	}
    void hienThiThongTin() {
        cout << "Ten San: " << tenSan << "\nLoai San: " << loaiSan 
             << "\nGia Thue: " << giaThue 
             << "\nTinh Trang: " << (tinhTrang ? "San Co San" : "San Khong The Dat") << endl;
    }
	void suaThongTin(int ten, string loai, int gia, bool trangThai) {
        tenSan = ten;
        loaiSan = loai;
        giaThue = gia;
        tinhTrang = trangThai;
	}
    string thongTinSan(){
    	string ten=to_string(tenSan);
    	string gia=(giaThue==GIA_T?to_string(GIA_T):to_string(GIA_V));
    	string tt=(tinhTrang?"TRUE":"FALSE");
		return ten+","+loaiSan+","+gia+","+tt;
	}
	bool setTT(){
		return tinhTrang=tinhTrang?false:true;
	}
	static int inSoSan(){
    	return SoSan;
	}
	static void tangSoSan(){
		SoSan++;
	}
	static void giamSoSan(){
		SoSan--;
	}

	
};

int San::SoSan=0;

class KhachHang {
private:
	int maKhachHang;
    string ten;
    string soDienThoai;
    string email;
	static int soKH;
	
public:
    KhachHang(int maKhachHang=-1,string tenKH="", string sdt="", string mail="")
        :maKhachHang(maKhachHang), ten(tenKH), soDienThoai(sdt), email(mail) {}
	
	~KhachHang(){
	}
	KhachHang(const KhachHang &a,int k){
		this->maKhachHang=k;
		this->ten=a.ten;
		this->soDienThoai=a.soDienThoai;
		this->email=a.email;
	}
	
    void hienThiThongTin() {
        cout <<"Ma Khach Hang: "<< maKhachHang << "\nTen Khach Hang: " << ten << "\nSo Dien Thoai: " << soDienThoai
             << "\nEmail: " << email << endl<<endl;
    }

    void suaThongTin(int maKhachHang,string tenKH, string sdt, string mail) {
    	maKhachHang=maKhachHang;
        ten = tenKH;
        soDienThoai = sdt;
        email = mail;
    }

    void themKhachHang(int maKhachHang,string tenKH, string sdt, string mail) {
    	maKhachHang=maKhachHang;
        ten = tenKH;
        soDienThoai = sdt;
        email = mail;
    }

    void xoaKhachHang() {
        ten = "";
        soDienThoai = "";
        email = "";
    }
    string ThongTinKH(){
    	return to_string(maKhachHang)+","+ten+","+soDienThoai+","+email;
	}
	static int inSoKH(){
   		return soKH;
	}
	static void tangSoKH(){
		soKH++;
	}
	static void giamSoKH(){
		soKH--;
	}
};


int KhachHang::soKH=0;

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

class BaoCaoThongKe {
public:
//    void thongKeDoanhThu(vector<double> doanhThu) {
//        double tongDoanhThu = 0;
//        for (double doanhSo : doanhThu) {
//            tongDoanhThu += doanhSo;
//        }
//        cout << "Tong Doanh Thu: " << tongDoanhThu << endl;
//    }
//
//    void baoCaoTinhTrangSuDungSan(vector<string> tinhTrangSan) {
//        for (string tinhTrang : tinhTrangSan) {
//            cout << "Tinh Trang San: " << tinhTrang << endl;
//        }
//    }
//
//    void baoCaoKhachHang(vector<string> thongTinKhachHang) {
//        for (string khachHang : thongTinKhachHang) {
//            cout << "Khach Hang: " << khachHang << endl;
//        }
//    }
};

void introduce(){
    cout << "+-------------------------------------------------------------------------------+\n";
    cout << "|                           HE THONG QUAN LY SAN BONG                           |\n";
    cout << "|                                                                               |\n";
    cout << "|0. Thoat                                                                       |\n";
    cout << "|1. San bong                                                                    |\n";
    cout << "|2. Khach hang                                                                  |\n";
    cout << "|3. Lich dat san                                                                |\n";
    cout << "|4. Thanh toan                                                                  |\n";
    cout << "|5. Bao cao thong ke                                                            |\n";
    cout << "+-------------------------------------------------------------------------------+\n";
    
} 

void giaodien1(){
    cout << "+-------------------------------------------------------------------------------+\n";
    cout << "|                           HE THONG QUAN LY SAN BONG                           |\n";
    cout << "|                                                                               |\n";
    cout << "|-1. Quay lai                                                                   |\n";
    cout << "|0. Thoat                                                                       |\n";
    cout << "|1. Hien thi thong tin                                                          |\n";
    cout << "|2. Sua thong tin                                                               |\n";
    cout << "|3. Them san bong                                                               |\n";
    cout << "|4. Xoa san bong                                                                |\n";
    cout << "|5. Doi trang thai san                                                          |\n";
    cout << "+-------------------------------------------------------------------------------+\n";
    
} 

void giaodien2(){
    cout << "+-------------------------------------------------------------------------------+\n";
    cout << "|                           HE THONG QUAN LY SAN BONG                           |\n";
    cout << "|                                                                               |\n";
    cout << "|-1. Quay lai                                                                   |\n";
    cout << "|0. Thoat                                                                       |\n";
    cout << "|1. Hien thi thong tin khach hang                                               |\n";
    cout << "|2. Sua thong tin khach hang                                                    |\n";
    cout << "|3. Them khach hang                                                             |\n";
    cout << "|4. Xoa khach hang                                                              |\n";
    cout << "+-------------------------------------------------------------------------------+\n";
    
} 

void ghiFile(fstream& file,San *A){
		file.close();
		file.open("San.csv",ios::trunc|ios::out);
		for(int i=1;i<=San::inSoSan();i++){
			file<<A[i].thongTinSan()<<"\n";
		}
		file.close();
}

void ghiFile(fstream& file2,KhachHang *B){
		file2.close();
		file2.open("KhachHang.csv",ios::trunc|ios::out);
		for(int i=1;i<=KhachHang::inSoKH();i++){
			file2<<B[i].ThongTinKH()<<"\n";
		}
		file2.close();
}

int nhap(){
	int n;
	cout<<"Nhap lua chon:";
	cin>>n;
	return n;
}



int main(){
	San *A= new San [Max_arr+1];
    
	fstream file;
	file.open("San.csv",ios::in|ios::out);
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
            San::tangSoSan();
    		San a(idStr,loaiSan,giaStr,trangThai);
    		A[San::inSoSan()]=a;
        }
        
    KhachHang *B=new KhachHang[MaxKH+1];
    
    fstream file2;
    file2.open("KhachHang.csv",ios::in|ios::out);
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
            KhachHang::tangSoKH();
    		KhachHang a(MaKH,tenKH,sdt,mail);
    		B[MaKH]=a;
        }
        
	system("cls");
giaodien0:
	introduce();
	int n=nhap();
	if(n<0||n>5){
		cout<<"Khong hop le\n";
		goto giaodien0;
	}
	else if(n==0) return 0;
	else if(n==1){
		system("cls");
giaodien1:
		giaodien1();
		int n1=nhap();
		
		if(n1<-1||n1>5){
			cout<<"Khong hop le\n";
			goto giaodien1;
		}
		else if(n1==0) return 0;
		else if(n1==-1){
			system("cls");
			goto giaodien0;
		}
		else if(n1==1){
			for(int i=1;i<=San::inSoSan();i++){
				A[i].hienThiThongTin();
			}
			goto giaodien1;
		}
		else if(n1==2){
			int tendoi,loaidoi;
			cout<<"Nhap ten san can doi(Nhap 0 de thoat):";
			cin>>tendoi;
			if(tendoi==0) goto giaodien1;
			if(tendoi<1||tendoi>San::inSoSan()){
				cout<<"Khong hop le\n";
				goto giaodien1;
			}
			cout<<"\nNhap loai san can doi(Thuong:0, Vip:1):";
			cin>>loaidoi;
			int gia=loaidoi?GIA_V:GIA_T;
			string loai=loaidoi?"Vip":"Thuong";
			A[tendoi].San::suaThongTin(tendoi,loai,gia,true);
			ghiFile(file,A);
			goto giaodien1;
		}
		else if(n1==3){
			if(San::inSoSan()==Max_arr){
				cout<<"So san da day\n";
				goto giaodien1;
			}
			int loaithem;
			cout<<"Nhap loai san can them(Thuong:0, Vip:1, Nhap -1 de thoat):";
			cin>>loaithem;
			if(loaithem==-1) goto giaodien1;
			if(loaithem!=0 && loaithem!=1){
				cout<<"Khong hop le\n";
				goto giaodien1;
			}
			else{
				string loai=loaithem?"Vip":"Thuong";
				int gia=loaithem?GIA_V:GIA_T;
				San::tangSoSan();
    			San a(San::inSoSan(),loai,gia,"TRUE");
    			A[San::inSoSan()]=a;
				ghiFile(file,A);
				cout<<"Them san thanh cong!\n";
				goto giaodien1;
			}
		}
		else if(n1==4){
			if(San::inSoSan()==0){
				cout<<"Khong co san nao de xoa\n";
				goto giaodien1;
			}
			int k;
    		cout<<"Nhap san can xoa: ";
    		cin>>k;
    		if(k<1||k>San::inSoSan()){
    			cout<<"Khong co san nay\n";
    			goto giaodien1;
			}
			else{
				San a(A[San::inSoSan()],k);
    			A[k]=a;
      		    San::giamSoSan();
				ghiFile(file,A);
				cout<<"Xoa thanh cong!\n";
				goto giaodien1;
			}
		}
		else if(n1==5){
			int k;
    		cout<<"Nhap san can doi trang thai: ";
    		cin>>k;
    		if(k<1||k>San::inSoSan()){
    			cout<<"Khong co san nay\n";
    			goto giaodien1;
			}
			else{
				A[k].setTT();
				ghiFile(file,A);
				cout<<"Doi thanh cong!\n";
				goto giaodien1;
			}
		}
	}
	else if(n==2){
		system("cls");
giaodien2:
		giaodien2();
		int n2=nhap();
		
		if(n2<-1||n2>4){
			cout<<"Khong hop le\n";
			goto giaodien2;
		}
		else if(n2==0) return 0;
		else if(n2==-1){
			system("cls");
			goto giaodien0;
		}
		else if(n2==1){
			for(int i=1;i<=KhachHang::inSoKH();i++){
				B[i].hienThiThongTin();
			}
			goto giaodien2;
		}
		else if(n2==2){
			int k;
			cout<<"Nhap ma khach hang can doi thong tin (Nhap 0 de thoat):";
			cin>>k;
			if(k==0) goto giaodien2;
			else if(k<0 || k>KhachHang::inSoKH()){
				cout<<"Khong hop le\n";
				goto giaodien2;
			}
			else{
				string tenDoi,sdtDoi,emailDoi;
				cout<<"Nhap ten khach hang can doi (Nhap 0 de thoat):";
				cin>>tenDoi;
				if(tenDoi=="0") goto giaodien2;
				cout<<"Nhap sdt khach hang can doi (Nhap 0 de thoat):";
				cin>>sdtDoi;
				if(sdtDoi=="0") goto giaodien2;
				cout<<"Nhap mail khach hang can doi (Nhap 0 de thoat):";
				cin>>emailDoi;
				if(emailDoi=="0") goto giaodien2;
				B[k].suaThongTin(k,tenDoi,sdtDoi,emailDoi);
				ghiFile(file2,B);
				cout<<"Sua thanh cong!\n";
				goto giaodien2;
			}
		}
		else if(n2==3){
			if(KhachHang::inSoKH()>MaxKH){
				cout<<"So khach hang da day\n";
				goto giaodien2;
			}
			string tenThem,sdtThem,emailThem;
			cout<<"Nhap ten khach hang can them (Nhap 0 de thoat):";
			cin>>tenThem;
			if(tenThem=="0") goto giaodien2;
			cout<<"Nhap sdt khach hang can them (Nhap 0 de thoat):";
			cin>>sdtThem;
			if(sdtThem=="0") goto giaodien2;
			cout<<"Nhap mail khach hang can them (Nhap 0 de thoat):";
			cin>>emailThem;
			if(emailThem=="0") goto giaodien2;
			KhachHang::tangSoKH();
    		KhachHang a(KhachHang::inSoKH(),tenThem,sdtThem,emailThem);
    		B[KhachHang::inSoKH()]=a;
			ghiFile(file2,B);
			cout<<"Them thanh cong!\n";
			goto giaodien2;
		}
		else if(n2==4){
			if(KhachHang::inSoKH()==0){
				cout<<"Khong co khach hang nao de xoa";
				goto giaodien2;
			}
			int k;
			cout<<"Nhap ma khach hang can xoa (Nhap 0 de thoat):";
			cin>>k;
			if(k==0) goto giaodien2;
			else if(k<0 || k>KhachHang::inSoKH()){
				cout<<"Khong hop le\n";
				goto giaodien2;
			}
			else{
				KhachHang a(B[KhachHang::inSoKH()],k);
    			B[k]=a;
        		KhachHang::giamSoKH();
				ghiFile(file2,B);
				cout<<"Xoa thanh cong!\n";
				goto giaodien2;
			}
		}
	}
	
	delete[] A;
	delete[] B;
	file.close();
	file2.close();
	return 0;
}
