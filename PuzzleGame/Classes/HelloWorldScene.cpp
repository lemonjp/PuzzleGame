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
    SpriteBody *sprite=new SpriteBody();
    sprite->initWithFile("Icon-72.png");
    sprite->setPosition(ccp(100,100));
    sprite->autorelease();
    
    this->addChild(sprite);
    
    BasicPhysics::sharedPhysics()->createBody(sprite,
                                              sprite->getPosition() ,
                                              b2_dynamicBody,
                                              1.0f,0.5f,1.0f,
                                              ccp(1.0f,1.0f));
    sprite->applyFroce(b2Vec2(100,100), b2Vec2(sprite->getPosition().x/32,sprite->getPosition().y/32));
    
    scheduleUpdate();
//    gameControl *control = gameControl::create();
//    this->addChild(control,99);
    
//    PGPausePlugin::sharedPlugin()->createPlugin(this);
    
//    CCSize size=CCDirector::sharedDirector()->getWinSize();
//    CCSprite *bg=CCSprite::create("HelloWorld.png");
//    bg->setPosition(ccp(size.width/2, size.height/2));
//    this->addChild(bg);
//    
//    PGPlayer::sharedPlayer()->createPlayer(this);
}

HelloWorld::~HelloWorld()
{
}


void HelloWorld::update(float dt)
{
   BasicPhysics::sharedPhysics()->update(dt);
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
