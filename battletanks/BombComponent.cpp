#include "pch.h"
#include "BombComponent.h"
#include "GameObject.h"

dae::BombComponent::BombComponent( GameObject* pOwner )
	:dae::Component{pOwner}
{
}

void dae::BombComponent::Update( float elapsedSec )
{
	m_Timer -= elapsedSec;
	if (m_Timer <= 0.0f)
	{
		
	}
}
