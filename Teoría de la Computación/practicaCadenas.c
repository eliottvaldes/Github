// CADENAS (SUFIJO, PREFIJO, SUBCADENA, SUBSENCUENCIA, INVERSA Y CONCATENAR)
// Autora: Colín Astudillo Diana Itzel
// Fecha: abril de 2024

#include <stdio.h>
#include <stdlib.h>

// Variables globales
int largoCadena = 50;

int main()
{
    // Variables locales para manejar la cadena
    char cadena1[largoCadena];
    int longitudCadena = 0;
    int longitudCadena2 = 0;

    // Creamos un menú de opciones
    int opc = 0;
    printf("\n ------- BIENVENIDO, PROFE, A LA PRACTICA DE CADENAS -------\n");
    do
    {
        printf("\nSeleccione la opcion que quiera realizar: \n");
        printf("1. Leer cadena\n");
        printf("2. Obtener sufijo\n");
        printf("3. Obtener prefijo\n");
        printf("4. Obtener subcadena\n");
        printf("5. Obtener subsecuencia\n");
        printf("6. Obtener inversa\n");
        printf("7. Concatenar cadenas\n");
        printf("8. Salir\n");
        printf("\nLa opcion que quiero es: ");
        fflush(stdin);
        scanf("%d", &opc);

        // Hacemos el switch para las 8 opciones
        switch (opc)
        {
        case 1:
        {
            // 1. Leer Cadena
            printf("\nIntroduzca la cadena a trabajar: ");
            fflush(stdin);
            scanf("%s", &cadena1);
            // Obtenemos la longitud de nuestra cadena ingresada
            while (cadena1[longitudCadena] != 0)
            {
                longitudCadena++;
            }
            printf("\nAhora . . .\n");
            break;
        }

        case 2:
        {
            // 2. Obtener sufijo
            printf("\nLa cadena ingresada es: %s . El largo de la cadena ingresada es: %d .\n", cadena1, longitudCadena);
            // Hay que validar la longitud de la cadena1 vs el número de sufijo que se desea obtener
            // Preguntamos el número de sufijo que se desean obtener
            int nSF = 0;
            do
            {
                printf("\nIndique el numero de sufijo que desea obtener: ");
                fflush(stdin);
                scanf("%d", &nSF);

                // Obtenemos el sufijo requerido
                if (nSF >= 0 && nSF <= longitudCadena)
                {
                    if (nSF == 0)
                    {
                        printf("\nEl sufijo es: lambda (cadena vacia, ningun caracter)\n");
                    }
                    else
                    {
                        printf("\nEl sufijo de la cadena es: ");
                        for (int i = longitudCadena - nSF; i < longitudCadena; i++)
                        {
                            printf("%c", cadena1[i]);
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("\nEl numero de sufijo es negativo o mayor al largo de la cadena ingresada. Por favor, intentelo nuevamente.\n");
                }
            } while (nSF < 0 || nSF > longitudCadena);
            break;
        }

        case 3:
        {
            // 3. Obtener prefijo
            printf("\nLa cadena ingresada es: %s . El largo de la cadena ingresada es: %d .\n", cadena1, longitudCadena);
            // Validar longitud de cadena1 vs número de prefijo deseado
            // Preguntamos el número de prefijo a obtener
            int nPF = 0;
            do
            {
                printf("\nIndique el numero de prefijo que desea obtener: ");
                fflush(stdin);
                scanf("%d", &nPF);

                // Obtenemos el prefijo
                if (nPF >= 0 && nPF <= longitudCadena)
                {
                    if (nPF == 0)
                    {
                        printf("\nEl prefijo es: lambda (cadena vacia, ningun caracter)\n");
                    }
                    else
                    {
                        printf("\nEl prefijo de la cadena es: ");
                        for (int i = 0; i < nPF; i++)
                        {
                            printf("%c", cadena1[i]);
                        }
                    }
                }
                else
                {
                    printf("\nEl numero de prefijo es negativo o mayor al largo de la cadena ingresada. Por favor, intentelo nuevamente.\n");
                }
            } while (nPF < 0 || nPF > longitudCadena);
            break;
        }

        case 4:
        {
            // 4. Obtener subcadena
            printf("\nLa cadena ingresada es: %s . El largo de la cadena ingresada es: %d .\n", cadena1, longitudCadena);

            // Indicar número de sufijo y prefijo de la subcadena
            int nSFSC = 0;
            int nPFSC = 0;
            do
            {
                printf("\nIndique el numero de prefijo que desea quitar: ");
                fflush(stdin);
                scanf("%d", &nPFSC);
                printf("\nIndique el numero de sufijo que desea quitar: ");
                fflush(stdin);
                scanf("%d", &nSFSC);
                if (nSFSC + nPFSC <= longitudCadena && nSFSC >= 0 && nPFSC >= 0)
                {
                    if (nSFSC + nPFSC == longitudCadena)
                    {
                        printf("\nLa subcadena es: lambda (cadena vacia, ningun caracter)\n");
                    }
                    else
                    {
                        printf("\nLa subcadena es: ");
                        for (int i = nPFSC; i < longitudCadena - nSFSC; i++)
                        {
                            printf("%c", cadena1[i]);
                        }
                        printf("\n");
                    }
                }
                else
                {
                    printf("\nEl numero de sufijo y/o prefijo es negativo o mayor al largo de la cadena ingresada. Por favor, intentelo nuevamente.\n");
                }
            } while (nSFSC + nPFSC > longitudCadena || nSFSC < 0 || nPFSC < 0);
            break;
        }

        case 5:
        {
            // 5. Obtener subsecuencia
            printf("\nLa cadena ingresada es: %s . El largo de la cadena ingresada es: %d .\n", cadena1, longitudCadena);

            // Indicar caracteres a quitar
            int quitar = 0;
            do
            {
                printf("\nIndique el numero de caracteres que desea quitar de la cadena: ");
                fflush(stdin);
                scanf("%d", &quitar);

                int posiciones[quitar];
                printf("\nIndique las posiciones de los %d caracteres que desea quitar.\n", quitar);
                for (int i = 0; i < quitar; i++)
                {
                    printf("Quiero que el caracter %d se quite de la posicion: ", i + 1);
                    fflush(stdin);
                    scanf("%d", &posiciones[i]);
                }

                // Imprimimos el arreglo de posiciones
                printf("\nLas posiciones a quitar son: ");
                for (int i = 0; i < quitar; i++)
                {
                    printf("%d ", posiciones[i]);
                }
                printf("\n");

                // Quitar caracteres de las posiciones indicadas e imprimir subsecuencia
                printf("\nLa subsecuencia de la cadena es: ");                                
                // loop over the string
                for (int i = 0; i < longitudCadena; i++)
                {
                    // validate if i exist in posiciones array in any position                    
                    int exist = 0;
                    for (int j = 0; j < quitar; j++)
                    {
                        if (i == posiciones[j])
                        {
                            exist = 1;
                            break;
                        }
                    }
                    // if i does not exist in posiciones array, print the character
                    if(exist == 0){
                        printf("%c", cadena1[i]);
                    }                    
                } 
                printf("\n\n");
                /* 
                // OLD VERSION
                printf("\nLa subsecuencia de la cadena es: ");
                for (int i = 0; i < quitar; i++)
                {
                    for (int j = 0; j < longitudCadena; j++)
                    {
                        if ((posiciones[i]) != j)
                        {                            
                            printf("%c", cadena1[j]);
                        }
                    }
                }
                */                                

            } while (quitar < 0 || quitar > longitudCadena);
            break;
        }

        case 6:
        {
            // 6. Obtener inversa
            printf("\nLa cadena ingresada es: %s . El largo de la cadena ingresada es: %d .\n", cadena1, longitudCadena);
            printf("\nLa cadena inversa es: ");
            for (int i = longitudCadena; i >= 0; i--)
            {
                printf("%c", cadena1[i]);
            }
            printf("\n");
            break;
        }

        case 7:
        {
            // 7. Concatenar cadenas
            // Pedimos que ingrese una segunda cadena
            char cadena2[largoCadena];
            printf("\nIntroduzca una segunda cadena: ");
            fflush(stdin);
            scanf("%s", &cadena2);
            // Obtenemos la longitud de la segunda cadena
            while (cadena2[longitudCadena2] != 0)
            {
                longitudCadena2++;
            }
            printf("\nLa primer cadena ingresada es: %s . El largo de la cadena es: %d .\n", cadena1, longitudCadena);
            printf("\nLa segunda cadena ingresada es: %s . El largo de la cadena es: %d .\n", cadena2, longitudCadena2);

            // Concatenamos las cadenas
            printf("\nLas cadenas concatenadas son: ");
            for (int i = 0; i < longitudCadena; i++)
            {
                printf("%c", cadena1[i]);
            }
            for (int i = 0; i < longitudCadena2; i++)
            {
                printf("%c", cadena2[i]);
            }

            printf(" . La longitud de las cadenas concatenadas es: %d \n.", longitudCadena + longitudCadena2);
            break;
        }

        case 8:
        {
            printf("\n\nGracias por el diez. Hasta luego.\n");
            break;
        }

        default:
        {
            printf("\n\nOpcion no valida. Intente de nuevo.\n");
            break;
        }
        }
    } while (opc != 8);

    return 0;
}