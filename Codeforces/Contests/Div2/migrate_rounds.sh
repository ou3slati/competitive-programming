#!/bin/bash

# Base directories
SRC_DIR="/Users/amineoueslati/Desktop/Competitive Programming/Codes/Codeforces/Rated"
DEST_DIR="/Users/amineoueslati/Desktop/competitive-programming/Codeforces/Contests/Div2"

# Function to process a single round
process_round() {
    local round=$1
    local contest_id=$2
    echo "Processing Round $round (Contest $contest_id)..."
    
    # Create round directory
    mkdir -p "$DEST_DIR/Round$round"
    
    # Copy all .cpp files
    find "$SRC_DIR/$round" -name "*.cpp" -exec cp {} "$DEST_DIR/Round$round/" \;
    
    # Clean template code from all .cpp files
    for file in "$DEST_DIR/Round$round"/*.cpp; do
        if [ -f "$file" ]; then
            # Remove template header
            sed -i '' -e '/Never stop trying/,/using namespace std;/c\
#include <bits/stdc++.h>\
using namespace std;\
' "$file"
            
            # Remove template footer
            sed -i '' -e '/Careful!!!/,$d' "$file"
        fi
    done
}

# Process rounds in parallel
process_round "675" "1422" &
process_round "676" "1421" &
process_round "678" "1426" &

# Wait for all background processes to complete
wait

echo "All rounds processed!"
