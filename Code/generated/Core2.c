/** 
 * @file Core2.c
 * @generated by CPrinter
 * @date Sun May 03 22:33:32 CEST 2015
 */

#include "../include/x86.h"

// Core Global Declaration
extern pthread_barrier_t iter_barrier;
extern int stopThreads;
extern char *const WritePGM_init_b__WritePGM__0;  // WritePGM_init_b > WritePGM size:= 101376*char defined in Core0
extern sem_t sem_0_SSRE; 
extern char SharedMem[89186408]; //  size:= 89186408*char
extern uchar *const init_out__g__0;  // WritePGM_init_g_init_out > WritePGM_g size:= 101376*uchar defined in Core0
extern char *const WritePGM_init_r__WritePGM__0;  // WritePGM_init_r > WritePGM size:= 101376*char defined in Core0
extern sem_t sem_1_SSRE; 
extern int *const init_out__in__0;  // octavesH_init_in_init_out > octavesH_in size:= 6*int defined in Core0
extern int *const out1__octavesH__0;  // octavesH_out1 > BuildOB_octavesH size:= 6*int defined in Core0
extern int *const out2__octavesH__0;  // octavesH_out2 > BuildSS_octavesH size:= 6*int defined in Core0
extern int *const out3__octavesH__0;  // octavesH_out3 > DoG_octavesH size:= 6*int defined in Core0
extern int *const out4__octavesH__0;  // octavesH_out4 > Extreme_octavesH size:= 6*int defined in Core0
extern int *const out5__end_in__0;  // octavesH_out5 > octavesH_end_out5_end_in size:= 6*int defined in Core0
extern char *const octavesH__octavesH_end_out5__0;  // octavesH > octavesH_end_out5 size:= 24*char defined in Core0
extern char *const octavesH__Extreme__0;  // octavesH > Extreme size:= 24*char defined in Core0
extern char *const octavesH__DoG__0;  // octavesH > DoG size:= 24*char defined in Core0
extern char *const octavesH__BuildSS__0;  // octavesH > BuildSS size:= 24*char defined in Core0
extern char *const octavesH__BuildOB__0;  // octavesH > BuildOB size:= 24*char defined in Core0
extern uchar *const init_out__r__0;  // WritePGM_init_r_init_out > WritePGM_r size:= 101376*uchar defined in Core0
extern uchar *const init_out__b__0;  // WritePGM_init_b_init_out > WritePGM_b size:= 101376*uchar defined in Core0

// Core Global Definitions
char *const FIFO_Head_Render_end_g__Writ__0 = (char*) (SharedMem+58954512);  // FIFO_Head_Render_end_g > WritePGM_init_g size:= 101376*char
char *const FIFO_Head_Init_end_octavesH___0 = (char*) (SharedMem+88983560);  // FIFO_Head_Init_end_octavesH_g > octavesH_init_in size:= 24*char
sem_t sem_3_SSRE;
sem_t sem_4_SSRE;
sem_t sem_5_SSRE;
sem_t sem_6_SSRE;
sem_t sem_7_SSRE;

void *computationThread_Core2(void *arg){
	// Initialisation(s)
	fifoInit(FIFO_Head_Render_end_g__Writ__0, 101376*sizeof(char), NULL, 0);
	fifoInit(FIFO_Head_Init_end_octavesH___0, 24*sizeof(char), NULL, 0);
	sem_init(&sem_3_SSRE,0,0/*init_val*/); // octavesH > octavesH_end_out5
	sem_init(&sem_4_SSRE,0,0/*init_val*/); // octavesH > Extreme
	sem_init(&sem_5_SSRE,0,0/*init_val*/); // octavesH > DoG
	sem_init(&sem_6_SSRE,0,0/*init_val*/); // octavesH > BuildSS
	sem_init(&sem_7_SSRE,0,0/*init_val*/); // octavesH > BuildOB

	// Begin the execution loop 
	while(1){
		pthread_barrier_wait(&iter_barrier);
		if(stopThreads){
			pthread_exit(NULL);
		}
		receiveStart(); // Core1 > Core2: WritePGM_init_b__WritePGM__0 
		receiveEnd(&sem_0_SSRE/*ID*/); // Core1 > Core2: WritePGM_init_b__WritePGM__0 
		fifoPop(init_out__g__0, FIFO_Head_Render_end_g__Writ__0, 101376*sizeof(char), NULL, 0);
		receiveStart(); // Core0 > Core2: WritePGM_init_r__WritePGM__0 
		receiveEnd(&sem_1_SSRE/*ID*/); // Core0 > Core2: WritePGM_init_r__WritePGM__0 
		fifoPop(init_out__in__0, FIFO_Head_Init_end_octavesH___0, 24*sizeof(char), NULL, 0);
		// Broadcast octavesH
		{
			memcpy(out1__octavesH__0+0, init_out__in__0+0, 6*sizeof(int));
			memcpy(out2__octavesH__0+0, init_out__in__0+0, 6*sizeof(int));
			memcpy(out3__octavesH__0+0, init_out__in__0+0, 6*sizeof(int));
			memcpy(out4__octavesH__0+0, init_out__in__0+0, 6*sizeof(int));
			memcpy(out5__end_in__0+0, init_out__in__0+0, 6*sizeof(int));
		}
		sendStart(&sem_3_SSRE/*ID*/); // Core2 > Core1: octavesH__octavesH_end_out5__0 
		sendEnd(); // Core2 > Core1: octavesH__octavesH_end_out5__0 
		sendStart(&sem_4_SSRE/*ID*/); // Core2 > Core0: octavesH__Extreme__0 
		sendEnd(); // Core2 > Core0: octavesH__Extreme__0 
		sendStart(&sem_5_SSRE/*ID*/); // Core2 > Core0: octavesH__DoG__0 
		sendEnd(); // Core2 > Core0: octavesH__DoG__0 
		sendStart(&sem_6_SSRE/*ID*/); // Core2 > Core3: octavesH__BuildSS__0 
		sendEnd(); // Core2 > Core3: octavesH__BuildSS__0 
		sendStart(&sem_7_SSRE/*ID*/); // Core2 > Core1: octavesH__BuildOB__0 
		sendEnd(); // Core2 > Core1: octavesH__BuildOB__0 
		write_ppm(init_out__r__0,init_out__g__0,init_out__b__0,352/*w*/,288/*h*/); // WritePGM
	}
}
