#ifndef SOCCER_AI_SOCCER_PITCH
#define SOCCER_AI_SOCCER_PITCH

#include <Scene/Node.hpp>
#include <Graphics/MeshComponent.hpp>

class SoccerPitch : public dt::Node {
	Q_OBJECT

public:
	SoccerPitch(const QString name = "SoccerPitch");

	void onInitialize();

	void onDeinitialize();

	void onUpdate(double time_diff);

private:

	//dt::MeshComponent mMesh; 

};





#endif