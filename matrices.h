#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#define MIN_F_NAVE 3
#define MIN_C_NAVE 3
#define MIN_F_GENERADOR 8
#define MIN_C_GENERADOR 35
#define MIN_FC_PULSAR 15
#ifdef __MINGW32__
    #define SDL_MAIN_HANDLED
    #include <SDL_main.h>
#endif
#include <SDL.h>
#define CEL_VIVA 1
#define CEL_MUERTA 0
#define CEL_REVIVE 2
#define CEL_MORIRA -1
#define TAM_MIN 50

#define BUFFER 10
#define FATAL_ERROR 0
#define TODO_OK 1

void ActualizarMatriz(int **matriz, size_t fila, size_t columna);
int ContVecinos(int **matriz, size_t fila, size_t columna,size_t Max_File, size_t Max_Colum);
int **Generar_Matriz(size_t Colum,size_t File);
void inicializarMatriz(int **MAT, size_t fila, size_t columna,int valor);
int Menu (int **mat, size_t f, size_t c, char* nombreNE, char* nombreGNE, char* nombrePulsar, char* nombreNL);
int validarDato(unsigned valor);
void CrearMatrizNaveEspacial(int **mat,size_t fila, size_t columna);
void CrearGeneradorNavesEspaciales(int **mat,size_t fila, size_t columna);
void CrearPulsar(int **mat, unsigned cf, unsigned cc);
void Destruir_Matriz(int**matriz,size_t Colum,size_t File);
void MostrarMatriz(int **Mat, unsigned fila, unsigned columna, SDL_Renderer* renderer);
SDL_Window* crearVentana(int alto, int ancho);
SDL_Renderer* crearLienzo(SDL_Window* window);
int ejecutarJuego(int **Mat, unsigned fila, unsigned columna, SDL_Renderer* renderer,SDL_Window* window,unsigned generacion);
void CrearMatrizNaveEspacialMedia(int **mat, size_t fila, size_t columna);
void IngresarDatos(unsigned* f,unsigned* c, unsigned* g);

int procesarTxt(const char *name,int **Mat);
void desglosarLinea(const char *cad,unsigned *X,unsigned *Y);
#endif // MATRICES_H_INCLUDED
