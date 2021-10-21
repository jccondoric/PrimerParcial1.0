#pragma once
#include"GameActor.h"
class SueloCircuito:
	public GameActor
{
public:
	SueloCircuito(Texture* _textura, Tile* _tileActual);
	void setTileActual(Tile* _tileNuevo);

};

