#pragma once
#include <glm/glm.hpp>
#include "Component.h"

namespace dae
{
	class Transform final//:public Component
	{
	public:
		const glm::vec2& GetPosition() const { return m_position; }
		void SetPosition( float x, float y/*, float z*/);

		glm::vec2 GetWorldPosition() const;
		
		glm::vec2 GetLocalPosition() const;
		void SetLocalPosition( const glm::vec2& Pos );

		void SetDirtyFlag();
	private:
		glm::vec2 m_position{};
		bool m_IsDirtyFlag{false};
	};
}
