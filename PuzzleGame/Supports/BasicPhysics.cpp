//
//  BasicPhysics.cpp
//  PuzzleGame
//
//  Created by 何遵祖 on 13-6-19.
//
//

#include "BasicPhysics.h"

using namespace cocos2d;

static BasicPhysics* gamePhysics;

BasicPhysics* BasicPhysics::sharedPhysics(){
    if (!gamePhysics) {
        gamePhysics=new BasicPhysics();
        gamePhysics->initWithPhysics();
        
    }
    return gamePhysics;
}

void BasicPhysics::end(){
    gamePhysics=NULL;
    CC_SAFE_RELEASE(gamePhysics);
    
    //删除世界
    CC_SAFE_DELETE(world_);
    world_=NULL;
}

void BasicPhysics::initWithPhysics(){
    PlistLoader *loader=PlistLoader::initWithPlistFile("PhysicsWorldPlist.plist");
    CCString *pointStr=(CCString*)loader->getObjectFromFileKey("Gravity");
    CCPoint gravityPoint=CCPointFromString(pointStr->getCString());
    
    CCString *ratioString=(CCString*)loader->getObjectFromFileKey("PTM_RATIO");
    PTM_RATIO=ratioString->intValue();
    
    b2Vec2 gravity;
    gravity.Set(gravityPoint.x, gravityPoint.y);
    
    world_=new b2World(gravity);
    
    bool allowSleeping=loader->getObjectFromFileKey("AllowSleeping");
    world_->SetAllowSleeping(allowSleeping);
    bool contiunousPhysics=loader->getObjectFromFileKey("ContinuousPhysics");
    world_->SetContinuousPhysics(contiunousPhysics);
    
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, 0);
    b2Body* groundBody=world_->CreateBody(&groundBodyDef);
    b2EdgeShape groundBox;
    
    this->crateEdgeShape(groundBody, groundBox);
}

void BasicPhysics::crateEdgeShape(b2Body *groundBody, b2EdgeShape groundBox){
    CCSize s=CCDirector::sharedDirector()->getWinSize();
    //产生四边的碰撞墙壁
    //底部
    groundBox.Set(b2Vec2(0,0),b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
    //顶部
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO));
    groundBody->CreateFixture(&groundBox,0);
    //左边
    groundBox.Set(b2Vec2(0,s.height/PTM_RATIO), b2Vec2(0,0));
    groundBody->CreateFixture(&groundBox,0);
    //右边
    groundBox.Set(b2Vec2(s.width/PTM_RATIO,s.height/PTM_RATIO), b2Vec2(s.width/PTM_RATIO,0));
    groundBody->CreateFixture(&groundBox,0);
}

void BasicPhysics::update(float dt){
    //It is recommended that a fixed time step is used with Box2D for stability
    //of the simulation, however, we are using a variable time step here.
    //You need to make an informed choice, the following URL is useful
    //http://gafferongames.com/game-physics/fix-your-timestep/
    
    int velocityIterations = 8;
    int positionIterations = 1;
    
    // Instruct the world to perform a single step of simulation. It is
    // generally best to keep the time step and iterations fixed.
    world_->Step(dt, velocityIterations, positionIterations);
    
    //Iterate over the bodies in the physics world
    for (b2Body* b = world_->GetBodyList(); b; b = b->GetNext())
    {
        if (b->GetUserData() != NULL) {
            //Synchronize the AtlasSprites position and rotation with the corresponding body
            CCSprite* myActor = (CCSprite*)b->GetUserData();
            myActor->setPosition( CCPointMake( b->GetPosition().x * PTM_RATIO, b->GetPosition().y * PTM_RATIO) );
            myActor->setRotation( -1 * CC_RADIANS_TO_DEGREES(b->GetAngle()) );
        }
    }
}

void BasicPhysics::createBody(SpriteBody *sprite,
                              CCPoint position,
                              b2BodyType type,
                              float density,
                              float friction,
                              float restitution,
                              CCPoint boxData){
    b2BodyDef bodyDef;
    bodyDef.type=type;
    bodyDef.position.Set(position.x/PTM_RATIO, position.y/PTM_RATIO);
    bodyDef.userData=sprite;
    
    //在物理世界中产生body
    b2Body *body=world_->CreateBody(&bodyDef);
    
    //产生一个squareBox
    //产生一个square box
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(boxData.x,boxData.y);
    
    b2FixtureDef fixtureDef;
    fixtureDef.shape=&dynamicBox;
    fixtureDef.density=density;//密度
    fixtureDef.friction=friction;//设置摩擦
    fixtureDef.restitution=restitution;//恢复
    
    body->CreateFixture(&fixtureDef);
    
    sprite->setPhysicsBody(body);
}

void BasicPhysics::destroyBody(SpriteBody *sprite){
    b2Body *spriteBody=sprite->getPhysicsBody();
    world_->DestroyBody(spriteBody);
}