/**<
#Author: Eamonn Gaynor
#Date created: 08/10/2017
#Bugs: N/A
#Purpose: A mutex file for two threads through one task 
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
