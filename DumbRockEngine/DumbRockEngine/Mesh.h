#ifndef _MESH_H
#define _MESH_H

#pragma once

#include "RS Math\RS_Math_Engine.h"

using namespace RS_MATH;

class Color;

namespace DRE
{
	struct Vertex
	{

	};

	class Mesh
	{
	public:
		Mesh();
		Mesh(Vec3* vertices[], Vec3* uvs[], Vec3* colours[], Vec2* normals[]);

	private:
		//All data stored within a Mesh
		Vec3* vertices[];
		Vec3* uvs[];
		Color* colours[];
		Vec2* normals[];

		//Get/Set for Vertices
		void setVertices(Vec3* vertices[]);
		Vec3* getVertices();

		//Get/Set for UVs
		void setUVs(Vec3* uvs[]);
		Vec3* getUVs();

		//Get/Set for Colours
		void setColours(Vec3* colours[]);
		Vec3* getColours();

		//Get/Set for Normals
		void setNormals(Vec2* normals[]);
		Vec2* getNormals();
	};
}

#endif // !MESH_H

