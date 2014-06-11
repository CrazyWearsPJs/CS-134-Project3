#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameEntity.h"
class Projectile : public GameEntity
{
	private:
		std::vector<Ogre::Entity *> collision(Ogre::RaySceneQuery *);
	public:

		Projectile(Ogre::Entity *, Ogre::Vector3, Ogre::Vector3);

		void move(Ogre::RaySceneQuery *);

		~Projectile();
};
#endif // PROJECTILE_H
