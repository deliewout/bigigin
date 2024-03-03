#pragma once

namespace dae
{
	class GameObject;
	class Transform;

	class Component
	{

	public:
		
		virtual void Update( float elapsedSec );
		virtual void FixedUpdate() {};
		virtual void Render() const {};

		virtual ~Component()= default;
		Component( const Component& other ) = delete;
		Component& operator=( const Component& rhs ) = delete;
		Component( Component&& other ) = delete;
		Component& operator=( Component&& rhs ) = delete;

		
		Transform* GetTransform() const;
	protected:
		Component() = default;
		GameObject* GetOwner() const;
	private:
		friend class GameObject;
		
		GameObject* m_pOwner{};

		bool m_IsOwnerSet{ false };

		void SetOwner( GameObject* pOwner );




	};
}



