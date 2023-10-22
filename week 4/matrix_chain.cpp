#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std ;

#ifdef TABULATION 
int matrix_chain_order( int p[] , int n ){
	int m[n][n] ; 
	for( int i = 1 ; i < n ; i++ ){
		m[i][i] = 0 ;
	}
	for( int l = 2 ; l < n ; l++ ){
		for( int i = 1 ; i < n - l + 1 ; i++){
			int j = i + l - 1 ; 
			m[i][j] = INT_MAX ;
			for( int k = i ; k <= j - 1 ; k++ )
			{
				int q = m[i][k] + m[k + 1][j] + ( p[i - 1] * p[k] * p[j] ) ;
			      	if ( q < m[i][j]) m[i][j] = q ; 	
			}
		}
	}
	return m[1][n - 1] ; 
}
#endif

#ifdef MEMOIZATION
int dp[100][100] ; 
int matrix_chain_memoised( int *p , int i , int j ){
	if ( i == j ) return 0 ; 
	if ( dp[i][j] != -1 ) return dp[i][j] ; 
	dp[i][j] = INT_MAX ; 
	for(int k = i ; k < j ; k++ ){
		dp[i][j] = min( dp[i][j] , matrix_chain_memoised( p , i , k ) + 
				           matrix_chain_memoised( p , k + 1 , j ) + 
					   p[ i - 1 ] * p[k] * p[j] ) ; 
	}
	return dp[i][j] ; 
}
int matrix_chain_order( int *p , int n ) {
	int i = 1 , j = n - 1 ; 
	return matrix_chain_memoised( p , i , j ) ;
}
#endif


int main() {
	int arr[] = { 1, 2 , 3 , 4 , 3 } ; 
	int n = sizeof(arr) / sizeof(arr[0]) ; 
	cout << "Min no of multiplications : " ;

#ifdef TABULATION
	cout << matrix_chain_order( arr , n ) << endl ; 
#endif
#ifdef MEMOIZATION
	memset( dp , -1 , sizeof dp ) ; 
	cout << matrix_chain_order( arr , n ) << endl ; 
#endif
	return 0 ; 
}
