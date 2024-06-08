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

void dae::InputManager::BindKeyBoardAction( SDL_Scancode Button, KeyStates KeyState, std::unique_ptr<dae::Command> Action )
{
	//temp fix
	Button;
	KeyState;
	Action;
}

void dae::InputManager::BindGamePadAction( int ControllerIndex, GamepadStates Button, KeyStates KeyState, std::unique_ptr<dae::Command> Action )
{
	//temp fix
	ControllerIndex;
	Button;
	KeyState;
	Action;
}

void dae::InputManager::ProcessActions()
{
}

