#pragma once
#include <memory>
#include "Transform.h"
#include<string>
#include "Component.h"
#include <vector>

namespace dae
{
	class Texture2D;

	
	class GameObject final
	{
	public:
		void Update( float elapsedSec );
		void FixedUpdate( float  );
		void Render() const;

		void SetPosition(float x, float y);

		void SetParent( GameObject* parent, bool keepWorldPosition );
		GameObject* GetParent() const { return m_pParent; };
		size_t GetChildCount() const { return m_pChildren.size(); };
		GameObject* GetChildAt( unsigned int index ) const {return m_pChildren[index].get(); };
		void RemoveChild( GameObject* pChild );
		void AddChild( GameObject* pChild );

		template<typename T>
		T* AddComponent();
		template<typename T>
		void RemoveComponent();
		template<typename T>
		T* GetComponent();
		template<typename T>
		bool HasComponent();



		GameObject();
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		Transform GetTransform() { return m_pTransform; };

	private:
		Transform m_pTransform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		//std::shared_ptr<Texture2D> m_texture{};

		std::vector<std::unique_ptr<Component>> m_pComponents;

		GameObject* m_pParent{};
		std::vector<std::unique_ptr<GameObject>> m_pChildren;
		
	};

	template<typename T>
	T* GameObject::AddComponent()
	{
		if (HasComponent<T>() == false)
		{
			auto pComponent = std::make_unique<T>( this );



			m_pComponents.emplace_back( std::move( pComponent ) );


			return  dynamic_cast<T*>(m_pComponents.back().get());
		}
		return nullptr;
	}

	template<typename T>
	void GameObject::RemoveComponent()
	{
		for (auto it = m_pComponents.begin(); it > m_pComponents.end(); ++it)
		{
			if (std::dynamic_pointer_cast<T>(*it))
			{
				m_pComponents.erase( it );
				return;
			}
		}
	}

	template<typename T>
	T* GameObject::GetComponent()
	{
		for (const auto& ptr : m_pComponents)
		{
			if (auto pCast = dynamic_cast<T*>(ptr.get()))
			{
				return pCast;
			}
		}
		return nullptr;
	}

	template<typename T>
	bool GameObject::HasComponent()
	{
		return GetComponent<T>() != nullptr;
	}
}
