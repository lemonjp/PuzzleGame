//
//  PGBox.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-11.
//
//

#ifndef __PuzzleGame__PGBox__
#define __PuzzleGame__PGBox__

#include "cocos2d.h"
#include "PhysicsSprite.h"
#include "BasicPhysics.h"

using namespace cocos2d;

class PGBox : CCObject{
public:
    void addBoxToScreen(CCLayer* layer,CCPoint position);
private:
    CC_SYNTHESIZE(SpriteBody*,boxBody,BoxBody);
};

#endif /* defined(__PuzzleGame__PGBox__) */
