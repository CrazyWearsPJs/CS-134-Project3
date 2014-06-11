#ifndef PLAYER_H
#define PLAYER_H
#include "GameEntity.h"
#include "Projectile.h"
class Player : public GameEntity{

	private:

		Player(Ogre::Entity *, Ogre::Vector3, Ogre::Vector3);

	public:

		Projectile * fireProjectile();

		void move(Ogre::RaySceneQuery * RaySceneQuery);

		~Player();

};
#endif // PLAYER_H
