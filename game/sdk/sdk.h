

class fvector2d
{
public:
	fvector2d() : x(0.f), y(0.f)
	{

	}

	fvector2d(double _x, double _y) : x(_x), y(_y)
	{

	}
	~fvector2d()
	{

	}


	fvector2d operator-(fvector2d v)
	{
		return fvector2d(x - v.x, y - v.y);
	}


	double x;
	double y;



};

class Vector3
{
public:
	Vector3() : x(0.f), y(0.f), z(0.f)
	{

	}

	Vector3(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
	{

	}
	~Vector3()
	{

	}

	double x;
	double y;
	double z;

	inline float Dot(Vector3 v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	inline float Distance(Vector3 v)
	{
		return sqrtf((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y) + (v.z - z) * (v.z - z));
	}

	Vector3 operator+(Vector3 v)
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 operator-(Vector3 v)
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 operator*(float number) const {
		return Vector3(x * number, y * number, z * number);
	}
};


struct WeaponInformation
{
	int32_t ammo_count;
	int32_t max_ammo;

	BYTE tier;
	std::string weapon_name;
	std::string buildplan;

};
std::string LocalPlayerWeapon;


WeaponInformation WeaponInfo;



class fvector
{
public:
	double x, y, z;
	fvector()
	{
		x = y = z = 0.f;
	}

	fvector(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	fvector operator+(const fvector& v) {
		return fvector{ x + v.x, y + v.y, z + v.z };
	}

	fvector operator-(const fvector& v) {
		return fvector{ x - v.x, y - v.y, z - v.z };
	}

	fvector operator*(const double v) {
		return fvector{ x * v, y * v, z * v };
	}

	fvector operator/(const double fl) const {
		return fvector(x / fl, y / fl, z / fl);
	}


	inline double length() {
		return sqrt(x * x + y * y + z * z);
	}

	inline double distancefrom(const fvector Other) {
		double dx = (this->x - Other.x);
		double dy = (this->y - Other.y);
		double dz = (this->z - Other.z);

		return sqrt((dx * dx) + (dy * dy) + (dz * dz));
	}

	inline double Distance(fvector v)
	{
		return double(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
	}

	__forceinline double size() const {
		return (double)sqrtf((float)x * (float)x + (float)y * (float)y + (float)z * (float)z);
	}

	double Dot(const fvector& vOther) const {
		const fvector& a = *this;

		return (a.x * vOther.x + a.y * vOther.y + a.z * vOther.z);
	}
};

struct fquat
{
	double x;
	double y;
	double z;
	double w;
};
struct frotator
{
	double Pitch;
	double Yaw;
	double Roll;
};

struct fplane : fvector
{
	double W = 0;


	fvector ToVector3()
	{
		fvector value;
		value.x = this->x;
		value.y = this->y;
		value.z = this->y;

		return value;
	}
};

struct ftransform
{
	fplane  rot;
	fvector translation;
	char    pad[8];
	fvector scale;

	D3DMATRIX ToMatrixWithScale()
	{

		D3DMATRIX m;
		m._41 = translation.x;
		m._42 = translation.y;
		m._43 = translation.z;

		double x2 = rot.x + rot.x;
		double y2 = rot.y + rot.y;
		double z2 = rot.z + rot.z;

		double xx2 = rot.x * x2;
		double yy2 = rot.y * y2;
		double zz2 = rot.z * z2;
		m._11 = (1.0f - (yy2 + zz2)) * scale.x;
		m._22 = (1.0f - (xx2 + zz2)) * scale.y;
		m._33 = (1.0f - (xx2 + yy2)) * scale.z;

		double yz2 = rot.y * z2;
		double wx2 = rot.W * x2;
		m._32 = (yz2 - wx2) * scale.z;
		m._23 = (yz2 + wx2) * scale.y;

		double xy2 = rot.x * y2;
		double wz2 = rot.W * z2;
		m._21 = (xy2 - wz2) * scale.y;
		m._12 = (xy2 + wz2) * scale.x;

		double xz2 = rot.x * z2;
		double wy2 = rot.W * y2;
		m._31 = (xz2 + wy2) * scale.z;
		m._13 = (xz2 - wy2) * scale.x;

		m._14 = 0.0f;
		m._24 = 0.0f;
		m._34 = 0.0f;
		m._44 = 1.0f;

		return m;
	}
};
inline D3DMATRIX MatrixMultiplication(D3DMATRIX pM1, D3DMATRIX pM2)
{
	SPOOF_FUNC
		D3DMATRIX pOut;
	pOut._11 = pM1._11 * pM2._11 + pM1._12 * pM2._21 + pM1._13 * pM2._31 + pM1._14 * pM2._41;
	pOut._12 = pM1._11 * pM2._12 + pM1._12 * pM2._22 + pM1._13 * pM2._32 + pM1._14 * pM2._42;
	pOut._13 = pM1._11 * pM2._13 + pM1._12 * pM2._23 + pM1._13 * pM2._33 + pM1._14 * pM2._43;
	pOut._14 = pM1._11 * pM2._14 + pM1._12 * pM2._24 + pM1._13 * pM2._34 + pM1._14 * pM2._44;
	pOut._21 = pM1._21 * pM2._11 + pM1._22 * pM2._21 + pM1._23 * pM2._31 + pM1._24 * pM2._41;
	pOut._22 = pM1._21 * pM2._12 + pM1._22 * pM2._22 + pM1._23 * pM2._32 + pM1._24 * pM2._42;
	pOut._23 = pM1._21 * pM2._13 + pM1._22 * pM2._23 + pM1._23 * pM2._33 + pM1._24 * pM2._43;
	pOut._24 = pM1._21 * pM2._14 + pM1._22 * pM2._24 + pM1._23 * pM2._34 + pM1._24 * pM2._44;
	pOut._31 = pM1._31 * pM2._11 + pM1._32 * pM2._21 + pM1._33 * pM2._31 + pM1._34 * pM2._41;
	pOut._32 = pM1._31 * pM2._12 + pM1._32 * pM2._22 + pM1._33 * pM2._32 + pM1._34 * pM2._42;
	pOut._33 = pM1._31 * pM2._13 + pM1._32 * pM2._23 + pM1._33 * pM2._33 + pM1._34 * pM2._43;
	pOut._34 = pM1._31 * pM2._14 + pM1._32 * pM2._24 + pM1._33 * pM2._34 + pM1._34 * pM2._44;
	pOut._41 = pM1._41 * pM2._11 + pM1._42 * pM2._21 + pM1._43 * pM2._31 + pM1._44 * pM2._41;
	pOut._42 = pM1._41 * pM2._12 + pM1._42 * pM2._22 + pM1._43 * pM2._32 + pM1._44 * pM2._42;
	pOut._43 = pM1._41 * pM2._13 + pM1._42 * pM2._23 + pM1._43 * pM2._33 + pM1._44 * pM2._43;
	pOut._44 = pM1._41 * pM2._14 + pM1._42 * pM2._24 + pM1._43 * pM2._34 + pM1._44 * pM2._44;

	return pOut;
}
#define PI 3.14159265358979323846f
struct _MATRIX {
	union {
		struct {
			float        _11, _12, _13, _14;
			float        _21, _22, _23, _24;
			float        _31, _32, _33, _34;
			float        _41, _42, _43, _44;

		};
		float m[4][4];
	};
};
D3DMATRIX Matrix(fvector rot, fvector origin = fvector(0, 0, 0))
{

	float radPitch = (rot.x * float(PI) / 180.f);
	float radYaw = (rot.y * float(PI) / 180.f);
	float radRoll = (rot.z * float(PI) / 180.f);

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


namespace camera
{
	fvector location, rotation;
	Vector3 nigga_loc;
	float fov;
}

struct camera_position_s {
	fvector location{};
	fvector rotation{};
	float fov{};
};
inline camera_position_s camera_postion{};


#define deg2Rad(angleDegrees) ((angleDegrees) * M_PI / 180.0)
#define rad2Deg(angleRadians) ((angleRadians) * 180.0 / M_PI)
struct FMinimalViewInfo
{
	FMinimalViewInfo() : Location(), Rotation(), FOV(FOV) {}
	FMinimalViewInfo(fvector Location, fvector Rotation, float FOV) : Location(Location), Rotation(Rotation), FOV(FOV) {}

	fvector Location, Rotation;
	float FOV;
};

inline FMinimalViewInfo m_camera_information{};


typedef struct _D3DMATRIX1 {
	union {
		struct {
			double _11, _12, _13, _14;
			double _21, _22, _23, _24;
			double _31, _32, _33, _34;
			double _41, _42, _43, _44;

		};
		double m[4][4];
	};
} D3DMATRIX1;

typedef struct D3DXMATRIX1 {
	DOUBLE _ij;
} D3DXMATRIX1, * LPD3DXMATRIX1;

struct FPlane : public fvector
{
	double W;
};


auto in_screen(fvector2d screen_location) -> bool {

	if (screen_location.x > 0 && screen_location.x < width && screen_location.y > 0 && screen_location.y < height) return true;
	else return false;

}

static auto UpdateCamera() -> void
{
	SPOOF_FUNC;
	auto location_pointer = read<uintptr_t>(pointer->uworld + 0x110);
	//printf("Location -> ", location_pointer);
	auto rotation_pointer = read<uintptr_t>(pointer->uworld + 0x120);
	//printf("Rotation -> ", rotation_pointer);

	struct FNRotation
	{
		double a; //0x0000
		char pad_0008[24]; //0x0008
		double b; //0x0020
		char pad_0028[424]; //0x0028
		double c; //0x01D0
	}tpmrotation;

	tpmrotation.a = read<double>(rotation_pointer);
	tpmrotation.b = read<double>(rotation_pointer + 0x20);
	tpmrotation.c = read<double>(rotation_pointer + 0x1d0);

	/*tpmrotation = read<FNRotation>(rotation_pointer);*/

	camera::rotation.x = asin(tpmrotation.c) * (180.0 / PI);
	camera::rotation.y = ((atan2(tpmrotation.a * -1, tpmrotation.b) * (180.0 / PI)) * -1) * -1;
	camera::location = read<fvector>(location_pointer);
	camera::fov = read<float>(pointer->player_controller + 0x394) * 90.f;

}

static auto w2s(fvector worldlocation) -> fvector2d {
	SPOOF_FUNC;

	D3DMATRIX tempMatrix = Matrix(camera::rotation);

	fvector vAxisX = fvector(tempMatrix.m[0][0], tempMatrix.m[0][1], tempMatrix.m[0][2]);
	fvector vAxisY = fvector(tempMatrix.m[1][0], tempMatrix.m[1][1], tempMatrix.m[1][2]);
	fvector vAxisZ = fvector(tempMatrix.m[2][0], tempMatrix.m[2][1], tempMatrix.m[2][2]);

	fvector vDelta = worldlocation - camera::location;
	fvector vTransformed = fvector(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	if (vTransformed.z < 1.f)
		vTransformed.z = 1.f;


	return fvector2d((width / 2.0f) + vTransformed.x * (((width / 2.0f) / tanf(camera::fov * (float)PI / 360.f))) / vTransformed.z, (height / 2.0f) - vTransformed.y * (((width / 2.0f) / tanf(camera::fov * (float)PI / 360.f))) / vTransformed.z);

}


static auto is_visible(uintptr_t skeletal_mesh) -> bool {

	auto last_submit = read <float>(skeletal_mesh + 0x2E8);
	auto last_render = read <float>(skeletal_mesh + 0x2F0);
	return (bool)(last_render + 0.06f >= last_submit);

}

static auto GetBoneLocation(uintptr_t skeletal_mesh, int bone_index) -> fvector {
	SPOOF_FUNC;
	uintptr_t bone_array = read<uintptr_t>(skeletal_mesh + offset::bone_array);
	if (bone_array == NULL) bone_array = read<uintptr_t>(skeletal_mesh + offset::bone_array + 0x10);
	ftransform bone = read<ftransform>(bone_array + (bone_index * 0x60));
	ftransform component_to_world = read<ftransform>(skeletal_mesh + offset::component_to_world);
	D3DMATRIX matrix = MatrixMultiplication(bone.ToMatrixWithScale(), component_to_world.ToMatrixWithScale());
	return fvector(matrix._41, matrix._42, matrix._43);
}

ftransform GetBoneIndex(uint64_t mesh, int index)
{
	uint64_t bonearray = read<uint64_t>(mesh + 0x4a8);
	if (!bonearray) bonearray = read<uint64_t>(mesh + 0x4a8 + 0x10);
	return read<ftransform>(bonearray + (index * 0x30));
}

Vector3 GetBoneWithRotation(DWORD_PTR mesh, int id)
{
	ftransform bone = GetBoneIndex(mesh, id);
	ftransform ComponentToWorld = read<ftransform>(mesh + 0x1c0);

	D3DMATRIX Matrix;
	Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());

	return Vector3(Matrix._41, Matrix._42, Matrix._43);
}



fvector calc_angle(fvector LocalPos, fvector WorldPos) {
	fvector RelativePos = WorldPos - LocalPos;
	float yaw = atan2(RelativePos.y, RelativePos.x) * 180.0f / PI;
	float pitch = -((acos(RelativePos.z / LocalPos.Distance(WorldPos)) * 180.0f / PI) - 90.0f);
	return fvector(pitch, yaw, 0);
}

static void normalize(fvector& in)
{
	while (in.x > 180.0f)
		in.x -= 360.0f;

	while (in.x < -180.0f)
		in.x += 360.0f;

	while (in.y > 180.0f)
		in.y -= 360.0f;

	while (in.y < -180.0f)
		in.y += 360.0f;

	in.z = 0;
}

__forceinline double Clamp(double value, double min, double max)
{
	if (value < min) {
		return min;
	}
	else if (value > max) {
		return max;
	}
	else {
		return value;
	}
}


fvector Prediction(fvector TargetPosition, fvector ComponentVelocity, float player_distance, float ProjectileSpeed = 239)
{
	float gravity = 3.5;
	float TimeToTarget = player_distance / ProjectileSpeed;
	float bulletDrop = abs(gravity) * (TimeToTarget * TimeToTarget) * 0.5;
	return fvector
	{
	TargetPosition.x + TimeToTarget * ComponentVelocity.x,
	TargetPosition.y + TimeToTarget * ComponentVelocity.y,
	TargetPosition.z + TimeToTarget * ComponentVelocity.z + bulletDrop
	};
}

inline std::wstring MBytesToWString(const char* lpcszString)
{
	SPOOF_FUNC;

	int len = strlen(lpcszString);
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, NULL, 0);
	wchar_t* pUnicode = new wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));
	::MultiByteToWideChar(CP_ACP, 0, lpcszString, -1, (LPWSTR)pUnicode, unicodeLen);
	std::wstring wString = (wchar_t*)pUnicode;
	delete[] pUnicode;
	return wString;
}
inline std::string WStringToUTF8(const wchar_t* lpwcszWString)
{
	SPOOF_FUNC;

	char* pElementText;
	int iTextLen = ::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, NULL, 0, NULL, NULL);
	pElementText = new char[iTextLen + 1];
	memset((void*)pElementText, 0, (iTextLen + 1) * sizeof(char));
	::WideCharToMultiByte(CP_UTF8, 0, (LPWSTR)lpwcszWString, -1, pElementText, iTextLen, NULL, NULL);
	std::string strReturn(pElementText);
	delete[] pElementText;
	return strReturn;
}




std::wstring string_to_wstring(const std::string& str) {
	if (str.empty()) return std::wstring();
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstr(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstr[0], size_needed);
	return wstr;
}

std::string wstring_to_utf8(const std::wstring& wstr) {
	if (wstr.empty()) return std::string();
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string str(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size_needed, NULL, NULL);
	return str;
}

static float powf_(float _X, float _Y) {
	SPOOF_FUNC;
	return (_mm_cvtss_f32(_mm_pow_ps(_mm_set_ss(_X), _mm_set_ss(_Y))));
}
static float sqrtf_(float _X) {
	SPOOF_FUNC;
	return (_mm_cvtss_f32(_mm_sqrt_ps(_mm_set_ss(_X))));
}

static double GetCrossDistance(double x1, double y1, double x2, double y2) {
	SPOOF_FUNC;
	return sqrtf(powf((x2 - x1), 2) + powf_((y2 - y1), 2));
}

auto smooth_aim(float x, float y) {
	SPOOF_FUNC;
	float ScreenCenterX = (width / 2);
	float ScreenCenterY = (height / 2);
	fvector2d target(0, 0);

	if (x != 0) {
		if (x > ScreenCenterX) {
			target.x = -(ScreenCenterX - x);
			target.x /= (aimb::smoothing);
			if (target.x + ScreenCenterX > ScreenCenterX * 2)
				target.x = 0;
		}

		if (x < ScreenCenterX) {
			target.x = x - ScreenCenterX;
			target.x /= (aimb::smoothing);
			if (target.x + ScreenCenterX < 0)
				target.x = 0;
		}
	}
	if (y != 0) {
		if (y > ScreenCenterY) {
			target.y = -(ScreenCenterY - y);
			target.y /= (aimb::smoothing);
			if (target.y + ScreenCenterY > ScreenCenterY * 2)
				target.y = 0;
		}

		if (y < ScreenCenterY) {
			target.y = y - ScreenCenterY;
			target.y /= (aimb::smoothing);
			if (target.y + ScreenCenterY < 0)
				target.y = 0;
		}
	}


	return target;
}