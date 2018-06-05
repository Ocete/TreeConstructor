#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

/*
  PLEASE READ THIS COMMENT FIRST

  So, I've trying to deal with these two lines in the training period for a long time:

    string A[] = gets(stdin);
    cout << TreeConstructor(A);

  That's the default version for reading the input done by this website, it doesn't work
  if you compile out of it. The problem is, I'm not able to know how long the
  array A is. So I've changed the way the reading is done BUT the input is
  horrible to read just as it is presented.

  I've prepared a GitHub repository with the code, a makefile and an input file
  with the refracted data provided by the CoderByte website (which I currently don't have
  but I will right when I send this).

  https://github.com/Ocete/TreeConstructor

  Sorry for the inconvenience,
  Jose
*/

// This methods fills the map "m", where map[i] represents the parent of i
// Returns true if there is only 1 possible root, false in any other case
// If true is returned, the possible will be in the variable root
bool FillMap(map<int,int> &child_of, set<int> &nodes, vector<pair<int,int> > &v, int &root) {
  set<int> possible_roots;
  map<int,int> childs_per_node;

  // v[i].first (= c) is child of v[i].second (= p)
  for (int i=0; i<v.size(); i++) {
    // Check that the numbers of childs per node is lower than 3
    childs_per_node[v[i].second] += 1;
    if ( childs_per_node[v[i].second] >= 3 ) {
      return false;
    }

    // Check if p is a possible root so far by checking if it already has a parent
    if (child_of.find(v[i].second) == child_of.end()) {
        possible_roots.insert(v[i].second);
    }

    // Check if c was a possible root. It isn't anymore.
    set<int>::iterator it = possible_roots.find(v[i].first);
    if (it != possible_roots.end()) {
        possible_roots.erase(it);
    }

    // Add the new pair c->p, checking first that a node can only have 1 possible parent
    if (child_of.find(v[i].first) == child_of.end()) {
      child_of[v[i].first] = v[i].second;
    } else {
      return false;
    }
  }

  bool result = false;
  if (possible_roots.size() == 1) {
      root = *possible_roots.begin();
      result = true;
  }
  return result;
}

// Assuming no duplicates on the final tree
// Following the definition of tree as a "directed connected acyclic graph" we have to:
// 1. Find a root (unique)
// 2. Check the number if childs per node is max 2 (its binary)
// 3. Prove there are no cycles and that the graph is connected.
string TreeConstructor(vector<pair<int,int> > &v) {

  map<int,int> child_of;
  set<int> nodes;
  int root;

  // Step one and - Find the root and
  // step two - Check the number of childs per node.
  if ( !FillMap(child_of, nodes, v, root) ) {
      return "false";
  }

  // Step three: draw a path from each node to the root in order
  // to prove the tree is acyclic and connected.
  // Keepp in mind that we would reach the root within at most nodes.size() - 1 steps
  int child, steps;
  for (set<int>::iterator it = nodes.begin(); it != nodes.end(); it++) {
    child = *it;

    steps = nodes.size() - 1;
    while (child != root && steps > 0) {
        child = child_of[child];
        steps--;
    }

    if (child != root && steps == 0) {
        return "false";
    }
  }

  // We could make this last part way faster by marking as OK every node we
  // travel through on our way up

  return "true";
}

void ReadInput(vector<pair<int,int> > &v) {
  int n_pairs, aux1, aux2;
  cin >> n_pairs;

  v.clear();
  for (int i=0; i<n_pairs; i++) {
    cin >> aux1;
    cin >> aux2;
    v.push_back(pair<int,int> (aux1, aux2));
  }
}

int main() {
  int n_test_cases;
  vector<pair<int,int> > v;

  cin >> n_test_cases;

  for (int i=0; i<n_test_cases; i++) {
    ReadInput(v);
    cout << TreeConstructor(v) << endl;
  }

  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set
     it equal to the stdin to test your code with arrays. */
  /*
  string A[] = gets(stdin);
  cout << TreeConstructor(A);
  */
  return 0;

}
