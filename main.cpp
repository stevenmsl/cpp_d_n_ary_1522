#include <iostream>
#include <vector>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1522;

/*
 Input: root = [1,null,3,2,4,null,5,6]
 Output: [1,null,3,2,4,null,5,6]
*/

Node *testFixture2()
{
  /* build the tree first */
  auto *tree = new Node(1);

  tree->children.push_back(new Node(2));

  tree->children[0]->children.push_back(new Node(3));
  tree->children[0]->children.push_back(new Node(4));

  tree->children[0]->children[0]->children.push_back(new Node(5));
  tree->children[0]->children[1]->children.push_back(new Node(6));

  return tree;
}

Node *testFixture3()
{
  /* build the tree first */
  auto *tree = new Node(1);
  tree->children.push_back(new Node(2));
  tree->children.push_back(new Node(3));
  tree->children.push_back(new Node(4));
  tree->children.push_back(new Node(5));

  /* level 3 */
  tree->children[1]->children.push_back(new Node(6));
  tree->children[1]->children.push_back(new Node(7));

  tree->children[2]->children.push_back(new Node(8));

  tree->children[3]->children.push_back(new Node(9));
  tree->children[3]->children.push_back(new Node(10));

  /* level 4 */
  tree->children[1]->children[1]->children.push_back(new Node(11));
  tree->children[2]->children[0]->children.push_back(new Node(12));
  tree->children[3]->children[0]->children.push_back(new Node(13));

  /* level 5 */
  tree->children[1]->children[1]->children[0]->children.push_back(new Node(14));

  return tree;
}

void test2()
{
  auto tree = testFixture2();

  cout << "Test 2 - expect to see 4" << endl;
  Solution sol;

  auto length = sol.diameter(tree);
  cout << "result: " << length << endl;
}

void test3()
{
  auto tree = testFixture3();

  cout << "Test 3 - expect to see 7" << endl;
  Solution sol;

  auto length = sol.diameter(tree);
  cout << "result: " << length << endl;
}

void testLevelOrderHeight()
{
  auto fixture = testFixture3();
  cout << " Test Level Order Height - expect to see 5" << endl;
  cout << "tree height: " << LevelOrder::height(fixture) << endl;
}

void tesLevelOrderToVec()
{
  auto fixture = testFixture3();
  cout << " Test Level Order to Vec" << endl;
  cout << "result: use debugger to verify result" << endl;

  auto tree = LevelOrder::toVec(fixture);
}

void testXOR()
{
  int root = 0;
  int node = 1;

  root ^= node;

  root ^= 2;
  root ^= 3;
  root ^= 2;
  root ^= 3;
}
void testToStr()
{
  auto fixture = testFixture2();
  cout << LevelOrder::toStr(fixture) << endl;
}

main()
{
  test2();
  test3();
  //    testLevelOrderHeight();
  //    tesLevelOrderToVec();
  //   testXOR();
  // testToStr();
  return 0;
}