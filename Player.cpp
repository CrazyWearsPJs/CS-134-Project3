#include "Player.h"
#include "Projectile.h"

Player::Player(Ogre::Entity * entity, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity, inital_pos, inital_dir)
{}

Projectile * Player::fireProjectile()
{
	return 0;
}

void Player::move(Ogre::RaySceneQuery * RaySceneQuery)
{
	return;
}

Player::~Player()
{

}
