#include "cWindowManager.h"

int main() {
    // Window Manager
    cWindowManager* Window = new cWindowManager("Super Paint 2000!");

    // Process
    Window->Process();

    // Memory Cleanup
    delete(Window);
    Window = nullptr;
}