#include "InterfaceJNI.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>

using namespace cocos2d;

void InterfaceJNI::helloWorld()
{
	// Java variables
	JavaVM* jvm = JniHelper::getJavaVM();
	int status;
	JNIEnv *env;
	jmethodID mid;
	bool isAttached = false;


	// Return
	bool returnValue = false;

	CCLog("Static helloWorld");

	// Get Status
	status = jvm->GetEnv((void **) &env, JNI_VERSION_1_6);


	if(status < 0)
	{
		//LOGE("callback_handler: failed to get JNI environment, " // "assuming native thread");
		status = jvm->AttachCurrentThread(&env, NULL);
		CCLog("helloWorld Status 2: %d", status);
		if(status < 0)
		{
			// LOGE("callback_handler: failed to attach " // "current thread");
			return;
		}
		isAttached = true;
		//CCLog("helloWorld Status isAttached: %d", isAttached);
	}
	//-----------------------------------------------------------

	CCLog("helloWorld Status: %d", status);

	// Get the class
	jclass mClass = env->FindClass("org/example/SocialNetwork/InternetConnection");

	// Get a STATIC Method; void helloWorld(void)
	mid = env->GetStaticMethodID(mClass, "helloWorld", "()V");
	if (mid == 0)
	{
		CCLog("helloWorld FAIL GET METHOD STATIC");
		return;
	}
	// Call to class
	env->CallStaticVoidMethod(mClass, mid);

	CCLog("helloWorld Done ");

	// Detach
	if(isAttached)
		jvm->DetachCurrentThread();

}

/**
 * MAKING
 */
void InterfaceJNI::postMessageToFB()
{
	JavaVM* jvm = JniHelper::getJavaVM();
	int status;
	JNIEnv *env;
	jmethodID mid;

	bool isAttached = false;

	CCLog("Static postMessageToFB");

	// Get Status
	status = jvm->GetEnv((void **) &env, JNI_VERSION_1_6);

	if(status < 0)
	{
		//LOGE("callback_handler: failed to get JNI environment, " // "assuming native thread");
		status = jvm->AttachCurrentThread(&env, NULL);
		CCLog("Status 2: %d", status);
		if(status < 0)
		{
			// LOGE("callback_handler: failed to attach " // "current thread");
			return;
		}
		isAttached = true;
		CCLog("Status isAttached: %d", isAttached);
	}
	//-----------------------------------------------------------

	CCLog("Status: %d", status);

	jclass mClass = env->FindClass("tutorial/getsocial/meizpipero/GetSocial");

	CCLog("jClass Located?");

	mid = env->GetStaticMethodID(mClass, "postMessage", "()V");

	CCLog("mID: %d", mid);

	if (mid!=0)
		env->CallStaticVoidMethod(mClass, mid);
			//-----------------------------------------------------------
	CCLog("Finish");
	if(isAttached)
		jvm->DetachCurrentThread();

	return;
}
/**
 * MAKING
 */
void InterfaceJNI::postMessageToTweet()
{
	JavaVM* jvm = JniHelper::getJavaVM();
	int status;
	JNIEnv *env;
	jmethodID mid;

	bool isAttached = false;

	CCLog("Static postMessageToTweet");

	// Get Status
	status = jvm->GetEnv((void **) &env, JNI_VERSION_1_6);



	if(status < 0)
	{
		//LOGE("callback_handler: failed to get JNI environment, " // "assuming native thread");
		status = jvm->AttachCurrentThread(&env, NULL);
		CCLog("Status 2: %d", status);
		if(status < 0)
		{
			// LOGE("callback_handler: failed to attach " // "current thread");
			return;
		}
		isAttached = true;
		CCLog("Status isAttached: %d", isAttached);
	}
	//-----------------------------------------------------------

	CCLog("Status: %d", status);

	jclass mClass = env->FindClass("tutorial/getsocial/meizpipero/GetSocial");

	CCLog("jClass ");

	mid = env->GetStaticMethodID(mClass, "tweet", "()V");

	CCLog("mID: %d", mid);

	if (mid!=0)
		env->CallStaticVoidMethod(mClass, mid);
			//-----------------------------------------------------------
	CCLog("Finish");
	if(isAttached)
		jvm->DetachCurrentThread();

	return;
}
/**
 * MAKIING
 */
void InterfaceJNI::postMessageEMail()
{
	JavaVM* jvm = JniHelper::getJavaVM();
	int status;
	JNIEnv *env;
	jmethodID mid;

	bool isAttached = false;

	CCLog("Static postMessageEMail");

	// Get Status
	status = jvm->GetEnv((void **) &env, JNI_VERSION_1_6);



	if(status < 0)
	{
		//LOGE("callback_handler: failed to get JNI environment, " // "assuming native thread");
		status = jvm->AttachCurrentThread(&env, NULL);
		CCLog("Status 2: %d", status);
		if(status < 0)
		{
			// LOGE("callback_handler: failed to attach " // "current thread");
			return;
		}
		isAttached = true;
		CCLog("Status isAttached: %d", isAttached);
	}
	//-----------------------------------------------------------

	CCLog("Status: %d", status);

	jclass mClass = env->FindClass("tutorial/getsocial/meizpipero/GetSocial");

	CCLog("jClass Located?");

	mid = env->GetStaticMethodID(mClass, "sendEMail", "()V");

	CCLog("mID: %d", mid);

	if (mid!=0)
		env->CallStaticVoidMethod(mClass, mid);
			//-----------------------------------------------------------
	CCLog("Finish");
	if(isAttached)
		jvm->DetachCurrentThread();

	return;
}
/**
 * Check if Internet Connection is ONLINE
 */
bool InterfaceJNI::isInternetConnected()
{
	JavaVM* jvm = JniHelper::getJavaVM();
	int status;
	JNIEnv *env;
	jmethodID mid;

	bool isAttached = false;
	// jboolean o bool?
	bool returnValue = false;

	CCLog("Static isInternetConnected");

	// Get Status
	status = jvm->GetEnv((void **) &env, JNI_VERSION_1_6);

	if(status < 0)
	{
		//LOGE("callback_handler: failed to get JNI environment, " // "assuming native thread");
		status = jvm->AttachCurrentThread(&env, NULL);
		CCLog("isInternetConnected Status 2: %d", status);
		if(status < 0)
		{
			// LOGE("callback_handler: failed to attach " // "current thread");
			return false;
		}
		isAttached = true;
		CCLog("isInternetConnected Status isAttached: %d", isAttached);
	}


	CCLog("isInternetConnected Status: %d", status);

	jclass mClass = env->FindClass("org/example/SocialNetwork/InternetConnection");

	// Get Static bool isInternetConnection()
	mid = env->GetStaticMethodID(mClass, "isInternetConnection", "()Z");
	if (mid == 0)
	{
		CCLog("isInternetConnected FAIL GET METHOD STATIC");
		return false;
	}
	// Call Static bool isInternetConnection()
	returnValue = env->CallStaticBooleanMethod(mClass, mid);
	CCLog("isInternetConnected Done ");

			//-----------------------------------------------------------
	CCLog("Finish");
	if(isAttached)
		jvm->DetachCurrentThread();

	// Change for return value
	return returnValue;
}
