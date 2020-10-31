#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

// Map class
class Map {
public:
    const static int mapWidth = 6;
    const static int mapHeight = 5;
    vector<vector<int> > grid = {
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0 }
    };
};

// Planner class
class Planner : Map {
public:
    int start[2] = { 0, 0 };
    int goal[2] = { mapHeight - 1, mapWidth - 1 };
    int cost = 1;

    string movements_arrows[4] = { "^", "<", "v", ">" };

    vector<vector<int> > movements{
        { -1, 0 },
        { 0, -1 },
        { 1, 0 },
        { 0, 1 }
    };
};

// Template function to print 2D vectors of any type
template <typename T>
void print2DVector(T Vec)
{
    for (int i = 0; i < Vec.size(); ++i) {
        for (int j = 0; j < Vec[0].size(); ++j) {
            cout << Vec[i][j] << ' ';
        }
        cout << endl;
    }
}

void printTriplet(array<int, 3> triplet)
{
    cout << "[ ";
    for(const auto& t: triplet) {
        cout << t << ' ';
    }
    cout << "]" << endl;
}

/*#### TODO: Code the search function which will generate the expansion list ####*/
// You are only required to print the final triplet values
void search(Map map, Planner planner)
{
    array<int, 3> cell_picked;
    vector<array<int, 3>> open_list = { {0, planner.start[0], planner.start[1]} };
    int expansion = 0;
    vector<array<int, 2>> visited_cells = { {planner.start[0], planner.start[1]} };

    vector<vector<int>> expansion_matrix(map.mapHeight, vector<int>(map.mapWidth, -1));

    while (!open_list.empty()) {
        cout << "Expansion #: " << expansion << endl;
    
        // Pick cell
        cell_picked = open_list.back();
        open_list.pop_back();

        expansion_matrix[cell_picked[1]][cell_picked[2]] = expansion++;

        cout << "Next cell: "; printTriplet(cell_picked);
        
        // Check if reached the goal
        if ( (cell_picked[1] == planner.goal[0]) && (cell_picked[2] == planner.goal[1])) {
            printTriplet(cell_picked);
            break;
        }

        // Expand the search
        for (const auto& m: planner.movements) {
            int new_x = cell_picked[1] + m[0];
            int new_y = cell_picked[2] + m[1];
            // Check for valid coordinates
            if ( (new_x >= 0) && (new_x < map.mapHeight) && (new_y >= 0) && (new_y < map.mapWidth) ) {
                // Check for visited cell
                vector<array<int, 2>>::iterator it;
                array<int, 2> new_cell = { new_x, new_y };
                it = find (visited_cells.begin(), visited_cells.end(), new_cell );
                if (it == visited_cells.end()) {
                    // Check for empty cell
                    if ( map.grid[new_x][new_y] == 0) {
                        array<int, 3> new_item = { cell_picked[0] + planner.cost, new_x, new_y };
                        open_list.insert(open_list.begin(), new_item);
                        visited_cells.push_back(new_cell);
                    }
                }
            }
        }
    }

    if (open_list.empty()) {
        cout << "Roadblock" << endl;
    } else {
        print2DVector(expansion_matrix);
    }
}

int main()
{
    // Instantiate map and planner objects
    Map map;
    Planner planner;

    // Search for the expansions
    search(map, planner);

    return 0;
}
