#pragma once
#include <glm/glm.hpp>

namespace dae
{
	class GameObject;
	//class Transform;

	class Component
	{

	public:
		
		virtual void Update( float elapsedSec );
		virtual void FixedUpdate() {};
		virtual void Render(glm::vec2) const {};

		virtual ~Component()= default;
		Component( const Component& other ) = delete;
		Component& operator=( const Component& rhs ) = delete;
		Component( Component&& other ) = delete;
		Component& operator=( Component&& rhs ) = delete;

		GameObject* GetOwner() const;
		//Transform* GetTransform() const;
	protected:
		Component( GameObject* pOwner ) : m_pOwner{ pOwner } {} /*= default*/;
		
	private:
		friend class GameObject;
		
		GameObject* m_pOwner{};

		bool m_IsOwnerSet{ false };

		//void SetOwner( GameObject* pOwner );
	};
}



