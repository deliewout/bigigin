#pragma once
#include "TextObject.h"
#include "GameObject.h"
namespace dae
{
	class FPSComponent final : public Component
	{
	public:
		void Update(float elapesedSec ) override;

		FPSComponent( GameObject* pOwner ) :Component{ pOwner } {};
		~FPSComponent() = default;
		FPSComponent( const FPSComponent& other ) = delete;
		FPSComponent& operator=( const FPSComponent& rhs ) = delete;
		FPSComponent( FPSComponent&& other ) = delete;
		FPSComponent& operator=( FPSComponent&& rhs ) = delete;
	private:
		TextObject* m_pTextComponent{};
		float m_AccumulatedSec{};
		float m_UpdateInterval{0.3f};

	};
}


