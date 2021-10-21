#pragma once
#include <iostream>
#include "GamePawn.h"

using namespace std;
//game pawn incorpora el manejo de teclado
class Bomberman : public GamePawn
{
private:

public:
	//Constructor
	Bomberman(Texture* _textura, Tile* _tileActual);
	//defino 
	void setTileActual(Tile* _tileNuevo) override;

	void update();
	void render();

};

