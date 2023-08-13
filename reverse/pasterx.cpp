#include "pasterx.h"
#include "driver.h"
#include "Print.hpp"
#include "d3d9_x.h"
#include "xor.hpp"
#include <dwmapi.h>
#include <vector>
#include "Keybind.h"
#include "auth.hpp"
#include "color.hpp"
#include "json.hpp"
#include "utils.hpp"
#include "offsets.h"
#include "xstring"

// UPDATED BY PAYSON HOLMES - DSC.GG/SUBZEROFN

using namespace KeyAuth;

std::string name = ""; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = ""; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = ""; // app secret, the blurred text on licenses tab and other tabs
std::string version = ""; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/"; // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);

#define color1 (WORD)(0x0001 | 0x0000)
#define color2 (WORD)(0x0002 | 0x0000)
#define color3 (WORD)(0x0003 | 0x0000)
#define color4 (WORD)(0x0004 | 0x0000)
#define color5 (WORD)(0x0005 | 0x0000)
#define color6 (WORD)(0x0006 | 0x0000)
#define color7 (WORD)(0x0007 | 0x0000)
#define color8 (WORD)(0x0008 | 0x0000)
#define color9 (WORD)(0x0008 | 0x0000)
#define COLOR(h, c) SetConsoleTextAttribute(h, c);

static int aimkeypos = 3;
static int aimbone = 1;

int faken_rot = 0;

float BOG_TO_GRD(float BOG) {
	return (180 / M_PI) * BOG;
}

float GRD_TO_BOG(float GRD) {
	return (M_PI / 180) * GRD;
}

bool lobby = false;
bool fuel = false;
bool animate = false;

bool threed = false;
bool filledsqr = false;
bool fovcircle = false;
bool targetlines = false;
bool ShowMenu = true;
bool Esp = false;
bool Esp_box = false;
bool fovchanger = false;
bool zekren = false;
bool cornerbox = false;
bool Esp_info = false;
bool Esp_line = false;
bool Aimbot = false;
bool crosshair = false;
bool Skeleton = false;
bool Esp_Skeleton1 = false;
bool slefESP = false;
bool square_fov = false;
bool weaponesp = false;
bool ammoESP = false;
bool AimWhileJumping = false;
bool Esp_Distance = false;
bool carFly = false;
bool niggerfovchanger = false;
bool RapidFire = false;
bool spinbot = false;
bool infammo = false;
bool tpose = false;
bool minigun = false;
bool instantreload = false;
bool boatspeed = false;
bool bostspeed = false;
bool carto = false;
bool first_person = false;
bool Safemode = true;
bool reloadcheck = true;
bool fillbox = false;
bool fovcirclefilled = false;
bool lineheadesp = false;
bool cornerline = false;
float BoxWidthValue = 0.550;
bool carfly = false;
bool bullettp = false;


float ChangerFOV = 80;




ImFont* m_pFont;
float smooth = 5;
static int VisDist = 250;
float AimFOV = 150;
static int aimkey;
static int hitbox;
static int hitboxpos = 0;





DWORD_PTR Uworld;
DWORD_PTR LocalPawn;
DWORD_PTR PlayerState;
DWORD_PTR Localplayer;
DWORD_PTR Rootcomp;
DWORD_PTR PlayerController;
DWORD_PTR Persistentlevel;
uintptr_t PlayerCameraManager;
Vector3 localactorpos;

uint64_t TargetPawn;
int localplayerID;

RECT GameRect = { NULL };
D3DPRESENT_PARAMETERS d3dpp;
DWORD ScreenCenterX;
DWORD ScreenCenterY;
Vector3 LocalRelativeLocation; struct FBoxSphereBounds
{
	struct Vector3                                     Origin;                                                   // 0x0000(0x0018) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	struct Vector3                                     BoxExtent;                                                // 0x0018(0x0018) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	double                                             SphereRadius;                                             // 0x0030(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
};
static void xCreateWindow();
static void xInitD3d();
static void xMainLoop();
static void xShutdown();
static LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static HWND Window = NULL;
IDirect3D9Ex* p_Object = NULL;
static LPDIRECT3DDEVICE9 D3dDevice = NULL;
static LPDIRECT3DVERTEXBUFFER9 TriBuf = NULL;

typedef struct {
	float X, Y, Z;
} FVector;

typedef struct {
	float X, Y;
} FVector2D;



typedef struct {
	FVector Location;
	float FOV;
	float OrthoWidth;
	float OrthoNearClipPlane;
	float OrthoFarClipPlane;
	float AspectRatio;
} FMinimalViewInfo;

typedef struct {
	float M[4][4];
} FMatrix;

typedef struct {
	FVector ViewOrigin;
	char _padding_0[4];
	FMatrix ViewRotationMatrix;
	FMatrix ProjectionMatrix;
} FSceneViewProjectionData;




class UClass {
public:
	BYTE _padding_0[0x40];
	UClass* SuperClass;
};

class UObject {
public:
	PVOID VTableObject;
	DWORD ObjectFlags;
	DWORD InternalIndex;
	UClass* Class;
	BYTE _padding_0[0x8];
	UObject* Outer;

	inline BOOLEAN IsA(PVOID parentClass) {
		for (auto super = this->Class; super; super = super->SuperClass) {
			if (super == parentClass) {
				return TRUE;
			}
		}

		return FALSE;
	}
};



class FUObjectItem {
public:
	UObject* Object;
	DWORD Flags;
	DWORD ClusterIndex;
	DWORD SerialNumber;
	DWORD SerialNumber2;
};

class TUObjectArray {
public:
	FUObjectItem* Objects[9];
};

class GObjects {
public:
	TUObjectArray* ObjectArray;
	BYTE _padding_0[0xC];
	DWORD ObjectCount;
};


template<class T>
struct TArray {
	friend struct FString;

public:
	inline TArray() {
		Data = nullptr;
		Count = Max = 0;
	};

	inline INT Num() const {
		return Count;
	};

	inline T& operator[](INT i) {
		return Data[i];
	};

	inline BOOLEAN IsValidIndex(INT i) {
		return i < Num();
	}

private:
	T* Data;
	INT Count;
	INT Max;
};

struct FString : private TArray<WCHAR> {
	FString() {
		Data = nullptr;
		Max = Count = 0;
	}

	FString(LPCWSTR other) {
		Max = Count = static_cast<INT>(wcslen(other));

		if (Count) {
			Data = const_cast<PWCHAR>(other);
		}
	};

	inline BOOLEAN IsValid() {
		return Data != nullptr;
	}

	inline PWCHAR c_str() {
		return Data;
	}
};

VOID(*FreeInternal)(PVOID) = nullptr;

VOID Free(PVOID buffer) {
	FreeInternal(buffer);
}


#pragma once

namespace detail
{
	extern "C" void* _spoofer_stub();

	template <typename Ret, typename... Args>
	static inline auto shellcode_stub_helper(
		const void* shell,
		Args... args
	) -> Ret
	{
		auto fn = (Ret(*)(Args...))(shell);
		return fn(args...);
	}

	template <std::size_t Argc, typename>
	struct argument_remapper
	{
		template<
			typename Ret,
			typename First,
			typename Second,
			typename Third,
			typename Fourth,
			typename... Pack
		>
		static auto do_call(const void* shell, void* shell_param, First first, Second second,
			Third third, Fourth fourth, Pack... pack) -> Ret
		{
			return shellcode_stub_helper< Ret, First, Second, Third, Fourth, void*, void*, Pack... >(shell, first, second, third, fourth, shell_param, nullptr, pack...);
		}
	};

	template <std::size_t Argc>
	struct argument_remapper<Argc, std::enable_if_t<Argc <= 4>>
	{
		template<
			typename Ret,
			typename First = void*,
			typename Second = void*,
			typename Third = void*,
			typename Fourth = void*
		>
		static auto do_call(
			const void* shell,
			void* shell_param,
			First first = First{},
			Second second = Second{},
			Third third = Third{},
			Fourth fourth = Fourth{}
		) -> Ret
		{
			return shellcode_stub_helper<
				Ret,
				First,
				Second,
				Third,
				Fourth,
				void*,
				void*
			>(
				shell,
				first,
				second,
				third,
				fourth,
				shell_param,
				nullptr
				);
		}
	};
}

template <typename Ret, typename... Args>
static inline auto SpoofCall(Ret(*fn)(Args...), Args... args) -> Ret
{
	static const void* jmprbx = nullptr;
	if (!jmprbx) {
		const auto ntdll = reinterpret_cast<const unsigned char*>(::GetModuleHandleW(NULL));
		const auto dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(ntdll);
		const auto nt = reinterpret_cast<const IMAGE_NT_HEADERS*>(ntdll + dos->e_lfanew);
		const auto sections = IMAGE_FIRST_SECTION(nt);
		const auto num_sections = nt->FileHeader.NumberOfSections;

		constexpr char section_name[5]{ '.', 't', 'e', 'x', 't' };
		const auto     section = std::find_if(sections, sections + num_sections, [&](const auto& s) {
			return std::equal(s.Name, s.Name + 5, section_name);
			});

		constexpr unsigned char instr_bytes[2]{ 0xFF, 0x26 };
		const auto              va = ntdll + section->VirtualAddress;
		jmprbx = std::search(va, va + section->Misc.VirtualSize, instr_bytes, instr_bytes + 2);
	}

	struct shell_params
	{
		const void* trampoline;
		void* function;
		void* rdx;
	};

	shell_params p
	{
		jmprbx,
		reinterpret_cast<void*>(fn)
	};

	using mapper = detail::argument_remapper<sizeof...(Args), void>;
	return mapper::template do_call<Ret, Args...>((const void*)&detail::_spoofer_stub, &p, args...);
}

namespace SpoofRuntime {
	inline float acosf_(float x)
	{
		return SpoofCall(acosf, x);
	}

	inline float atan2f_(float x, float y)
	{
		return SpoofCall(atan2f, x, y);
	}
}



#define BONE_HEAD_ID (68)
#define BONE_NECK_ID (67)
#define BONE_CHEST_ID (36)
#define BONE_PELVIS_ID (2)




Vector3 GetBoneWithRotation(uintptr_t mesh, int bone_id)
{
	uintptr_t bone_array = ReadBizzy<uintptr_t>(mesh + OFFSETS::BoneArray);
	if (bone_array == NULL) bone_array = ReadBizzy<uintptr_t>(mesh + OFFSETS::BoneArray + 0x10);
	FTransform bone = ReadBizzy<FTransform>(bone_array + (bone_id * 0x60));
	FTransform component_to_world = ReadBizzy<FTransform>(mesh + OFFSETS::ComponetToWorld);
	D3DMATRIX matrix = MatrixMultiplication(bone.ToMatrixWithScale(), component_to_world.ToMatrixWithScale());
	return Vector3(matrix._41, matrix._42, matrix._43);
}

