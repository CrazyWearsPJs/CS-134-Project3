#ifndef ENEMY_H
#define ENEMY_H

#include "Projectile.h"

class Enemy: public GameEntity {
	private:
		std::vector<Ogre::String> collision(Ogre::RaySceneQuery *);
		static int id;

	public:
		Enemy(const Ogre::String &, Ogre::Vector3, Ogre::Vector3);

		Projectile * fireProjectile(Ogre::SceneManager *);

		static Ogre::String get_next_name();

		void move(Ogre::SceneManager *, Ogre::RaySceneQuery *, Ogre::Camera *);

		~Enemy();
};
#endif // ENEMY_H
