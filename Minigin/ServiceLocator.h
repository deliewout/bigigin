#pragma once
#include <memory>
#include "SoundSystem.h"
namespace dae
{
	class ServiceLocator final
	{
		static std::unique_ptr<SoundSystem> SoundSystemInstance;
		static std::unique_ptr<DefaultSoundSystem> DefaultSoundSystemInstance;
	public:
		ServiceLocator() = default;
		~ServiceLocator() = default;

		ServiceLocator( ServiceLocator& other ) = delete;
		ServiceLocator( ServiceLocator&& other ) = delete;
		ServiceLocator operator=( ServiceLocator& other ) = delete;
		ServiceLocator operator=( ServiceLocator&& other ) = delete;

		static SoundSystem& GetSoundSystem() { return *SoundSystemInstance; }
		static void RegisterSoundSystem( std::unique_ptr<SoundSystem>&& ss ) {
			SoundSystemInstance = std::move( ss );
		}
	};
}

