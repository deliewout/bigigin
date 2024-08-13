#pragma once
#include "Command.h"
#include "GameObject.h"
namespace dae
{
	class PlaceBombCommand :public Command
	{
	public:
		PlaceBombCommand( std::shared_ptr<GameObject> pPlayer, std::shared_ptr<GameObject> pBomb );

		PlaceBombCommand( const PlaceBombCommand& other ) = delete;
		PlaceBombCommand( PlaceBombCommand&& other ) = delete;
		PlaceBombCommand& operator=( const PlaceBombCommand& other ) = delete;
		PlaceBombCommand& operator=( PlaceBombCommand&& other ) = delete;

		virtual void Execute() override;
	private:
		std::shared_ptr<GameObject> m_pPlayer;
		std::shared_ptr<GameObject> m_pBomb;

	};
}


