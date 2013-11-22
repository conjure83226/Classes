#include "AppScene.h"

USING_NS_CC;

static Size g_tShow = Size();               // 显示大小
static Point g_tPos = Point();              // 显示位置
static Size g_tLogic = Size();              // 逻辑大小
static SceneName g_iNextScene = SCENE_MIN;	// 下个场景
static SceneName g_iLastScene = SCENE_MIN;  // 上个场景

// 显示指定场景
void CAppScene::show(SceneName name)
{
	if (SCENE_LAST == name)
	{// 返回上个场景
		name = g_iLastScene;
	}
	if (name != g_iNextScene && name > SCENE_MIN && name < SCENE_MAX)
	{// 开始改变场景
		Director *pDirector = Director::getInstance();
		bool isRunScene = SCENE_MIN >= g_iNextScene;
		g_iLastScene = g_iNextScene;
		g_iNextScene = name;
		if (isRunScene)
		{// 首次进入场景，设置窗口大小
            g_tShow = pDirector->getWinSizeInPixels();
			if(g_tShow.height > g_tShow.width)
			{// 是竖屏幕显示
				float side = g_tShow.width / g_tShow.height * SIDE_LONG;
                g_tPos.x = (side - SIDE_SHORT) * 0.5f;
                g_tLogic.height = SIDE_LONG;
                g_tLogic.width = SIDE_SHORT;
				g_tShow.height = SIDE_LONG;
				g_tShow.width = side;
			}
			else
			{// 是横屏幕显示
				float side = g_tShow.height / g_tShow.width * SIDE_LONG;
                g_tPos.y = (side - SIDE_SHORT) * 0.5f;
                g_tLogic.height = SIDE_SHORT;
                g_tLogic.width = SIDE_LONG;
				g_tShow.width = SIDE_LONG;
                g_tShow.height = side;
			}
            ScriptEngineManager::getInstance()->setScriptEngine(LuaEngine::getInstance());// 设置脚本引擎
			pDirector->getOpenGLView()->setDesignResolutionSize(g_tShow.width, g_tShow.height, ResolutionPolicy::SHOW_ALL);
		}
		Scene *pScene = Scene::create();
		pScene->addChild(CAppScene::create());
		isRunScene ? pDirector->runWithScene(pScene) : pDirector->replaceScene(CAppSceneDefine::getTransition(pScene, g_iNextScene, g_iLastScene));
	}
	else
	{// 没有改变场景
		log("CAppScene::show(%i)------------>>Failed!", name);
	}
}

// 获得显示大小
Size CAppScene::getShowSize()
{
	return g_tShow;
}

// 获得逻辑大小
Size CAppScene::getLogicSize()
{
    return g_tLogic;
}

// 配置逻辑位置
void CAppScene::setup(Node *pLogic, LogicPos value)
{
    if (LOGIC_CENTER == value)
    {
        pLogic->setPosition(g_tPos);
    }
    else if (LOGIC_OTHER == value)
    {
        pLogic->setPosition(g_tPos * 2);
    }
    else
    {
        pLogic->setPosition(Point());
    }
}

// 初始化过渡场景层
bool CAppScene::init()
{
    LayerColor::init();
	return CAppSceneDefine::drawTransition(this, g_iNextScene);
}

// 已经进入过渡场景
void CAppScene::onEnterTransitionDidFinish()
{
	LayerColor::onEnterTransitionDidFinish();
	this->scheduleUpdate();
}

// 更新切换指定场景
void CAppScene::update(float delta)
{
	LayerColor::update(delta);
    this->unscheduleUpdate();
	CAppSceneDefine::update(g_iNextScene, true);
}

// 已经退出过渡场景
void CAppScene::onExit()
{
	LayerColor::onExit();
    CAppSceneDefine::update(g_iLastScene, false);
    Director::getInstance()->getTextureCache()->dumpCachedTextureInfo();
}
