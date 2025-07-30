#include "cWindowManager.h"

int main() {
    // Managers

    cWindowManager* WindowManager = new cWindowManager(sf::VideoMode({ 1200, 900 }), "Super Paint 2000!");

    // Process
    WindowManager->Process();

    // Memory Cleanup
    delete(WindowManager);
}