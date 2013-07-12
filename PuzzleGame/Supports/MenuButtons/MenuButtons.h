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
#include "PlistLoader.h"

typedef enum ButtonType{
    b_jump = 0,
    b_pause = 2,
    b_left = 4,
    b_right = 6,
    b_restart = 8,
}ButtonType;

using namespace cocos2d;

class MenuButtonPlugin : public CCSprite , public CCTouchDelegate{
public:
    MenuButtonPlugin();
    virtual ~MenuButtonPlugin();

    //添加不同类型的按钮到层中
    void addPluginButtonToScreen(ButtonType type,CCPoint position,CCLayer *layer , int tag);

    //触摸事件的侦听
    //添加和注销触摸侦听事件
    void onEnter();
    void onExit();
    //具体触摸事件
    virtual bool ccTouchBegan(CCTouch *ptouch,CCEvent *event);
    virtual void ccTouchEnded(CCTouch *ptouch,CCEvent *event);
    
private:
    PlistLoader *plist;
    CCTexture2D *texture;
};

#endif /* defined(__PuzzleGame__MeneButtons__) */
