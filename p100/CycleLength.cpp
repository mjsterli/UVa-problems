#include <iostream>
#include <unordered_map>

using namespace std;

int CycleLength( int number, unordered_map<int, int> &lengths )
{
  if( number == 1 )
    return 1;
  else if( lengths.find( number ) != lengths.end() )
    return lengths[number];
  else
  {
    int l = ( number % 2 == 0 ? CycleLength( number / 2, lengths ) : CycleLength( (3 * number)+1, lengths ) ) + 1;
    lengths[number] = l;
    return l;
  }

}


int main()
{
  unordered_map<int, int> cycleLengths;
  int i, j, highestCycleLength, lo, hi;
  while( cin>>i>>j )
  {
    highestCycleLength = 0;
    if( i < j )
    {
      lo = i;
      hi = j;
    }
    else
    {
      hi = i;
      lo = j;
    }
    for( int a = lo; a <= hi; a++ )
    {
      int length = CycleLength( a, cycleLengths );
      if( length > highestCycleLength )
        highestCycleLength = length;
    }

    cout<<i<<" "<<j<<" "<<highestCycleLength<<endl;
  }
}
