//
//  DemoLayer.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-6.
//
//

#include "DemoLayer.h"

extern const char* moveLeft;
extern const char* moveRight;
extern const char* jump;

using namespace cocos2d;

CCScene* DemoLayer::scene(){
    CCScene* scene=CCScene::create();
    
    DemoLayer *layer=DemoLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool DemoLayer::init(){
    //生成层失败
    if (!CCLayer::init()) {
        return false;
    }
    //添加背景
    this->addGameBackground(this);
    //添加暂停按钮
    this->addGamePauseButton(this);
    PGPlayer::sharedPlayer()->createPlayer(this);
    
    scheduleUpdate();
    
    return true;
}

void DemoLayer::update(float dt){
    BasicPhysics::sharedPhysics()->update(dt);
}

void DemoLayer::addGamePauseButton(CCLayer *layer){
    CCSprite *sprite=CCSprite::create("buttons.png", CCRectMake(84*2, 0, 84, 84));
    sprite->setPosition(ccp(100,100));
    layer->addChild(sprite);
}

void DemoLayer::addGameBackground(CCLayer* layer){
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite *bg=CCSprite::create("background1.png");
    bg->setPosition(ccp(size.width/2, size.height/2));
    bg->setScale(0.5f);
    layer->addChild(bg);
}

#pragma mark-
#pragma mark player moving method
void DemoLayer::playerMoveLeft(){
    
}

void DemoLayer::playerMoveRight(){
    
}

void DemoLayer::playerJumping(){
    
}