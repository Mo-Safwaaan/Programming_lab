#include <iostream>
using namespace std ;

template < typename T >
class node {
	public : 
		T data ; 
		node<T>* next ; 
		node<T>* prev ;

		node() {
			next = NULL ;
			prev = NULL ; 
		}
}; 

template < typename T > 
class double_linked_list {
	public : 
		node<T>* head ;

	        double_linked_list() {
			this->head = NULL ;
		}

		void insert_front( T val ) {
			node<T>* new_node = new node<T> ; 
			new_node->data = val ; 
			if ( head == NULL ) {
				head = new_node ; 
				return ;
			}
			else {
				head->prev = new_node ; 
				new_node->next = head ; 
				head = new_node ;
			}
		}
                
                void insert_end( T val ) {
			node<T>* new_node = new node<T> ; 
			new_node->data = val ; 
			if ( head == NULL ) {
				head = new_node ; 
				return ; 
			}
			else {
				node<T>* temp = head ; 
				while ( temp->next != NULL ) {
					temp = temp->next ; 
				}
				temp->next = new_node ;
				new_node->prev = temp ; 
				return ; 
			}
		}

                void display() {
			if ( head == NULL ) {
				cout << "List is empty!\n" ; 
				return ; 
			}
			else {
				node<T>* temp = head ; 
				while( temp!=NULL ) {
					cout << temp->data << " " ; 
					temp = temp->next ; 
				}
				cout << endl ; 
			}
		}

               void deletion( T val ) {
	       		if ( head == NULL ) {
				cout << "List is empty!\n" ; 
				return ; 
			}
			else {
				node<T>* temp = head ; 
				if ( head->data == val ) {
					head = head->next ; 
					if ( head != NULL ) 
						head->prev = NULL ;
					free(temp) ;
					return ; 
				}
				while( temp!=NULL && temp->data != val ){
					temp = temp->next ; 
				}
				if ( temp == NULL ) {
					cout << "Value not found in the list!\n" ;
				        return ; 	
				}
				else if ( temp->next == NULL ) {
					temp->prev->next = NULL ; 
					free(temp) ; 
					return ; 
				}
				else {
					temp->prev->next = temp->next ;
					temp->next->prev = temp->prev ;
					free(temp) ; 
					return ; 
				}

			}
	       }
	       
               void search( T val ) {
	       		if ( head == NULL ) {
				cout << "List is empty!\n" ; 
				return ;
			}
			else {
				int pos = 1 ; 
				node<T>* temp = head ; 
				while( temp!= NULL ) {
					if ( temp->data == val ) {
						cout << val << " found at node " << pos << "\n" ; 
						return ; 
					}
					temp = temp->next ; 
					pos++ ; 
				}
				cout << val << " not found!\n" ; 
			}
	       }	       
};

int main() {
	double_linked_list<int> int_list ;
        int_list.insert_end(12) ;
	int_list.insert_front(34) ; 
	int_list.insert_front(49) ; 
	int_list.insert_end(54) ; 
	int_list.display() ;
	int_list.search(49) ;
	int_list.search(54) ;
	int_list.search(12) ;
	int_list.deletion(12) ; 
	int_list.display() ;
	int_list.search(12) ; 
	int_list.search(59) ;
          	
}
