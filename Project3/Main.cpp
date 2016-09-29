#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "p_input.h"
#include <iostream>

struct levelArray {
	bool platforms[40][30];
	sf::RectangleShape shape;

	levelArray() {
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 30; j++) {
				if (i == 0 || i == 39 || j == 0 || j == 29) platforms[i][j] = true;
				else if (i > 29 && j == 26) platforms[i][j] = true;
				else platforms[i][j] = false;
				if (platforms[i][j]) std::cout << '*';
				else std::cout << " ";
			}
			std::cout << std::endl;
		}
		shape = sf::RectangleShape(sf::Vector2f(16.0, 16.0));
		shape.setFillColor(sf::Color::Red);
	}

	void drawShit(sf::RenderWindow * window) {
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 30; j++) {
				if (platforms[i][j] == true) {
					shape.setPosition(sf::Vector2f(16.0 * i, 16.0 * j));
					window->draw(shape);
				}
			}
		}
	}

};


struct pCharacter {
	float pos_x, pos_y;
	float vel_y, vel_x;
	bool dJump;
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::Sprite sprite;
	key_state keys;
	bool faceRight;

	pCharacter() {
		pos_x = 320;
		pos_y = 240;
		vel_y = 0;
		vel_x = 0;
		dJump = false;
		faceRight = true;
		if (!texture.loadFromFile("res/test.png")) { std::cout << "FUCK"; }
		sprite.setTexture(texture);
		shape = sf::RectangleShape(sf::Vector2f(16.0, 16.0));
		shape.setFillColor(sf::Color::Blue);
	}

	void update(levelArray level) {
		keys.update();
		if (level.platforms[((int)pos_x + 8) / 16][((int)pos_y + 16) / 16] == false) {
			vel_y += 1;
			if (dJump == true && keys.keyboard_array[9] && vel_y >= 0) {
				vel_y = -16;
				dJump = false;
			}
		}
		else {
			dJump = true;
			if (keys.keyboard_array[9]) vel_y = -16;
			if (keys.keyboard_array[3]) {
				faceRight = true;
				vel_x += 1;
			}
			if (keys.keyboard_array[0]) {
				faceRight = false;
				vel_x -= 1;
			}
		}


		vel_x = vel_x * (16 / 17.0);
		vel_y = vel_y * (16 / 17.0);


		pos_x += vel_x;
		pos_y += vel_y;


		if (level.platforms[((int)pos_x + 8) / 16][((int)pos_y + 15) / 16]) {
			vel_y = -1 * vel_y / 2;
			pos_y = (int)(((pos_y + 15) / 16) - 1) * 16;
		}
		if (level.platforms[((int)pos_x + 15) / 16][((int)pos_y + 8) / 16]) {
			pos_x = (int)(((pos_x + 15) / 16) - 1) * 16;
			vel_x = -vel_x / 16;
		}
		else if (level.platforms[((int)pos_x) / 16][((int)pos_y + 8) / 16]) {
			pos_x = (int)(((pos_x) / 16) + 1) * 16;
			vel_x = -vel_x / 16;
		}
	}

	void drawShit(sf::RenderWindow * window) {
		sprite.setPosition(pos_x, pos_y);
		if (!faceRight) {
			sprite.setScale(sf::Vector2f(-1, 1));
			sprite.setPosition(pos_x + 16, pos_y);
		}
		else {
			sprite.setScale(sf::Vector2f(1, 1));
			sprite.setPosition(pos_x, pos_y);
		}
		window->draw(sprite);
	}
};

struct Camera {
	float pos_x, pos_y;
	float vel_y, vel_x;
	sf::RectangleShape shape;

	Camera() {
		pos_x = 320;
		pos_y = 240;
		vel_x = 0;
		vel_y = 0;
		shape = sf::RectangleShape(sf::Vector2f(320, 240));
		shape.setFillColor(sf::Color(0, 255, 0, 64));

	}

	void update(pCharacter player) {

		if (player.pos_x > pos_x + 240) {
			pos_x = player.pos_x - 240;
			vel_x = 0;
		}
		else
			if (player.pos_x < pos_x + 80) {
				pos_x = player.pos_x - 80;
				vel_x = 0;
			}
		if (player.pos_y > pos_y + 160) {
			pos_y = player.pos_y - 160;
			vel_y = 0;
		}
		else
			if (player.pos_y < pos_y + 80) {
				pos_y = player.pos_y - 80;
				vel_y = 0;
			}

		pos_x += (player.pos_x - (pos_x + 160)) / 8;
		pos_y += (player.pos_y - (pos_y + 120)) / 4;
	}

	void drawShit(sf::RenderWindow  * window) {
		shape.setPosition(pos_x, pos_y);
		window->draw(shape);
	}
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "PlatformTest");
	sf::Keyboard keyboard;
	sf::Music music;
	levelArray level1;
	pCharacter player;
	Camera camera;
	music.openFromFile("res/test.wav");

	music.setLoop(true);
	music.play();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		level1.drawShit(&window);
		player.update(level1);
		player.drawShit(&window);
		camera.update(player);
		camera.drawShit(&window);

		window.display();
		sf::sleep(sf::seconds(1 / 60.0));

	}

	return 0;
}

