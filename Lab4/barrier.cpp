/*
#Author: Eamonn Gaynor 
#Date created: 18/10/2017
#Bugs: Deadlock reached upon first loop
#Purpose: A reusable barrier class for three threads. 
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0; 

int noOfThreads = 3;

int loop = 0; /* loop intiated to 0, commented out as deadlock reached*/


void taskOne(std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> turnstile, std::shared_ptr<Semaphore> turnstile2)

{
	while(loop <= 2){

		mutex->Wait();
		counter ++; 
		std::cout << "Thread no. "; 
		std::cout << counter;
		std::cout << "\n";
		std::cout << "Thread has reached a barrier and is waiting\n"; 
	  	if(counter == noOfThreads)

			{	
				turnstile2->Wait();   /*Lock the second */
				turnstile->Signal();  /*Unlock the first */
			}

		mutex->Signal();

		turnstile->Wait();	/*First Turnstile */
		turnstile->Signal();
		

		/* Critical Point */
	  

		mutex->Wait();
		counter--;
		if(counter == 0)
			{
				std::cout << "Threads complete\n"; 
				turnstile->Wait();	/*Lock the first */
				loop ++;
				turnstile2->Signal();	/*Unlock the second */
			}

		mutex->Signal();


	 	turnstile2->Wait();	/*Second Turnstile */
		turnstile2->Signal();
		
	}
}
	  


int main()
{
  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> mutex(new Semaphore (1));
  std::shared_ptr<Semaphore> turnstile(new Semaphore(0));
  std::shared_ptr<Semaphore> turnstile2(new Semaphore(1));
  /**< Launch the threads  */
  threadOne=std::thread(taskOne, mutex, turnstile, turnstile2);
  threadTwo=std::thread(taskOne, mutex, turnstile, turnstile2);
  threadThree=std::thread(taskOne, mutex, turnstile, turnstile2);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  return 0;
}
