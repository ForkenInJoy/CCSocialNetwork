/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.example.SocialNetwork;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.content.Context;
import android.content.Intent;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.widget.Toast;

public class CCSocialNetwork extends Cocos2dxActivity
{
	private static final String TAG = "CCSocialNetwork";
	static Context myAndroidContext;
	
	//////////////////////////////////////////////////////////////
	// 					Lifecicle								//
	//////////////////////////////////////////////////////////////
    protected void onCreate(Bundle savedInstanceState)
    {
		super.onCreate(savedInstanceState);	
		myAndroidContext = getApplicationContext();

	}
	//////////////////////////////////////////////////////////////
	// 					Interface  								//
	//////////////////////////////////////////////////////////////
    static public boolean isInternetConnection()
    {
    	Log.v("InternetConnection", "isInternetConnection Start");
    	/*
    	 // Toast make fail DEMO ! :S
		Toast toast1 =	Toast.makeText(myAndroidContext,
										"Checking Internet", Toast.LENGTH_SHORT);
	        toast1.show();
		*/
		ConnectivityManager conMgr =  (ConnectivityManager)myAndroidContext.getSystemService(Context.CONNECTIVITY_SERVICE);
		NetworkInfo i = conMgr.getActiveNetworkInfo();
		
		if (i == null)
		{
			Log.v("InternetConnection", "isInternetConnection NULL :S");
			return false;
		}
			
		if (!i.isConnected())
		{
			Log.v("InternetConnection", "isInternetConnection is not connected");
			return false;
		}
			
		if (!i.isAvailable())
		{
			Log.v("InternetConnection", "isInternetConnection is not available");
			return false;
		}
		Log.v("InternetConnection", "isInternetConnection DONE!");

		return true;   	
    }
/*
    protected void onActivityResult(int requestCode, int resultCode, Intent data) 
    {
		this.facebookConnector.getFacebook().authorizeCallback(requestCode, resultCode, data);
	}
    
    public void updateLoginStatus() {
		loginStatus.setText("Logged into Twitter : " + facebookConnector.getFacebook().isSessionValid());
	}
	

	private static String getFacebookMsg() 
	{
		return MSG + " at " + new Date().toLocaleString();
	}	
	
	static public void postMessage() 
	{
		Log.d("activity", "postMessage (FB) on Java");
		if (facebookConnector.getFacebook().isSessionValid()) 
		{
			postMessageInThread();
		} 
		else 
		{
			SessionEvents.AuthListener listener = new SessionEvents.AuthListener() 
			{
				
				public void onAuthSucceed() 
				{
					postMessageInThread();
				}
				
				public void onAuthFail(String error) 
				{
					
				}
			};
			SessionEvents.addAuthListener(listener);
			facebookConnector.login();
		}
	}

	private static void postMessageInThread() 
	{
		Thread t = new Thread() {
			public void run() {
		    	
		    	try {
		    		facebookConnector.postMessageOnWall(getFacebookMsg());
					mFacebookHandler.post(mUpdateFacebookNotification);
				} catch (Exception ex) {
					Log.e(TAG, "Error sending msg",ex);
				}
		    }
		};
		t.start();
	}

	private void clearCredentials() 
	{
		try 
		{
			facebookConnector.getFacebook().logout(getApplicationContext());
		} 
		catch (MalformedURLException e) 
		{
			e.printStackTrace();
		} 
		catch (IOException e) 
		{
			e.printStackTrace();
		}
	}
	*/
	private static void sendATweet()
	{
		Log.d("activity", "Tweet on Java EDITABLE (Bad way, better use a library; Current version use web navigator)");
		String score = "123";
		String tweetUrl = "https://twitter.com/intent/tweet?text=Hello ! I have just got " + score + " points in mygame for Android !!!!";
		Uri uri = Uri.parse(tweetUrl);
		Intent i = new Intent(Intent.ACTION_VIEW, uri);
        i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        myAndroidContext.startActivity(i);
	}
	private static void sendEMail()
	{
		Log.d("activity", "Send a email on Java");
		Intent i = new Intent(Intent.ACTION_SEND);
		//i.setType("text/plain"); //use this line for testing in the emulator
		i.setType("message/rfc822") ; // use from live device
		i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
		i.putExtra(Intent.EXTRA_EMAIL, new String[]{"mrpiperoman@hotmail.com"/*"test@gmail.com"*/});
		i.putExtra(Intent.EXTRA_SUBJECT,"Subject goes here");
		i.putExtra(Intent.EXTRA_TEXT,"Test body goes here");
		myAndroidContext.startActivity(i);
	}
	//////////////////////////////////////////////////////////////
	// 					OpenGL   								//
	//////////////////////////////////////////////////////////////
    public Cocos2dxGLSurfaceView onCreateView() 
    {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// CCSocialNetwork should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	
    	return glSurfaceView;
    }

	//////////////////////////////////////////////////////////////
	// 					Libraries								//
	//////////////////////////////////////////////////////////////
    static 
    {
        System.loadLibrary("cocos2dcpp");
    }     
}
