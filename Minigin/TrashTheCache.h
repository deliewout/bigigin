#pragma once
#include <vector>
#include "imgui.h"

namespace dae
{
	class TrashTheCache final
	{
	public:
		TrashTheCache() = default;
		~TrashTheCache() = default;

		TrashTheCache( const TrashTheCache& other ) = delete;
		TrashTheCache( TrashTheCache&& other ) = delete;
		TrashTheCache& operator=( const TrashTheCache& other ) = delete;
		TrashTheCache& operator=( TrashTheCache&& other ) = delete;

		void Render();
	private:
		struct transform
		{
			float matrix[16] = {
				1,0,0,0,
				0,1,0,0,
				0,0,1,0,
				0,0,0,1
			};
		};

		class GameObject3D
		{
			transform local;
		public:

			int id{};
		};

		class GameObject3DAlt
		{
			transform* local;
		public:

			int id{};
		};
		
		const int m_AmountOfNumbers{ 100000000 };

		void RenderEx1();
		void RenderEx2();

		void ExcerciseInt();
		void ExcerciseGO3D();
		void ExcerciseGO3DAlt();

		int m_IntSampleAmount{ 10 };
		std::vector<float> m_IntSamples{};

		int m_GO3DSampleAmount{ 10 };
		std::vector<float> m_GO3DSamples{};
		int m_GO3DAltSampleAmount{ 10 };
		std::vector<float> m_GO3DAltSamples{};
		
	};
}


