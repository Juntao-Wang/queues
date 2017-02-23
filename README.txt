/**********************************************************************
 *  Randomized Queues and Deques
 **********************************************************************/

Name: WANG Juntao
ID: 20255651
Login: jwangcc
Hours to complete assignment (optional): 


/**********************************************************************
 *  Compile and run
 **********************************************************************/
% make

% ./rand_main 
% ./deque_main

% echo (input-characters) | ./Subset (input-positive-int-argument)
% echo (input-characters) | ./Palindrome

Note: rand_main and deque_main are the test programs for the RandomizedQueue
class and Deque class respectively.
Subset and Palindrome are the client programs.



/**********************************************************************
 *  Explain briefly how you implemented the randomized queue and deque.
 *  Which data structure did you choose (array, linked list, etc.)
 *  and why?
 **********************************************************************/
Randomized queue:
I choose array to implement randomized queue, for it allows a constant time
complexity to randomly access and remove an item from an array, while linked
list would cost O(N) time complexity to remove an item from middle. Where N is 
the number of stored objects.

In RandomizedQueue class, I used private data member length to record the 
number of stored objects which could indicate whether the container is empty 
or not, used array to store each objects, and used arr_len to indicate the length 
of the array. 
Using array to store objects could encounter the condition that the length
of the array is not long enough to store the objects, while the number of
objects is keep increasing. To solve this problem, in the process of enqueuing,
I would compare the current number of objects and the length of the array,
when the number of objects is the same as the length of the array, I would 
construct a new array with doubled length, and copy the objects from former one
to later one, and then delete the former one. By doing this, the length of the 
array is ensured to be large enough to store the objects. The way that I delete 
the object from the array is that, I used a type T object constructed by default
to clean up the space where the removed object used to be stored.Because this 
the same as, when allocate the array (new T[arr_len]), each positions filled up
with a type T object which is constructed by default. Moreover, this process only
cost O(1) time and O(1) extra space.
This class also provide a iterator to separate the objects and the algorithms.
For our container is an array, it is convenient that I just used pointer to the
objects as the iterator, and it can do its job well. And client should notice 
that dereference a iterator which is beyond the scope of the list is undefined 
behaviour.


deque:
I choose linked list to implement deque, for it allows a constant time 
complexity to add/move object to the front or to the end. While array would 
cost O(N) to add object to the front. Where N is the number of stored objects.

In deque I used a private data member length to record the number of stored objects 
which could indicate whether the container is empty or not. And I also implement
a node class which could store the object information and the pointers to its 
previous object or the next object. For deque class, its data structure is double-
end linked list, which means that for each node would store a pointer pointing to
its previous node, and a pointer pointing to its next node. By doing this, it 
only takes O(1) to add/remove a element from the list. Because we have the information
of the first and last element, what we need to do is only allocate/free the space of
added/removed object, and modify the pointers relation.
This class also provide a iterator class, containing a data member, pointer to 
node, such that client could do algorithms on it or access the object to which
iterator refers. And iterator class also overload some basic arithmetic operators
such that client could use it more naturally and conveniently. i.e. assignment operator
(=), prefix/postfix increment (++itr, itr++), prefix/postfix decrement (--itr, itr--),
dereference operator(*, ->). If the arithmetic operations would make the iterator 
beyond the scope of the list, the iterator would remain unchanged.




/**********************************************************************
 *  Briefly describe why any sequence of N randomized queue operations,
 *  starting from an empty randomized queue, takes O(N) time.
 **********************************************************************/
For any operation except enqueue and dequeue, takes only O(1) time. So firstly,
for any sequence of N operations without enqueue and dequeue operations takes 
O(N) time.
For enqueue operation, to some stages we have to enlarge the list (details 
can be found above), and copy the memory, so starting from an empty list, 
a sequence of N enqueue operations would take at most 
t < N + 1/2 * N + 1/4 * N + ... + 1/(2^k) * N + c * N < 2 * N + c * N
= O(N). Where c is a constant.
And this is the same for dequeue operation.

So combining the previous cases, we can conclude that, for any sequence of N 
randomized queue operations take O(N).

/**********************************************************************
 *  Briefly describe why each Deque operation takes O(1) time.
 **********************************************************************/
For each deque operations we only deal with single one object without operating
other objects, such that the operation only takes O(1) time.


/**********************************************************************
 *  How much memory (in bytes) does your data type use to store N items.
 *  Use tilde notation to simplify your answer. Use the memory requirements
 *  for a "typical machine" given in Lecture. In your analysis, don't include
 *  the memory for the items themselves (as this memory is allocated by
 *  the client and depends on the item type.
 *  For a typical machine, refer to page 11 of 
 *  http://www.cs.princeton.edu/courses/archive/spring10/cos226/lectures/02-14Analysis-2x2.pdf 
 **********************************************************************/

Typically, for a 64-bits system.
the size of (int) is 4 bytes.
the size of pointer is 8 bytes.

RandomizedQueue: 
This class has data members:
int length;
T* array;
int arr_len;
Considering the data alignment, before objects have been inserted,
the memory cost is 3 * 8 = 24 bytes.


Dequeue:
This class has data memebers:
int length;
node<T>* first;
node<T>* last;
For it contains pointers and int, data alignment occurs,
so the size of the deque class should be 3 * 8 = 24 bytes. 

For node class's data members:
T elem;
node<T>* prev;
node<T>* next;
So the size of N nodes should be N * (2 * 8 + sizeof(T)) bytes.

For my node class is declared outside the deque class, such that the size of 
deque is only 24 bytes, if we consider all the space that needed to store 
the data, then it should be 24 + N(16 * sizeof(T)) bytes.


/**********************************************************************
 *  Known bugs / limitations.
 **********************************************************************/
limitation:
RandomizedQueue:
I only use the pointer (index of the array) to objects as the provided iterator. 
Because it can do the job sufficiently well. e.g. increment operations, decrement
operations, dereference operations.
However, the limitation is that if the iterator exceeds the length of the array,
the dereference operations are undefined. And this won't cause the compilation error
or run time error.

Deque:
For the iterations class, I only provides some basic arithmetic operations, which 
can do sufficiently well job. i.e. increment/decrement operations, dereference operations.
While comparison operations I did not implement, for the types of stored objects 
is unknown, for some types, comparison definition might be different, such that, 
comparison behaviour somehow should be implemented by the users.

/**********************************************************************
 *  List whatever help (if any) that you received and from whom,
 *  including help from staff members or lab TAs.
 **********************************************************************/
None.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
None.




/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
This project enhances my understanding of template class and operator overload.
Good!