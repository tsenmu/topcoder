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

class TestTaking {
public:
    int findMax(int, int, int);
};

int TestTaking::findMax(int questions, int guessed, int actual) {
    return min(questions - guessed, questions - actual) + min(guessed, actual); 
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!