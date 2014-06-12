#include "Enemy.h"
#include "Projectile.h"
#include <vector>
#include <sstream>

using namespace Ogre;

Enemy::Enemy(const Ogre::String & entity_name, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity_name, inital_pos, inital_dir)
{
	++Enemy::id;
}

int Enemy::id = 0;

Ogre::String Enemy::get_next_name()
{
	Ogre::StringStream ss;
	ss << Enemy::id;
	return "Enemy" + ss.str();
}

std::vector<Ogre::String> Enemy::collision(Ogre::RaySceneQuery *)
{
	return std::vector<Ogre::String>();
}

Projectile * Enemy::fireProjectile(Ogre::SceneManager * manager)
{
	Ogre::String new_entity_name;

	return new Projectile(new_entity_name, this -> pos, Ogre::Vector3(1, 0, 0));
}

void Enemy::move(Ogre::SceneManager * manager, Ogre::RaySceneQuery * query, Ogre::Camera * camera)
{
    Vector3 newPos = pos + Vector3(-0.1, 0, 0);
    this -> pos = newPos;
    manager -> getSceneNode(this -> entity_name + "Node") -> setPosition(newPos);
	return;
}

Enemy::~Enemy()
{

}
