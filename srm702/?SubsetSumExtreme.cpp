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

class SubsetSumExtreme {
public:
    double getExpectation(vector <int>, vector <int>);
};

void findSubset(vector<vector<int> >& subsets,
    int targetSum,
    const vector<int>& block,
    vector<int>& currentSubset,
    int currentSum,
    int currentStartIndex) {

    if (currentSum == targetSum) {
        subsets.push_back(currentSubset);
        return;
    }

    if (currentSum > targetSum) {
        return;
    }

    for (int i = currentStartIndex; i < block.size(); ++i) {
        currentSubset.push_back(i);
        findSubset(subsets, targetSum, block, currentSubset, currentSum + block[i], i + 1);
        currentSubset.pop_back();
    }
}

double calculateMinExpectation(vector<bool>& visited,
    const vector<vector<vector<int> > >& allSubsets,
    const vector<int>& block,
    const vector<int>& face) {

    double ans = 0;
    bool found = false;

    for (int i = 0; i < face.size(); ++i) {
        const vector<vector<int> >& subsets = allSubsets[i];

        double minExp = numeric_limits<double>::max();
        for (int j = 0; j < subsets.size(); ++j) {
            const vector<int>& subset = subsets[j];
            bool isValidSubset = true;
            for (int k = 0; k < subset.size(); ++k) {
                if (visited[subset[k]]) {
                    isValidSubset = false;
                    break;
                }
            }

            if (isValidSubset) {
                found = true;
                for (int k = 0; k < subset.size(); ++k) {
                    visited[subset[k]] = true;
                }

                minExp = min(minExp, 
                    1.0 / face.size() * calculateMinExpectation(visited, allSubsets, block, face));


                for (int k = 0; k < subset.size(); ++k) {
                    visited[subset[k]] = false;
                }
            }
        }

        if (minExp == numeric_limits<double>::max()) {
            int remainingSum = 0;
            for (int j = 0; j < block.size(); ++j) {
                if (!visited[j]) {
                    remainingSum += block[j];
                }
            }
            ans += (double) remainingSum / face.size();
        } else {
            ans += minExp;
        }
    }

    if (!found) {
        int remainingSum = 0;
        for (int i = 0; i < block.size(); ++i) {
            if (!visited[i]) {
                remainingSum += block[i];
            }
        }
        ans = remainingSum;
    }

    return ans;
}

double SubsetSumExtreme::getExpectation(vector <int> block, vector <int> face) {
    vector<vector<vector<int> > > allSubsets;
    for (int i = 0; i < face.size(); ++i) {
        vector<vector<int> > subsets;
        vector<int> currentSubset;
        findSubset(subsets, face[i], block, currentSubset, 0, 0);
        allSubsets.push_back(subsets);
    }

    vector<bool> visited(block.size(), false);
    return calculateMinExpectation(visited, allSubsets, block, face);
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!