#include "Projectile.h"

Projectile::Projectile(Ogre::Entity * entity, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity, inital_pos, inital_dir)
{}

void Projectile::move(Ogre::RaySceneQuery * RaySceneQuery)
{
	return;
}

std::vector<Ogre::Entity *> Projectile::collision(Ogre::RaySceneQuery *)
{
	return std::vector<Ogre::Entity *>();
}

Projectile::~Projectile()
{

}
