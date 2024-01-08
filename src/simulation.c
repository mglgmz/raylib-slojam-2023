#include "simulation.h"
#include "renderer.h"
#include "drop_system.h"
#include "score.h"

static Sound explosionSound;

void InitSimulation(void) {
    explosionSound = LoadSound("resources/sounds/effects/explosion.wav");
    SetSoundVolume(explosionSound, 0.4f);
}

void ReleaseSimulation(void) {
    UnloadSound(explosionSound);
}

void UpdateSimulation(void)
{
    AsteroidList *asteroids = GetAsteroids();
    EntityList *bullets = GetBullets();
    Player *player = GetPlayer();

    float dt = GetFrameTime();
    for (int i = 0; i < asteroids->used; i++)
    {
        Asteroid *asteroid = &asteroids->array[i];
        asteroid->rotation = asteroid->rotation + asteroid->rotationSpeed * dt;
        NormalizeAngle(&asteroid->rotation);
        asteroid->x += asteroid->dx * dt;
        asteroid->y += asteroid->dy * dt;

        
        if(player->apocaplipsis) {
            asteroid->active = 0;
            OnAsteroidHit(asteroid, asteroid->x, asteroid->y);
            RollDrop(ASTEROID, asteroid->size, asteroid->x, asteroid->y);
            AddScore(asteroid->size);
        }

        WrapPosition(&asteroid->x, &asteroid->y, asteroid->size);
    }

    player->apocaplipsis = 0;

    for (int j = 0; j < asteroids->used; j++)
    {
        Asteroid *asteroid = &asteroids->array[j];
        if(!asteroid->active) continue;
        int bulletsUsed = bullets->used;
        for (int i = 0; i < bulletsUsed; i++)
        {
            Entity *bullet = &bullets->array[i];
            if (!bullet->active)
                continue;
            if (IsPointInsideCircle(bullet->x, bullet->y, asteroid->x, asteroid->y, asteroid->size))
            {
                OnAsteroidHit(asteroid, bullet->x, bullet->y);
                AddScore(asteroid->size);
                OnBulletHit(bullet);
                RollDrop(ASTEROID, asteroid->size, asteroid->x, asteroid->y);
            }
        }

        if (player->currentLife > 0 && asteroid->active && IsPointInsideCircle(player->x, player->y, asteroid->x, asteroid->y, asteroid->size))
        {
            // TODO: damage based on asteroid->size
            HitPlayer(player, 1);
            ShakeScreen(30);
            OnAsteroidHit(asteroid, player->x, player->y);
        }
    }

    for (int i = asteroids->used - 1; i >= 0; i--)
    {
        if (asteroids->array[i].active == 0) {
            DespawnAsteroid(i);
            PlaySound(explosionSound);
        }
    }

    if (bullets->used > 0)
        for (int i = bullets->used - 1; i >= 0; i--)
        {
            Entity *bullet = &bullets->array[i];

            if (!bullet->active || WrapPosition(&bullet->x, &bullet->y, 0) > 0)
                EntityList_Delete(bullets, i);
            else
            {
                bullet->x += bullet->dx * dt;
                bullet->y += bullet->dy * dt;
            }
        }
}