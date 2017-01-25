#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Initialize( vector< vector<int> > &blocks, int number )
{
  vector<int> stack = blocks[abs(blocks[number][0])];
  do
  {
    int popped = stack.pop_back();
    blocks[popped][0] = popped;
  }while( stack.back() != number );
}

void Move( vector< vector<int> > &blocks, int from, int to )
{
  vector<int> tempStack, fromStack, toStack;
  bool found = false;
  fromStack = blocks[abs(blocks[from][0])];

  do
  {
    found = ( fromStack.back() == from );
    tempStack.push_back( fromStack.pop_back() );
  } while( !found );

  toStack = blocks[abs(blocks[to][0])];
  do
  {
    blocks[tempStack.back()][0] = to * -1;
    toStack.push_back( tempStack.pop_back() );
  }while( tempStack.size() != 0 );
}

int main()
{

}
