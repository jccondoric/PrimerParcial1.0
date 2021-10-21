#include "MapGenerator.h"

MapGenerator::MapGenerator()
{
	anchoPantalla = 0;
	altoPantalla = 0;
	renderer = nullptr;
}

MapGenerator::MapGenerator(SDL_Renderer* _renderer, int _anchoPantalla, int _altoPantalla, TilesGraph* _tilesGraph):
	anchoPantalla(_anchoPantalla),
	altoPantalla(_altoPantalla),
	renderer(_renderer),
	tilesGraph(_tilesGraph)
{
	
}

bool MapGenerator::crearObjetosJuego(string _path)
{
	// Crea un flujo de archivo
	fstream file;

	// Abrir el archivo
	file.open(_path.c_str(), ios::in);

	if (file.is_open() == false) {
		std::cout << "No se pudo abrir el archivo de mapa" << std::endl;
		return false;
	}

	string line;
	
	Texture* texturaBomberman;
	texturaBomberman = new Texture();
	Texture* texturaBomberwoman;
	texturaBomberwoman = new Texture();
	Texture* texturaBombermanRobot;
	texturaBombermanRobot = new Texture();
	Texture* texturaMuroMetal;
	texturaMuroMetal = new Texture();
	Texture* texturaMuroCeramica;
	texturaMuroCeramica = new Texture();
	Texture* texturaSueloCesped;
	texturaSueloCesped = new Texture();
	Texture* texturaMuroLadrillo;
	texturaMuroLadrillo = new Texture();
	Texture* texturaMuroGalactico;
	texturaMuroGalactico = new Texture();
	Texture* texturaSueloCircuito;
	texturaSueloCircuito = new Texture();


	
	Texture::renderer = renderer;

	texturaBomberman->loadFromImage("resources/bomberman.jpg");
	texturaBombermanRobot->loadFromImage("resources/bombermanRobot.jpg");
	texturaBomberwoman->loadFromImage("resources/bomberman.jpg");
	texturaMuroCeramica->loadFromImage("resources/muro_ceramica.jpg");
	texturaMuroMetal->loadFromImage("resources/muro_metal.jpg");
	texturaSueloCesped->loadFromImage("resources/suelo_cesped.jpg");
	texturaMuroLadrillo->loadFromImage("resources/muro_ladrillo.jpg");
	texturaMuroGalactico->loadFromImage("resources/muro_galactico.jpg");
	texturaSueloCircuito->loadFromImage("resources/suelo_circuito.jpg");


	int x = 0;
	int y = 0;
	int bombermanPosicionX = -1;
	int bombermanPosicionY = -1;
	int bomberwomanPosicionX = -1;
	int bomberwomanPosicionY = -1;
	int bombermanRobotPosicionX = -1;
	int bombermanRobotPosicionY = -1;

	while (getline(file, line)) {
		vector<char> chars(line.begin(), line.end());
		x = 0;

		for (int i = 0; i < chars.size(); i++) {
			if (chars[i] != ' ') {
				GameObject* objetoNuevo = nullptr;
				Tile* tileNuevo = tilesGraph->getTileEn(x, y);
				switch (chars[i]) {
				case '0':
					objetoNuevo = new SueloCesped(texturaSueloCesped, tileNuevo);
					if (x > bombermanPosicionX && bombermanPosicionX == -1) {
						bombermanPosicionX = x;
						bombermanPosicionY = y;
					}

					if (x > bomberwomanPosicionX || y > bomberwomanPosicionY) {
						bomberwomanPosicionX = x;
						bomberwomanPosicionY = y;
					}
					if (x > bombermanRobotPosicionX || y > bombermanRobotPosicionY) {
						bombermanRobotPosicionX = x;
						bombermanRobotPosicionY = y;
					}

					//pilaObjetosJuegoMurosMetal.Insertar((GameActor*)objetoNuevo);

					break;
				case '1':
					objetoNuevo = new MuroCeramica(texturaMuroCeramica, tileNuevo);
					
					break;
				case '2':
					objetoNuevo = new MuroMetal(texturaMuroMetal, tileNuevo);
					break;
					
				case '3':
						objetoNuevo = new MuroLadrillo(texturaMuroLadrillo, tileNuevo);
					break;
				case '4':
					    objetoNuevo = new MuroGalactico(texturaMuroGalactico, tileNuevo);
					break;

				case '5':
					objetoNuevo = new SueloCircuito(texturaSueloCircuito, tileNuevo);
					if (x > bombermanPosicionX && bombermanPosicionX == -1) {
						bombermanPosicionX = x;
						bombermanPosicionY = y;
					}

					if (x > bomberwomanPosicionX || y > bomberwomanPosicionY) {
						bomberwomanPosicionX = x;
						bomberwomanPosicionY = y;
					}
					if (x > bombermanRobotPosicionX || y > bombermanRobotPosicionY) {
						bombermanRobotPosicionX = x;
						bombermanRobotPosicionY = y;
					}
					break;
					
				}
				if (objetoNuevo != nullptr) {
					((GameActor*)objetoNuevo)->setPosicionX(x * 34);
					((GameActor*)objetoNuevo)->setPosicionY(y * 34);
					vectorObjectosJuego.push_back(objetoNuevo);
					x++;
				}	
			}
		}
		y++;
	}


	
	GameObject* objetoBomberman = nullptr;
	Tile* tileNuevo = tilesGraph->getTileEn(bombermanPosicionX, bombermanPosicionY);
	objetoBomberman = new Bomberman(texturaBomberman, tileNuevo);
	if (objetoBomberman != nullptr) {
		((GameActor*)objetoBomberman)->setPosicionX(bombermanPosicionX * 34);
		((GameActor*)objetoBomberman)->setPosicionY(bombermanPosicionY * 34);
		vectorObjectosJuego.push_back(objetoBomberman);
	}


	GameObject* objetoBombermanRobot = nullptr;
	Tile* tileNuevo2 = tilesGraph->getTileEn(bombermanRobotPosicionX, bombermanRobotPosicionY);
	objetoBombermanRobot = new Bomberman(texturaBombermanRobot, tileNuevo2);
	if (objetoBomberman != nullptr) {
		((GameActor*)objetoBombermanRobot)->setPosicionX(bombermanRobotPosicionX * 34);
		((GameActor*)objetoBombermanRobot)->setPosicionY(bombermanRobotPosicionY * 34);
		vectorObjectosJuego.push_back(objetoBombermanRobot);
	}

	GameObject* objetoBomberwoman = nullptr;
	tileNuevo = tilesGraph->getTileEn(bomberwomanPosicionX, bomberwomanPosicionY);
	objetoBomberwoman = new Bomberman(texturaBomberwoman, tileNuevo);
	if (objetoBomberwoman != nullptr) {
		((GameActor*)objetoBomberwoman)->setPosicionX(bomberwomanPosicionX * 34);
		((GameActor*)objetoBomberwoman)->setPosicionY(bomberwomanPosicionY * 34);
		((GamePawn*)objetoBomberwoman)->setBotomBomba(SDLK_o);
		((GamePawn*)objetoBomberwoman)->setBotomArriba(SDLK_w);
		((GamePawn*)objetoBomberwoman)->setBotomAbajo(SDLK_s);
		((GamePawn*)objetoBomberwoman)->setBotomIzquierda(SDLK_a);
		((GamePawn*)objetoBomberwoman)->setBotomDerecha(SDLK_d);

		vectorObjectosJuego.push_back(objetoBomberwoman);
	}


	return false;
}

void MapGenerator::transferirObjetosJuego(vector<GameObject*>& _vectorObjetosJuegoDestino)
{
	for (int i = 0; i < vectorObjectosJuego.size(); i++) {
		_vectorObjetosJuegoDestino.push_back(vectorObjectosJuego[i]);
	}
}
