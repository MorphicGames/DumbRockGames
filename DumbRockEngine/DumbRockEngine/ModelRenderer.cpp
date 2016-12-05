#include "ModelRenderer.h"

namespace DRE
{
	ModelRenderer::ModelRenderer(Model* model) : Component("Model")
	{
		m_model = model;
	}

	ModelRenderer::~ModelRenderer()
	{

	}

	void ModelRenderer::Update()
	{

	}

	void ModelRenderer::Render()
	{
		//m_model->Render();		
	}
}