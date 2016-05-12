#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

#include "../ownLibC/screenSystemShow.h"

#define LIMPIARPANTALLA "clear" // "cls" para windows | "clear" para linux

/** \brief Imprime el menu
 * \param (menu) recibe el texto a imprimir
 */
void printAwesomeMenu(char *menu)
{
    cleanScreen();
    printf("%s",menu);
}

/** \brief Consume todo el stdin hasta encontrar un EOF o un "\n", se utiliza en reemplazo del fflush().
 *
 */
void erradicateStdin()
{
    char stdinBuffer;
    while((stdinBuffer = getchar()) != '\n' && stdinBuffer != EOF);

    return;
}

/** \brief Pausa el programa hasta que se presiona Enter.
 *
 */
void pauseScreen()
{
    printf("\nPresione Enter para continuar: ... ");
    while ( getchar() != '\n');
}

/** \brief Limpia la pantalla
 *
 */

void cleanScreen()
{
    system(LIMPIARPANTALLA);
}

/** \brief convierte una cadena de carateres en mayuscula, minuscula o capital
 * \param (stringToConvert) cadena de caracter a convertir
 * \param (option) (1 = mayuscula | 2 = minuscula | 3 = capital)
 * \return 0 si funciona correctamente -1 si es un puntero a null o una longitud negativa
 *
 */

int stringSetCase(char *stringToConvert,int option)
{
    long int i;
    int ret = -1;

    if(stringToConvert != NULL && (option > 0 && option <4 ))
    {
        switch(option)
        {
            case 1 :
                for(i=0; stringToConvert[i]!='\0'; i++)
                {
                    stringToConvert[i] = toupper(stringToConvert[i]);
                }
            break;

            case 2 :
                for(i=0; stringToConvert[i]!='\0'; i++)
                {
                    stringToConvert[i] = tolower(stringToConvert[i]);
                }
            break;

            case 3 :
                stringToConvert[0] = toupper(stringToConvert[0]);
                for(i=1; stringToConvert[i]!='\0'; i++)
                {
                    stringToConvert[i] = tolower(stringToConvert[i]);
                }
            break;

            ret = 0;
        }
    }
    return ret;
}

/** \brief Permite swapear dos punteros a void
 *
 * \param (pointer1) puntero1 a swapear
 * \param (pointer2) puntero2 a swapear
 *
 */

void swapVariables(void *pointer1, void *pointer2, int size)
{
    void *buf = malloc(size);
    memcpy(buf,pointer1,size);
    memcpy(pointer1, pointer2,size);
    memcpy(pointer2,buf,size);
}
