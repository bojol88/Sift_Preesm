#include "sift.h"
#include "img_io.h"
#include "Tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

static int k = -2, l = -3, m = 1, n = 1;
// l is down to -3 because of the pipeline, is value is 1 minus the number of pipeline stage before him
// The same for k


void Test_OB(unsigned char* octaves)
{
	char filename[256];
	sprintf(filename, "Tests/BuildOB/Resultats/%d.pgm", k);
	write_pgm(octaves, 352, 6 * 288, filename);
	k++;
}

void Test_SS(float* scaleSpace)
{
	if (l>0)
	{
		char filename[256];
		sprintf(filename, "Tests/BuildSS/Resultats/%d.pgm", l);
		write_float_pgm(scaleSpace, 6*352, 6*288, filename,1);
	}
	l++;
}

void Test_DoG(float* DoG)
{
	char filename[256];
	sprintf(filename, "Tests/DoG/Resultats/%d.pgm", m);
	m++;
	write_float_pgm(DoG, 5 * 352, 6 * 288, filename,1);
}

void Test_Extrem(pointList* KeyPointList)
{
	int i;
	FILE* out_file;
	char filename[256];
	sprintf(filename, "Tests/Extrem/Resultats/%d.txt", n);
	n++;
	out_file = fopen(filename, "wb");
	if (!out_file){
		fprintf(stderr, "Fail to open file: %s\n", filename);
		exit(1);
	}
	for (i = 0; i < KeyPointList->size; i++)
	{
		fprintf(out_file, "%d : %d %d\n", i, (int)KeyPointList->list[i].x, (int)KeyPointList->list[i].y);
	}
	fclose(out_file);
}
