#include <iostream>
#include <cstdlib>
#include <ctime>

// class to represent coordinates on the grid
class Point2D {
public:
    int x, y;

    // Constructor initializes the coordinates
    Point2D(int x, int y) : x(x), y(y) {}

    // Function to calculate the distance between two points
    int distanceTo(const Point2D& other) const {
        // Simple Euclidean distance (without square root for efficiency)
        return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
    }
};


// Entry point of the program
int main() {
    // Initialize random seed
    srand(time(0));

    // Setup game parameters
    int width = 30; //width
    int height = 30; // height

    // Create game arena
    // Arena arena(width, height);

    // Start the game
   //arena.startGame();

    return 0;
}
