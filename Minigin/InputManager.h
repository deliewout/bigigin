#pragma once
#include "Singleton.h"
#include "KeyboardInput.h"
#include "ControllerInput.h"

namespace dae
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
	};

}
