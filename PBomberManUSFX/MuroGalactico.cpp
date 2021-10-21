#include "MuroGalactico.h"

MuroGalactico::MuroGalactico(Texture* _textura, Tile* _tileActual) :GameActor(_textura, _tileActual)
{
	tileActual = _tileActual;

	if (tileActual != nullptr) {
		tileActual->setMuroGalactico(this);

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

void MuroGalactico::setTileActual(Tile* _tileNuevo)
{
	if (tileActual != nullptr) {
		tileActual->setMuroGalactico(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setMuroGalactico(this);

		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
}