#include "Projectile.h"
#include <string>
#include <sstream>

Projectile::Projectile(const Ogre::String & entity_name, Ogre::Vector3 inital_pos = Ogre::Vector3::ZERO,
					Ogre::Vector3 inital_dir = Ogre::Vector3::ZERO)
			:GameEntity(entity_name, inital_pos, inital_dir)
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


void Projectile::move(Ogre::SceneManager * manager, Ogre::RaySceneQuery * RaySceneQuery, Ogre::Camera * camera)
{
	return;
}

std::vector<Ogre::String> Projectile::collision(Ogre::RaySceneQuery *)
{
	return std::vector<Ogre::String>();
}

Projectile::~Projectile()
{

}
