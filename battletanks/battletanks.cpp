#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif
#include "pch.h"
#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "FPSComponent.h"
#include "Texture2D.h"
#include "Scene.h"
#include "RenderComponent.h"
#include "ServiceLocator.h"
#include "SDLSoundSystem.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<std::vector<int>> grid{};

enum class BlockTypes
{
	levelvoid,
	wall,
	path,
	teleport

};
void LoadLevelFile()
{
	std::ifstream file( "../Data/levels/LevelLayout0.csv" );
	if (!file.is_open())
	{
		std::cout << "error opening the file" << "\n";
	}
	// Read the grid layout from the file

	std::string line;
	while (std::getline( file, line )) {
		std::vector<int> row;
		std::stringstream ss( line );
		std::string value;

		while (std::getline( ss, value, ',' )) {
			row.push_back( std::stoi( value ) );
		}

		grid.push_back( row );
	}
	for (const auto& row : grid) {
		for (int type : row) {
			std::cout << type << " ";
		}
		std::cout << std::endl;
	}

	file.close();
}

void test()
{
	//dae::ServiceLocator::RegisterSoundSystem( std::make_unique<dae::SDLSoundSystem>() );
	auto& scene = dae::SceneManager::GetInstance().CreateScene( "Demo" );
	

	auto go = std::make_shared<dae::GameObject>();

	auto font = dae::ResourceManager::GetInstance().LoadFont( "Lingua.otf", 36 );

	auto text = go->AddComponent<dae::TextObject>();

	go = std::make_shared<dae::GameObject>();
	auto createTexture = dae::ResourceManager::GetInstance().LoadTexture( "background.tga" );
	auto newTexture = go->AddComponent<dae::RenderComponent>();
	newTexture->SetTexture( createTexture );
	scene.Add( go );

	go = std::make_shared<dae::GameObject>();
	createTexture = dae::ResourceManager::GetInstance().LoadTexture( "logo.tga" );
	newTexture = go->AddComponent<dae::RenderComponent>();
	newTexture->SetTexture( createTexture );
	go->SetPosition( 216, 180 );
	scene.Add( go );


	auto refont = dae::ResourceManager::GetInstance().LoadFont( "Lingua.otf", 36 );
	go = std::make_shared<dae::GameObject>();

	//FPS->FixedUpdate();
	text = go->AddComponent<dae::TextObject>();
	text->SetFont( refont );
	text->SetText( "Programming 4 Assignment" );
	go->SetPosition( 80, 20 );
	scene.Add( go );

	//go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::RenderComponent>();
	//go->AddComponent<dae::FPSComponent>();
	//const auto pText{ go->AddComponent<dae::TextObject>() };
	//pText->SetFont( font );
	//pText->SetColor( 255, 255, 0 );

	go = std::make_shared<dae::GameObject>();
	createTexture = dae::ResourceManager::GetInstance().LoadTexture( "sprites/RedTank.png" );
	newTexture = go->AddComponent<dae::RenderComponent>();
	newTexture->SetTexture( createTexture );
	go->SetPosition( 300, 300 );
	scene.Add( go );
	LoadLevelFile();
}
int main( int, char* [] ) {
	dae::Minigin engine("../Data/");
	engine.Run(test);
	return 0;
}