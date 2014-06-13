#include "Enemy.h"
#include "Projectile.h"
#include <vector>
#include <sstream>
#include <cmath>

using namespace Ogre;


Enemy::Enemy(const  Ogre::String & entity_name, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO, 
                                                Ogre::Vector3 inital_center = Ogre::Vector3::ZERO,
					                            Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO, 
                                                enemy_type type = STRAIGHT,
                                                int life = 3)
			:GameEntity(entity_name, inital_pos,  inital_dir), type(type), center(inital_center), life(life), outOfBounds(false)
{
    vel = Vector3::ZERO;
	++Enemy::id;
}
void Enemy::setOutOfBounds()
{
    outOfBounds = true;
}

bool Enemy::isOutOfBounds()
{
    return outOfBounds;
}

int Enemy::getShot() {
    return --life;
}

bool Enemy::isDead() {
    return life <= 0;
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

void Enemy::move(Ogre::SceneManager * manager, Ogre::RaySceneQuery * query, Ogre::Camera * camera, Vector3 playerPos)
{
    Vector3 newPos(0,0,0);
    Vector3 acc(0,0,0);
    if (type == STRAIGHT) {
        newPos = pos + dir;
    } else if (type == SINE) {
        (this->vel).y -= 0.0008 * (this->pos.y - this->center.y);
        newPos = pos + vel + dir;
    } else if (type == TRACKER) {
        acc = playerPos - this->pos;
        acc.normalise();
        //acc = (playerPos - this->pos).normalise();
        if (this->vel.length() > 0.7) {
            vel.normalise();
            vel *= 0.7;
        }
        (this->vel) += acc * 0.03;
    }

    // The actual movement, same for all
    newPos = pos + vel + dir;
    this -> pos = newPos;
    manager -> getSceneNode(this -> entity_name + "Node") -> setPosition(newPos);

    if(this -> pos.x <= -100) setOutOfBounds();

    /*
    Vector3 newPos = pos + dir;
    this -> pos = newPos;
	return;
    */
}

Enemy::~Enemy()
{

}
