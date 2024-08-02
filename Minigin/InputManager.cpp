#include <SDL.h>
#include "InputManager.h"
#include <backends/imgui_impl_sdl2.h>



dae::InputManager::InputManager()
{
	m_Keyboard = std::make_unique<KeyboardInput>();
}

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
	m_Keyboard->Update();
	for (auto& currentGamepad : m_Gamepads)
	{
		currentGamepad->Update();
	}
	//HandleCommands();
	return true;
}

void dae::InputManager::BindKeyboardCommand( SDL_Scancode button, KeyStates keyState, std::unique_ptr<Command> action )
{
	m_KeyboardCommands.push_back( std::make_unique<KeyboardCommand>( button, keyState, std::move( action ) ) );
}

void dae::InputManager::BindGamePadCommand( int controllerIndex, GamepadStates button, KeyStates keyState, std::unique_ptr<Command> action )
{
	m_GamepadCommands.push_back( std::make_unique<GamePadCommand>( controllerIndex, button, keyState, std::move(action) ) );
}

void dae::InputManager::ProcessActions()
{
}

void dae::InputManager::HandleCommands()
{
	for (auto& command : m_KeyboardCommands)
	{
		switch (command->KeyState)
		{
		case KeyStates::up:
			if (m_Keyboard->IsButtonReleased( command->Button ))
				command->Action->Execute();
			break;
		case KeyStates::down:
			if (m_Keyboard->IsButtonDown( command->Button ))
				command->Action->Execute();
			break;
		case KeyStates::pressed:
			if (m_Keyboard->IsButtonPressed( command->Button ))
				command->Action->Execute();
			break;
		default:
			break;
		}
	}
	for (auto& command : m_GamepadCommands)
	{
		switch (command->KeyState)
		{
		case KeyStates::up:
			if (m_Gamepads[command->ControllerIdx]->IsButtonUp( static_cast<unsigned int>(command->Button)))
				command->Action->Execute();
			break;
		case KeyStates::down:
			if (m_Gamepads[command->ControllerIdx]->IsButtonDown( static_cast<unsigned int>(command->Button) ))
				command->Action->Execute();
			break;
		case KeyStates::pressed:
			if (m_Gamepads[command->ControllerIdx]->IsButtonPressed( static_cast<unsigned int>(command->Button) ))
				command->Action->Execute();
			break;
		default:
			break;
		}
	}
}

