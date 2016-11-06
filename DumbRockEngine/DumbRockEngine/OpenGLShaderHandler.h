#ifndef _OPENGLSHADERHANDLER_H
#define _OPENGLSHADERHANDLER_H

#pragma once

#include <glew.h>
#include <glut.h>

#include <gl\GL.h>
#include <gl\GLU.h>

namespace DRE
{
	class OpenGLShaderHandler
	{
	private:
		bool isNull = true;
		GLuint shaderReference;

	public:
		OpenGLShaderHandler() : shaderReference(0) {

		}

		bool IsNull() {
			return isNull;
		}
		GLuint getOpenGLReference() const;
		void setOpenGLReference(GLuint ref);
		void Nullify();
	};
}

#endif