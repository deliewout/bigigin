#include "Transform.h"

void dae::Transform::SetPosition(float x,float y/*, const float z*/)
{
	m_position.x = x;
	m_position.y = y;
	//m_position.z = z;
}

void dae::Transform::SetLocalPosition( const glm::vec2& Pos )
{
	m_position = Pos;
}

void dae::Transform::SetDirtyFlag()
{
	m_IsDirtyFlag = true;
	//for (auto& child : GetOwner()->GetChildren())
	//{

	//}
}

glm::vec2 dae::Transform::GetWorldPosition() const
{
	return m_position;
}



glm::vec2 dae::Transform::GetLocalPosition() const
{
	return m_position;
}
