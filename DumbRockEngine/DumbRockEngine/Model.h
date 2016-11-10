#ifndef _MODEL_H
#define _MODEL_H

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
#pragma once

#endif
