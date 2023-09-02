#include<iostream> 
#include "array.h"
#include "queue_array.h"
#include "array.h"
#include "stack_array.h"
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
			for( int i = 0 ; i < n ; i++ ) {
                                for( int j = 0 ; j < n ; j++ ) {
                                        adj_matrix[i]->new_array[j] = 0   ;
                                }
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
		void bfs( int val ) {
			Queue<int> bfs_queue  ;
			array<int> bfs_list(n) ;
			array<int> visited(n) ; 
			bfs_queue.insert( val ) ;
			visited.insert( 0 , val ) ; 
			int i = 0 ; 
			while( !bfs_queue.is_empty() ){
				int k = 1 ; 
				int curr = bfs_queue.deletion() ;
			        bfs_list.insert( i , curr ) ; 
			        i++ ; 	
				for( int j = 0 ; j < n ; j++ ) {
					if( adj_matrix[curr]->new_array[j] == 1 && bfs_list.search(j) == 0 && visited.search(j) == 0  ) {
						bfs_queue.insert( j ) ;
						visited.insert( k ,  j ) ;
					        k++ ; 	
					 }	
				}
			}
			bfs_list.display() ; 
							
		}
		void dfs( int val ) {
			Stack<int> dfs_stack ;
			array<int> dfs_list(n) ; 
			array<bool> visited(n) ;
		        for( int i = 0 ; i < n ; i++ ) {
				visited.insert( i , false ) ; 
			}	
			dfs_stack.push( val ) ;  
			visited.insert( val , true  ) ;
			int i = 0 ; 
			while( !dfs_stack.is_empty() ){
				int curr = dfs_stack.curr_top() ;
				dfs_stack.pop() ; 
				dfs_list.insert( i , curr ) ; 
				i++ ; 
				for( int j = 0 ; j < n ; j++ ){
					 if( adj_matrix[curr]->new_array[j] == 1 && dfs_list.search(j) == 0 && visited.new_array[j] == false  ) {
					 	dfs_stack.push( j ) ; 
						visited.insert( i  , j ) ;
					 }
				}  
			}
			dfs_list.display() ; 

		}


}; 

int main() {
	adjacency_matrix adj(4) ; 
	adj.add_edge(0 , 1) ; 
	adj.add_edge(0 , 2) ; 
	adj.add_edge(1 , 2) ; 
	adj.add_edge(3 , 1) ; 
	adj.display() ; 
	cout << "BFS : " ;
	adj.bfs(3) ;
	cout << "DFS : " ; 
        adj.dfs(3) ;	
	return 0 ; 
} 
