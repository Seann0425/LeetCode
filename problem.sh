#!/bin/bash

# Check if name argument is provided
if [ -z "$1" ]; then
  echo "Error: File name is required"
  exit 1
fi

name=$1

# Navigate to the directory
# cd /home/leetcode || exit

# Copy the template file
cp leetcode_template.cpp "$name.cpp"

# Output message
echo "Created file: $name.cpp"

# Open the file with Visual Studio Code
code "$name.cpp"