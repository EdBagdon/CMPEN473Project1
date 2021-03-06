#pragma once
//myschedule.h
/* Students need to define their own data structure to contain
   and access objects from 'thread class'. The 'CreateThread()' 
   function should insert the threads into the student defined
   data structure after creating them.
   They are allowed to add any additional functionality (only 
   declaration in this file, define in 'myschedule.cpp')
   which they might find helpful.*/

#include "scheduler.h"
//#include <vector>
//#include <list>

//Define your data structure here.
typedef struct node{
	struct ThreadDescriptorBlock ThreadInfo;
//	struct node* prev;
	struct node* next;
}node;


class MyScheduler: public Scheduler {
private:
	
	node* head = NULL;
	//Holder holdee;
	
public:
	
	MyScheduler(Policy p, unsigned int n) : Scheduler(p, n) {}
	bool Dispatch(); //Function to implement scheduling policy and to keep a check on processed threads
	void CreateThread(int arriving_time, int remaining_time, int priority, int tid); //Function to create threads and insert them in student defined data structure

	//Declare additional methods(s) below if needed.
	bool FCFS_fun();
	bool STRFwoP_fun();
	bool STRFwP_fun();
	bool PBS_fun();
};
