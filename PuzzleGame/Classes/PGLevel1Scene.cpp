//
//  PGLevel1Scene.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-12.
//
//

#include "PGLevel1Scene.h"

PGLevel1Scene::PGLevel1Scene(){}
PGLevel1Scene::~PGLevel1Scene(){
    CC_SAFE_DELETE_ARRAY(elements);
    CC_SAFE_DELETE_ARRAY(backgrounds);
}

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
    
    //游戏中的元素数组
    elements=CCArray::create();
    elements->retain();
    backgrounds=CCArray::create();
    backgrounds->retain();
    
    //添加背景
//    this->addGameBackground(this,ccp(size.width/2,size.height/2));
//    this->addGameBackground(this,ccp(size.width/2+size.width,size.height/2));
//    this->addGameBackground(this,ccp(size.width/2+size.width*2,size.height/2));
//    this->addGameBackground(this,ccp(size.width/2+size.width*3,size.height/2));
//    this->addGameBackground(this,ccp(size.width/2+size.width*4,size.height/2));
    
    //添加box和step
    this->addGameBoxs(this);
    this->addGameSteps(this);
    this->addGameGear(this);
    
    return true;
}

void PGLevel1Scene::isContactGear(){
    CCSprite *player=PGPlayer::sharedPlayer()->getSpriteBody();
    for (int i=0; i<elements->count(); i++) {
        PGGear *gear=dynamic_cast<PGGear*>(elements->objectAtIndex(i));
        if (gear!=NULL) {//如果是box对象
            if (gear->spriteIsContactGear(player)) {
                CCLOG("---contact gear---");
            }
        }
    }
}

#pragma mark -
#pragma mark secne move event
bool PGLevel1Scene::moveLevelScene(float speedX,float speedY){
    if(!this->isAllowMoveScene(speedX)){
        return false;
    }else{
        //遍历
        for (int i=0;i<backgrounds->count();i++) {
            CCSprite *sprite=dynamic_cast<CCSprite*>(backgrounds->objectAtIndex(i));
            sprite->setPosition(ccpAdd(sprite->getPosition(),ccp(speedX,speedY)));
        }
        for (int i=0; i<elements->count(); i++) {
            PGElement *element=dynamic_cast<PGElement*>(elements->objectAtIndex(i));
            element->moveElement(speedX, speedY);
        }
    }
    return true;
}

bool PGLevel1Scene::isAllowMoveScene(float dir){
    CCPoint playerPos=PGPlayer::sharedPlayer()->getSpriteBody()->getPosition();
    CCPoint realPos=ccpAdd(ccp(-dir,0), playerPos);
    
    for (int i=0; i<elements->count(); i++) {
        PGElement *element=dynamic_cast<PGElement*>(elements->objectAtIndex(i));
        CCPoint elementPos=element->getElementPosition();
        if (abs(ccpSub(realPos,elementPos).x)<=41) {
            if (abs(ccpSub(realPos,elementPos).y)<=20.0f) {
                return false;
            }
            continue;
        }
    }
    return true;
}

#pragma mark -
#pragma mark 游戏元素

void PGLevel1Scene::addGameBackground(CCLayer *layer, CCPoint pos){
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    CCSprite *bg=CCSprite::create("background1.png");
    bg->setPosition(ccp(pos.x, pos.y));
    bg->setScale(0.5f);
    layer->addChild(bg);
    backgrounds->addObject(bg);
    
    CCSprite *green=CCSprite::create("green.png");
    green->setPosition(ccp(pos.x,pos.y));
    green->setScale(0.5f);
    layer->addChild(green,70);
    backgrounds->addObject(green);
}

void PGLevel1Scene::addGameBoxs(CCLayer* layer){
    PGBox *box=new PGBox();
    box->addBoxToScreen(this, ccp(100, 200));
    elements->addObject(box);
    box->release();
}

void PGLevel1Scene::addGameSteps(CCLayer* layer){
    //添加台阶1
    for (int i=0;i<3; i++) {
        PGStep *step=new PGStep();
        step->addStepToScreen(this, ccp(410,100+30*i));
        elements->addObject(step);
        step->release();
    }
    //添加台阶2
    for (int i=0;i<3; i++) {
        PGStep *step=new PGStep();
        step->addStepToScreen(this, ccp(440,100+30*i));
        elements->addObject(step);
        step->release();
    }
    //添加台阶3
    for (int i=0; i<3; i++) {
        PGStep *step=new PGStep();
        step->addStepToScreen(this, ccp(530-30*i,100));
        elements->addObject(step);
        step->release();
    }
    //添加台阶4
    PGStep *step=new PGStep();
    step->addStepToScreen(this, ccp(758, 100));
    elements->addObject(step);
    step->release();
}

void PGLevel1Scene::addGameGear(CCLayer *layer){
    //齿轮1
    for (int i=0; i<4; i++) {
        PGGear *gear=new PGGear();
        gear->addGearToScreen(this,ccp(570+48*i,105));
        elements->addObject(gear);
        gear->release();
    }
    //齿轮2
    for (int i=0; i<4; i++) {
        PGGear *gear2=new PGGear();
        gear2->addGearToScreen(this,ccp(890+120*i,105));
        elements->addObject(gear2);
        gear2->release();
    }
}