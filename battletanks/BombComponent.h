#pragma once
#include "Component.h"
namespace dae
{
	class BombComponent: public Component
	{
	public:
		BombComponent( GameObject* pOwner );
		virtual void Update( float elapsedSec ) override;
	private:
		float m_Timer{ 3.f };

	};
}


