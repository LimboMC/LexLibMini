#pragma once
//_______________________________
//Project : LEX_LIB
//Version : 0.0.0.1 Alpha
//Core : OpenGL 4.6
//------------------------------
// The engine was created by LimboMC and is based on the learn OpenGL project by VictorGordan.
// Original tutorials available at:
// https://github.com/VictorGordan/opengl-tutorials
// Lex_Engine is a graphics library created for learning purposes using OpenGL 4.6.
//------------------------------
#ifndef LEX_CORE_CLASS_FUNC_H
#define LEX_CORE_CLASS_FUNC_H
#include<glad/glad.h>
#include<glfw/glfw3.h>
#include<vec3.hpp>
#include<stb_image.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
#include<vector>
#if defined(_WIN32) || defined(_WIN64)
#if defined(__TINYC__)
    #define __declspec(x) __attribute__((x))
#endif
#if defined(BUILD_LEX)
#define LEX_API __declspec(dllexport)
#elif defined(USE_LEX)
#define LEX_API __declspec(dllimport)
#else 
#define LEX_API
#endif // defined(BUILD_LEX_SHARED)
#else
#if defined(BUILD_LEX_SHARED)
#define LEX_API __attribute__((visibility("default")))
#else
#define LEX_API
#endif // defined(BUILD_LEX_SHARED)
#endif // defined(_WIN32) || defined(_WIN64)
//Define Core 
// Matrix modes (equivalent to OpenGL)
#define LEX_MODELVIEW                            0x1700      // GL_MODELVIEW
#define LEX_PROJECTION                           0x1701      // GL_PROJECTION
#define LEX_TEXTURE                              0x1702      // GL_TEXTURE
// Primitive assembly draw modes
#define LEX_LINES                                0x0001      // GL_LINES
#define LEX_TRIANGLES                            0x0004      // GL_TRIANGLES
#define LEX_QUADS                                0x0007      // GL_QUADS
// GL equivalent data types
#define LEX_UNSIGNED_BYTE                        0x1401      // GL_UNSIGNED_BYTE
#define LEX_FLOAT                                0x1406      // GL_FLOAT
#define LEX_INT                                  0x1404      // GL_INT
#define LEX_SHORT                                0x1402      // GL_SHORT
#define LEX_DOUBLE                               0x140A      // GL_DOUBLE
#define LEX_BYTE                                 0x1400      // GL_BYTE
#define LEX_UNSIGNED_SHORT                       0x1403      // GL_UNSIGNED_SHORT
#define LEX_UNSIGNED_INT                         0x1405      // GL_UNSIGNED_INT
#define LEX_TRUE                                 1           // GL_TRUE
#define LEX_FALSE                                0           // GL_FALSE
#define LEX_UNSIGNED_INT                         0x1405      // GL_UNSIGNED_INT
// GL buffer usage hint
#define LEX_STREAM_DRAW                          0x88E0      // GL_STREAM_DRAW
#define LEX_STREAM_READ                          0x88E1      // GL_STREAM_READ
#define LEX_STREAM_COPY                          0x88E2      // GL_STREAM_COPY
#define LEX_STATIC_DRAW                          0x88E4      // GL_STATIC_DRAW
#define LEX_STATIC_READ                          0x88E5      // GL_STATIC_READ
#define LEX_STATIC_COPY                          0x88E6      // GL_STATIC_COPY
#define LEX_DYNAMIC_DRAW                         0x88E8      // GL_DYNAMIC_DRAW
#define LEX_DYNAMIC_READ                         0x88E9      // GL_DYNAMIC_READ
#define LEX_DYNAMIC_COPY                         0x88EA      // GL_DYNAMIC_COPY
// GL Shader type
#define LEX_FRAGMENT_SHADER                      0x8B30      // GL_FRAGMENT_SHADER
#define LEX_VERTEX_SHADER                        0x8B31      // GL_VERTEX_SHADER
#define LEX_COMPUTE_SHADER                       0x91B9      // GL_COMPUTE_SHADER
#define LEX_ARRAY_BUFFER                          0x8892
#define LEX_ELEMENT_ARRAY_BUFFER                  0x8893
//
#define LEX_UNBIND                                0x9999     // Unbind all buffers and arrays
#define LEX_COLOR_BUFFER_BIT                      0x00004000
#define LEX_DEPTH_BUFFER_BIT                      0x00000100
#define LEX_STENCIL_BUFFER_BIT                    0x00000400
#define LEX_COLOR_CUSTOM                          0x001234
// Window Modes
#define LEX_MAXIMIZED_WINDOW                      0x00020008 //GLFW_MAXIMIZED
#define LEX_MINIMIZED_WINDOW                      0x00020002 //GLFW_ICONIFIED
#define LEX_HIDE_WINDOW                           0x0002022A //-Lex-//
#define LEX_FLOAT_WINDOW                          0x00020007 //GLFW_FLOATING
#define LEX_RESIZABLE_WINDOW                      0x00020003 //GLFW_RESIZABLE
#define LEX_MOUSE_PASSTHROUGH_WINDOW              0x0002000D //GLFW_MOUSE_PASSTHROUGH
#define KEX_DECORATED_WINDOW                      0x00020005 //GLFW_DECORATED    
#define LEX_VISIBLE_WINDOW                        0x00020004 //GLFW_VISIBLE
#define LEX_FOCUSED_WINDOW                        0x00020001 //GLFW_FOCUSED
#define LEX_AUTO_ICONIFY_WINDOW                   0x00020006 //GLFW_AUTO_ICONIFY
#define LEX_TRANSPARENT_FRAMEBUFFER_WINDOW        0x0002000A //GLFW_TRANSPARENT_FRAMEBUFFER
#define LEX_FOCUS_ON_SHOW                         0x0002000C //GLFW_FOCUS_ON_SHOW   
#define LEX_SCALE_FRAMEBUFFER_WINDOW              0x0002200D //GLFW_SCALE_FRAMEBUFFER

