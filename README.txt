----------------------------------------
GET SOCIAL
----------------------------------------
License LGPL, read LICENSE.txt. 
You can share this code, and use it with out warranty.

----- NO ESTABLE - NO WORKING (YET)



Project in cocos2d-2.1rc0-x-2.1.2 for android and iOS.

Example using Facebook, twitter, sending e-mails and gree.

iOS Status
-----------------------
[ ] - Facebook; 
[ ] - Twitter; 
[ ] - E-Mail; 
[  ] - Check internet connection;

ANDROID Status
------------------------

[ ] - Facebook Android SDK 3.0.1 as of March 20, 2013 ;
[ ] - Twitter; 
[ ] - E-Mail; 
[ ] - Check internet connection;

iOS Instructions
-----------------------


ANDROID Instructions
------------------------
1º Configure "MY CONFIG" in build_native.sh with your data
2º Execute "./build_native.sh"
3º Import into Eclipse cocos2d-x Library:
	3.1 File > Import > Android > Existing.. 
	3.2 Select $COCOS2d-2.1-rc0-x-2.1.2>cocos2dx/platform/android/java [A project named "java" will be see in workspace]
	3.3 Ok
4º Import into Eclipse project:
	4.1 File > Import > Android > Existing.. 
	4.2 Select the MAIN folder where you did clone
	4.3 Finish
5º Add library to SOCIAL PROJECT
	5.1 Go to Properties
	5.2 Add Library
	5.3 Select libcocos2dx

If you have problems, try to launch a hello world!
https://github.com/cocos2d/cocos2d-x/blob/master/samples/Cpp/HelloCpp/proj.android/README.md

STEPS CREATING THIS PROJECT
----------------------------------



Based on:
- Barti Sid example: http://lipekdev.wordpress.com/2012/09/19/integrating-facebook-twitter-open-feint-other-with-cocos2d-x-in-android-project/

Authors 2013
- Meizaguirre
- Piperoman

