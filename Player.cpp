#include "Player.h"
#include "Projectile.h"
#include <vector>

using namespace Ogre;

Player::Player(const Ogre::String & entity_name, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity_name, inital_pos, inital_dir)
{
    pitch = Radian(Degree(0));
}

Projectile * Player::fireProjectile(Ogre::SceneManager * manager)
{
	Ogre::String new_entity_name;

	return new Projectile(new_entity_name, this -> pos, Ogre::Vector3(1, 0, 0));
}

std::vector<Ogre::String> Player::collision(Ogre::RaySceneQuery * query)
{
	return std::vector<Ogre::String>();
}

void Player::moveTo(Vector3 pos, SceneManager * manager)
{
    this -> pos = pos;
    manager -> getSceneNode(this -> entity_name + "Node") -> setPosition(pos);
}

void Player::move(Ogre::SceneManager * manager, Ogre::RaySceneQuery * query, Ogre::Camera * camera)
{
    // First normalize the direction vector
    this->dir.normalise();

    // Move the player in the normalized direction multipled by maximum movement speed
    moveTo(dir + this->pos, manager);
    //manager -> getSceneNode(this -> entity_name + "Node") -> moveTo(dir);
}

void Player::rotatePitch(SceneManager * manager) 
{
    // Check y position
    if (dir[1] > 0) {
        if (this -> pitch < Radian(Degree(30))) {
            this -> pitch += Radian(Degree(2));
        }
    } else if (dir[1] < 0) {

    } else {// dir[1] == 0

    }
    (manager -> getSceneNode(this -> entity_name + "Node")) -> pitch( Radian(Degree(20)));
}

Player::~Player()
{

}
