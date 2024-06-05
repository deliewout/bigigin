#pragma once
#include "SoundSystem.h"
#include <SDL_mixer.h>
#include <queue>
#include <mutex>
namespace dae 
{
	class SDLSoundSystem final: public SoundSystem
	{
	public:
		SDLSoundSystem();
		virtual ~SDLSoundSystem();

		virtual void Play( soundId id, int volume ) override;
		virtual void SetVolume( int volume ) override;
		virtual void Mute() override;
		virtual void Stop() override;
	private:
		//need for threads
		std::mutex m_Mutex{};
		std::jthread m_Thread{};
		std::condition_variable m_ConditionVariable{};

		//std::queue<soundId, int> m_Queue{};
		
		int m_Volume{ 0 };
	};
}


