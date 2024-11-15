#include "matrices.h"

int main(int argc, char *argv[])
{
    if (argc != 7)
    {
        return 1;
    }  // Retornar un código de error }

    unsigned fila,columna,generacion;
    int **Mat;

    SDL_Window* window;
    SDL_Renderer* renderer;

    int OP,iniciar,nuevosValoresFyC=1;
    int alto, ancho;

    alto=atoi(argv[1]);
    ancho=atoi(argv[2]);

    char nombreArcNaveEspacial[30];
    strcpy(nombreArcNaveEspacial, argv[3]);

    char nombreArcGeneradorNave[30];
    strcpy(nombreArcGeneradorNave, argv[4]);

    char nombreArcPulsar[30];
    strcpy(nombreArcPulsar, argv[5]);

    char nombreArcNaveLigera[30];
    strcpy(nombreArcNaveLigera, argv[6]);

    printf("**********Bienvenido al Juego de la Vida, desea iniciar?**********\n1.Si\n2.No\n");
    do{
        scanf("%d",&iniciar);
        system("cls");
        if(iniciar!=1 && iniciar!=2)
            printf("Error, ingrese nuevamente si desea iniciar\n1.Si\n2.No\n");
    }while(iniciar!=1 && iniciar!=2);

   if(iniciar==1)
   {
        while(OP!=5)
        {
            if(nuevosValoresFyC==1)
                IngresarDatos(&fila,&columna,&generacion);
            else if(nuevosValoresFyC == 3)
                return 0;

            Mat=Generar_Matriz(columna, fila);
            inicializarMatriz(Mat,fila,columna,0);
            OP=Menu(Mat,fila,columna, nombreArcNaveEspacial, nombreArcGeneradorNave, nombreArcPulsar, nombreArcNaveLigera);
            system("cls");
            if(OP!=5)
            {
                ///////////////////////////////////////////////////////////////////////////
                if (SDL_Init(SDL_INIT_VIDEO) != 0)
                {
                    printf("SDL No se ha podido inicializar! SDL_Error: %s\n", SDL_GetError());
                    return 1;
                }
                //Mucha de esta parametrizacion puede venir por linea de comando!!
                window = crearVentana(alto,ancho);
                if (window == NULL)
                {
                    SDL_Quit(); // Limpiar SDL si no se pudo crear la ventana
                    return 1; // Manejo de error
                }

                renderer  = crearLienzo(window);// Creamos el lienzo
                if (renderer == NULL)
                {
                    SDL_DestroyWindow(window); // Limpiar ventana si no se puede crear el renderer
                    SDL_Quit(); // Limpiar SDL
                    return 1; // Manejo de error
                }

                nuevosValoresFyC=ejecutarJuego(Mat,fila,columna,renderer,window,generacion);
            }
            Destruir_Matriz(Mat,columna,fila);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }

        //destruyo todos los elementos creados
        //Observar ni mas ni menos que destructores, en la asignatura no inventamos nada!
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        //DESTROYER MAT
   }

    return 0;
}
