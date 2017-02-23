#include <iostream>
#include "Deque.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv){
    char temp;
    char changed;
    Deque<char> dq_temp;
    Deque<char> dq_changed;
    Deque<char>::Iterator itr_temp;
    Deque<char>::Iterator itr_changed;
    bool isPalindrome;
    
    isPalindrome = true;
    while(cin >> temp){
        
        dq_temp.addLast(temp);
        
        switch(temp){//change the base.
            case 'A':
                changed = 'T';
                break;
            case 'T':
                changed = 'A';
                break;
            case 'C':
                changed = 'G';
                break;
            case 'G':
                changed = 'C';
                break;
            default:
                changed = ' ';
                isPalindrome = false;//wrong input would result non-Palindrome.
                break;
        }
        dq_changed.addFirst(changed);//reverse the sequence.
    }
    
    //test if they are Palindrome.
    itr_temp = dq_temp.iterator();
    itr_changed = dq_changed.iterator();
    for(int i = 0;i != dq_temp.size(); ++i, ++itr_temp, ++itr_changed){
        if(*itr_changed != *itr_temp){//if the input char is wrong, then some elements in dq_temp and dq_changed must be different resulting in non-Palindrome.
            isPalindrome = false;
            break;
        }else if(i == dq_temp.size() -1) isPalindrome = true;//all element are the same.
        //and we can see that, if the input is char ' ' (space), we set it to be palindrome by default.
        //For other wrong input, we set it to be non-palindrome.
    }
    
    cout << ((isPalindrome ==1)? "true" :"false") << endl;
    
}
