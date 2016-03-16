#include "Assets.h"
#include "sfwdraw.h"
#include "Window.h"

void Asset::loadTexture(const std::string & name, const char * path)
{

	assert(Window::instance().isInitialized & "Window is not initialized");
	Texture temp;
	//todo: error handling
	temp.handle = sfw::loadTextureMap(path);
	temp.height = sfw::getTextureHeight(temp.handle);
	temp.width = sfw::getTextureWidth(temp.handle);

	textures[name] = temp;
}

Asset::Texture Asset::getTexture(const std::string & name)
{
	return textures[name];
}

void Asset::drawTexture(const std::string & name, const mat3 & m)
{
	sfw::drawTextureMatrix(getTexture(name).handle, 0, WHITE, andMath::mat4::mat3to4(m.m, 0).m);
}
