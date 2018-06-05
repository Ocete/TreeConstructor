# TreeConstructor

This repositoy will hold my solution to the TreeConstructor problem. The problem statement reads as follows:

Have the function TreeConstructor(strArr) take the array of strings stored in strArr, which will contain pairs of integers in the following format: (i1,i2), where i1 represents a child node in a tree and the second integer i2 signifies that it is the parent of i1. For example: if strArr is ["(1,2)", "(2,4)", "(7,2)"], then this forms the following tree:

                    4
                  /
                2
              /   \
            1       7

which you can see forms a proper binary tree. Your program should, in this case, return the string true because a valid binary tree can be formed. If a proper binary tree cannot be formed with the integer pairs, then return the string false. All of the integers within the tree will be unique, which means there can only be one node in the tree with the given integer value.

## Input

The test cases provided by the website are the following:

1. For the input ["(1,2)", "(2,4)", "(7,2)"] the correct answer is true.
2. For the input ["(1,2)", "(2,4)", "(5,7)", "(7,2)", "(9,5)"] the correct answer is true.
3. For the input ["(1, 2)", "(3,2)", "(2, 12)", "(5,2)"] the correct answer is false.
4. For the input ["(2,5)", "(2,6)"] the correct answer is false.
5. For the input ["(10,20)"] the correct answer is true.
6. For the input ["(2,3)", "(1,2)", "(4,9)", "(9,3)", "(12,9)", "(6,4)"] the correct answer is true.
7. For the input ["(2,3)", "(1,2)", "(4,9)", "(9,3)", "(12,9)", "(6,4)", "(1,9)"] the correct answer is false.
8. For the input ["(1,2)", "(2,4)", "(7,4)"] the correct answer is true.
9. For the input ["(5,6)", "(6,3)", "(2,3)", "(12,5)"] the correct answer is true.
10. For the input ["(10,20)", "(20,50)"] the correct answer is true.

This test cases are all in the input file along with another 2:

11. A graph with a cycle, ["(1,2)", "(2,3)", "(3,1)"] the correct answer is false.
12. A complete binary search tree of height 4 (16 nodes). The correct answer is true.

My algorithm hits the correct answer for all of those test cases.
