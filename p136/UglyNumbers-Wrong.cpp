#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

void Produce2( vector<unsigned long long> &uNumbers, vector<unsigned long long> &u2, vector<unsigned long long> &u3, vector<unsigned long long> &u5 )
{
  int i;
  unsigned long long product;

  for( i = 0; i < u2.size(); i++ )
  {
    product = (unsigned long long)( 2ull * u2[i] );
    if( product != 0 )
    {
      uNumbers.push_back( product );
      u2.push_back( product );
    }
  }
}

void Produce3( vector<unsigned long long> &uNumbers, vector<unsigned long long> &u2, vector<unsigned long long> &u3, vector<unsigned long long> &u5 )
{
  int i;
  unsigned long long product;

  for( i = 0; i < u3.size(); i++ )
  {
    product = (unsigned long long)( 3ull * u3[i] );
    if( product != 0 )
    {
      uNumbers.push_back( product );
      u2.push_back( product );
      u3.push_back( product );
    }
  }
}

void Produce5( vector<unsigned long long> &uNumbers, vector<unsigned long long> &u2, vector<unsigned long long> &u3, vector<unsigned long long> &u5 )
{
  int i;
  unsigned long long product;

  for( i = 0; i < u5.size(); i++ )
  {
    product = (unsigned long long)( 5ull * u5[i] );
    if( product != 0 )
    {
      uNumbers.push_back( product );
      u2.push_back( product );
      u3.push_back( product );
      u5.push_back( product );
    }
  }
}

int Partition( vector<unsigned long long> &A, int lo, int hi )
{
  int i = lo, j;
  unsigned long long pivot = A[hi], temp;

  for( j = lo; j <= hi - 1; j++ )
    if( A[j] <= pivot )
    {
      temp = A[j];
      A[j] = A[i];
      A[i] = temp;
      i++;
    }

  temp = A[hi];
  A[hi] = A[i];
  A[i] = temp;

  return i;
}

void Print( vector<unsigned long long> A )
{
  for( int i = 0; i < A.size(); i++ )
    cout<<A[i]<<" ";
  cout<<endl;
}

void QuickSort( vector<unsigned long long> &A, int lo, int hi )
{
  if( lo < hi )
  {
    int p = Partition( A, lo, hi );
    QuickSort( A, lo, p - 1 );
    QuickSort( A, p + 1, hi );
  }
}


int main()
{
  int i = 0, size = 150;
  vector<unsigned long long> uglyNumbers, pu2, pu3, pu5;
  uglyNumbers = { 1ull, 2ull, 3ull, 5ull };
  pu2 = { 2ull, 3ull, 5ull };
  pu3 = { 3ull, 5ull };
  pu5 = { 5ull };

  do
  {
    i++;

    Produce2( uglyNumbers, pu2, pu3, pu5 );
    Produce3( uglyNumbers, pu2, pu3, pu5 );
    Produce5( uglyNumbers, pu2, pu3, pu5 );
  }
  while( i < size );

  QuickSort( uglyNumbers, 0, uglyNumbers.size() - 1 );
  cout<<"The "<<size<<"'th ugly number is "<<uglyNumbers[size-1]<<endl;
}
