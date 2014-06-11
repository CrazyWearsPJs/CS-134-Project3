#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameEntity.h"
class Projectile : public GameEntity
{
	private:

		Projectile(Ogre::Entity *, Ogre::Vector3, Ogre::Vector3);

	public:

		void move(Ogre::RaySceneQuery *);

		~Projectile();
};
#endif // PROJECTILE_H
