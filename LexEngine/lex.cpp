#include"lex.h"
#include<iostream>
void LexInit() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
	glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);
}
LWindow::LWindow() {
	LWindow::Window = NULL;
}
void LGetVersion() {
	const unsigned char* Version;
	Version = glGetString(GL_VERSION);
	std::cout << Version <<'\n';
}
void LGetRenderer() {
	const unsigned char* Renderer = glGetString(GL_RENDERER);
	std::cout << Renderer << '\n';
}
void LGetVendor() {
	const unsigned char* Vendor = glGetString(GL_VENDOR);
	std::cout << Vendor << '\n';
}
void LSetColor(float Red, float Green, float Blue, float Alpha) {
	glClearColor(Red, Green, Blue, Alpha);
	glClear(GL_COLOR_BUFFER_BIT);
}
void LSetColorBits(unsigned int ModeColorBits) {
	if (ModeColorBits == LEX_RBGA_NORMAL_BIT8) {
		glfwWindowHint(LEX_RED_BITS, 8);
		glfwWindowHint(LEX_GREEN_BITS, 8);
		glfwWindowHint(LEX_BLUE_BITS, 8);
		glfwWindowHint(LEX_ALPHA_BITS, 8);
	}
	else if (ModeColorBits == LEX_RBGA_NORMAL_BIT10) {
		glfwWindowHint(LEX_RED_BITS, 10);
		glfwWindowHint(LEX_GREEN_BITS, 10);
		glfwWindowHint(LEX_BLUE_BITS, 10);
		glfwWindowHint(LEX_ALPHA_BITS, 10);
	}
	else if (ModeColorBits == LEX_RBGA16_BITS) {
		glfwWindowHint(LEX_RED_BITS, 16);
		glfwWindowHint(LEX_GREEN_BITS, 16);
		glfwWindowHint(LEX_BLUE_BITS, 16);
		glfwWindowHint(LEX_ALPHA_BITS, 16);
	}
	else if (ModeColorBits == LEX_RBGA10_A2_BITS) {
		glfwWindowHint(LEX_RED_BITS, 10);
		glfwWindowHint(LEX_GREEN_BITS, 10);
		glfwWindowHint(LEX_BLUE_BITS, 10);
		glfwWindowHint(LEX_ALPHA_BITS, 2);
	}
	else std::cout<<"ERROR : MODE COLOR NOT SUPPORT !\n";
}
//CURSOR
//Create Window Lex
void LWindow::LCreateWindow(int Width, int Height, const char* Tille) {
	Window = glfwCreateWindow(Width, Height, Tille, NULL, NULL);
	if (Window == NULL) {
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
	}
}
// Set Context Window OpenGL
void LWindow::LSetContextWindow() const {
	glfwMakeContextCurrent(Window);
	gladLoadGL();
}
//Func Should CLose Window Lex
int LWindow::LShouldClose() const {
	return glfwWindowShouldClose(Window);
}
//Loop Window Lex
void LWindow::LPollWindow() const {
	glfwSwapBuffers(Window);
	glfwPollEvents();
}
//Destroy Window Lex
void LWindow::LDestroyWindow() const {
	glfwDestroyWindow(Window);
	glfwTerminate();
}
void LWindow::LSetCursorMode(int ModeCursor )const {
	if (ModeCursor == LEX_CURSOR_CAPTURED) {
		glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
	}
	else if (ModeCursor == LEX_CURSOR_DISABLED) {
		glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
	else if (ModeCursor == LEX_CURSOR_NORMAL) {
		glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	else if (ModeCursor == LEX_CURSOR_HIDDEN) {
		glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	}
	else
		std::cout << "ERROR : MODE CURSOR NOT SUPPORT !" << std::endl;
}
void LWindow::LSetStatusWindow(int Mode) const {
	if (Mode == LEX_MAXIMIZED_WINDOW) {
		glfwMaximizeWindow(Window);
	}
	else if (Mode == LEX_MINIMIZED_WINDOW) {
		glfwIconifyWindow(Window);
	}
	else if (Mode == LEX_HIDE_WINDOW) {
		glfwHideWindow(Window);
	}
	else {
		std::cout<<"Error: Mode Window Size Not Found\n";
	}
}
void LWindow::LWaitEvent()const {
	glfwWaitEvents();
}
void LWindow::LWaitTimeEventOut(double TimeWait)const {
	glfwWaitEventsTimeout(TimeWait);
}
void LWindow::LDestroyCursor(GLFWcursor* Cursor)const {
	glfwDestroyCursor(Cursor);
}
void LViewPort(int x, int y, int Width, int Height){
	glViewport(x, y, Width, Height);
}
void LWindow::LSetStatusWindow(int Mode) {
	if (Mode == LEX_MAXIMIZED_WINDOW) {
		glfwMaximizeWindow(Window);
	}
	else if (Mode == LEX_MINIMIZED_WINDOW) {
		glfwIconifyWindow(Window);
	}
	else if (Mode == LEX_HIDE_WINDOW) {
		glfwHideWindow(Window);
	}
	else {
		std::cout<<"Error: Mode Window Size Not Found\n";
	}
}
void LWindow::LWindowOpacity(float opacity) const {
	glfwSetWindowOpacity(Window, opacity);
}
void LWindow::LSetWindowMode(int ModeWindow, int ModeBool) const {
	glfwWindowHint(ModeWindow, ModeBool);
}
//Input
int LWindow::LGetKeyInput(int Key) const {
	return glfwGetKey(Window, Key);
}
void LWindow::LSetInputMode(int ModeInput, int Bool) const {
	glfwSetInputMode(Window, ModeInput, Bool);
}
int LJoyStick(int jid) {
	return glfwJoystickPresent(jid);
}
const unsigned char * LGetJoyStickHats(int jid,int *Count){
	return glfwGetJoystickHats(jid,Count);
}
const char* LSetJoyStickName(int jid) {
	return glfwGetJoystickName(jid);
}
int LSetJoyStickIsGamePad(int jid) {
	return glfwJoystickIsGamepad(jid);
}
const char * LGetGamepadName(int jid) {
	return glfwGetGamepadName(jid);
}
double LGetTime() {
	return glfwGetTime();
}
void LSetTime(double Time) {
	glfwSetTime(Time);
}
uint64_t LGetTimerValue() {
	return glfwGetTimerValue();
}
uint64_t LGetTimerFrequency() {
	return glfwGetTimerFrequency();
}
const char * LWindow::LGetClipboardString() const {
	return glfwGetClipboardString(Window);
}
void LWindow::LSetClipboardString(const char *String) const{
	glfwSetClipboardString(Window, String);
}
std::string GetFile(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}
// Constructor that build the Shader Program from 2 different shaders
LShader::LShader(const char* vertexFile, const char* fragmentFile)
{
	// Read vertexFile and fragmentFile and store the strings
	std::string vertexCode = GetFile(vertexFile);
	std::string fragmentCode = GetFile(fragmentFile);
	// Convert the shader source strings into character arrays
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();
	// Create Vertex Shader Object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	// Attach Vertex Shader source to the Vertex Shader Object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(vertexShader);
	// Checks if Shader compiled succesfully
	CheckErrors(vertexShader, "VERTEX");
	// Create Fragment Shader Object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// Attach Fragment Shader source to the Fragment Shader Object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	// Compile the Vertex Shader into machine code
	glCompileShader(fragmentShader);
	// Checks if Shader compiled succesfully
	CheckErrors(fragmentShader, "FRAGMENT");
	// Create Shader Program Object and get its reference
	Program = glCreateProgram();
	// Attach the Vertex and Fragment Shaders to the Shader Program
	glAttachShader(Program, vertexShader);
	glAttachShader(Program, fragmentShader);
	// Wrap-up/Link all the shaders together into the Shader Program
	glLinkProgram(Program);
	// Checks if Shaders linked succesfully
	CheckErrors(Program, "PROGRAM");
	// Delete the now useless Vertex and Fragment Shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}
// Activates the Shader Program
void LShader::Activate() const
{
	glUseProgram(Program);
}
// Deletes the Shader Program
void LShader::DeleteProgram() const
{
	glDeleteProgram(Program);
}
void LDeleteSync(LSync Sync) {
	glDeleteSync(Sync);
}
bool LIsSync(LSync Sync){
	return glIsSync(Sync);
}
void LWaitSync(LSync Sync, unsigned int BitFeild){
	glWaitSync(Sync,BitFeild,GL_TIMEOUT_IGNORED);
}
bool LShader::LIsProgram() {
	return glIsProgram(Program);
}
// Checks if the different Shaders have compiled properly
void LShader::CheckErrors(unsigned int shader, const char* type)
{
	// Stores status of compilation
	GLint hasCompiled;
	// Character array to store error message in
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}
void LDrawArrays(int Mode,int First,int Count) {
	glDrawArrays(Mode, First, Count);
}
void LDrawArraysInstancedBaseInstance(int Mode, int First, int Count,int InstanceCount,unsigned int BaseInstance) {
	glDrawArraysInstancedBaseInstance(Mode, First, Count, InstanceCount, BaseInstance);
}
void LDrawArraysIndirect(int Mode,const void *Indirect) {
	glDrawArraysIndirect(Mode, Indirect);
}
void LDrawArraysInstanced(int Mode, int First, int Count, int InstanceCount) {
	glDrawArraysInstanced(Mode, First, Count, InstanceCount);
}
void LMultiDrawArrays(int Mode,const int* First,const int* Count, int DrawCount) {
	glMultiDrawArrays(Mode, First, Count, DrawCount);
}
void LDrawElements(int Mode, int Count,int Type, const void* Indirect) {
	glDrawElements(Mode, Count, Type, Indirect);
}
void LDrawElementsIndirect(int Mode,int Type, const void* Indirect) {
	glDrawElementsIndirect(Mode, Type, Indirect);
}
void LDrawElementsInstanced(int Mode, int Count, int Type, const void* Indirect, int InstanceCount) {
	glDrawElementsInstanced(Mode, Count, Type, Indirect, InstanceCount);
}
LEBO::LEBO(GLuint* indices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void LModePolygon(int Mode){
	glPolygonMode(GL_FRONT_AND_BACK, Mode);
}
// Binds the EBO
void LEBO::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

// Unbinds the EBO
void LEBO::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Deletes the EBO
void LEBO::Delete() const
{
	glDeleteBuffers(1, &ID);
}
LVAO::LVAO()
{
	glGenVertexArrays(1, &ID);
}

// Links a VBO Attribute such as a position or color to the VAO
void LVAO::LinkAttrib(LVBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizei stride, void* offset) const
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

// Binds the VAO
void LVAO::Bind() const
{
	glBindVertexArray(ID);
}

// Unbinds the VAO
void LVAO::Unbind() const
{
	glBindVertexArray(0);
}
// Deletes the VAO
void LVAO::Delete() const
{
	glDeleteVertexArrays(1, &ID);
}
LVBO::LVBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

// Binds the VBO
void LVBO::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

// Unbinds the VBO
void LVBO::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Deletes the VBO
void LVBO::Delete() const
{
	glDeleteBuffers(1, &ID);
}