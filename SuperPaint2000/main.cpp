#include "cWindow.h"

int main() {
    // Window
    cWindow* Window = new cWindow("Super Paint 2000!");

    // Process
    Window->Process();

    // Memory Cleanup
    delete(Window);
    Window = nullptr;
}