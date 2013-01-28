#include "SoccerPitch.h"

#include <Physics/PhysicsBodyComponent.hpp>

#include <OgreProcedural.h>

SoccerPitch::SoccerPitch(const QString name /* = "SoccerPitch" */)
	: dt::Node(name) {
}

void SoccerPitch::onUpdate(double time_diff) {
	
}

void SoccerPitch::onInitialize() {
	// Realize a mesh 

	OgreProcedural::PlaneGenerator().setSizeX(100.0f).setSizeY(100.0f).setUTile(10.0).setVTile(10.0).realizeMesh("PitchMesh");
	this->addComponent(new dt::PhysicsBodyComponent("PitchMesh", "PitchPhysicsComponent", dt::PhysicsBodyComponent::CONVEX, 0.0f));
}

void SoccerPitch::onDeinitialize() {

}



