#pragma once
#include "cButtonApply.h"
#include "cButtonCancel.h"
#include "cButtonColor.h"

class cColorPickerManager {
private:
	cWindowManager* m_Window;
	cToolManager* m_ToolManager;
	sf::RenderWindow* m_ColorPickerWindow;

	// Color Picker
	sf::Image m_ColorPickerImage;
	sf::Texture m_ColorPickerTexture;
	sf::Sprite* m_ColorPickerSprite;
	sf::Color m_SelectedFillColor;
	sf::Color m_FillColor;
	sf::Color m_SelectedOutlineColor;
	sf::Color m_OutlineColor;

	// Button Member Variables
	cButtonApply* m_ButtonApply;
	cButtonCancel* m_ButtonCancel;
	cButtonColor* m_ButtonTransparent;
	cButtonColor* m_ButtonWhite;
	cButtonColor* m_ButtonBlack;

	// Transparent Texture
	sf::Image m_TransparentImage;
	sf::Texture m_TransparentTexture;

public:

	cColorPickerManager(cWindowManager* _window, cToolManager* _toolManager);
	~cColorPickerManager();

	// Buttons
	void DrawButtons(sf::RenderWindow* _colorPickerWindow);
	cButton* GetButton(sf::Vector2i _mousePos);
	cButtonColor* GetButtonColor(sf::Vector2i _mousePos);
	void RemoveHovers();
	void UnselectButtons();
	void HoverButton(sf::Vector2i _mousePos);
	void HoverButtonColor(sf::Vector2i _mousePos);
	void ClickButton(sf::Vector2i _mousePos);
	void ClickButtonColor(sf::Vector2i _mousePos);

	// Color
	void PickColor();
	sf::Color GetSelectedFillColor() const;
	sf::Color GetSelectedOutlineColor() const;
	void ConfirmNewColors();
	void CancelNewColors();
};

