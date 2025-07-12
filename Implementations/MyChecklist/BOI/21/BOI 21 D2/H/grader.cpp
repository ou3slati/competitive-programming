/*
SAMPLE GRADER for task SWAPS

USAGE:
place together with your solution and swaps.h in the same directory, then:
g++ <flags> sample_grader.cpp <solution_file>
e.g.:
g++ -std=c++17 sample_grader.cpp swaps.cpp

INPUT/OUTPUT:
The sample grader expects on standard input the numbers N and V as well as a
list of N integers, the rooms ordered by decreasing aesthetic value at the
beginning of solve. Then, the grader writes to standard output a protocol of
all grader functions called by your program. Whenever schedule(i, j) is called,
the grader expects on standard input the number 1 if the art collections of
rooms i and j should be swapped at that point in time, or 0 otherwise.
At the end, the grader prints your verdict.
*/
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>

#include "swaps.h"

using namespace std;

void __attribute__((noreturn)) __attribute__((format(printf, 1, 2))) result(const char *msg, ...) {
    va_list args;
    va_start(args, msg);
    vfprintf(stderr, msg, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(0);
}

namespace {
    int N, V, visits;
    set<int> queryIndices;
    vector<int> A, queryResult;
}

void schedule(int i, int j) {
    printf("schedule(%d, %d)\n", i, j);
    fflush(stdout);

    if (i < 1 || i > N || j < 1 || j > N || i == j)
        result("Invalid schedule");
    if (queryIndices.find(i) != queryIndices.end() || queryIndices.find(j) != queryIndices.end())
        result("Invalid schedule");
    queryIndices.insert(i);
    queryIndices.insert(j);

    int s;
    if (scanf("%d", &s) != 1 || (s != 0 && s != 1))
        result("Invalid input");
    if (s)
        swap(A[i], A[j]);
    queryResult.push_back(A[i] < A[j]);
}

vector<int> visit() {
    printf("visit(): {");
    for (int i = 0; i < (int)queryResult.size(); i++) {
        printf("%d", queryResult[i]);
        if (i + 1 != (int)queryResult.size())
            printf(", ");
    }
    printf("}\n");
    fflush(stdout);

    visits++;
    if (visits > V)
        result("Out of visits");

    vector<int> res = queryResult;
    queryIndices.clear();
    queryResult.clear();
    return res;
}

void answer(vector<int> r) {
    printf("answer({");
    for (int i = 0; i < (int)r.size(); i++) {
        printf("%d", r[i]);
        if (i + 1 != (int)r.size())
            printf(", ");
    }
    printf("})\n");

    if ((int)r.size() != N)
        result("Invalid answer");

    for (int i = 0; i < N; i++) {
        if (r[i] < 1 || r[i] > N)
            result("Invalid answer");
        if (A[r[i]] != i + 1)
            result("Wrong answer");
    }

    result("Correct: %d visit(s) used", visits);
}

int main() {
    if (scanf("%d %d", &N, &V) != 2 || N < 1 || V < 0)
        result("Invalid input");

    A.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        int x;
        if (scanf("%d", &x) != 1 || x < 1 || x > N || A[x])
            result("Invalid input");
        A[x] = i;
    }

    solve(N, V);

    result("No answer");
}
