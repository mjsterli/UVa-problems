#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
  Prints out the vector<char>
*/
void PrintPattern( vector<char> pattern )
{
  for( int i = 0; i < pattern.size(); i++ )
    cout<<pattern[i];
  cout<<endl;
}

/*
  Sorts the vector starting at a particular index
*/
void SortSubstring( vector<char> &substring, int startIndex )
{
  char temp;
  for( int i = startIndex; i < substring.size(); i++ )
    for( int j = i + 1; j < substring.size(); j++ )
    {
      if( substring[j] < substring[i] )
      {
        temp = substring[i];
        substring[i] = substring[j];
        substring[j] = temp;
      }
    }
}

/*
  Gets the next pattern in the permutation
  1. Find the highest index i such that s[i] < s[i+1]. If no such index exists, the permutation is the last permutation.
  2. Find the highest index j > i such that s[j] > s[i]. Such a j must exist, since i+1 is such an index.
  3. Swap s[i] with s[j].
  4. Reverse the order of all of the elements after index i till the last element.
  Read article https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
*/
void NextPattern( vector<char> pattern )
{
  char temp;
  int i = pattern.size() - 1, j, lo, hi;
  bool foundLo = false, foundHi = false;

  while( i > 0 && !foundLo )
  {
    if( pattern[i] > pattern[i-1] ) //Find the highest in order index.
    {
      foundLo = true;
      lo = i - 1;
      j = pattern.size() - 1; // Because we are looking for the highest index, it would be best to start from the end rather than the beginning of the vector

      while( j > lo && !foundHi )
      {
        if( pattern[j] > pattern[lo] ) //Now find the highest index that is greater than the value of pattern[lo]
        {
          foundHi = true;
          hi = j;
        }
        j--;
      }

      //Switch the hi and lo characters
      temp = pattern[hi];
      pattern[hi] = pattern[lo];
      pattern[lo] = temp;

      // Sort all characters after the lo
      SortSubstring( pattern, lo + 1 );
      PrintPattern( pattern );
    }
    i--;
  }

  if( !foundLo ) // We could not find any in-order adjacent characters so this must be the last permutation
    cout<<"No Successor"<<endl;
}

int main()
{
  vector<string> inputs;
  string input = "";

  while ( input != "#" ) // Read all inputs until we read a #
  {
    cin>>input;
    if( input != "#" )
    {
      if( input.size() <= 50 ) // All input has to be less than 50 characters
      inputs.push_back( input );
    }
  }

  for( int i = 0; i < inputs.size(); i++ )
  {
    vector<char> pattern( inputs[i].c_str(), inputs[i].c_str() + inputs[i].size() );
    NextPattern( pattern );
  }
}
