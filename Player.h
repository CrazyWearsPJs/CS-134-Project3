#ifndef PLAYER_H
#define PLAYER_H
#include "GameEntity.h"
#include "Projectile.h"
#include <vector>
class Player : public GameEntity{

	private:
		std::vector<Ogre::Entity *> collision(Ogre::RaySceneQuery *);

	public:
		Player(Ogre::Entity *, Ogre::Vector3, Ogre::Vector3);

		Projectile * fireProjectile(Ogre::SceneManager *);

		void move(Ogre::RaySceneQuery *);

		~Player();

};
#endif // PLAYER_H
