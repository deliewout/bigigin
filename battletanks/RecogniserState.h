#pragma once
namespace dae
{
	enum class RecogniserStates
	{
		wandering,
		chasing,
		dying
	};

	class RecogniserState
	{
	public:

	};
	class WanderingState : public RecogniserState
	{

	};
	class ChasingState : public RecogniserState
	{

	};
}


