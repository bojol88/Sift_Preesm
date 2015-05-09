/*
============================================================================
Name        : splitMerge.c
Author      : kdesnos
Version     : 1.0
Copyright   : CECILL-C
Description :
============================================================================
*/

#include <string.h>
#include <stdlib.h>

#include "splitMerge.h"

void split(int nbSlice, int xSize, int ySize, unsigned char *input, unsigned char *output){
  int i,j;
 // int sliceSize = xSize*ySize/nbSlice;
  for (j = 0; j < nbSlice; j++)
  {
	  for (i = 0; i < xSize*ySize * 6; i++)
	  {
		  output[i + j*nbSlice] = input[i + j*nbSlice];
	  }
  }

  /*for (i = 0; i<nbSlice*6; i++){
	  memcpy(output + i*sliceSize, input + i*sliceSize, sliceSize);
  }*/
}


void merge(int nbSlice, int xSize, int ySize, float *input, float *output){
  int i,j;
  //int sliceSize = xSize*ySize/nbSlice;

  for (j = 0; j < nbSlice; j++)
  {
	  for (i = 0; i < xSize*ySize * 36; i++)
	  {
		  output[i + j*nbSlice] = input[i + j*nbSlice];
	  }
  }

  /*for (i = 0; i < nbSlice*36 ; i++){
	  memcpy(output + i*sliceSize, input + i*sliceSize, sliceSize);
  }*/

}

