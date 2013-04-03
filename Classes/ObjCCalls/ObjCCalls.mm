#include "ObjCCalls.h" 
#import "../cocos2dx/platform/ios/EAGLView.h" 
#import "TweetSender.h"
#import "Facebook.h"
#import "MailSender.h"
#import "Reachability.h"

void ObjCCalls::trySendATweet(const char *score)
{
    [TweetSender trySendATweet:score];
}

void ObjCCalls::trySendAnEMail(const char *score, bool usingInternalApp)
{
    MailSender *mailSender = [MailSender alloc];
    if (usingInternalApp) {
        [mailSender sendMailUsingInAppMailer:score];
    }
    else{
        [mailSender sendMailUsingExternalApp:score];
    }
}

void ObjCCalls::tryPostOnFB(const char *score)
{
    [Facebook tryToPostOnFacebook:score];
}

bool ObjCCalls::tryIsInternetConnection()
{
    Reachability *networkReachability = [Reachability reachabilityForInternetConnection];
    NetworkStatus networkStatus = [networkReachability currentReachabilityStatus];
    return !(networkStatus == NotReachable);
}
