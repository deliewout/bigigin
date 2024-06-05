#include "ServiceLocator.h"
#include "SoundSystem.h"

std::unique_ptr<dae::SoundSystem> dae::ServiceLocator::SoundSystemInstance = nullptr;

