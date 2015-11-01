public class JavaThreads{

	static int  range;

	static int  thread_num;
    

	static boolean isPrime(int num){

		for(int i = 2; i < num; i++){

			if(num % i == 0)
			return false;
		}
        
		return true;
	}

    
	static class PrimeThread extends Thread{

		int  tid;

		PrimeThread(int thread_id){

			tid = thread_id;
		}

		public void run(){   
        
			int min = (tid*(range/thread_num))+1;
			int max = (tid+1)*(range/thread_num);

			System.out.printf(" THREAD#%d : ", tid);

			for(int i = min; i <= max; i++){

				if(isPrime(i))
					System.out.printf("%3d ", i);
			}
            
			System.out.println();
		}
	}


	public static void main(String[] args) {

		if(args.length != 2){
            
			System.out.print("\nINVALID NUMBER OF ARGS!\n\n");
			System.exit(-1);
		}
        

		range = Integer.parseInt(args[0]);

		thread_num = Integer.parseInt(args[1]);
        
        
		if(thread_num > range){

			System.out.print("\nNUMBER OF THREADS EXCEEDS RANGE!\n");
			System.exit(-1);
		}


		for(int i = 0; i < 63; i++)
			System.out.print('-');

		System.out.print("\nComputing primes between 1 and ");
		System.out.printf("%3d with the use of %3d THREADS.\n",
		                  range, thread_num);

		for(int i = 0; i < 63; i++)
			System.out.print('-');

		System.out.println();


		for(int i = 0; i < thread_num; i++)
			(new PrimeThread(i)).start();
	}
}
