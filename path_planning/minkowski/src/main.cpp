#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Print 2D vectors coordinate values
void print2DVector(vector<vector<int> > vec)
{
     // Sorting the vector for grading purpose
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec[0].size(); ++j) {
                cout << vec[i][j] << "  ";
        }
        cout << endl;
    }
}

// ***TODO: Check for duplicate coordinates inside a 2D vector and delete them*** //
vector<vector<int> > delete_duplicate(vector<vector<int> > C)
{
    vector<vector<int>> newC;

    for(int i = 0; i < C.size(); i++) {
        if ( find(newC.begin(), newC.end(), C[i]) == newC.end() ) {
            newC.push_back(C[i]);
        } 
    }

    return newC;
}

// ***TODO: Compute the Minkowski Sum of two vectors***//
vector<vector<int> > minkowski_sum(vector<vector<int> > A, vector<vector<int> > B)
{
    vector<vector<int> > C;
    
    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < A.size(); ++j) {
                C.push_back({ (B[i][0] + A[j][0]), (B[i][1] + A[j][1])});
        }
    }
    
    C = delete_duplicate(C);
    return C;
}

int main()
{
    // ***TODO: Define the coordinates of triangle A and B using 2D vectors*** //
    vector<vector<int>> A
    {
        {0, 1},
        {1, 0},
        {0, -1}
    };
    
    vector<vector<int>> B
    {
        {0, 0},
        {1, 1},
        {1, -1}
    };

    // Compute the minkowski sum of triangle A and B
    vector<vector<int> > C;
    C = minkowski_sum(A, B);

    // Print the resulting vector
    print2DVector(C);

    return 0;
}