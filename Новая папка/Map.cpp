#include "Map.h"

Map::Map(int height, int width) :
	player('@', 0, 0)
{
	this->width = width;
	this->height = height;
	map = new char* [height];
	for (int i = 0; i < height; i++) {
		map[i] = new char[width];
	}
}

void Map::draw() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}
void Map::generetationWater() {
	int k = random(0, 5);
	for (int j = 0; j < width; j++) {
		for (int i = 0; i < k; i++) {
			map[i][j] = tiles[0];
		}
		int flag = random(0, 1);
		if (j>1 && map[k][j - 1] != tiles[0] && map[k][j-2]!=tiles[0]) {
			if (flag) {
				if (k < 7) k++;
			}
			else {
				if (k > 2) k--;
			}
		}
	}
	k = random(2, 5);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < k; j++) {
			map[i][j] = tiles[0];
		}
		int flag = random(0, 1);
		if (i > 1 && map[k][i - 1] != tiles[0] && map[k][i - 2] != tiles[0]) {
			if (flag) {
				if (k < 7) k++;
			}
			else {
				if (k > 2) k--;
			}
		}
	}
	k = random(2, 5);
	for (int j = 0; j < width; j++) {
		for (int i = height-1; i > height-1-k; i--) {
			map[i][j] = tiles[0];
		}
		int flag = random(0, 1);
		if (j > 1 && map[k][j - 1] != tiles[0] && map[k][j - 2] != tiles[0]) {
			if (flag) {
				if (k < 7) k++;
			}
			else {
				if (k > 2) k--;
			}
		}
	}
	k = random(2, 5);
	for (int j = 0; j < height; j++) {
		for (int i = width-1; i > width-1-k; i--) {
			map[j][i] = tiles[0];
		}
		int flag = random(0, 1);
		if (j > 1 && map[k][j - 1] != tiles[0] && map[k][j - 2] != tiles[0]) {
			if (flag) {
				if (k < 7) k++;
			}
			else {
				if (k > 2) k--;
			}
		}
	}
}
void Map::generation() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = tiles[1];
		}
	}
	generetationWater();
}