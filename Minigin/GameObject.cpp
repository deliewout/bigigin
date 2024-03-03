#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::GameObject::GameObject()
{
	m_pTransform = AddComponent<Transform>();
}

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update( float elapsedSec  )
{
	for (size_t i = 0; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->Update( elapsedSec );
	}
		

}

void dae::GameObject::FixedUpdate( float )
{
}

void dae::GameObject::Render() const
{
	for (size_t i = 0; i < m_pComponents.size(); ++i)
	{
		m_pComponents[i]->Render();
	}
	//const auto& pos = m_pTransform->GetPosition();
	//Renderer::GetInstance().RenderTexture(*m_pComponents[], pos.x, pos.y);
}


void dae::GameObject::SetPosition(float x, float y)
{
	m_pTransform->SetPosition(x, y, 0.0f);
}

void dae::GameObject::SetParent( GameObject* pParent )
{
	if (pParent == nullptr || m_pParent == nullptr)
	{
		//GetTransform()->
	}
	m_pParent = pParent;
}




