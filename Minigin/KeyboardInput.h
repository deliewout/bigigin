#pragma once
#include <SDL_scancode.h>
#include <vector>
namespace dae
{
	class KeyboardInput
	{
	public:
		KeyboardInput() ;
		~KeyboardInput() = default;

		KeyboardInput( const KeyboardInput& other ) = delete;
		KeyboardInput( KeyboardInput&& other ) = delete;
		KeyboardInput& operator=( const KeyboardInput& other ) = delete;
		KeyboardInput& operator=( KeyboardInput&& other ) = delete;

		void Update();

		bool IsButtonDown( SDL_Scancode button ) { return m_Down[button]; };
		bool IsButtonReleased( SDL_Scancode button ) { return m_Up[button]; };
		bool IsButtonPressed( SDL_Scancode button ) { return m_Pressed[button]; };

	private:
		std::vector<Uint8> m_Down;
		std::vector<Uint8> m_Up;
		std::vector<Uint8> m_Pressed;
		std::vector<Uint8> m_PreviousState;

	};
}


