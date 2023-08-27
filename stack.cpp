#include <iostream>
#include "single_linked_list.h" 
using namespace std ; 

template < typename T > 
class stack{
	private : 
		linked_list<T> st ;

	public : 	
		void push( T val ) {
			st.insert_front( val ) ;
		}
		
		void pop() {
			if ( st.head == NULL ) {
				cout << "stack is empty!\n" ;
				return ;
			}
			else {
				st.deletion( st.head->data ) ; 
			}
		}

		void display() {
			if ( st.head == NULL ){
                                cout << "stack is empty!\n" ;
                                return ;
                        }
                        else {
                                node<T>* temp = st.head ;
                                while( temp!=NULL ) {
                                        cout << temp->data << "\n" ;
                                        temp = temp->next ;
                                }
                                cout << endl ;
                        }

		}	
};

int main() {
	stack<int> st ; 
	st.push(10) ; 
	st.push(20) ; 
	st.push(30) ;
        cout << "Pushed 10 , 20 , 30 \n" ; 	
	st.display() ; 
	cout << "pushed 40 \n" ; 
	st.push(40) ; 
	st.display() ; 
	st.pop() ; 
	cout << "Popped 40 \n" ; 
	st.display() ; 
	st.pop() ; 
	cout << "Popped 30 \n"  ;
	st.display() ;
} 
