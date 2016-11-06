#ifndef _SHADER_COMPONENT_H
#define _SHADER_COMPONENT_H

#pragma once

#include "OpenGLShaderHandler.h"
#include "ShaderProgram.h"

#include <vector>

#include <glew.h>
#include <glut.h>

#include <gl\GL.h>
#include <gl\GLU.h>

namespace DRE
{
	class ShaderComponent
	{
	public:
		enum ShaderType
		{
			VERTEX,
			FRAGMENT,
			GEOMETRY,
			TESSELLATION
		};

		ShaderComponent(const std::string& shaderFilename, const std::string& shaderName, ShaderType type);
		~ShaderComponent();

		void LoadShaderSource();
		void CompileShader();
		void MakeRunnable();
		void RemoveFromGPU();

		void AddVertexUser(const ShaderProgram* sp)
		{
			auto iter = std::find(vertexUsers.begin(), vertexUsers.end(), sp);
			if (iter != vertexUsers.end())
			{
				vertexUsers.push_back((ShaderProgram*)sp);
			}
		}
		void RemoveVertexUser(const ShaderProgram* sp)
		{
			auto iter = std::find(vertexUsers.begin(), vertexUsers.end(), sp);
			if (iter != vertexUsers.end())
			{
				vertexUsers.erase(iter);
			}
		}

		void AddFragmentUser(const ShaderProgram* sp)
		{
			auto iter = std::find(fragmentUsers.begin(), fragmentUsers.end(), sp);
			if (iter != fragmentUsers.end())
			{
				fragmentUsers.push_back((ShaderProgram*)sp);
			}
		}
		void RemoveFragmentUser(const ShaderProgram* sp)
		{
			auto iter = std::find(fragmentUsers.begin(), fragmentUsers.end(), sp);
			if (iter != fragmentUsers.end())
			{
				fragmentUsers.erase(iter);
			}
		}

		void DetachFromAllPrograms()
		{
			for (auto iter = vertexUsers.begin(); iter != vertexUsers.end(); iter++)
			{
				//(*iter)->DetachVertexShader();
			}
			vertexUsers.clear();
			for (auto iter = fragmentUsers.begin(); iter != vertexUsers.end(); iter++)
			{
				//(*iter)->DetachVertexShader();
			}
			fragmentUsers.clear();
		}

	private:
		bool canRun = false;

		ShaderType m_ShaderType;

		OpenGLShaderHandler* shaderReference;

		std::string m_sourceResource;
		std::string m_sourceFilename;
		std::string m_shaderSource;

		std::string GetCompileMessage() const;

		std::vector<ShaderProgram*> vertexUsers;
		std::vector<ShaderProgram*> fragmentUsers;
	};
}

#endif
