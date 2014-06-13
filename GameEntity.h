#ifndef ENTITY_H
#define ENTITY_H

#include "BaseApplication.h"
#include <vector>
#include <string>

using namespace Ogre;

class GameEntity {

	public:
		Ogre::String entity_name;
		Ogre::Vector3 pos;
		Ogre::Vector3 dir;
        Ogre::Vector3 vel;

		virtual std::vector<Ogre::String> collision(Ogre::RaySceneQuery * query) = 0;


		GameEntity(const Ogre::String & entity_name, Ogre::Vector3 inital_pos,
					Ogre::Vector3 inital_dir)
			:entity_name(entity_name), pos(inital_pos), dir(inital_dir)
		{}

		virtual void move(Ogre::SceneManager *, Ogre::RaySceneQuery *, Ogre::Camera *)
        {}

		virtual ~GameEntity()
		{}
};
#endif // ENTITY_H
