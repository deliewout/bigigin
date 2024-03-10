#include "TrashTheCache.h"
#include <chrono>
#include <algorithm>
#include <numeric>
#include "imgui.h"
#include "imgui_plot.h"

void dae::TrashTheCache::Render()
{
	//RenderEx1();
}

void dae::TrashTheCache::RenderEx1()
{
	if (!ImGui::Begin( "Excercise1" ))
	{
		ImGui::End();
		return;
	}
}

void dae::TrashTheCache::RenderEx2()
{
}

void dae::TrashTheCache::ExcerciseInt()
{
	std::vector<int> buffer{};
	buffer.resize( m_AmountOfNumbers );

	int stepsize{};
	
	for (stepsize = 1; stepsize <= 1024; stepsize *= 2)
	{
		std::vector<float>steptimes{};
		for (int currentSample{ 0 }; currentSample < m_IntSampleAmount; ++currentSample)
		{
			auto startTime = std::chrono::high_resolution_clock::now();
			for (size_t i = 0; i < buffer.size(); i += stepsize)
			{
				buffer[i] *= 2;
			}
			auto endTime = std::chrono::high_resolution_clock::now();
			auto elapsedTime{ std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() };
			steptimes.emplace_back( static_cast<float>(elapsedTime) );
		}
		std::sort( steptimes.begin(), steptimes.end() );
		const float avg{ std::accumulate( steptimes.begin() + 1,steptimes.end() - 1,0.0f ) / (steptimes.size() - 2) };
		m_IntSamples.emplace_back( avg );
	}
	
}

void dae::TrashTheCache::ExcerciseGO3D()
{
	std::vector<GameObject3D> buffer{};
	buffer.resize( m_AmountOfNumbers );

	int stepsize{};
	for (stepsize = 1; stepsize <= 1024; stepsize *= 2)
	{
		std::vector<float>steptimes{};
		for (int currentSample{ 0 }; currentSample < m_GO3DSampleAmount; ++currentSample)
		{
			auto startTime = std::chrono::high_resolution_clock::now();
			for (size_t i = 0; i < buffer.size(); i += stepsize)
			{
				buffer[i].id *= 2;
			}
			auto endTime = std::chrono::high_resolution_clock::now();
			auto elapsedTime{ std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() };
			steptimes.emplace_back( static_cast<float>(elapsedTime) );
		}
		std::sort( steptimes.begin(), steptimes.end() );
		const float avg{ std::accumulate( steptimes.begin() + 1,steptimes.end() - 1,0.0f ) / (steptimes.size() - 2) };
		m_GO3DSamples.emplace_back( avg );
	}
}

void dae::TrashTheCache::ExcerciseGO3DAlt()
{
	std::vector<GameObject3DAlt> buffer{};
	buffer.resize( m_AmountOfNumbers );

	int stepsize{};
	for (stepsize = 1; stepsize <= 1024; stepsize *= 2)
	{
		std::vector<float>steptimes{};
		for (int currentSample{ 0 }; currentSample < m_GO3DAltSampleAmount; ++currentSample)
		{
			auto startTime = std::chrono::high_resolution_clock::now();
			for (size_t i = 0; i < buffer.size(); i += stepsize)
			{
				buffer[i].id *= 2;
			}
			auto endTime = std::chrono::high_resolution_clock::now();
			auto elapsedTime{ std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() };
			steptimes.emplace_back( static_cast<float>(elapsedTime) );
		}
		std::sort( steptimes.begin(), steptimes.end() );
		const float avg{ std::accumulate( steptimes.begin() + 1,steptimes.end() - 1,0.0f ) / (steptimes.size() - 2) };
		m_GO3DAltSamples.emplace_back( avg );
	}
}
