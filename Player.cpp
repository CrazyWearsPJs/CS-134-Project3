#include "Player.h"
#include "Projectile.h"
#include <vector>

using namespace Ogre;

Player::Player(const Ogre::String & entity_name, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity_name, inital_pos, inital_dir), alive(true)
{
    coins_collected = 0;
    pitch = 0;
    shot_rate = default_shot_rate;
    projectile_speed = default_projectile_speed;
    triple_shot = false;
}

void Player::collectCoin() {
    ++coins_collected;
}

int Player::getCoins() {
    return coins_collected;
}

void Player::setTripleShot() {
    triple_shot = true;
}

bool Player::isTripleShot() {
    return triple_shot;
}

int Player::getShotRate() {
    return shot_rate;
}

void Player::setShotRate(int rate = default_shot_rate) {
    shot_rate = rate;
}

double Player::getProjectileSpeed() {
    return projectile_speed;
}

void Player::setProjectileSpeed(double speed = default_projectile_speed) {
    projectile_speed = speed;
}

void Player::getShot()
{
    alive = false;
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

bool Player::isDead()
{
    return !alive;
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
