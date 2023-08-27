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
		void deletion() {
			if ( front == -1 ) {
				cout << "Queue is empty!\n" ; 
			}
			else {
				queue->deletion( queue->new_array[front] ) ; 
				front++ ; 
				if ( front > rear ) {
					front = rear = -1 ; 
					}
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
}; 

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
}
