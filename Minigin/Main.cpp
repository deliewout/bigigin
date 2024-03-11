#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "TextObject.h"
#include "FPSComponent.h"
#include "Texture2D.h"
#include "Scene.h"
#include "TrashTheCache.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	
	//const auto 
	//auto texture=go->AddComponent<dae::Texture2D>();
	//texture->GetTexture()
	

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	auto text=go->AddComponent<dae::TextObject>();
	text->SetText("hello");

	text->SetFont( font );
	go->SetPosition( 200, 200 );
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	//auto newTexture=go->AddComponent<dae::Texture2D>( /*"logo.tga"*/ );
	//newTexture.
	go->SetPosition(216, 180);
	scene.Add(go);

	auto refont = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	auto ro = std::make_shared<dae::GameObject>();
	//auto FPS=ro->AddComponent<dae::FPSComponent>();
	//FPS->FixedUpdate();
	text=ro->AddComponent<dae::TextObject>(  );
	text->SetFont( refont );
	text->SetText( "Programming 4 Assignment" );
	ro->SetPosition(80, 20);
	scene.Add(ro);


}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}