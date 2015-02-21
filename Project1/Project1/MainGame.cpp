#include "MainGame.h"
#include "StdOutTools.h"
#include <iostream>
#include <string>


MainGame::MainGame(void) {
    _window = nullptr;
    _screenWidth = 1024;
    _screenHeight = 768;
    _currentGameState = GameState::PLAY;
}

MainGame::~MainGame(void) {
}

void MainGame::run() {
    initSystems();
    gameLoop();
}

void MainGame::initSystems() {
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

    if (_window == nullptr) {
        StdOutTools::fatalError("Failed to create window");
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(_window);

    if (_window == nullptr) {
        StdOutTools::fatalError("SDL_GLContext could not be created");
    }

    GLenum error = glewInit();
    if (error != GLEW_OK) {
        StdOutTools::fatalError("Could not init glew");
    }

    //one screen clears while the other is rendering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0,0,0,1.0);
}

void MainGame::gameLoop() {
    while (_currentGameState != GameState::EXIT) {
        processInput();
        drawGame();
    }
}

void MainGame::processInput() {
    SDL_Event evnt;
    while(SDL_PollEvent(&evnt)) {
        switch (evnt.type) {
            case SDL_MOUSEMOTION:
                std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
                break;
            case SDL_QUIT:
                _currentGameState = GameState::EXIT;
                break;
            default:
                break;
        }
    }
}

void MainGame::drawTriangle(GLfloat r, GLfloat g, GLfloat b, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3) {
    glBegin(GL_TRIANGLES);
    glColor3f(r, g, b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void MainGame::drawGame() {
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glEnableClientState(GL_COLOR_ARRAY);

    //drawTriangle(1.0f, 0.0f, 1.0f, 480, 384, 544, 384, 512, 400);
    drawTriangle(1.0f, 0.0f, 1.0f, -.5f, 0.0f, 0.0f, -.5f, .5f, .5f);

    SDL_GL_SwapWindow(_window);
}
