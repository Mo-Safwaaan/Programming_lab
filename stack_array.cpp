#include <iostream> 
#include "array.h" 
using namespace std ; 

template < typename T >
class Stack{
        private :
		int top ; 
		array<T>* stack ;
                                    
	public :
		Stack() {
			this->top = -1 ;
			stack = new array<T>(10) ; 	
		}

                void push( T val ) {
			top++ ; 
                        int flag = stack->insert( top , val ) ;
			if ( flag == -1 ) {
				top-- ; 
			} 
                }

                void pop() {
                        if ( top == -1 ) {
                                cout << "Stack Underflow!\n" ;
                        }
                        else {
                                stack->deletion( stack->new_array[top] ) ;
				top-- ; 
                        }
                }

                void display() {
                        if ( top == -1  ){
                                cout << "Stack is empty!\n" ;
				return ; 
			}
			else {
			 	for( int i = 0 ; i <= top ; i++ ) {
					cout << stack->new_array[i] << " " ; 
				}
			       cout << endl ;	
			}

                }
};

int main() {
        Stack<int> st ;
        st.push(10) ;
        st.push(20) ;
        st.push(30) ;
        cout << "Pushed 10 , 20 , 30 \n" ;
        st.display() ;
        cout << "pushed 40 \n" ;
        st.push(40) ;
        st.display() ;
        st.pop() ;
        cout << "Popped 40 \n" ;
        st.display() ;
        st.pop() ;
        cout << "Popped 30 \n"  ;
        st.display() ;
}

