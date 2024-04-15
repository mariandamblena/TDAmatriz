#include <stdio.h>
#include <stdlib.h>


int sumarDiagonalPrincipal(int** mat, int orden); // (modificado, falta modificar las demas funciones)pasar matriz por parametro: se pasa solo la cant de columnas (el orden puede ser parametro de la matriz si se declara antes en la funcion)
int sumarTriangularInferior(int orden, int mat[][orden]);
int sumarTriangularSuperior(int orden, int mat[][orden]);
int sumarDiagonalSecundaria(int orden, int mat[][orden]);
int sumarTriangularSuperiorInv(int orden, int mat[][orden]);
int sumarTriangularInferiorInv(int orden, int mat[][orden]);
void** crearMatriz(int filas, int columnas, size_t tamElem); // usa malloc para ubicar los vectores(filas) que estan relacionadas con el vector columna(columna de direcciones)
void destruirMatriz(void** mat, int filas); // va haciendo un free de cada uno de los bloques
void mostrarMatriz(int** mat, int filas, int columnas);
int** productoMatrices(int** m1,int** m2, intfilM1, int colM1FilM2, int col M2);


int main()
{
    /*int matriz[4][4]=
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };*/

    int** matriz = (int**)crearMatriz(4,4,sizeof(int));
    int** m1 = (int**)crearMatriz(2,4,sizeof(int));
    int** m2 = (int**)crearMatriz(4,3,sizeof(int));

    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            matriz[i][j] = i * 4 + j + 1;
        }
    }

        for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            m1[i][j] = i * 4 + j + 1;
        }
    }

        for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            m2[i][j] = i * 4 + j + 1;
        }
    }


    /*int sumaDP = sumarDiagonalPrincipal(matriz, 4);
    printf ("suma de la diagonal principal %d\n",sumaDP);
    int sumaTI = sumarTriangularInferior(4, matriz);
    printf ("suma de la triangular inferior %d\n",sumaTI);
    int sumaTS = sumarTriangularSuperior(4, matriz);
    printf ("suma de la triangular inferior %d\n",sumaTS);
    int sumaDS = sumarDiagonalSecundaria(4, matriz);
    printf ("suma de la triangular inferior %d\n",sumaDS);
    int sumaTSINV = sumarTriangularSuperiorInv(4, matriz);
    printf ("suma de la triangular inferior %d\n",sumaTSINV);
    int sumaTIINV = sumarTriangularInferiorInv(4, matriz);
    printf ("suma de la triangular inferior %d\n",sumaTIINV);
    return 0;
    */

    int** mProd = productoMatrices(m1,m2,2,4,3);
    mostrarMatriz(mProd, 2, 3);
    destruirMatriz((void**)m1, 2);
    destruirMatriz((void**)m2, 4);
    destruirMatriz((void**)mProd, 2);

    /*mostrarMatriz(matriz, 4, 4);
    destruirMatriz(matriz,4);
    mostrarMatriz(m)
    */
    


    return 0;


}

int sumarDiagonalPrincipal(int** mat, int orden)
{
    int suma = 0;
    for (int i = 0; i < orden; i++)
    {
        suma += mat[i][i];
    }
    return suma;
}

int sumarTriangularInferior(int orden, int mat[][orden])
{
    int suma = 0;
    for (int i = 1; i < orden; i++)
    {
        for (int j = 0; j < i; j++)
        {
           suma += mat[i][j];
        }
    }
    return suma;
}

int sumarTriangularSuperior(int orden, int mat[][orden])
{
    int suma = 0;
    for (int i = 0 ; i < orden-1 ; i++)
    {
        for (int j = i+1 ; j < orden; j++)
        {
           suma += mat[i][j];
        }
    }
    return suma;
}

int sumarDiagonalSecundaria(int orden, int mat[][orden])
{
    int suma = 0;
    for (int i = 0 ; i < orden ; i++)
    {
           suma += mat[i][orden-1-i];
    }
    return suma;
}

int sumarTriangularSuperiorInv(int orden, int mat[][orden])
{
    int suma = 0;
    for (int i = 0 ; i < orden-1 ; i++)
    {
        for (int j = 0 ; j < orden - 1 - i; j++)
        {
           suma += mat[i][j];
        }
    }
    return suma;
}

int sumarTriangularInferiorInv(int orden, int mat[][orden])
{
    int suma = 0;
    for (int i = 0 ; i < orden-1 ; i++)
    {
        for (int j = 0 ; j < orden - 1 - i; j++)
        {
           suma += mat[i][j];
        }
    }
    return suma;
}

void** crearMatriz(int filas, int columnas, size_t tamElem)
{
    void** mat = malloc(filas * sizeof(void*));

    if (!mat)
        return NULL;

    for (int i = 0; i < filas; i++)
    {
        mat[i] = malloc(columnas * tamElem);

        if (!mat[i])
        {
            destruirMatriz(mat, i);
            return NULL; // Added curly braces to properly enclose the block
        }
    }

    return mat;
}


void destruirMatriz(void** mat, int filas)
{
    for(int i = 0; i < filas; i++)
    {
        free(mat[i]);

    }
}

void mostrarMatriz(int** mat, int filas, int columnas)
{
    for(int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%4d", mat[i][j]);
        }

        putchar('\n');

    }
}

int** productoMatrices(int** m1,int** m2, int filM1, int colM1FilM2, int colM2)
{
    int** mProd = crearMatriz(filM1, colM2, sizeof(int));

    if(!mProd)
        return NULL;

    for (int i = 0; i < filM1; i++)
    {
        for (INT J = 0; i < colM2; j++)
        {
            mProd[i][j] = 0;
            for (int k = 0; k < colM1FilM2; k++)
            {
                mProd[i][j] += m1[i][k] * m2[k][j];
            }
            
        }
        
    }

    return mProd;
    
}