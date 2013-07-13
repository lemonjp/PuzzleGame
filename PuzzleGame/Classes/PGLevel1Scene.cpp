//
//  PGLevel1Scene.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-12.
//
//

#include "PGLevel1Scene.h"

using namespace cocos2d;

CCScene* PGLevel1Scene::scene(){
    CCScene *scene = CCScene :: create();
    PGLevel1Scene *layer = PGLevel1Scene::create();
    scene->addChild(layer);
    return scene;
}

bool PGLevel1Scene::init(){
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    //添加背景
    //this->addGameBackground(this,ccp(size.width/2,size.height/2));
    //this->addGameBackground(this,ccp(size.width/2+size.width,size.height/2));
    //this->addGameBackground(this,ccp(size.width/2+size.width*2,size.height/2));
    
    //添加可以移动的箱子
    PGBox *box=new PGBox();
    box->addBoxToScreen(this, ccp(100, 200));
    
    return true;
}

void PGLevel1Scene::addGameBackground(CCLayer *layer, CCPoint pos){
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite *bg=CCSprite::create("background1.png");
    bg->setPosition(ccp(pos.x, pos.y));
    bg->setScale(0.5f);
    layer->addChild(bg);
    
    CCSprite *green=CCSprite::create("green.png");
    green->setPosition(ccp(pos.x,pos.y));
    green->setScale(0.5f);
    layer->addChild(green,70);
}