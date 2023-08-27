#include<iostream> 
#include "single_linked_list.h" 

using namespace std ;

template < typename T > 
class queue{ 
	private : 
		linked_list<T> q ; 
	public : 
		void insert( T val ) {
			q.insert_end( val ) ; 
		}

		void deletion() {
			if ( q.head == NULL ) {
				cout << "Queue is empty!\n" ; 
				return ; 
			}
			else {
				q.deletion( q.head->data ) ; 
			}
		}

		void display() {
			if ( q.head == NULL ){
                                cout << "Queue is empty!\n" ;
                                return ;
                        }
                        else {
                                node<T>* temp = q.head ;
                                while( temp!=NULL ) {
                                        cout << temp->data << " " ;
                                        temp = temp->next ;
                                }
                                cout << endl ;
                        }

		}
};

int main() {
        queue<int> q ;
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
	
}

