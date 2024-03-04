#include <string>
#include <memory>
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
	m_pTransform->SetPosition(x, y);
}

void dae::GameObject::SetParent( GameObject* pParent, bool keepWorldPosition)
{
	if (pParent == m_pParent || pParent == this)
	{
		return;
	}
	m_pParent = pParent;
	keepWorldPosition = true;

}

void dae::GameObject::RemoveChild( GameObject* pChild )
{
	m_pChildren.erase( std::remove_if( m_pChildren.begin(), m_pChildren.end(), [&]( std::unique_ptr<GameObject>& pCurrentChild)
		{
			return pCurrentChild.get()==pChild;
		}), m_pChildren.end());
}

void dae::GameObject::AddChild( GameObject* pChild )
{
	m_pChildren.emplace_back( pChild );
}



