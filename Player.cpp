#include "Player.h"
#include "Projectile.h"
#include <vector>

using namespace Ogre;

Player::Player(const Ogre::String & entity_name, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity_name, inital_pos, inital_dir)
{
    pitch = 0;
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
    // Trying to move Left or Right
    if ((dir.x > 0 && this->pos.x > 60) || (dir.x <0 && this->pos.x < -58)) {
        dir.x = 0;
    }

    // Trying to move Up or Down
    if ((dir.y > 0 && this->pos.y > 38) || (dir.y <0 && this->pos.y < -37)) {
        dir.y = 0;
    }

    // First normalize the direction vector
    this->dir.normalise();

    // Move the player in the normalized direction multipled by maximum movement speed
    moveTo(dir + this->pos, manager);
    //manager -> getSceneNode(this -> entity_name + "Node") -> moveTo(dir);
}

void Player::rotatePitch(SceneManager * manager) 
{
    // Check y position
    if (dir.y > 0) {
        if ((this -> pitch) < 30) {
            this -> pitch += 2;
            (manager -> getSceneNode(this -> entity_name + "Node")) -> pitch( Radian(Degree(-2)));
        }
    } else if (dir.y < 0) {
        if ((this -> pitch) > -30) {
            this -> pitch -= 2;
            (manager -> getSceneNode(this -> entity_name + "Node")) -> pitch( Radian(Degree(2)));
        }
    } else {// dir[1] == 0
        if ((this -> pitch) > 0) {
            this -> pitch -= 2;
            (manager -> getSceneNode(this -> entity_name + "Node")) -> pitch( Radian(Degree(2)));
        } else if ((this -> pitch) < 0){
            this -> pitch += 2;
            (manager -> getSceneNode(this -> entity_name + "Node")) -> pitch( Radian(Degree(-2)));
            
        }
    }
}

Player::~Player()
{

}
