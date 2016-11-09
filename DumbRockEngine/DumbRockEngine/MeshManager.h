#ifndef _MESHMANAGER_H
#define _MESHMANAGER_H

#pragma once

#include "Mesh.h"
#include "ResourceManager.h"

namespace DRE
{
	class MeshManager : public ResourceManager<Mesh>
	{
	public:
		MeshManager()
			: ResourceManager<Mesh>()
		{

		}

		~MeshManager() 
		{

		}
	};
}

#endif