#ifndef _MODELRENDERER_H
#define _MODELRENDERER_H
#pragma once

#include "Component.h"
#include "Model.h"

namespace DRE
{
	class ModelRenderer : public Component
	{
	public:
		ModelRenderer(Model* model);
		~ModelRenderer();

		void Update();
		void Render();

	protected:
		Model* m_model;


	};
}

#endif
