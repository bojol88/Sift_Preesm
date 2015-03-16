#ifndef _SIFT_H_
#define _SIFT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/****************************************
 * Flags
 ***************************************/
// print information
#define VERBOSE 1

/****************************************
 * Global Definitions
 ***************************************/

// maximum number of octaves
#define MAX_O (6)
// maximum nuber of scales per octave
#define MAX_S (6)
// number of bins for orientation histogram
#define ORI_BINS (36)


/****************************************
 * Memory allocations customized for CIF images: 352x288
 ***************************************/

// number of total octaves (skip last two level)
#define NUMBER_OF_OCTAVES (6)
// int NUMBER_OF_OCTAVES = (int)(log2( (w < h) ? (float)w : (float)h))-2;

// number of scales per octaves (empirical number)
#define NUMBER_OF_SCALES (6)

// size of the largest octave
// to simplify, each octave is allocated the same size.
// this can be improved
#define MAX_OCTAVE_SIZE (101376)

// maximum number of SIFT points to retrieve
#define MAX_NUMBER_OF_POINTS (500)

/****************************************
 * Data Structures
 ***************************************/

// 128-element descriptor
#define NUM_OF_DESCRIPTORS (128)
typedef struct SiftKeypoint_t {
    int o; // octave number
    float x; // x coordinate
    float y; // y coordinate
    float s; // scale
    float ori; // orientation in degrees.
    float mag; // magnitude
    //float descriptors [NUM_OF_DESCRIPTORS]; // In the current code, the descriptors are not computed
} SiftKeypoint;

// a linked list for descriptors
typedef struct pointList_t{
    SiftKeypoint list[MAX_NUMBER_OF_POINTS];
    int size;
} pointList;

// Gradient buffer for orientation and descriptor calculation
extern int current_octave;
extern float* grad_buffer;

/****************************************
 * Functions
 ***************************************/


void buildOB(unsigned char* img,
             unsigned char* octaves,
             int* octavesW, int* octavesH);

void buildSS(unsigned char* octaves,
			 float* scaleSpace,
             int* octavesW, int* octavesH,
             float* sigmas);

void DoG(float* dog,
		 float* scaleSpace,
         int* octavesW, int* octavesH);

void extreme(pointList* keyPointList,
			 float * dog,
             int* octavesW, int* octavesH);

void orientation(pointList* keyPointList,
				 pointList* keyPointListCP,
				 float* scaleSpace ,
                 float* sigmas ,
                 int* octavesW);

void write_keypoints(FILE* fp,
                     SiftKeypoint* keys,
                     int n);

void  render(unsigned char* img,
             int* octavesW, int* octavesH,
             pointList* keyPointList,
			 float * sigmas, unsigned char* r, unsigned char* g, unsigned char* b);


void Sift(unsigned char* input, int xsize, int ysize, unsigned char* r, unsigned char* g, unsigned char* b);

void InitSift(int xsize, int ysize, int * octavesW_g, int * octavesH_g, float * sigmas);

#endif//_SIFT_H_

