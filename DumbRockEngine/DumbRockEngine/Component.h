#ifndef _COMPONENT_H
#define _COMPONENT_H
#pragma once

#include <string>


namespace DRE
{
	class Component
	{
	public:

		Component(std::string type)
		{
			mtype = type;
		}
		virtual ~Component();

		virtual void Update() = 0;
		virtual void Render() = 0;

	protected:
		std::string mtype;




	};
}

#endif