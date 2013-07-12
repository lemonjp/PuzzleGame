//
//  PGPlayerControl.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-12.
//
//

#include "PGPlayerControl.h"

extern const char* moveLeft;
extern const char* moveRight;
extern const char* jump;

using namespace cocos2d;

CCScene* PGPlayerControl ::scene(){
    CCScene* scene=CCScene::create();
    PGPlayerControl *layer=PGPlayerControl::create();
    scene->addChild(layer);
    return scene;
}

bool PGPlayerControl::init(){
    if (!CCLayer::init()) {
        return false;
    }
    
    //添加玩家
    PGPlayer::sharedPlayer()->createPlayer(this);
    
    //游戏控制层
    gameControl *control=gameControl::create();
    this->addChild(control,200);
    
    ADD_OBSERVER(moveLeft, PGPlayerControl::playerMoveLeft);
    ADD_OBSERVER(moveRight, PGPlayerControl::playerMoveRight);
    ADD_OBSERVER(jump, PGPlayerControl::playerJumping);
    
    return true;
}

#pragma mark-
#pragma mark player moving method
void PGPlayerControl::playerMoveLeft(){
    PGPlayer::sharedPlayer()->playerMoveingInBox2d(p_left);
}

void PGPlayerControl::playerMoveRight(){
    PGPlayer::sharedPlayer()->playerMoveingInBox2d(p_right);
}

void PGPlayerControl::playerJumping(){
    
}