#pragma once
#include <iostream>
#include "GamePawn.h"

using namespace std;
//game pawn incorpora el manejo de teclado
class BombermanRobot : public GamePawn
{
private:

public:
	//Constructor
	BombermanRobot(Texture* _textura, Tile* _tileActual);
	//defino  set tile actual y lo sobrecargo y lo reescribo
	void setTileActual(Tile* _tileNuevo) override;

	void update2();
	void render2();

};

