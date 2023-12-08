#include "simulation.h"

void UpdateSimulation()
{
    EntityList* asteroids = GetAsteroids();
    EntityList* bullets = GetBullets();

    for (int i = 0; i < bullets->used; i++)
    {
        Entity *bullet = &bullets->array[i];
        for (int j = 0; j < asteroids->used; j++)
        {
            Entity *asteroid = &asteroids->array[j];
            if (IsPointInsideCircle(bullet->x, bullet->y, asteroid->x, asteroid->y, asteroid->size))
            {
                asteroid->active = 0;
                bullet->active = 0;
                if (asteroid->size > ASTEROID_BASE_SIZE)
                {
                    float halfSize = asteroid->size / 2;
                    // spawn new asteroids
                    SpawnAsteroid(asteroid->x + GetRandomValue(-halfSize,halfSize), asteroid->y + GetRandomValue(-halfSize,halfSize), asteroid->size / 2, asteroid->speed, GetRandomValue(0, 360));
                    
                    SpawnAsteroid(asteroid->x + GetRandomValue(-halfSize,halfSize), asteroid->y + GetRandomValue(-halfSize,halfSize), asteroid->size / 2, asteroid->speed, GetRandomValue(0, 360));
                }
            }
        }
    }

    for (int i = asteroids->used - 1; i >= 0; i--)
    {
        if (asteroids->array[i].active == 0)
            EntityList_Delete(asteroids, i);
    }

     if(bullets->used > 0)
        for(int i = bullets->used - 1; i >= 0; i--){
            Entity *bullet = &bullets->array[i];
            if(!bullet->active ||  WrapPosition(&bullet->x, &bullet->y) > 0)
                EntityList_Delete(bullets, i);
        }
}