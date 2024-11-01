#!/usr/bin/bash

CUB3D_EXEC=./cub3d
FOLDER_MAPS=$1
TIME_LIMIT=$2
RED="\033[0;31m"
GRN="\033[0;32m"
BYEL="\033[1;33m"
BBLU="\033[1;34m"
NC="\033[0m"
MAP_ARRAY=($(ls $FOLDER_MAPS/*.*))

for i in "${MAP_ARRAY[@]}"
do
    echo -n -e "$i\t:\t"
    
    timeout -s KILL $TIME_LIMIT "$CUB3D_EXEC" "$i" > /dev/null 2>&1
    EXIT_STATUS=$?

    if [ $EXIT_STATUS -eq 137 ]; then 
        echo -e "${RED}TIMEOUT${NC}"
    elif [ $EXIT_STATUS -eq 0 ]; then
        echo -e "${BBLU}VALID${NC}"
    else
        echo -e "${BYEL}NO_VALID${NC}"
    fi
done

echo -e "${GRN}DONE${NC}"