#!/bin/zsh
emulate -LR zsh
echo "Are You Sure ??"
echo "-------------------"
read inp
if [ "$inp" = 'yes' ] || [ "$inp" = 'y' ]
then
	echo "-------------------"
	echo "Deleting .cpp__tests and .exe files !!" 
	find . -name "*.cpp__tests" -type f -delete
	find . -name "*.exe" -type f -delete
else 
	echo "-------------------"
    echo "Exit without deleting"
fi 


