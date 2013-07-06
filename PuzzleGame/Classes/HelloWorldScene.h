//
//  HelloWorldScene.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-6-19.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//
#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

// When you import this file, you import all the cocos2d classes
#include "cocos2d.h"
#include "Box2D.h"
#include "PlistLoader.h"
#include "BasicPhysics.h"

#include "PGPausePlugin.h"
#include "PGPlayer.h"

class HelloWorld : public cocos2d::CCLayer {
public:
    ~HelloWorld();
    HelloWorld();
    
    // returns a Scene that contains the HelloWorld as the only child
    static cocos2d::CCScene* scene();
    
    void initPhysics();
    // adds a new sprite at a given coordinate
    void addNewSpriteAtPosition(cocos2d::CCPoint p);

    virtual void draw();
    void update(float dt);
    
    cocos2d::CCSprite *sp;
    void leftMoving();
    void rightMoving();
    void jumpping();
    
    CREATE_FUNC(HelloWorld);
    
private:
    b2World* world;
    cocos2d::CCTexture2D* m_pSpriteTexture; // weak ref
};

#endif // __HELLO_WORLD_H__
