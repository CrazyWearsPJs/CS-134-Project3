#include "Enemy.h"
#include "Projectile.h"

Enemy::Enemy(Ogre::Entity * entity, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity, inital_pos, inital_dir)
{}

Projectile * Enemy::fireProjectile()
{
	return 0;
}

void Enemy::move(Ogre::RaySceneQuery * query)
{
	return;
}

Enemy::~Enemy()
{
	
}
