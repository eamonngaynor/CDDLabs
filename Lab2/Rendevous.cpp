/*! 


Author: Eamonn Gaynor

Date: 08/10/2018

File: Semaphore.cpp

Brief: Rendezvous - Demonstrating the Rendezvous pattern

Bugs: N/A

Licence: GNU (General Public License)


*/


#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived)
{
  std::cout <<"A has arrived\n";
  aArrived -> Signal();
  std::cout << "B is in wait\n";
  bArrived -> Wait();
  std::cout << "A Done\n";
  
  
  }


void taskTwo(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived)
{
  std::cout <<"B has arrived\n";
  bArrived -> Signal();	
  std::cout << "A is in wait\n";
  aArrived -> Wait();
  std::cout << "B Done\n";
  
    
}

int main(void)
{
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> aArrived( new Semaphore);
  std::shared_ptr<Semaphore> bArrived( new Semaphore);
  /**< Launch the threads  */

  threadOne=std::thread(taskTwo,aArrived, bArrived);
  threadTwo=std::thread(taskOne,aArrived, bArrived);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
