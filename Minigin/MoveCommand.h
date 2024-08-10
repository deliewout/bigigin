#pragma once
#include <glm/glm.hpp>
#include "Command.h"
namespace dae
{
	class MoveCommand final: public Command
	{
	public:
		MoveCommand( const glm::vec2& direction, float speed ) :m_Direction{ direction }, m_Speed{ speed } {};
		~MoveCommand() = default;

		MoveCommand( const MoveCommand& other ) = delete;
		MoveCommand( MoveCommand&& other ) = delete;
		MoveCommand& operator=( const MoveCommand& other ) = delete;
		MoveCommand& operator=( MoveCommand&& other ) = delete;

		void Execute();
	private:
		const glm::vec2& m_Direction;
		float m_Speed;
	};
}


