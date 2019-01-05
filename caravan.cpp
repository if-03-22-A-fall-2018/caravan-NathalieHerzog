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
#include "pack_animal.h"
#include <stdlib.h>
#include <stdio.h>

struct Node *head;

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(caravan));

  caravan->length = 0;
  caravan->loadC = 0;
  caravan->empty = true;

  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  free(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (head != NULL)
  {
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));

    current = head;

    while (current->next != NULL)
    {
      current = current->next;
    }

    current->next = (struct Node *)malloc(sizeof(struct Node));
    current->next->data = animal;

    caravan->length++;
    caravan->loadC += animal->load;
    animal->caravan = caravan;
  }
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  if (head != NULL)
  {
    struct Node *current = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    current = head;

    while (current != NULL)
    {
      if (current->data->name == animal->name)
      {
        temp = current;
        free(temp);
      }
      current = current->next;
    }

    caravan->length--;

    //maybe delete
    caravan->loadC -= animal->load;
  }
  else
  {
    caravan->empty = true;
  }
}

int get_caravan_load(Caravan caravan)
{
  return caravan->loadC;
}

void unload(Caravan caravan)
{
  struct Node *current = (struct Node *)malloc(sizeof(struct Node));

  caravan->loadC = 0;

  while (current->data->load != '\0')
  {
    current->data->load = 0;
    current->data->load = current->next->data->load;
  }
}

int get_caravan_speed(Caravan caravan)
{
  struct Node *current = (struct Node *)malloc(sizeof(struct Node));
  int caravanSpeed = current->data->max_speed;

  while (current != 0)
  {
    if (current->data->max_speed <= current->next->data->max_speed)
    {
      caravanSpeed = current->data->max_speed;
    }

    current->data = current->next->data;
  }

  return caravanSpeed;
}

/*void optimize_load(Caravan caravan)
{

}*/
