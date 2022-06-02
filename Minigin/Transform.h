#pragma once
#include "Component.h"
#pragma warning(push, 0)
#include <glm/glm.hpp>
#pragma warning (pop)
namespace dae
{
	class Transform : public Component
	{
	public:
		Transform(GameObject* owner);
		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z);
	private:
		glm::vec3 m_Position;
	};
}
