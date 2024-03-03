#pragma once
#include <memory>
#include "Component.h"
#include "Texture2D.h"

namespace dae
{
	class RenderComponent final: public Component
	{

	public:

		RenderComponent() = default;
		~RenderComponent() = default ;
		RenderComponent( const RenderComponent& other ) = delete;
		RenderComponent& operator=( const RenderComponent& rhs ) = delete;
		RenderComponent( RenderComponent&& other ) = delete;
		RenderComponent& operator=( RenderComponent&& rhs ) = delete;

		void SetTexture( std::shared_ptr<dae::Texture2D> pTexture );

		void Render()const;

	private:
		std::shared_ptr<dae::Texture2D> m_pTexture2D{};

	};
}


