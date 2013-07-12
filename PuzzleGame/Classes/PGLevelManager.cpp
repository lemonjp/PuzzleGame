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
    
    //添加关卡背景和元素的层
    PGLevel1Scene *scene=PGLevel1Scene::create();
    scene->setPosition(ccp(-100,0));
    this->addChild(scene);
    
    //添加游戏控制和主角的层
    PGPlayerControl *playerConrtol=PGPlayerControl::create();
    this->addChild(playerConrtol);
    
    //更新函数
    scheduleUpdate();
    
    return true;
}

void PGLevelManager::update(float dt){
    BasicPhysics::sharedPhysics()->update(dt);
}