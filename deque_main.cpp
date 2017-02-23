
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Deque.h"
#include <assert.h>
/*
 This main program only checks your class, functions' signatures correct or not.
 To check the correctness of your program, you may need to use more complicated examples.
 */

int main(int argc, char ** argv){
    srand((unsigned)time(NULL));
    
    Deque<char> q;
    cout <<"memory cost: " << sizeof(q) <<endl;
    cout << "Empty? "<< q.isEmpty() << endl;
    cout << "Size? " << q.size() << endl;
    q.addFirst('a');
    q.addFirst('b');
    q.addLast('c');
    q.addLast('d');
    q.addFirst('e');
    cout << "Empty? " << q.isEmpty() << endl;
    cout << "Size? " << q.size() << endl;

    Deque<char>::Iterator itr = q.iterator();
    cout << "deque : " ;
    for(int i = 0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    cout << "remove first : " << q.removeFirst() << endl;
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    cout << "remove last " << q.removeLast() << endl;
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    cout <<"remove LFL : " << q.removeLast() << " ";
    cout << q.removeFirst()<<" ";
    cout <<q.removeLast()<<endl;
    
    
    //try to remove a element from an empty list.
    try {
        cout <<q.removeLast()<<endl;
    }
    catch(exception& e){
        cout <<e.what()<<endl;
    }
    
    try {
    cout << q.removeFirst()<<endl;
    }
    catch(exception& e){
        cout << e.what() <<endl;
    }

    //insert element again.
    cout << "Empty? "<< q.isEmpty() << endl;
    cout << "Size? " << q.size() << endl;
    q.addFirst('a');
    q.addFirst('b');
    q.addLast('c');
    q.addLast('d');
    q.addFirst('e');
    q.addFirst('f');
    q.addFirst('g');
    q.addFirst('h');
    q.addFirst('i');
    q.addFirst('j');
    q.addLast('k');
    q.addLast('l');
    
    cout << "Empty? " << q.isEmpty() << endl;
    cout << "Size? " << q.size() << endl;
    
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    
    //remove first half.
    for(int i = 0; i !=6 ;++i){
        q.removeFirst();
    }
    
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    cout << "Size? " << q.size() << endl;
    
    //remove and add.
    cout << "remove first: "<< q.removeFirst() <<endl;
    
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    cout << "Size? " << q.size() << endl;

    q.addFirst('z');
    
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    cout << "Size? " << q.size() << endl;
    
    //add and remove
    q.addLast('x');
    
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    cout << "Size? " << q.size() << endl;
    
    cout << "remove last: "<< q.removeLast() <<endl;
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size();i++){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;
    cout << "Size? " << q.size() << endl;
    
    
    //test iterator range.
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size() + 10;i++){
        cout << *itr << " ";
        ++itr;//if ++itr makes the iterator exceeding the range of list, then the iterator remiains unchanged.
    }
    cout << endl;
    
    //construction of the iterator
    itr = q.iterator();
    Deque<char>::Iterator itr2 = itr;
    cout << "deque : ";
    for(int i = 0; i < q.size() + 10;i++){
        cout << *itr2 << " ";
        ++itr2;//if ++itr makes the iterator exceeding the range of list, then the iterator remiains unchanged.
    }
    cout << endl;
    
    itr = q.iterator();
    Deque<char>::Iterator itr3;
    itr3 = itr;
    cout << "deque : ";
    for(int i = 0; i < q.size() + 10;i++){
        cout << *itr3 << " ";
        ++itr3;//if ++itr makes the iterator exceeding the range of list, then the iterator remiains unchanged.
    }
    cout << endl;
    
    //test postfix increment.
    itr = q.iterator();
    cout << "deque : ";
    for(int i = 0; i < q.size() + 10;i++){
        cout << *itr << " ";
        itr++;//if ++itr makes the iterator exceeding the range of list, then the iterator remiains unchanged.
    }
    cout << endl;
    
    
    return 0;
}
