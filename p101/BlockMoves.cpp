#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Print( vector< vector<int> > blocks )
{
  for( int i = 0; i < blocks.size(); i++ )
  {
    cout<<i<<": ";
    for( int j = 0; j < blocks[i].size(); j++ )
      if( blocks[i][j] >= 0 )
        cout<<blocks[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
}

int GetStackIn( vector< vector<int> > blocks, int number )
{
  return ( blocks[number][0] >= 0 ? number : abs(blocks[number][0]) );
}

void Initialize( vector< vector<int> > &blocks, int number )
{
  int popped;
  vector<int> *stack = &blocks[GetStackIn( blocks, number)];

  while( stack->back() != number )
  {
    popped = stack->back();
    stack->pop_back();
    blocks[popped][0] = popped;
  }
}

void Move( vector< vector<int> > &blocks, int from, int to )
{
  int popped;
  vector<int> tempStack, *fromStack, *toStack;
  bool found = false;

  fromStack = &blocks[GetStackIn(blocks, from)];
  if( fromStack->size() == 1 )
    tempStack.push_back( fromStack->back() );
  else
  {
    do
    {
      popped = fromStack->back();
      if( fromStack->size() > 1 )
        fromStack->pop_back();
      tempStack.push_back( popped );
    }while( popped != from );
  }

  toStack = &blocks[GetStackIn(blocks, to)];
  do
  {
    blocks[tempStack.back()][0] = GetStackIn(blocks, to) * -1;
    popped = tempStack.back();
    toStack->push_back( popped );
    tempStack.pop_back();
  }while( tempStack.size() != 0 );
}


int main()
{
  vector< vector<int> > blocks;
  int numOfBlocks, a, b;
  string actionA = "", actionB;

  cin>>numOfBlocks;
  for( int i = 0; i < numOfBlocks; i++ )
  {
    blocks.push_back( vector<int>() );
    blocks[i].push_back(i);
  }

  cin>>actionA;
  while( actionA != "quit" )
  {
    cin>>a>>actionB>>b;
    if( a != b && a < numOfBlocks && b < numOfBlocks && GetStackIn( blocks, a ) != GetStackIn( blocks, b ) )
    {
      if( actionA == "move" )
        Initialize( blocks, a );

      if( actionB == "onto" )
        Initialize( blocks, b );

      Move( blocks, a, b );
    }
    cin>>actionA;
  }
  Print( blocks );
}
