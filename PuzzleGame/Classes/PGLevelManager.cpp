//
//  PGLevelManager.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-12.
//
//

#include "PGLevelManager.h"

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
    
    mapX=mapY=0;
    
    //添加关卡背景和元素的层
    PGLevel1Scene *scene=PGLevel1Scene::create();
    scene->setPosition(ccp(mapX,mapY));
    this->addChild(scene);
    
    //添加游戏控制和主角的层
    PGPlayerControl *playerConrtol=PGPlayerControl::create();
    this->addChild(playerConrtol);
    
    //更新函数
    scheduleUpdate();
    
    return true;
}

void PGLevelManager::gameSchedule(){
    CCSprite *sprite=PGPlayer::sharedPlayer()->getSpriteBody();
    CCLOG("%f,%f",sprite->getPosition().x,sprite->getPosition().y);
}

void PGLevelManager::update(float dt){
    BasicPhysics::sharedPhysics()->update(dt);
    this->gameSchedule();
}

void PGLevelManager::draw(){
    CCLayer::draw();
    BasicPhysics::sharedPhysics()->draw();
}