#ifndef _VERTEX_H
#define _VERTEX_H

#pragma once

#include "RS Math\RS_Math_Engine.h"
#include "Colour.h"
using namespace RS_MATH;
namespace DRE
{
	class Vertex
	{
	private:
		Vec3 *vertices;
		Colour *colour;
		Vec3 *uvs;
		Vec3 *normals;

	public:
		//Get for Vertices
		Vec3* getVertices();

		//Get for UVs
		Vec3* getUVs();

		//Get for Colours
		Vec3* getColours();

		//Get for Normals
		Vec2* getNormals();
		
	protected:
		//Set normals
		void setNormals(Vec2 *normals);

		//Set colours
		void setColours(Vec3 *colours);

		//Set vertices
		void setVertices(Vec3 *vertices);

		//Set UVs
		void setUVs(Vec3* uvs[]);
	};
}

#endif
