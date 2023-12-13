#include "simulation.h"

void UpdateSimulation()
{
    EntityList *asteroids = GetAsteroids();
    EntityList *bullets = GetBullets();
    Player *player = GetPlayer();

    float dt = GetFrameTime();
    for (int i = 0; i < asteroids->used; i++)
    {
        Entity *asteroid = &asteroids->array[i];

        asteroid->x += asteroid->dx * dt;
        asteroid->y += asteroid->dy * dt;

        WrapPosition(&asteroid->x, &asteroid->y);
    }

    for (int j = 0; j < asteroids->used; j++)
    {
        Entity *asteroid = &asteroids->array[j];

        for (int i = 0; i < bullets->used; i++)
        {
            Entity *bullet = &bullets->array[i];
            if(!bullet->active) continue;
            if (IsPointInsideCircle(bullet->x, bullet->y, asteroid->x, asteroid->y, asteroid->size))
            {
                asteroid->active = 0;
                bullet->active = 0;
                 OnAsteroidHit(asteroid, bullet->x, bullet->y);
                if (asteroid->size > ASTEROID_BASE_SIZE)
                {
                    float halfSize = asteroid->size / 2;
                    // spawn new asteroids
                    SpawnAsteroid(
                        asteroid->x + GetRandomValue(-halfSize, halfSize),
                        asteroid->y + GetRandomValue(-halfSize, halfSize),
                        asteroid->size / 2,
                        asteroid->speed,
                        GetRandomValue(0, 360));
                    SpawnAsteroid(
                        asteroid->x + GetRandomValue(-halfSize, halfSize),
                        asteroid->y + GetRandomValue(-halfSize, halfSize),
                        asteroid->size / 2,
                        asteroid->speed,
                        GetRandomValue(0, 360));
                }
            }
        }

        if (player->currentLife > 0 && asteroid->active && IsPointInsideCircle(player->x, player->y, asteroid->x, asteroid->y, asteroid->size))
        {
            HitPlayer(player, 1);
            OnAsteroidHit(asteroid, player->x, player->y);
            // TODO: damage based on asteroid->size
        }
    }

    if (player->currentLife <= 0)
    {
        // GAME OVER
    }

    for (int i = asteroids->used - 1; i >= 0; i--)
    {
        if (asteroids->array[i].active == 0)
            EntityList_Delete(asteroids, i);
    }

    if (bullets->used > 0)
        for (int i = bullets->used - 1; i >= 0; i--)
        {
            Entity *bullet = &bullets->array[i];

            if (!bullet->active || WrapPosition(&bullet->x, &bullet->y) > 0)
                EntityList_Delete(bullets, i);
            else
            {
                bullet->x += bullet->dx * dt;
                bullet->y += bullet->dy * dt;
            }
        }
}