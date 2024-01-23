#pragma once
#include "Entity.h"
#include "Manager.h"
#include "Component.h"

void Entity::update() const
{
	for (auto const& c : components) c->update();
}

void Entity::draw() const
{
	for (auto const& c : components) c->draw();
}

bool Entity::hasGroup(Group mGroup)
{
	return groupBitSet[mGroup];
}

void Entity::addGroup(Group mGroup)
{
	groupBitSet[mGroup] = true;
	manager.addToGroup(this, mGroup);
}

void Entity::delGroup(Group mGroup)
{
	groupBitSet[mGroup] = false;
}
