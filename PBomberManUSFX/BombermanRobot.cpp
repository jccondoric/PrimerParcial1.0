#include "BombermanRobot.h"
//Va recibir una textura cuando este creando el objeto un tile actual donde esta apuntando
BombermanRobot::BombermanRobot(Texture* _textura, Tile* _tileActual) :GamePawn(_textura, _tileActual)
{
	 //variables de gameactor
	tileActual = _tileActual;	//tileActual esta heredando desde GameActor
	tileSiguiente = nullptr;// no tiene tiel siguiente por que se esta empezando



	if (tileActual != nullptr) {//si he asignado  un tile para mi robot, luego es establecer a ese tile
		//que la direccion donde esta el BormermanRobot es la direccion del obejto actual	 
		tileActual->setBombermanRobot(this);
					//le esta donde bombermanRobot Actual

		//posicion de graficacion
		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile; //Devueelve el pixel donde tengo que emoezar a dibujar el bomber
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;
		ancho = Tile::anchoTile;
		alto = Tile::altoTile;
	}
	else {
		//en caso de que no tenga ningun tile asignado,asigno posicion x posicion y
		posicionX = 0;
		posicionY = 0;
	}
	//propiedades que a heredado de Game Actor, y las esta trabjando como suyas 
	velocidad = 1; //velocidad a la que mueve 
	movil = true;
	enMovimiento = false;
	direccionActual = MOVE_DIRECTION_NONE;///no se mueve
	direccionSiguiente = MOVE_DIRECTION_NONE;//no se mueve

}

void BombermanRobot::update2()
//Revisa si se ha precionado uno de los botones, si se ha precionado uno de los botones da una nueva direccion en funcion  que boton se ha preciaonado
{
	direccionSiguiente = MOVE_DIRECTION_NONE;

	if (keyboardInput->IsKeyOn(botonAbajo)) {
		direccionSiguiente = MOVE_DIRECTION_ABAJO;
	}
	else if (keyboardInput->IsKeyOn(botonArriba)) {
		direccionSiguiente = MOVE_DIRECTION_ARRIBA;
	}
	else if (keyboardInput->IsKeyOn(botonDerecha)) {
		direccionSiguiente = MOVE_DIRECTION_DERECHA;
	}
	else if (keyboardInput->IsKeyOn(botonIzquierda)) {
		direccionSiguiente = MOVE_DIRECTION_IZQUIERDA;
	}


	//if (tileActual != nullptr && tileActual->getSueloCesped() != nullptr) {
	//	//Camina normalmente, se revisan colisiones
	//}

	// Animar Bomberman
	//if (enMovimiento) {
	//	//GameActor::update();
	//}

	//// Cambiar de direccion y tileSiguiente
	//if (tileActual != nullptr && tileActual->getSueloCesped() != nullptr) {
	//	//Camina normalmente, se revisan colisiones
	//}

	//if (tileSiguiente == tileActual || tileSiguiente == nullptr) {
	if (direccionSiguiente != direccionActual && tratarDeMover(direccionSiguiente))
		direccionActual = direccionSiguiente;
	else
		tratarDeMover(direccionActual);

	/*if (tileSiguiente == nullptr)
		enMovimiento = false;
	else
		enMovimiento = true;*/
		//}
		//else {
	if (tileSiguiente != nullptr) {
		switch (direccionActual) {
		case MOVE_DIRECTION_ARRIBA:
			posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile);
			//posicionY = posicionY - velocidad;
			break;
		case MOVE_DIRECTION_ABAJO:
			posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionTileY() * Tile::altoTile);
			//posicionY = posicionY + velocidad;
			break;
		case MOVE_DIRECTION_IZQUIERDA:
			posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile);
			//posicionX = posicionX - velocidad;
			break;
		case MOVE_DIRECTION_DERECHA:
			posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionTileX() * Tile::anchoTile);
			//posicionX = posicionX + velocidad;
			break;
		}

		// Asignacion de coliciones
		//
		//

		// Cambio de direccion

		if ((direccionActual == MOVE_DIRECTION_ABAJO || direccionActual == MOVE_DIRECTION_ARRIBA) && posicionY == tileSiguiente->getPosicionTileY() * Tile::altoTile)
			setTileActual(tileSiguiente);

		if ((direccionActual == MOVE_DIRECTION_IZQUIERDA || direccionActual == MOVE_DIRECTION_DERECHA) && posicionX == tileSiguiente->getPosicionTileX() * Tile::anchoTile)
			setTileActual(tileSiguiente);
	}
	//}
}

void BombermanRobot::render2()
{
	GamePawn::render();
}
void BombermanRobot::setTileActual(Tile* _tileNuevo)
{
	if (tileActual != nullptr) {
		tileActual->setBomberman(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setBombermanRobot(this);

		posicionX = tileActual->getPosicionTileX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionTileY() * Tile::altoTile;
	}

}