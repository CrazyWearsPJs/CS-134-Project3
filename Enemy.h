#ifndef ENEMY_H
#define ENEMY_H

#include "Projectile.h"

class Enemy: public GameEntity {
	private:
		std::vector<Ogre::Entity *> collision(Ogre::RaySceneQuery *);

	public:
		Enemy(Ogre::Entity *, Ogre::Vector3, Ogre::Vector3);

		Projectile * fireProjectile(Ogre::SceneManager *);

		void move(Ogre::RaySceneQuery *);

		~Enemy();
};
#endif // ENEMY_H
