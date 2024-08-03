#pragma once
#include <cstdint>

class entity {
public:
	uintptr_t
		actor,
		skeletal_mesh,
		root_component,
		player_state;
	int
		team_index;
	int
		kills;
};

class item {
public:
	uintptr_t
		Actor;

	std::string
		Name;
	bool
		isVehicle,
		isChest,
		isPickup,
		isAmmoBox;
	float
		distance;


};

class Pointers {
public:
	uintptr_t
		uworld,
		game_instance,
		game_state,
		local_player,
		acknowledged_pawn,
		player_state,
		player_controller,
		root_component,
		skeletal_mesh,
		persistent_level,
		world_settings,
		WorldGravityZ,
		player_array,
		levels,
		player_array_size,
		player_camera_manager,
		current_weapon,
		squad_id,
		current_vehicle;
	int
		team_index;
}; static Pointers* pointer = new Pointers();

std::vector<entity> entity_list;
std::vector<entity> temporary_entity_list;


//
//int team_indx, player_arry_size;
//fvector relatv_location;
//fvector velocity;

namespace o {
	class p
	{
	public:

		uintptr_t
			uworld,
			game_instance,
			game_state,
			local_player,
			acknowledged_pawn,
			player_state,
			player_controller,
			root_component,
			skeletal_mesh,
			persistent_level,
			world_settings,
			WorldGravityZ,
			player_array,
			levels,
			player_array_size,
			player_camera_manager,
			current_weapon,
			squad_id,
			current_vehicle;
		//int
		//	team_index;
		//fvector
		//	relative_location,
		//	velocity;
	};
} 
static o::p* g_ptr = new o::p();

int width, height;

namespace aimb {
	 bool aimbot = true;
	 bool human_aim = true;
	 int aim_type = 0;
	 bool use_deadzone = false;
	 float deadzone = 0;
	 int key = VK_RBUTTON;
	 int mind = 0;
	 bool prediction = false;
	 bool visible_check = false;
	 bool team_check = false;
	 bool show_fov = false;
	 int fov_size = 100;
	 int smoothing = 4;
	 int aim_bone = 0;
	 int aimbot_key = VK_RBUTTON;
}

namespace esp {
	 bool box = true;
	int box_type = 0;
	 bool rounded = false;
	 bool cornered = false;
	 bool filled_esp = false;
	 bool skeleton = false;
	 bool head_circle = false;
	 bool snapline = false;
	 int snapline_type = 0;
	 bool username = false;
	 bool platform = false;
	 bool kill_count = false;
	 bool weapon = false;
	 bool distance = false;
	 bool rank_esp = false;

	 bool radar = false;
	 int radar_pos_x = 20;
	 int radar_pos_y = 50;
	 int radar_size = 200;
	 int radar_range = 60.f;



	 int max_visual_distance = 300;
	 bool outline = false;

	//ImColor visible = ImVec4(0.0f, 1.0f, 0.0f, 1.0f); // green
	//ImColor invisible = ImVec4(1.0f, 0.0f, 0.0f, 1.0f); // red

	float visible[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
	float invisible[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
	float text_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
}

namespace idk {
	 bool vsync = false;
}