D3DXMATRIX Matrix(Vector3 rot, Vector3 origin = Vector3(0, 0, 0))
{
	float radPitch = (rot.x * float(M_PI) / 180.f);
	float radYaw = (rot.y * float(M_PI) / 180.f);
	float radRoll = (rot.z * float(M_PI) / 180.f);

	float SP = sinf(radPitch);
	float CP = cosf(radPitch);
	float SY = sinf(radYaw);
	float CY = cosf(radYaw);
	float SR = sinf(radRoll);
	float CR = cosf(radRoll);

	D3DMATRIX matrix;
	matrix.m[0][0] = CP * CY;
	matrix.m[0][1] = CP * SY;
	matrix.m[0][2] = SP;
	matrix.m[0][3] = 0.f;

	matrix.m[1][0] = SR * SP * CY - CR * SY;
	matrix.m[1][1] = SR * SP * SY + CR * CY;
	matrix.m[1][2] = -SR * CP;
	matrix.m[1][3] = 0.f;

	matrix.m[2][0] = -(CR * SP * CY + SR * SY);
	matrix.m[2][1] = CY * SR - CR * SP * SY;
	matrix.m[2][2] = CR * CP;
	matrix.m[2][3] = 0.f;

	matrix.m[3][0] = origin.x;
	matrix.m[3][1] = origin.y;
	matrix.m[3][2] = origin.z;
	matrix.m[3][3] = 1.f;

	return matrix;
}


double __fastcall Atan2(double a1, double a2)
{
	double result; // xmm0_8

	result = 0.0;
	if (a2 != 0.0 || a1 != 0.0)
		return atan2(a1, a2);
	return result;
}
double __fastcall FMod(double a1, double a2)
{
	if (fabs(a2) > 0.00000001)
		return fmod(a1, a2);
	else
		return 0.0;
}

double ClampAxis(double Angle)
{
	// returns Angle in the range (-360,360)
	Angle = FMod(Angle, (double)360.0);

	if (Angle < (double)0.0)
	{
		// shift to [0,360) range
		Angle += (double)360.0;
	}

	return Angle;
}

double NormalizeAxis(double Angle)
{
	// returns Angle in the range [0,360)
	Angle = ClampAxis(Angle);

	if (Angle > (double)180.0)
	{
		// shift to (-180,180]
		Angle -= (double)360.0;
	}

	return Angle;
}

class FRotator
{
public:
	FRotator() : Pitch(0.f), Yaw(0.f), Roll(0.f)
	{

	}

	FRotator(double _Pitch, double _Yaw, double _Roll) : Pitch(_Pitch), Yaw(_Yaw), Roll(_Roll)
	{

	}
	~FRotator()
	{

	}

	double Pitch;
	double Yaw;
	double Roll;
	inline FRotator get() {
		return FRotator(Pitch, Yaw, Roll);
	}
	inline void set(double _Pitch, double _Yaw, double _Roll) {
		Pitch = _Pitch;
		Yaw = _Yaw;
		Roll = _Roll;
	}

	inline FRotator Clamp() {
		FRotator result = get();
		if (result.Pitch > 180)
			result.Pitch -= 360;
		else if (result.Pitch < -180)
			result.Pitch += 360;
		if (result.Yaw > 180)
			result.Yaw -= 360;
		else if (result.Yaw < -180)
			result.Yaw += 360;
		if (result.Pitch < -89)
			result.Pitch = -89;
		if (result.Pitch > 89)
			result.Pitch = 89;
		while (result.Yaw < -180.0f)
			result.Yaw += 360.0f;
		while (result.Yaw > 180.0f)
			result.Yaw -= 360.0f;

		result.Roll = 0;
		return result;

	}
	double Length() {
		return sqrt(Pitch * Pitch + Yaw * Yaw + Roll * Roll);
	}

	FRotator operator+(FRotator angB) { return FRotator(Pitch + angB.Pitch, Yaw + angB.Yaw, Roll + angB.Roll); }
	FRotator operator-(FRotator angB) { return FRotator(Pitch - angB.Pitch, Yaw - angB.Yaw, Roll - angB.Roll); }
	FRotator operator/(float flNum) { return FRotator(Pitch / flNum, Yaw / flNum, Roll / flNum); }
	FRotator operator*(float flNum) { return FRotator(Pitch * flNum, Yaw * flNum, Roll * flNum); }
	bool operator==(FRotator angB) { return Pitch == angB.Pitch && Yaw == angB.Yaw && Yaw == angB.Yaw; }
	bool operator!=(FRotator angB) { return Pitch != angB.Pitch || Yaw != angB.Yaw || Yaw != angB.Yaw; }

};


FRotator Rotator(FQuat* F)
{
	const double SingularityTest = F->z * F->x - F->w * F->y;
	const double YawY = 2.f * (F->w * F->z + F->x * F->y);
	const double YawX = (1.f - 2.f * ((F->y * F->y) + (F->z * F->z)));

	const double SINGULARITY_THRESHOLD = 0.4999995f;
	const double RAD_TO_DEG = 57.295776;
	double Pitch, Yaw, Roll;

	if (SingularityTest < -SINGULARITY_THRESHOLD)
	{
		Pitch = -90.f;
		Yaw = (Atan2(YawY, YawX) * RAD_TO_DEG);
		Roll = NormalizeAxis(-Yaw - (2.f * Atan2(F->x, F->w) * RAD_TO_DEG));
	}
	else if (SingularityTest > SINGULARITY_THRESHOLD)
	{
		Pitch = 90.f;
		Yaw = (Atan2(YawY, YawX) * RAD_TO_DEG);
		Roll = NormalizeAxis(Yaw - (2.f * Atan2(F->x, F->w) * RAD_TO_DEG));
	}
	else
	{
		Pitch = (asin(2.f * SingularityTest) * RAD_TO_DEG);
		Yaw = (Atan2(YawY, YawX) * RAD_TO_DEG);
		Roll = (Atan2(-2.f * (F->w * F->x + F->y * F->z), (1.f - 2.f * ((F->x * F->x) + (F->y * F->y)))) * RAD_TO_DEG);
	}

	FRotator RotatorFromQuat = FRotator{ Pitch, Yaw, Roll };
	return RotatorFromQuat;
}
struct CamewaDescwipsion {
	Vector3 Location;
	Vector3 Rotation;
	float FieldOfView;
	char Useless[0x18];
};
CamewaDescwipsion GetViewPoint() {
	char v1; // r8
	CamewaDescwipsion ViewPoint = ReadBizzy<CamewaDescwipsion>(base_address + 0xEDC66E0); // 0xED57310 = EncryptedViewPoint
	BYTE* v2 = (BYTE*)&ViewPoint;
	int i; // edx
	__int64 result; // rax

	v1 = 0x40;
	for (i = 0; i < 0x40; ++i) {
		*v2 ^= v1;
		result = (unsigned int)(i + 0x17);
		v1 += i + 0x17;
		v2++;
	}

	return ViewPoint;
}


Vector3 ProjectWorldToScreen(Vector3 WorldLocation)
{
	CamewaDescwipsion ViewPoint = GetViewPoint();
	D3DMATRIX tempMatrix = Matrix(ViewPoint.Rotation);
	Vector3 vAxisX = Vector3(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	Vector3 vAxisY = Vector3(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	Vector3 vAxisZ = Vector3(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);
	Vector3 vDelta = WorldLocation - ViewPoint.Location;
	Vector3 vTransformed = Vector3(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));
	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;
	return Vector3((Width / 2.0f) + vTransformed.x * (((Width / 2.0f) / tanf(ViewPoint.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, (Height / 2.0f) - vTransformed.y * (((Width / 2.0f) / tanf(ViewPoint.FieldOfView * (float)M_PI / 360.f))) / vTransformed.z, 0);
}



void DrawStrokeText(int x, int y, const char* str)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);

	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 255, 255)), utf_8_2.c_str());
}


void DrawSkeleton(DWORD_PTR mesh)
{
	Vector3 vHeadBone = GetBoneWithRotation(mesh, 68);
	Vector3 vHip = GetBoneWithRotation(mesh, 7);
	Vector3 vNeck = GetBoneWithRotation(mesh, 67);
	Vector3 vUpperArmLeft = GetBoneWithRotation(mesh, 9);
	Vector3 vUpperArmRight = GetBoneWithRotation(mesh, 38);
	Vector3 vLeftHand = GetBoneWithRotation(mesh, 30);
	Vector3 vRightHand = GetBoneWithRotation(mesh, 58);
	Vector3 vLeftHand1 = GetBoneWithRotation(mesh, 11);
	Vector3 vRightHand1 = GetBoneWithRotation(mesh, 40);
	Vector3 vRightThigh = GetBoneWithRotation(mesh, 78);
	Vector3 vLeftThigh = GetBoneWithRotation(mesh, 71);
	Vector3 vRightCalf = GetBoneWithRotation(mesh, 79);
	Vector3 vLeftCalf = GetBoneWithRotation(mesh, 72);
	Vector3 vLeftFoot = GetBoneWithRotation(mesh, 74);
	Vector3 vRightFoot = GetBoneWithRotation(mesh, 81);
	Vector3 vHeadBoneOut = ProjectWorldToScreen(vHeadBone);
	Vector3 vHipOut = ProjectWorldToScreen(vHip);
	Vector3 vNeckOut = ProjectWorldToScreen(vNeck);
	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(vUpperArmLeft);
	Vector3 vUpperArmRightOut = ProjectWorldToScreen(vUpperArmRight);
	Vector3 vLeftHandOut = ProjectWorldToScreen(vLeftHand);
	Vector3 vRightHandOut = ProjectWorldToScreen(vRightHand);
	Vector3 vLeftHandOut1 = ProjectWorldToScreen(vLeftHand1);
	Vector3 vRightHandOut1 = ProjectWorldToScreen(vRightHand1);
	Vector3 vRightThighOut = ProjectWorldToScreen(vRightThigh);
	Vector3 vLeftThighOut = ProjectWorldToScreen(vLeftThigh);
	Vector3 vRightCalfOut = ProjectWorldToScreen(vRightCalf);
	Vector3 vLeftCalfOut = ProjectWorldToScreen(vLeftCalf);
	Vector3 vLeftFootOut = ProjectWorldToScreen(vLeftFoot);
	Vector3 vRightFootOut = ProjectWorldToScreen(vRightFoot);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vHipOut.x, vHipOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vLeftHandOut1.x, vLeftHandOut1.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vRightHandOut1.x, vRightHandOut1.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightThighOut.x, vRightThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImVec2(vRightThighOut.x, vRightThighOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftFootOut.x, vLeftFootOut.y), ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightFootOut.x, vRightFootOut.y), ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
}

