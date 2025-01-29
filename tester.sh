#!/usr/bin/bash

exec 2>/dev/null

FOLDER_MAPS=$1
TIME_LIMIT=$2
RED="\033[0;31m"
GRN="\033[0;32m"
BYEL="\033[1;33m"
BBLU="\033[1;34m"
NC="\033[0m"
mapfile -t MAP_ARRAY < <(ls "$FOLDER_MAPS"*.cub)

VERSION=$3
LOG_FILE="tester.log"
make
if [ $? -ne 0 ]; then
	echo -e "${RED}Erreur: La compilation a échoué.${NC}"
	exit 1
fi

if [ "$VERSION" = "bonus" ]; then
	make bonus
	if [ $? -ne 0 ]; then
		echo -e "${RED}Erreur: La compilation a échoué.${NC}"
		exit 1
	fi
    CUB3D_EXEC="./cub3D_bonus"
else
    CUB3D_EXEC="./cub3D"
fi

if [ ! -f "$CUB3D_EXEC" ]; then
    echo -e "${RED}Erreur: L'exécutable $CUB3D_EXEC n'existe pas.${NC}"
    exit 1
fi

if [ -z "$FOLDER_MAPS" ] || [ -z "$TIME_LIMIT" ]; then
    echo -e "${RED}Usage: $0 <FOLDER_MAPS> <TIME_LIMIT> [bonus]${NC}"
    echo "Arguments:"
    echo "  FOLDER_MAPS  : chemin du dossier contenant les fichiers de carte"
    echo "  TIME_LIMIT   : limite de temps pour exécuter chaque carte (en secondes)"
    echo "  VERSION      : bonus (optionnel)"
    exit 1
fi
>"$LOG_FILE"

TEST_NUM=1
for i in "${MAP_ARRAY[@]}"; do
    COLS=$(tput cols)
    printf "Test #%03d : %s" $TEST_NUM "$i"

    (timeout -s KILL "$TIME_LIMIT" "$CUB3D_EXEC" "$i") &>/tmp/_tmp_output
    EXIT_STATUS=$?

    printf "\nTest #%03d : %s\n" $TEST_NUM "$i" >>"$LOG_FILE"
    cat /tmp/_tmp_output >>"$LOG_FILE"
    rm -f /tmp/_tmp_output

    if [ $EXIT_STATUS -eq 137 ]; then
        RESULT="${BBLU}VALID${NC}"
    elif [ $EXIT_STATUS -eq 139 ]; then
        RESULT="${RED}SEGFAULT${NC}"
    elif [ $EXIT_STATUS -eq 1 ]; then
        RESULT="${RED}MLX_ERROR${NC}"
    elif [ $EXIT_STATUS -eq 0 ]; then
        RESULT="${BBLU}VALID${NC}"
    else
        RESULT="${BYEL}NO_VALID${NC}"
    fi

    printf " : %d" $EXIT_STATUS
    SPACES=$((COLS - ${#i} - ${#RESULT} - ${#EXIT_STATUS}- 15))
    [ $SPACES -lt 1 ] && SPACES=1
    printf "%${SPACES}s" ""
    echo -e "$RESULT"

    ((TEST_NUM++))
done
echo -e "${GRN}DONE${NC}"
