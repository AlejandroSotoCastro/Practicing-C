#include <string.h>
#include <windows.h>
#include <stdio.h>

//RANDOM:
#include <time.h>
#include <stdlib.h>


// Camelleria


// Redefinir el tipo "unsigned int" a "uint" para tener que escribir menos:
typedef unsigned int uint;

// Crear la estructura camello:
typedef struct cam{
   char nombre[16];
   float chele;
   float caudal;
};
cam camello;

char *nombres[8] = {"Manolo", "Pepe", "Romualdo", "Misifu", "Celeutereo", "Proscojoncio", "Prepuciancio", "Macarron"};

// Funcion para poblar la estructura:
void iniciarCamello(camello *cam, uint i){
   strcpy(cam->nombre, nombres[i]);
   cam->chele = 0.f;
   float random = (rand() % 1000) / 10000.f;
   cam->caudal = random;
}

void renderCamello(camello *cam){
   char chele[33];
   uint cheleValor = (uint)(cam->chele * 32.f);
   for(uint i = 0; i < cheleValor; i++){
      chele[i] = '#';
   }
   for(uint i = cheleValor; i < 32; i++){
      chele[i] = '-';
   }
   printf("Camello %s:\n   Chele: [%s] %fl\n\n", cam->nombre, chele, cam->chele);
}

void renderTotal(float total){
   printf("\nChele total cosechada: %f litros\n", total);
}

#define N_CAMELLOS 8

// total de chele acumulada:
float chele_total = 0.f;



int main(){

   // Iniciar con un seed el generador de numeros aleatorios:
   srand(time(NULL));

   // Crear un array de punteros a camello:
   camello camellos[N_CAMELLOS];

   // Iniciar y asignar camellos a los elementos del array:
   for(uint i = 0; i < N_CAMELLOS; i++){

      camello tempCamello;
      iniciarCamello(&tempCamello, i);
      camellos[i] = tempCamello;

   }

   // Blucle infinito:
   while(1){

      system("cls");

      // Loopear por cada camello:
      for(uint i = 0; i < N_CAMELLOS; i++){

         // Aumentar la chele acumulada sumando su caudal:
         camellos[i].chele += camellos[i].caudal;

         // Si tiene mas de un litro:
         if(1.f < camellos[i].chele){

            // Ordeñar al camello:
            chele_total += camellos[i].chele;
            camellos[i].chele = 0.f;

         }

         renderCamello(&camellos[i]);
      }

      renderTotal(chele_total);
      
      // Esperar 500ms:
      Sleep(500);
   }
}