#include <src/helpers/Globals.h>
#include <src/Application.h>
#include "GameCamera.h"
#include <imgui.h>

GameCamera::GameCamera(bool start_enabled) : Module("renderer")
{
	CalculateViewMatrix();

	X = vec3(1.0f, 0.0f, 0.0f);
	Y = vec3(0.0f, 1.0f, 0.0f);
	Z = vec3(0.0f, 0.0f, 1.0f);

	Position = vec3(10.0f, 10.0f, 50.0f);
	Reference = vec3(0.0f, 0.0f, 0.0f);

	frustum.nearPlaneDistance = 0.5f;
	frustum.farPlaneDistance = 1000.0f;

	frustum.type = FrustumType::PerspectiveFrustum;
	frustum.projectiveSpace = FrustumProjectiveSpace::FrustumSpaceGL;
	frustum.handedness = FrustumHandedness::FrustumRightHanded;

	frustum.SetWorldMatrix(float3x4::identity);

	frustum.verticalFov = DegToRad(60.0f);
	SetAspectRatio();

	frustum.SetPerspective(frustum.horizontalFov, frustum.verticalFov);

	frustum.pos = float3::zero;

	frustum.Translate(vec(0.0f, 0.0f, 5.0f));

	frustum.GetCornerPoints(bb_frustum);
}

GameCamera::~GameCamera()
{}

// -----------------------------------------------------------------
bool GameCamera::Start()
{
	PLOG("Setting up the camera");
	bool ret = true;

	return ret;
}

// -----------------------------------------------------------------
bool GameCamera::CleanUp()
{
	PLOG("Cleaning camera");

	return true;
}

// -----------------------------------------------------------------
update_status GameCamera::Update(float dt)
{
	// Implement a debug camera with keys and mouse
	// Now we can make this movememnt frame rate independant!

	// Recalculate matrix -------------
	CalculateViewMatrix();

	// glOrtho(0.0f, 640, 480, 0.0f, 1.0f, -1.0f);		// Works weird as fuck
	
	return UPDATE_CONTINUE;
}

// -----------------------------------------------------------------
void GameCamera::Look(const vec3& Position, const vec3& Reference, bool RotateAroundReference)
{
	this->Position = Position;
	this->Reference = Reference;

	Z = normalize(Position - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	if (!RotateAroundReference)
	{
		this->Reference = this->Position;
		this->Position += Z * 0.05f;
	}

	CalculateViewMatrix();
}

// -----------------------------------------------------------------
void GameCamera::LookAt(const vec3& Spot)
{
	Reference = Spot;

	Z = normalize(Position - Reference);
	X = normalize(cross(vec3(0.0f, 1.0f, 0.0f), Z));
	Y = cross(Z, X);

	CalculateViewMatrix();
}

// -----------------------------------------------------------------
void GameCamera::Move(const vec3& Movement)
{
	Position += Movement;
	Reference += Movement;

	CalculateViewMatrix();
}

// -----------------------------------------------------------------
float* GameCamera::GetViewMatrix()
{
	return &ViewMatrix;
}

// -----------------------------------------------------------------
void GameCamera::CalculateViewMatrix()
{
	ViewMatrix = mat4x4(X.x, Y.x, Z.x, 0.0f, X.y, Y.y, Z.y, 0.0f, X.z, Y.z, Z.z, 0.0f, -dot(X, Position), -dot(Y, Position), -dot(Z, Position), 1.0f);
	ViewMatrixInverse = inverse(ViewMatrix);
}

void GameCamera::SetAspectRatio()
{
	float aspect_ratio = ((1280 -100) / (720-100));		//Window aspect ratio
	frustum.horizontalFov = 2.f * atanf(tanf(frustum.verticalFov * 0.5f) * aspect_ratio);
	frustum.SetPerspective(frustum.horizontalFov, frustum.verticalFov);
}

void GameCamera::ChangePosition(const vec3& pos)
{
	Position.x = pos.x;
	Position.y = pos.y;
	Position.z = pos.z;
}