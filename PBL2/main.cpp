#include <SFML/Graphics.hpp>
#include "textbox.h"
#include "button.h"

void GiaodienSan(){
	RenderWindow San(VideoMode(960, 700), "San", Style::Default);
	Font a;
	a.loadFromFile("arial.ttf");
	
	Button BThemSan("+",Vector2f(70.f, 70.f),50,Color::Blue,Color::White);
	BThemSan.setPosition({800,100});
	BThemSan.setFont(a);
	BThemSan.setTextColor(Color::White);
	BThemSan.setTextPosition({820,103});
	
	Button BXoaSan("-",Vector2f(70.f, 70.f),50,Color::Blue,Color::White);
	BXoaSan.setPosition({800,200});
	BXoaSan.setFont(a);
	BXoaSan.setTextColor(Color::White);
	BXoaSan.setTextPosition({827,200});
	
	while (San.isOpen()) {
        Event event;
        while (San.pollEvent(event)) {
            if (event.type == Event::Closed) {
                San.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
            if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(!BThemSan.isMouseOver(San)){
           	 		}
				}
			}
        }
		San.clear();
		BThemSan.drawTo(San);
		BXoaSan.drawTo(San);
        San.display();
    }
}

void run(){
	RenderWindow MENU(VideoMode(960, 700), "Main Menu", Style::Default);
    
    Font a;
    a.loadFromFile("arial.ttf");
    
    Button BSan("San",Vector2f(250.f, 25.f),15,Color::Blue,Color::White);
	BSan.setPosition({350,250});
	BSan.setFont(a);
	BSan.setTextColor(Color::White);
	BSan.setTextPosition({460,250});
	
	Button BKhachHang("KhachHang",Vector2f(250.f, 25.f),15,Color::Blue,Color::White);
	BKhachHang.setPosition({350,300});
	BKhachHang.setFont(a);
	BKhachHang.setTextPosition({440,300});
	
	Button BDatSan("DatSan",Vector2f(250.f, 25.f),15,Color::Blue,Color::White);
	BDatSan.setPosition({350,350});
	BDatSan.setFont(a);
	BDatSan.setTextPosition({450,350});
	
	Button BThanhToan("ThanhToan",Vector2f(250.f, 25.f),15,Color::Blue,Color::White);
	BThanhToan.setPosition({350,400});
	BThanhToan.setFont(a);
	BThanhToan.setTextPosition({440,400});
	
	Button BThoat("Thoat",Vector2f(250.f, 25.f),15,Color::Blue,Color::White);
	BThoat.setPosition({350,450});
	BThoat.setFont(a);
	BThoat.setTextPosition({455,450});
	
    while (MENU.isOpen()) {
        Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close(); // Ðóng c?a s? khi nh?n nút dóng
            }
           	if(event.type == Event::MouseButtonPressed){
           		if(event.mouseButton.button == Mouse::Left){
           			if(!BSan.isMouseOver(MENU)){
           	 			GiaodienSan();
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
}

int main() {
    run();

    return 0;
}

