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
			T* resized_array = new T[n] ; 
			for ( int i = 0 ; i < size ; i++ ) {
				resized_array[i] = new_array[i] ; 
			}
			this->new_array = resized_array ; 
			this->size = n ; 
		}

                void push_back( T val ){
                	if ( size == ( pointer + 1 ) ) {
				resize( 2*size ) ;
				pointer++ ; 
				new_array[pointer] = val ; 
			}
			else{	
				pointer++ ; 
				new_array[pointer] = val ;
			}
                }

                void delete_end() {
                        pointer-- ; 
			if ( ( pointer + 1 ) == ( size / 4 ) ) {
				resize( size/2 ) ; 
			} 
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
                        for ( int i = 0 ; i <= pointer ; i++ ) {
                                cout << new_array[i] << " " ;
                        }
                        cout << endl ;
                }

} ;

int main() {
	dynamic_array<int> arr ;
        cout << "Pushed 10 and 20\n" ; 	
	arr.push_back(10) ; 
	arr.push_back(20) ; 
	arr.display() ; 
	cout << "Pushed 30 \n" ; 
	arr.push_back(30) ; 
        arr.display() ; 	
	cout << "Delete 30\n" ; 
	arr.delete_end() ; 
	arr.display() ; 
	cout<< "Delete 20\n" ;
	arr.delete_end() ; 
	arr.display() ; 
	cout << "Delete 10\n"  ; 
	arr.delete_end() ; 
	arr.display() ; 
	return 0 ; 
}
