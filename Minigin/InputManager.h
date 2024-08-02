#pragma once
#include "Singleton.h"
#include "KeyboardInput.h"
#include "ControllerInput.h"
#include <Xinput.h>
#include <memory>
#include <SDL_scancode.h>
#include "Command.h"


namespace dae
{
	
	class KeyboardInput;
	class InputManager final : public Singleton<InputManager>
	{
	public:
		InputManager();
		bool ProcessInput();

		//all buttons for gamepad (without thumbs)
		enum class GamepadStates
		{
			Dpad_Up = 0x0001,
			Dpad_Down = 0x0002,
			Dpad_Left = 0x0004,
			Dpad_Right = 0x0008,
			Dpad_Start = 0x0010,
			Dpad_Back = 0x0020,
			//Dpad_LeftThumb = 0x0040,
			//Dpad_RightThumb = 0x0080,
			Dpad_LeftShoulder = 0x0100,
			Dpad_RightShoulder = 0x0200,
			Dpad_A = 0x1000,
			Dpad_B = 0x2000,
			Dpad_X = 0x4000,
			Dpad_Y = 0x8000
		};

		enum class KeyStates
		{
			up,
			down,
			pressed,
		};



		//functions to bind a button press to a certain command
		void BindKeyboardCommand(SDL_Scancode button,  KeyStates keyState, std::unique_ptr<Command> action );
		void BindGamePadCommand(int controllerIndex, GamepadStates button,  KeyStates keyState, std::unique_ptr<Command> action );
		void ProcessActions();

		struct KeyboardCommand final
		{
			KeyboardCommand( SDL_Scancode button, KeyStates keyState, std::unique_ptr<Command> action )
				:Button{ button }, KeyState{ keyState }, Action{ std::move( action ) }
			{}

			SDL_Scancode Button;
			KeyStates KeyState;
			std::unique_ptr<Command> Action;
		};
		struct GamePadCommand final
		{
			GamePadCommand( int controllerIndex, GamepadStates button, KeyStates keyState, std::unique_ptr<Command> action )
				:ControllerIdx{ controllerIndex },Button {button}, KeyState{ keyState }, Action{ std::move( action ) }
			{}

			int ControllerIdx;
			GamepadStates Button;
			KeyStates KeyState;
			std::unique_ptr<Command> Action;
		};
	private:
		//vectors of commands depending on which input device is used
		std::vector<std::unique_ptr<KeyboardCommand>> m_KeyboardCommands;
		std::vector<std::unique_ptr<GamePadCommand>> m_GamepadCommands;
		std::unique_ptr<KeyboardInput> m_Keyboard;
		std::vector<std::unique_ptr<ControllerInput>> m_Gamepads;


		void HandleCommands();
	};
}
