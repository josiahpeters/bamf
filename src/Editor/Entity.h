#pragma once

#include "gEntity.h"

using namespace BAMF;
using namespace System::ComponentModel;

[TypeConverter(ExpandableObjectConverter::typeid)] 
ref class Entity
{	
public:
	gEntity* unmanaged;
	TreeNode^ node;

	property String^ Name
	{
		String^ get()
		{
			return node->Text;
		}
		void set(String^ value)
		{
			node->Text = value;
		}
	}
	[ReadOnly(true)] 
	property int Id
	{
		int get()
		{
			return unmanaged->id;
		}
	}
	void SelectEntityAndNode(gEntity* entity, TreeNode^ _node)
	{
		node = _node;
		unmanaged = entity;
	}
	Entity()
	{
	}
	Entity(gEntity* entity, TreeNode^ _node)
	{
		node = _node;
		unmanaged = entity;
	}
};