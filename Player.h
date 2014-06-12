#ifndef PLAYER_H
#define PLAYER_H
#include "GameEntity.h"
#include "Projectile.h"
#include <vector>

using namespace Ogre;

class Player : public GameEntity{

	private:
		std::vector<Ogre::String> collision(Ogre::RaySceneQuery *);
        Radian pitch;

	public:
		Player(const Ogre::String &, Ogre::Vector3, Ogre::Vector3);

		Projectile * fireProjectile(Ogre::SceneManager *);

        void moveTo(Vector3 pos, SceneManager * manager);

		void move(Ogre::SceneManager *, Ogre::RaySceneQuery *, Ogre::Camera *);

        void rotatePitch(SceneManager * manager);

		~Player();

};
#endif // PLAYER_H
