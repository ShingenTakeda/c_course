#pragma once
#include <stdint.h>
#include "vector.h"

//make this a bitset ECS, even thought it sucks

typedef uint64_t ENTITY_ID;
typedef uint64_t ARCHTYPE_ID;
typedef ENTITY_ID COMPONENT_ID;

typedef struct
{
	ENTITY_ID entities;
	Vector_t *entidades_mortas;
	Vector_t *matrix_componentes;
}ECS_World_t;

ECS_World_t *ecs_world_init();
uint8_t *get_entity_component(ECS_World_t *world, COMPONENT_ID component);
