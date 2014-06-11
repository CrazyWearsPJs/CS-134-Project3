#ifndef ENEMY_H
#define ENEMY_H

#include "Projectile.h"

class Enemy: public GameEntity {
	private:

		Enemy(Ogre::Entity *, Ogre::Vector3, Ogre::Vector3);

	public:

		Projectile * fireProjectile();

		void move(Ogre::RaySceneQuery *);

		~Enemy();
};
#endif // ENEMY_H
