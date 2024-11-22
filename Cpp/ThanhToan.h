#ifndef ThanhToan_H
#define ThanhToan_H

#include <string>
using namespace std;

class ThanhToan{
	int IdThanhToan;
	int IdLichDatSan;
	int ThanhTien;
public:
	ThanhToan(int, int ,int);
	~ThanhToan(){}
	string getSTT();
	string getSTT2();
	int getIdTT();
	int getIdLDS();
	int getTT();
};

#endif
