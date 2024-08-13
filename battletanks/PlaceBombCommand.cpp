#include "pch.h"
#include "PlaceBombCommand.h"

dae::PlaceBombCommand::PlaceBombCommand( std::shared_ptr<GameObject> pPlayer, std::shared_ptr<GameObject> pBomb )
	:m_pPlayer{ pPlayer }, m_pBomb{pBomb}
{
}

void dae::PlaceBombCommand::Execute()
{
	m_pBomb->GetTransform()->SetLocalPosition( m_pPlayer->GetTransform()->GetLocalPosition() );
}
