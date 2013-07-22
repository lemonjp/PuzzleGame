//
//  PGLevelManager.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-12.
//
//

#ifndef __PuzzleGame__PGLevelManager__
#define __PuzzleGame__PGLevelManager__

#include "cocos2d.h"

#include "BasicPhysics.h"
#include "PGPlayer.h"
#include "PGGameControl.h"

#include "PGLevelScene.h"
#include "PGLevel1Scene.h"

//屏幕移动最大距离
#define Scene_Move_MAX_Width 1920
//屏幕移动最小距离
#define Scene_Move_MIN_Width 243

using namespace cocos2d;

class PGLevelManager : public CCLayer{
public:
    static CCScene* scene();
    virtual bool init();
    CREATE_FUNC(PGLevelManager);
    
    void playerMoveLeft();
    void playerMoveRight();
    void playerJumping();
    
    void update(float dt);
    void draw();
    
    void contactBegining();
    void contactEnded();
    
private:
    PGLevelScene *currentScene;
    CCSize winSize;
    //参考点
    CCPoint referPoint;
    //游戏主循环
    void gameSchedule();
};
#endif /* defined(__PuzzleGame__PGLevelManager__) */
