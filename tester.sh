#!/usr/bin/bash

CUB3D_EXEC=./cub3d
FOLDER_MAPS=$1
TIME_LIMIT=$2
GRN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"
BOLD="\033[1m"
MAP_ARRAY=($(ls $FOLDER_MAPS/*.*))

for i in "${MAP_ARRAY[@]}"
do
    "$CUB3D_EXEC" "$i" > /dev/null 2>&1 &
    EXIT_STATUS=$?
    PID=$!
    sleep $TIME_LIMIT & 
    SLEEP_PID=$!
    wait $PID 2>/dev/null
    if kill -0 $PID 2>/dev/null; then
        kill $PID
        wait $PID 2>/dev/null
        echo -e "${RED}FAIL${NC}: $i ${BOLD}(timeout)${NC}"
    else
        if [ $EXIT_STATUS -eq 0 ]; then
            echo -e "${GRN}PASSED${NC}: $i"
        else
            echo -e "${RED}FAIL${NC}: $i"
        fi
    fi
    kill $SLEEP_PID 2>/dev/null
done
