#ifndef _MATERIAL_H
#define _MATERIAL_H

#include <string>
#include "Colour.h"
namespace DRE
{
	class Material
	{
	private:
		Colour ambient;
		Colour diffuse;
		Colour specular;
		Colour emissive;
		float specPower;
		std::string materialName;
	};
}


#pragma once



#endif
