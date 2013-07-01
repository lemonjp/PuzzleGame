//
//  PhysicsSprite.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-6-20.
//
//

#include "PhysicsSprite.h"

#define PTM_RATIO 32

void BWContactListener::BeginContact(b2Contact* contact){
    if (contact) {
        //Add Audio
        mc.fixtureA=contact->GetFixtureA();
        mc.fixtureB=contact->GetFixtureB();
        
        mc.bodyA=contact->GetFixtureA()->GetBody();
        mc.bodyB=contact->GetFixtureB()->GetBody();
        
        SpriteBody *spriteA=(SpriteBody*)mc.bodyA->GetUserData();
        SpriteBody *spriteB=(SpriteBody*)mc.bodyB->GetUserData();
        
//        if (spriteA!=NULL) {
//            spriteA->setIsColliding(true);
//            if (mc.bodyA->GetLinearVelocity().y<-0.1){//下落
//                spriteA->setIsContinueColliding(true);
//            }
//        }
//        if(spriteB!=NULL){
//            spriteB->setIsColliding(true);//代表碰撞了
//            if (mc.bodyB->GetLinearVelocity().y<-0.1){//下落
//                spriteB->setIsContinueColliding(true);
//            }
//        }
//        
        contact_list.push_back(mc);
    }
    B2_NOT_USED(contact);
    //CCLOG("Begin!");
}

void BWContactListener::EndContact(b2Contact* contact){
    SpriteBody *spriteA=(SpriteBody*)mc.bodyA->GetUserData();
    SpriteBody *spriteB=(SpriteBody*)mc.bodyB->GetUserData();
    
//    if (spriteA!=NULL) {
//        spriteA->setIsColliding(false);
//        CCLOG("%f",mc.bodyA->GetLinearVelocity().y);
//        //不符合让持续碰撞停止条件
//        if (mc.bodyA->GetLinearVelocity().y>0.1){
//            spriteA->setIsContinueColliding(false);
//        }
//    }
//    if(spriteB!=NULL){
//        spriteB->setIsColliding(false);//代表碰撞了
//        CCLOG("%f",mc.bodyB->GetLinearVelocity().y);
//        //不符合让持续碰撞停止条件
//        if (mc.bodyB->GetLinearVelocity().y>0.1){
//            spriteB->setIsContinueColliding(false);
//        }
//    }
    
    contact_list.clear();
    B2_NOT_USED(contact);
}


SpriteBody::SpriteBody()
: m_pBody(NULL)
{
    
}


bool SpriteBody::isDirty(void)
{
    return true;
}

CCAffineTransform SpriteBody::nodeToParentTransform(void)
{
    b2Vec2 pos  = m_pBody->GetPosition();
    
    float x = pos.x * PTM_RATIO;
    float y = pos.y * PTM_RATIO;
    
    if ( isIgnoreAnchorPointForPosition() ) {
        x += m_tAnchorPointInPoints.x;
        y += m_tAnchorPointInPoints.y;
    }
    
    // Make matrix
    float radians = m_pBody->GetAngle();
    float c = cosf(radians);
    float s = sinf(radians);
    
    if( ! CCPoint::CCPointEqualToPoint(m_tAnchorPointInPoints, CCPointZero) ){
        x += c*-m_tAnchorPointInPoints.x + -s*-m_tAnchorPointInPoints.y;
        y += s*-m_tAnchorPointInPoints.x + c*-m_tAnchorPointInPoints.y;
    }
    
    // Rot, Translate Matrix
    m_tTransform = CCAffineTransformMake( c,  s,
                                         -s,  c,
                                         x,  y );
    
    return m_tTransform;
}
