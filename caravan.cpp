/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Nathalie Herzog
 * Due Date:		8th January, 2019
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

#include "caravan.h"
#include "pack_animal.h"
#include <stdlib.h>
#include <stdio.h>
#include "general.h"

struct Node *head;

Caravan new_caravan()
{
  Caravan caravan = (Caravan)malloc(sizeof(caravan));

  caravan->length = 0;
  caravan->loadC = 0;

  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  for (int i = 0; i < caravan->length; i++)
  {
    Node *temp = caravan->head;
    caravan->head = temp->next;
    sfree(temp);
  }

  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if ((animal == 0) || (animal->caravan == caravan))
  {
    return;
  }

  struct Node *current = (struct Node *)malloc(sizeof(struct Node));

  animal->caravan = caravan;

  current->data = animal;
  current->next = caravan->head;
  caravan->head = current;

  caravan->length++;
  caravan->loadC += animal->load;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  struct Node *current = caravan->head;
  struct Node *temp = current->next;

  if ((animal == 0) || (current == 0))
  {
    return;
  }

  animal->caravan = 0;

  if (current->data == animal)
  {
    caravan->head = current->next;
    sfree(current);
    return;
  }

  while ((current->next != 0) && (current->next->data != animal))
  {
    current = current->next;
  }

  if (current->next == 0)
  {
    return;
  }
  current->next = temp->next;
  sfree(temp);

  caravan->length--;
  caravan->loadC -= animal->load;
}

int get_caravan_load(Caravan caravan)
{
  return caravan->loadC;
}

void unload(Caravan caravan)
{
  int length = get_length(caravan);

  Node *current = caravan->head;

  caravan->loadC = 0;

  for (int i = 0; i < length; i++)
  {
    current->data->load = 0;
    current = current->next;
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
