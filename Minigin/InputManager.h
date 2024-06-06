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
	//class Command;
	class KeyboardInput;
	class InputManager final : public Singleton<InputManager>
	{
	public:
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

		std::vector<dae::Command> m_KeyboardCommands;
		std::vector<dae::Command> m_GamepadCommands;

		void BindKeyBoardAction(SDL_Scancode Button,  KeyStates KeyState, std::unique_ptr<dae::Command> Action );
		void BindGamePadAction(int ControllerIndex, GamepadStates Button,  KeyStates KeyState, std::unique_ptr<dae::Command> Action );
		void ProcessActions();
	};
}
