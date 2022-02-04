#include "solution.h"

#include <functional>
#include <unordered_map>
#include <stack>
using namespace sol1522;
using namespace std;

/* takeaways
   - the longest paths
     - they are from a leave node to another
       leave node
     - or leave node to root
       (if root has only one child)

   - visiting a node to find the top 1
     and top 2 paths in length
     - it's better to draw a tree to
       understand this
             /
             2
          / / \ \
         3 4  5  6
     - the possible paths are 3-2-4, 4-2-5, ...
     - from 2's point, the longest path is formed
       from the top two of the child paths in length
       plus itself

   - here is the trciky part
     - a node's children might alread can form the longest
       and move up the tree to include node won't help
     - check the example 2 in the question
       - once you done visiting the node 2, you move up to node
         node 1 and report the top 1 length "2" back along the
         way
       - the maxLength so far is 4
       - node 1 only has 1 child, so the top 1 for it
         is 2 (reports back by node 2) plus 1 as you traveled
         up one more. Top 2 for node 1 is 0
       - so if path formed including node 1 can only have
         a length of 3 ( 3 + 0)
       - so node 1 is not included

*/

int Solution::diameter(Node *tree)
{
  /*
    - track the max length of the paths
      been examined
  */
  int maxLength = 0;

  function<int(Node *)> dfs = [&maxLength, &dfs](Node *node)
  {
    int top1 = 0, top2 = 0;
    for (auto c : node->children)
    {
      /*
         - add one more as you are one up from
           the children
      */
      auto cMaxLen = dfs(c) + 1;
      if (cMaxLen > top1)
        top1 = cMaxLen;
      else if (cMaxLen > top2)
        top2 = cMaxLen;
    }
    /*
       - we might or might not have a longer path after
         examining the new paths formed that include
        this node
    */
    maxLength = max(maxLength, top1 + top2);
    /*
       - report the longest and let the parent make the pick
         among its children
       - you might wonder what happen if all your siblings’
         top1 is shorter than your top2
       - that's why we have an additional variable maxLength
         to track the length of the longest path. In this
         case, maxLength won't get updated after visiting
         the parent node.
    */
    return top1;
  };

  dfs(tree);
  return maxLength;
}