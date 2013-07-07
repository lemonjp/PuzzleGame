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
#include "PGPlayer.h"

using namespace cocos2d;

class DemoLayer : CCLayer{
public:
    static CCScene* scene();
    
    virtual bool init();
    
    void update(float dt);
    
    void playerMoveLeft();
    void playerMoveRight();
    void playerJumping();
    
    CREATE_FUNC(DemoLayer);
private:
    void addGameBackground(CCLayer* layer);
    void addGamePauseButton(CCLayer* layer);
};

#endif /* defined(__PuzzleGame__DemoLayer__) */