float DrawLobbyText(ImFont* pFont, const std::string& text, float size, ImU32 color, bool center)
{
	std::stringstream stream(text);
	std::string line;

	float y = 0.0f;
	int i = 0;

	while (std::getline(stream, line))
	{
		ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());

		if (center)
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((textSize.x / 2.0f) + 1, (textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((textSize.x / 2.0f) - 1, (textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((textSize.x / 2.0f) + 1, (textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((textSize.x / 2.0f) - 1, (textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());

			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(textSize.x / 2.0f, textSize.y * i), ImGui::GetColorU32(color), line.c_str());
		}
		else
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(+1, (textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(-1, (textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(+1, (textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(-1, (textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());


		}

		y = +textSize.y * (i + 1);
		i++;
	}
	return y;
}


float DrawOutlinedText(ImFont* pFont, const std::string& text, const ImVec2& pos, float size, ImU32 color, bool center)
{
	std::stringstream stream(text);
	std::string line;

	float y = 0.0f;
	int i = 0;

	while (std::getline(stream, line))
	{
		ImVec2 textSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, line.c_str());

		if (center)
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x - textSize.x / 2.0f) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());

			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x - textSize.x / 2.0f, pos.y + textSize.y * i), ImGui::GetColorU32(color), line.c_str());
		}
		else
		{
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) + 1, (pos.y + textSize.y * i) - 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());
			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((pos.x) - 1, (pos.y + textSize.y * i) + 1), ImGui::GetColorU32(ImVec4(0, 0, 0, 255)), line.c_str());

			ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(pos.x, pos.y + textSize.y * i), ImGui::GetColorU32(color), line.c_str());
		}

		y = pos.y + textSize.y * (i + 1);
		i++;
	}
	return y;
}

void DrawText1(int x, int y, const char* str, RGBA* color)
{
	ImFont a;
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
}

void DrawLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), thickness);
}

void LobbyLine(int x1, int y1, int x2, int y2, RGBA* color, int thickness)
{
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(959, 1100), ImVec2(960, 540), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 000.0, color->B / 000.0, color->A / 255.0)), 1.0f);
}

void LobbyBox(float X, float Y, float W, float H, RGBA* color)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(815 + 1, 967 + 1), ImVec2(((830 + 275) - 1), ((851 - 625) - 1)), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
	//ImGui::GetOverlayDrawList()->AddRect(ImVec2(150, 60), ImVec2(150 + 63, 60 + 125), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
}

void DrawCircle(int x, int y, int radius, RGBA* color, int segments)
{
	ImGui::GetOverlayDrawList()->AddCircle(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), segments);
}
void DrawBox(float X, float Y, float W, float H, ImU32 Col)
{
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(X + 1, Y + 1), ImVec2(((X + W) - 1), ((Y + H) - 1)), Col);
	ImGui::GetOverlayDrawList()->AddRect(ImVec2(X, Y), ImVec2(X + W, Y + H), Col);
}
void DrawFilledRect(int x, int y, int w, int h, ImU32 color)
{
	ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0);
}
void DrawNormalBox(int x, int y, int w, int h, int borderPx, ImU32 color)
{

	DrawFilledRect(x + borderPx, y, w, borderPx, color); //top 
	DrawFilledRect(x + w - w + borderPx, y, w, borderPx, color); //top 
	DrawFilledRect(x, y, borderPx, h, color); //left 
	DrawFilledRect(x, y + h - h + borderPx * 2, borderPx, h, color); //left 
	DrawFilledRect(x + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawFilledRect(x + w - w + borderPx, y + h + borderPx, w, borderPx, color); //bottom 
	DrawFilledRect(x + w + borderPx, y, borderPx, h, color);//right 
	DrawFilledRect(x + w + borderPx, y + h - h + borderPx * 2, borderPx, h, color);//right 
}
void DrawCorneredBox(int X, int Y, int W, int H, const ImU32& color, int thickness) {
	float lineW = (W / 3);
	float lineH = (H / 3);

	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);

	//corners
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}
void DrawBox(int X, int Y, int W, int H, const ImU32& color, int thickness) {
	float lineW = (W / 1);
	float lineH = (H / 1);
	ImDrawList* Drawlist = ImGui::GetOverlayDrawList();
	//black outlines
	Drawlist->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	Drawlist->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	Drawlist->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	Drawlist->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	Drawlist->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	Drawlist->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	Drawlist->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);
	Drawlist->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), 3);

	//corners
	Drawlist->AddLine(ImVec2(X, Y), ImVec2(X, Y + lineH), ImGui::GetColorU32(color), thickness);
	Drawlist->AddLine(ImVec2(X, Y), ImVec2(X + lineW, Y), ImGui::GetColorU32(color), thickness);
	Drawlist->AddLine(ImVec2(X + W - lineW, Y), ImVec2(X + W, Y), ImGui::GetColorU32(color), thickness);
	Drawlist->AddLine(ImVec2(X + W, Y), ImVec2(X + W, Y + lineH), ImGui::GetColorU32(color), thickness);
	Drawlist->AddLine(ImVec2(X, Y + H - lineH), ImVec2(X, Y + H), ImGui::GetColorU32(color), thickness);
	Drawlist->AddLine(ImVec2(X, Y + H), ImVec2(X + lineW, Y + H), ImGui::GetColorU32(color), thickness);
	Drawlist->AddLine(ImVec2(X + W - lineW, Y + H), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
	Drawlist->AddLine(ImVec2(X + W, Y + H - lineH), ImVec2(X + W, Y + H), ImGui::GetColorU32(color), thickness);
}



typedef struct _FNlEntity
{
	uint64_t Actor;
	int ID;
	uint64_t mesh;
}FNlEntity;

std::vector<FNlEntity> entityList;


struct HandleDisposer
{
	using pointer = HANDLE;
	void operator()(HANDLE handle) const
	{
		if (handle != NULL || handle != INVALID_HANDLE_VALUE)
		{
			CloseHandle(handle);
		}
	}
};
using unique_handle = std::unique_ptr<HANDLE, HandleDisposer>;
void clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

static std::uint32_t _GetProcessId(std::string process_name) {
	PROCESSENTRY32 processentry;
	const unique_handle snapshot_handle(CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0));

	if (snapshot_handle.get() == INVALID_HANDLE_VALUE)
		return 0;

	processentry.dwSize = sizeof(MODULEENTRY32);

	while (Process32Next(snapshot_handle.get(), &processentry) == TRUE) {
		if (process_name.compare(processentry.szExeFile) == 0)
			return processentry.th32ProcessID;
	}
	return 0;
}
// random standard header




DWORD Menuthread(LPVOID in)
{
	while (1)
	{
		if (MouseController::GetAsyncKeyState(VK_INSERT) & 1) {
			ShowMenu = !ShowMenu;
		}
		Sleep(1);
	}
}
using namespace std;

std::string random_string(std::string::size_type length)
{
	static auto& chrs = "0123456789"
		"abcdefghijklmnopqrstuvwxyz"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#%^&*()";

	thread_local static std::mt19937 rg{ std::random_device{}() };
	thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

	std::string s;

	s.reserve(length);

	while (length--)
		s += chrs[pick(rg)];

	return s + ".exe";
}
std::string path()
{
	char shitter[_MAX_PATH]; // defining the path
	GetModuleFileNameA(NULL, shitter, _MAX_PATH); // getting the path
	return std::string(shitter); //returning the path
}
void rndmTitle()
{
	constexpr int length = 25;
	const auto characters = TEXT("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	TCHAR title[length + 1]{};

	for (int j = 0; j != length; j++)
	{
		title[j] += characters[rand() % 55 + 1];
	}

	SetConsoleTitle(title);
}
struct slowly_printing_string {
	std::string data;
	long int delay;
};
std::ostream& operator<<(std::ostream& out, const slowly_printing_string& s) {
	for (const auto& c : s.data) {
		out << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(s.delay));
	}
	return out;
}

using namespace std;

//int Authenticator()
//{
//	KeyAuthApp.init();
//
//	if (!KeyAuthApp.data.success)
//	{
//		std::cout << termcolor::red << E("\n Status: ") << KeyAuthApp.data.message;
//		Sleep(5000);
//		exit(0);
//	}
//
//	if (KeyAuthApp.checkblack()) {
//		system(E("cls"));
//		std::cout << termcolor::red << E("\n You're banned from the cheat, contact us if you think can be an error.");
//		Sleep(5000);
//		abort();
//	}
//
//	KeyAuthApp.check();
//
//
//	if (std::filesystem::exists("key.json")) //change test.txt to the path of your file :smile:
//	{
//		if (!CheckIfJsonKeyExists("key.json", "username"))
//		{
//			std::string key = ReadFromJson("key.json", "license");
//			KeyAuthApp.license(key);
//			if (!KeyAuthApp.data.success)
//			{
//				std::remove("key.json");
//				std::cout << termcolor::red << E("\n Status: ") << KeyAuthApp.data.message;
//				Sleep(5000);
//				exit(0);
//			}
//		}
//		else
//		{
//			std::string username = ReadFromJson("key.json", "username");
//			std::string password = ReadFromJson("key.json", "password");
//			KeyAuthApp.login(username, password);
//			if (!KeyAuthApp.data.success)
//			{
//				std::remove("key.json");
//				std::cout << termcolor::red << E("\n Status: ") << KeyAuthApp.data.message;
//				Sleep(5000);
//				exit(0);
//			}
//		}
//	}
//	else
//	{
//		std::string username;
//		std::string password;
//		std::string key;
//		std::cout << termcolor::yellow << E("\n Enter license: ");
//		std::cin >> key;
//		KeyAuthApp.license(key);
//		std::cout << termcolor::white;
//
//		system(E("cls"));
//
//		if (!KeyAuthApp.data.success)
//		{
//			std::cout << termcolor::red << E("\n Status: ") << KeyAuthApp.data.message;
//			Sleep(5000);
//			exit(0);
//		}
//
//		if (username.empty() || password.empty())
//		{
//			WriteToJson("key.json", "license", key, false, "", "");
//		}
//	}
//
//
//	std::cout << termcolor::yellow << E("\n User data:");
//	std::cout << E("\n Key: ") << KeyAuthApp.data.username;
//	std::cout << E("\n Subscription(s):");
//	std::cout << E("\n ");
//	for (int i = 0; i < KeyAuthApp.data.subscriptions.size(); i++) {
//		auto sub = KeyAuthApp.data.subscriptions.at(i);
//		std::cout << E("Key expiry: ") << tm_to_readable_time(timet_to_tm(string_to_timet(sub.expiry))) << termcolor::white;
//		Sleep(5000);
//	}
//
//	return 0;
//}
void load_Driver() {
menu_:
	int choice;
	system("color 3");

	Sleep(500);
	system("cls");





	Sleep(4500);
	printf((" [1] Load Cheat\n [2] Load Driver\n\n > "));
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		break;

	case 2:
		system(("cls"));
// THESE DRIVERS ARE UD ON BE AS OF 8-12-23
		// SEMI UD ON EAC
		system(E("curl https://cdn.discordapp.com/attachments/1136129388245680138/1140002464209305792/driver.sys --output C:\\Windows\\System32\\driver.sys >nul 2>&1"));
		system(E("curl https://cdn.discordapp.com/attachments/1136129388245680138/1136826273184882728/subzero_mapper.exe --output C:\\Windows\\System32\\mapper.exe >nul 2>&1"));
		system(E("C:\\Windows\\System32\\mapper.exe C:\\Windows\\System32\\driver.sys"));
		std::remove(E("C:\\Windows\\System32\\driver.sys"));
		std::remove(E("C:\\Windows\\System32\\mapper.exe"));
		system(E("cls"));
		MessageBoxA(NULL, "Loaded", "dsc.gg/subzerofn", MB_OK);
		goto menu_;
		break;
	}

}
//void InitOverlay()
//{
//	while (hwnd == NULL)
//	{
//		hwnd = FindWindowA(0, "Fortnite  ");
//		//		hwnd = FindWindowA(0, wind.decrypt());
//		Sleep(100);
//	}
//
//	Sleep(3000);
//	system("cls");
//	processID = _GetProcessId("FortniteClient-Win64-Shipping.exe");
//
//	if (driver->Init(FALSE)) {
//		driver->Attach(processID);
//		base_address = driver->GetModuleBase(L"FortniteClient-Win64-Shipping.exe");
//	};
//    xCreateWindow();
//	xInitD3d();
//
//    xMainLoop();
//    xShutdown();
//
//}
//int main()
//{
//	int choice;
//	system("color 3");
//
//	Sleep(500);
//	system("cls");
//	SetConsoleTitleA(random_string(30).c_str());
//
//
//
//
//	Sleep(4500);
//	printf((" [1] Load Cheat w/ Driver\n [2] Load Cheat w/o Driver\n\n > "));
//	std::cin >> choice;
//	switch (choice)
//	{
//	case 2:
//		system("cls");
//		Sleep(4000);
//		cout << "\n					Waiting for Fortnite... \n";
//		break;
//
//	case 1:
//
//		system(("cls"));
//		system(E("curl https://cdn.discordapp.com/attachments/1128731514591510610/1128735128248647680/driver.sys --output C:\\Windows\\System32\\driver.sys >nul 2>&1"));
//		system(E("curl https://cdn.discordapp.com/attachments/1128731514591510610/1128735128680669317/mapper.exe --output C:\\Windows\\System32\\mapper.exe >nul 2>&1"));
//		system(E("C:\\Windows\\System32\\mapper.exe C:\\Windows\\System32\\driver.sys"));
//		std::remove(E("C:\\Windows\\System32\\driver.sys"));
//		std::remove(E("C:\\Windows\\System32\\mapper.exe"));
//		system(E("cls"));
//		cout << "\n					Loaded Driver! \n";
//		Sleep(4000);
//		system("cls");
//		cout << "\n					Waiting for Fortnite... \n";
//		break;
//
//
//
//	InitOverlay();
//
//}
int main(int argc, const char* argv[])

