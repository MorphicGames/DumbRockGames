#ifndef _MESH_H
#define _MESH_H

#pragma once

#include "RS Math\RS_Math_Engine.h"
#include "Vertex.h"

using namespace RS_MATH;

class Color;

namespace DRE
{
	class Mesh
	{
	public:
		Mesh();
		Mesh(Vertex *vertices);

		//Get vertices
		Vertex* getVertices();

	private:
		//All data stored within a Mesh
		Vertex *vertices;

		
	};
}

#endif // !MESH_H

