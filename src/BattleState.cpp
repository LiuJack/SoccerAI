#include "BattleState.h"

#include <Graphics/DisplayManager.hpp>


#include <Graphics/MeshComponent.hpp>

#include <Graphics/LightComponent.hpp>

#include <Core/ResourceManager.hpp>


#include <OgreProcedural.h>


void BattleState::onInitialize() {
	auto scene = addScene(new dt::Scene("scene_01"));
	// This one is very important
	OgreProcedural::Root::getInstance()->sceneManager = scene->getSceneManager();

	dt::Node::NodeSP camnode = scene->addChildNode(new dt::Node("camnode"));
	camnode->setPosition(Ogre::Vector3(0.0f, 10.f, -5.f));
	camnode->addComponent(new dt::CameraComponent("camera"));
	camnode->findComponent<dt::CameraComponent>("camera")->lookAt(0, 0, 0);

	auto light_node = scene->addChildNode(new dt::Node("lightnode"));
	light_node->setPosition(Ogre::Vector3(-2000.0f, 2000.0f, 1000.0f));
	light_node->addComponent(new dt::LightComponent("light"));

	OgreProcedural::PlaneGenerator().setSizeX(10.0f).setSizeY(7.0f).setUTile(1.0).setVTile(1.0).realizeMesh("Plane");
	auto plane_node = scene->addChildNode(new dt::Node("planenode"));
	plane_node->addComponent(new dt::MeshComponent("Plane", "PrimitivesTest/Pebbles", "plane-mesh"));
	plane_node->addComponent(new dt::PhysicsBodyComponent("plane-mesh", "plane-body",
		dt::PhysicsBodyComponent::CONVEX, 0.0f));
	
}

void BattleState::onDeinitialize() {

}

void BattleState::updateStateFrame(double simulation_frame_time) {

}

// Just testing. Sorry :) 
