#include<iostream> 
#include "array.h" 
using namespace std ; 

class adjacency_matrix {
	private : 
		int n ; 
		array<int>* adj_matrix[] ; 
	public : 
		adjacency_matrix( int val ) {
			this->n = val ; 	
			for ( int i = 0 ; i < n ; i++ ) {
				adj_matrix[i] = new array<int>(n) ; 
			}
		}
		void add_edge( int src , int dest ){
			adj_matrix[src]->new_array[dest] = 1 ; 
			adj_matrix[dest]->new_array[src] = 1 ; 
		}
		void delete_edge( int src , int dest ){
			adj_matrix[src]->new_array[dest] = 0 ; 
			adj_matrix[dest]->new_array[src] = 0 ; 
		}
		void display() {
			for( int i = 0 ; i < n ; i++ ) {
				for( int j = 0 ; j < n ; j++ ) {
					cout << adj_matrix[i]->new_array[j] << " " ; 
				}
				cout << endl ; 
			}
		}

}; 

int main() {
	adjacency_matrix adj(4) ; 
	adj.add_edge(0 , 1) ; 
	adj.add_edge(0 , 2) ; 
	adj.add_edge(1 , 2) ; 
	adj.add_edge(3 , 1) ; 
	adj.display() ; 
	cout << "3-1 edge deleted\n" ;
	adj.delete_edge(3 , 1) ;
	adj.display() ; 
	return 0 ; 
}
