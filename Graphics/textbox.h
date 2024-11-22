#ifndef textbox_h
#define textbox_h

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using namespace sf;
using namespace std;

class Textbox{
	public:
		Textbox(){}
		Textbox(int size,Color color,bool sel,Font *a,Vector2f pos);
		void setFont(Font &font);
		void setPosition(Vector2f pos);
		void setLimit(bool ToF,int lim);
		void setSelected(bool sel);
		string getText();
		void drawTo(RenderWindow &window);
 		void typeOn(Event input);
 		void typeOnNumber(Event input);
	private:
		Text textbox;
		ostringstream text;
		bool isSelected = false;
		bool hasLimit = false;
		int limit;
		
		void inputLogic(int charType);
		void deleteLastChar();
};

#endif
