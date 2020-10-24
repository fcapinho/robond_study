#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

/* TODO: Define a Map class
   Inside the map class, define the mapWidth, mapHeight and grid as a 2D vector
*/
class Map 
{
    public:
        const static int mapWidth = 6;
        const static int mapHeight = 5;
        vector<vector<int>> grid;

        Map() 
        {
           grid = vector<vector<int>>(mapHeight, vector<int>(mapWidth, 0));

           grid[0][1] = 1;
           grid[1][1] = 1;
           grid[2][1] = 1;
           grid[3][1] = 1;
           grid[4][3] = 1;
           grid[4][4] = 1;
        }
};

/* TODO: Define a Planner class
   Inside the Planner class, define the start, goal, cost, movements, and movements_arrows
   Note: The goal should be defined it terms of the mapWidth and mapHeight
*/
class Planner
{
    public:
        vector<int> start, goal;
        int cost;
        vector<vector<int>> movements;
        vector<string> movements_arrows;

    Planner()
    {
        start = { 0, 0 };
        goal = { 4, 5 };
        cost = 1;
        movements = vector<vector<int>>(4, vector<int>(2));
        movements[0] = { -1,  0 };
        movements[1] = {  0, -1 };
        movements[2] = {  1,  0 };
        movements[3] = {  0,  1 };

        movements_arrows = { "^", "<", "v", ">"};
    }
};

/* TODO: Define a print2DVector function which will print 2D vectors of any data type
   Example
   
   Input: 
   vector<vector<int> > a{{ 1, 0 },{ 0, 1 }};
   print2DVector(a);
   vector<vector<string> > b{{ "a", "b" },{ "c", "d" }};
   print2DVector(b);
   
   Output:
   1 0
   0 1
   a b
   c d
   Hint: You need to use templates
*/
template <typename T>
void print2DVector(vector<vector<T>> vect) 
{
    for(int i = 0; i < vect.size(); i++) {
        for(int j = 0; j < vect[i].size(); j++) {
            cout << vect[i][j] << " "; 
        }
        cout << endl;
    }
}

/*############ Don't modify the main function############*/
int main()
{
    // Instantiate map and planner objects
    Map map;
    Planner planner;

    // Print classes variables
    cout << "Map:" << endl;
    print2DVector(map.grid);
    cout << "Start: " << planner.start[0] << " , " << planner.start[1] << endl;
    cout << "Goal: " << planner.goal[0] << " , " << planner.goal[1] << endl;
    cout << "Cost: " << planner.cost << endl;
    cout << "Robot Movements: " << planner.movements_arrows[0] << " , " << planner.movements_arrows[1] << " , " << planner.movements_arrows[2] << " , " << planner.movements_arrows[3] << endl;
    cout << "Delta:" << endl;
    print2DVector(planner.movements);

    return 0;
}
