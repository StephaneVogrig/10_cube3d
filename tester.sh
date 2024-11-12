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

if [ -z "$FOLDER_MAPS" ] || [ -z "$TIME_LIMIT" ]; then
    echo -e "${RED}Usage: $0 <FOLDER_MAPS> <TIME_LIMIT>${NC}"
    echo "Arguments:"
    echo "  FOLDER_MAPS  : chemin du dossier contenant les fichiers de carte"
    echo "  TIME_LIMIT   : limite de temps pour exécuter chaque carte (en secondes)"
    exit 1
fi

for i in "${MAP_ARRAY[@]}"
do
    echo -n -e "$i\t:\t"
    
    timeout -s KILL "$TIME_LIMIT" "$CUB3D_EXEC" "$i" > /dev/null 2>&1
    disown -h
    EXIT_STATUS=$?

    if [ $EXIT_STATUS -eq 137 ]; then 
        echo -e "${RED}TIMEOUT${NC}"
    elif [ $EXIT_STATUS -eq 139 ]; then
        echo -e "${RED}SEGFAULT${NC}"
    elif [ $EXIT_STATUS -eq 1 ]; then
        echo -e "${RED}MLX_ERROR${NC}"
    elif [ $EXIT_STATUS -eq 0 ]; then
        echo -e "${BBLU}VALID${NC}"
    elif [ $EXIT_STATUS -gt 255 ]; then
        echo -e "${BYEL}NO_VALID${NC}"
    fi
done

echo -e "${GRN}DONE${NC}"