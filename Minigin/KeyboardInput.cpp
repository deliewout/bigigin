#include "KeyboardInput.h"

dae::KeyboardInput::KeyboardInput()
{
	m_Down.resize( SDL_NUM_SCANCODES );
	m_Up.resize( SDL_NUM_SCANCODES );
	m_Pressed.resize( SDL_NUM_SCANCODES );
}

void dae::KeyboardInput::Update()
{
}
