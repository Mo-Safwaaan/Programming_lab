#include <iostream> 
#include <time.h>
#include "dynamic_array.h"
#include "single_linked_list.h"
using namespace std ; 

int main() {
	long int n = 100  ; 
	int option ;

       	//initialize random seed 
        srand( time(NULL) );

	cout << "Enter Case : " ;
        cin >> option ; 

        switch(option) {	
		case 1 :{
			// Probabilty of insertion and deletion 
			float prob_insertion = 0.0 ; 
			float prob_deletion = 1.0 ; 

			//time variable 
			double time_dynamic_array[11] ; 
			double time_linked_list[11] ;

			cout << "Probability % : Dynamic array : Linked list\n"	;
			for(int i = 0 ; i <= 10 ; i++ ) {
				dynamic_array<int> arr ;
	        		linked_list<int> list ; 

				//Generate random test cases and store them 
	        		int size_insertion = prob_insertion * n  ; 
	        		int size_deletion = prob_deletion * n  ; 
	        
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
				cout << "Average time for dynamic array: ";
				double avg = 0;
				for(int i=0;i<=10;i++){
					avg += time_dynamic_array[i];
				}
				cout << avg/11 << " seconds" << endl;
				avg = 0;
				cout << "Average time for Linkedlist: ";
				for(int i=0;i<=10;i++){
					avg += time_linked_list[i];
				}
				cout << avg/11 << " seconds" << endl;
				break;
			}

		case 2 : {
		        // Probabilty of insertion and deletion 
                        float prob_insertion = 0.0 ;
                        float prob_deletion = 1.0 ;

                        //time variable 
                        double time_dynamic_array[11][11] ;
                        double time_linked_list[11][11] ;

                        for(int i = 0 ; i <= 10 ; i++ ) {
                                int size_insertion = prob_insertion * n  ;
                                int size_deletion = prob_deletion * n ; 
 				
				for( int k = 0 ; k <= 10 ; k++ ){
					dynamic_array<int> arr ;
                                	linked_list<int> list ;

					for( int j = 0 ; j < n ; j++ ) {
                                        	int random = rand() % 100 + 1 ;
                                        	arr.push_back(random) ;
                                        	list.insert_end(random) ;
                                	}

	
					//Probabilty of start and end
                                        float prob_start = 0.0 ;
                                        float prob_end = 1.0 ;

					int start_insertion = prob_start * size_insertion ; 
			                int end_insertion = prob_end * size_insertion ; 
			                int start_deletion = prob_start * size_deletion ; 
			                int end_deletion = prob_end * size_deletion ; 	

                                	clock_t start , end ;

                                	//Store time of dynamic array insertion and deletion
                                	start = clock() ;
                                	for( int j = 0 ; j < start_insertion ; j++ ) {
                                        	arr.push_front( rand() % 100 + 1 ) ;
                                	}
				 	for( int j = 0 ; j < end_insertion ; j++ ) {
                                        	arr.push_back( rand() % 100 + 1 ) ;
                                	}

                                	for( int j = 0 ; j < start_deletion ; j++ ) {
                                        	arr.delete_front() ;
                                	}
				 	for( int j = 0 ; j < end_deletion ; j++ ) {
                                        	arr.delete_end() ;
                                	}

                                	end = clock() ;
                                	time_dynamic_array[i][k] = double( end - start )  ;

                                	//Store time of linked list insertion and deletion 
                                	start = clock() ;
                                	for( int j = 0 ; j < start_insertion ; j++ ) {
                                                list.insert_front( rand() % 100 + 1 ) ;
                                        }
                                        for( int j = 0 ; j < end_insertion ; j++ ) {
                                                list.insert_end( rand() % 100 + 1 ) ;
                                        }

                                        for( int j = 0 ; j < start_deletion ; j++ ) {
                                                list.delete_front() ;
                                        }
                                        for( int j = 0 ; j < end_deletion ; j++ ) {
                                                list.delete_end() ;
                                        }


                                	end = clock() ;
                                	time_linked_list[i][k] = double( end - start ) ;

					prob_start += 0.1 ; 
					prob_end -= 0.1 ; 
				}

                                prob_insertion += 0.1 ;
                                prob_deletion -= 0.1 ;
                        }
                                cout << "Average time for dynamic array: ";
                                double avg = 0;
                                for(int i=0;i<=10;i++){
					for(int j=0;j<=10;j++){
						avg += time_dynamic_array[i][j] ; 
					} 
                                }
                                cout << avg/121 << " seconds" << endl;
                                avg = 0;
                                cout << "Average time for Linkedlist: ";
                                for(int i=0;i<=10;i++){
                                        for(int j=0;j<=10;j++){
                                                avg += time_linked_list[i][j] ;
                                        }
                                }
                                cout << avg/10 << " seconds" << endl;
                                break;

			 
			 }
	        case 3 : break ;
	        default : break ; 
		}
  return 0 ;}	
