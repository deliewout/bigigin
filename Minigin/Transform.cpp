#include "Transform.h"
#include "GameObject.h"

//void dae::Transform::SetPosition(float x,float y/*, const float z*/)
//{
//	m_Position.x = x;
//	m_Position.y = y;
//	//m_Position.z = z;
//}

void dae::Transform::SetLocalPosition( const glm::vec2& Pos )
{
	m_LocalPosition = Pos;
	SetDirtyFlag();
}

void dae::Transform::SetLocalPosition( float x, float y )
{
	return SetLocalPosition( glm::vec2{ x,y } );
}

void dae::Transform::SetTransformParent( GameObject* pParent )
{
	m_pParent = pParent;
}

void dae::Transform::SetDirtyFlag()
{
	m_IsDirtyFlag = true;
	for (const auto& child : m_pParent->GetChildren())
	{
		child->GetTransform()->SetDirtyFlag();
	}
}

glm::vec2 dae::Transform::GetWorldPosition()
{
	if (m_IsDirtyFlag)
		UpdateWorldPos();
	return m_WorldPosition;
}

void dae::Transform::UpdateWorldPos()
{
	if (m_IsDirtyFlag)
	{
		if (m_pParent==nullptr)
		{
			m_WorldPosition = m_LocalPosition;
		}
		else
		{
			m_WorldPosition = m_pParent->GetTransform()->GetWorldPosition() + m_LocalPosition;
		}
	}
	m_IsDirtyFlag = false;
}

glm::vec2 dae::Transform::GetLocalPosition() const
{
	return m_LocalPosition;
}
