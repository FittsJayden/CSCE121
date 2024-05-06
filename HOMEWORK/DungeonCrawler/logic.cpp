#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    char line;
    ifstream ifs(fileName);
    if (!ifs.is_open()) {
        char** ptr = nullptr;
        return ptr;
    }

    ifs >> maxRow >> maxCol;
    ifs >> player.row >> player.col;

    if (INT32_MAX / maxRow < maxCol || INT32_MAX / maxCol < maxRow) {
        char** ptr = nullptr;
        return ptr;
    }


    char** ptr = createMap(maxRow, maxCol);

    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            ifs >> std::ws;
            ifs >> line;
            ptr[i][j] = line;
        }
    }

    if (ifs.fail()) {
        return nullptr;
    }
    ptr[player.row][player.col] = TILE_PLAYER;



    return ptr;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    switch (input)
    {
    case MOVE_UP:
        nextRow -= 1;
        break;
    
    case MOVE_LEFT:
        nextCol -= 1;
        break;

    case MOVE_DOWN:
        nextRow += 1;
        break;

    case MOVE_RIGHT:
        nextCol += 1;
        break;
    }
    
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    char** ptr = new char*[maxRow];
    for (int i = 0; i < maxRow; i++) {
        ptr[i] = new char[maxCol];
        for (int j = 0; j < maxCol; j++) {
            ptr[i][j] = TILE_OPEN;
        }
    }

    return ptr;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    for (int i = 0; i < maxRow; i++) {
        delete [] map[i];
    }
    delete [] map;
    maxRow = 0;
    map = nullptr;
    
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    int newMaxRow = 2 * maxRow;
    int newMaxCol = 2 * maxCol;
    char** newMap = createMap(newMaxRow, newMaxCol);

    if (INT32_MAX / newMaxRow < newMaxCol || INT32_MAX / newMaxCol < newMaxRow) {
        newMap = nullptr;
        return newMap;
    }

    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            if (map[i][j] == TILE_PLAYER) {
                newMap[i][j] = map[i][j];
            }
            else {
                newMap[i][j] = map[i][j];
                newMap[i + maxRow][j] = map[i][j];
                newMap[i][j + maxCol] = map[i][j];
                newMap[i + maxRow][j + maxCol] = map[i][j];
            }
        }
    }


    deleteMap(map, maxRow);
    maxRow = newMaxRow;
    maxCol = newMaxCol;
    return newMap;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    int status = STATUS_STAY;

    if (player.col != nextCol) {
        if (nextCol < 0 || nextCol >= maxCol) {
            return STATUS_STAY;
        }

    }
    else if (player.row != nextRow) {
        if (nextRow < 0 || nextRow >= maxRow) {
            return STATUS_STAY;
        }
    }


    switch (map[nextRow][nextCol])
    {
    case TILE_PILLAR:
    
    case TILE_MONSTER:
        status = STATUS_STAY;
        break;

    case TILE_EXIT:
        if (player.treasure >= 1) {
            status = STATUS_ESCAPE;
        }
        else {
            status = STATUS_STAY;
        }
        break;

    case TILE_DOOR:
        status = STATUS_LEAVE;
        break;
    
    case TILE_TREASURE:
        player.treasure += 1;
        status = STATUS_TREASURE;
        break;
    
    case TILE_AMULET:
        status = STATUS_AMULET;
        break;
    
    case TILE_OPEN:
        status = STATUS_MOVE;
        break;
    }

    if (status != STATUS_STAY) {
        map[player.row][player.col] = TILE_OPEN;
        player.col = nextCol;
        player.row = nextRow;
        map[player.row][player.col] = TILE_PLAYER;
    }
    return status;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    //check above
    for (int i = player.row + 1; i < maxRow; i++) { 
        if (map[i][player.col] == TILE_PILLAR) {
            break;
        }
        else if (map[i][player.col] == TILE_MONSTER) {
            map[i][player.col] = TILE_OPEN;
            map[i - 1][player.col] = TILE_MONSTER;
        }

    }
    for (int i = player.row - 1; i >= 0; i--) {
        if (map[i][player.col] == TILE_PILLAR) {
            break;
        }
        else if (map[i][player.col] == TILE_MONSTER) {
            map[i][player.col] = TILE_OPEN;
            map[i + 1][player.col] = TILE_MONSTER;
        }
    }
    for (int i = player.col + 1; i < maxCol; i++) {
        if (map[player.row][i] == TILE_PILLAR) {
            break;
        }
        else if (map[player.row][i] == TILE_MONSTER) {
            map[player.row][i] = TILE_OPEN;
            map[player.row][i - 1] = TILE_MONSTER;
        }
    }
    for (int i = player.col - 1; i >= 0; i--) {
        if (map[player.row][i] == TILE_PILLAR) {
            break;
        }
        else if (map[player.row][i] == TILE_MONSTER) {
            map[player.row][i] = TILE_OPEN;
            map[player.row][i + 1] = TILE_MONSTER;
        }
    }
    if (map[player.row][player.col] == TILE_MONSTER) {
        return true;
    }

    return false;

}
