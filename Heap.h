#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};











//CONTENTS OF THE IPP FILE




#include <string>

template<class Pri, class T>
Heap<Pri, T>::Heap(){
	numItems = 0;
	arrSize = START_SIZE;
	std::pair<Pri, T>* backingArray = new std::pair<Pri, T> [arrSize];
}

template<class Pri, class T>
Heap<Pri, T>::~Heap(){
	for (int x = 0; x < arrSize; x++){
		remove();
	}
	delete backingArray;
}

template<class Pri, class T>
void Heap<Pri, T>::grow(){
	std::pair<Pri, T>* newArray = new std::pair<Pri, T>*[(arrSize * 2)];
	for (int x = 0; x < numItems; x++){
		add(backingArray[x]);
	}
}

template<class Pri, class T>
void Heap<Pri, T>::add(std::pair<Pri, T> toAdd){
	numItems++;
	backingArray[numItems - 1] = toAdd;
	bubbleUp(numItems - 1);
}

template<class Pri, class T>
void Heap<Pri, T>::bubbleUp(unsigned long index){
	std::pair<Pri, T> tmp;
	if (backingArray[(index - 1) / 2].Pri < backingArray[index].Pri){
		tmp = backingArray[index];
		backingArray[index] = backingArray[(index - 1) / 2];
		backingArray[(index - 1) / 2] = tmp;
		if ((index - 1) / 2 > 0){
			bubbleUp((index - 1) / 2);
		}
	}
}

template<class Pri, class T>
void Heap<Pri, T>::trickleDown(unsigned long index){
	std::pair<Pri, T> tmp;
	if (backingArray[(2 * index + 2)].Pri > backingArray[index].Pri
		&& backingArray[(2 * index + 2)].Pri > backingArray[(2 * index + 1)].Pri){
		tmp = backingArray[index];
		backingArray[index] = backingArray[(2 * index + 2)];
		backingArray[(2 * index + 2)] = tmp;

		if ((2 * index + 2) < numItems - 1){
			trickleDown(2 * index + 2);
		}
	} else if (backingArray[(2 * index + 1)].Pri > backingArray[index].Pri){
		tmp = backingArray[index];
		backingArray[index] = backingArray[(2 * index + 1)];
		backingArray[(2 * index + 1)] = tmp;
		if ((2 * index + 1) < numItems - 1){
			trickleDown(2 * index + 1);
		}
	}
	

	
}

template<class Pri, class T>
std::pair<Pri, T> Heap<Pri, T>::remove(){
	numItems--;
	std::pair<Pri, T> tmp = backingArray[0];
	backingArray[0] = backingArray[numItems];
	backingArray[numItems].Pri = NULL;
	backingArray[numItems].T = NULL;
	trickleDown(0);
	return tmp;
}

template<class Pri, class T>
unsigned long Heap<Pri, T>::getNumItems(){
	return numItems;
}

