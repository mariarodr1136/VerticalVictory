#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;
const int CELL_SIZE = 100;
const int RADIUS = CELL_SIZE / 2 - 5;

enum class Player { None, Player1, Player2 };

class Connect4Game {
public:
    Connect4Game() : board(ROWS, std::vector<Player>(COLS, Player::None)), currentPlayer(Player::Player1), gameOver(false) {}

    void reset() {
        board = std::vector<std::vector<Player>>(ROWS, std::vector<Player>(COLS, Player::None));
        currentPlayer = Player::Player1;
        gameOver = false;
    }

    bool dropPiece(int column) {
        if (gameOver || column < 0 || column >= COLS || board[0][column] != Player::None)
            return false;

        for (int row = ROWS - 1; row >= 0; --row) {
            if (board[row][column] == Player::None) {
                board[row][column] = currentPlayer;
                gameOver = checkWin(row, column);
                if (!gameOver) switchPlayer();
                return true;
            }
        }
        return false;
    }

    Player getCurrentPlayer() const { return currentPlayer; }
    bool isGameOver() const { return gameOver; }
    Player getWinner() const { return currentPlayer; }
    const std::vector<std::vector<Player>>& getBoard() const { return board; }

private:
    std::vector<std::vector<Player>> board;
    Player currentPlayer;
    bool gameOver;

    void switchPlayer() {
        currentPlayer = (currentPlayer == Player::Player1) ? Player::Player2 : Player::Player1;
    }

    bool checkWin(int row, int col) {
        return checkDirection(row, col, 1, 0) || // Horizontal
               checkDirection(row, col, 0, 1) || // Vertical
               checkDirection(row, col, 1, 1) || // Diagonal 
               checkDirection(row, col, 1, -1);  // Diagonal 
    }  

    bool checkDirection(int row, int col, int dRow, int dCol) {
        Player player = board[row][col];
        int count = 1;

        for (int step = 1; step < 4; ++step) {
            int r = row + step * dRow;
            int c = col + step * dCol;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == player) count++;
            else break;
        }
        for (int step = 1; step < 4; ++step) {
            int r = row - step * dRow;
            int c = col - step * dCol;
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == player) count++;
            else break;
        }
        return count >= 4;
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(COLS * CELL_SIZE, ROWS * CELL_SIZE), "Connect 4");
    Connect4Game game;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Could not load font\n";
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !game.isGameOver()) {
                int column = event.mouseButton.x / CELL_SIZE;
                game.dropPiece(column);
            }
        }

        window.clear(sf::Color::Blue);

        // Draw the board
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                sf::CircleShape circle(RADIUS);
                circle.setPosition(col * CELL_SIZE + 5, row * CELL_SIZE + 5);

                if (game.getBoard()[row][col] == Player::Player1)
                    circle.setFillColor(sf::Color::Red);
                else if (game.getBoard()[row][col] == Player::Player2)
                    circle.setFillColor(sf::Color::Yellow);
                else
                    circle.setFillColor(sf::Color::White);

                window.draw(circle);
            }
        }

        if (game.isGameOver()) {
            text.setString("Player " + std::to_string((game.getWinner() == Player::Player1) ? 1 : 2) + " wins! Click to reset.");
            text.setPosition(10, ROWS * CELL_SIZE - 40);

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                game.reset();
            }
        }

        window.draw(text);
        window.display();
    }

    return 0;
}
