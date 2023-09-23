#include "adjacency_matrix.h" 
#include "stack_array.h" 
#include "array.h"
#include <iostream> 

using namespace std ;

void rec_dfs1 ( int x , array<int> &visited , adjacency_matrix &adj , Stack<int> &dfs  ) {
	visited.insert( x , 1 ) ;
        for( int i = 0 ; i < 5 ; i++ ){	
		if( adj.adj_matrix[x]->new_array[i] == 1 && visited.new_array[i] == 0 ){
			rec_dfs1( i , visited , adj , dfs ) ; 
		}
	}
	dfs.push(x) ; 
}

void rec_dfs2( int x , array<int> &visited , adjacency_matrix &adj ){
	cout << x << " " ; 
	visited.insert( x , 1 ) ; 
	for( int i = 0 ; i < 5 ; i++ ){
                if( adj.adj_matrix[x]->new_array[i] == 1 && visited.new_array[i] == 0 ){
                        rec_dfs2( i , visited , adj ) ;
                }

    }
}

int main() {
	cout << "--------------------------------STRONGLY CONNECTED COMPONENTS------------------------------------------\n" ;  
        cout << "1. Kosarjus Algorithm \n2. Tarajans Algorithm\n" ; 
        cout <<	"Enter Algortihm choice : " ; 
	int ch ; 
	cin >> ch ; 
	switch(ch) {
		case 1 : {
			 	adjacency_matrix adj(5) ; 
				adj.add_edge( 0 , 1 ) ; 
				adj.add_edge( 1 , 2 ) ;
			       	adj.add_edge( 2 , 0 ) ;
				adj.add_edge( 1 , 3 ) ;
				adj.add_edge( 3 , 4 ) ;
				adj.display() ;
			        Stack<int> dfs ; 
			        array<int> visited(5) ; 
			        rec_dfs1( 0 , visited , adj , dfs ) ; 	
			        adj.transpose() ; 
			 
				for( int i = 0 ; i < 5 ; i++ ) {
					visited.insert( i , 0 ) ; 
				}
				int i = 1 ;
			        int flag = 1 ; 	
				while( !dfs.is_empty() ){
					if( flag == 1 ) cout << "Component " << i << " : " ; 
				        int top = dfs.curr_top() ; 
				        dfs.pop() ; 
				        if( visited.new_array[top] == 0 ) {
						flag = 1 ; 
						rec_dfs2( top , visited , adj ) ; 
						i++ ; 
						cout << endl ; 
					}
					else flag = 0 ; 	
				}	
				break ; 
			 }
		case 2 : break ; 
	        default : break ; 
	}
	return 0 ; 
}
