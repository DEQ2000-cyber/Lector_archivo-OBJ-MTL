#ifndef __OBJREAD_H__
#define __OBJREAD_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static FILE *StoreV=NULL;
static FILE *StoreF=NULL;
static FILE *StoreVT=NULL;
static unsigned int LenV=0;
static unsigned int LenF=0;
static unsigned int LenVT=0;

void __InfoStore(void){
	printf("Vertex        : %i\n", LenV );
	printf("Faces         : %i\n", LenF );
	printf("Vertex Texture: %i\n", LenVT );
}

const int __InitStoreFopenClose(void){
	LenV=0;
	LenF=0;
	LenVT=0;
	if (StoreV)
	{
		fclose(StoreV),StoreV=NULL;
	} else {
		StoreV=fopen("StoreV.bin","w");
	}
	if (StoreF)
	{
		fclose(StoreF),StoreF=NULL;
	} else {
		StoreF=fopen("StoreF.bin","w");
	}
	if (StoreVT)
	{
		fclose(StoreVT),StoreVT=NULL;
	} else {
		StoreVT=fopen("StoreVT.bin","w");
	}
	return 1;
}

const int __LectorObjVertice( const char cadena[] ){
	fprintf(StoreV, "%s", cadena);
	return 1;
}

const int __LectorObjFace( const char cadena[] ){
	fprintf(StoreF, "%s", cadena);
	return 1;
}

const int __LectorObjVerticeTexture( const char cadena[] ){
	fprintf(StoreVT, "%s", cadena);
	return 1;
}

const int LectorObj( const char file[] ){
	FILE *OBJ = fopen(file,"r");
	if (!OBJ)
	{
		fclose(OBJ),OBJ=NULL;
		return 0;
	} else {
		char *BUFFER = NULL;
		BUFFER = (char*)malloc(sizeof(char)*512);
		do
		{
			if ( *BUFFER == 'v' && BUFFER[1] == ' ' )LenV+=__LectorObjVertice(&BUFFER[2]);
			if ( *BUFFER == 'f' && BUFFER[1] == ' ' )LenF+=__LectorObjFace(&BUFFER[2]);
			if ( *BUFFER == 'v' && BUFFER[1] == 't' )LenVT+=__LectorObjVerticeTexture(&BUFFER[3]);
			if ( *BUFFER == 'm' && BUFFER[1] == 't' && BUFFER[2] == 'l' && BUFFER[3] == 'l' && BUFFER[4] == 'i' && BUFFER[5] == 'b' );
		} while ( fgets( BUFFER, 512, OBJ ) );
		free(BUFFER),BUFFER=NULL;
		fclose(OBJ),OBJ=NULL;
		return 1;
	}
	return 1;
}
#ifdef __cplusplus
	}
#endif
#endif