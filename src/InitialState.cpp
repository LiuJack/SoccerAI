#include "InitialState.h"
#include "BattleState.h"

#include <Graphics/DisplayManager.hpp>
#include <Scene/StateManager.hpp>
#include <Core/ResourceManager.hpp>


void InitialState::onInitialize() {
	dt::ResourceManager::get()->addResourceLocation("", "FileSystem");
	dt::ResourceManager::get()->addResourceLocation("sinbad.zip", "Zip", true);

	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	//auto scene = addScene(new dt::Scene("scene_01"));
	//auto camnode = scene->addChildNode(new dt::Node("camnode"));
	//camnode->addComponent(new dt::CameraComponent("camera"));

	dt::DisplayManager::get()->setWindowSize(800, 600);

}

void InitialState::onDeinitialize() {

}

void InitialState::updateStateFrame(double simulation_frame_time) {
	dt::StateManager::get()->setNewState(new BattleState());	
}