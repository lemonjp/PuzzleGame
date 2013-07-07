//
//  MeneButtons.h
//  PuzzleGame
//
//  Created by 何遵祖 on 13-7-7.
//
//

#ifndef __PuzzleGame__MeneButtons__
#define __PuzzleGame__MeneButtons__

#include "cocos2d.h"

typedef enum ButtonType{
    b_jump = 0,
    b_pause = 1,
    b_left = 2,
    b_right = 3,
    b_restart = 4,
}ButtonType;

using namespace cocos2d;

class MenuButtonPlugin : CCObject {
public:
    MenuButtonPlugin();
    virtual ~MenuButtonPlugin();

    //void addPluginButtonToScreen(ButtonType *type,CCPoint position,int tag);

};

#endif /* defined(__PuzzleGame__MeneButtons__) */