{


	system("cls");
	HANDLE hpStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	MouseController::Init();

	CreateThread(NULL, NULL, Menuthread, NULL, NULL, NULL);
	SetConsoleTitleA("PASTERX UPDATED BY PAYSON HOLMES | DSC.GG/SUBZEROFN");
	


	//printf((" [1] Load Cheat\n [2] Load Driver\n\n > "));
	load_Driver();
	Sleep(2000);



	system("cls");

	//Authenticator();

	system("cls");

	//std::cout << termcolor::green << slowly_printing_string{ "\n\n Loading Cheat...", 50 };	Sleep(3000);
	//std::cout << termcolor::white;

	system("cls");

	ShowWindow(GetConsoleWindow(), SW_HIDE);

	

	ShowWindow(GetConsoleWindow(), SW_SHOW);


	/*std::cout << termcolor::green << "\n\n Open Fortnite and press F5 on main lobby";
	std::cout << termcolor::white;
	while (true)
	{
		Sleep(10);
		if (GetAsyncKeyState(VK_F5))
		{
			break;
		}
	}*/
	system("cls");
	//Beep(500, 500);

	ShowWindow(GetConsoleWindow(), SW_HIDE);
	while (hwnd == NULL)
	{
		XorS(wind, "Fortnite  ");
		hwnd = FindWindowA(0, wind.decrypt());
		Sleep(100);
	}

	processID = _GetProcessId("FortniteClient-Win64-Shipping.exe");

	if (driver->Init(FALSE)) {
		driver->Attach(processID);
		base_address = driver->GetModuleBase(L"FortniteClient-Win64-Shipping.exe");
	};
	xCreateWindow();
	xInitD3d();

	xMainLoop();
	xShutdown();

	return 0;
}



void SetWindowToTarget()
{
	while (true)
	{
		if (hwnd)
		{
			ZeroMemory(&GameRect, sizeof(GameRect));
			GetWindowRect(hwnd, &GameRect);
			Width = GameRect.right - GameRect.left;
			Height = GameRect.bottom - GameRect.top;
			DWORD dwStyle = GetWindowLong(hwnd, GWL_STYLE);

			if (dwStyle & WS_BORDER)
			{
				GameRect.top += 32;
				Height -= 39;
			}
			ScreenCenterX = Width / 2;
			ScreenCenterY = Height / 2;
			MoveWindow(Window, GameRect.left, GameRect.top, Width, Height, true);
		}
		else
		{
			exit(0);
		}
	}
}



const MARGINS Margin = { -1 };

void xCreateWindow()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)SetWindowToTarget, 0, 0, 0);

	WNDCLASS windowClass = { 0 };
	windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hInstance = NULL;
	windowClass.lpfnWndProc = WinProc;
	windowClass.lpszClassName = "notepad";
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	if (!RegisterClass(&windowClass))
		std::cout << "\n\n notepad";

	Window = CreateWindow("notepad",
		NULL,
		WS_POPUP,
		0,
		0,
		GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN),
		NULL,
		NULL,
		NULL,
		NULL);

	ShowWindow(Window, SW_SHOW);

	DwmExtendFrameIntoClientArea(Window, &Margin);
	SetWindowLong(Window, GWL_EXSTYLE, WS_EX_TRANSPARENT | WS_EX_TOOLWINDOW | WS_EX_LAYERED);
	UpdateWindow(Window);
}

void restartpc() //reiniciar pc
{
	system(E("shutdown /r /t 0"));
}

bool isProcessRunning(const WCHAR* processName) {
	bool exists = false;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32W processEntry;
	processEntry.dwSize = sizeof(PROCESSENTRY32W);
	if (Process32FirstW(hSnapshot, &processEntry)) {
		do {
			if (_wcsicmp(processEntry.szExeFile, processName) == 0) {
				exists = true;
				break;
			}
		} while (Process32NextW(hSnapshot, &processEntry));
	}
	CloseHandle(hSnapshot);
	return exists;
}

//void checkProcesses() {
//	const WCHAR* processNames[] = { L"idaq.exe", L"idaq64.exe", L"Wireshark.exe", L"KsDumper.exe", L"x64dbg.exe", L"IDA.exe", L"OllyDbg" };
//	const int numProcesses = sizeof(processNames) / sizeof(processNames[0]);
//	while (true) {
//		for (int i = 0; i < numProcesses; i++) {
//			if (isProcessRunning(processNames[i])) {
//				char message[100];
//				sprintf_s(message, sizeof(message), "Tried to crack the cheat. Process %ls is running", processNames[i]);
//				KeyAuthApp.ban(message);
//				Sleep(3000);
//				restartpc();
//			}
//		}
//		Sleep(1000);
//	}
//}

void xInitD3d()
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &p_Object)))
		exit(3);

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = Width;
	d3dpp.BackBufferHeight = Height;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.hDeviceWindow = Window;
	d3dpp.Windowed = TRUE;

	p_Object->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &D3dDevice);

	IMGUI_CHECKVERSION();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImGui_ImplWin32_Init(Window);
	ImGui_ImplDX9_Init(D3dDevice);

	ImGui::StyleColorsClassic();
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowMinSize = ImVec2(400, 420);
	style->WindowBorderSize = 0;

	style->ChildRounding = 0;
	style->FrameRounding = 0;
	style->ScrollbarRounding = 0;
	style->GrabRounding = 0;
	style->PopupRounding = 0;
	style->WindowRounding = 0;


	style->Colors[ImGuiCol_WindowBg] = ImColor(30, 30, 30, 255);
	style->Colors[ImGuiCol_Border] = ImColor(30, 30, 30, 255);
	style->Colors[ImGuiCol_FrameBg] = ImColor(50, 50, 50, 255);
	style->Colors[ImGuiCol_FrameBgHovered] = ImColor(50, 50, 50, 255);
	style->Colors[ImGuiCol_FrameBgActive] = ImColor(90, 90, 90, 255);
	style->Colors[ImGuiCol_CheckMark] = ImColor(3, 24, 252, 255);
	style->Colors[ImGuiCol_SliderGrab] = ImColor(3, 24, 252, 255);
	style->Colors[ImGuiCol_SliderGrabActive] = ImColor(3, 24, 252, 255);
	style->Colors[ImGuiCol_Button] = ImColor(3, 24, 252, 255);
	style->Colors[ImGuiCol_ButtonHovered] = ImColor(70, 70, 70, 255);
	style->Colors[ImGuiCol_ButtonActive] = ImColor(90, 90, 90, 255);
	style->Colors[ImGuiCol_Separator] = ImColor(89, 3, 247, 255);
	style->Colors[ImGuiCol_TitleBg] = ImColor(3, 24, 252);
	style->Colors[ImGuiCol_TitleBgActive] = ImColor(3, 24, 252);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(3, 24, 252);

	style->WindowTitleAlign.x = 0.50f;


	XorS(font, "C:\\Windows\\Fonts\\Impact.ttf");
	m_pFont = io.Fonts->AddFontFromFileTTF(font.decrypt(), 14.0f, nullptr, io.Fonts->GetGlyphRangesDefault());

	p_Object->Release();
}

void aimbot(float x, float y)
{
	float ScreenCenterX = (Width / 2);
	float ScreenCenterY = (Height / 2);
	int AimSpeed = smooth;
	float TargetX = 0;
	float TargetY = 0;

	if (x != 0)
	{
		if (x > ScreenCenterX)
		{
			TargetX = -(ScreenCenterX - x);
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
		}

		if (x < ScreenCenterX)
		{
			TargetX = x - ScreenCenterX;
			TargetX /= AimSpeed;
			if (TargetX + ScreenCenterX < 0) TargetX = 0;
		}
	}

	if (y != 0)
	{
		if (y > ScreenCenterY)
		{
			TargetY = -(ScreenCenterY - y);
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
		}

		if (y < ScreenCenterY)
		{
			TargetY = y - ScreenCenterY;
			TargetY = y - ScreenCenterY;
			TargetY /= AimSpeed;
			if (TargetY + ScreenCenterY < 0) TargetY = 0;
		}
	}

	//WriteAngles(TargetX / 3.5f, TargetY / 3.5f);
	mouse_event(MOUSEEVENTF_MOVE, static_cast<DWORD>(TargetX), static_cast<DWORD>(TargetY), NULL, NULL);

	return;
}

