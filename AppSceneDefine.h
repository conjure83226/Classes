#ifndef __APP_SCENE_DEFINE_H__
#define __APP_SCENE_DEFINE_H__

#include "cocos2d.h"

#define SIDE_SHORT 540 // 短边长度
#define SIDE_LONG 960 // 长边长度

typedef enum SceneName
{// 自定义场景名称
	SCENE_LAST = -1,
	SCENE_MIN,
	SCENE_LOGO,
	SCENE_MAX,
}SceneName;

typedef enum LogicPos
{// 自定义逻辑位置
	LOGIC_DEFAULT = 0,
	LOGIC_CENTER,
	LOGIC_OTHER,
}PosShow;

class CAppSceneDefine
{
public:
	// 获得过渡场景(设置进入过渡场景时的效果)
	static cocos2d::Scene* getTransition(cocos2d::Scene *pScene, SceneName nextScene, SceneName lastScene);
    
	// 绘制过渡场景(设置过渡场景的显示)
	static bool drawTransition(cocos2d::LayerColor *pRoot, SceneName nextScene);
    
	// 更新场景
	static void update(SceneName updateScene, bool isShow);
    
};

#endif  // __APP_SCENE_DEFINE_H__
