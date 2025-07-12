#include <vector>

/**
 * schedules to compare the art in rooms i and j during your next visit to
 * the museum (1 ≤ i, j ≤ N, i ≠ j). Immediately after a call to this function,
 * the museum can decide to swap the art collections of rooms i and j.
 */
void schedule(int, int);

/**
 * visits the museum and performs all scheduled comparisons. This function
 * returns an array with exactly one entry for each scheduled comparison
 * since your last visit to the museum (that is, for each call to schedule
 * since the last call to visit or the beginning of the program).
 * The entry at index k is 1 if the art in room i has a higher aesthetic
 * value than in room j, and 0 otherwise. Here, i and j are the rooms
 * from the (k + 1)-th scheduled comparison.
 */
std::vector<int> visit();

/**
 * publishes your list of all the rooms of the museum ordered by decreasing
 * aesthetic value. r must be an array of length N with its i-th entry being
 * the room with the (i + 1)-th most aesthetic art collection at the end of
 * your last visit to the museum. You have to call this function exactly once;
 * your program will be automatically terminated afterwards.
 */
void answer(std::vector<int>);

void solve(int, int);