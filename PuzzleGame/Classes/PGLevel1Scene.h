//
//  PGLevel1Scene.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-12.
//
//

#ifndef __PuzzleGame__PGLevel1Scene__
#define __PuzzleGame__PGLevel1Scene__

#include "cocos2d.h"
#include "PGBox.h"
using namespace cocos2d;

class PGLevel1Scene : public CCLayer{
public:
    static CCScene* scene();
    virtual bool init();
    CREATE_FUNC(PGLevel1Scene);
private:
    //添加背景(背景和地面)
    void addGameBackground(CCLayer* layer,CCPoint pos);
};

#endif /* defined(__PuzzleGame__PGLevel1Scene__) */
