#ifndef ENTITY_H
#define ENTITY_H

#include "BaseApplication.h"
#include <vector>

class GameEntity {

	protected:

		Ogre::Entity * entity;
		Ogre::Vector3 pos;
		Ogre::Vector3 dir;

		virtual bool collisionWithPlayer(GameEntity * player) = 0;
		virtual bool collisionWithEnemy(GameEntity * enemy) = 0;

	public:

		GameEntity(Ogre::Entity * entity, Ogre::Vector3 inital_pos,
					Ogre::Vector3 inital_dir)
			:entity(entity), pos(inital_pos), dir(inital_dir)
		{}

		virtual void move(Ogre::RaySceneQuery * query) = 0;

		virtual ~GameEntity()
		{

		}
};
#endif // ENTITY_H
