#!/bin/bash

# Process all files in parallel
for file in A B C D; do
  # Extract core solution, remove template code
  sed -i '' -e '/Never stop trying/,/using namespace std;/c\
/*\
CF 673'"$file"' - Problem Title\
https://codeforces.com/contest/1417/problem/'"$file"'\
\
Key insights:\
1. TBD\
2. TBD\
3. TBD\
*/\
\
#include <bits/stdc++.h>\
using namespace std;\
' "/Users/amineoueslati/Desktop/competitive-programming/Codeforces/Contests/Div2/Round673/$file.cpp"

  # Remove template footer
  sed -i '' -e '/Careful!!!/,$d' "/Users/amineoueslati/Desktop/competitive-programming/Codeforces/Contests/Div2/Round673/$file.cpp"
done
