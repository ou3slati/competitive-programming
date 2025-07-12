#include "catdog.h"

int x;

void initialize(int N, std::vector<int> A, std::vector<int> B) {
  x = A.size();
}

int cat(int v) {
  return 1;
}

int dog(int v) {
  return 2;
}

int neighbor(int v) {
  return 3;
}
