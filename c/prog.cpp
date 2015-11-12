#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <semaphore.h>
#include <vector>


int  range;

int  thread_num;

pthread_t  tid[100];

sem_t  sem;


bool isPrime(int num){
	
	for(int i = 2; i < sqrt(num) +1; i++){

		if(num % i == 0)
			return false;
	}
	
	return true;	
}

void* searchRange(void *param){

	long int tid =  (long int)param;

	int min = (tid*(range/thread_num))+1;
	int max = (tid+1)*(range/thread_num);


	std::vector<int>  primes;

	for(int i = min; i <= max; i++){

		if(isPrime(i))
			primes.push_back(i);

	}


	sem_wait(&sem);		// ENTERING CRITICAL REGION! ------------------------

	printf(" THREAD#%d : ", tid);

	while(!primes.empty()){

		printf("%3d ", primes.back());
		primes.pop_back();
	}

	sem_post(&sem);		// ------------------------- EXITING CRITICAL REGION!


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


	sem_init(&sem, NULL, 1);


	for(int i = 0; i < thread_num; i++){

		pthread_create(&tid[i], NULL, searchRange, (void*)i);
	}


	for(int i = 0; i < thread_num; i++){

		pthread_join(tid[i], NULL);
	}


	return 0;
}
