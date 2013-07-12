//
//  DemoLayer.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-6.
//
//

#ifndef __PuzzleGame__DemoLayer__
#define __PuzzleGame__DemoLayer__

#include "cocos2d.h"

#include "BasicPhysics.h"
#include "PhysicsSprite.h"
#include "MenuButtons.h"

#include "PGPlayer.h"
#include "PGGear.h"
#include "PGBox.h"
#include "PGGameControl.h"

using namespace cocos2d;

class DemoLayer : public CCLayer{
public:
    static CCScene* scene();
    
    virtual bool init();
    
    void update(float dt);
    
    void playerMoveLeft();
    void playerMoveRight();
    void playerJumping();
    
    CREATE_FUNC(DemoLayer);
private:
    //添加背景
    void addGameBackground(CCLayer* layer);
    //添加暂停按钮
    void addGamePauseButton(CCLayer* layer);
    //添加齿轮
    void addGameGear(CCLayer* layer);
};

#endif /* defined(__PuzzleGame__DemoLayer__) */
