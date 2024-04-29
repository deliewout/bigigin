#pragma once
#include "SoundSystem.h"
namespace dae 
{
	class SDLSoundSystem final: public SoundSystem
	{
	public:
		SDLSoundSystem();
		virtual ~SDLSoundSystem();

		virtual void SetVolume( float volume ) override;
	private:
		float m_Volume{ 0.0f };
	};
}


