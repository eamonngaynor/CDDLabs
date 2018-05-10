/*! 


Author: Eamonn Gaynor

Date: 08/10/2018

File: mutex.cpp

Brief: This program will demonstrate Mutual Exlusion using the Semaphore class

Bugs: N/A

Licence: GNU (General Public License)


*/



#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>

int count = 0; 


void taskOne(std::shared_ptr<Semaphore> mutex)
{
  
  mutex->Wait();
  /**< Critical section */
  count += 1;
  std::cout << count;
  mutex->Signal();
  
  
}

int main(void)
{
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex( new Semaphore);
  /**< Launch the threads  */
  mutex->Signal();
  threadOne=std::thread(taskOne, mutex);
  threadTwo=std::thread(taskOne, mutex);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
