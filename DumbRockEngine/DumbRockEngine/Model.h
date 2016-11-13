#ifndef _MODEL_H
#define _MODEL_H

#pragma once

#include "Mesh.h"
#include "Vertex.h"
#include "AbstractRenderer.h"

namespace DRE
{
	class Model
	{
	private:
		Mesh *meshes;
		AbstractRenderer *renderer;

	};
}

#endif
