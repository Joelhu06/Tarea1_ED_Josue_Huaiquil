#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct 
{
    int ID;
    char descripcion[500];
    char prioridad[20];
    int hora;
    int minuto;
    int segundo;
}Ticket;

void mostrarMenuPrincipal()
{
  printf("========================================\n");
  printf("     SISTEMA DE GESTION DE TICKETS\n");
  printf("========================================\n");

  printf("LISTADO DE OPCIONES:\n");
  printf("- OPCION 1: REGISTRAR NUEVO TICKET.\n");
  printf("- OPCION 2: FINALIZAR REGISTRO.\n");

  printf("========================================\n\n");
}

void registrarTicket(List *tickets)
{
  int ID_Dato;
  char descrip_Dato[500];
  Ticket *dataTicket = (Ticket*)malloc(sizeof(Ticket));
  time_t tiempoActual = time(NULL);
  struct tm *tiempo = localtime(&tiempoActual);

  printf("\n");
  printf("Ingrese el ID (NUMERICA) del Ticket: ");
  scanf("%d", &ID_Dato);
  getchar();

  if (ID_Dato == 0) return;
  else
  {
    printf("Ingrese la descripcion del Ticket: ");
    scanf("%[^\n]", descrip_Dato);
    getchar();

    (*dataTicket).ID = ID_Dato;
    strcpy((*dataTicket).descripcion, descrip_Dato);
    strcpy((*dataTicket).prioridad, "Bajo");

    (*dataTicket).hora = (*tiempo).tm_hour;
    (*dataTicket).minuto = (*tiempo).tm_min;
    (*dataTicket).segundo = (*tiempo).tm_sec;

    list_pushBack(tickets, dataTicket);

    printf("Ticket registrado con prioridad BAJA y hora %02d:%02d:%02d\n\n",
      (*dataTicket).hora, (*dataTicket).minuto, (*dataTicket).segundo);
  }
}

void asignarPrioridad(List *tickets)
{
    Ticket *elemento = list_first(tickets);
    char nPrioridad[20];

    while (elemento != NULL)
    {
      while (1)
      {
          printf("Ingrese la prioridad (Bajo, Medio, Alto) para el ticket con ID %d: ", (*elemento).ID);
          scanf("%[^\n]", nPrioridad);
          getchar();

          if (strcmp(nPrioridad, "Bajo") != 0 && strcmp(nPrioridad, "Medio") != 0 && strcmp(nPrioridad, "Alto") != 0)
          {
              printf("PRIORIDAD INVALIDA\n");
              continue;
          }

          strcpy((*elemento).prioridad, nPrioridad);
          break;
      }
      elemento = list_next(tickets);
    }
}

void cambioLista(List *tickets, List *nueva, char *text)
{
  Ticket *elemento = list_first(tickets);
  while (elemento != NULL)
  {
    if (strcmp((*elemento).prioridad, text) == 0) list_pushBack(nueva, elemento);
    elemento = list_next(tickets);
  }
}

void mostrarListaTickets(List *tickets, char *text)
{
  printf("Tickets con prioridad %s: \n", text);
  Ticket *elemento = list_first(tickets);
  if (elemento == NULL) printf("- NO HAY TICKETS CON PRIORIDAD %s\n", text);
  while (elemento != NULL)
  {
    printf("-ID: %d\n", (*elemento).ID);
    elemento = list_next(tickets);
  }
}

void procesarSiguiente(List *lista)
{
  Ticket *primero = list_first(lista);
  if (primero == NULL)
  {
    printf("No hay tickets para procesar en esta lista.\n");
    return;
  }
  printf("DATOS TICKET A PROCESAR:\n");
  printf("- ID: %d\n- DESCRIPCION: %s\n- PRIORIDAD: %s\n", (*primero).ID, (*primero).descripcion, (*primero).prioridad);
  printf("- HORA: %02d:%02d:%02d\n\n", (*primero).hora, (*primero).minuto, (*primero).segundo);

  list_popFront(lista);
}

void buscarID(List *lista, int ID)
{
  Ticket *elemento = list_first(lista);
  while (elemento != NULL)
  {
    if (ID == (*elemento).ID)
    {
      printf("DATOS TICKET BUSCADO:\n");
      printf("- ID: %d\n- DESCRIPCION: %s\n- PRIORIDAD: %s\n", (*elemento).ID, (*elemento).descripcion, (*elemento).prioridad);
      printf("- HORA: %02d:%02d:%02d\n\n", (*elemento).hora, (*elemento).minuto, (*elemento).segundo);
      break;
    }
    else elemento = list_next(lista);
  }
  if (elemento == NULL) printf("ID NO ESCONTRADA");
}

int main() 
{
  List *tickets = list_create();
  mostrarMenuPrincipal();

  while (1)
  {
    char opcion[20];
    printf("SELECCIONE UNA OPCION (1, 2): ");
    scanf("%[^\n]", opcion);
    getchar();

    if (strcmp(opcion, "1") == 0) registrarTicket(tickets);
    else if (strcmp(opcion, "2") == 0) break;
    else printf("ACCION INVALIDA\n\n");
  }
  printf("\nFIN DEL REGISTRO\n\n");
  printf("========================================\n\n");

  if (list_first(tickets) != NULL) 
  {
    printf("ASIGNACION DE PRIORIDAD\n\n");
    
    asignarPrioridad(tickets);  
    printf("\n========================================\n\n");

    List *tAlto = list_create();
    List *tMedio = list_create(); 
    List *tBajo = list_create();

    cambioLista(tickets, tBajo, "Bajo");
    cambioLista(tickets, tMedio, "Medio");
    cambioLista(tickets, tAlto, "Alto");

    list_clean(tickets);

    printf("LISTAS TICKETS PENDIENTES: \n");
    mostrarListaTickets(tAlto, "ALTA");
    mostrarListaTickets(tMedio, "MEDIA");
    mostrarListaTickets(tBajo, "BAJA");

    printf("\n========================================\n\n");

    if (list_first(tAlto) != NULL) procesarSiguiente(tAlto);
    else if (list_first(tMedio) != NULL) procesarSiguiente(tMedio);
    else if (list_first(tBajo) != NULL) procesarSiguiente(tBajo);

    printf("========================================\n\n");

    int id;
    printf("BUSQUEDA POR ID\n");
    printf("\nINGRESE LA ID A BUSCAR: ");
    scanf("%d", &id);
    if (list_first(tAlto) != NULL) buscarID(tAlto, id);
    else if (list_first(tMedio) != NULL) buscarID(tMedio, id);
    else if (list_first(tBajo) != NULL) buscarID(tBajo, id);
    else printf("ID NO ESCONTRADA");

    list_clean(tAlto);
    list_clean(tMedio);
    list_clean(tBajo);
  }
  else printf("NO SE INGRESARON TICKETS");

  return 0;
}