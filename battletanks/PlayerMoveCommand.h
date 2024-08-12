#pragma once
#include "Command.h"
#include "GameObject.h"
namespace dae
{
	class PlayerMoveCommand: public Command
	{
	public:
		
		PlayerMoveCommand( std::shared_ptr<GameObject> pPlayer, const glm::vec2& direction, float speed );

		PlayerMoveCommand( const PlayerMoveCommand& other ) = delete;
		PlayerMoveCommand( PlayerMoveCommand&& other ) = delete;
		PlayerMoveCommand& operator=( const PlayerMoveCommand& other ) = delete;
		PlayerMoveCommand& operator=( PlayerMoveCommand&& other ) = delete;

		virtual void Execute() override;
	private:
		std::shared_ptr<GameObject> m_pPlayer;
		const glm::vec2 m_Direction;
		float m_Speed;
		
	};
}


