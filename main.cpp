#include "CTable.h"
#include "CPlayer.h"
#include <iostream>
#include <limits>
#include <algorithm>

// Function to display the current player's hand
void displayPlayerHand(const CPlayer& player) {
    std::cout << "Player's Hand: ";
    for (std::size_t i = 0; i < player.getHandSize(); ++i) {
        std::cout << "[" << player.getDomino(i).getSide1() << "|" << player.getDomino(i).getSide2() << "] ";
    }
    std::cout << std::endl;
}

// Function to check if a domino can be placed on the table
bool canPlaceDomino(const CDomino& domino, const CTable& table) {
    return (domino.getSide1() == table.getHead() || domino.getSide1() == table.getTail() ||
            domino.getSide2() == table.getHead() || domino.getSide2() == table.getTail());
}

// Function to place the first piece on the table
void placeFirstPiece(CTable& table, const CDomino& firstPiece) {
    table.placeDomino(firstPiece);
    std::cout << "First piece played on the table: ";
    firstPiece.display();
    std::cout << std::endl;
}

int main() {
    // Initialize the table
    CTable table;

    // Initialize two players
    CPlayer player1;
    CPlayer player2;

    // Randomly distribute dominoes to players
    for (int i = 0; i < 10; ++i) {
        player1.addDomino(table.drawPiece());
        player2.addDomino(table.drawPiece());
    }

    // Randomly select which player goes first
    bool isPlayer1Turn = (rand() % 2 == 0);

    // Draw and place the first piece on the table
    CDomino firstPiece = table.drawPiece();
    placeFirstPiece(table, firstPiece);

    // Game loop: players take turns
    while (true) {
        // Display current state of the table including head and tail
        table.displayTable(); // This now includes head and tail values.

        if (isPlayer1Turn) {
            std::cout << "Player 1's turn." << std::endl;
            displayPlayerHand(player1);
            std::string choiceStr; // Use a string to handle the input

            // Allow player to choose a domino to play or draw
            std::cout << "Choose a domino index to play (0 to " << player1.getHandSize() - 1 << ") (press enter to draw): ";
            std::getline(std::cin, choiceStr); // Get input from player

            // Check if the player wants to draw
            if (choiceStr.empty()) {
                // Attempt to draw from available pieces
                if (table.isAvailable()) {
                    CDomino drawnDomino = table.drawPiece(); // Draw a piece
                    player1.addDomino(drawnDomino); // Add drawn piece to player's hand
                    std::cout << "Player 1 drew a piece: ";
                    drawnDomino.display();

                    // Check if they can now play the drawn piece
                    if (canPlaceDomino(drawnDomino, table)) {
                        table.placeDomino(drawnDomino);
                        player1.removeDomino(player1.getHandSize() - 1); // Remove the drawn piece
                        std::cout << "Player 1 played the drawn piece: ";
                        drawnDomino.display();
                    } else {
                        std::cout << "Player 1 still cannot play after drawing." << std::endl;
                    }
                } else {
                    std::cout << "No available pieces left to draw." << std::endl;
                }
            } else {
                // Convert choiceStr to an integer
                int choice = std::stoi(choiceStr);

                // Get the selected domino
                if (choice >= 0 && choice < player1.getHandSize()) {
                    CDomino p1Domino = player1.getDomino(choice);

                    // Check if the domino can be placed
                    if (canPlaceDomino(p1Domino, table)) {
                        table.placeDomino(p1Domino);
                        player1.removeDomino(choice);
                        std::cout << "Player 1 played: ";
                        p1Domino.display();
                    } else {
                        std::cout << "Player 1 cannot play this domino." << std::endl;
                        // Allow to draw if they cannot play
                        std::cout << "Press enter to draw a piece." << std::endl;
                        std::getline(std::cin, choiceStr); // Wait for player to press enter

                        // Attempt to draw from available pieces
                        if (table.isAvailable()) {
                            CDomino drawnDomino = table.drawPiece(); // Draw a piece
                            player1.addDomino(drawnDomino); // Add drawn piece to player's hand
                            std::cout << "Player 1 drew a piece: ";
                            drawnDomino.display();

                            // Check if they can now play the drawn piece
                            if (canPlaceDomino(drawnDomino, table)) {
                                table.placeDomino(drawnDomino);
                                player1.removeDomino(player1.getHandSize() - 1); // Remove the drawn piece
                                std::cout << "Player 1 played the drawn piece: ";
                                drawnDomino.display();
                            } else {
                                std::cout << "Player 1 still cannot play after drawing." << std::endl;
                            }
                        } else {
                            std::cout << "No available pieces left to draw." << std::endl;
                        }
                    }
                } else {
                    std::cout << "Invalid choice! Please enter a valid index." << std::endl;
                }
            }

            // Check if Player 1 has won
            if (player1.hasNoDominoes()) {
                std::cout << "Player 1 wins!" << std::endl;
                std::cout << "Player 2 has " << player2.getHandSize() << " pieces left: ";
                displayPlayerHand(player2); // Display the pieces left with Player 2
                break;
            }
        } else {
            std::cout << "Player 2's turn." << std::endl;
            displayPlayerHand(player2);
            std::string choiceStr; // Use a string to handle the input

            // Allow player to choose a domino to play or draw
            std::cout << "Choose a domino index to play (0 to " << player2.getHandSize() - 1 << ") (press enter to draw): ";
            std::getline(std::cin, choiceStr); // Get input from player

            // Check if the player wants to draw
            if (choiceStr.empty()) {
                // Attempt to draw from available pieces
                if (table.isAvailable()) {
                    CDomino drawnDomino = table.drawPiece(); // Draw a piece
                    player2.addDomino(drawnDomino); // Add drawn piece to player's hand
                    std::cout << "Player 2 drew a piece: ";
                    drawnDomino.display();

                    // Check if they can now play the drawn piece
                    if (canPlaceDomino(drawnDomino, table)) {
                        table.placeDomino(drawnDomino);
                        player2.removeDomino(player2.getHandSize() - 1); // Remove the drawn piece
                        std::cout << "Player 2 played the drawn piece: ";
                        drawnDomino.display();
                    } else {
                        std::cout << "Player 2 still cannot play after drawing." << std::endl;
                    }
                } else {
                    std::cout << "No available pieces left to draw." << std::endl;
                }
            } else {
                // Convert choiceStr to an integer
                int choice = std::stoi(choiceStr);

                // Get the selected domino
                if (choice >= 0 && choice < player2.getHandSize()) {
                    CDomino p2Domino = player2.getDomino(choice);

                    // Check if the domino can be placed
                    if (canPlaceDomino(p2Domino, table)) {
                        table.placeDomino(p2Domino);
                        player2.removeDomino(choice);
                        std::cout << "Player 2 played: ";
                        p2Domino.display();
                    } else {
                        std::cout << "Player 2 cannot play this domino." << std::endl;
                        // Allow to draw if they cannot play
                        std::cout << "Press enter to draw a piece." << std::endl;
                        std::getline(std::cin, choiceStr); // Wait for player to press enter

                        // Attempt to draw from available pieces
                        if (table.isAvailable()) {
                            CDomino drawnDomino = table.drawPiece(); // Draw a piece
                            player2.addDomino(drawnDomino); // Add drawn piece to player's hand
                            std::cout << "Player 2 drew a piece: ";
                            drawnDomino.display();

                            // Check if they can now play the drawn piece
                            if (canPlaceDomino(drawnDomino, table)) {
                                table.placeDomino(drawnDomino);
                                player2.removeDomino(player2.getHandSize() - 1); // Remove the drawn piece
                                std::cout << "Player 2 played the drawn piece: ";
                                drawnDomino.display();
                            } else {
                                std::cout << "Player 2 still cannot play after drawing." << std::endl;
                            }
                        } else {
                            std::cout << "No available pieces left to draw." << std::endl;
                        }
                    }
                } else {
                    std::cout << "Invalid choice! Please enter a valid index." << std::endl;
                }
            }

            // Check if Player 2 has won
            if (player2.hasNoDominoes()) {
                std::cout << "Player 2 wins!" << std::endl;
                std::cout << "Player 1 has " << player1.getHandSize() << " pieces left: ";
                displayPlayerHand(player1); // Display the pieces left with Player 1
                break;
            }
        }

        // Switch turns
        isPlayer1Turn = !isPlayer1Turn;
    }

    return 0;
}