#pragma once
#include "settings.h"
#include "player.h"
#include "field.h"


class Game {
private:
	sf::RenderWindow window;
	Player player;
	Apple apple;
	Field field;

	void checkEvents() {
		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed) window.close();
	}

	void reset_field();

	void update() {

		player.update();
	}

	void draw() {
		window.clear(sf::Color(183, 212, 168));


		for (int j = 0; j < field_size_y; j++) {
			for (int i = 0; i < field_size_x; i++) {
				switch (field[j][i]) {
				case FIELD_CELL_TYPE_NONE:
					field.draw_field(window);
					break;
				case FIELD_CELL_TYPE_APPLE:
					apple.draw(window);
					break;
				default:
					player.draw(window);
				}
			}
		}
		window.display();
	}
public:
	Game() :
		window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Close)
	{
		window.setFramerateLimit(FPS);
	}

	void play() {
		while (/*window.isOpen() && */game_over == false)
		{
			checkEvents();
			update();
			draw();
		}
	}
};
