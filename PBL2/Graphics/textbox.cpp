#include "textbox.h"

Textbox::Textbox(int size,Color color,bool sel,Font *a,Vector2f pos){
	textbox.setPosition(pos);
	textbox.setFont(*a);
	textbox.setCharacterSize(size);
	textbox.setFillColor(color);
	isSelected = sel;
	if(sel){
		textbox.setString("_");
	}
	else{
		textbox.setString("");
	}
}

void Textbox::setLimit(bool ToF,int lim){
	hasLimit = ToF;
	limit=lim;
}
		
void Textbox::setFont(Font &font){
	textbox.setFont(font);
}
		
void Textbox::setPosition(Vector2f pos){
	textbox.setPosition(pos);
}

void Textbox::setSelected(bool sel){
	isSelected=sel;
	if(!sel){
		string t = text.str();
		string newT = "";
		for(int i=0;i<t.length();i++){
			newT+=t[i];
		}
		textbox.setString(newT);
	}
}

string Textbox::getText(){
	return text.str();
}

void Textbox::drawTo(RenderWindow &window){
	window.draw(textbox);
}
void Textbox::typeOn(Event input){
	if(isSelected){
		int charTyped = input.text.unicode;
		if(charTyped < 128){
			if(hasLimit){
				if(text.str().length()<=limit){
					inputLogic(charTyped);
				}
				else if(text.str().length()>limit && charTyped == DELETE_KEY){
					deleteLastChar();
				}
			}
			else{
				inputLogic(charTyped);
			}
		}
	}
}

void Textbox::inputLogic(int charType){
	if(charType != DELETE_KEY && charType != ENTER_KEY && charType != ESCAPE_KEY){
		text << static_cast<char>(charType);
	}
	else if(charType == DELETE_KEY){
		if(text.str().length() > 0){
			deleteLastChar();
		}
	}
	textbox.setString(text.str());
}
	
void Textbox::deleteLastChar(){
	string t = text.str();
	string newT = "";
	for(int i=0;i<t.length()-1;i++){
		newT+=t[i];
	}
	text.str("");
	text<<newT;
	
	textbox.setString(text.str());
}
