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

		virtual void Play( soundId id, int volume ) = 0 ;
		virtual void SetVolume( int volume ) = 0;
		virtual void Mute( ) = 0;
		virtual void Stop( ) = 0;
	};
	class DefaultSoundSystem : public SoundSystem
	{
	public:
		DefaultSoundSystem() = default;
		virtual ~DefaultSoundSystem() = default;

		virtual void Play( soundId , int  ) override {};
		virtual void SetVolume( int ) override {};
		virtual void Mute() override {};
		virtual void Stop() override {};
	};
}