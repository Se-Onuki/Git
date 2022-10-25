#pragma once

#include "Entity.hpp"

#include "PolarCoordinates.hpp"
#include "Vector2.hpp"
#include "Math.hpp"
#include "BaseData.hpp"

#include "Easing.hpp"

#include "Map.hpp"

#include "Enemy.hpp"

#include "Bullet.hpp"

class Player : public Entity
{
public:
    Player();
    using Entity::Entity;

    int bulletCooltime = 0;

    PolarCoordinates nowPolar = { 0,0 };
    PolarCoordinates prePolar = { 0,0 };

    void DrawEntity();

    void EntityMoveInput();
    void EntityUpdate();
    void BulletShooting();

    void EnemyHit();

    void Reset(int count);

    void BossAttackHit();

    bool isInput = false;

    int reverse = 1;

protected:
};

static unsigned int playerCount = 2;

inline void Player::EntityMoveInput() {
    if (isKeyPress(DIK_SPACE)) {
        if (/*isKeyPress(DIK_BACKSPACE) &&*/ velocity.Length() == 0) {
            isInput = true;
            prePolar.theta += Degree2Radian(3 * reverse);
            prePosition = MapCentor + PolarToVector2(prePolar);
        }
 /*       else if (!isKeyPress(DIK_BACKSPACE)) {
            isInput = true;
            prePolar.theta += Degree2Radian(3 * reverse);
            prePosition = MapCentor + PolarToVector2(prePolar);
        }*/


    }
    else if (isKeyRelease(DIK_SPACE)) {
        isInput = false;

        /*
        if (
                (Vector2Difference(PolarToVector2(nowPolar), PolarToVector2(prePolar))).Length()
                >
                (Vector2Difference(PolarToVector2(nowPolar), position)).Length()
           )
        {*/
        velocity = Nomalize(Vector2Difference(position, prePosition)) * speed;

        //}
        /*


        nowPolar = prePolar;
        position = prePosition;
        */

    }
};


inline void Player::EnemyHit() {
    if (velocity.Length() != 0) {
        for (int i = 0; i < EnemyMax; i++) {
            if (enemy[i].isAlive) {
                if (BallCollision(position, radius, enemy[i].position, enemy[i].radius)) {
                    enemy[i].Reset();
                }
            }
        }
    }
}

inline void Player::BulletShooting() {
    for (int i = 0; i < Bullet::BulletMaxCount; i++) {
        if (!Bullet::bullet[i].isAlive) {       //バレットスポーン関数を作る
            Bullet::bullet[i].isAlive = true;
            Bullet::bullet[i].velocity = this->velocity;
            Bullet::bullet[i].position = this->position;

            break;
        }
    }

}