#include <stdio.h>

    void RiegoParaRosas(){
    printf("Has seleccionado Riego para Rosas.\n");
    // Aqui va el codigo para Riego para de Rosas
    }

    void RiegoParaHortalizas(){
    printf("Has seleccionado Riego para Hortalizas.\n");
    // Aqui va el codigo para Riego para de Hortalizas
    }

    void RiegoParaFrutas(){
    printf("Has seleccionado Riego para Frutas.\n");
    // Aqui va el codigo para Riego para de Frutas
    }

    void RiegoPersonalizado(){
    printf("Has seleccionado Riego Personalizado.\n");
    // Aqui va el codigo para el Riego Personalizado
    }

    void RiegoAutomatico(){
    int opcion_riego;

    do {
        printf("\nHas seleccionado Riego Automatico. ¿Que tipo de planta deseas regar?\n");
        printf("1. Riego para Rosas\n");
        printf("2. Riego para Hortalizas\n");
        printf("3. Riego para Frutas\n");
        printf("4. Riego Personalizado\n");
        printf("5. Regresar al menu anterior\n");
        printf("ingresa la opcion a utilizar ");
        scanf("%d", &opcion_riego);

        switch(opcion_riego){
            case 1:
                RiegoParaRosas();
                break;
            case 2:
                RiegoParaHortalizas();
                break;
            case 3:
                RiegoParaFrutas();
                break;
            case 4:
                RiegoPersonalizado();
                break;
            case 5:
                printf("Regresando al menu anterior...\n");
                break;
            default:
                printf("Opcion no valida, por favor selecciona una opcion entre 1 y 5.\n");
        }
    } while (opcion_riego != 5);
    }

    void RiegoManual(){
        printf("Has seleccionado Riego Manual.\n");
        // Aqui va el codigo para el Riego Manual
    }

    void Registro(){
        printf("Has seleccionado Registro.\n");
        // Aqui va el codigo para el Registro
    }

    void Facturacion(){
        printf("Has seleccionado Facturacion.\n");
        // Aqui va el codigo para la Facturacion
    }

    int main(){
        int opcion;

        do {
            printf("\n Hola usuario, ¿Que necesitas realizar hoy?\n");
            printf("1. Riego Automatico\n");
            printf("2. Riego Manual\n");
            printf("3. Registro\n");
            printf("4. Facturacion\n");
            printf("5. Salir\n");
            printf("Ingresa la opcion a trabajar: ");
            scanf("%d", &opcion);

            switch(opcion){
                case 1:
                    RiegoAutomatico();
                    break;
                case 2:
                    RiegoManual();
                    break;
                case 3:
                    Registro();
                    break;
                case 4:
                    Facturacion();
                    break;
                case 5:
                    printf("hasta luego...\n");
                    break;
                default:
                    printf("Opcion no valida, por favor selecciona una opcion entre 1 y 5.\n");
            }
        } while (opcion != 5);

    return 0;
}
