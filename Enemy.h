#ifndef ENEMY_H
#define ENEMY_H

#include "Projectile.h"

using namespace Ogre;

enum enemy_type{STRAIGHT, SINE, LOOP, TRACKER};
class Enemy: public GameEntity {
	private:
		std::vector<Ogre::String> collision(Ogre::RaySceneQuery *);
		static int id;
        enemy_type type;
        Vector3 center;
        int life;
        bool outOfBounds;
    public:
		Enemy(const Ogre::String &, Ogre::Vector3, Ogre::Vector3, Ogre::Vector3, enemy_type, int);

        void setOutOfBounds();

        bool isOutOfBounds();

        int getShot();

        bool isDead();

		Projectile * fireProjectile(Ogre::SceneManager *);

		static Ogre::String get_next_name();

		void move(Ogre::SceneManager *, Ogre::RaySceneQuery *, Ogre::Camera *, Vector3);

		~Enemy();
};
#endif // ENEMY_H

