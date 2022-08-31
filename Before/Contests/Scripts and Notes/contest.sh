#!/bin/zsh
emulate -LR zsh

cd /mnt/e/CP-Repos/Contests
echo "Moved to -> `pwd`"
echo "-------------------------------------------------"
# clearing the input and output files
echo "Cleared the input and output files "
echo -n "" > inputf.in 
echo -n "" > outputf.in
echo "-------------------------------------------------"

# This script is mainly for codeforces contests
# I might extend it for other contests too
# moving to codeforces folder
echo "Moving to CodeForces"
cd CodeForces
echo "-------------------------------------------------"

echo "Name of the Round and Div ? "
read nameof div
# making the final name of the contest folder
final_name="Round_${nameof}_Div_${div}"
mkdir $final_name && cd $final_name
# creating three files in the hope that I can solve upto C
touch A.cpp B.cpp C.cpp Notes.md
echo "## \``date`\`" > Notes.md

echo "\nDo you want to delete the last folder ?"
read response
if [ "$response" = 'yes' ] || [ "$response" = 'y' ]
then
	echo "-------------------------------------------------"
	cd .. && rm -rfv "$final_name"
else 
	echo "-------------------------------------------------"
    echo "Exit without deleting"
fi