#include <iostream>
#include <unordered_set>

using namespace std;


bool IsAnUglyNumber( int number, unordered_set<int> &uglyNumbers )
{
  bool determined = false;

  while( number > 0 && !determined )
  {
    if ( uglyNumbers.find( number ) != uglyNumbers.end() )
      determined = true;
    else if ( number % 2 == 0 )
      number /= 2;
    else if ( number % 3 == 0 )
      number /= 3;
    else if ( number % 5 == 0 )
      number /= 5;
    else
      determined = ( number == 1 );
  }

  return determined;
}

int main()
{
  int i = 0, count = 0, number;
  unordered_set<int> uglyNumbers;

  do
  {
    i++;

    if( IsAnUglyNumber( i, uglyNumbers ) )
    {
      uglyNumbers.insert( i );
      count++;
    }
  }
  while( count < 1500 );

  cout<<"The 1500'th ugly number is "<<i<<endl;
}
