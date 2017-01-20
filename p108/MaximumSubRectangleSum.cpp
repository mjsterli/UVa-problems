#include <iostream>

using namespace std;

int MaxSubRectangleSum( int[][] matrix, int size )
{
  int maxSum = -128, sum;
  for( int h = 0; h < size - 1; h++ )
    for( int i = 0; i < size - 1; i++ )
      for( int j = i + 1; j < size; j++ )
      {
        sum = 0;
        for( int k = h; k < size; k++ )
          for( int l = j; l > i; l-- )
          {
            sum += matrix[k][l];
            if( k != h && sum > maxSum )
              maxSum = sum;
          }
      }

  return maxSum;
}

int main()
{
  int matrixSize;
  cin>>matrixSize;
  int[][] matrix = new int[matrixSize][matrixSize];
  for( int = 0; i < matrixSize; i++ )
    for( int j = 0; j < matrixSize; j++ )
      cin>>matrix[i][j];

  cout<<MaxSubRectangleSum( matrix, matrixSize )<<endl;
}
