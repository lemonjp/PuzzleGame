//
//  PhysicsSprite.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-6-20.
//
//

#ifndef __PuzzleGame__PhysicsSprite__
#define __PuzzleGame__PhysicsSprite__

#include "cocos2d.h"
#include "Box2D.h"

using namespace cocos2d;
using std::list;

//box2d碰撞检测
/*用于放入碰撞检测需要的数据*/
class BWContact{
public:
    b2Fixture* fixtureA;
    b2Fixture* fixtureB;
    
    b2Body *bodyA;
    b2Body *bodyB;
    
};
class BWContactListener : public b2ContactListener{
public:
    /*开始碰撞时候会调用此方法*/
    virtual void BeginContact(b2Contact* contact);
    /*结束碰撞会调用此方法*/
    virtual void EndContact(b2Contact* contact);
    /*碰撞列表，用于存储碰撞信息*/
    std::list<BWContact> contact_list;
private:
    BWContact mc;//用于存储b2Contact相关信息
};

class SpriteBody : public CCSprite{
public:
    SpriteBody();
    virtual bool isDirty(void);
    virtual CCAffineTransform nodeToParentTransform(void);
private:
    CC_SYNTHESIZE(b2Body*, m_pBody, PhysicsBody);
};

#endif /* defined(__PuzzleGame__PhysicsSprite__) */
