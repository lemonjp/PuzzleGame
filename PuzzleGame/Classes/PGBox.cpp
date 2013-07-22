//
//  PGBox.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-11.
//
//

#include "PGBox.h"

PGBox::PGBox(){}
PGBox::~PGBox(){
    CC_SAFE_DELETE(boxBody);
}

void PGBox::addBoxToScreen(CCLayer *layer, CCPoint point){
    boxBody=new SpriteBody();
    boxBody->initWithFile("gameProp1.png", CCRectMake(13, 130, 34, 38));
    boxBody->setPosition(point);
    boxBody->autorelease();
    layer->addChild(boxBody);
    
    BasicPhysics::sharedPhysics()->createBody(boxBody,
                                              boxBody->getPosition(),
                                              b2_dynamicBody,
                                              0.8f, 0.5f, 0.0f,
                                              CCSizeMake(33, 37));
}

void PGBox::removeBoxFromScreen(CCLayer *layer){
    if (!boxBody) {
        CCLOG("不存在box组件");
        return;
    }
    BasicPhysics::sharedPhysics()->destroyBody(boxBody);
    layer->removeChild(boxBody, true);
}

void PGBox::moveElement(float speedX, float speedY){
    int PTM_RATIO=BasicPhysics::sharedPhysics()->getRATIO();
    boxBody->setTransform(b2Vec2((boxBody->getPosition().x+speedX)/PTM_RATIO,
                                 (boxBody->getPosition().y+speedY)/PTM_RATIO),0);
}

CCPoint PGBox::getElementPosition(){
    return ccp(100000,0);
}