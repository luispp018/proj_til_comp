#!/bin/bash

# Create an array to store results
declare -A results

# Create directory for XML files if it doesn't exist
mkdir -p xml

# Collect filenames
test_files=$(find ../co24/auto-tests -type f -name '*.til')

# Loop through sorted files
for file in $test_files; do
    # Extract filename without extension
    filename=$(basename -- "$file")
    filename_no_ext="${filename%.*}"

    # Run the command and capture the output
    output=$(./til "$file" -o "xml/${filename_no_ext}.xml" 2>&1)

    # Check if the command was successful
    if [ $? -eq 0 ]; then
        results["$filename"]="PASS"
    else
        results["$filename"]="ERROR"
    fi
done

# Sort the results alphabetically by filename
sorted_results=$(for filename in "${!results[@]}"; do
    echo "$filename - ${results["$filename"]}"
done | sort)

# Print sorted results
echo "$sorted_results"