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

//glm::vec dae::Transform::GetWorldPosition() const
//{
//	
//}
