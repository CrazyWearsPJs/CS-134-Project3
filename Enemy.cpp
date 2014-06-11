#include "Enemy.h"
#include "Projectile.h"
#include <vector>
Enemy::Enemy(Ogre::Entity * entity, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity, inital_pos, inital_dir)
{}

std::vector<Ogre::Entity *> Enemy::collision(Ogre::RaySceneQuery *)
{
	return std::vector<Ogre::Entity *>();
}

Projectile * Enemy::fireProjectile(Ogre::SceneManager * manager)
{
	Ogre::Entity * new_entity = 0;

	return new Projectile(new_entity, this -> pos, Ogre::Vector3(1, 0, 0));
}

void Enemy::move(Ogre::RaySceneQuery * query)
{
	return;
}

Enemy::~Enemy()
{

}
