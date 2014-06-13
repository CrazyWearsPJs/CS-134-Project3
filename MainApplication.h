/*
-----------------------------------------------------------------------------
Filename:    %ProjectName:l%.%CppHeaderSuffix%
-----------------------------------------------------------------------------


This source file is generated by the
   ___                   _              __    __ _                  _ 
  /___\__ _ _ __ ___    /_\  _ __  _ __/ / /\ \ (_)______ _ _ __ __| |
 //  // _` | '__/ _ \  //_\\| '_ \| '_ \ \/  \/ / |_  / _` | '__/ _` |
/ \_// (_| | | |  __/ /  _  \ |_) | |_) \  /\  /| |/ / (_| | | | (_| |
\___/ \__, |_|  \___| \_/ \_/ .__/| .__/ \/  \/ |_/___\__,_|_|  \__,_|
      |___/                 |_|   |_|                                 
      Ogre 1.8.x Application Wizard for QtCreator (May 2012)
      https://bitbucket.org/jacmoe/ogreappwizards
-----------------------------------------------------------------------------
*/
#ifndef __MainApplication_h__
#define __MainApplication_h__

#include "BaseApplication.h"
#include "GameEntity.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

#include <vector>

class MainApplication: public BaseApplication
{
public:
    MainApplication(void);
    virtual ~MainApplication(void);

protected:


    long long timer;


    virtual void createScene(void);
    virtual bool frameRenderingQueued(const Ogre::FrameEvent &);
    virtual bool processUnbufferedInput(const Ogre::FrameEvent &);

    // OIS::KeyListener
    virtual bool keyPressed( const OIS:: KeyEvent& evt);
    virtual bool keyReleased( const OIS:: KeyEvent& evt);

    Ogre::Entity * mEntity;
    Ogre::Entity * mEntity2;

    Ogre::SceneNode * mNode;
    Ogre::SceneNode * mNode2;

    Ogre::RaySceneQuery * mQuery;

    void processEnemy();
    void spawnEnemy(Vector3, Vector3, Vector3, enemy_type);

    void setupPlayer();

    void destroyEntities();

    void reset();

    void collisionDetectionProjectile();
   
    void collisionDetectionPlayerEnemyHelper(Vector3 rayPos);

    void collisionDetectionPlayerEnemy();

    void cleanUpProjectiles();

    void cleanUpEnemies();

    void destroyGameEntity(GameEntity *);

    void createHeroProjectile(Vector3, Vector3, Degree);


    Player * mHero;

    std::vector<Enemy *> mEnemies; 

    std::vector<Projectile *> mHeroProjectiles;

    std::vector<Projectile *> mEnemyProjectiles;
};

#endif

