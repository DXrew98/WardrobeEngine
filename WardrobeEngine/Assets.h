#pragma once
#include <unordered_map>
#include "VMMath.h"

class Asset {
	
	Asset() {}
public:
	struct Texture {
		
		unsigned width, height, handle;
		// rows, colls, animations could be included in here
	};
	
	std::unordered_map<std::string, Texture> textures;
	
	void loadTexture(const std::string &name, const char *path);
	Texture getTexture(const std::string &name);

	void drawTexture(const std::string &name, const mat3 &m = mat3::identity());

	static Asset &instance() {
		static Asset i; return i;
	}
};