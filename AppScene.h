#ifndef __APP_SCENE_H__
#define __APP_SCENE_H__

#include "AppSceneDefine.h"

class CAppScene : public cocos2d::LayerColor
{
public:
	// 显示指定场景
	static void show(SceneName name);
    
    // 获得显示大小
	static cocos2d::Size getShowSize();
    
    // 获得逻辑大小
	static cocos2d::Size getLogicSize();
    
    // 配置逻辑位置
    static void setup(cocos2d::Node *pLogic, LogicPos value);
    
protected:
    // 静态方法创建节点
	CREATE_FUNC(CAppScene);
    
	// 初始化过渡场景层
	virtual bool init();
    
	// 已经进入过渡场景
	virtual void onEnterTransitionDidFinish();
    
	// 更新切换指定场景
	virtual void update(float delta);
    
	// 已经退出过渡场景
	virtual void onExit();
    
};

#endif  // __APP_SCENE_H__
