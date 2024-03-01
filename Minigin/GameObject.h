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
		void Update( float );
		void FixedUpdate( float  );
		void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		//void SetParent( GameObject* parent );
		//void GetParent() const;
		//size_t GetChildCount() const;
		//GameObject* GetChildAt( unsigned int index ) const;

		template<typename T,typename...Args>
		T* AddComponent(Args... print);
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

		Transform* GetTransform() { return m_pTransform; };

	private:
		//Transform m_transform{};
		Transform* m_pTransform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::shared_ptr<Texture2D> m_texture{};

		std::vector<std::unique_ptr<Component>> m_Components;

		std::unique_ptr<GameObject> m_Parent{};
		std::unique_ptr<GameObject[]> m_Children;
		
	};

	template<typename T, typename...Args>
	inline T* GameObject::AddComponent(Args... print)
	{
		if (HasComponent<T>() == false)
		{
			auto pComponent = std::make_unique<T>( std::forward<Args>( print )... );
			pComponent->SetOwner( this );
			T* componentPtr{ pComponent.get() };
			
			m_Components.push_back( std::move(pComponent) );
			

			return componentPtr;
		}
		return nullptr;
	}

	template<typename T>
	inline void dae::GameObject::RemoveComponent()
	{
		for (auto it = m_Components.begin(); it > m_Components.end(); ++it)
		{
			if (std::dynamic_pointer_cast<T>(*it))
			{
				m_Components.erase( it );
				return;
			}
		}
	}

	template<typename T>
	inline T* GameObject::GetComponent()
	{
		for (const auto& ptr : m_Components)
		{
			if (auto pCast = dynamic_cast<T*>(ptr.get()))
			{
				return pCast;
			}
		}
		return nullptr;
	}

	template<typename T>
	inline bool dae::GameObject::HasComponent()
	{
		return GetComponent<T>()!=nullptr;
	}
}
