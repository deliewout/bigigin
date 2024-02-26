#include "Component.h"
#include "GameObject.h"



dae::GameObject* dae::Component::GetOwner() const
{
	return m_pOwner;
}

dae::Transform* dae::Component::GetTransform() const
{
	return m_pOwner->GetTransform();
}

void dae::Component::SetOwner( GameObject* pOwner )
{
	m_pOwner = pOwner;
}
