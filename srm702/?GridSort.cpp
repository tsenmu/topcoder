#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
    

using namespace std;

class GridSort {
public:
    string sort(int, int, vector <int>);
    void swapRow(vector<int>& grid, int n, int m, int r1, int r2, vector<int>& locRow);
    void swapCol(vector<int>& grid, int n, int m, int c1, int c2, vector<int>& locCol);
};

void GridSort::swapRow(vector<int>& grid, int n, int m, int r1, int r2, vector<int>& locRow) {
    if (r1 == r2) {
        return;
    }

    for (int i = 0; i < m; ++i) {
        swap(grid[r1 * n + i], grid[r2 * n + i]);
        locRow[r1 * n + 1] = r2;
        locRow[r2 * n + 1] = r1;
    }
}

void GridSort::swapCol(vector<int>& grid, int n, int m, int c1, int c2, vector<int>& locCol) {
    if (c1 == c2) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        swap(grid[i * n + c1], grid[i * n + c2]);
        locCol[i * n + c1] = c2;
        locCol[i * n + c2] = c1;
    }
}

string GridSort::sort(int n, int m, vector <int> grid) {
    bool isPossible = true;
    int size = grid.size();
    vector<int> locRow(size + 1, 0);
    vector<int> locCol(size + 1, 0);
    for (int i = 0; i < size; ++i) {
        locRow[grid[i]] = i / n;
        locCol[grid[i]] = i % n;
    }

    for (int i = 0; i < size; ++i) {
        if (grid[i] != i + 1) {
            swapRow(grid, n, m, locRow[grid[i]], locRow[i + 1], locRow);
            swapCol(grid, n, m, locCol[grid[i]], locCol[i + 1], locCol);
        }
    }

    for (int i = 0; i < size; ++i) {
        if (grid[i] != i + 1) {
            isPossible = false;
            break;
        }
    }
    
    return isPossible ? "Possible" : "Impossible";
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!