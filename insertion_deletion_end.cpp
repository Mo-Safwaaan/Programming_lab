#include <iostream> 
#include <time.h>
#include "dynamic_array.h"
#include "single_linked_list.h"
using namespace std ; 

int main() {
	long int n = 100  ; 

	// Probabilty of insertion and deletion 
	float prob_insertion = 0.1 ; 
	float prob_deletion = 0.9 ; 

	//time variable 
	double time_dynamic_array[10] ; 
	double time_linked_list[10] ;

	cout << "Probability % : Dynamic array : Linked list\n"	;
	for(int i = 0 ; i < 10 ; i++ ) {
		dynamic_array<int> arr ;
	        linked_list<int> list ; 

		//Generate random test cases and store them 
	        int size_insertion = prob_insertion * n  ; 
	        int size_deletion = prob_deletion * n  ; 
	        //initialize random seed 
                srand( time(NULL) );
	        for( int j = 0 ; j < n ; j++ ) {
			int random = rand() % 100 + 1 ; 
		        arr.push_back(random) ; 
		        list.insert_end(random) ; 	
		}
		
		clock_t start , end ; 
		
		//Store time of dynamic array insertion and deletion
		start = clock() ;  
		for( int j = 0 ; j < size_insertion ; j++ ) {
			arr.push_back( rand() % 100 + 1 ) ; 
		}
		for( int j = 0 ; j < size_deletion ; j++ ) {
			arr.delete_end() ; 
		}
		end = clock() ;
	        time_dynamic_array[i] = double( end - start )  ; 

		//Store time of linked list insertion and deletion 
		start = clock() ; 
	        for( int j = 0 ; j < size_insertion ; j++ ){
			list.insert_end( rand() % 100  + 1 ) ; 
		}
	        for( int j = 0 ; j < size_deletion ; j++ ) {
			list.delete_end() ;
		}
	        end = clock() ; 
	        time_linked_list[i] = double( end - start ) ; 

		cout << prob_insertion * 100 << "\t\t" << ( long int )time_dynamic_array[i] << "\t\t" << ( long int )time_linked_list[i] << endl ; 

		prob_insertion += 0.1 ; 
		prob_deletion -= 0.1 ;	
		
	}
	return 0 ;
}
