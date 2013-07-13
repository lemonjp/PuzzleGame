//
//  PGBox.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-11.
//
//

#include "PGBox.h"

using namespace cocos2d;

void PGBox::addBoxToScreen(CCLayer *layer, CCPoint point){
    boxBody=new SpriteBody();
    boxBody->initWithFile("gameProp1.png", CCRectMake(18, 154, 34, 38));
    boxBody->setPosition(point);
    boxBody->autorelease();
    layer->addChild(boxBody);
    
    CCLOG("%f,%f",boxBody->getContentSize().width,boxBody->getContentSize().height);
    BasicPhysics::sharedPhysics()->createBody(boxBody,
                                              boxBody->getPosition(),
                                              b2_dynamicBody,
                                              0.8f, 1.0f, 0.0f,
                                              boxBody->getContentSize());
}