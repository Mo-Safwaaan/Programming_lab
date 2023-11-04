#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ; 

#ifdef MEMOIZATION

int lcs( string X , string Y , int m , int n , vector<vector<int>> &dp ){
	if ( m == 0 || n == 0 )
		return 0 ;
	if ( X[ m - 1 ] == Y[ n - 1 ] )
		return dp[m][n] = 1 + lcs( X , Y , m - 1 , n - 1 , dp ) ;
	if ( dp[m][n] != -1 ) 
		return dp[m][n] ; 
	return dp[m][n] = max( lcs( X , Y , m , n - 1 , dp ) , lcs( X , Y , m - 1 , n , dp ) ) ;
}

#endif

#ifdef TABULATION 
int lcs( string X , string Y , int m , int n ){
	int L[ m + 1 ][ n + 1 ] ; 
	for( int i = 0 ; i <= m ; i++ ){
		for( int j = 0 ; j <= n ; j++ ){
			if( i == 0 || j == 0 )
				L[i][j] = 0 ; 
			else if ( X[i - 1] == Y[j - 1] )
				L[i][j] = L[i - 1][j - 1] + 1 ; 
			else 
				L[i][j] = max( L[i - 1][j] , L[i][j - 1] ) ; 
		}
	}
	return L[m][n] ; 
} 
#endif

#ifdef OPTIMIZED
int lcs ( string X , string Y , int n , int m ){
	vector<int> prev( m + 1 , 0 ) , cur( m + 1 , 0 ) ; 
	for(int i = 1 ; i < n + 1 ; i++ ){
		for( int j = 1 ; j < m + 1 ; j++ ){
			if ( X[i - 1] == Y[j - 1] )
				cur[j] = 1 + prev[j - 1] ; 
			else 
				cur[j] = max( cur[j - 1] , prev[j] ) ; 
		}
		prev = cur ; 
	}
	return cur[m] ; 
} 
#endif

int main() {
	string X = "AGGTAB" ; 
	string Y = "GXTXAYB" ; 

	int m = X.size() ; 
	int n = Y.size() ; 
#ifdef MEMOIZATION
	vector<vector<int>> dp( m + 1 , vector<int>( n + 1 , -1 )) ;
        cout << "Length of LCS is : " << lcs( X , Y , m , n , dp ) << endl ; 
#endif	

#ifdef TABULATION
	cout << "Length of LCS is : " << lcs( X , Y , m , n ) << endl ; 
#endif

#ifdef OPTIMIZED
	cout << "Length of LCS is : " << lcs( X , Y , m , n ) << endl ;
#endif
}
