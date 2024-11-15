#include"matrices.h"

int**Generar_Matriz(size_t Colum,size_t File)
{
    int**init=malloc(File*sizeof(int*));
    if(!init)
    {
        return NULL;
    }
    for(int**col=init;col<(init+File);col++)
    {
        *col=malloc(sizeof(int)*Colum);
        if(!*col)
        {
            for(int **k=init;k<col;k++)
            {
                free(*k);
            }
            free(init);
            return NULL;
        }
    }
 return init;
}
void inicializarMatriz(int **MAT, size_t fila, size_t columna,int valor)
{
    size_t i,j;
    for(i=0;i<fila;i++)
    {
        for(j=0;j<columna;j++)
        {
            MAT[i][j]=valor;
        }
    }
}
void Destruir_Matriz(int**matriz,size_t Colum,size_t File)
{
    unsigned i;

    for(i=0;i<File;i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}
int procesarTxt(const char *name,int **Mat)
{
    FILE *ptr_txt=fopen(name,"rt");
    if(!ptr_txt)
    {
        return FATAL_ERROR;
    }

    char *linea=malloc(BUFFER*sizeof(char));
    if(!linea)
    {
        fclose(ptr_txt);
        return FATAL_ERROR;
    }

    unsigned posX;
    unsigned posY;

    while(fgets(linea,BUFFER,ptr_txt))
    {
        desglosarLinea(linea,&posX,&posY);
        Mat[posX][posY]=1;
    }
    free(linea);
    fclose(ptr_txt);
    return TODO_OK;
}
void desglosarLinea(const char *cad,unsigned *X,unsigned *Y)
{
    char *aux=strrchr(cad,'\n');
    *aux='\0';

    aux=strrchr(cad,'|');

    aux++;
    sscanf(aux,"%u",Y);

    *(aux-1)='\0';
    sscanf(cad,"%u",X);
}

int Menu (int **mat, size_t f, size_t c, char* nombreNE, char* nombreGNE, char* nombrePulsar, char* nombreNL)
{
    int op;
    printf("*************************************************************** \n");
   do {
        printf("Seleccione el patron inicial:\n 1) Nave\n 2) Generador de naves espaciales\n 3) Pulsar\n 4) Nave Ligera\n 5) Terminar Programa\n");
        scanf("%d", &op);
        if (op < 1 || op > 5) {
            printf("Opcion no disponible, elige una opcion entre 1 y 5.\n");
        }
    } while(op < 1 || op > 5);
    switch(op)
    {
        case 1: procesarTxt(nombreNE,mat);
                break;
        case 2: procesarTxt(nombreGNE,mat);
                break;

        case 3: procesarTxt(nombrePulsar,mat);
                break;
        case 4: procesarTxt(nombreNL,mat);
        break;

    }
    printf("*************************************************************** \n");
return op;
}
void IngresarDatos(unsigned* f,unsigned* c, unsigned* g)
{

    system("cls");

    printf("*************************************************************** \n");
    do
    {
        printf("Ingrese el numero de fila (minimo 50 filas): \n");
        scanf("%u",f);
        if(*f<50)
            printf("Filas insuficiente, Ingrese nuevamente\n");//ERROR
    }
    while(*f<50);
    do
    {
        printf("Ingrese el numero de columna (minimo 50 columnas): \n");
        scanf("%u", c);
        if(*c<TAM_MIN)
            printf("Columnas insuficiente, Ingrese nuevamente\n");
    }
    while(*c<TAM_MIN);
    printf("Ingrese hasta cuantas iteraciones de celulas quiere ver: \n");
    scanf("%u",g);

    printf("*************************************************************** \n");
    *f+=2;
    *c+=2;

}



/// Se realizaron estas funciones anteriormente para inicializar los patrones
/*
void CrearMatrizNaveEspacial(int **mat,size_t fila, size_t columna)
{

    if(fila > MIN_F_NAVE  && columna > MIN_C_NAVE)
    {
        mat[1][2]=1;
        mat[2][3]=1;
        mat[3][1]=1;
        mat[3][2]=1;
        mat[3][3]=1;
    }
}
void CrearGeneradorNavesEspaciales(int **mat,size_t fila, size_t columna)
{

    if(fila > MIN_F_GENERADOR && columna > MIN_C_GENERADOR)
    {
        mat[1][5] = 1;
        mat[2][5] = 1;
        mat[1][6] = 1;
        mat[2][6] = 1;

        mat[13][3] = 1;
        mat[14][3] = 1;
        mat[12][4] = 1;
        mat[16][4] = 1;
        mat[11][5] = 1;
        mat[17][5] = 1;
        mat[11][6] = 1;
        mat[15][6] = 1;
        mat[17][6] = 1;
        mat[18][6] = 1;
        mat[11][7] = 1;
        mat[17][7] = 1;
        mat[12][8] = 1;
        mat[16][8] = 1;
        mat[13][9] = 1;
        mat[14][9] = 1;

        mat[25][1] = 1;
        mat[23][2] = 1;
        mat[25][2] = 1;
        mat[21][3] = 1;
        mat[22][3] = 1;
        mat[21][4] = 1;
        mat[22][4] = 1;
        mat[21][5] = 1;
        mat[22][5] = 1;
        mat[23][6] = 1;
        mat[25][6] = 1;
        mat[25][7] = 1;

        mat[35][3] = 1;
        mat[36][3] = 1;
        mat[35][4] = 1;
        mat[36][4] = 1;
    }
}
void CrearPulsar(int **mat, unsigned cf, unsigned cc)
{
    // Asegúrarse de que el tamaño sea lo suficientemente grande
    if (cf >= MIN_FC_PULSAR && cc >= MIN_FC_PULSAR)
    {
        mat[2][4] = 1;
        mat[2][5] = 1;
        mat[2][6] = 1;
        mat[2][10] = 1;
        mat[2][11] = 1;
        mat[2][12] = 1;

        mat[4][2] = 1;
        mat[4][7] = 1;
        mat[4][9] = 1;
        mat[4][14] = 1;

        mat[5][2] = 1;
        mat[5][7] = 1;
        mat[5][9] = 1;
        mat[5][14] = 1;

        mat[6][2] = 1;
        mat[6][7] = 1;
        mat[6][9] = 1;
        mat[6][14] = 1;

        mat[7][4] = 1;
        mat[7][5] = 1;
        mat[7][6] = 1;
        mat[7][10] = 1;
        mat[7][11] = 1;
        mat[7][12] = 1;

        mat[9][4] = 1;
        mat[9][5] = 1;
        mat[9][6] = 1;
        mat[9][10] = 1;
        mat[9][11] = 1;
        mat[9][12] = 1;

        mat[10][2] = 1;
        mat[10][7] = 1;
        mat[10][9] = 1;
        mat[10][14] = 1;

        mat[11][2] = 1;
        mat[11][7] = 1;
        mat[11][9] = 1;
        mat[11][14] = 1;

        mat[12][2] = 1;
        mat[12][7] = 1;
        mat[12][9] = 1;
        mat[12][14] = 1;

        mat[14][4] = 1;
        mat[14][5] = 1;
        mat[14][6] = 1;
        mat[14][10] = 1;
        mat[14][11] = 1;
        mat[14][12] = 1;

    }
}
void CrearMatrizNaveEspacialMedia(int **mat, size_t fila, size_t columna)
{
    if (fila > MIN_F_NAVE && columna > MIN_C_NAVE)
    {
        // Patrón de nave espacial de peso medio (MWSS)
        if (fila >= 6 && columna >= 6) {
          mat[4][4] = 1;
          mat[5][4] = 1;
          mat[7][5] = 1;
         mat[8][6] = 1;

         mat[8][7] = 1;
         mat[8][8] = 1;

        mat[2][5] = 1;

        mat[2][7] = 1;
        mat[3][8] = 1;
       mat[4][8] = 1;
       mat[5][8] = 1;
       mat[6][8] = 1;
       mat[7][8] = 1;
        }
    }
}

*/


SDL_Window* crearVentana(int alto , int ancho)
{
    SDL_Window* window = NULL;

    window = SDL_CreateWindow("Juego de la vida",
                                                SDL_WINDOWPOS_UNDEFINED,
                                                SDL_WINDOWPOS_UNDEFINED,
                                                alto,
                                                ancho,
                                                SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Error en la creacion de la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }
    return window;
}
SDL_Renderer* crearLienzo(SDL_Window* window)
{
    SDL_Renderer* renderer;
       renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("No se ha podido crear el lienzo! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL;
}
return renderer;
}




int ejecutarJuego(int **Mat, unsigned fila, unsigned columna, SDL_Renderer* renderer,SDL_Window* window,unsigned generacion)
{
    char tecla;
    unsigned char done=0;
    int i=0,nuevosValoresFyC;
    SDL_Event e;
    int delay =200;

    while (!done && i<generacion)  //Se puede parar tambien cuando no se observen cambios!
    {
        while (SDL_PollEvent(&e) != 0)
        {
            // Salida del usuario
            if (e.type == SDL_QUIT)
            {
                done = 1;
            }
        }
        // Se limpia la pantalla
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);

        ActualizarMatriz(Mat, fila, columna);//1
        MostrarMatriz(Mat,fila,columna,renderer);//4

        // Actualizacion del "lienzo"
        SDL_RenderPresent(renderer);

        //Titulo/caption de la ventana
        SDL_SetWindowTitle(window, "JUEGO DE LA VIDA JOHN HORTON CONWAY");
        SDL_Delay(delay);

        i++;

        if(kbhit())
        {
            tecla=getch();
            if(tecla==13)
                break;
        }
    }

    printf("Elija una opcion:\n1.Ingresar nuevos valores para Filas, Columnas y Numero de Generaciones.\n2.Elegir nuevo patron inicial.\n3.Terminar juego.\n");
    do{
        scanf("%d",&nuevosValoresFyC);
        system("cls");
        if(nuevosValoresFyC < 1 || nuevosValoresFyC > 3)
            printf("Error, ingrese opcion nuevamente:\n1.Ingresar nuevos valores para Filas, Columnas y Numero de Generaciones.\n2.Elegir nuevo patron inicial.\n3.Terminar juego.\n");
    }while(nuevosValoresFyC < 1 || nuevosValoresFyC > 3);

    return nuevosValoresFyC;
}
void ActualizarMatriz(int **matriz,size_t fila,size_t columna)
{
    int i, j, contVivos = 0;
    for (i = 1; i < fila-1; i++)
    {
        for (j = 1; j < columna-1; j++)
        {
            contVivos = ContVecinos(matriz, i,j,fila,columna);/// Contamos la cantidad de celulas vivas por cada celda de la matriz

            if (matriz[i][j] == CEL_MUERTA && contVivos == 3)
            {
                matriz[i][j] = CEL_REVIVE;
            }
            else if (matriz[i][j] == CEL_VIVA && (contVivos != 2 && contVivos != 3))///si la celula esta viva y no cumple las condiciones para vivir
            {
                matriz[i][j] = CEL_MORIRA;
            }
        }
    }

}
int ContVecinos(int **matriz, size_t fila, size_t columna,size_t Max_File, size_t Max_Colum)
{
    int i, j, contador = 0;

    for (i = fila - 1; i <= fila + 1; i++)
    {
        for (j = columna - 1; j <= columna + 1; j++)
        {
            if(i!=fila || j!=columna) /// para que no  cuente la celda que mandamos
            {
                if (matriz[i][j] == CEL_VIVA|| matriz[i][j] == CEL_MORIRA)/// cuenta las celdas en donde la celula esta viva y esta por morir
                {
                    contador++;
                }
            }
        }
    }

    return contador;
}
void MostrarMatriz(int **Mat, unsigned fila, unsigned columna, SDL_Renderer* renderer)
{
    unsigned x,y;
    SDL_Rect fillRect;

    for(x=1;x<fila-1;x++)
        {
            for(y=1;y<columna-1;y++)
            {
                if(Mat[x][y] == CEL_MORIRA)
                    Mat[x][y] = CEL_MUERTA;

                if(Mat[x][y] == CEL_REVIVE)
                    Mat[x][y] = CEL_VIVA;

                if (Mat[x][y] == CEL_VIVA)
                {
                    fillRect.x = x*10; //Pos X
                    fillRect.y = y*10; //Pos Y
                    fillRect.h = 10; //Alto
                    fillRect.w = 10; //Ancho

                    //Plantilla para pintar cuadrados
                    SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
                    SDL_RenderFillRect(renderer, &fillRect);
                }

            }
        }
}


