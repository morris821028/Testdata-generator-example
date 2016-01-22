/*
  by asas
*/
#include <bits/stdc++.h>
#define CASET int ___T, Case = 1; scanf("%d ", &___T); while (___T-- > 0)
#define SZ(X) ((int)(X).size())
#define PHB push_back
#define PPB pop_back
#define LL long long
#define ULL unsigned long long
#define ALL(X) (X).begin(), (X).end()
#define MP make_pair
#define PII pair<int,int>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define F first
#define S second
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define DRI(X) int (X) = in()
#define DRII(X, Y) int X = in() , Y = in()
#define DRIII(X, Y, Z) int X = in() , Y = in() , Z = in()
using namespace std ;
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
const double EPS = 1e-6;
inline int in(int d=0,char q=0,int c=1){while(q!='-'&&q!=EOF&&(q<48||q>57))q=getchar();if(q==EOF)return EOF;if(q=='-')c=-1,q=getchar();do d=d*10+(q^48),q=getchar();while(q<58&&q>47);return c*d;}
// template end here
void swapColumn( double *M , int p1 , int p2 , int length , int width )
{
	if ( p1 != p2 )
	{
		for ( int i = 0 ; i < length ; i ++ )
		{
			swap( *(M + p1 * width + i) , *(M + p2 * width + i) ) ;
		}
	}
}
void multiplyColumn( double *M , int p , double scale , int length , int width )
{
	for ( int i = 0 ; i < length ; i ++ )
	{
		*(M + p * width + i) *= scale ;
	}
}
void subtractColumn( double *M , int p1 , int p2 , double scale , int length , int width )
{
	for ( int i = 0 ; i < length ; i ++ )
	{
		*(M + p1 * width + i) -= *(M + p2 * width + i) * scale ;
		if ( fabs( *(M + p1 * width + i) ) < EPS )
		{
			*(M + p1 * width + i) = 0.0 ;
		}
	}
}
string scoreStatus( double *M , int n , int m , int width )
{
	bool check ;
	for ( int i = 0 ; i < n ; i ++ )
	{
		check = false ;
		for ( int j = 0 ; j < m ; j ++ )
		{
			if ( fabs( *(M + i * width + j ) ) < EPS ) ;
			else
			{
				check = true ;
			}
		}
		if ( false == check )
		{
			if ( fabs( *(M + i * width + m ) ) > EPS )
			{
				return "contradictory" ;
			}
		}
	}
	for ( int j = 0 ; j < m ; j ++ )
	{
		if ( fabs( *(M + n * width + j ) ) < EPS ) ;
		else
		{
			return "not sure" ;
		}
	}
	char q[ 10 ] ;
	sprintf( q , "%.0lf" , -1.0 * *(M + n * width + m ) ) ;
	if ( string( q ) == "-0" )
	{
		return "0" ;
	}
	return string( q ) ;
}
void printMatrix( double *M , int n , int m , int width )
{
	for ( int i = 0 ; i < n ; i ++ )
	{
		for ( int j = 0 ; j < m ; j ++ )
		{
			printf( "%.2lf " , *(M + i * width + j) ) ;
		}
		printf( "\n" ) ;
	}
	printf( "\n" ) ;
}
int main()
{
	double M[ 101 ][ 101 ] , scale ;
	int n , m ;
	while ( cin >> n >> m )
	{
		MS0( M ) ;
		for ( int i = 0 ; i < n ; i ++ )
		{
			for ( int j = 0 ; j <= m ; j ++ )
			{
				cin >> M[ i ][ j ] ;
			}
		}
		for ( int j = 0 ; j < m ; j ++ )
		{
			cin >> M[ n ][ j ] ;
		}
		//printMatrix( &M[ 0 ][ 0 ] , n + 1 , m + 1 , 101 ) ;
		for ( int i = 0 , p = 0 , bestIndex ; i < m ; i ++ )
		{
			bestIndex = -1 ;
			// find other wrong answer
			for ( int j = p ; j < n ; j ++ )
			{
				if ( fabs( M[ j ][ i ] ) > EPS )
				{
					bestIndex = j ;
					break ;
				}
			}
			if ( -1 != bestIndex )
			{
				swapColumn( &M[ 0 ][ 0 ] , p , bestIndex , m + 1 , 101 ) ;
				multiplyColumn( &M[ 0 ][ 0 ] , p , 1.0 / M[ p ][ i ] , m + 1 , 101 ) ;
				for ( int j = 0 ; j <= n ; j ++ )
				{
					if ( j != p )
					{
						subtractColumn( &M[ 0 ][ 0 ] , j , p , M[ j ][ i ] , m + 1 , 101 ) ;
					}
				}
				p ++ ;
			}
		}
		cout << scoreStatus( &M[ 0 ][ 0 ] , n , m , 101 ) << endl ;
		//printMatrix( &M[ 0 ][ 0 ] , n + 1 , m + 1 , 101 ) ;
	}
	return 0 ;
}

