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
			Queue<int> bfs_queue ; 
			bfs_queue.insert(val) ;
			array<int> visited(n) ; 
			visited.insert( val , 1 ) ;
		        cout << "BFS : " ; 
		        while( !bfs_queue.is_empty() ){
				int curr = bfs_queue.deletion() ; 
			        cout << curr << " " ; 
			        visited.insert( curr , 1 ) ; 
			        for( int i = 0 ; i < n ; i++ ) {
					if( adj_matrix[curr]->new_array[i] == 1 && visited.new_array[i] == 0 ){
						bfs_queue.insert(i) ; 
						visited.insert( i , 1 ) ; 
					}
				}	
			}	
			cout << endl ;
		}


		void dfs( int val ) {
			Stack<int> dfs_stack ; 
			dfs_stack.push(val) ; 
			array<int> visited(n) ; 
			visited.insert( val , 1 ) ; 
			cout << "DFS : " ;
			cout << val << " " ; 
			while( !dfs_stack.is_empty() ){
				int curr = dfs_stack.curr_top() ; 
				int flag = 0 ; 
				for( int i = 0 ; i < n ; i++ ){
					if( adj_matrix[curr]->new_array[i] == 1 && visited.new_array[i] == 0 ){
						visited.insert( i , 1 ) ; 
						dfs_stack.push(i) ;
						cout << i << " " ; 
						flag++ ; 
						break ; 
					}
				}
				if( flag == 0 ) dfs_stack.pop() ;
			}
			cout << endl ; 
		}
}; 

int main() {
	adjacency_matrix adj(4) ;  
	adj.add_edge(0 , 2) ; 
	adj.add_edge(1 , 2) ; 
	adj.add_edge(3 , 1) ; 
	adj.display() ; 
	adj.bfs(2) ;
        adj.dfs(3) ;	
	return 0 ; 
} 
