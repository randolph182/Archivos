#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    char nombre[50];
    int carne;
}Datos;

typedef struct
{
    char curso[100];
    int codigo;
    int nota;
}Curso;

void mostrarCurso();
void ingresarCurso();
int main()
{
   // printf("Hello world!\n");
//   FILE *F;
//   F = fopen("/home/randolph/Escritorio/hoja.gen","w+b");
//   if(F != NULL)
//   {
//        datos data ;
//        strcpy(data.nombre, "randolph");
//        data.carne = 201314112;
//        fwrite(&data,sizeof(datos),1,F);
//        printf("se creo el archivo binario\n");
//   }
//   else
//        printf("se creo el archivo binario\n");
//    fclose(F);


//    ingresarCurso();
   // mostrarCurso();
   ingresarEstudiantes();
   mostrarDatos();
    return 0;
}
void mostrarCurso()
{
//    File *F;
//    F = fopen("/home/randolph/Escritorio/hoja.gen","rb");
//    int cantidad = fread(F,)


           // int pos, res, val;
           char val[100];
           int pos,res;
      //  int width;
       int width = sizeof(char); /* cuantos bytes ocupa cada entero en el archivo */
        width =4;
        FILE *file;
        file = fopen("/home/randolph/Escritorio/hoja.gen","rb");
        if (file == NULL) {
                printf("Archivo no se pudo abrir\n");
                return 1;
        }
        printf("-----------------------------\n");
        printf("Ingrese posicion a mostrar (0=primero)\n");
        scanf("%d", &pos);
        res = fseek(file, pos * width, SEEK_SET);
        if (res != 0) {
                printf("Error en seek");
                return 1;
        }
        fread(&val, width, 1, file);
        //printf("val = 0x%x (decimal:%d)\n", val, val);
        printf("%s",val);
        printf("-----------------------------\n");
        fclose(file);

}
void ingresarEstudiantes()
{
    FILE *F;
    char nombre1[50];
    char nombre2[50];
    int carne1;
    int carne2;
    F = fopen("/home/randolph/Escritorio/hoja.gen","w+b");
    printf("Ingrese el carne 1: ");
    scanf("%d",&carne1);
    printf("Ingrese el nombre 1: ");
    scanf("%s",&nombre1);
    printf("Ingrese el carne 2: ");
    scanf("%d",&carne2);
    printf("Ingrese el nombre 2: ");
    scanf("%s",&nombre2);
    Datos datos1;
    strcpy(datos1.nombre,nombre1);
    datos1.carne = carne1;
    Datos datos2;
    strcpy(datos2.nombre,nombre2);
    datos2.carne = carne2;

   if(F != NULL)
   {

        fwrite(&datos1,sizeof(Datos),1,F);
        fseek(F,sizeof(datos1),SEEK_END); //me hubico al final del primer dato
        fwrite(&datos2,sizeof(Datos),1,F); //escribo la nueva informacion
        printf("Los datos de los estudiantes se han registrado\n");
   }
   fclose(F);

}

void mostrarDatos()
{
    FILE *F;
    F = fopen("/home/randolph/Escritorio/hoja.gen","rb");
    fseek(F, 0L, SEEK_SET); //datos del primer estudiante
    Datos datos1;
    fread(&datos1, sizeof(Datos), 1, F);

    fseek(F,sizeof(datos1),SEEK_END);
    Datos datos2;
    fread(&datos2,sizeof(Datos),1,F);

    printf("Carnet Estudiante1: %d",datos1.carne);
    printf("Carnet Estudiante2: %d",datos2.carne);
}

void ingresarCurso()
{
    char datosCurso[150];
    int codigoCurso;
    int notaCurso;
    printf("Ingrese el nombre del curso: ");
    scanf("%s", &datosCurso);
    printf("Ingrese el codigo del curso: ");
    scanf("%d", &codigoCurso);
    printf("Ingrese nota del Curso: ");
    scanf("%d", &notaCurso);
    FILE *F;
    F = fopen("/home/randolph/Escritorio/hoja.gen","w+b");
   if(F != NULL)
   {
        Curso data ;
        strcpy(data.curso, datosCurso);
        data.codigo = codigoCurso;
        data.nota = notaCurso;
        fwrite(&data,sizeof(Curso),1,F);
        printf("datos ingresados\n");
   }
   fclose(F);
//    printf("introdusca una cadena de texto\n");
//    scanf("%s",&cadena);
}
