//
//  PGGear.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-10.
//
//

#include "PGGear.h"

using namespace cocos2d;

PGGear::PGGear(){
}

PGGear::~PGGear(){
}

void PGGear::addGearToScreen(CCLayer *layer, CCPoint point){
    gearBody=new SpriteBody();
    gearBody->initWithFile("gameProp1.png", CCRectMake(0, 0, 60, 60));
    gearBody->setPosition(point);
    gearBody->autorelease();
    
    layer->addChild(gearBody);
    
    BasicPhysics::sharedPhysics()->createBody(gearBody,
                                              gearBody->getPosition(),
                                              b2_staticBody,
                                              0.8f,0.5f,0.0f,
                                              CCSizeMake(1.0f, 1.0f));
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
