#ifndef D_ARRAY_H
#define D_ARRAY_H
#include<iostream>
using namespace std ;
template < typename T >
class dynamic_array {
        public :
                int size  ;
		int pointer ; 
                T* new_array ; 
                dynamic_array() {
                        this->size = 1 ;
			this->pointer = -1 ; 
                        this->new_array = new T[size] ;
                }

		void resize( int n ){
           /*			 int *copyArray = new int[n];
                         for( int i = 0; i <= this->pointer ; i++ )
                         	copyArray[i] = new_array[i];
                         delete[] this->new_array;
                         this->new_array = new int[n];
                         for( int i = 0; i <= this->pointer ; i++)
                         	this->new_array[i] = copyArray[i];
                         this->size = n ; 
                         delete[] copyArray;
	     */  
			
	      		T* resized_array = new T[n] ; 
			for ( int i = 0 ; i <= this->pointer ; i++ ) {
				resized_array[i] = this->new_array[i] ; 
			}
			delete[] this->new_array ; 
			this->new_array = resized_array ; 
			this->size = n ;
		    	
		}

                void push_back( int val ){
                	if ( this->size == ( this->pointer + 1 ) ) {
				resize( 2 * this->size ) ;
				this->pointer++ ; 
				this->new_array[this->pointer] = val ; 
			}
			else{	
				this->pointer++ ; 
				this->new_array[this->pointer] = val ;
			}
                }

                void delete_end() {
			if ( this->pointer  == ( this->size / 4 ) ) {
				resize( this->size / 2 ) ; 
			}
			this->pointer-- ; 
                }

                void search( int val ) {
                        for ( int i = 0 ; i < this->size ; i++ ) {
                                if ( this->new_array[i] == val ) {
                                        cout << val <<" found at index " << i << "\n" ;
                                        return ;
                                }
                        }
                        cout << val << " not found in the array!\n" ;
                }

                void display() {
                        for ( int i = 0 ; i <= this->pointer ; i++ ) {
                                cout << this->new_array[i] << " " ;
                        }
                        cout << endl ;
                }

} ;
#endif
/*
int main() {
	dynamic_array<int> arr ;
        cout << "Pushed 10 and 20\n" ; 	
	arr.push_back(10) ; 	
	arr.push_back(20) ;
        cout << "pushed 30, 40 and 50  \n" ; 
	arr.push_back(30)  ;
        arr.push_back(40)  ; 
        arr.push_back(50)  ;	
	arr.display() ;
        cout << "Pushed 60\n" ; 
        arr.push_back(60) ; 
        arr.display() ; 	
	cout << "Delete 60\n" ; 
	arr.delete_end() ; 
	cout << "size : " << arr.size << "\n" ;
	arr.display() ; 
	cout<< "Delete 50\n" ;
	arr.delete_end() ; 
	cout << "size : " << arr.size << "\n" ;
	arr.display() ; 
	cout << "Delete 40\n"  ; 
	arr.delete_end() ; 
	cout << "size : " << arr.size << "\n" ;
	arr.display() ;
        cout << "Delete 30\n"  ;
        arr.delete_end() ;
        cout << "size : " << arr.size << "\n" ;
        arr.display() ;	
	return 0 ; 
} */
