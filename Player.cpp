#include "Player.h"
#include "Projectile.h"
#include <vector>
Player::Player(Ogre::Entity * entity, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity, inital_pos, inital_dir)
{}

Projectile * Player::fireProjectile(Ogre::SceneManager * manager)
{
	Ogre::Entity * new_entity = 0;

	return new Projectile(new_entity, this -> pos, Ogre::Vector3(1, 0, 0));
}

std::vector<Ogre::Entity *> Player::collision(Ogre::RaySceneQuery * query)
{
	return std::vector<Ogre::Entity *>();
}

void Player::move(Ogre::RaySceneQuery * query)
{

}

Player::~Player()
{

}