//Bits 
#define LEX_RED_BITS                           0x00021001 //GLFW_RED_BITS
#define LEX_GREEN_BITS                         0x00021002 //GLFW_GREEN_BITS
#define LEX_BLUE_BITS                          0x00021003 //GLFW_BLUE_BITS
#define LEX_ALPHA_BITS                         0x00021004 //GLFW_ALPHA_BITS
#define LEX_ACCUM_RED_BITS                     0x00021007 //GLFW_ACCUM_RED_BITS
#define LEX_ACCUM_GREEN_BITS                   0x00021008 //GLFW_ACCUM_GREEN_BITS
#define LEX_ACCUM_BLUE_BITS                    0x00021009 //GLFW_ACCUM_BLUE_BITS
#define LEX_ACCUM_ALPHA_BITS                   0x0002100A //GLFW_ACCUM_ALPHA_BITS
#define LEX_DEPTH_BITS                         0x00021005 //GLFW_DEPTH_BITS
#define LEX_STENCIL_BITS                       0x00021006 //GLFW_STENCIL_BITS

#define LEX_RBGA_MAX_BITS                      0x00021012//Lex//
#define LEX_RBGA_NORMAL_BIT8                   0x00021013//Lex//
#define LEX_RBGA_NORMAL_BIT10                  0x00021014//Lex//
#define LEX_RBGA10_A2_BITS                     0x00021015//Lex//
#define LEX_RBGA16_BITS                        0x00021012//Lex//

#define LEX_CURSOR_NORMAL                     0x00034001
#define LEX_CURSOR_HIDDEN                     0x00034002 //GLFW_CURSOR_HIDDEN
#define LEX_CURSOR_DISABLED                   0x00034003 //GLFW_CURSOR_DISABLED
#define LEX_CURSOR_CAPTURED                   0x00034004 //GLFW_CURSOR_CAPTURED

#define LEX_TEXTURE_2D                        0x0DE1//GL_TEXTURE_2D

