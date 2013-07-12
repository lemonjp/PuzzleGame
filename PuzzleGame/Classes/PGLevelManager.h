//
//  PGLevelManager.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-12.
//
//

#ifndef __PuzzleGame__PGLevelManager__
#define __PuzzleGame__PGLevelManager__

#include "cocos2d.h"

#include "BasicPhysics.h"

#include "PGPlayerControl.h"
#include "PGLevel1Scene.h"

using namespace cocos2d;

class PGLevelManager : public CCLayer{
public:
    static CCScene* scene();
    virtual bool init();
    CREATE_FUNC(PGLevelManager);
    
    void update(float dt);
};
#endif /* defined(__PuzzleGame__PGLevelManager__) */
