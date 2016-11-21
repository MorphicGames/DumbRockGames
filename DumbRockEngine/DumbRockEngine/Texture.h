#ifndef _TEXTURE_H
#define _TEXTURE_H

#pragma once

#include <string>
#include "OpenGL\glew-1.13.0\include\GL\glew.h"
#include "OpenGL\assimp-3.1.1\include\assimp\Importer.hpp"

namespace DRE
{
	struct Texture {
		GLuint id;
		std::string type;
		aiString path;
	};
}

#endif 