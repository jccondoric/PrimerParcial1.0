#pragma once
#include "GameActor.h"
class MuroLadrillo :
    public GameActor
{
public:
    MuroLadrillo(Texture* _textura, Tile* _tileActual);
    void setTileActual(Tile* _tileNuevo);
};
