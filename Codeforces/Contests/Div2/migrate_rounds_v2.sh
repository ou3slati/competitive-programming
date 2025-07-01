#!/bin/bash

# Base directories
SRC_DIR="/Users/amineoueslati/Desktop/Competitive Programming/Codes/Codeforces/Rated"
DEST_DIR="/Users/amineoueslati/Desktop/competitive-programming/Codeforces/Contests/Div2"

# Contest IDs mapping (add as needed)
declare -A CONTEST_IDS=(
    ["679"]="1435"
    ["680"]="1445"
    ["681"]="1443"
    ["682"]="1438"
    ["683"]="1447"
)

# Function to process a single round
process_round() {
    local round=$1
    local contest_id=${CONTEST_IDS[$round]}
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
            
            # Add basic header structure
            filename=$(basename "$file" .cpp)
            sed -i '' -e '1i\
/*\
CF '"$round$filename"' - TBD\
https://codeforces.com/contest/'"$contest_id"'/problem/'"$filename"'\
\
Key insights:\
1. TBD\
2. TBD\
3. TBD\
*/\
' "$file"
        fi
    done
    
    # Create README.md template
    cat > "$DEST_DIR/Round$round/README.md" << EOL
# Codeforces Round #$round (Div. 2)
[Contest Link](https://codeforces.com/contest/$contest_id)

## Problems
EOL
}

# Process multiple rounds in parallel
for round in 679 680 681 683; do
    process_round "$round" &
done

# Wait for all background processes to complete
wait

echo "All rounds processed!"
