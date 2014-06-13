#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameEntity.h"
class Projectile : public GameEntity
{
	private:
		std::vector<Ogre::String> collision(Ogre::RaySceneQuery *);
		static int id;
       
	public:
        bool is_used;
		Projectile(const Ogre::String &, Ogre::Vector3, Ogre::Vector3);

		Ogre::String get_next_name();

		void move(Ogre::SceneManager *, Ogre::RaySceneQuery *, Ogre::Camera *, double);

		~Projectile();
};
#endif // PROJECTILE_H
