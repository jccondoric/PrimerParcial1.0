#pragma once
#include "GameActor.h"//Clase Base
class MuroLadrillo : 
    public GameActor
{
public:
    //Metodo y le pasamos texture y tile
    MuroLadrillo(Texture* _textura, Tile* _tileActual);
    //
    void setTileActual(Tile* _tileNuevo);
};
