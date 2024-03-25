#include "Subject.h"
#include "Event.h"
#include "Observer.h"
#include <algorithm>

void dae::Subject::AddObserver( Observer* pObserver )
{
	if (std::find( m_Observers.begin(), m_Observers.end(), pObserver ) == m_Observers.end())
		m_Observers.push_back(pObserver);
}

void dae::Subject::RemoveObserver( Observer* pObserver )
{
	m_Observers.erase( std::remove( m_Observers.begin(), m_Observers.end(), pObserver ), m_Observers.end() );
}

void dae::Subject::NotifyObservers( const Event& event )
{
	for (const auto& observer : m_Observers)
		observer->Notify( event);
}
