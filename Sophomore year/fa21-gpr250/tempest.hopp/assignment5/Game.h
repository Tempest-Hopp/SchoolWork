#pragma once
#include <Trackable.h>
#include <iostream>
#include <ctime>
#include <PerformanceTracker.h>

#include "Event.h"
#include "EventListener.h"
#include "EventSystem.h"
#include "GameEvents.h"
#include "Timer.h"
#include "System.h"
#include "GraphicsSystem.h"
#include "Sprite.h"
#include "GraphicsBuffer.h"
#include "Unit.h"
#include "UnitManager.h"
#include "GraphicsBufferManager.h"
#include "InputTranslator.h"
using namespace std;
class Game :
    public Trackable, public EventListener
{

    const string ASSET_PATH = "..\\..\\shared\\assets\\";
    const string SMURF_FILENAME = "smurf_sprites.png";
    const string DEAN_FILENAME = "dean_sprites.png";
    const string WOODS_FILENAME = "Woods.png";
private:
    static Game* mGame;

    System* mpSystem;

    UnitManager* mUnitManager;
    GraphicsBufferManager* mGraphicsBufferManager;

    InputTranslator* mpInputTranslator;

    double mTimePerFrame;
    bool mIsRunning;

public:
    Game();
    Game(const Game &other) = delete;
    ~Game();
    void Init(int width, int height, double fps);
    void defineUnit(Vector2D location);
    void Cleanup();
    void DoLoop();
    void getInput();
    void Update(double fps);
    void Render();
    void handleEvent(const Event& theEvent);


    UnitManager* getUnitManager() { return mUnitManager; };
    GraphicsBufferManager* getGraphicsBufferManager() { return mGraphicsBufferManager; };

    static Game* getInstance();
};
