#include "adjacency_matrix.h" 
#include "stack_array.h" 
#include "array.h"
#include <iostream> 

using namespace std ;

//DFS stack store elements based on finish times
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

void tarajan_dfs( int v, int curr_index , array<int> &index , array<int> &low_link , array<int> &on_stack , Stack<int> &st , adjacency_matrix &adj ){
	static int  comp = 1 ; 
	index.insert( v , curr_index ) ;	
	low_link.insert( v , index.new_array[v] ) ; 
	curr_index++ ; 
	st.push(v) ; 
	on_stack.insert( v , 1 ) ; 
	for (int i = 0 ; i < 5 ; i++ ){
		if( adj.adj_matrix[v]->new_array[i] == 1 ) {

			//successor not visited yet
			if ( index.new_array[i] == -1 ){
				tarajan_dfs( i , curr_index , index , low_link , on_stack , st , adj ) ;
				if ( low_link.new_array[v] >= low_link.new_array[i] ){
					low_link.insert( v , low_link.new_array[i]  ) ; 
				}
			
			}
			
			//successor already on stack and current SCC
		        else if( on_stack.new_array[i] == 1  ){
				if( low_link.new_array[v] >= index.new_array[i] ){
					low_link.insert( v , index.new_array[i]  ) ; 
			}
		}
	  }
	}
	
	//V is root node ; pop the nodes and construct an SCC
	if( low_link.new_array[v] == index.new_array[v] ){
		int w ; 
		cout << "componenet " << comp << " : " ;
	        do {    
			if( !st.is_empty() ){
				w = st.curr_top() ;
			        st.pop() ; 	
				on_stack.insert( w , 0 ) ;
				cout << w << " " ;
			}
		}
		while ( w != v ) ;  
		cout << endl ; 
		comp++ ; 	
	}
}

int main() {
	cout << "--------------------------------STRONGLY CONNECTED COMPONENTS------------------------------------------\n" ;  
        cout << "1. Kosarjus Algorithm \n2. Tarajans Algorithm\n" ; 
        cout <<	"Enter Algortihm choice : " ; 
	int ch ; 
	cin >> ch ; 
	// Create Adjacency matrix of a graph
        adjacency_matrix adj(5) ;
        adj.add_edge( 0 , 1 ) ;
        adj.add_edge( 1 , 2 ) ;
        adj.add_edge( 2 , 0 ) ;
        adj.add_edge( 1 , 3 ) ;
        adj.add_edge( 3 , 4 ) ;
        adj.display() ;

	switch(ch) {
		case 1 : { 
			        Stack<int> dfs ; 
			        array<int> visited(5) ;

				// DFS on graph 
			        rec_dfs1( 0 , visited , adj , dfs ) ;

				//Transpose the graph	
			        adj.transpose() ; 
			
				for( int i = 0 ; i < 5 ; i++ ) {
					visited.insert( i , 0 ) ; 
				}
				int i = 1 ;
			        int flag = 1 ;

				//DFS on transposed graph 	
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
		case 2 : { 
				array<int> index(5) ; 
				array<int> low_link(5) ;
				array<int> on_stack(5) ; 
				Stack<int> st ;
			      	
				//initialize	
			        int curr_index = 0 ; 	
				for(int i = 0 ; i < 5 ; i++){ 
					index.insert( i , -1 ) ;
				        low_link.insert( i , -1 ) ;
				        on_stack.insert( i , 0 ) ; 	
				}

				for( int i = 0 ; i < 5 ; i++ ){	
					if( index.new_array[i] == -1 ){
						tarajan_dfs( i , curr_index , index , low_link , on_stack , st , adj ) ; 
					}
				}

				 
				 break ;} 
	        default : break ; 
	}
	return 0 ; 
}
