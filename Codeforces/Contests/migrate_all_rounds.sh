#!/bin/bash

# Base directories
SRC_DIR="/Users/amineoueslati/Desktop/Competitive Programming/Codes/Codeforces/Rated"
DEST_DIR="/Users/amineoueslati/Desktop/competitive-programming/Codeforces/Contests"

# Function to process a regular round
process_div2_round() {
    local round=$1
    local contest_id=$2
    echo "Processing Div2 Round $round (Contest $contest_id)..."
    
    local target_dir="$DEST_DIR/Div2/Round$round"
    mkdir -p "$target_dir"
    
    # Copy and clean files
    find "$SRC_DIR/$round" -name "*.cpp" -exec cp {} "$target_dir/" \;
    clean_cpp_files "$target_dir" "$contest_id" "$round"
}

# Function to process an educational round
process_edu_round() {
    local round=$1
    local contest_id=$2
    echo "Processing Educational Round $round (Contest $contest_id)..."
    
    local target_dir="$DEST_DIR/Educational/Round$round"
    mkdir -p "$target_dir"
    
    # Handle different possible source directory names
    local source_dir
    for dir in "EDU $round" "Edu $round" "edu $round"; do
        if [ -d "$SRC_DIR/$dir" ]; then
            source_dir="$dir"
            break
        fi
    done
    
    # Copy and clean files
    if [ ! -z "$source_dir" ]; then
        find "$SRC_DIR/$source_dir" -name "*.cpp" -exec cp {} "$target_dir/" \;
        clean_cpp_files "$target_dir" "$contest_id" "Edu$round"
    fi
}

# Function to process a global round
process_global_round() {
    local round=$1
    local contest_id=$2
    echo "Processing Global Round $round (Contest $contest_id)..."
    
    local target_dir="$DEST_DIR/Global/Round$round"
    mkdir -p "$target_dir"
    
    # Handle different possible source directory names
    local source_dir
    for dir in "Global $round" "GLOBAL $round" "global $round"; do
        if [ -d "$SRC_DIR/$dir" ]; then
            source_dir="$dir"
            break
        fi
    done
    
    # Copy and clean files
    if [ ! -z "$source_dir" ]; then
        find "$SRC_DIR/$source_dir" -name "*.cpp" -exec cp {} "$target_dir/" \;
        clean_cpp_files "$target_dir" "$contest_id" "Global$round"
    fi
}

# Function to clean cpp files
clean_cpp_files() {
    local dir=$1
    local contest_id=$2
    local prefix=$3
    
    for file in "$dir"/*.cpp; do
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
CF '"$prefix$filename"' - TBD\
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
}

# Process Div2 rounds 651-658
DIV2_ROUNDS=(
    "651:1364"
    "652:1369"
    "653:1374"
    "654:1371"
    "655:1372"
    "656:1385"
    "657:1379"
    "658:1382"
)

# Process Educational rounds
EDU_ROUNDS=(
    "82:1303"
    "84:1327"
    "85:1334"
    "86:1342"
    "89:1366"
    "91:1380"
    "92:1389"
    "93:1398"
    "94:1400"
    "95:1418"
    "96:1430"
    "97:1437"
    "98:1452"
    "100:1463"
    "101:1469"
    "102:1473"
    "104:1487"
    "106:1499"
)

# Process Global rounds
GLOBAL_ROUNDS=(
    "7:1326"
    "9:1375"
    "11:1427"
    "12:1450"
    "13:1491"
    "14:1515"
)

# Process all rounds in parallel
for round_info in "${DIV2_ROUNDS[@]}"; do
    round=$(echo $round_info | cut -d: -f1)
    contest_id=$(echo $round_info | cut -d: -f2)
    process_div2_round "$round" "$contest_id" &
done

for round_info in "${EDU_ROUNDS[@]}"; do
    round=$(echo $round_info | cut -d: -f1)
    contest_id=$(echo $round_info | cut -d: -f2)
    process_edu_round "$round" "$contest_id" &
done

for round_info in "${GLOBAL_ROUNDS[@]}"; do
    round=$(echo $round_info | cut -d: -f1)
    contest_id=$(echo $round_info | cut -d: -f2)
    process_global_round "$round" "$contest_id" &
done

# Wait for all background processes to complete
wait

echo "All rounds processed!"