/*void aimbot() {
	if (!TargetPawn) return;

	auto mesh = read<uintptr_t>(TargetPawn + 0x310);
	if (!mesh) {
		ClosestDistance = FLT_MAX;
		TargetPawn = NULL;
	}
	Vector3 Head3D = SDK::GetBoneWithRotation(mesh, 68);
	Vector2 Head2D = SDK::ProjectWorldToScreen(Head3D);

	auto dx = Head2D.x - (Width / 2);
	auto dy = Head2D.y - (Height / 2);
	auto dz = 0;
	auto dist = sqrtf(dx * dx + dy * dy) / 100.0f;

	if (dist < FovSize && dist <= ClosestDistance) {

		if (Head2D.x != 0 || Head2D.y != 0) {

			if ((Util::GetCrossDistance(Head2D.x, Head2D.y, Width / 2, Height / 2) <= FovSize)) {
				float x = Head2D.x; float y = Head2D.y;
				float ScreenCenterX = (Width / 2);
				float ScreenCenterY = (Height / 2);

				float AimSpeed = Smooth;

				float TargetX = 0;
				float TargetY = 0;

				if (x != 0)
				{
					if (x > ScreenCenterX)
					{
						TargetX = -(ScreenCenterX - x);
						TargetX /= AimSpeed;
						if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;
					}

					if (x < ScreenCenterX)
					{
						TargetX = x - ScreenCenterX;
						TargetX /= AimSpeed;
						if (TargetX + ScreenCenterX < 0) TargetX = 0;
					}
				}
				if (y != 0)
				{
					if (y > ScreenCenterY)
					{
						TargetY = -(ScreenCenterY - y);
						TargetY /= AimSpeed;
						if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;
					}

					if (y < ScreenCenterY)
					{
						TargetY = y - ScreenCenterY;
						TargetY /= AimSpeed;
						if (TargetY + ScreenCenterY < 0) TargetY = 0;
					}
				}

				mouse_event(MOUSEEVENTF_MOVE, TargetX, TargetY, NULL, NULL);

			}
			else {
				bIsTargeting = false;
			}
		}
		else {
			bIsTargeting = false;
		}
	}
	else {
		ClosestDistance = FLT_MAX;
		TargetPawn = NULL;
		bIsTargeting = false;
	}


}*/
bool isVisible(uint64_t mesh)
{
	float bing = ReadBizzy<float>(mesh + 0x360);
	float bong = ReadBizzy<float>(mesh + 0x368);
	const float tick = 0.06f;
	return bong + tick >= bing;
}
void AimAt(DWORD_PTR entity)
{
	uint64_t currentactormesh = ReadBizzy<uint64_t>(entity + OFFSETS::Mesh);
	auto rootHead = GetBoneWithRotation(currentactormesh, hitbox);
	Vector3 rootHeadOut = ProjectWorldToScreen(rootHead);

	if (rootHeadOut.y != 0 || rootHeadOut.y != 0)
	{
		aimbot(rootHeadOut.x, rootHeadOut.y);
	}
}
void DrawSkeleton1337(DWORD_PTR mesh)
{
	Vector3 vHeadBone = GetBoneWithRotation(mesh, 68);
	Vector3 vHip = GetBoneWithRotation(mesh, 7);
	Vector3 vNeck = GetBoneWithRotation(mesh, 67);
	Vector3 vUpperArmLeft = GetBoneWithRotation(mesh, 9);
	Vector3 vUpperArmRight = GetBoneWithRotation(mesh, 38);
	Vector3 vLeftHand = GetBoneWithRotation(mesh, 30);
	Vector3 vRightHand = GetBoneWithRotation(mesh, 58);
	Vector3 vLeftHand1 = GetBoneWithRotation(mesh, 11);
	Vector3 vRightHand1 = GetBoneWithRotation(mesh, 40);
	Vector3 vRightThigh = GetBoneWithRotation(mesh, 78);
	Vector3 vLeftThigh = GetBoneWithRotation(mesh, 71);
	Vector3 vRightCalf = GetBoneWithRotation(mesh, 79);
	Vector3 vLeftCalf = GetBoneWithRotation(mesh, 72);
	Vector3 vLeftFoot = GetBoneWithRotation(mesh, 74);
	Vector3 vRightFoot = GetBoneWithRotation(mesh, 81);
	Vector3 vHeadBoneOut = ProjectWorldToScreen(vHeadBone);
	Vector3 vHipOut = ProjectWorldToScreen(vHip);
	Vector3 vNeckOut = ProjectWorldToScreen(vNeck);
	Vector3 vUpperArmLeftOut = ProjectWorldToScreen(vUpperArmLeft);
	Vector3 vUpperArmRightOut = ProjectWorldToScreen(vUpperArmRight);
	Vector3 vLeftHandOut = ProjectWorldToScreen(vLeftHand);
	Vector3 vRightHandOut = ProjectWorldToScreen(vRightHand);
	Vector3 vLeftHandOut1 = ProjectWorldToScreen(vLeftHand1);
	Vector3 vRightHandOut1 = ProjectWorldToScreen(vRightHand1);
	Vector3 vRightThighOut = ProjectWorldToScreen(vRightThigh);
	Vector3 vLeftThighOut = ProjectWorldToScreen(vLeftThigh);
	Vector3 vRightCalfOut = ProjectWorldToScreen(vRightCalf);
	Vector3 vLeftCalfOut = ProjectWorldToScreen(vLeftCalf);
	Vector3 vLeftFootOut = ProjectWorldToScreen(vLeftFoot);
	Vector3 vRightFootOut = ProjectWorldToScreen(vRightFoot);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vHipOut.x, vHipOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImVec2(vNeckOut.x, vNeckOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vUpperArmLeftOut.x, vUpperArmLeftOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vUpperArmRightOut.x, vUpperArmRightOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftHandOut.x, vLeftHandOut.y), ImVec2(vLeftHandOut1.x, vLeftHandOut1.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightHandOut.x, vRightHandOut.y), ImVec2(vRightHandOut1.x, vRightHandOut1.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightThighOut.x, vRightThighOut.y), ImVec2(vHipOut.x, vHipOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImVec2(vLeftThighOut.x, vLeftThighOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImVec2(vRightThighOut.x, vRightThighOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vLeftFootOut.x, vLeftFootOut.y), ImVec2(vLeftCalfOut.x, vLeftCalfOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
	ImGui::GetOverlayDrawList()->AddLine(ImVec2(vRightFootOut.x, vRightFootOut.y), ImVec2(vRightCalfOut.x, vRightCalfOut.y), ImColor(0.92f, 0.10f, 0.14f), 2.0f);
}
static auto DrawCircleFilled(int x, int y, int radius, RGBA* color) -> void
{
	ImGui::GetOverlayDrawList()->AddCircleFilled(ImVec2(x, y), radius, ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)));
}
namespace cumera
{
	Vector3 Location;
};
double GetCrossDistance(double x1, double y1, double x2, double y2) {
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
void OutlinedText(int x, int y, ImColor Color, const char* text)
{
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x - 1, y), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y - 1), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImColor(0, 0, 0), text);
	ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), Color, text);
}


