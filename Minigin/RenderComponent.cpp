#include "RenderComponent.h"
#include "Transform.h"
#include "Renderer.h"

void dae::RenderComponent::SetTexture( std::shared_ptr<dae::Texture2D> pTexture )
{
	m_pTexture2D = pTexture;
}

void dae::RenderComponent::Render() const
{
	const auto& pos = GetTransform()->GetPosition();
	Renderer::GetInstance().RenderTexture( *m_pTexture2D, pos.x, pos.y );
}
