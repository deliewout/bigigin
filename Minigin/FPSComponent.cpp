#include "FPSComponent.h"
#include "sstream"

void dae::FPSComponent::Update(float elapsedSec)
{
	if (!m_pTextComponent)
	{
		//make sure this is put in initialized by next week
		m_pTextComponent=GetOwner()->GetComponent<TextObject>();
	}
	m_AccumulatedSec += elapsedSec;
	if (m_AccumulatedSec >= m_UpdateInterval)
	{
		m_AccumulatedSec -= m_UpdateInterval;

		std::stringstream fpsNumber{ std::to_string( static_cast<int>(1.0f / elapsedSec) )};
		
		fpsNumber << " FPS";
		m_pTextComponent->SetText( fpsNumber.str() );
		
		

	}
}
