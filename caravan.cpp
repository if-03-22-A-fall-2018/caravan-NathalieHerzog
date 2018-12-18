/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Nathalie Herzog
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "caravan.h"
#include <stdio.h>

struct CaravanImplementation
{
  int length;
};

struct Node
{
  int data;
  struct Node* next;
};

Caravan new_caravan()
{
  return 0;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  caravan = 0;
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));

  node->data = 39;
  tail->next = node;
  node->next = 0;
  tail = node;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
}

int get_caravan_load(Caravan caravan)
{
  return 0;
}

void unload(Caravan caravan)
{
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}
