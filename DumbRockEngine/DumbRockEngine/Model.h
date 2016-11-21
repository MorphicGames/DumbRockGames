#ifndef _MODEL_H
#define _MODEL_H

#pragma once

#include <vector>

#include "Mesh.h"
#include "DRE_typedef.h"

namespace DRE
{
	class Model
	{
	private:
		std::vector<Mesh> meshes;

	public:
		Model()
		{

		}
	};
}

#endif
