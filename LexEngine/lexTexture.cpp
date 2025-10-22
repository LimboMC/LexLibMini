#include"lex.h"
void LTexture::LSetFlipImage(bool ModeFlip) {
	stbi_set_flip_vertically_on_load(ModeFlip);
}
void LTexture::LLoadTexture(const char *FileIMG) {
	LexTex = stbi_load(FileIMG, &WidthImg, &HeightImg, &numCloch, 0);
}
void LTexture::LSetTexture2D(float Param_Min,float Param_Mag, int Map_S,int Map_T) const {
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Param_Min);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Param_Mag);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Map_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Map_T);
}
void LTexture::LSetTexture3D(float Param_Min, float Param_Mag, int Map_S,int Map_T,int Map_R) const {
	glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, Param_Min);
	glTexParameterf(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, Param_Mag);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, Map_S);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, Map_T);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, Map_R);
}
LTexture::LTexture() {
	glGenTextures(1, &TextureIMG);
}
void LTexture::LBindTexture2D() const {
	glBindTexture(GL_TEXTURE_2D,TextureIMG);
}
void LTexture::LUnBind2D() const{
	glBindTexture(GL_TEXTURE_2D,0);
}
void LTexture::LBindTexture3D() const {
	glBindTexture(GL_TEXTURE_3D, TextureIMG);
}
void LTexture::LTexImage2D(int Texture,int Level,int Format,int Type) const {
	glTexImage2D(Texture,Level,Format,WidthImg, HeightImg,0,Format,Type,LexTex);
}
void LTexture::LTexImage3D(int Texture, int Level,int Depth, int Format, int Type) const {
	glTexImage3D(Texture, Level,Format, WidthImg, HeightImg, Depth, 0, Format, Type, LexTex);
}
void LTexture::LTexImage2DMulti(unsigned int Samples, int InternalFormat,unsigned char Fixedsamplelocation) const {
	glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, Samples, InternalFormat, WidthImg, HeightImg, Fixedsamplelocation);
}
void LTexture::LTexImage3DMulti(unsigned int Samples, int InternalFormat,int Depth,unsigned char Fixedsamplelocation) const {
	glTexImage3DMultisample(GL_TEXTURE_2D_MULTISAMPLE_ARRAY, Samples, InternalFormat, WidthImg, HeightImg, Depth, Fixedsamplelocation);
}
void LTexture::LCompressedTexImage2D(int Texture, int Level, int InternalFormat,unsigned int ImageSize) const{
	glCompressedTexImage2D(Texture, Level, InternalFormat, WidthImg, HeightImg, 0, ImageSize, LexTex);
}
void LTexture::LCompressedTexImage3D(int Texture, int Level, int InternalFormat,unsigned int Depth, unsigned int ImageSize) const {
	glCompressedTexImage3D(Texture, Level, InternalFormat, WidthImg, HeightImg, Depth, 0, ImageSize, LexTex);
}
void LTexture::LTexStorageImage2D(int Texture, int Levels, int InternalFormat)const {
	glTexStorage2D(Texture, Levels, InternalFormat, WidthImg, HeightImg);
}
void LTexture::LTexStorageImage3D(int Texture, int Levels, int InternalFormat,int Depth) const {
	glTexStorage3D(Texture, Levels, InternalFormat, WidthImg, HeightImg, Depth);
}
void LTexture::LFreeTexture() const {
	stbi_image_free(LexTex);
}
void LTexture::LActiveTexture(GLenum TextureMode)const {
	glActiveTexture(TextureMode);
}
void LTexture::LDeleteTexture()const {
	glDeleteTextures(1, &TextureIMG);
}
void LTexture::LBindImageTex(unsigned int Uint,unsigned int Texture,int Level,bool Layered,int Layer,int Access,int Format) const {
	glBindImageTexture(Uint, Texture, Level, Layered, Layer, Access, Format);
}
void LEnable(unsigned int Mode){
	glEnable(Mode);
}
void LDisable(unsigned int Mode){
	glDisable(Mode);
}
void LTexture::LGenerateMipmap(unsigned int ModeMipmap) const {
	glGenerateMipmap(ModeMipmap);
}
void LTexture::LTexSubImage2D(int Texture,int Level,int XoffSet,int YoffSet,int Width,int Height,int Format,int Type) const {
	glTexSubImage2D(Texture, Level, XoffSet, YoffSet, Width, Height, Format, Type, LexTex);
}
void LTexture::LTexSubImage3D(int Texture, int Level, int XoffSet, int YoffSet,int ZoffSet, int Width, int Height,int Depth, int Format, int Type) const {
	glTexSubImage3D(Texture, Level, XoffSet, YoffSet, ZoffSet, Width, Height, Depth, Format, Type, LexTex);
}
void LTexture::LTextureSubImage2D(int Texture,int Level,int XoffSet,int YoffSet,int Width,int Height,int Format,int Type) const {
	glTextureSubImage2D(Texture, Level, XoffSet, YoffSet, Width, Height, Format, Type, LexTex);
}
void LTexture::LTextureSubImage3D(int Texture, int Level, int XoffSet, int YoffSet, int ZoffSet, int Width, int Height, int Depth, int Format, int Type) const {
	glTextureSubImage3D(Texture, Level, XoffSet, YoffSet, ZoffSet, Width, Height, Depth, Format, Type, LexTex);
}
void LTexture::LCompressedTexSubImage2D(int Texture, int Level, int XoffSet, int YoffSet, int Width, int Height, int Format, int ImageSize) const {
	glCompressedTexSubImage2D(Texture, Level, XoffSet, YoffSet, Width, Height, Format, ImageSize, LexTex);
}
void LTexture::LCompressedTexSubImage3D(int Texture, int Level, int XoffSet, int YoffSet, int ZoffSet, int Width, int Height, int Depth, int Format, int ImageSize)const{
	glCompressedTexSubImage3D(Texture, Level, XoffSet, YoffSet, ZoffSet, Width, Height, Depth, Format, ImageSize, LexTex);
}