#include<iostream> 
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
class circular_linked_list {
	public : 
		node<T>* head ; 

		circular_linked_list() {
			this->head = NULL ;
		}

	        void display() {
			if ( head == NULL ) {
				cout << "List is empty\n" ; 
				return ; 
			}
			else {  
				node<T>* temp = head ; 
				do{
					cout << temp->data << " " ;
					temp = temp->next ; 
				}while( temp != head ) ;
				cout <<  endl ; 
			}
		}

		void insert_front( T val ) {
			node<T>* new_node = new node<T> ; 
			new_node->data = val ;
			if ( head == NULL ) {
				head = new_node ; 
				head->next = head ; 
				return ; 
			}
			else {
				new_node->next = head ; 
				node<T>* temp = head ; 
				while ( temp->next != head ) {
					temp = temp->next ; 
				}
				temp->next = new_node ; 
				head = new_node ; 
			}
		}

	        void insert_end( T val ) {
			node<T>* new_node = new node<T> ; 
			new_node->data = val ; 
			if ( head == NULL ) {
				head = new_node ;
				head->next = head ;
				return ; 
			}
			else {
				node<T>* temp = head ; 
				while ( temp->next != head ) {
					temp = temp->next ; 
				}
			        temp->next = new_node ; 
			        new_node->next = head ; 
			        return ; 	
			}
		}
	        
	        void deletion( T val ) {
			if ( head == NULL ) {
				cout << "Linked list is empty!\n" ; 
				return ; 
			}
			else {
                                node<T>* temp = head ;
                                node<T>* prev = NULL ;
                                if ( head->data == val ) {
					if ( head->next == head ) {
						head = NULL ; 
						free(temp) ; 
						return ;
					}
					else {
						prev = head ; 
						do{
						       prev = prev->next ; 
						}while ( prev->next !=head ) ; 
				                prev->next = head->next ; 
				                head = head->next ; 
				                free(temp) ; 
				                return ; 		
					}
                                }
                                do{
                                        prev = temp ;
                                        temp = temp->next ;
                                }while( temp!=head && temp->data!=val ) ; 
                                if ( temp == head ) {
                                        cout << "Value not found in the list!\n" ;
                                }
                                else {
                                        prev->next = temp->next ;
                                        free(temp) ;
					return ;
                                }
                        }

		}

	        void search( T val ) {
			if ( head == NULL ) {
				cout << "Linked list is empty!\n" ; 
				return ; 
			}
			else {
				int pos = 1 ; 
				node<T>* temp = head ;
				do {
					if ( temp->data == val ) {
						cout << val << " found at node " << pos << "\n" ; 
						return ; 
					}
					temp = temp->next ; 
					pos++ ; 
				}while ( temp!= head ) ; 

				cout << val << " not found ! \n" ; 
			}
		}	
};

int main() {
	circular_linked_list<double> double_list ; 
        double_list.insert_end(13.213);  
        double_list.insert_end(14.3328) ; 
        double_list.insert_front(15.382682) ; 
        double_list.insert_front(18.3775) ;
	double_list.display() ;
        double_list.search(15.382682) ;
	double_list.search(13.213);
        double_list.search(18.3775) ;	
        double_list.deletion(18.3775) ;
	double_list.display() ;
	double_list.search(18.3775) ; 
	double_list.search(14.3328) ; 
   
} 
