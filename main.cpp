#include <iostream>

constexpr int arraySize = 3;

void print(char array[arraySize][arraySize]) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            std::cout << array[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

void fillInArray(char array[arraySize][arraySize]) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            array[i][j] = '-';
        }
    }
}

bool checkIfWin(char array[arraySize][arraySize]) {
    for (int i = 0; i < arraySize; ++i) {
        if ((array[i][0] == array[i][1]) && (array[i][1] == array[i][2]) && (array[i][0] != '-'))
            return true;
        else if ((array[0][i] == array[1][i]) && (array[1][i] == array[2][i]) && (array[0][i] != '-'))
            return true;
        else if ((array[0][0] == array[1][1]) && (array[1][1] == array[2][2]) && (array[0][0] != '-'))
            return true;
        else if ((array[2][0] == array[1][1]) && (array[1][1] == array[0][2]) && (array[1][1] != '-'))
            return true;
    }
    return false;
}

bool draw(char array[arraySize][arraySize]) {
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            if (array[i][j] == '-')
                return false;
        }
    }
    return true;
}

bool fieldEmpty(char array[arraySize][arraySize], int row, int column) {
    if (array[row][column] == '-')
        return true;
    else
        return false;
}

char checkMark(int counter) {
    if (counter % 2 == 0)
        return 'X';
    else
        return 'O';
}


void movePossible(char array[arraySize][arraySize], int counter) {

    char mark = checkMark(counter);

    std::cout << "Podaj pole" << std::endl;
    int row{0}, column{0};
    std::cin >> row >> column;

    if (row >= arraySize || column >= arraySize) {
        std::cout << "Nie ma takiego pola. ";
        return movePossible(array, counter);
    } else if (fieldEmpty(array, row, column)) {
        array[row][column] = mark;
    } else {
        std::cout << "Pole zajete. ";
        return movePossible(array, counter);
    }
}


int main() {

    char board[arraySize][arraySize];
    fillInArray(board);
    int counter{0};

    while (!draw(board)) {
        movePossible(board, counter);
        counter++;

        print(board);

        if (checkIfWin(board)) {
            std::cout << "Koniec gry!";
            break;
        }
        else if (draw(board)){
            std::cout << "Koniec gry - remis!";
            break;
        }
    }

    return 0;
}