#include "SueloCircuito.h"
SueloCircuito::SueloCircuito(Texture* _textura, Tile* _tileActual) :GameActor(_textura, _tileActual)
{
	tileActual = _tileActual;

	if (tileActual != nullptr) {
		tileActual->setSueloCircuito(this);

		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;

		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
}

void SueloCircuito::setTileActual(Tile* _tileNuevo)
{
	if (tileActual != nullptr) {
		tileActual->setSueloCircuito(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setSueloCircuito(this);

		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
}