#include<iostream>
#include<omp.h>
#include<vector>
using namespace std ; 
const int N = 1000 ; 

int main() {
	vector<vector<int>> a( N , vector<int> (N) ) ; 
        vector<vector<int>> b( N , vector<int> (N) ) ; 
	vector<vector<int>> c( N , vector<int> (N) ) ;

	

	for( int i = 0 ; i < N ; i++ ){
		for( int j = 0 ; j < N ; j++ ){
			a[i][j] = rand() % 100 ; 
			b[i][j] = rand() % 100 ; 
		}
	}

	//ifdef LINEAR 
	
	for( int i = 0 ; i < N ; i++ ){
		for ( int j = 0 ; j < N ; j++ ){
			int sum = 0 ; 
			for( int k = 0 ; k < N ; k++ ){
				sum += a[i][k] * b[k][j] ; 
			}
			c[i][j] = sum ; 
		}
	}

	//endif 
	
	//ifdef PARALLEL
	#pragma omp parallel for
        for( int i = 0 ; i < N ; i++ ){
                for ( int j = 0 ; j < N ; j++ ){
                        int sum = 0 ;
                        for( int k = 0 ; k < N ; k++ ){
                                sum += a[i][k] * b[k][j] ;
                        }
                        c[i][j] = sum ;
                }
        }
	//endif       
}
