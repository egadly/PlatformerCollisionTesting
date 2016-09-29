#include "p_input.h"

key_state::key_state() {
	keyboard_array = new bool[26];
	for (int i = 0; i < 26; i++) keyboard_array[i] = false;
}

void key_state::update() {
	keyboard_array[0] = keyboard.isKeyPressed(sf::Keyboard::A) ? true : false;
	keyboard_array[1] = keyboard.isKeyPressed(sf::Keyboard::B) ? true : false;
	keyboard_array[2] = keyboard.isKeyPressed(sf::Keyboard::C) ? true : false;
	keyboard_array[3] = keyboard.isKeyPressed(sf::Keyboard::D) ? true : false;
	keyboard_array[4] = keyboard.isKeyPressed(sf::Keyboard::E) ? true : false;
	keyboard_array[5] = keyboard.isKeyPressed(sf::Keyboard::F) ? true : false;
	keyboard_array[6] = keyboard.isKeyPressed(sf::Keyboard::G) ? true : false;
	keyboard_array[7] = keyboard.isKeyPressed(sf::Keyboard::H) ? true : false;
	keyboard_array[8] = keyboard.isKeyPressed(sf::Keyboard::I) ? true : false;
	keyboard_array[9] = keyboard.isKeyPressed(sf::Keyboard::J) ? true : false;
	keyboard_array[10] = keyboard.isKeyPressed(sf::Keyboard::K) ? true : false;
	keyboard_array[11] = keyboard.isKeyPressed(sf::Keyboard::L) ? true : false;
	keyboard_array[12] = keyboard.isKeyPressed(sf::Keyboard::M) ? true : false;
	keyboard_array[13] = keyboard.isKeyPressed(sf::Keyboard::N) ? true : false;
	keyboard_array[14] = keyboard.isKeyPressed(sf::Keyboard::O) ? true : false;
	keyboard_array[15] = keyboard.isKeyPressed(sf::Keyboard::P) ? true : false;
	keyboard_array[16] = keyboard.isKeyPressed(sf::Keyboard::Q) ? true : false;
	keyboard_array[17] = keyboard.isKeyPressed(sf::Keyboard::R) ? true : false;
	keyboard_array[18] = keyboard.isKeyPressed(sf::Keyboard::S) ? true : false;
	keyboard_array[19] = keyboard.isKeyPressed(sf::Keyboard::T) ? true : false;
	keyboard_array[20] = keyboard.isKeyPressed(sf::Keyboard::U) ? true : false;
	keyboard_array[21] = keyboard.isKeyPressed(sf::Keyboard::V) ? true : false;
	keyboard_array[22] = keyboard.isKeyPressed(sf::Keyboard::W) ? true : false;
	keyboard_array[23] = keyboard.isKeyPressed(sf::Keyboard::X) ? true : false;
	keyboard_array[24] = keyboard.isKeyPressed(sf::Keyboard::Y) ? true : false;
	keyboard_array[25] = keyboard.isKeyPressed(sf::Keyboard::Z) ? true : false;
}