#define LEX_RED                               0x1903//GL_RED
#define LEX_GREEN                             0x1904//GL_GREEN
#define LEX_BLUE                              0x1905//GL_BLUE
#define LEX_ALPHA                             0x1906//GL_ALPHA
#define LEX_RGB                               0x1907//GL_RGB
#define LEX_RGBA                              0x1908//LEX_RGBA
//TypeDef
typedef GLsync LSync;
//Input
typedef enum {
	//Alphanumeric
	LKEY_0 = 48,                 //Key_0
	LKEY_1 = 49,                 //Key_1
	LKEY_2 = 50,                 //Key_2
	LKEY_3 = 51,                 //Key_3
	LKEY_4 = 52,                 //Key_4
	LKEY_5 = 53,                 //Key_5
	LKEY_6 = 54,                 //Key_6
	LKEY_7 = 55,                 //Key_7
	LKEY_8 = 56,                 //Key_8
	LKEY_9 = 57,                 //Key_9
	LKEY_A = 65,                 //Key_A
	LKEY_B = 66,                 //Key_B
	LKEY_C = 67,                 //Key_C
	LKEY_D = 68,                 //Key_D
	LKEY_E = 69,                 //Key_E
	LKEY_F = 70,                 //Key_F
	LKEY_G = 71,                 //Key_G
	LKEY_H = 72,                 //Key_H
	LKEY_I = 73,                 //Key_I
	LKEY_J = 74,                 //Key_J
	LKEY_K = 75,                 //Key_K
	LKEY_L = 76,                 //Key_L
	LKEY_M = 77,                 //Key_M
	LKEY_N = 78,                 //Key_N
	LKEY_O = 79,                 //Key_O
	LKEY_P = 80,                 //Key_P
	LKEY_Q = 81,                 //Key_Q
	LKEY_R = 82,                 //Key_R
	LKEY_S = 83,                 //Key_S
	LKEY_T = 84,                 //Key_T
	LKEY_V = 86,                 //Key_V
	LKEY_W = 87,                 //Key_W
	LKEY_X = 88,                 //Key_X
	LKEY_Y = 89,                //Key_Y
	LKEY_Z = 90,                //KeyZ
	LKEY_SPACE = 32,             //Key_Space
	LKEY_APOSTROPHE = 39,        //Key_'
	LKEY_COMMA = 44,             //Key_,
	LKEY_MINUS = 45,             //Key_-
	LKEY_PERIOD = 46,            //Key_.
	LKEY_SLASH = 47,             //Key_/
	LKEY_LEFT_BRACKET = 91,      //Key_[
	LKEY_BACKSLASH = 92,         /* Key_\ */
	LKEY_RIGHT_BRACKET = 93,     //Key_]
	LKEY_GRAVE_ACCENT = 96,      //Key_`
	LKEY_EQUAL = 61,             // =
	LKEY_WORLD_1 = 161,          /* non-US #1 */
	LKEY_WORLD_2 = 162,          /* non-US #2 */
	/* Modifier keys */
	LKEY_ESCAPE = 256,           //Key_ESC
	LKEY_ENTER = 257,            //Key_ENTER
	LKEY_TAB = 258,              //Key_TAB
	LKEY_BACKSPACE = 259,        //Key_BACKSPACE
	LKEY_INSERT = 260,           //Key_INSERT
	LKEY_DELETE = 261,           //Key_DELETE
	LKEY_RIGHT = 262,            //Key ->
	LKEY_LEFT = 263,             //Key <-
	LKEY_DOWN = 264,             //Key_Down
	LKEY_UP = 265,               //Key_Up
	LKEY_PAGE_UP = 266,          //Key_PG_UP
	LKEY_PAGE_DOWN = 267,        //Key_PG_DOWN
	LKEY_HOME = 268,             //Key_HOME
	LKEY_END = 269,              //Key_END
	LKEY_CAPS_LOCK = 280,        //Key_CAPS_LOCK
	LKEY_LEFT_SHIFT = 340,       //Key_LEFT_SHIFT
	LKEY_LEFT_CONTROL = 341,     //Key_LEFT_CONTROL
	LKEY_LEFT_ALT = 342,         //Key_LEFT_ALT
	LKEY_LEFT_SUPER = 343,       //Key_LEFT_SUPER
	LKEY_RIGHT_SHIFT = 344,      //Key_RIGHT_SHIFT
	LKEY_RIGHT_CONTROL = 345,    //Key_RIGHT_CONTROL
	LKEY_RIGHT_ALT = 346,        //Key_RIGHT_ALT
	LKEY_RIGHT_SUPER = 347,      //Key_RIGHT_SUPER
	LKEY_MENU = 348,             //Key_MENU
	//Function Key
	LKEY_F1 = 290,               //Key_F1
	LKEY_F2 = 291,               //Key_F2
	LKEY_F3 = 292,               //Key_F3
	LKEY_F4 = 293,               //Key_F4
	LKEY_F5 = 294,               //Key_F5
	LKEY_F6 = 295,               //Key_F6
	LKEY_F7 = 296,               //Key_F7
	LKEY_F8 = 297,               //Key_F8
	LKEY_F9 = 298,               //Key_F9
	LKEY_F10 = 299,              //Key_F10
	LKEY_F11 = 300,              //Key_F11
	LKEY_F12 = 301,              //Key_F12
	LKEY_F13 = 302,              //Key_F13
	LKEY_F14 = 303,              //Key_F14
	LKEY_F15 = 304,              //Key_F15
	LKEY_F16 = 305,              //Key_F16
	LKEY_F17 = 306,              //Key_F17
	LKEY_F18 = 307,              //Key_F18
	//KeyPad Key
	LKEY_KP_0 = 320,             //KeyPad_0
	LKEY_KP_1 = 321,             //KeyPad_1
	LKEY_KP_2 = 322,             //KeyPad_2
	LKEY_KP_3 = 323,             //KeyPad_3
	LKEY_KP_4 = 324,             //KeyPad_4
	LKEY_KP_5 = 325,             //KeyPad_5
	LKEY_KP_6 = 326,             //KeyPad_6
	LKEY_KP_7 = 327,             //KeyPad_7
	LKEY_KP_8 = 328,             //KeyPad_8
	LKEY_KP_9 = 329,             //KeyPad_9
	LKEY_KP_DECIMAL = 330,       //KeyPad_. (Decimal)
	LKEY_KP_DIVIDE = 331,        //KeyPad_/
	LKEY_KP_MULTIPLY = 332,      //KeyPad_*
	LKEY_KP_SUBTRACT = 333,      //KeyPad_-
	LKEY_KP_ADD = 334,           //KeyPad_+
	LKEY_KP_ENTER = 335,         //KeyPad_ENTER
	LKEY_KP_EQUAL = 336,         //KeyPad_=
}LexInput;
typedef enum {
	LEX_MOUSE_BUTTON_LEFT = 0,
	LEX_MOUSE_BUTTON_RIGHT = 1,
	LEX_MOUSE_BUTTON_MIDDLE = 2,
	LEX_MOUSE_BUTTON_4 = 3,
	LEX_MOUSE_BUTTON_5 = 4,
	LEX_MOUSE_BUTTON_6 = 5,
	LEX_MOUSE_BUTTON_7 = 6,
	LEX_MOUSE_BUTTON_LAST = 7,
}LexMouse;
typedef enum {
	LEX_RELEASE = 0,
	LEX_PRESS = 1,
	LEX_REPEAT = 2,
}LexStatus;
typedef enum {
	LCURSOR_NORMAL = 0x00034001,
	LCURSOR_HIDDEN = 0x00034002,
	LCURSOR_DISABLED = 0x00034003,
	LCURSOR_CAPTURED = 0x00034004,
}LexModeCursor;
typedef enum {
	LEX_JOYSTICK_1 = 0,
	LEX_JOYSTICK_2 = 1,
	LEX_JOYSTICK_3 = 2,
	LEX_JOYSTICK_4 = 3,
	LEX_JOYSTICK_5 = 4,
	LEX_JOYSTICK_6 = 5,
	LEX_JOYSTICK_7 = 6,
	LEX_JOYSTICK_8 = 7,
	LEX_JOYSTICK_9 = 8,
	LEX_JOYSTICK_10 = 9,
	LEX_JOYSTICK_11 = 10,
	LEX_JOYSTICK_12 = 11,
	LEX_JOYSTICK_13 = 12,
	LEX_JOYSTICK_14 = 13,
	LEX_JOYSTICK_15 = 14,
	LEX_JOYSTICK_16 = 15,
}LexJoystick;
typedef enum {
	LEX_GAMEPAD_BUTTON_A = 0,
	LEX_GAMEPAD_BUTTON_B = 1,
	LEX_GAMEPAD_BUTTON_X = 2,
	LEX_GAMEPAD_BUTTON_Y = 3,
	LEX_GAMEPAD_BUTTON_LEFT_BUMPER = 4,
	LEX_GAMEPAD_BUTTON_RIGHT_BUMPER = 5,
	LEX_GAMEPAD_BUTTON_BACK = 6,
	LEX_GAMEPAD_BUTTON_START = 7,
	LEX_GAMEPAD_BUTTON_GUIDE = 8,
	LEX_GAMEPAD_BUTTON_LEFT_THUMB = 9,
	LEX_GAMEPAD_BUTTON_RIGHT_THUMB = 10,
	LEX_GAMEPAD_BUTTON_DPAD_UP = 11,
	LEX_GAMEPAD_BUTTON_DPAD_RIGHT = 12,
	LEX_GAMEPAD_BUTTON_DPAD_DOWN = 13,
	LEX_GAMEPAD_BUTTON_DPAD_LEFT = 14,
	LEX_GAMEPAD_BUTTON_CROSS = 0,
	LEX_GAMEPAD_BUTTON_CIRCLE = 1,
	LEX_GAMEPAD_BUTTON_SQUARE = 2,
	LEX_GAMEPAD_BUTTON_TRIANGLE = 3,
}LexGamePad;
struct Object {
	glm::vec3 Position;
	glm::vec3 Velocity;
	glm::vec3 Force;
	float Mass;
};
//
typedef enum {
	LexGuiEnable = 1
}LexModeGui;
 LEX_API std::string GetFile(const char* filename);
