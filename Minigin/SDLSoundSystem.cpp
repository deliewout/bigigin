#include "SDLSoundSystem.h"

dae::SDLSoundSystem::SDLSoundSystem()
{
}

dae::SDLSoundSystem::~SDLSoundSystem()
{
}

void dae::SDLSoundSystem::Play( soundId /*id*/, int volume )
{
	std::lock_guard lock( m_Mutex );
	
	//m_ConditionVariable.wait()
	m_Volume = volume;
	

}

void dae::SDLSoundSystem::SetVolume( int volume )
{
	Mix_VolumeMusic( volume );
}

void dae::SDLSoundSystem::Mute()
{
	m_Volume = 0;
	Mix_VolumeMusic( m_Volume );
}

void dae::SDLSoundSystem::Stop()
{
	Mix_HaltMusic();
}
