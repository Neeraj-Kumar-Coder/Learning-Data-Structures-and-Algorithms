#include <iostream>
#include <vector>

using namespace std;

class N_Queen
{
private:
    vector<int> _left_diagonal;
    vector<int> _right_diagonal;
    vector<int> _verticle;
    vector<vector<int>> _board;
    int _size_of_board;
    bool solveUtil(int _row = 0)
    {
        if (_row == _size_of_board)
            return true;

        for (int _i = 0; _i < _size_of_board; _i++)
        {
            if (_left_diagonal[_row - _i + _size_of_board - 1] || _right_diagonal[_row + _i] || _verticle[_i])
                continue;
            _board[_row][_i] = _left_diagonal[_row - _i + _size_of_board - 1] = _right_diagonal[_row + _i] = _verticle[_i] = 1;
            if (solveUtil(_row + 1))
                return true;
            _board[_row][_i] = _left_diagonal[_row - _i + _size_of_board - 1] = _right_diagonal[_row + _i] = _verticle[_i] = 0;
        }
        return false;
    }

public:
    /**
     * @brief Default constructor for an ordinary chess board (8 x 8)
     **/
    N_Queen(void) : N_Queen(8) {}
    /**
     * @brief Constructor for the N_Queen class
     * @param _size_of_board The size of the chess board
     **/
    N_Queen(int _size_of_board) : _size_of_board(_size_of_board)
    {
        _board = vector<vector<int>>(_size_of_board, vector<int>(_size_of_board, 0));
        _left_diagonal = vector<int>(2 * _size_of_board - 1, 0);
        _right_diagonal = vector<int>(2 * _size_of_board - 1, 0);
        _verticle = vector<int>(_size_of_board, 0);
    }
    /**
     * @brief Solver for the N Queen problem
     * @return Returns true if the board is solved else false
     **/
    bool solve(void)
    {
        return solveUtil();
    }
    /**
     * @return Returns the board
     **/
    vector<vector<int>> get_board(void)
    {
        return _board;
    }
};

int main(void)
{
    N_Queen obj;
    if (!obj.solve())
        cout << "The problem cannot be solved!\n";
    else
    {
        vector<vector<int>> answer = obj.get_board();
        for (auto &&i : answer)
        {
            for (auto &&x : i)
            {
                if (x)
                    cout << 'Q' << ' ';
                else
                    cout << '-' << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}