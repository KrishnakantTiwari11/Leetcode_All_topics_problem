/**
 * @param {number} n
 * @return {string[][]}
 */

var solveNQueens = function(n) {
    const res = [];
    const board = Array.from({ length: n }, () => Array(n).fill('.'));
    const rowConfig = new Array(n).fill(0);

    function isSafe(row, col) {
        if (rowConfig[row]) return false;

        let i = row, j = col;

        // upper-left diagonal
        while (i >= 0 && j >= 0) {
            if (board[i][j] === 'Q') return false;
            i--; j--;
        }

        // lower-left diagonal
        i = row; j = col;
        while (i < n && j >= 0) {
            if (board[i][j] === 'Q') return false;
            i++; j--;
        }

        return true;
    }

    function solve(col) {
        if (col === n) {
            const temp = board.map(row => row.join(''));
            res.push(temp);
            return;
        }

        for (let i = 0; i < n; i++) {
            if (isSafe(i, col)) {
                rowConfig[i] = 1;
                board[i][col] = 'Q';

                solve(col + 1);

                board[i][col] = '.';
                rowConfig[i] = 0;
            }
        }
    }

    solve(0);
    return res;
};