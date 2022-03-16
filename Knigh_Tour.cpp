#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool knight_tour(vector<vector<int>> &board, int size_of_chess_board, int row, int column, int count_of_moves = 1)
{
    if (row < 0 || column < 0 || row >= size_of_chess_board || column >= size_of_chess_board || board[row][column])
        return false;
    
    board[row][column] = count_of_moves;
    if (count_of_moves / size_of_chess_board == size_of_chess_board)
        return true;
    if (knight_tour(board, size_of_chess_board, row - 1, column - 2, count_of_moves + 1))
        return true;
    if (knight_tour(board, size_of_chess_board, row - 2, column - 1, count_of_moves + 1))
        return true;
    if (knight_tour(board, size_of_chess_board, row - 2, column + 1, count_of_moves + 1))
        return true;
    if (knight_tour(board, size_of_chess_board, row - 1, column + 2, count_of_moves + 1))
        return true;
    if (knight_tour(board, size_of_chess_board, row + 1, column + 2, count_of_moves + 1))
        return true;
    if (knight_tour(board, size_of_chess_board, row + 2, column + 1, count_of_moves + 1))
        return true;
    if (knight_tour(board, size_of_chess_board, row + 2, column - 1, count_of_moves + 1))
        return true;
    if (knight_tour(board, size_of_chess_board, row + 1, column - 2, count_of_moves + 1))
        return true;
    board[row][column] = 0;
    return false;
}

int main(void)
{
    int size_of_chess_board;
    cout << "Enter the size of the chess board: ";
    cin >> size_of_chess_board;
    int row, column;
    cout << "Enter the position of the knight in the chess board (row, column): ";
    cin >> row >> column;
    vector<vector<int>> board(size_of_chess_board, vector<int>(size_of_chess_board, 0));
    cout << boolalpha << "Knight Tour Result: " << knight_tour(board, size_of_chess_board, row, column) << '\n';
    cout << "Path followed by Knight\n";

    // Getting the number of digits in maximum move
    unsigned long long int number = 1LL * size_of_chess_board * size_of_chess_board, digits = 0;
    while (number)
    {
        digits++;
        number /= 10;
    }

    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board[i].size(); j++)
        {
            cout << setw(digits) << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}