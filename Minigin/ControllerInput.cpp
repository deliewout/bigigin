#include "ControllerInput.h"

dae::ControllerInput::ControllerInput( int index )
	:m_GamepadIndex{index}
{

}

void dae::ControllerInput::Update()
{
	auto previousState = m_State;
	//XINPUT_STATE state;
	ZeroMemory( &m_State, sizeof( XINPUT_STATE ) );
	DWORD result = XInputGetState( m_GamepadIndex, &m_State );
	if (result == ERROR_DEVICE_NOT_CONNECTED)
	{
		m_DisconnectController = true;
		return;
	}
	
	m_ButtonChanges = m_State.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
	m_ButtonsPressedThisFrame = m_ButtonChanges & m_State.Gamepad.wButtons;
	m_ButtonsReleasedThisFrame= m_ButtonChanges & (~m_State.Gamepad.wButtons);
}

bool dae::ControllerInput::IsButtonDown( unsigned int button )
{
	return m_ButtonsPressedThisFrame & button;
}

bool dae::ControllerInput::IsButtonUp( unsigned int button )
{
	return m_ButtonsReleasedThisFrame & button;
}

bool dae::ControllerInput::IsButtonPressed( unsigned int button )
{
	return m_State.Gamepad.wButtons & button;
}
