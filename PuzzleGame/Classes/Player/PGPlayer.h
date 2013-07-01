//
//  PGPlayer.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-6-30.
//
//

#ifndef __PuzzleGame__PGPlayer__
#define __PuzzleGame__PGPlayer__

#include "cocos2d.h"
#include "PlistLoader.h"

using namespace cocos2d;

class PGPlayer : CCObject{
public:
    PGPlayer();
    virtual ~PGPlayer();
    
    /*产生玩家单例*/
    static PGPlayer* sharedPlayer();
    /*产生玩家对象*/
    void createPlayer(CCLayer* layer);
    /*删除游戏玩家*/
    void deletePlayer(CCLayer* layer);
private:
    PlistLoader *plist;
    
    CCArray *moveAnim;
    CCArray *jumpAnim;
    
    void initWithMoveAnimation();
    void initWithJumpAnimation();
};

#endif /* defined(__PuzzleGame__PGPlayer__) */
