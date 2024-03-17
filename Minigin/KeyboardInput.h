#pragma once
#include <SDL_scancode.h>
class KeyboardInput
{
public:
	KeyboardInput() = default;
	~KeyboardInput() = default;

	KeyboardInput( const KeyboardInput& other ) = delete;
	KeyboardInput( KeyboardInput&& other ) = delete;
	KeyboardInput& operator=( const KeyboardInput& other ) = delete;
	KeyboardInput& operator=( KeyboardInput&& other ) = delete;

	bool IsButtonPressed( SDL_Scancode button ) { return button == m_Down; };
	bool IsButtonReleased( SDL_Scancode button ) { return button == m_Up; };
	//bool IsButtonHeldDown( SDL_Scancode button );

private:
	Uint8 m_Down;
	Uint8 m_Up;
	
};

