#include "entity_list.h"

void EntityList_Init(EntityList *list, int initialCapacity)
{
    Entity *entities;
    entities = malloc(sizeof(Entity) * initialCapacity);
    if (entities == NULL)
    {
        TraceLog(LOG_ERROR, "Unable to allocate memory");
        free(entities);
        exit(0);
    }
    else
    {
        list->array = entities;
        list->size = initialCapacity;
        list->used = 0;
    }
}

void EntityList_Add(EntityList *list, Entity *entity)
{
    Entity *entities;
    list->used += 1;

    if (list->used >= list->size)
    {
        list->size = list->size * 2;
        entities = (Entity *)realloc(list->array, list->size * sizeof(Entity));
        if (entities == NULL)
        {
            TraceLog(LOG_ERROR, "Unable to allocate memory");
            free(entities);
            exit(0);
        }
        list->array = entities;
    }
    list->array[list->used - 1] = *entity;
}

void EntityList_Delete(EntityList *list, int index)
{
    int i;
    Entity *entities;
    for (i = index; i < list->size; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->used -= 1;
}

void EntityList_Free(EntityList *list)
{
    free(list->array);
    list->array = NULL;
    list->size = 0;
}