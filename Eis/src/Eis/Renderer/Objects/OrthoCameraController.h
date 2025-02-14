#pragma once

#include "OrthographicCamera.h"
#include "Eis/Core/TimeStep.h"

#include "Eis/Events/ApplicationEvent.h"
#include "Eis/Events/MouseEvent.h"

namespace Eis
{
	class OrthoCameraController
	{
	public:
		OrthoCameraController(float aspectRatio, bool lock = false, bool rotation = false);
		~OrthoCameraController() = default;

		inline OrthographicCamera& GetCamera() { return m_Camera; }
		const inline OrthographicCamera& GetCamera() const { return m_Camera; }

		void OnUpdate(TimeStep ts);
		void OnEvent(Event& e);

		inline float GetCameraSpeed() { return m_CameraSpeed; }
		inline void SetCameraSpeed(float speed) { m_CameraSpeed = speed; }

		inline float GetSpeedModifier() { return m_SpeedMultiplier; }
		inline void SetSpeedModifier(float speedMultiplier) { m_SpeedMultiplier = speedMultiplier; }

	private:
		bool OnMouseScrolled(MouseScrolledEvent e);
		bool OnWindowResized(WindowResizeEvent e);

	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		float m_SpeedMultiplier = 2.0f;
		OrthographicCamera m_Camera;

		bool m_Rotation;
		bool m_Locked;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f; //Degrees, anti-clockwise direction
		float m_CameraSpeed = 2.0f,
			  m_CameraRotationSpeed = 90.0f,
		      m_ZoomSensitivity = 5.0f;
	};
}