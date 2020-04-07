#include <iostream>
#include <stack>
#include <vector>

enum GridType {
    EMPTY = 0,
    VISITED = 1,
    OBSTACLE = 2,
};

struct Move {
    int row;
    int col;
};

struct Robot {
    int cur_row;
    int cur_col;
    std::stack<Move> moves;

    Robot() {
        this->cur_row = 0;
        this->cur_col = 0;
        Move m = Move{0, 0};
        this->moves.push(m);
    }
};

struct Grid {
    int row_n;
    int col_n;
    std::vector <std::vector<GridType>> G;
    Robot robot;

    Grid(int row_n, int col_n, Robot r) {
        this->row_n = row_n;
        this->col_n = col_n;
        this->G.assign(row_n, std::vector<GridType>(col_n, EMPTY));
        this->robot = r;
    }

    bool moveRobotRec() {
        int cur_r = this->robot.cur_row;
        int cur_c = this->robot.cur_col;

        if (!canMove()) {
            if (isGoal()) {
                // Goal
                Move last_move = Move{cur_r, cur_c};
                this->robot.moves.push(last_move);
                return true;
            } else {
                // no next move, so must pop move.
                return false;
            }
        }
        
        if (canMoveRight()) {
            Move m = Move{cur_r, cur_c + 1};
            this->robot.cur_col += 1;
            this->robot.moves.push(m);
            if (moveRobotRec()) {
                return true;
            }
            this->robot.moves.pop();
            this->robot.cur_col -= 1;
        }
        if (canMoveDown()) {
            Move m = Move{cur_r + 1, cur_c};
            this->robot.cur_row += 1;
            this->robot.moves.push(m);
            if (moveRobotRec()) {
                return true;
            }
            this->robot.moves.pop();
            this->robot.cur_row -= 1;
        }

        return false;
    }

    bool isGoal() {
        return (this->robot.cur_row + 1 == this->row_n) && (this->robot.cur_col + 1 == this->col_n);
    }

    bool canMove() {
        int cur_row = this->robot.cur_row;
        int cur_col = this->robot.cur_col;

        if (cur_row + 1 == this->row_n) { return false; }
        if (this->G[cur_row + 1][cur_col] == EMPTY) { return true; }

        if (cur_col + 1 == this->col_n) { return false; }
        if (this->G[cur_row][cur_col + 1] == EMPTY) { return true; }

        return false;
    }

    bool canMoveRight() {
        int cur_row = this->robot.cur_row;
        int cur_col = this->robot.cur_col;

        if (cur_col + 1 == this->col_n) { return false; }
        return this->G[cur_row][cur_col + 1] == EMPTY;
    }

    bool canMoveDown() {
        int cur_row = this->robot.cur_row;
        int cur_col = this->robot.cur_col;

        if (cur_row + 1 == this->row_n) { return false; }
        return this->G[cur_row + 1][cur_col] == EMPTY;
    }

    void moveRobot() {
        if (moveRobotRec()) {
            // print succeed path
            std::cout << "FOUND PATH" << std::endl;

            while(!this->robot.moves.empty()) {
                Move m = this->robot.moves.top();
                this->robot.moves.pop();
                this->G[m.row][m.col] = VISITED;
            }
        } else {
            std::cout << "FOUND PATH" << std::endl;
        }
    }

    void setObstacke(int r, int c) {
        this->G[r][c] = OBSTACLE;
    }

    void print() {
        for (int i = 0; i < this->row_n; i++) {
            for (int j = 0; j < this->col_n; j++) {
                std::cout << "+--";
            }
            std::cout << "+" << std::endl;
            for (int j = 0; j < this->col_n; j++) {
                printEachCell(i, j);
            }
            std::cout << "|" << std::endl;
        }
        for (int j = 0; j < this->col_n; j++) {
            std::cout << "+--";
        }
        std::cout << "+" << std::endl;
    }

private:
    void printEachCell(int r, int c) {
        GridType t = this->G[r][c];
        if (t == EMPTY) {
            std::cout << "|  ";
        } else if (t == VISITED) {
            std::cout << "|👌";
        } else if (t == OBSTACLE) {
            std::cout << "|💩";
        }
    }
};

int main() {
    Robot r = Robot();

    Grid G = Grid(10, 15, r);
    G.setObstacke(0, 11);
    G.setObstacke(1, 1);
    G.setObstacke(1, 10);
    G.setObstacke(2, 5);

    G.moveRobot();

    G.print();
}
