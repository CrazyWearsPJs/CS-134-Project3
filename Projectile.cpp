#include "Projectile.h"
#include <string>
#include <sstream>

using namespace Ogre;

Projectile::Projectile(const Ogre::String & entity_name, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity_name, inital_pos, inital_dir), is_used(false)
{
	++Projectile::id;
}

int Projectile::id = 0;

Ogre::String Projectile::get_next_name()
{
	Ogre::StringStream ss;
	ss << Projectile::id;
	return "Projectile" + ss.str();
}


void Projectile::move(Ogre::SceneManager * manager, Ogre::RaySceneQuery * RaySceneQuery, Ogre::Camera * camera, double player_projectile_speed)
{
    this->dir.normalise();
    Vector3 newPos = this -> pos + (this -> dir * player_projectile_speed);
    //Vector3 newPos = this -> pos + Vector3(player_projectile_speed, 0, 0);
    this -> pos = newPos;
    manager -> getSceneNode(this -> entity_name + "Node") -> setPosition(newPos);
	if(this -> pos.x > 60) is_used = true;
    return;
}

std::vector<Ogre::String> Projectile::collision(Ogre::RaySceneQuery *)
{
	return std::vector<Ogre::String>();
}

Projectile::~Projectile()
{

}
