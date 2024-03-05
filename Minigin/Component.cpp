#include "Component.h"
#include "GameObject.h"



dae::GameObject* dae::Component::GetOwner() const
{
	return m_pOwner;
}

void dae::Component::Update( float /*elapsedSec*/ )
{

}

//dae::Transform* dae::Component::GetTransform() const
//{
//	return m_pOwner->GetTransform();
//}

//void dae::Component::SetOwner( GameObject* pOwner )
//{
//	if (!m_IsOwnerSet)
//	{
//		m_pOwner = pOwner;
//		m_IsOwnerSet=true;
//	}
//	
//}
