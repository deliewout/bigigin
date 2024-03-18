#pragma once
#include <Windows.h>
#include <winerror.h>
#include <Xinput.h>
namespace dae 
{
	enum class Buttons
	{
		
	};
	class ControllerInput
	{
	public:
		ControllerInput() = default;
		~ControllerInput() = default;

		ControllerInput( const ControllerInput& other ) = delete;
		ControllerInput( ControllerInput&& other ) = delete;
		ControllerInput& operator=( const ControllerInput& other ) = delete;
		ControllerInput& operator=( ControllerInput&& other ) = delete;

		void Update();

		bool IsButtonDown( unsigned int button );
		bool IsButtonUp( unsigned int button );
		bool IsButtonPressed( unsigned int button );
		
	private:

		int m_ButtonChanges;
		int m_ButtonsPressedThisFrame;
		int m_ButtonsReleasedThisFrame;
		XINPUT_STATE m_State;
		int m_GamepadIndex;

		bool m_DisconnectController=false;

	};
}


