
#ifndef RandomizedQueue_h
#define RandomizedQueue_h
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;
using std::runtime_error;

template<typename T>
class RandomizedQueue{
public:
    typedef T* Iterator;//we can simply use T* as the iterator.
    //constructor.
    RandomizedQueue();
    //desctrutor
    ~RandomizedQueue();
    //return: if RandomizedQueue is empty.
    bool isEmpty() const;
    //return: the size of RandomizedQueue.
    int size() const {return length;}
    //enqueue element into RandomizedQueue.
    void enqueue(T item);
    //randomly delete an element from RandomizedQueue, and return it.
    T dequeue();
    //randomly pick an element from RandomizedQueue, and return it.
    T sample() const;
    //provide an iterator to do algorithms.
    Iterator iterator();
    //return: the size of the array.
    int arr_size() const {return arr_len;}
private:
    int length;
    T* array;
    int arr_len;
    
    
};

template<typename T>
RandomizedQueue<T>::RandomizedQueue(){
    length = 0;
    arr_len = 0;
    array = NULL;
}

template<typename T>
RandomizedQueue<T>::~RandomizedQueue(){
    delete [] array;
}


template<typename T>
bool RandomizedQueue<T>::isEmpty() const{
    return (length == 0);
}


template<typename T>
void RandomizedQueue<T>::enqueue(T item){
    if(arr_len == 0){//if the array is empty.
        arr_len++;
        array = new T[arr_len];
        array[arr_len-1] = item;
    }
    if(length == arr_len){//if the array is full. Enlarge its size.
        arr_len = 2* length;
        T* temp = array;
        array = new T[arr_len];
        for (int i = 0; i != length ; ++i){//copy the items from old array to the new one.
            array[i] = temp[i];
        }
        //delete the old array.
        delete [] temp;
    }
    length++;
    array[length-1] = item;
    
}

template<typename T>
T RandomizedQueue<T>::dequeue(){
    if(length == 0) throw runtime_error("the list is empty!!");//length cannot be 0.
    int pos;//position of the tiem about to delete.
    pos = ((1.0 * rand() / RAND_MAX) * length);
    //swap it with the last element in the array and delete it at the last position.
    T cleanUp;
    /*ojbect with type T, which is constructed by default,
     *could be used to clean up the space where the removed
     *object used to be stored. Because this the same as
     *when allocate the array (new T[arr_len]), each position
     *is filled up with a type T object which is constructed by default.
     *Moreover, this process only cost O(1) time and O(1) extra space.*/
    T tempItem = array[pos];
    array[pos] = array[length -1];
    array[length-1] = cleanUp;//we use the a object constructed by default to fill the space.
    length --;
    if(arr_len >= 2*length){//if the array length is too large compared with the number of elements stored, we resize the array.
        arr_len = length;
        T* temp = array;
        array = new T[arr_len];
        for (int i = 0; i != length ; ++i){//copy the items from old array to the new one.
            array[i] = temp[i];
        }
        delete [] temp;
    }
    return tempItem;
    
}

template<typename T>
T RandomizedQueue<T>::sample() const{
    if(length == 0) throw runtime_error("the list is empty!!");//length cannot be 0.
    int pos;//position of the tiem about to delete.
    pos = ((1.0 * rand() / RAND_MAX) * length);
    T tempItem = array[pos];
    return tempItem;
    
}

template<typename T>
typename RandomizedQueue<T>::Iterator RandomizedQueue<T>::iterator(){
    return array;
}

#endif /* RandomizedQueue_h */
