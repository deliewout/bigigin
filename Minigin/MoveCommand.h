#pragma once
#include "Command.h"
namespace dae
{
	class MoveCommand final: public Command
	{
	public:
		MoveCommand()= default;
		~MoveCommand() = default;

		MoveCommand( const MoveCommand& other ) = delete;
		MoveCommand( MoveCommand&& other ) = delete;
		MoveCommand& operator=( const MoveCommand& other ) = delete;
		MoveCommand& operator=( MoveCommand&& other ) = delete;

		void Execute();
	};
}


