#ifndef _TEXTURE_H
#define _TEXTURE_H

#pragma once

#include "OpenGL\glew-1.13.0\include\GL\glew.h"
#include "OpenGL\Simple OpenGL Image Library\src\SOIL.h"

namespace DRE
{
	class Texture
	{
	private:
		GLuint m_Texture;
		unsigned char* m_Image;
		int m_Width, m_Height;

	public:
		Texture(const char* filename, int width, int height)
			: m_Width(width)
			, m_Height(height)
		{
			glGenTextures(1, &m_Texture);
			glBindTexture(GL_TEXTURE_2D, m_Texture);
				m_Image = SOIL_load_image(filename, &m_Width, &m_Height, 0, SOIL_LOAD_RGB);
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_Image);
				glGenerateMipmap(GL_TEXTURE_2D);
				SOIL_free_image_data(m_Image);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	};
}

#endif 