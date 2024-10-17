#ifndef button_n
#define button_n

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Button{
public:
	Button(){};
	Button(string t="",Vector2f size={0,0}, int charSize=1,Color bgColor=Color::Black, Color textColor=Color::Black,Vector2f pos={0,0},Font *a=nullptr,Vector2f pos1={0,0});
	void setFont(Font &font);
	void setBackColor(Color color);
	void setTextColor(Color color);
	void setPosition(Vector2f pos);
	void setTextPosition(Vector2f pos);
	void drawTo(RenderWindow &window);
	int getTop();
	int getBot();
	Vector2f getPosition();
	bool isMouseOver(RenderWindow &window);
private:
	RectangleShape button;
	Text text;
};

#endif
