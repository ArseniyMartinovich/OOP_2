#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include "player.h"
#include "apple.h"

class Field {
private:
	sf::Texture none_texture;
	sf::Sprite none;
public:
	int** field;
	sf::RenderWindow window;
	Player player;
	Apple apple;
	void reset_field();
	void draw_field(sf::RenderWindow& window);
	Field();
};

Field::Field() {
	none_texture.loadFromFile(IMAGES_FOLDER + NONE_FILE_NAME);
	none.setTexture(none_texture);

	field = new (int*)[field_size_y * cell_size][field_size_x * cell_size];
	for (int i = 0; i < field_size_y * cell_size; i++) {
		field[i] = new int[field_size_y * cell_size];
	}
	for (int i = 0; i < field_size_x * cell_size; i++) {
		field[i] = new int[field_size_x * cell_size];
	}
}

void Field::reset_field() {
	for (int j = 0; j < field_size_y; j++) {
		for (int i = 0; i < field_size_x; i++) {
			field[j][i] = FIELD_CELL_TYPE_NONE;
		}
	}
	for (int i = 0; i < player.getLenth(); i++) {
		field[player.getPlayerPosY()][player.getPlayerPosY() - i] = player.getLenth() - i;
	}
	apple.spawn();
}

void Field::draw_field(sf::RenderWindow& window) {
	for (int j = 0; j < field_size_y; j++) {
		for (int i = 0; i < field_size_x; i++) {
			none.setPosition(float(i * cell_size), float(j * cell_size));
			window.draw(none);
		}
	}

}