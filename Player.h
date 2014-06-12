#ifndef PLAYER_H
#define PLAYER_H
#include "GameEntity.h"
#include "Projectile.h"
#include <vector>
class Player : public GameEntity{

	private:
		std::vector<Ogre::String> collision(Ogre::RaySceneQuery *);

	public:
		Player(const Ogre::String &, Ogre::Vector3, Ogre::Vector3);

		Projectile * fireProjectile(Ogre::SceneManager *);

		void move(Ogre::SceneManager *, Ogre::RaySceneQuery *, Ogre::SceneManager *, Ogre::Camera *);

		~Player();

};
#endif // PLAYER_H