#if defined(__cplusplus)
extern "C" {
#endif
	LEX_API void LexInit();
	LEX_API void LGetVersion();
	LEX_API void LGetRenderer();
	LEX_API void LGetVendor();
	//Untill
	LEX_API void LSetColor(float Red, float Green, float Blue, float Alpha);
	LEX_API void LSetColorBits(unsigned int ModeColorBits);
	LEX_API void LViewPort(int x, int y, int Width, int Height);
	//JoyStick
	LEX_API int LJoyStick(int jid);
	LEX_API const unsigned char* LGetJoyStickHats(int jid, int* Count);
	LEX_API const char* LSetJoyStickName(int jid);
	LEX_API int LSetJoyStickIsGamePad(int jid);
	//GamePad
	LEX_API const char* LGetGamepadName(int jid);
	//Time
	LEX_API double LGetTime();
	LEX_API void LSetTime(double Time);
	LEX_API uint64_t LGetTimerValue();
	LEX_API uint64_t LGetTimerFrequency();
	//Sync
	LEX_API bool LIsSync(LSync Sync);
	LEX_API void LDeleteSync(LSync Sync);
	LEX_API void LWaitSync(LSync Sync,unsigned int BitFeild);
	LEX_API void LEnable(unsigned int Mode);
	LEX_API void LDisable(unsigned int Mode);

	//Draw
	LEX_API void LDrawArrays(int Mode, int First, int Count);
	LEX_API void LDrawArraysInstancedBaseInstance(int Mode, int First, int Count, int InstanceCount, unsigned int BaseInstance);
	LEX_API void LDrawArraysIndirect(int Mode, const void* Indirect);
	LEX_API void LDrawArraysInstanced(int Mode, int First, int Count, int InstanceCount);
	LEX_API void LMultiDrawArrays(int Mode, const int* First, const int* Count, int DrawCount);
	LEX_API void LDrawElements(int Mode, int Count, int Type, const void* Indirect);
	LEX_API void LDrawElementsIndirect(int Mode, int Type, const void* Indirect);
	LEX_API void LDrawElementsInstanced(int Mode, int Count, int Type, const void* Indirect, int InstanceCount);

	LEX_API void LModePolygon(int Mode);

	//Window
	class LEX_API LWindow {
	private:
		GLFWwindow* Window;
	public:
		LWindow();
		void LCreateWindow(int Width, int Height, const char* Tille);
		void LSetContextWindow() const;
		int LShouldClose()const;
		void LPollWindow() const;
		void LDestroyWindow() const;
		void LSetCursorMode(int ModeCursor) const;
		void LSetStatusWindow(int Mode)const;
		void LWaitEvent()const;
		void LSetStatusWindow(int Mode);
		void LWaitTimeEventOut(double TimeWait)const;
		void LDestroyCursor(GLFWcursor* Cursor)const;
		int LGetKeyInput(int Key) const;
		void LWindowOpacity(float Opacity) const;
		void LSetWindowMode(int ModeWindow, int ModeBool) const;
		void LSetInputMode(int ModeInput, int Bool) const;
		const char* LGetClipboardString() const;
		void LSetClipboardString(const char* String) const;
	};
	class LEX_API LTexture {
	private:
		int WidthImg; int HeightImg;
		int numCloch;
	public:
		unsigned int TextureIMG = 0;
		unsigned char* LexTex = nullptr;
		LTexture();
		void LActiveTexture(GLenum TextureMode)const;
		void LBindTexture2D() const;
		void LBindImageTex(unsigned int Uint, unsigned int Texture, int Level, bool Layered, int Layer, int Access, int Format)const;
		void LUnBind2D() const;
		void LBindTexture3D() const;
		void LSetFlipImage(bool ModeFlip);
		void LLoadTexture(const char* FileIMG);
		void LTexImage2D(int ModeTexture, int Level, int Format, int Type) const;
		void LTexImage3D(int ModeTexture, int Level, int Depth, int Format, int Type)const;
		void LTexImage2DMulti(unsigned int Samples, int InternalFormat, unsigned char Fixedsamplelocation) const;
		void LTexImage3DMulti(unsigned int Samples, int InternalFormat, int Depth,unsigned char Fixedsamplelocation) const;
		void LCompressedTexImage2D(int ModeTexture, int Level, int InternalFormat, unsigned int ImageSize)const;
		void LCompressedTexImage3D(int ModeTexture, int Level, int InternalFormat, unsigned int Depth, unsigned int ImageSize)const;
		void LTexStorageImage2D(int ModeTexture, int Levels, int InternalFormat)const;
		void LTexStorageImage3D(int ModeTexture, int Levels, int InternalFormat, int Depth)const;
		void LGenerateMipmap(unsigned int ModeMipmap) const;
		void LTexSubImage2D(int ModeTexture, int Level, int XoffSet, int YoffSet, int Width, int Height, int Format, int Type) const;
		void LTexSubImage3D(int ModeTexture, int Level, int XoffSet, int YoffSet, int ZoffSet, int Width, int Height, int Depth, int Format, int Type) const;
		void LTextureSubImage2D(int Texture, int Level, int XoffSet, int YoffSet, int Width, int Height, int Format, int Type) const;
		void LTextureSubImage3D(int Texture, int Level, int XoffSet, int YoffSet, int ZoffSet, int Width, int Height, int Depth, int Format, int Type) const;
		void LCompressedTexSubImage2D(int Texture, int Level, int XoffSet, int YoffSet, int Width, int Height, int Format, int ImageSize) const;
		void LCompressedTexSubImage3D(int Texture, int Level, int XoffSet, int YoffSet, int ZoffSet, int Width, int Height, int Depth, int Format, int ImageSize) const;
		void LFreeTexture() const;
		void LDeleteTexture()const;
		void LSetTexture2D(float Param_Min, float Param_Mag, int Map_S, int Map_T) const ;
		void LSetTexture3D(float Param_Min, float Param_Mag, int Map_S, int Map_T, int Map_R) const ;
	};
	class LEX_API LShader {
	private:
		void CheckErrors(unsigned int shader, const char* type);
	public: 
		unsigned int Program;
		LShader(const char* vertexFile, const char* fragmentFile);
		void Activate() const;
		void DeleteProgram() const;
		bool LIsProgram();
	};
	class LEX_API LEBO {
	public:
		GLuint ID;
		// Constructor that generates a Elements Buffer Object and links it to indices
		LEBO(GLuint* indices, GLsizeiptr size);
		// Binds the EBO
		void Bind() const;
		// Unbinds the EBO
		void Unbind() const;
		// Deletes the EBO
		void Delete() const;
	};
	class LVBO
	{
	public:
		// Reference ID of the Vertex Buffer Object
		GLuint ID;
		// Constructor that generates a Vertex Buffer Object and links it to vertices
		LVBO(GLfloat* vertices, GLsizeiptr size);
		// Binds the VBO
		void Bind() const;
		// Unbinds the VBO
		void Unbind() const;
		// Deletes the VBO
		void Delete() const;
	};
	class LEX_API LVAO {
	public:
		GLuint ID;
		LVAO();
		void LinkAttrib(LVBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset) const;
		// Binds the VAO
		void Bind() const;
		// Unbinds the VAO
		void Unbind() const;
		// Deletes the VAO
		void Delete() const;
	};
#if defined(__cplusplus)
}
#endif
#endif // !LEX_CORE_CLASS_FUNC_H