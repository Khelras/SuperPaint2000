#include "cFileInterface.h"

cFileInterface::cFileInterface(cToolManager* _toolManager, sf::Vector2f _size, std::string _text) : cButton(_size) {
    this->m_ToolManager = _toolManager;

    // Text
    if (this->m_Font.openFromFile("fonts/arial.ttf") == false) printf("ERR: Unable to Load Font!\n"); // FOR DEBUGGING
    this->m_Text = new sf::Text(this->m_Font);
    this->m_Text->setString(_text);
    this->m_Text->setFillColor(sf::Color::Black);
    this->m_Text->setOrigin(this->m_Text->getGlobalBounds().getCenter());
}

cFileInterface::~cFileInterface() {
    delete(this->m_Text);
}

void cFileInterface::LoadFile(cWindowManager* _window, cCanvas* _canvas) {
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    if (SUCCEEDED(hr)) {
        IFileOpenDialog* pFileOpen;

        // Create the FileOpenDialog object.
        hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

        if (SUCCEEDED(hr)) {
            // Show the Open dialog box.
            hr = pFileOpen->Show(NULL);

            // Get the file name from the dialog box.
            if (SUCCEEDED(hr)) {
                IShellItem* pItem;
                hr = pFileOpen->GetResult(&pItem);
                if (SUCCEEDED(hr)) {
                    PWSTR pszFilePath;
                    hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

                    // Display the file name to the user.
                    if (SUCCEEDED(hr)) {
                        sf::Texture newTex(pszFilePath);
                        _window->ImportImage(newTex, _canvas); // Imports Image onto Canvas

                        MessageBoxW(NULL, L"Image Loaded successfully.", L"Success!", MB_OK);
                        CoTaskMemFree(pszFilePath);
                    }

                    pItem->Release();
                }
            }
            pFileOpen->Release();
        }
        CoUninitialize();
    }
}

void cFileInterface::SaveFile(sf::RenderTexture* _canvasTexture) {
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);

    if (SUCCEEDED(hr)) {
        IFileSaveDialog* pFileSave;

        // Create the FileOpenDialog object.
        hr = CoCreateInstance(CLSID_FileSaveDialog, NULL, CLSCTX_ALL, IID_IFileSaveDialog, reinterpret_cast<void**>(&pFileSave));

        if (SUCCEEDED(hr)) {
            // Show the Save dialog box.
            hr = pFileSave->Show(NULL);

            // Get the file name from the dialog box.
            if (SUCCEEDED(hr)) {
                IShellItem* pItem;
                hr = pFileSave->GetResult(&pItem);
                if (SUCCEEDED(hr)) {
                    PWSTR pszFilePath;
                    hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

                    // Display the file name to the user.
                    if (SUCCEEDED(hr)) {
                        if (_canvasTexture->getTexture().copyToImage().saveToFile(pszFilePath)) {
                            MessageBoxW(NULL, pszFilePath, L"Saved to: ", MB_OK);
                            CoTaskMemFree(pszFilePath);
                        }
                    }
                    pItem->Release();
                }
            }
            pFileSave->Release();
        }
        CoUninitialize();
    }
}

void cFileInterface::Select() {} // Removes Select() Functionality

void cFileInterface::Unselect() {} // Removes Unselect() Functionality

void cFileInterface::DrawButton(cWindowManager* _window, float _posY) {
    // Calls DrawFunction Function from cButton Parent Class
    cButton::DrawButton(_window, _posY);

    // Extend Functionality
    // Draws the Contents of the Button
    // Draws Button Contents to the Center Position of Button Bounds
    float fCenterBoundsX = this->m_Button.getPosition().x + (this->m_Button.getSize().x / 2);
    float fCenterBoundsY = this->m_Button.getPosition().y + (this->m_Button.getSize().y / 2);
    this->m_Text->setPosition(sf::Vector2f(fCenterBoundsX, fCenterBoundsY));

    _window->m_ToolWindow.draw(*(this->m_Text));
}
