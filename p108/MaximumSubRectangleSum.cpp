#include <iostream>
#include <vector>

using namespace std;

int MaxSubRectangleSum( vector< vector<int> > m )
{
  int maxSum = -128, sum;
  for( int h = 0; h < m.size() - 1; h++ ) // controls the limit of the height of your rectangle
    for( int i = 0; i < m.size() - 1; i++ ) // controls the limit of the lenght of your rectangle
      for( int j = i + 1; j < m.size(); j++ ) // your starting point for the length of your rectangle
      {
        sum = 0;
        for( int k = h; k < m.size(); k++ ) // iterates through each permutation of rectangles by row
        {
          for( int l = j; l >= i; l-- ) // iterates through each permutation of rectangles by columns
            sum += m[k][l];

          if( k != h && sum > maxSum ) // if you are a multi dimensional permutation, then check your sum
            maxSum = sum;
        }
      }

  return maxSum;
}

int main()
{
  int matrixSize, t;
  cin>>matrixSize; //Input of the size of the 2 dimensional array (n*n)
  vector< vector<int> > matrix;
  for( int i = 0; i < matrixSize; i++ )
  {
    matrix.push_back( vector<int>() );
    for( int j = 0; j < matrixSize; j++ )
    {
      cin>>t;
      matrix[i].push_back(t);
    }
  }

  cout<<MaxSubRectangleSum( matrix )<<endl;
}
