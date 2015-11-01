#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int  range;

int  thread_num;

pthread_t  tid[100];


bool isPrime(int num){
	
	for(int i = 2; i < num; i++){

		if(num % i == 0)
			return false;
	}
	
	return true;	
}

void* searchRange(void *param){

	int tid =  (int)param;

	int min = (tid*(range/thread_num))+1;
	int max = (tid+1)*(range/thread_num);


	printf(" THREAD#%d : ", tid);

	for(int i = min; i <= max; i++){

		if(isPrime(i))
			printf("%3d ", i);

	}

	printf("\n");
}

int main(int argc, char* argv[]){

	if(argc != 3){

		printf("\nINVALID NUMBER OF ARGS!  EXITING.\n\n");
		exit(-1);
	}



	range = atoi(argv[1]);

	thread_num = atoi(argv[2]);

	if(thread_num > range){

		printf("\nNUMBER OF THREADS EXCEEDS RANGE!  EXITING.\n");
		exit(-1);
	}


	printf("---------------------------------------------------------------\n");
	printf("Computing primes between 1 and %3d with the use of %3d THREADS.\n",
	        range, thread_num);
	printf("---------------------------------------------------------------\n");


	for(int i = 0; i < thread_num; i++){

		pthread_create(&tid[i], NULL, searchRange, (void*)i);
	}


	for(int i = 0; i < thread_num; i++){

		pthread_join(tid[i], NULL);
	}


	return 0;
}
