#pragma once
#include <imgui_plot.h>
#include <vector>
struct Transform
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
public:
	Transform transform;
	int ID{};
};

class GameObject3DAlt
{
public:
	~GameObject3DAlt()
	{
		delete transform;
	}
	Transform* transform = new Transform{};
	int ID{};
};

class Exercise
{

public:
	void DoIntBuffer();
	void DoGameObject3DBuffer();
	void DoGameObject3DBufferAlt();
	ImGui::PlotConfig confInt;
	ImGui::PlotConfig confGo;
	ImGui::PlotConfig confGo3D;
	void ActivateIntRender();
	bool intPlot=false;
	bool goPlot = false;
	bool go3DPlot = false;
private:
	int length = 99999;
	std::vector<float> timings;
	std::vector<float> timingsGo;
	std::vector<float> timingsGo3D;
};

