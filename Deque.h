
#ifndef Deque_h
#define Deque_h
#include <iostream>
#include <stdexcept>

using namespace std;
using std::runtime_error;


template<typename T>
struct node{
    T elem;
    node<T>* next;
    node<T>* prev;
};


template<typename T>
class Deque{
public:
    //constructor.
    Deque();
    //desctructor.
    ~Deque();
    //return: if deque is empty or not.
    bool isEmpty() const;
    //return: the size of deque.
    int size() const;
    //add element to deque in the front.
    void addFirst(T);
    //add element to deque at the end.
    void addLast(T);
    //remoe the first element.
    T removeFirst();
    //remoe the last element.
    T removeLast();
    //iterator class, which can be applied to algorithms implementation.
    class Iterator;
    //return the position of the first element.
    Iterator iterator();
    
private:
    int length;
    node<T>* first;
    node<T>* last;
    
};

/**Iterator implementation**/
template<typename T>
class Deque<T>::Iterator{
public:
    //constructor.
    Iterator();
    Iterator(node<T>*);
    Iterator(const Iterator&);
    ~Iterator();
    
    //arithmtic operator.
    Iterator operator++();
    Iterator operator++(int);
    Iterator operator--();
    Iterator operator--(int);
    Iterator operator=(const Iterator&);
    
    //dereference operator
    T& operator*();
    T& operator->();
    
    node<T>* get() const {return curN;}
private:
    node<T>* curN;
    
};

template<typename T>
Deque<T>::Iterator::Iterator(){
    curN = NULL;
}

template<typename T>
Deque<T>::Iterator::Iterator(node<T>* p){
    curN = p;
}

template<typename T>
Deque<T>::Iterator::Iterator(const Iterator& itr){
    curN = itr.get();
}

template<typename T>
Deque<T>::Iterator::~Iterator(){
    curN = NULL;
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator++(){
    if(curN->next != NULL){//prevent the iterator exceeding the range of the list.
        curN = curN->next;
    }
    return *this;
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator++(int){
    Iterator temp = *this;
    if(curN->next != NULL){//prevent the iterator exceeding the range of the list.
        curN = curN->next;
    }
    return temp;
}


template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator--(){
    if(curN->prev != NULL){//prevent the iterator exceeding the range of the list.
        curN = curN->prev;
    }
    return *this;
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator--(int){
    Iterator temp = *this;
    if(curN->prev != NULL){//prevent the iterator exceeding the range of the list.
        curN = curN->prev;
    }
    return temp;
}


template<typename T>
typename Deque<T>::Iterator Deque<T>::Iterator::operator=(const Iterator& itr){
    curN = itr.get();
    return *this;
}


template<typename T>
T& Deque<T>::Iterator::operator*(){//dereference would return the object.
    return curN->elem;
}

template<typename T>
T& Deque<T>::Iterator::operator->(){//dereference would return the object.
    return curN->elem;
}

template<typename T>
typename Deque<T>::Iterator Deque<T>::iterator(){//return the first element position.
    Deque<T>::Iterator iter(first);
    return iter;
}

/**Deque implementation**/
template<typename T>
Deque<T>::Deque(){//initialize deque.
    length = 0;
    first = NULL;
    last = NULL;
}

template<typename T>
Deque<T>::~Deque(){
    while(length != 0){
        removeLast();//if deque is not empty, keep deleting elements in it.
        //when we delete the last element, allocated space would also be freed.
    }
}

template<typename T>
bool Deque<T>::isEmpty() const{
    if(length == 0){//if the length is 0, deque is empty.
        return true;
    }
    return false;
}

template<typename T>
int Deque<T>::size() const{
    return length;//return the number of the objects.
}

template<typename T>
void Deque<T>::addFirst(T item){
    if(first == NULL){//if deque is empty.
        first = new node<T>;//allocate new space for first.
        last = first;//for only one element, both first and last point to it.
        first->elem = item;//store the element into it.
        first->next = NULL;
        first->prev = NULL;
    }else{//if deque is non-empty.
        node<T>* ptrNew = new node<T>;//allocate new space for a new pointer.
        ptrNew->elem = item;//store the element into it.
        //changed their relations, such that newly inserted object become the first one.
        ptrNew->next = first;
        ptrNew->prev = NULL;
        first->prev = ptrNew;
        first = ptrNew;
    }
    length++;
}


template<typename T>
void Deque<T>::addLast(T item){
    if(first == NULL){//if deque is empty.
        last = new node<T>;//allocate new space for last.
        first = last;//for only one element, both first and last point to it.
        last->elem = item;//store the element into it.
        last->next = NULL;
        last->prev = NULL;
    }else{//if the list is non-empty.
        node<T>* ptrNew = new node<T>;//allocate new space for a new pointer.
        ptrNew->elem = item;//store the element into it.
        //changed their relations, such that newly inserted object become the last one.
        ptrNew->prev = last;
        ptrNew->next = NULL;
        last->next = ptrNew;
        last = ptrNew;
        
    }
    length++;
}

template<typename T>
T Deque<T>::removeFirst(){
    if(first == NULL) throw runtime_error("no element to remove!!");
    T DelItem = first->elem;
    node<T>* temp = first;
    if(first->next == NULL){
        //if the list has only one element left, both last and first pointer are pointing to this elment.
        //delete one more time, the whole list is empty, so both last and first pointer should be set to be NULL.
        last = NULL;
        first = NULL;
        delete temp;
        length--;
        return DelItem;
    }else{
        first = first->next;
        first->prev = NULL;
        delete temp;
        length--;
        return DelItem;
    }
}

template<typename T>
T Deque<T>::removeLast(){
    if(last == NULL) throw runtime_error("no element to remove!!");
    T DelItem = last->elem;
    node<T>* temp = last;
    if(last->prev == NULL){
        //if the list has only one element left, both last and first pointer are pointing to this elment.
        //delete one more time, the whole list is empty, so both last and first pointer should be set to be NULL.
        first = NULL;
        last = NULL;
        delete temp;
        length--;
        return DelItem;
    }else{
        node<T>* temp = last;
        last = last->prev;
        last->next = NULL;
        delete temp;
        length--;
        return DelItem;
    }
}







#endif /* Deque_h */
