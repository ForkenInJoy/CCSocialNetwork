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
import android.os.Bundle;
import android.util.Log;

public class CCSocialNetwork extends Cocos2dxActivity
{
	static boolean m_isInit = false;
	private static final String TAG = "CCSocialNetwork";
	static public InternetConnection m_InternetConnection;
	
	//////////////////////////////////////////////////////////////
	// 					Lifecicle								//
	//////////////////////////////////////////////////////////////
    protected void onCreate(Bundle savedInstanceState)
    {
		super.onCreate(savedInstanceState);	
		if(!m_isInit)
		{
			Log.v(TAG, "Java Initializing CCSocialNetwork");
			m_isInit = true;
			m_InternetConnection = new InternetConnection();
			m_InternetConnection.isInternetConnection(getContext());
			Log.v(TAG, "Java Initializing CCSocialNetwork finished!");
		}
	}
	//////////////////////////////////////////////////////////////
	// 					Interface  								//
	//////////////////////////////////////////////////////////////
    static public boolean isInternetConnection()
    {
    	return m_InternetConnection.isInternetConnection(getContext());
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
