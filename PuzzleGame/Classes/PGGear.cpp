//
//  PGGear.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-10.
//
//

#include "PGGear.h"

PGGear::PGGear(){
}

PGGear::~PGGear(){
    CC_SAFE_DELETE(gearBody);
}

void PGGear::addGearToScreen(CCLayer *layer, CCPoint point){
    gearBody=new SpriteBody();
    gearBody->initWithFile("gameProp1.png", CCRectMake(0, 0, 45, 45));
    gearBody->setPosition(point);
    //gearBody->autorelease();
    
    layer->addChild(gearBody);
    
    BasicPhysics::sharedPhysics()->createBody(gearBody,
                                              gearBody->getPosition(),
                                              b2_staticBody,
                                              1.0f,1.0f,0.0f,
                                              gearBody->getContentSize());
    //产生旋转关节
    //BasicPhysics::sharedPhysics()->createRevoiuteJoint(gearBody->getPhysicsBody(), 30);
}

void PGGear::removeGearFromScreen(CCLayer *layer){
    if (!gearBody) {
        CCLOG("gearBody is not created!");
        return;
    }
    BasicPhysics::sharedPhysics()->destroyBody(gearBody);
    layer->removeChild(gearBody, true);
}

bool PGGear::spriteIsContactGear(CCSprite* sprite){
    CCRect gearRect=CCRectMake(gearBody->getPosition().x-gearBody->getContentSize().width/2,
                               gearBody->getPosition().y-gearBody->getContentSize().height/2,
                               gearBody->getContentSize().width,
                               gearBody->getContentSize().height);
    CCRect spriteRect=CCRectMake(sprite->getPosition().x-sprite->getContentSize().width/2,
                                 sprite->getPosition().y-sprite->getContentSize().height/2,
                                 sprite->getContentSize().width,
                                 sprite->getContentSize().height);
    
    if (gearRect.intersectsRect(spriteRect)) {
        return true;
    }
    return false;
}

void PGGear::moveElement(float speedX, float speedY){
    int PTM_RATIO=BasicPhysics::sharedPhysics()->getRATIO();
    gearBody->setTransform(b2Vec2((gearBody->getPosition().x+speedX)/PTM_RATIO,
                                 (gearBody->getPosition().y+speedY)/PTM_RATIO),0);
}

void PGGear::gearRotation(){
    gearBody->setAngle(30);
}

CCPoint PGGear::getElementPosition(){
    return gearBody->getPosition();
}