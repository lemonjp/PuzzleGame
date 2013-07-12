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
    //this->addGamePauseButton(this);
    PGPlayer::sharedPlayer()->createPlayer(this);
    //添加控制
    gameControl *control=gameControl::create();
    this->addChild(control,200);
    
    ADD_OBSERVER(moveLeft, DemoLayer::playerMoveLeft);
    ADD_OBSERVER(moveRight, DemoLayer::playerMoveRight);
    ADD_OBSERVER(jump, DemoLayer::playerJumping);
    
    //添加可以移动的box
    PGBox *box=new PGBox();
    box->addBoxToScreen(this, ccp(300,300));
    
    this->setPosition(ccp(-100,0));
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
    
    CCSprite *green=CCSprite::create("green.png");
    green->setPosition(ccp(size.width/2,size.height/2));
    green->setScale(0.5f);
    layer->addChild(green,70);
}

#pragma mark-
#pragma mark player moving method
void DemoLayer::playerMoveLeft(){
    PGPlayer::sharedPlayer()->playerMoveingInBox2d(p_left);
}

void DemoLayer::playerMoveRight(){
    PGPlayer::sharedPlayer()->playerMoveingInBox2d(p_right);
}

void DemoLayer::playerJumping(){
    
}