#include "button.h"

Button::Button(string t,Vector2f size, int charSize,Color bgColor, Color textColor,Vector2f pos,Font *a,Vector2f pos1){
	text.setString(t);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);
	button.setSize(size);
	button.setFillColor(bgColor);
	button.setPosition(pos);
	text.setFont(*a);
	text.setPosition(pos1);
}
void Button::setFont(Font &font){
	text.setFont(font);
}

void Button::setBackColor(Color color){
	button.setFillColor(color);
}

void Button::setTextColor(Color color){
	text.setFillColor(color);
}

void Button::setPosition(Vector2f pos){
	button.setPosition(pos);
	text.setPosition(pos);
}

Vector2f Button::getPosition(){
	return button.getPosition();
}

void Button::setTextPosition(Vector2f pos){
	text.setPosition(pos);
}


void Button::drawTo(RenderWindow &window){
	window.draw(button);
	window.draw(text);
}

int Button::getTop(){
	return button.getPosition().y;
}

int Button::getBot(){
	return button.getPosition().y+button.getSize().y;
}

bool Button::isMouseOver(RenderWindow &window){
	float mouseX = Mouse::getPosition(window).x;
	float mouseY = Mouse::getPosition(window).y;
	
	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;
	
	float btnPosWidth = button.getPosition().x + button.getLocalBounds().width;
	float btnPosHeight = button.getPosition().y + button.getLocalBounds().height;
	
	if(mouseX < btnPosWidth && mouseX > btnPosX && mouseY < btnPosHeight && mouseY > btnPosY){
		return false;
	}
	return true;
}
