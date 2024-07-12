#pragma once
#include <glm/glm.hpp>
#include "Component.h"

namespace dae
{
	class GameObject;
	class Transform final: public Component
	{
	public:
		//const glm::vec2& GetPosition() const { return m_Position; }
		//void SetPosition( float x, float y/*, float z*/);
		Transform( GameObject* pOwner  ) :Component( pOwner ) {};
		virtual ~Transform() = default;
		Transform( const Transform& other ) = delete;
		Transform& operator=( const Transform& rhs ) = delete;
		Transform( Transform&& other ) = delete;
		Transform& operator=( Transform&& rhs ) = delete;

		glm::vec2 GetWorldPosition();
		glm::vec2 GetLocalPosition() const;

		void UpdateWorldPos();
		void SetLocalPosition( const glm::vec2& Pos );
		void SetLocalPosition( const float x, const float y );

		void SetTransformParent(GameObject* pParent);

		void SetDirtyFlag();
	private:
		
		GameObject* m_pParent{};

		//made it a vec2 because it currently is just a 2d engine
		glm::vec2 m_LocalPosition{};
		glm::vec2 m_WorldPosition{};
		bool m_IsDirtyFlag{false};
	};
}
