#include <SDL.h>
#include "InputManager.h"
#include <backends/imgui_impl_sdl2.h>



bool dae::InputManager::ProcessInput()
{
	//ZeroMemory( &m_CurrentState, sizeof );
	
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		ImGui_ImplSDL2_ProcessEvent( &e );
		if (e.type == SDL_KEYDOWN) {
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		// etc...
	}

	return true;
}

void dae::InputManager::BindKeyboardAction( SDL_Scancode button, KeyStates keyState, std::unique_ptr<Command> action )
{
	m_KeyboardCommands.push_back( std::make_unique<KeyboardCommand>( button, keyState, std::move( action ) ) );
}

void dae::InputManager::BindGamePadAction( int controllerIndex, GamepadStates button, KeyStates keyState, std::unique_ptr<Command> action )
{
	m_GamepadCommands.push_back( std::make_unique<GamePadCommand>( controllerIndex, button, keyState, action ) );
}

void dae::InputManager::ProcessActions()
{
}

