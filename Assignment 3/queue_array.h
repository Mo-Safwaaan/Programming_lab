#ifndef QUEUE_H
#define QUEUE_H

#include <iostream> 
#include "array.h" 
using namespace std ; 

template < typename T > 
class Queue {
	private : 
		int front ; 
		int rear ;
	      	array<T>* queue ; 	
	public : 
		Queue() {
			this->front = -1 ; 
			this->rear = -1 ; 
			queue = new array<T>(100) ; 
			 
		}
		void insert( T val ){
			rear++ ; 
			queue->insert( rear , val ) ; 
			if ( front == -1 ){
				front++ ; 
			} 
		}
		int deletion() {
			if ( front == -1 ) {
				cout << "Queue is empty!\n" ;
			        return -1 ; 	
			}
			else {	
				int front_element = queue->new_array[front] ; 
				queue->deletion( front_element ) ; 
				front++ ; 
				if ( front > rear ) {
					front = rear = -1 ; 
					}
				return front_element ; 
				}
		}
		void display() {
			if ( front == -1 ) {
				cout << "Queue is empty!\n" ; 
			}
			else {
				for( int i = front ; i <= rear ; i++) {
					cout << queue->new_array[i] << " " ; 
				} 
				cout << endl ; 
			}
		}
		bool is_empty() {
			if ( front == -1 && rear == -1 ) return true ; 
			else return false ;  
		}
}; 

#endif 
/*

int main() {
	Queue<int> q ;
        q.insert(10) ;
        q.insert(20) ;
        q.insert(30) ;
        cout << "Inserted 10 , 20 , 30 \n" ;
        q.display() ;
        cout << "Inserted 40 \n" ;
        q.insert(40) ;
        q.display() ;
        q.deletion() ;
        cout << "Deleted 10 \n" ;
        q.display() ;
        q.deletion() ;
        cout << "Deleted 20 \n"  ;
        q.display() ;
        cout << "Deleted 30 \n" ;
        q.deletion() ;
        q.display() ;
        cout << "Deleted 40 \n" ;
        q.deletion() ;
        q.display() ; 
	return 0 ; 
} */
