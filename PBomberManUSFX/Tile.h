#pragma once
#include <SDL.h>

//
//#include "Bomberman.h"
//#include "MuroCeramica.h"
//#include "MuroMetal.h"
//#include "SueloCesped.h"

class Bomberman;
class BombermanRobot;
class MuroCeramica;
class MuroMetal;
class SueloCesped;
class MuroLadrillo;
class MuroGalactico;
class SueloCircuito;

class Tile
{
private:
	Bomberman* bomberman;
	BombermanRobot* bombermanRobot;
	MuroCeramica* muroCeramica;
	MuroMetal* muroMetal;
	SueloCesped* sueloCesped;
	SueloCircuito* sueloCircuito;
	MuroGalactico* muroGalactico;
	MuroLadrillo* muroLadrillo;

	int posicionTileX;
	int posicionTileY;

public:
	static const int anchoTile = 34;
	static const int altoTile = 34;

	// Constructores y destructores
	Tile();
	Tile(int _posicionTileX, int _posicionTileY);

	// Metodos accesores
	Bomberman* getBomberman() { return bomberman; }
	BombermanRobot* getBombermanRobot() { return bombermanRobot; }
	MuroCeramica* getMuroCeramica() { return muroCeramica; }
	MuroMetal* getMuroMetal() { return muroMetal; }
	SueloCesped* getSueloCesped() { return sueloCesped; }
	MuroLadrillo* getMuroLadrillo() { return muroLadrillo; }
	MuroGalactico* getMuroGalactico() { return muroGalactico; }
	SueloCircuito* getSueloCircuito() { return sueloCircuito; }
	int getPosicionTileX() { return posicionTileX; }
	int getPosicionTileY() { return posicionTileY; }

	void setBomberman(Bomberman* _bomberman) { bomberman = _bomberman; }
	void setBombermanRobot(BombermanRobot* _bombermanRobot) { bombermanRobot = _bombermanRobot; }
	void setMuroCeramica(MuroCeramica* _muroCeramica) { muroCeramica = _muroCeramica; }
	void setMuroMetal(MuroMetal* _muroMetal) { muroMetal = _muroMetal; }
	void setMuroLadrillo(MuroLadrillo* _muroLadrillo) { muroLadrillo = _muroLadrillo; }
	void setSueloCesped(SueloCesped* _sueloCesped) { sueloCesped = _sueloCesped; }
	void setMuroGalactico(MuroGalactico* _muroGalactico) { muroGalactico = _muroGalactico; }
	void setSueloCircuito(SueloCircuito* _sueloCircuito) { sueloCircuito = _sueloCircuito; }
	void setPosicionTileX(int _posicionTileX) { posicionTileX = _posicionTileX; }
	void setPosicionTileY(int _posicionTileY) { posicionTileY = _posicionTileY; }



};

