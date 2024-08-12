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
#include "InputManager.h"
#include "MoveCommand.h"
#include "PlayerMoveCommand.h"
#include <glm/glm.hpp>

std::vector<std::vector<int>> grid{};
const float movementspeed{ 1.0f };

enum class BlockTypes
{
	wall,
	path,
	brick

};
void LoadLevelFile()
{
	std::ifstream file( "../Data/levels/LevelLayout1.csv" );
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

	file.close();
}

void test()
{
	dae::ServiceLocator::RegisterSoundSystem( std::make_unique<dae::SDLSoundSystem>() );
	auto& input=dae::InputManager::GetInstance();
	
	auto& scene = dae::SceneManager::GetInstance().CreateScene( "Demo" );


	auto go = std::make_shared<dae::GameObject>();

	auto font = dae::ResourceManager::GetInstance().LoadFont( "Lingua.otf", 36 );

	auto text = go->AddComponent<dae::TextObject>();

	go = std::make_shared<dae::GameObject>();
	auto createTexture = dae::ResourceManager::GetInstance().LoadTexture( "background.tga" );
	auto newTexture = go->AddComponent<dae::RenderComponent>();
	newTexture->SetTexture( createTexture );
	scene.Add( go );

	//load the diffrent tile texture
	auto wallTexture = dae::ResourceManager::GetInstance().LoadTexture( "levels/wall.png" );
	auto pathTexture = dae::ResourceManager::GetInstance().LoadTexture( "levels/path.png" );
	auto brickTexture = dae::ResourceManager::GetInstance().LoadTexture( "levels/BrickWall.png" );
	
	//load the level layout
	LoadLevelFile();

	const int blockSize = 20;
	int startX = 0;
	int startY = 100;

	// Draw the blocks based on the grid data
	for (size_t row = 0; row < grid.size(); ++row) {
		for (size_t col = 0; col < grid[row].size(); ++col) {
			go = std::make_shared<dae::GameObject>();
			if (!go) {
				std::cout << "Error creating game object\n";
				continue;
			}

			auto renderComponent = go->AddComponent<dae::RenderComponent>();
			if (!renderComponent) {
				std::cout << "Error creating render component\n";
				continue;
			}

			// Set the texture based on block type
			switch (static_cast<BlockTypes>(grid[row][col])) {
			case BlockTypes::wall:
				renderComponent->SetTexture( wallTexture );
				break;
			case BlockTypes::path:
				renderComponent->SetTexture( pathTexture );
				break;
			case BlockTypes::brick:
				renderComponent->SetTexture( brickTexture );
				break;
			default:
				std::cout << "Unknown block type\n";
				continue;
			}

			// Set the position of the block
			go->GetTransform()->SetLocalPosition( startX + static_cast<float>(col) * blockSize, startY + static_cast<float>(row) * blockSize );
			scene.Add( go );
		}
	}

	go = std::make_shared<dae::GameObject>();
	createTexture = dae::ResourceManager::GetInstance().LoadTexture( "logo.tga" );
	newTexture = go->AddComponent<dae::RenderComponent>();
	newTexture->SetTexture( createTexture );
	go->GetTransform()->SetLocalPosition( 216, 360 );
	scene.Add( go );


	auto refont = dae::ResourceManager::GetInstance().LoadFont( "Lingua.otf", 36 );
	go = std::make_shared<dae::GameObject>();

	//FPS->FixedUpdate();
	text = go->AddComponent<dae::TextObject>();
	text->SetFont( refont );
	text->SetText( "Programming 4 Assignment" );
	go->GetTransform()->SetLocalPosition( 80, 20 );
	scene.Add( go );

	//go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::RenderComponent>();
	//go->AddComponent<dae::FPSComponent>();
	//const auto pText{ go->AddComponent<dae::TextObject>() };
	//pText->SetFont( font );
	//go->GetTransform()->SetLocalPosition( 400, 300 );
	//scene.Add( go );
	//pText->SetColor( 255, 255, 0 );

	go = std::make_shared<dae::GameObject>();
	createTexture = dae::ResourceManager::GetInstance().LoadTexture( "sprites/player.png" );
	newTexture = go->AddComponent<dae::RenderComponent>();
	newTexture->SetTexture( createTexture );
	go->GetTransform()->SetLocalPosition( 20, 200 );
	scene.Add( go );

	//bind keyboard keys for moving
	input.BindKeyboardCommand( SDL_SCANCODE_W, dae::InputManager::KeyStates::pressed, std::make_unique<dae::PlayerMoveCommand>(go, glm::vec2{ 0,-1 }, movementspeed ) );
	input.BindKeyboardCommand( SDL_SCANCODE_S, dae::InputManager::KeyStates::pressed, std::make_unique<dae::PlayerMoveCommand>(go, glm::vec2{ 0,1 }, movementspeed ) );
	input.BindKeyboardCommand( SDL_SCANCODE_A, dae::InputManager::KeyStates::pressed, std::make_unique<dae::PlayerMoveCommand>(go, glm::vec2{ -1,0 }, movementspeed ) );
	input.BindKeyboardCommand( SDL_SCANCODE_D, dae::InputManager::KeyStates::pressed, std::make_unique<dae::PlayerMoveCommand>(go, glm::vec2{ 1,0 }, movementspeed ) );
	
	//bind gamepad keys for moving
	input.BindGamePadCommand( 0, dae::InputManager::GamepadStates::Dpad_Up, dae::InputManager::KeyStates::pressed, std::make_unique<dae::PlayerMoveCommand>( go, glm::vec2{ 0,-1 }, movementspeed ) );
	input.BindGamePadCommand( 0, dae::InputManager::GamepadStates::Dpad_Down, dae::InputManager::KeyStates::pressed, std::make_unique<dae::PlayerMoveCommand>( go, glm::vec2{ 0,1 }, movementspeed ) );
	input.BindGamePadCommand( 0, dae::InputManager::GamepadStates::Dpad_Left, dae::InputManager::KeyStates::pressed, std::make_unique<dae::PlayerMoveCommand>( go, glm::vec2{ -1,0 }, movementspeed ) );
	input.BindGamePadCommand( 0, dae::InputManager::GamepadStates::Dpad_Right, dae::InputManager::KeyStates::pressed, std::make_unique<dae::PlayerMoveCommand>( go, glm::vec2{ 1,0 }, movementspeed ) );
	

}
int main( int, char* [] ) {
	dae::Minigin engine("../Data/");
	engine.Run(test);
	return 0;
}