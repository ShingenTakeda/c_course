#pragma once
#include <stdint.h>
#include "vector.h"

//make this a bitset ECS, even thought it sucks

typedef uint64_t ENTITY_ID;
typedef ENTITY_ID COMPONENT_ID;

typedef struct
{
	ENTITY_ID entities;
	COMPONENT_ID components;
	Vector_t *entidades_mortas;
	Vector_t *matrix_componentes;
}ECS_World_t;

ECS_World_t *world_init();
ENTITY_ID create_entity(ECS_World_t *world);
COMPONENT_ID register_component(ECS_World_t *world, void *component);
uint8_t *get_entity_component(ECS_World_t *world, ENTITY_ID entity_id,COMPONENT_ID component_id);
void world_free(ECS_World_t *world);
