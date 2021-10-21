#include "MuroLadrillo.h"
//declaracion del metodo										//gameactor le paso texture y tile
MuroLadrillo::MuroLadrillo(Texture* _textura, Tile* _tileActual) :GameActor(_textura, _tileActual)
{
	tileActual = _tileActual;

	if (tileActual != nullptr) {
		tileActual->setMuroLadrillo(this);

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

void MuroLadrillo::setTileActual(Tile* _tileNuevo)
{
	if (tileActual != nullptr) {
		tileActual->setMuroLadrillo(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setMuroLadrillo(this);

		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
}