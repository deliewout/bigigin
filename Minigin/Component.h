#pragma once

namespace dae
{
	class GameObject;
	class Transform;

	class Component
	{

	public:
		
		virtual void Update(float) {};
		virtual void FixedUpdate() {};
		virtual void Render() const {};

		virtual ~Component()= default;
		Component( const Component& other ) = delete;
		Component& operator=( const Component& rhs ) = delete;
		Component( Component&& other ) = delete;
		Component& operator=( Component&& rhs ) = delete;

		GameObject* GetOwner() const;
		Transform* GetTransform() const;
	protected:
		Component() = default;
	private:
		friend class GameObject;
		
		GameObject* m_pOwner{};

		void SetOwner( GameObject* pOwner );


	};
}



