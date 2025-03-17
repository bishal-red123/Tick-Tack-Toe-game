#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>

using namespace sf;
using namespace std;

const int SIZE = 3;
const int CELL_SIZE = 200;
char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char current_marker = 'X';
int current_player = 1;

int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return current_player;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return current_player;
    return 0;
}

bool placeMarker(int row, int col) {
    if (board[row][col] != ' ') return false;
    board[row][col] = current_marker;
    return true;
}

void swapPlayer() {
    current_marker = (current_marker == 'X') ? 'O' : 'X';
    current_player = (current_player == 1) ? 2 : 1;
}

int main() {
    RenderWindow window(VideoMode(Vector2u(600, 600)), "Tic-Tac-Toe");
    Font font;
    if (!font.openFromFile("arial.ttf")) {
        cerr << "Failed to load font!" << endl;
        return -1;
    }

    Text text(font);  // ✅ SFML 3.0 requires a font reference
    text.setString(" ");
    text.setCharacterSize(50);
    text.setFillColor(Color::White);
    
    

    int winner = 0, moves = 0;

    while (window.isOpen()) {
        std::optional<Event> event = window.pollEvent();
        while (event.has_value()) {
            if (event->is<Event::Closed>()) 
                window.close();

            if (event->is<Event::MouseButtonPressed>() && winner == 0) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int row = mousePos.y / CELL_SIZE;
                int col = mousePos.x / CELL_SIZE;

                if (placeMarker(row, col)) {
                    moves++;
                    winner = checkWin();
                    if (winner == 0 && moves < 9) swapPlayer();
                }
            }
            event = window.pollEvent();
        }

        window.clear(Color::Black);

        for (int i = 1; i < SIZE; i++) {
            RectangleShape line(Vector2f(600.f, 5.f));
            line.setFillColor(Color::White);
            line.setPosition(Vector2f(0.f, i * CELL_SIZE));
            window.draw(line);

            line.setSize(Vector2f(5.f, 600.f));
            line.setPosition(Vector2f(i * CELL_SIZE, 0.f));
            window.draw(line);
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != ' ') {
                    text.setString(board[i][j]);
                    text.setPosition(Vector2f(j * CELL_SIZE + 75.f, i * CELL_SIZE + 50.f));
        
                    // Set color: Neon Blue for 'X', Neon Red for 'O'
                    if (board[i][j] == 'X') {
                        text.setFillColor(Color(0, 255, 255));  // Neon Blue (Cyan)
                    } else {
                        text.setFillColor(Color(255, 0, 102));  // Neon Red (Pinkish Red)
                    }
        
                    window.draw(text);
                }
            }
        }
        
        if (winner != 0 || moves == 9) {
            window.clear(Color::Black);  // ✅ Black background for popup
        
            string result = (winner != 0) ? "Player " + to_string(winner) + " Wins!" : "It's a Tie!";
            text.setString(result);
            text.setCharacterSize(60);
            
            text.setFillColor(Color(0, 255, 0));  // ✅ Neon Green text
            
            text.setPosition(Vector2f(100.f, 250.f));  // ✅ Shifted left
        
            window.draw(text);
            window.display();
        
            sf::sleep(sf::seconds(3));  // ✅ Hold popup for 3 sec before closing
            window.close();
        }
        
        

        window.display();
    }

    return 0;
}