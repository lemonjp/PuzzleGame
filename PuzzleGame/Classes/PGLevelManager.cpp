//
//  PGLevelManager.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-12.
//
//

#include "PGLevelManager.h"

extern const char* moveLeft;
extern const char* moveRight;
extern const char* jump;

extern const char* contactBegin;
extern const char* contactEnd;

CCScene* PGLevelManager::scene(){
    CCScene* scene=CCScene::create();
    PGLevelManager *layer=PGLevelManager::create();
    scene->addChild(layer);
    return scene;
}

bool PGLevelManager::init(){
    if (!CCLayer::init()) {
        return false;
    }
    
    winSize=CCDirector::sharedDirector()->getWinSize();
    
    //添加关卡背景和元素的层
    currentScene=PGLevel1Scene::create();
    currentScene->setPosition(ccp(0,0));
    this->addChild(currentScene);
    
    //添加游戏控制和主角的层
    //添加玩家
    PGPlayer::sharedPlayer()->createPlayer(this);
    referPoint=PGPlayer::sharedPlayer()->getSpriteBody()->getPosition();

    //游戏控制层
    gameControl *control=gameControl::create();
    this->addChild(control,200);
    
    //添加观察者
    ADD_OBSERVER(moveLeft, PGLevelManager::playerMoveLeft);
    ADD_OBSERVER(moveRight, PGLevelManager::playerMoveRight);
    ADD_OBSERVER(jump, PGLevelManager::playerJumping);
    
    //box2d碰撞检测
    ADD_OBSERVER(contactBegin,PGLevelManager::contactBegining);
    ADD_OBSERVER(contactEnd,PGLevelManager::contactEnded);
    
    //更新函数
    scheduleUpdate();
    
    return true;
}

void PGLevelManager::update(float dt){
    BasicPhysics::sharedPhysics()->update(dt);
    //碰撞检测
    currentScene->isContactGear();
}

void PGLevelManager::draw(){
    CCLayer::draw();
    BasicPhysics::sharedPhysics()->draw();
}

#pragma mark-
#pragma mark player moving method
void PGLevelManager::playerMoveLeft(){
    float playerSpeed=PGPlayer::sharedPlayer()->getSpeed();
    if (referPoint.x<Scene_Move_MIN_Width||
        referPoint.x>(Scene_Move_MAX_Width-Scene_Move_MIN_Width)) {
        if (referPoint.x<=0) return;
        referPoint=ccpAdd(referPoint, ccp(-playerSpeed,0));
        PGPlayer::sharedPlayer()->playerMoveingInBox2d(p_left);
        return;
    }else{
        referPoint=ccpAdd(referPoint, ccp(-playerSpeed,0));
        if(!currentScene->moveLevelScene(playerSpeed, 0)){//如果没有移动就复位
            referPoint=ccpAdd(referPoint,ccp(playerSpeed,0));
        }
    }
}

void PGLevelManager::playerMoveRight(){
    float playerSpeed=PGPlayer::sharedPlayer()->getSpeed();
    if (referPoint.x<Scene_Move_MIN_Width||
        referPoint.x>(Scene_Move_MAX_Width-Scene_Move_MIN_Width)) {
        if (referPoint.x>=Scene_Move_MAX_Width) return;
        referPoint=ccpAdd(referPoint, ccp(playerSpeed,0));
        PGPlayer::sharedPlayer()->playerMoveingInBox2d(p_right);
        return;
    }else{
        referPoint=ccpAdd(referPoint,ccp(playerSpeed,0));
        if(!currentScene->moveLevelScene(-playerSpeed, 0)){//如果没有移动就复位
            referPoint=ccpAdd(referPoint,ccp(-playerSpeed,0));
        }
    }
}

void PGLevelManager::playerJumping(){
    PGPlayer::sharedPlayer()->playerJumpingInBox2d();
}

#pragma mark -
#pragma mark contact Event
void PGLevelManager::contactBegining(){
    if ((int)(PGPlayer::sharedPlayer()->getSpriteBody()->getLinearImpulse().y)==0) return;
    PGPlayer::sharedPlayer()->setIsContinueCollde(true);
}

void PGLevelManager::contactEnded(){
    if ((int)(PGPlayer::sharedPlayer()->getSpriteBody()->getLinearImpulse().y)==0) return;
    PGPlayer::sharedPlayer()->setIsContinueCollde(false);
}