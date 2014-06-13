#ifndef PLAYER_H
#define PLAYER_H
#include "GameEntity.h"
#include "Projectile.h"
#include <vector>

using namespace Ogre;

class Player : public GameEntity{

	private:
		std::vector<Ogre::String> collision(Ogre::RaySceneQuery *);
        int pitch;
        bool alive;
        static const int default_shot_rate = 45;
        int shot_rate;
        static const double default_projectile_speed = 1.0;
        double projectile_speed;
        bool triple_shot;
        int coins_collected;
	public:
		Player(const Ogre::String &, Ogre::Vector3, Ogre::Vector3);

        void collectCoin();
        int getCoins();

        void setTripleShot();
        bool isTripleShot();

        int getShotRate();
        void setShotRate(int);

        double getProjectileSpeed();
        void setProjectileSpeed(double);

        void getShot();
		bool isDead();
      
        Projectile * fireProjectile(Ogre::SceneManager *);

        void moveTo(Vector3 pos, SceneManager * manager);

		void move(Ogre::SceneManager *, Ogre::RaySceneQuery *, Ogre::Camera *);

        void rotatePitch(SceneManager * manager);

		~Player();

};
#endif // PLAYER_H
