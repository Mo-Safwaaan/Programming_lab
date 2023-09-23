#ifndef ADJ_MATRIX_H
#define ADJ_MATRIX_H

#include<iostream> 
#include "array.h"
#include "queue_array.h"
#include "array.h"
#include "stack_array.h"
using namespace std ; 

class adjacency_matrix {
	public : 
		int n ; 
		array<int>* adj_matrix[] ; 
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
		}
		void delete_edge( int src , int dest ){
			adj_matrix[src]->new_array[dest] = 0 ; 
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


		Stack<int> dfs( int val ) {
			Stack<int> stack ; 
			Stack<int> dfs_stack ;  
			stack.push(val) ; 
			array<int> visited(n) ; 
			visited.insert( val , 1 ) ; 
			dfs_stack.push(val) ;  
			while( !stack.is_empty() ){
				int curr = stack.curr_top() ; 
				int flag = 0 ; 
				for( int i = 0 ; i < n ; i++ ){
					if( adj_matrix[curr]->new_array[i] == 1 && visited.new_array[i] == 0 ){
						visited.insert( i , 1 ) ; 
						stack.push(i) ;
						dfs_stack.push(i) ;  
						flag++ ; 
						break ; 
					}
				}
				if( flag == 0 ) stack.pop() ;
			}
			return dfs_stack ; 
		}

		void transpose() {
			for( int i = 0 ; i < n ; i++ ){
				for( int j = 0 ; j < n ; j++ ){
					if( i < j ){
					int temp = adj_matrix[i]->new_array[j] ; 
					adj_matrix[i]->new_array[j] = adj_matrix[j]->new_array[i] ; 
					adj_matrix[j]->new_array[i] = temp ; 
					}
				}
			}
		}
}; 

#endif 
/*
int main() {
	adjacency_matrix adj(4) ;  
	adj.add_edge(0 , 2) ; 
	adj.add_edge(1 , 2) ; 
	adj.add_edge(3 , 1) ; 
	adj.display() ; 
	adj.bfs(2) ;
        adj.dfs(3) ;	
	return 0 ; 
} */