float crosshairchick[3] = { ImColor(232, 255, 47) };
float crosshaircolor[3] = { ImColor(232, 255, 47) };
void DrawESP() {

	static const auto size = ImGui::GetIO().DisplaySize;
	static const auto center = ImVec2(size.x / 2, size.y / 2);

	if (square_fov) {
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(ScreenCenterX - AimFOV, ScreenCenterY - AimFOV), ImVec2(ScreenCenterX + AimFOV, ScreenCenterY + AimFOV), IM_COL32(255, 255, 255, 255), 1.5f);
		bool fovcircle = false;
		bool  fovcirclefilled = false;
	}
	if (fovcircle) {
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(AimFOV), ImColor(255, 255, 255, 255), 100.0f, 1.5f);
		bool square_fov = false;
		bool fovcircle = false;
		bool  fovcirclefilled = false;
	}
	if (fovcirclefilled) {
		ImGui::GetOverlayDrawList()->AddCircle(ImVec2(ScreenCenterX, ScreenCenterY), float(AimFOV), ImColor(255, 255, 255, 255), 100.0f, 1.5f);
		ImGui::GetOverlayDrawList()->AddCircleFilled(center, AimFOV, ImColor(0, 0, 0, 110), 100);
	}

	if (hitboxpos == 0)
	{
		hitbox = 68; //head
	}
	else if (hitboxpos == 1)
	{
		hitbox = 67; //neck
	}
	else if (hitboxpos == 2)
	{
		hitbox = 36; //chest
	}
	else if (hitboxpos == 3)
	{
		hitbox = 2; //pelvis
	}

	if (aimkeypos == 0)
	{
		aimkey = 0x01;//left mouse button
	}
	else if (aimkeypos == 1)
	{
		aimkey = 0x02;//right mouse button
	}
	else if (aimkeypos == 2)
	{
		aimkey = 0x04;//middle mouse button
	}
	else if (aimkeypos == 3)
	{
		aimkey = 0x05;//x1 mouse button
	}
	else if (aimkeypos == 4)
	{
		aimkey = 0x06;//x2 mouse button
	}
	else if (aimkeypos == 5)
	{
		aimkey = 0x03;//control break processing
	}
	else if (aimkeypos == 6)
	{
		aimkey = 0x08;//backspace
	}
	else if (aimkeypos == 7)
	{
		aimkey = 0x09;//tab
	}
	else if (aimkeypos == 8)
	{
		aimkey = 0x0c;//clear
	}
	else if (aimkeypos == 9)
	{
		aimkey == 0x0D;//enter
	}
	else if (aimkeypos == 10)
	{
		aimkey = 0x10;//shift
	}
	else if (aimkeypos == 11)
	{
		aimkey = 0x11;//ctrl
	}
	else if (aimkeypos == 12)
	{
		aimkey == 0x12;//alt
	}
	else if (aimkeypos == 13)
	{
		aimkey == 0x14;//caps lock
	}
	else if (aimkeypos == 14)
	{
		aimkey == 0x1B;//esc
	}
	else if (aimkeypos == 15)
	{
		aimkey == 0x20;//space
	}
	else if (aimkeypos == 16)
	{
		aimkey == 0x30;//0
	}
	else if (aimkeypos == 17)
	{
		aimkey == 0x31;//1
	}
	else if (aimkeypos == 18)
	{
		aimkey == 0x32;//2
	}
	else if (aimkeypos == 19)
	{
		aimkey == 0x33;//3
	}
	else if (aimkeypos == 20)
	{
		aimkey == 0x34;//4
	}
	else if (aimkeypos == 21)
	{
		aimkey == 0x35;//5
	}
	else if (aimkeypos == 22)
	{
		aimkey == 0x36;//6
	}
	else if (aimkeypos == 23)
	{
		aimkey == 0x37;//7
	}
	else if (aimkeypos == 24)
	{
		aimkey == 0x38;//8
	}
	else if (aimkeypos == 25)
	{
		aimkey == 0x39;//9
	}
	else if (aimkeypos == 26)
	{
		aimkey == 0x41;//a
	}
	else if (aimkeypos == 27)
	{
		aimkey == 0x42;//b
	}
	else if (aimkeypos == 28)
	{
		aimkey == 0x43;//c
	}
	else if (aimkeypos == 29)
	{
		aimkey == 0x44;//d
	}
	else if (aimkeypos == 30)
	{
		aimkey == 0x45;//e
	}
	else if (aimkeypos == 31)
	{
		aimkey == 0x46;//f
	}
	else if (aimkeypos == 32)
	{
		aimkey == 0x47;//g
	}
	else if (aimkeypos == 33)
	{
		aimkey == 0x48;//h
	}
	else if (aimkeypos == 34)
	{
		aimkey == 0x49;//i
	}
	else if (aimkeypos == 35)
	{
		aimkey == 0x4A;//j
	}
	else if (aimkeypos == 36)
	{
		aimkey == 0x4B;//k
	}
	else if (aimkeypos == 37)
	{
		aimkey == 0x4C;//L
	}
	else if (aimkeypos == 38)
	{
		aimkey == 0x4D;//m
	}
	else if (aimkeypos == 39)
	{
		aimkey == 0x4E;//n
	}
	else if (aimkeypos == 40)
	{
		aimkey == 0x4F;//o
	}
	else if (aimkeypos == 41)
	{
		aimkey == 0x50;//p
	}
	else if (aimkeypos == 42)
	{
		aimkey == 0x51;//q
	}
	else if (aimkeypos == 43)
	{
		aimkey == 0x52;//r
	}
	else if (aimkeypos == 44)
	{
		aimkey == 0x53;//s
	}
	else if (aimkeypos == 45)
	{
		aimkey == 0x54;//t
	}
	else if (aimkeypos == 46)
	{
		aimkey == 0x55;//u
	}
	else if (aimkeypos == 47)
	{
		aimkey == 0x56;//v
	}
	else if (aimkeypos == 48)
	{
		aimkey == 0x57;//w
	}
	else if (aimkeypos == 49)
	{
		aimkey == 0x58;//x
	}
	else if (aimkeypos == 50)
	{
		aimkey == 0x59;//y
	}
	else if (aimkeypos == 51)
	{
		aimkey == 0x5A;//z
	}
	else if (aimkeypos == 52)
	{
		aimkey == 0x60;//numpad 0
	}
	else if (aimkeypos == 53)
	{
		aimkey == 0x61;//numpad 1
	}
	else if (aimkeypos == 54)
	{
		aimkey == 0x62;//numpad 2
	}
	else if (aimkeypos == 55)
	{
		aimkey == 0x63;//numpad 3
	}
	else if (aimkeypos == 56)
	{
		aimkey == 0x64;//numpad 4
	}
	else if (aimkeypos == 57)
	{
		aimkey == 0x65;//numpad 5
	}
	else if (aimkeypos == 58)
	{
		aimkey == 0x66;//numpad 6
	}
	else if (aimkeypos == 59)
	{
		aimkey == 0x67;//numpad 7
	}
	else if (aimkeypos == 60)
	{
		aimkey == 0x68;//numpad 8
	}
	else if (aimkeypos == 61)
	{
		aimkey == 0x69;//numpad 9
	}
	else if (aimkeypos == 62)
	{
		aimkey == 0x6A;//multiply
	}


	auto entityListCopy = entityList;
	float closestDistance = FLT_MAX;
	DWORD_PTR closestPawn = NULL;
	Uworld = ReadBizzy<DWORD_PTR>(base_address + 0xEE9ED98);
	DWORD_PTR Gameinstance = ReadBizzy<DWORD_PTR>(Uworld + OFFSETS::Gameinstance);
	DWORD_PTR LocalPlayers = ReadBizzy<DWORD_PTR>(Gameinstance + OFFSETS::LocalPlayers);
	Localplayer = ReadBizzy<DWORD_PTR>(LocalPlayers);
	PlayerController = ReadBizzy<DWORD_PTR>(Localplayer + OFFSETS::PlayerController);
	LocalPawn = ReadBizzy<DWORD_PTR>(PlayerController + OFFSETS::LocalPawn);
	uintptr_t pcmc = ReadBizzy<uint64_t>(PlayerController + 0x330);
	PlayerState = ReadBizzy<DWORD_PTR>(LocalPawn + OFFSETS::PlayerState);
	DWORD_PTR PlayerCameraManager = ReadBizzy<DWORD_PTR>(PlayerController + OFFSETS::Cameramanager);
	PlayerCameraManager = ReadBizzy<DWORD_PTR>(LocalPawn + PlayerCameraManager);
	Rootcomp = ReadBizzy<DWORD_PTR>(LocalPawn + OFFSETS::RootComponet);
	Persistentlevel = ReadBizzy<DWORD_PTR>(Uworld + OFFSETS::PersistentLevel);
	uintptr_t Crrneytwep = ReadBizzy<uintptr_t>(LocalPawn + 0x868);
	DWORD ActorCount = ReadBizzy<DWORD>(Persistentlevel + OFFSETS::ActorCount);
	DWORD_PTR AOFFSETS = ReadBizzy<DWORD_PTR>(Persistentlevel + OFFSETS::AActor);

	DWORD_PTR GameState = ReadBizzy<DWORD_PTR>(Uworld + OFFSETS::GameState);//gamestate
	DWORD_PTR PlayerArray = ReadBizzy<DWORD_PTR>(GameState + OFFSETS::PlayerArray);//playerarray
	uint64_t CurrentVehicle = ReadBizzy<uint64_t>(LocalPawn + 0x2348); //FortPlayerPawn::CurrentVehicle

	bool InLobby;
	InLobby = false;
	if (LocalPawn) InLobby = true;
	int Num = ReadBizzy<int>(GameState + (OFFSETS::PlayerArray + sizeof(uintptr_t))); //reads the total number of player states in this array

	for (uint32_t i = 0; i < Num; i++)
	{





		auto player = ReadBizzy<uintptr_t>(PlayerArray + i * 0x8);
		auto CurrentActor = ReadBizzy<uintptr_t>(player + OFFSETS::PawnPrivate);//PawnPrivate

		if (!CurrentActor) {
			continue;
			cout << "JOPA";
		}


		if (!LocalPawn)
		{
			VisDist = 2400;
		}
		else
		{
			// Aquí no hacemos ningún cambio en el valor de VisDist para mantenerlo sin cambios
		}
		int NewPlayerLocationX;
		int NewPlayerLocationY;

		//uint64_t CurrentActor = read<uint64_t>(AOFFSETS + i * OFFSETS::CurrentActor);
	   // if (read<float>(CurrentActor + OFFSETS::Revivefromdbnotime) != 10) continue;
		uint64_t CurrentActorMesh = ReadBizzy<uint64_t>(CurrentActor + OFFSETS::Mesh);
		int MyTeamId = ReadBizzy<int>(PlayerState + OFFSETS::TeamId);
		DWORD64 otherPlayerState = ReadBizzy<uint64_t>(CurrentActor + 0x290);
		int ActorTeamId = ReadBizzy<int>(otherPlayerState + OFFSETS::TeamId);
		auto isDBNO = (ReadBizzy<char>(CurrentActor + 0x7c2) >> 4) & 1;

		auto entityListCopy = entityList;
		//if (MyTeamId == ActorTeamId) continue;



		if (slefESP)
		{
			continue;
		}
		else {
			if (CurrentActor == LocalPawn) continue;
		}
		if (CurrentActor == LocalPawn) continue;
		Vector3 Headpos = GetBoneWithRotation(CurrentActorMesh, 67);
		Vector3 head2 = GetBoneWithRotation(CurrentActorMesh, 68);
		Vector3 footpos = GetBoneWithRotation(CurrentActorMesh, 0);
		localactorpos = ReadBizzy<Vector3>(Rootcomp + OFFSETS::relativelocation);
		auto normal_head = ProjectWorldToScreen(Headpos);
		float distance = localactorpos.Distance(Headpos) / ChangerFOV;

		Vector3 bone15 = GetBoneWithRotation(CurrentActorMesh, 50);
		Vector3 top = ProjectWorldToScreen(bone15);

		Vector3 bone0 = GetBoneWithRotation(CurrentActorMesh, 0);
		Vector3 bottom = ProjectWorldToScreen(bone0);
		Vector3 Headbox = ProjectWorldToScreen(Vector3(Headpos.x, Headpos.y, Headpos.z + 15));
		Vector3 HeadElvar = ProjectWorldToScreen(Vector3(Headpos.x, Headpos.y, Headpos.z));
		Vector3 FeetElvar = ProjectWorldToScreen(Vector3(footpos.x, footpos.y, footpos.z));
		//Vector3 Toebox = ProjectWorldToScreen(Vector3(Toepos.x, Toepos.y, Toepos.z + 15));
		Vector3 w2shead = ProjectWorldToScreen(Headpos);

		float BoxHeight = (float)(Headbox.y - bottom.y);
		float BoxWidth = BoxHeight * 0.50f;

		float LeftX = (float)Headbox.x - (BoxWidth / 1);
		float LeftY = (float)bottom.y;

		int center_x = GetSystemMetrics(0) / 2 - 3;
		int center_y = GetSystemMetrics(1) / 2 - 3;






		float CornerHeight = abs(Headbox.y - bottom.y);
		float CornerWidth = CornerHeight * BoxWidthValue;
		if (zekren)
		{
			POINT Screen;
			int oodofdfo, jbjfdbdsf;
			Screen.x = GetSystemMetrics(0);
			Screen.y = GetSystemMetrics(1);
			// Middle POINT
			POINT Middle;
			Middle.x = (int)(Screen.x / 2);
			Middle.y = (int)(Screen.y / 2);
			int a = (int)(Screen.y / 2 / 30);
			float gamma = atan(a / a);
			static int faken_rot = 0;
			faken_rot++;
			int Drehungswinkel = faken_rot;

			int i = 0;
			while (i < 4)
			{
				std::vector<int> p;
				p.push_back(a * sin(GRD_TO_BOG(Drehungswinkel + (i * 90))));                                    // p[0]        p0_A.x
				p.push_back(a * cos(GRD_TO_BOG(Drehungswinkel + (i * 90))));                                    // p[1]        p0_A.y
				p.push_back((a / cos(gamma)) * sin(GRD_TO_BOG(Drehungswinkel + (i * 90) + BOG_TO_GRD(gamma))));    // p[2]        p0_B.x
				p.push_back((a / cos(gamma)) * cos(GRD_TO_BOG(Drehungswinkel + (i * 90) + BOG_TO_GRD(gamma))));    // p[3]        p0_B.y

				// Calculate the hue based on time (you can replace this with any other variable)
				float hue = fmodf(ImGui::GetTime(), 1.0f); // Range from 0.0 to 1.0

				ImU32 lineColor = ImColor::HSV(hue + i * 0.25f, 1.0f, 1.0f); // Radial gradient with rainbow colors
				ImVec2 p0 = ImVec2(Middle.x, Middle.y);
				ImVec2 p1 = ImVec2(Middle.x + p[0], Middle.y - p[1]);
				ImVec2 p2 = ImVec2(Middle.x + p[2], Middle.y - p[3]);

				ImGui::GetOverlayDrawList()->AddLine(p0, p1, lineColor);
				ImGui::GetOverlayDrawList()->AddLine(p1, p2, lineColor);

				i++;
			}
		}

		if (spinbot)
		{
			auto Mesh = ReadBizzy<uint64_t>(LocalPawn + OFFSETS::Mesh);
			static auto Cached = ReadBizzy<Vector3>(Mesh + 0x140);

			if (GetAsyncKeyState(VK_LBUTTON)) {
				WriteBizzy<Vector3>(Mesh + 0x140, Vector3(1, rand() % 361, 1));
			}
			else WriteBizzy<Vector3>(Mesh + 0x140, Cached);
		}
		if (instantreload)
		{
			uintptr_t worldsettings = ReadBizzy<uint64_t>(Persistentlevel + 0x298);
			uintptr_t CurrentWeapon = ReadBizzy<uintptr_t>(LocalPawn + 0x8d8);
			uintptr_t SimcraftsTwoPoint5Hours1 = ReadBizzy<uintptr_t>(CurrentWeapon + 0xc41);
			uintptr_t SimcraftsTwoPoint5Hours2 = ReadBizzy<uintptr_t>(SimcraftsTwoPoint5Hours1 + 0x1678);
			uintptr_t SimcraftsTwoPoint5Hours3 = ReadBizzy<uintptr_t>(SimcraftsTwoPoint5Hours2 + 0x6233);
			uintptr_t SimcraftsTwoPoint5Hours4 = ReadBizzy<uintptr_t>(SimcraftsTwoPoint5Hours3 + 0xc87);
			uintptr_t SimcraftsTwoPoint5Hours5 = ReadBizzy<uintptr_t>(SimcraftsTwoPoint5Hours4 + 0xb39);
			uintptr_t SimcraftsTwoPoint5Hours6 = ReadBizzy<uintptr_t>(SimcraftsTwoPoint5Hours5 + 0x267);
			uintptr_t SimcraftsTwoPoint5Hours7 = ReadBizzy<uintptr_t>(SimcraftsTwoPoint5Hours6 + 0x5cc);
			uintptr_t SimcraftsTwoPoint5Hours8 = ReadBizzy<uintptr_t>(SimcraftsTwoPoint5Hours7 + 0xc82 + 0x8 + 0x18);

			WriteBizzy<char>(SimcraftsTwoPoint5Hours8 + 0x9c8, 0);
			WriteBizzy<float>(SimcraftsTwoPoint5Hours8 + 0x928, 0.01);

			bool cum = ReadBizzy<bool>(CurrentWeapon + 0x329);

			if (cum) {
				WriteBizzy<float>(worldsettings + 0x3C0, 70);
			}
			else {
				WriteBizzy<float>(worldsettings + 0x3C0, 1);
			}

		}

		if (RapidFire) {

				uintptr_t DMR = ReadBizzy<uintptr_t>(base_address + 0x2883A10);
				uintptr_t DMRBuff1 = ReadBizzy<uintptr_t>(DMR + 0xDA);
				uintptr_t DMRBuff2 = ReadBizzy<uintptr_t>(DMRBuff1 + 0x3A);
				uintptr_t DMRBuff3 = ReadBizzy<uintptr_t>(DMRBuff2 + 0x67);
				uintptr_t DMRBuff4 = ReadBizzy<uintptr_t>(DMRBuff3 + 0x26);
				uintptr_t DMRBuff5 = ReadBizzy<uintptr_t>(DMRBuff4 + 0x7EA);

				WriteBizzy<float>(DMRBuff5 + 0x26, 0.003f);//troppo veloce

		}
		if (infammo) {

				uintptr_t CurrentWeapon = ReadBizzy<uintptr_t>(PlayerState + 0x8d8);
				if (CurrentWeapon) {
					WriteBizzy<char>(CurrentWeapon + 0x2628, true);
				}

		}
		if (tpose)
		{
			if (LocalPawn)
			{
				uintptr_t LocalMesh = ReadBizzy<uintptr_t>(LocalPawn + OFFSETS::Mesh);
				WriteBizzy<char>(LocalMesh + 0xa3a, true); //USkeletalMeshComponent	bForceRefpose : 1	0x9aa	char
			}
		}
		if (minigun){
			float TimeHeatWasLastAdded = ReadBizzy<float>(LocalPawn + 0x14d4);
			float TimeOverheatedBegan = ReadBizzy<float>(LocalPawn + 0x14d8);
			float OverheatValue = ReadBizzy<float>(LocalPawn + 0x14cc);
			float WeaponOverheatedAnimation = ReadBizzy<float>(LocalPawn + 0x14c0);
			uintptr_t CurrentWeapon = ReadBizzy<float>(LocalPawn + 0x8d8);

			if (TimeHeatWasLastAdded != 0.f or TimeOverheatedBegan != 0.f or OverheatValue != 0.f or WeaponOverheatedAnimation != 0.f) {
				WriteBizzy<float>(CurrentWeapon + 0x14d4, 0.f);
				WriteBizzy<float>(CurrentWeapon + 0x14d8, 0.f);
				WriteBizzy<float>(CurrentWeapon + 0x14cc, 0.f);
				WriteBizzy<float>(CurrentWeapon + 0x14c0, 0.f);
			}
	}

		if (first_person) {
			if (GetAsyncKeyState(VK_RBUTTON)) {
				if (LocalPawn) {
					uintptr_t Mesh = ReadBizzy<uintptr_t>(LocalPawn + 0x310);
					WriteBizzy<Vector3>(Mesh + 0x158, Vector3(2000, -2000, 2000)); //Class Engine.SceneComponent - RelativeScale3D
				}
			}
			else {
				uintptr_t Mesh = ReadBizzy<uintptr_t>(LocalPawn + 0x310);
				WriteBizzy<Vector3>(Mesh + 0x158, Vector3(0, 0, -87)); //Class Engine.SceneComponent - RelativeScale3D 
			}
		if (carfly)
			{
				uintptr_t CurrentVehicle = ReadBizzy<DWORD_PTR>(LocalPawn + 0x23d8); // CurrentVehicle

				if (CurrentVehicle && GetAsyncKeyState(VK_SPACE))
				{
					WriteBizzy<bool>(CurrentVehicle + 0x6aa, false); // bUseGravity : 1	
				}
				else {
					WriteBizzy<bool>(CurrentVehicle + 0x6aa, true); // bUseGravity : 1	
				}

			}
		}
		//if (bullettp) {
		//	{
		//		if (ReadBizzy<DWORD_PTR>(CurrentActor + 0x6b8) && ReadBizzy<DWORD_PTR>(ReadBizzy<DWORD_PTR>(CurrentActor + 0x6b8) + 0x8)) // Bullet Check, AFortProjectileBase - MaxSpeed - 0x6b8
		//		{
		//			std::string AllAct = ReadGetNameFromFName(CurrentActorId);

		//			if (AllAct == "B_Prj_Bullet_Sniper_C" or AllAct == "B_Prj_Bullet_DMR_C" or AllAct == "B_Prj_Bullet_Sniper_Heavy_C" or AllAct == "B_Prj_Bullet_Cosmos_AR_C")
		//			{
		//				uint64_t currentactormeshsexy = ReadBizzy<uint64_t>(closestPawn + 0x310);
		//				DWORD_PTR BulletRootComp = ReadBizzy<DWORD_PTR>(CurrentActor + 0x190);
		//				Vector3 POS = GetBoneWithRotation(currentactormeshsexy, 66);
		//				Vector3 TPOS = ProjectWorldToScreen(Vector3(POS.x, POS.y, POS.z));

		//				WriteBizzy<char>(BulletRootComp + 0x190, 0);
		//				WriteBizzy<Vector3>(BulletRootComp + 0x128, TPOS);
		//			}
		//		}
		//	}

		//}
		if (fovchanger)
		{


			int FOVVALUE = 500;
			uintptr_t PlayerCameraManager = ReadBizzy<uintptr_t>(PlayerController + 0x340); // APlayerController -  PlayerCameraManager
			WriteBizzy<float>(PlayerCameraManager + 0x29c + 0x4, 500); // APlayerCameraManager - DefaultFOV
			WriteBizzy(PlayerCameraManager + 0x348, 500); // AEmitterCameraLensEffectBase - BaseFOV


		}



		if (distance < VisDist)
		{
			if (Esp)
			{

				if (Esp_box)
				{
					DrawBox(Headbox.x - (CornerWidth / 2), Headbox.y, CornerWidth, CornerHeight, IM_COL32(255, 255, 255, 255), 2.5);

				}
				if (Esp_Skeleton1)
				{
					if (distance < VisDist)
					{
						DrawSkeleton1337(CurrentActorMesh);
						/*Vector3 vHeadBoneOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 68));
						Vector3 vHipOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 7));
						Vector3 vNeckOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 67));
						Vector3 vUpperArmLeftOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 9));
						Vector3 vUpperArmRightOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 38));
						Vector3 vLeftHandOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 30));
						Vector3 vRightHandOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 58));
						Vector3 vLeftHandOut1 = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 11));
						Vector3 vRightHandOut1 = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 40));
						Vector3 vRightThighOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 74));
						Vector3 vLeftThighOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 71));
						Vector3 vRightCalfOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 79));
						Vector3 vLeftCalfOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 72));
						Vector3 vLeftFootOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 74));
						Vector3 vRightFootOut = ProjectWorldToScreen(GetBoneWithRotation(CurrentActorMesh, 81));

						DrawLine(vHipOut.x, vHipOut.y, vNeckOut.x, vNeckOut.y, &Col.red, 2.f);

						DrawLine(vUpperArmLeftOut.x, vUpperArmLeftOut.y, vNeckOut.x, vNeckOut.y, &Col.red, 2.f);
						DrawLine(vUpperArmRightOut.x, vUpperArmRightOut.y, vNeckOut.x, vNeckOut.y, &Col.red, 2.f);

						DrawLine(vLeftHandOut.x, vLeftHandOut.y, vUpperArmLeftOut.x, vUpperArmLeftOut.y, &Col.red, 2.f);
						DrawLine(vRightHandOut.x, vRightHandOut.y, vUpperArmRightOut.x, vUpperArmRightOut.y, &Col.red, 2.f);

						DrawLine(vLeftHandOut.x, vLeftHandOut.y, vLeftHandOut1.x, vLeftHandOut1.y, &Col.red, 2.f);
						DrawLine(vRightHandOut.x, vRightHandOut.y, vRightHandOut1.x, vRightHandOut1.y, &Col.red, 2.f);

						DrawLine(vLeftThighOut.x, vLeftThighOut.y, vHipOut.x, vHipOut.y, &Col.red, 2.f);
						DrawLine(vRightThighOut.x, vRightThighOut.y, vHipOut.x, vHipOut.y, &Col.red, 2.f);

						DrawLine(vLeftCalfOut.x, vLeftCalfOut.y, vLeftThighOut.x, vLeftThighOut.y, &Col.red, 2.f);
						DrawLine(vRightCalfOut.x, vRightCalfOut.y, vRightThighOut.x, vRightThighOut.y, &Col.red, 2.f);

						DrawLine(vLeftFootOut.x, vLeftFootOut.y, vLeftCalfOut.x, vLeftCalfOut.y, &Col.red, 2.f);
						DrawLine(vRightFootOut.x, vRightFootOut.y, vRightCalfOut.x, vRightCalfOut.y, &Col.red, 2.f);*/
						


					}
				}
				if (Skeleton)
				{
					DrawSkeleton(CurrentActorMesh);
				}

				if (lineheadesp)
				{

					DrawLine(Width / 2, Height / 2, HeadElvar.x, HeadElvar.y, &Col.blue, 1.5);
				}

				if (cornerline)
				{
					if (isVisible(CurrentActorMesh)) {
						DrawLine(Width, Height, HeadElvar.x, HeadElvar.y, &Col.green, 1.5);
					}
					if (!isVisible(CurrentActorMesh)) {
						DrawLine(Width, Height, HeadElvar.x, HeadElvar.y, &Col.red, 1.5);
					}
				}

				if (fillbox)
				{
					DrawCorneredBox(HeadElvar.x - (CornerWidth / 2), HeadElvar.y, CornerWidth, CornerHeight, IM_COL32(3, 24, 252, 255), 2.5);
					DrawFilledRect(HeadElvar.x - (CornerWidth / 2), HeadElvar.y, CornerWidth, CornerHeight, IM_COL32(0, 0, 0, 125));
				}

				if (Esp_Distance)
				{


					XorS(dst, "[%.fm]\n");
					char dist[64];
					sprintf_s(dist, dst.decrypt(), distance);
					DrawOutlinedText(m_pFont, dist, ImVec2(Headbox.x, Headbox.y - 35), 16.0f, IM_COL32(56, 122, 675, 255), true);


				}

				if (Esp_line)

				{
					DrawLine(Width / 2, Height, bottom.x, bottom.y, &Col.white, 2.0);

				}
			}
		}
		auto dx = w2shead.x - (Width / 2);
		auto dy = w2shead.y - (Height / 2);
		auto dist = sqrtf(dx * dx + dy * dy);


		if (isVisible(CurrentActorMesh)) {

			if (dist < AimFOV && dist < closestDistance) {
				closestDistance = dist;
				closestPawn = CurrentActor;

			}
		}
	}

	if (Aimbot)
	{

		if (Aimbot && closestPawn && GetAsyncKeyState(hotkeys::aimkey) < 0) {
			AimAt(closestPawn);
		}


	}
	if (crosshair)
	{
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2 - 10, Height / 2), ImGui::GetColorU32({ crosshairchick[0], crosshairchick[1], crosshairchick[2], 2 }));
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2 + 10, Height / 2), ImGui::GetColorU32({ crosshairchick[0], crosshairchick[1], crosshairchick[2], 2 }));
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2, Height / 2 - 10), ImGui::GetColorU32({ crosshairchick[0], crosshairchick[1], crosshairchick[2], 2 }));
		ImGui::GetOverlayDrawList()->AddLine(ImVec2(Width / 2, Height / 2), ImVec2(Width / 2, Height / 2 + 10), ImGui::GetColorU32({ crosshairchick[0], crosshairchick[1], crosshairchick[2], 2 }));
	}
}

