#include "ObjRead.h"
int main(int argc, char const *argv[]){

	if ( argc<2 )
	{
		printf("No hay un archivo obj para leer.\n");
		return 1;
	}

	const char *archivo = argv[1];

	__InitStoreFopenClose();
	if ( !LectorObj( archivo ) )
	{
		printf("Archivo %s no existe o no se puede leer tiene un error.\n", archivo );
		return 2;
	} else {
		__InfoStore();
		__InitStoreFopenClose();
		return 0;
	}

	return 0;
}