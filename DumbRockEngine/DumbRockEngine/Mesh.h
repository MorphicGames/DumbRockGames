#ifndef _MESH_H
#define _MESH_H

#pragma once

#include "Vertex.h"

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

