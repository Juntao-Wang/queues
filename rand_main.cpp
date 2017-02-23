
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "RandomizedQueue.h"
using namespace std;

int main(int argc, char ** argv){
    
    srand((unsigned)time(NULL));
    RandomizedQueue<char> rq;
    cout << "Empty? " << rq.isEmpty() << endl;
    cout << "Size? " << rq.size() << endl;
    rq.enqueue('a');
    rq.enqueue('b');
    rq.enqueue('c');
    rq.enqueue('d');
    cout << "Empty? " << rq.isEmpty() << endl;
    cout << "Size? " << rq.size() << endl;
    int i;
    RandomizedQueue<char>::Iterator itr = rq.iterator();
    cout << "queue : ";
    for(i = 0; i < rq.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    cout << "sampling : " ;
    for(i = 0; i < rq.size()*2;i++){
        cout << rq.sample() << " ";
    }
    cout << endl;
    
    cout << "dequeue :  " << rq.dequeue() <<rq.dequeue() <<rq.dequeue() <<rq.dequeue() << endl;
    itr = rq.iterator();
    cout << "queue : ";
    for(i = 0; i < rq.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    //check the size of array.
    cout << "size of the array: ";
    cout << rq.arr_size() <<endl;
    
    //now it is empty, try sample or dequeue.
    try{
        rq.sample();
    }catch(exception& e) {
        cout <<e.what() <<endl;
    }
    
    try{
        rq.dequeue();
    }catch(exception& e) {
        cout <<e.what() <<endl;
    }
    
    cout << "Empty? " << rq.isEmpty() << endl;
    cout << "Size? " << rq.size() << endl;
    rq.enqueue('a'); 
    rq.enqueue('b');
    rq.enqueue('c');
    rq.enqueue('d');
    rq.enqueue('e');
    cout << "Empty? " << rq.isEmpty() << endl;
    cout << "Size? " << rq.size() << endl;
    
    //check the size of array.
    cout << "size of the array: ";
    cout << rq.arr_size() <<endl;
    
    itr = rq.iterator();
    cout << "queue : ";
    for(i = 0; i < rq.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    //add and remove
    cout << "remove: " << rq.dequeue() <<endl;
    
    cout << "size of the array: ";
    cout << rq.arr_size() <<endl;
    
    itr = rq.iterator();
    cout << "queue : ";
    for(i = 0; i < rq.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    rq.enqueue('z');
    
    itr = rq.iterator();
    cout << "queue : ";
    for(i = 0; i < rq.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    //remove and add
    rq.enqueue('x');
    
    itr = rq.iterator();
    cout << "queue : ";
    for(i = 0; i < rq.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    cout << "remove: "<< rq.dequeue() <<endl;
    
    itr = rq.iterator();
    cout << "queue : ";
    for(i = 0; i < rq.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    
    //clean up the array again.
    try{
        cout << "dequeue :  " << rq.dequeue() <<
        rq.dequeue() <<rq.dequeue() <<rq.dequeue()<< rq.dequeue() << endl;
    }catch(exception& e){
        cout << e.what() <<endl;
    }
    
    //try move a empty list.
    try{
        cout << rq.dequeue()<<endl;
    }catch(exception& e){
        cout << e.what() <<endl;
    }
    
    
    return 0;
}
