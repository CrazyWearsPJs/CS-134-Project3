#ifndef ENTITY_H
#define ENTITY_H

#include "BaseApplication.h"
#include <vector>
#include <string>
class GameEntity {

	public:
	Ogre::String entity_name;

	protected:
		Ogre::Vector3 pos;
		Ogre::Vector3 dir;

		virtual std::vector<Ogre::String> collision(Ogre::RaySceneQuery * query) = 0;

	public:

		GameEntity(const Ogre::String & entity_name, Ogre::Vector3 inital_pos,
					Ogre::Vector3 inital_dir)
			:entity_name(entity_name), pos(inital_pos), dir(inital_dir)
		{}

		virtual void move(Ogre::SceneManager *, Ogre::RaySceneQuery *, Ogre::Camera *) = 0;

		virtual ~GameEntity()
		{}
};
#endif // ENTITY_H
