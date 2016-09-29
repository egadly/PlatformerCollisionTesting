#ifndef P_INPUT
#define P_INPUT

#include "SFML\Window.hpp"

class key_state {
private:
	sf::Keyboard keyboard;
public:
	bool * keyboard_array;
	key_state();
	void update();


};


#endif
