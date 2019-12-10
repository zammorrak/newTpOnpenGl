//
// Created by ssohy on 12/9/2019.
//

#ifndef MONPROJETSDL_ENTITY_H
#define MONPROJETSDL_ENTITY_H

#include "../Utils/Include.h"


class Entity {      //An entity is just that, an Entity, a being, either a player or an AI

protected:
    //Base Variables
    float isAlive;
    float speed = 0;
    double hp;
    glm::vec3 position; //(xf,yf,zf)
    glm::vec3 direction;
    
    float canonSpeed = 0;
    float rotation = 0;
    float canonRotation = 0;
    float fireRate = 0;
    
public:
    
    Entity(const glm::vec3 &position);
    
    //Geter/Setter
    float getIsAlive() const;
    
    void setIsAlive(float isAlive);
    
    float getSpeed() const;
    
    void setSpeed(float speed);
    
    virtual const glm::vec3 &getPos() const;
    
    int getType() const;
    
    void setType(int type);
    
    float getCanonSpeed() const;
    
    void setCanonSpeed(float canonSpeed);
    
    virtual float getRotation() const;
    
    virtual void setRotation(float rotation);
    
    virtual float getCanonRotation() const;
    
    virtual void setCanonRotation(float canonRotation);
    
    float getFireRate() const;
    
    void setFireRate(float fireRate);
    
    double getHp() const;
    
    void setHp(double hp);
    
    
    virtual void movement();
    
    virtual void drawEntity();
    //called everytime an entity shoots
    void shoot(int type);
    
    void gotHit();
    
    void isDead();
    
    
    virtual void setPos(const glm::vec3 &pos);
    
};


#endif //MONPROJETSDL_ENTITY_H
