#include <iostream>
#include <time.h>
#include <fstream>
#include "adjacency_matrix.h"
#include "array.h" 

using namespace std ; 

int main() {
	int ch ; 
	cout << "Enter case : " ; 
	cin >> ch ;
        switch(ch){
		case 1 :{ 
				int fixed_n[ 200 , 500 , 1000 ] ;

				//Fixed n
				for( int t = 0 ; t < 3 ; t++ ) {
					cout << "\nFixed N = " << fixed_n[t] <<  " : \n" ; 
					cout << "	Var M : " ;
					int m ;  

					//Variable m = 2n to nC2  
					for( m = 2 * n ; m <= n * (n - 1) / 2 ; m++ ){
						adjacency_matrix adj(n) ;

						//initialize random seed
                				srand( time(NULL) );

						for( int j = 0 ; j < m ; j++ ){
							int flag = 0 ; 
							do {	
								//Random insertion of edges 
								int random1 = rand() % n ; 
		 						int random2 = rand() % n ; 
								if ( random1 != random2 && adj.adj_matrix[random1]->new_array[random2] != 1 ) {
									flag = 1 ; 
									adj.add_edge( random1 , random2 ) ; 
								}
							}
							while( flag == 0 ) ;  
						}

						//Time for dfs_forest
						clock_t start , end ;
						start = clock()  ; 
						adj.dfs_forest() ; 
						end = clock()  ;
	        				cout << m << " edges : " << double( end - start ) << "seconds ||" ;  	

					}
				}
				break ; 
			}
		case 2 : { break ; }
		default : break ; 	 

	}
	return 0 ; 
}
