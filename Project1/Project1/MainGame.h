#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>

enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	MainGame(void);
	~MainGame(void);

	void run();

private:
    //Init systems
	void initSystems();
	void processInput();
	
    //Game Loop
	void gameLoop();
    void drawGame();
	GameState _currentGameState;
    void drawTriangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);

    //Screen
	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
};

