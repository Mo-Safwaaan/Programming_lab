#ifndef MYHEADER_H  
#define MYHEADER_H
#include <iostream> 
using namespace std ; 

template < typename T > 
class node {
        public : 
		T data ; 
		node<T>* next ;
	        node() { 
			next = NULL ; 
		} 	
};

template < typename T > 
class linked_list {
	public : 
		node<T>* head ;

		linked_list() {
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
				new_node->next = head ; 
				head = new_node ; 
			}

		}

	        void insert_end ( T val ){
			node<T>* new_node = new node<T> ; 
			new_node->data = val ; 
			if ( head == NULL ) {
				head = new_node ; 
			        return ;	
			}
			else {
				node<T>* temp = head ; 
				while ( temp->next != NULL ){
					temp = temp->next; 
				}
			       temp->next = new_node ; 
		               return ; 	       
			}  
		}

	        void deletion ( T val ) {
			if ( head == NULL ) {
				cout << "Linked list is empty!\n" ; 
				return ;
			}
			else {
				node<T>* temp = head ;
				node<T>* prev = NULL ; 
			        if ( head->data == val ) {
					head = temp->next ; 
					free(temp) ; 
					return ;
				} 	
				while( temp != NULL &&  temp->data != val ){
					prev = temp ; 
					temp = temp->next ; 
				}
			        if ( temp == NULL ) {
					cout << "Value not found in the list!\n" ; 
				}
			        else {
					prev->next = temp->next ; 
					free(temp) ; 
				}	
			}
		}

	        void search ( T val ){
			if ( head == NULL ) {
				cout << "Linked list is empty!\n" ;
				return ;
			}
			else {
				int pos = 1 ;
                        	node<T>* temp = head ; 
				while ( temp!=NULL ) {
					if ( temp->data == val ) { 
						cout << val << " found at node " << pos << "\n" ; 
						return ;
				}
				temp = temp->next ;
				pos++ ; 
			}
                        	cout << val << " not found! \n" ;
			}
		}

	        void display (){
			if ( head == NULL ){
				cout << "Linked list is empty!\n" ; 
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
};

#endif

/*
int main() {
	linked_list<char> char_list ;
	char_list.insert_front('a') ; 
        char_list.insert_front ('b') ;
	char_list.insert_end('c') ;
	char_list.insert_front('d') ;
	char_list.display() ;
	char_list.search('d') ;
        char_list.search('a') ;
	char_list.search('c');
	char_list.deletion('a') ; 
	char_list.display() ;
	char_list.search('a') ;
        
} */ 
