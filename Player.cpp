#include "Player.h"
#include "Projectile.h"
#include <vector>
Player::Player(const Ogre::String & entity_name, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity_name, inital_pos, inital_dir)
{}

Projectile * Player::fireProjectile(Ogre::SceneManager * manager)
{
	Ogre::String new_entity_name;

	return new Projectile(new_entity_name, this -> pos, Ogre::Vector3(1, 0, 0));
}

std::vector<Ogre::String> Player::collision(Ogre::RaySceneQuery * query)
{
	return std::vector<Ogre::String>();
}

void Player::move(Ogre::SceneManager * manager, Ogre::RaySceneQuery * query, Ogre::Camera * camera)
{

}

Player::~Player()
{

}
