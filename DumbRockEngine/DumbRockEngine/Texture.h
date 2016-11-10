#ifndef _TEXTURE_H
#define _TEXTURE_H
#pragma once

#include <string>

namespace DRE
{
	class Texture
	{
	public:
		Texture() {}
		// The name of the texture
		GLuint	texName;
		// The name of the resource for the texture
		std::string	resourceName;
		//Image height
		int	height;
		//image width
		int	width;

	};
}



#endif // !_TEXTURE_H


