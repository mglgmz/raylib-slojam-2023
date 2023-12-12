#ifndef ENTITY_LIST_H
#define ENTITY_LIST_H

#include <stdlib.h>
#include <raylib.h>

typedef struct
{
    float x;
    float y;
    float dx;
    float dy;
    float speed;
    int size;
    int shape;
    float rotation;
    float ttl;
    int active;
} Entity;

typedef struct
{
    Entity *array;
    size_t size;
    size_t used;
} EntityList;

void EntityList_Init(EntityList *list, int inicialCapacity);
void EntityList_Add(EntityList *list, Entity *entity);
void EntityList_Delete(EntityList *list, int index);
void EntityList_Free(EntityList *list);

#endif