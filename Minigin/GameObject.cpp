#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::GameObject()
{
	m_pTransform = AddComponent<Transform>();
}

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update( float  ){}

void dae::GameObject::FixedUpdate( float )
{
}

void dae::GameObject::Render() const
{
	const auto& pos = m_pTransform->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_pTransform->SetPosition(x, y, 0.0f);
}

//void dae::GameObject::SetParent( GameObject* parent )
//{
//}


