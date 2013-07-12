//
//  PGGear.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-10.
//
//

#ifndef __PuzzleGame__PGGear__
#define __PuzzleGame__PGGear__

#include "cocos2d.h"
#include "BasicPhysics.h"
#include "PhysicsSprite.h"

using namespace cocos2d;

class PGGear : public CCObject{
public:
    PGGear();
    ~PGGear();
    
    //添加刺轮到屏幕上
    void addGearToScreen(CCLayer* layer,CCPoint position);
    //检测是否有精灵碰撞到刺轮
    bool spriteIsContactGear(CCSprite *sprite);
private:
    CC_SYNTHESIZE(SpriteBody*, gearBody, GearBody);
};

#endif /* defined(__PuzzleGame__PGGear__) */
