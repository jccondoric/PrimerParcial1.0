#pragma once
#include "GameActor.h"
class MuroGalactico:
    public GameActor
{
public:
    MuroGalactico(Texture* _textura, Tile* _tileActual);
    void setTileActual(Tile* _tileNuevo);
};
