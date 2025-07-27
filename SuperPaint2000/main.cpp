#include "cWindowManager.h"

int main() {
    cWindowManager* Window = new cWindowManager("Super Paint 2000!");

    while (Window->Process());

    // Memory Cleanup
    delete(Window);
    Window = nullptr;


    

    
}