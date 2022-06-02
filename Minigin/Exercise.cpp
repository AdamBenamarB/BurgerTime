#include "MiniginPCH.h"
#include "Exercise.h"
#include <iostream>
#include <chrono>

void Exercise::DoIntBuffer()
{
	if (!intPlot) {

		int* arr = new int[length];
		//std::cout << "Integer buffer" << '\n';


		for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int i{}; i < length; i += stepsize)
			{
				arr[i] *= 2;
			}
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> nsfloat = end - start;
			//const auto total = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
			const auto total = std::chrono::duration_cast<std::chrono::nanoseconds>(nsfloat).count();
			timings.push_back((float)total / 1000000);
			//std::cout << "Stepsize: " << stepsize << " ns:" << total << '\n';
		}
		delete[] arr;
		//conf.values.xs = x_data; // this line is optional
		confInt.values.ys = timings.data();
		confInt.values.count = (int)timings.size();
		confInt.scale.min = 0;
		confInt.scale.max = 0.2f;
		confInt.tooltip.show = true;
		confInt.tooltip.format = "x=%.2f, y=%.2f";
		confInt.grid_x.show = true;
		confInt.grid_y.show = true;
		confInt.frame_size = ImVec2(400, 400);
		confInt.line_thickness = 2.f;
		intPlot = true;
	}
}

void Exercise::DoGameObject3DBuffer()
{
	if (!goPlot) {
		GameObject3D* goarr = new GameObject3D[length];
		for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int i{}; i < length; i += stepsize)
			{
				goarr[i].transform.matrix[1] *= 2;
			}
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> nsfloat = end - start;
			const auto total = std::chrono::duration_cast<std::chrono::nanoseconds>(nsfloat).count();
			timingsGo.push_back((float)total / 1000000);
		}
		delete[] goarr;
		confGo.values.ys = timingsGo.data();
		confGo.values.count = (int)timingsGo.size();
		confGo.scale.min = 0;
		confGo.scale.max = 0.2f;
		confGo.tooltip.show = true;
		confGo.tooltip.format = "x=%.2f, y=%.2f";
		confGo.grid_x.show = true;
		confGo.grid_y.show = true;
		confGo.frame_size = ImVec2(400, 400);
		confGo.line_thickness = 2.f;
		goPlot = true;
	}
}

void Exercise::DoGameObject3DBufferAlt()
{
	if (!go3DPlot) {
		GameObject3DAlt* goarralt = new GameObject3DAlt[length];
		for (int stepsize{ 1 }; stepsize <= 1024; stepsize *= 2)
		{
			auto start = std::chrono::high_resolution_clock::now();
			for (int i{}; i < length; i += stepsize)
			{
				goarralt[i].transform->matrix[1] *= 2;
			}
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> nsfloat = end - start;
			const auto total = std::chrono::duration_cast<std::chrono::nanoseconds>(nsfloat).count();
			timingsGo3D.push_back((float)total / 1000000);
		}
		delete[] goarralt;
		confGo3D.values.ys = timingsGo3D.data();
		confGo3D.values.count = (int)timingsGo3D.size();
		confGo3D.scale.min = 0;
		confGo3D.scale.max = 0.2f;
		confGo3D.tooltip.show = true;
		confGo3D.tooltip.format = "x=%.2f, y=%.2f";
		confGo3D.grid_x.show = true;
		confGo3D.grid_y.show = true;
		confGo3D.frame_size = ImVec2(400, 400);
		confGo3D.line_thickness = 2.f;
		go3DPlot = true;
	}
}
void Exercise::ActivateIntRender()
{
	intPlot = true;
}