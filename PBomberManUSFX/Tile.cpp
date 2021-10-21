#include "Tile.h"

Tile::Tile()
{
	posicionTileX = 0;
	posicionTileY = 0;
	bomberman = nullptr;
	bombermanRobot = nullptr;
	muroCeramica = nullptr;
	sueloCesped = nullptr;
	muroLadrillo = nullptr;
	muroGalactico = nullptr;
	muroMetal = nullptr;
	sueloCircuito = nullptr;
	
}

Tile::Tile(int _posicionTileX, int _posicionTileY)
{
	posicionTileX = _posicionTileX;
	posicionTileY = _posicionTileY;
	bomberman = nullptr;
	bombermanRobot = nullptr;
	muroCeramica = nullptr;
	sueloCesped = nullptr;
	muroLadrillo = nullptr;
	muroMetal = nullptr;
	muroGalactico = nullptr;
	sueloCircuito = nullptr;
}