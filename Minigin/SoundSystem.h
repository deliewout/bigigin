#pragma once
namespace dae
{
	using soundId = unsigned short;
	class SoundSystem
	{
	public:
		SoundSystem() =default;
		
		virtual ~SoundSystem() = default;
		SoundSystem( const SoundSystem& other ) = delete;
		SoundSystem( SoundSystem&& other ) = delete;
		SoundSystem& operator=( const SoundSystem& other ) = delete;
		SoundSystem& operator=( SoundSystem&& other ) = delete;

		virtual void Play( soundId id, float volume ) = 0 ;
		virtual void SetVolume( float volume ) = 0;
		virtual void Stop( ) = 0;
	};
}