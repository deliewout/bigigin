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
#include "TrashTheCache.h"
//#include "Minigin.h"


void test()
{
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
}
int main( int, char* [] ) {
	dae::Minigin engine("../Data/");
	engine.Run(test);
	return 0;
}