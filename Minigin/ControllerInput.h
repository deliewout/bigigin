#pragma once


class ControllerInput
{
	public:
		ControllerInput() = default;
		~ControllerInput() = default;

		ControllerInput( const ControllerInput& other ) = delete;
		ControllerInput( ControllerInput&& other ) = delete;
		ControllerInput& operator=( const ControllerInput& other ) = delete;
		ControllerInput& operator=( ControllerInput&& other ) = delete;

};

