-----------------------------------------------------------------
                                     _      _   ___    __ ___ 
                                    | |    /_\ | _ )  /  \_  )
                                    | |__ / _ \| _ \ | () / / 
                                    |____/_/ \_\___/  \__/___|
                          
-----------------------------------------------------------------
Author: 	Matt W. Martin, 4374851
		kaethis@tasmantis.net

Project:	CS3790, Lab 02:
		Calculating Primes w/ THREADS (now w/ SEMAPHORES)

Date Issued:	
Date Archived:	

File:		README.txt


Comments:	This assignment consists of two programs:

		- cthreads:	This C++ program calculates the
				primes within a certain range
				(starting from 1 onward) distr-
				ibuted amongst multiple threads.

		- JavaThreads:	Virtually identical to "cthreads"
				except implemented in the Java
				language.


Instructions:	Executing the program (either "cthreads" or
		"JavaThreads") requires two integer command-
		line arguments: the first being the end of the
		range of numbers to calculate the primes from,
		and the second being the number of threads used
		to calculate the primes.  For example:

		  cthreads:	./cthreads 100 4

		  JavaThreads:	./java JavaThreads 100 4

		In both cases, the program will calculate the
		prime numbers between 1 and 100 using 4 threads.
		NOTE:	Both source files, as well as their
			respective MAKEFILES, are located in
			their own separate directories.


MAKE:		In ./c directory:

		  ./cthreads	Compiles the cthreads program.
		  ./clean	Removes the program.

		In ./java directory:

		  ./javathreads	Compiles the JavaThreads prog.
		  ./clean	Removes program and class files.

		In top-level (.) directory:
		
		  ./archive	Creates archive in parent-dir.


GIT Repository:	 https://github.com/kaethis/CS3790_Lab02.git


Notes:		- I discovered an interesting oddity with both
		  my LINUX and OS X systems: they both seem to
		  schedule user-level threads in a predictable
		  fashion.  Every time I executed the program,
		  it would always yield the same order of output
		  (which, given the random nature of threads in
		  respect to they way they're scheduled, simply
		  shouldn't happen).  This requires some more
		  investigation as to why this is the case.

		- It wasn't required for this assignment, but I
		  implemented semaphores for the region of code
		  that dealt with outputing the primes to the
		  console; without it, threads had a tendency
		  to interrupt each other's output when writing
		  on the same line.  I made sure not to include
		  the primes' calculation inside this critical
		  region, as this would defeat the purpose of
		  the impementations of the threads.
