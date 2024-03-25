#pragma once
namespace dae
{
	struct Event;
	class Observer
	{
	public:
		virtual void Notify(const Event& event)=0;
	};
}


