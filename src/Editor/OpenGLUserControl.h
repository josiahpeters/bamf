#pragma once

// Exclude rarely used parts of the windows headers
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
//#include <IL/ilut.h>

#define UNREF(x) x;
//typedef unsigned int uint;
typedef unsigned char uchar;
// To use these, we must add some references...
//	o PresentationFramework (for HwndHost)
//		* PresentationCore
//		* WindowsBase
using namespace System;
using namespace System::Windows;
using namespace System::Windows::Interop;
using namespace System::Windows::Input;
using namespace System::Windows::Media;
using namespace System::Windows::Forms; // We derive from UserControl this time, so this ref is necessary
using namespace System::Runtime::InteropServices;

namespace Editor 
{
	public ref class OpenGLUserControl : public UserControl
	{
	private:
		HDC						m_hDC;
		HWND					m_hWnd;
		HGLRC					m_hRC;

		System::ComponentModel::Container^ components;
	
	public:

		bool GlInitialized;

		virtual ~OpenGLUserControl()
		{
			if(NULL != m_hRC)
			{
				wglDeleteContext(m_hRC);
				m_hRC = NULL;
			}

			if(NULL != m_hWnd && NULL != m_hDC)
			{
				ReleaseDC(m_hWnd, m_hDC);
				m_hDC = NULL;
			}

			// Don't destroy the HWND... we didn't allocate it!

			if (components) 
			{
				delete components;
			}
		}

		OpenGLUserControl() : components(nullptr),
			m_hDC(NULL),
			m_hWnd(NULL),
			m_hRC(NULL),
			GlInitialized(false)
		{
			
			InitializeComponent();
			this->components = gcnew System::ComponentModel::Container();

			//Attach load and size change event handlers
			this->Load += gcnew System::EventHandler(this, &OpenGLUserControl::InitializeOpenGL);
			this->SizeChanged += gcnew EventHandler(this, &OpenGLUserControl::ResizeOpenGL);
		}
		void InitGlSettings()
		{
			glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
			glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
			glClearDepth(1.0f);									// Depth Buffer Setup
			glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
			glDepthFunc(GL_LEQUAL);		
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
		}
		void Draw()
		{
			glClearColor(0.39f, 0.58f, 0.92f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();
		}
		void Swap()
		{
			SwapBuffers(m_hDC);			
		}

	protected:
		void InitializeComponent()
		{
			this->Name = "OpenGLUserControl";
		}

		virtual void OnPaintBackground( PaintEventArgs^ e ) override
		{ 
			UNREF(e);
			// not doing anything here avoids flicker
		}

		virtual void OnPaint( System::Windows::Forms::PaintEventArgs^ e ) override
		{
			Draw();
			Swap();
		}	

		/// <summary>
		///	Event handler called when the form is loaded.  It retrieves the controls
		///	window handle and device context and creates the rendering context.
		/// </summary>
		virtual void InitializeOpenGL( Object^ sender, EventArgs^ e)
		{
			UNREF(e);
			UNREF(sender);

			// Get the HWND from the base object
			m_hWnd	= (HWND) this->Handle.ToPointer();

			if(m_hWnd)
			{
				m_hDC = GetDC(m_hWnd);
				if(!m_hDC)
				{
					//Helper::ErrorExit(L"BuildWindowCore");
				}

				//
				// Create PixelFormatDescriptor and choose pixel format
				//
				uint PixelFormat;

				BYTE iAlphaBits = 0;
				BYTE iColorBits = 32;
				BYTE iDepthBits = 16;
				BYTE iAccumBits = 0;
				BYTE iStencilBits = 0;

				static PIXELFORMATDESCRIPTOR pfd = 
				{
					sizeof(PIXELFORMATDESCRIPTOR),	//size
					1,								//version
					PFD_DRAW_TO_WINDOW|				//flags
					PFD_SUPPORT_OPENGL|
					PFD_DOUBLEBUFFER,
					PFD_TYPE_RGBA,					//pixeltype
					iColorBits,
					0, 0, 0, 0, 0, 0,				//color bits ignored
					iAlphaBits,						
					0,								//alpha shift ignored
					iAccumBits,						//accum. buffer
					0, 0, 0, 0,						//accum bits ignored
					iDepthBits,						//depth buffer
					iStencilBits,					//stencil buffer
					0,								//aux buffer
					PFD_MAIN_PLANE,					//layer type
					0,								//reserved
					0, 0, 0							//masks ignored
				};
				
				PixelFormat = ChoosePixelFormat(m_hDC, &pfd);
				if(!PixelFormat)
				{
					//Helper::ErrorExit(L"BuildWindowCore");
				}

				if(!SetPixelFormat(m_hDC, PixelFormat, &pfd))
				{
					//Helper::ErrorExit(L"BuildWindowCore");
				}

				m_hRC = wglCreateContext(m_hDC);
				if(!m_hRC)
				{
					//Helper::ErrorExit(L"BuildWindowCore");
				}

				if(!wglMakeCurrent(m_hDC, m_hRC))
				{
					//Helper::ErrorExit(L"BuildWindowCore");
				}

				//
				// DPI scaling is performed automatically!
				// TODO: Check with non-XP-Style DPI scaling!

				//ShowWindow(m_hWnd, SW_SHOW);
				//SetFocus(m_hWnd);
				InitGlSettings();
				Resize();
				//ilInit();
				//ilutRenderer(ILUT_OPENGL);
				GLenum err = glewInit();
				if (GLEW_OK != err)
				{
					MessageBox::Show("GLEW Init Failure. \n" + gcnew String((char*)glewGetErrorString(err)));
					Application::Exit();
				}
				GlInitialized = true;
				return;
			}
		}

		void Resize()
		{
			wglMakeCurrent(m_hDC, m_hRC);

			GLfloat aspectRatio = (float)Width/Height;

			// Use the Projection Matrix
			glMatrixMode(GL_PROJECTION);
			glViewport(0, 0, Width, Height);
			glLoadIdentity();

			// perspective variables
			GLfloat nearPlane = 0.05f;
			GLfloat farPlane = 1000.0f;
			GLfloat fieldOfViewAngle = 60.0f;
			// set perspective
			gluPerspective(fieldOfViewAngle, aspectRatio, nearPlane, farPlane);

			// set model view matrix
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			/*glViewport( 0, 0, Width, Height );

			glMatrixMode ( GL_PROJECTION );
			glLoadIdentity();
			// gluPerspective( 67.5,((double)(Width) / (double)(Height)), 1.0, 500.0);
			glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);
			glMatrixMode ( GL_MODELVIEW );
			glLoadIdentity();*/
		}

		/// <summary>
		/// Event handler called when the control is resized.
		/// </summary>
		void ResizeOpenGL(Object^ sender, EventArgs^ e)
		{
			UNREF(e);
			UNREF(sender);			

			if(m_hDC == NULL || m_hRC == NULL)
				return;

			if(Width == 0 || Height == 0)
				return;

			Resize();
			
		}
	};
};
