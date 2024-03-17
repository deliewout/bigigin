#pragma once
#include <memory>
#include "Component.h"
#include "Texture2D.h"

namespace dae
{
	class RenderComponent final: public Component
	{

	public:

		RenderComponent( GameObject* pOwner ) ;
		~RenderComponent() = default ;
		RenderComponent( const RenderComponent& other ) = delete;
		RenderComponent& operator=( const RenderComponent& rhs ) = delete;
		RenderComponent( RenderComponent&& other ) = delete;
		RenderComponent& operator=( RenderComponent&& rhs ) = delete;

		void SetTexture( std::shared_ptr<dae::Texture2D> pTexture );

		void Render( glm::vec2 pos )const;

	private:
		std::shared_ptr<dae::Texture2D> m_pTexture2D{};

	};
}


