#pragma once
#include "Player.h"
#include <iostream>
#define random(a, b) a+rand()%(b-a+1)
using namespace std;
class Map
{
	Player player;
	int height;
	int width;
	char** map = nullptr;
	char tiles[3]={ char(176), char(177), char(219)};
public:
	Map(int height, int width);
	void draw();
	void generetationWater();
	void generation();
};

