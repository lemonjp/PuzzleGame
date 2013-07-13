//
//  PGPlayerControl.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-12.
//
//

#ifndef __PuzzleGame__PGPlayerControl__
#define __PuzzleGame__PGPlayerControl__

#include "cocos2d.h"
#include "PGPlayer.h"
#include "PGGameControl.h"
#include "BasicPhysics.h"

using namespace cocos2d;

class PGPlayerControl : public CCLayer{
public:
    static CCScene* scene();
    virtual bool init();
    
    void playerMoveLeft();
    void playerMoveRight();
    void playerJumping();
    
    CREATE_FUNC(PGPlayerControl);
private:
    CCSize size;
};

#endif /* defined(__PuzzleGame__PGPlayerControl__) */
