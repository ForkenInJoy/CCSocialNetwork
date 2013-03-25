// Includes
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
// iOS Includes
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "ObjCCalls/ObjCCalls.h"
#endif
// Android Includes
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JNICalls/InterfaceJNI.h"
#endif


using namespace cocos2d;
//using namespace CocosDenshion;

static HelloWorld * mytry = NULL;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);


    // return the scene
    return scene;
}

HelloWorld* HelloWorld::get_instance()
{
    return mytry;
}
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	// Static reference
    mytry = this;

    // Init
    if ( !CCLayer::init() )
    {
        return false;
    }
    // Menu
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // Menu
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);

    // Hello World
    InterfaceJNI::helloWorld();

    // Welcome
    CCLabelTTF* pLabel = CCLabelTTF::create("CCSocialNetwork", "Thonburi", 34);
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    pLabel->setPosition( ccp(size.width / 2, size.height - 20) );
    this->addChild(pLabel, 1);

    // Static Label Score
    CCLabelTTF* scLabel = CCLabelTTF::create("Your Score:", "Thonburi", 34);
    scLabel->setPosition( ccp(10 + scLabel->getContentSize().width/2, size.height - 20) );
    this->addChild(scLabel, 1);

    // Simulate var Score
    sLabel = CCLabelTTF::create("123", "Thonburi", 34);
    sLabel->setPosition( ccp(10 + scLabel->getContentSize().width/2, size.height - 60) );
    this->addChild(sLabel, 1);

    // Internet Label
	CCLabelTTF* internetLabel = CCLabelTTF::create("Internet Connection:", "Thonburi", 20);
	CCLabelTTF* internetValueLabel = CCLabelTTF::create("Value", "Thonburi", 20);
	internetLabel->setPosition( ccp(10 + internetLabel->getContentSize().width/2, size.height - 90) );
	internetValueLabel->setPosition( ccp(10 + internetValueLabel->getContentSize().width/2, size.height - 120) );
	this->addChild(internetLabel, 1);
	this->addChild(internetValueLabel, 1);

	// Check Internet
	CCLog("Go to check Internet connection...");
	bool internet = this->tryIsInternetConnection();
	CCLog("Internet connection value: %d", internet);

    mLabel = CCLabelTTF::create("", "Thonburi", 20);
    mLabel->setPosition(ccp(size.width/2, 20));
    this->addChild(mLabel);


    //Main Menu With Font
    CCLabelTTF *sendMailButtonLabel = CCLabelTTF::create("Send an email", "Thonburi", 24);
	CCMenuItemLabel *sendMailButton = CCMenuItemLabel::create(sendMailButtonLabel, this, menu_selector(HelloWorld::trySendAnEmail));

    CCLabelTTF *sendTweetButtonLabel = CCLabelTTF::create("Send a tweet", "Thonburi", 24);
	CCMenuItemLabel *sendTweetButton = CCMenuItemLabel::create(sendTweetButtonLabel, this, menu_selector(HelloWorld::trySendATweet));

    CCLabelTTF *postOnFBButtonLabel = CCLabelTTF::create("Post on FB", "Thonburi", 24);
	CCMenuItemLabel *postOnFBButton = CCMenuItemLabel::create(postOnFBButtonLabel, this, menu_selector(HelloWorld::tryPostOnFB));

	CCMenu *mainMenu = CCMenu::create(sendMailButton, sendTweetButton, postOnFBButton, NULL);

	mainMenu->alignItemsVerticallyWithPadding(size.height * 0.06f);
	mainMenu->setPosition(ccp(size.width/2, size.height/2));

    this->addChild(mainMenu, 1);

    return true;
}

void HelloWorld::trySendAnEmail(CCObject* pSender)
{
	CCLog("HelloWorld: try to send an email");

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	InterfaceJNI::postMessageEMail();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	ObjCCalls::trySendAnEMail();
#endif
}

void HelloWorld::trySendATweet(CCObject* pSender)
{
	CCLog("HelloWorld: try to send a tweet");

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	InterfaceJNI::postMessageToTweet();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	ObjCCalls::trySendATweet();
#endif
}

bool HelloWorld::tryIsInternetConnection()
{
	CCLog("HelloWorld: tryIsInternetConnection");

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	return InterfaceJNI::isInternetConnected();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	//ObjCCalls::trySendATweet();
#endif
}

void HelloWorld::tweetCallback(int statusCode)
{
    switch (statusCode) {
        case -1:
            updateMessageLabel("Oops. Something went wrong.");
            break;
        case 0:
            updateMessageLabel("Tweet cancelled by the user.");
            break;
        case 1:
            updateMessageLabel("Tweet sent.");
            break;
        default:
            updateMessageLabel("Something wrong with the status code?");
            break;
    }
}

void HelloWorld::tryPostOnFB(CCObject* pSender){
    CCLog("HelloWorld: try to post on Facebook");
    int score = atoi (sLabel->getString());
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    InterfaceJNI::postMessageToFB();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    ObjCCalls::tryPostOnFB(score);
#endif

}

void HelloWorld::updateMessageLabel(const char *text)
{
    CCLog(text);
    mLabel->setString(text);
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::testCallFromJava()
{
    CCLog("testCallFromJava");
}
void HelloWorld::testCallToJava()
{
	CCLog("testCallToJava");
}

