//
//  HelloWorldScene.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-6-19.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "PGGameControl.h"

extern const char* moveLeft;
extern const char* moveRight;
extern const char* jump;

using namespace cocos2d;
using namespace CocosDenshion;


HelloWorld::HelloWorld()
{
    
    physics=new BasicPhysics();
    this->initPhysics();
    
    gameControl *control = gameControl::create();
    this->addChild(control,99);
    
    PGPausePlugin::sharedPlugin()->createPlugin(this);
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite *bg=CCSprite::create("HelloWorld.png");
    bg->setPosition(ccp(size.width/2, size.height/2));
    this->addChild(bg);
    
    PGPlayer::sharedPlayer()->createPlayer(this);
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::initPhysics()
{
    physics->initWithPhysics();
}


void HelloWorld::update(float dt)
{
    physics->update(dt);
}

void HelloWorld::draw()
{
    
}

void
HelloWorld::leftMoving(){
    sp->setPositionX(sp->getPositionX()-1);
}

void
HelloWorld::rightMoving(){
    sp->setPositionX(sp->getPositionX()+1);
}

void
HelloWorld::jumpping(){
    if (sp->getPositionY()>320) sp->setPositionY(0);
    sp->setPositionY(sp->getPositionY()+1);
}


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // add layer as a child to scene
    CCLayer* layer = new HelloWorld();
    scene->addChild(layer);
    layer->release();
    
    return scene;
}
