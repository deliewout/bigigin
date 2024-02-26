#pragma once
#include <glm/glm.hpp>
#include "Component.h"

namespace dae
{
	class Transform final:public Component
	{
	public:
		const glm::vec3& GetPosition() const { return m_position; }
		void SetPosition(float x, float y, float z);
	private:
		glm::vec3 m_position;
	};
}
