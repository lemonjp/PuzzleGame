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
    //物理环境的单例
    static BasicPhysics* sharedPhysics();
    //释放单例 消除世界
    void end();
    
    //初始化物理世界
    void initWithPhysics();
    
    //更新
    void update(float dt);
    //产生刚体
    void createBody(SpriteBody *sprite,
                    CCPoint position,
                    b2BodyType type,
                    float density,
                    float friction,
                    float restitution,
                    CCPoint boxData);
    //删除刚体
    void destroyBody(SpriteBody *sprite);
private:
    CC_SYNTHESIZE_READONLY(b2World*, world_, World);
    CC_SYNTHESIZE(int, PTM_RATIO, RATIO);
    
    void crateEdgeShape(b2Body* groundBody,b2EdgeShape groundBox);
};

#endif /* defined(__PuzzleGame__BasicPhysics__) */
