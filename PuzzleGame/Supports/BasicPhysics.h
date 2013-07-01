//
//  BasicPhysics.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-6-19.
//
//

#ifndef __PuzzleGame__BasicPhysics__
#define __PuzzleGame__BasicPhysics__

#include "cocos2d.h"
#include "Box2D.h"

#include "PhysicsSprite.h"
#include "PlistLoader.h"

using namespace cocos2d;

class BasicPhysics : CCObject{
public:
    BasicPhysics(){};
    virtual ~BasicPhysics(){};
    
    //初始化物理世界
    void initWithPhysics();
    void crateEdgeShape(b2Body* groundBody,b2EdgeShape groundBox);
    
    //产生刚体
    void createBody(SpriteBody* sprite,
                    CCPoint position,
                    float restitution,
                    b2BodyType type,
                    CCPoint boxData);
    
    //更新
    void update(float dt);
private:
    CC_SYNTHESIZE_READONLY(b2World*, world_, World);
    CC_SYNTHESIZE(int, PTM_RATIO, RATIO);
};

#endif /* defined(__PuzzleGame__BasicPhysics__) */
