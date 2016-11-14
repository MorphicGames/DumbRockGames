#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#pragma once

#include <map>
#include <vector>

namespace DRE
{
	template <class ResourceType>
	class ResourceManager
	{
	private:
		std::map<std::string, ResourceType*>* resourceNameTable;

	public:
		ResourceManager() {
			resourceNameTable = new std::map<std::string, ResourceType*>();
		}

		~ResourceManager() {
			if (resourceNameTable) {
				delete resourceNameTable;
				resourceNameTable = nullptr;
			}
		}

		int AddResource(const std::string& name, ResourceType* resource) {
			resourceNameTable->insert(std::make_pair(name, resource));
			return 0;
		}

		ResourceType GetResource(const std::string& name) {
			std::map<std::string, ResourceType*>::iterator tmp = resourceNameTable->find(name);
			return tmp->second;
		}

		ResourceType GetResource(int resourceIndex) {
			std::map<std::string, ResourceType*>::iterator tmp = resourceNameTable->at(resourceIndex);
			return tmp->second;
		}

		void RemoveResource(const std::string& name) {
			std::map<std::string, ResourceType*>::iterator tmp = resourceNameTable->find(name);
			delete tmp->second;
			tmp->second = nullptr;
			resourceNameTable->erase(name);
		}

		void RemoveResource(int resourceIndex) {
			std::map<std::string, ResourceType*>::iterator tmp = resourceNameTable->at(resourceIndex);
			delete tmp->second;
			tmp->second = nullptr;
			resourceNameTable->erase(tmp->first);
		}

		void ClearResources() {
			for (std::map<std::string, ResourceType*>::iterator i = resourceNameTable.begin(); i != resourceNameTable.end(); i++)
			{
				delete i->second;
				i->second = nullptr;
			}
			resourceNameTable->clear();
		}
	};
}

#endif