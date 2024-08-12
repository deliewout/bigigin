#include "pch.h"
#include "PlayerMoveCommand.h"

dae::PlayerMoveCommand::PlayerMoveCommand( std::shared_ptr<GameObject> pPlayer, const glm::vec2& direction, float speed )
	:m_pPlayer{std::move(pPlayer)}, m_Direction{direction},m_Speed{speed}
{
}

void dae::PlayerMoveCommand::Execute()
{
	if (m_pPlayer)
	{
		m_pPlayer->GetTransform()->MoveLocalPosition( m_Direction*m_Speed );
	}
}
