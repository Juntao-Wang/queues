#include <iostream>
#include "RandomizedQueue.h"
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>


using namespace std;

int main(int argc, char** argv){
    if (argc <2){
        cout << "wrong argument! Please pass a positive number" <<endl;
        exit(255);
    }
    
    srand(time(NULL));
    int numOfSub;
    string temp;
    RandomizedQueue<string> rq;
    istringstream trial(argv[1]);
    if (!(trial >> numOfSub)) cerr << "Invalid number " << argv[1] << '\n';
    if (numOfSub < 0){
        cout << "wrong argument! Please pass a positive number" <<endl;
        exit(255);
    }
    while(cin >> temp){
        rq.enqueue(temp);
    }
    
    if(numOfSub > rq.size()) numOfSub = rq.size();
    
    for(int i = 0; i !=numOfSub; ++i){//use dequeue such that the each element would only appear once, and it is random.
        cout << rq.dequeue() <<endl;
    }
    
    
    
}
