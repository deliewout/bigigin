#pragma once
#include <memory>
#include "SoundSystem.h"
namespace dae
{
	class ServiceLocator final
	{
		static std::unique_ptr<SoundSystem> SoundSystemInstance;
	public:
		static SoundSystem& GetSoundSystem() { return *SoundSystemInstance; }
		static void RegisterSoundSystem( std::unique_ptr<SoundSystem>&& ss ) {
			SoundSystemInstance = std::move( ss );
		}
	};
}

