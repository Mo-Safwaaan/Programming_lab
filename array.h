#ifndef MYHEADER_H
#define MYHEADER_H
#include <iostream>
using namespace std ;

template < typename T > 

class array {
	public : 
		int size  ; 
		T* new_array ; 
		
		array( int s ) {
			this->size = s ;
		        this->new_array	= new T[size] ; 
		}
 
                int insert( int index , T val ){
			if ( index > ( size - 1 )) {
				cout << "Array index out of bounds!\n" ; 
				return -1  ; 
			}
			else {
				new_array[index] = val ;
			        return 0 ; 	
			} 
			return 0 ; 
		}

		void deletion ( T val ) {
			for ( int i = 0 ; i < size ; i++ ) {
				if ( new_array[i] == val ) {
					new_array[i] = 0 ; 
					return ; 
				}
			}
			cout << "Value not found!\n" ; 
		} 

		void search( T val ) {
			for ( int i = 0 ; i < size ; i++ ) {
				if ( new_array[i] == val ) {
					cout << val <<" found at index " << i << "\n" ; 
					return ;
				}
			}
			cout << val << " not found in the array!\n" ; 
		}
		
                void display() {
			for ( int i = 0 ; i < size ; i++ ) {
				cout << new_array[i] << " " ; 
			}
			cout << endl ; 
		}		
} ; 
#endif
/*
int main() {
	array<char> my_array(4) ; 
	my_array.insert( 0 , 'a' ) ;
	my_array.insert( 1 , 'b' ) ;
	my_array.insert( 2 , 'c' ) ; 
	my_array.insert( 3 , 'd' ) ; 
	my_array.display() ;
	my_array.search('d') ; 
	my_array.search('f') ;
	my_array.deletion('a') ;
        my_array.search('a') ; 	
	my_array.deletion('b') ;
	my_array.search('c') ; 
	my_array.display() ; 
	my_array.deletion('c') ; 
	my_array.display() ; 
        my_array.deletion('d') ;
        my_array.display() ;	
} */ 
