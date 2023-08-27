#include <iostream> 
#include "single_linked_list.h" 
using namespace std ; 

class adjacency_list{
	private : 
		int n ;
	        linked_list<int>* adj_list ; 	
	public :
		adjacency_list( int val ){
			this->n = val ;	
			adj_list = new linked_list<int>[n] ; 
	
		}
		void add_edge( int src , int dest ){
			adj_list[src].insert_end(dest) ; 
			adj_list[dest].insert_end(src) ; 
		}
		void delete_edge( int src , int dest ){
			adj_list[src].deletion(dest) ;
			adj_list[dest].deletion(src) ;
		}
		void display() {
			for( int i = 0 ; i < n ; i++ ){
				cout<< i << " : " ; 
				adj_list[i].display() ;
			        cout << endl ; 	
			}
		}
}; 

int main() {
	adjacency_list adj(4) ; 
	adj.add_edge(0 , 1) ;
        adj.add_edge(0 , 2) ;
        adj.add_edge(1 , 2) ;
        adj.add_edge(3 , 1) ;
        adj.display() ;
        cout << "3-1 edge deleted\n\n" ;
        adj.delete_edge(3 , 1) ;
        adj.display() ;
	return 0 ; 
}
