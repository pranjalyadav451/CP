#!/bin/zsh
emulate -LR zsh
read file_name
g++ -DLOCAL -std=c++17 -o /mnt/e/CP-Repos/CP-March/a.exe `echo "$file_name"`
echo "Input: "
/mnt/e/CP-Repos/CP-March/a.exe