void render() {
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	static int maintabs = 0;
	if (GetAsyncKeyState(VK_INSERT) & 1) {
		ShowMenu = !ShowMenu;
	}
	if (ShowMenu)
	{

		ImGui::SetNextWindowSize({ 800, 800 });
		XorS(box_esp, "Box");
		XorS(snapline, "Snapline");
		XorS(es5, "Max Visuals Distance");
		XorS(aim1, "Aimbot");
		XorS(aim2, "Aimbot Key");
		XorS(aim3, "Aimbot Bone");
		XorS(aim6, "Aimbot FOV");
		XorS(smoothh, "Smooth");

		ImGui::Begin(("PasterX | Updated by Payson Holmes | dsc.gg/subzerofn"), 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);

		ImVec2 windowPos = ImGui::GetWindowPos();
		ImVec2 windowSize = ImGui::GetWindowSize();
		ImVec2 buttonSize(20, 20);
		ImVec2 buttonPos(windowPos.x + windowSize.x - buttonSize.x - 5, windowPos.y + 5);
		buttonPos.x += ImGui::GetContentRegionAvail().x - windowSize.x;
		if (ImGui::Button("X", buttonSize))
		{
			exit(0);
		}


		ImGui::BeginChild("##ChildIdentifier", ImVec2(420, 480)/*SIZE OF THE CHILD*/, false /*IF YOU WANT A BORDER OR NOT*/);
		{
			ImGui::Checkbox(aim1.decrypt(), &Aimbot);
			ImGui::SameLine();
			ImGui::Checkbox("Crosshair", &crosshair);
			ImGui::Checkbox("Circle FOV", &fovcircle);
			if (fovcircle)
			{
				square_fov = false;
				fovcirclefilled = false;
			}
			ImGui::SameLine();
			ImGui::Checkbox("Filled Circle FOV", &fovcirclefilled);
			if (fovcirclefilled)
			{
				fovcircle = false;
				square_fov = false;
			}
			//ImGui::SameLine();
			//ImGui::Checkbox("Square FOV", &square_fov);
			if (square_fov)
			{
				fovcirclefilled = false;
				fovcircle = false;
			}
			ImGui::SliderFloat(aim6.decrypt(), &AimFOV, 50.f, 800.f);
			ImGui::SliderFloat("Aimbot Smooth", &smooth, 1, 10);
			ImGui::Spacing();
			ImGui::Text("Aimbot Key");
			HotkeyButton(hotkeys::aimkey, ChangeKey, keystatus);
		}
		ImGui::EndChild();
		ImGui::SameLine();
		ImGui::BeginChild("##ChildIdentifier", ImVec2(750, 500)/*SIZE OF THE CHILD*/, false /*IF YOU WANT A BORDER OR NOT*/);
		{
			ImGui::SliderInt("Esp Distance", &VisDist, 20, 500);
			ImGui::Spacing();
			ImGui::Spacing();
			ImGui::Text("Visuals");
			ImGui::Spacing();
			ImGui::Checkbox("Enable ESP", &Esp);
			ImGui::Checkbox(box_esp.decrypt(), &Esp_box);
			//ImGui::SameLine();
			ImGui::Checkbox("Zekren Mode (Nazi Crosshair)", &zekren);
			ImGui::Checkbox("Distance", &Esp_Distance);
			ImGui::Checkbox("Snaplines", &Esp_line);
			ImGui::Checkbox("Skeleton", &Esp_Skeleton1);
			ImGui::Spacing();
			ImGui::Text("Exploits");
			ImGui::Checkbox("Spinbot", &spinbot);
			//ImGui::Checkbox("Instant Reload", &instantreload);
			ImGui::Checkbox("FOV Changer", &fovchanger);
			//HotkeyButton(hotkeys::fov, ChangeKey, keystatus);
			ImGui::Checkbox("Car Fly", &carfly);
			ImGui::Checkbox("Rapid Fire", &RapidFire);
			ImGui::Checkbox("First Person Mode", &first_person);
			ImGui::Checkbox("infinity ammo", &infammo);

			ImGui::Checkbox("T pose", &tpose);
			ImGui::Checkbox("Minigun", &minigun);
			ImGui::Checkbox("instant reload", &instantreload);

			
		}

		ImGui::EndChild();
		ImGui::End();
	}

	DrawESP();

	ImGui::EndFrame();
	D3dDevice->SetRenderState(D3DRS_ZENABLE, false);
	D3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	D3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	D3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	if (D3dDevice->BeginScene() >= 0)
	{
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		D3dDevice->EndScene();
	}
	HRESULT result = D3dDevice->Present(NULL, NULL, NULL, NULL);

	if (result == D3DERR_DEVICELOST && D3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
	{
		ImGui_ImplDX9_InvalidateDeviceObjects();
		D3dDevice->Reset(&d3dpp);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}

MSG Message = { NULL };
int Loop = 0;
void xMainLoop()
{
	static RECT old_rc;
	ZeroMemory(&Message, sizeof(MSG));

	while (Message.message != WM_QUIT)
	{
		if (PeekMessage(&Message, Window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}

		HWND hwnd_active = GetForegroundWindow();

		if (hwnd_active == hwnd) {
			HWND hwndtest = GetWindow(hwnd_active, GW_HWNDPREV);
			SetWindowPos(Window, hwndtest, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		}

		if (GetAsyncKeyState(0x23) & 1)
			exit(8);

		RECT rc;
		POINT xy;

		ZeroMemory(&rc, sizeof(RECT));
		ZeroMemory(&xy, sizeof(POINT));
		GetClientRect(hwnd, &rc);
		ClientToScreen(hwnd, &xy);
		rc.left = xy.x;
		rc.top = xy.y;

		ImGuiIO& io = ImGui::GetIO();
		io.ImeWindowHandle = hwnd;
		io.DeltaTime = 1.0f / 60.0f;

		POINT p;
		GetCursorPos(&p);
		io.MousePos.x = p.x - xy.x;
		io.MousePos.y = p.y - xy.y;

		if (GetAsyncKeyState(VK_LBUTTON)) {
			io.MouseDown[0] = true;
			io.MouseClicked[0] = true;
			io.MouseClickedPos[0].x = io.MousePos.x;
			io.MouseClickedPos[0].x = io.MousePos.y;
		}
		else
			io.MouseDown[0] = false;

		if (rc.left != old_rc.left || rc.right != old_rc.right || rc.top != old_rc.top || rc.bottom != old_rc.bottom)
		{
			old_rc = rc;

			Width = rc.right;
			Height = rc.bottom;

			d3dpp.BackBufferWidth = Width;
			d3dpp.BackBufferHeight = Height;
			SetWindowPos(Window, (HWND)0, xy.x, xy.y, Width, Height, SWP_NOREDRAW);
			D3dDevice->Reset(&d3dpp);
		}
		render();
	}
	ImGui_ImplDX9_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();

	DestroyWindow(Window);
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, Message, wParam, lParam))
		return true;

	switch (Message)
	{
	case WM_DESTROY:
		xShutdown();
		PostQuitMessage(0);
		exit(4);
		break;
	case WM_SIZE:
		if (D3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			d3dpp.BackBufferWidth = LOWORD(lParam);
			d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = D3dDevice->Reset(&d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		break;
	default:
		return DefWindowProc(hWnd, Message, wParam, lParam);
		break;
	}
	return 0;
}

void xShutdown()
{
	TriBuf->Release();
	D3dDevice->Release();
	p_Object->Release();

	DestroyWindow(Window);
	UnregisterClass("notepad", NULL);
}
