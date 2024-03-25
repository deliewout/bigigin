#pragma once
#include "vector"

namespace dae 
{
	struct Event;
	class Observer;
	class Subject
	{
	public:
		void AddObserver(Observer* pObserver);
		void RemoveObserver(Observer* pObserver);
	protected:
		void NotifyObservers( const Event& event );
	private:
		std::vector<Observer*> m_Observers{};
	};
}


