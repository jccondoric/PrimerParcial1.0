#pragma once
#include <iostream>
#include "GamePawn.h"

using namespace std;

class BombermanRobot : public GamePawn
{
private:

public:
	//Constructor
	BombermanRobot(Texture* _textura, Tile* _tileActual);
	void setTileActual(Tile* _tileNuevo) override;

	void update2();
	void render2();

};

