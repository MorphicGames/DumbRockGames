#include "OpenGLShaderHandler.h"

namespace DRE
{
	GLuint OpenGLShaderHandler::getOpenGLReference() const
	{
		return shaderReference;
	}

	void OpenGLShaderHandler::setOpenGLReference(GLuint ref)
	{
		shaderReference = ref;
		isNull = false;
	}

	void OpenGLShaderHandler::Nullify()
	{
		isNull = true;
	}
}
