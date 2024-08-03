//fvector relative_location;
Vector3 LocalRelativeLocation;
ImFont* GameFont;

inline void DrawString3(float fontSize, int x, int y, ImVec4 color, bool bCenter, bool stroke, const char* pText, ...)
{
	

	ImU32 converted_color = ImGui::ColorConvertFloat4ToU32(color);
	va_list va_alist;
	char buf[1024] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 4;
		y = y - textSize.y;
	}
	if (stroke)
	{
		/*ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());*/
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
	}
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), converted_color, text.c_str());
}

inline void DrawString(float fontSize, int x, int y, float color[4], bool bCenter, bool stroke, const char* pText, ...)
{
	
	float r = color[0];
	float g = color[1];
	float b = color[2];
	float a = color[3];

	ImU32 converted_color = ImGui::ColorConvertFloat4ToU32(ImVec4(r, g, b, a));
	va_list va_alist;
	char buf[1024] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 4;
		y = y - textSize.y;
	}
	if (stroke)
	{
		/*ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());*/
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
	}
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), converted_color, text.c_str());
}

inline void DrawString2(float fontSize, int x, int y, ImColor color, bool bCenter, bool stroke, const char* pText, ...)
{
	
	va_list va_alist;
	char buf[1024] = { 0 };
	va_start(va_alist, pText);
	_vsnprintf_s(buf, sizeof(buf), pText, va_alist);
	va_end(va_alist);
	std::string text = WStringToUTF8(MBytesToWString(buf).c_str());
	if (bCenter)
	{
		ImVec2 textSize = ImGui::CalcTextSize(text.c_str());
		x = x - textSize.x / 4;
		y = y - textSize.y;
	}
	if (stroke)
	{
		/*ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(0, 0, 0, 1)), text.c_str());*/
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y - 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x - 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
		ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x + 1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), text.c_str());
	}
	ImGui::GetBackgroundDrawList()->AddText(ImGui::GetFont(), fontSize, ImVec2(x, y), color, text.c_str());
}

void DrawLine2(int x1, int y1, int x2, int y2, float color[4], int thickness) {
	
	ImDrawList* drawList = ImGui::GetBackgroundDrawList();

	ImU32 convertedColor = ImGui::ColorConvertFloat4ToU32(ImVec4(color[0], color[1], color[2], color[3]));
	ImU32 convertedOutlineColor = ImGui::ColorConvertFloat4ToU32(ImVec4({ 0.0f, 0.0f, 0.0f, 1.0f }));

	if (esp::outline)
		drawList->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), IM_COL32(0, 0, 0, 255), thickness + 3.5);
	drawList->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), convertedColor, thickness);
}

float target_dist = FLT_MAX;
bool angles_resetted = false;
uintptr_t  target_entity = NULL;
uintptr_t freeze_target = NULL;
uintptr_t  desync_target_entity = NULL;

namespace loop {
	class game {
	public:
		void DrawBox(int x, int y, int w, int h, float color[4], int thickness) {
			
			ImDrawList* Drawlist = ImGui::GetBackgroundDrawList();

			float r = color[0];
			float g = color[1];
			float b = color[2];
			float a = color[3];

			ImU32 converted_color = ImGui::ColorConvertFloat4ToU32(ImVec4(r, g, b, a));



			Drawlist->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), converted_color, 0.0f, 0, thickness);
		}

		ImVec4 get_rank_color(int32_t Tier)
		{
			
			if (Tier == 0 || Tier == 1 || Tier == 2)
				return ImVec4(0.902f, 0.580f, 0.227f, 1.0f); // Bronze
			else if (Tier == 3 || Tier == 4 || Tier == 5)
				return ImVec4(0.843f, 0.843f, 0.843f, 1.0f); // Silver
			else if (Tier == 6 || Tier == 7 || Tier == 8)
				return ImVec4(1.0f, 0.871f, 0.0f, 1.0f); // Gold
			else if (Tier == 9 || Tier == 10 || Tier == 11)
				return ImVec4(0.0f, 0.7f, 0.7f, 1.0f); // Platinum
			else if (Tier == 12 || Tier == 13 || Tier == 14)
				return ImVec4(0.0f, 0.0f, 0.7f, 1.0f); // Diamond
			else if (Tier == 15)
				return ImVec4(0.7f, 0.7f, 0.7f, 1.0f); // Elite
			else if (Tier == 16)
				return ImVec4(1.0f, 0.6f, 0.0f, 1.0f); // Champion
			else if (Tier == 17)
				return ImVec4(0.6f, 0.0f, 0.6f, 1.0f); // Unreal
			else
				return ImVec4(0.0f, 0.7859f, 1.0f, 1.0f); // Unranked
		}

		std::string get_rank(int32_t Tier)
		{
			
			if (Tier == 0)
				return std::string("Bronze 1");
			else if (Tier == 1)
				return std::string("Bronze 2");
			else if (Tier == 2)
				return std::string("Bronze 3");
			else if (Tier == 3)
				return std::string("Silver 1");
			else if (Tier == 4)
				return std::string("Silver 2");
			else if (Tier == 5)
				return std::string("Silver 3");
			else if (Tier == 6)
				return std::string("Gold 1");
			else if (Tier == 7)
				return std::string("Gold 2");
			else if (Tier == 8)
				return std::string("Gold 3");
			else if (Tier == 9)
				return std::string("Platinum 1");
			else if (Tier == 10)
				return std::string("Platinum 2");
			else if (Tier == 11)
				return std::string("Platinum 3");
			else if (Tier == 12)
				return std::string("Diamond 1");
			else if (Tier == 13)
				return std::string("Diamond 2");
			else if (Tier == 14)
				return std::string("Diamond 3");
			else if (Tier == 15)
				return std::string("Elite");
			else if (Tier == 16)
				return std::string("Champion");
			else if (Tier == 17)
				return std::string("Unreal");
			else
				return std::string("Unranked");
		}


		bool debug = false;

		auto ActorLoop() -> void {

			{
			pointer->uworld = read<uintptr_t>(dynamic_uworld);
			if (debug) { printf(("\n {+} Uworld -> %llx"), pointer->uworld); }
			

			pointer->game_instance = read<uintptr_t>(pointer->uworld + offset::game_instance);
			if (debug) { printf(("\n {+} game_instance -> %llx"), pointer->game_instance); }

			pointer->levels = read<uintptr_t>(pointer->levels + 0x178);
			if (debug) { printf(("\n {+} levels -> %llx"), pointer->levels); }

			pointer->game_state = read<uintptr_t>(pointer->uworld + offset::game_state);
			if (debug) { printf(("\n {+} game_state -> %llx"), pointer->game_state); }

			pointer->local_player = read<uintptr_t>(read<uintptr_t>(pointer->game_instance + offset::local_player));
			if (debug) { printf(("\n {+} local_player -> %llx"), pointer->local_player); }

			pointer->player_controller = read<uintptr_t>(pointer->local_player + offset::player_controller);
			if (debug) { printf(("\n {+} player_controller -> %llx"), pointer->player_controller); }

			pointer->acknowledged_pawn = read<uintptr_t>(pointer->player_controller + offset::acknowledged_pawn);
			if (debug) { printf(("\n {+} acknowledged_pawn -> %llx"), pointer->acknowledged_pawn); }

			pointer->current_weapon = read<uintptr_t>(pointer->acknowledged_pawn + offset::current_weapon);
			if (debug) { printf(("\n {+} current_weapon -> %llx"), pointer->current_weapon); }

			pointer->skeletal_mesh = read<uintptr_t>(pointer->acknowledged_pawn + offset::skeletal_mesh);
			if (debug) { printf(("\n {+} skeletal_mesh -> %llx"), pointer->skeletal_mesh); }

			pointer->player_state = read<uintptr_t>(pointer->acknowledged_pawn + offset::player_state);
			if (debug) { printf(("\n {+} player_state -> %llx"), pointer->player_state); }

			pointer->root_component = read<uintptr_t>(pointer->acknowledged_pawn + offset::root_component);
			if (debug) { printf(("\n {+} root_component -> %llx"), pointer->root_component); }

			pointer->team_index = read<int>(pointer->player_state + offset::team_index);
			if (debug) { printf(("\n {+} team_index -> %llx"), pointer->team_index); }

			pointer->squad_id = read<int>(pointer->player_state + 0x137c);
			if (debug) { printf(("\n {+} squad_id -> %llx"), pointer->squad_id); }

			//relative_location = read<fvector>(pointer->root_component + offset::relative_location);

			pointer->player_array = read<uintptr_t>(pointer->game_state + offset::player_array);
			pointer->player_array_size = read<int>(pointer->game_state + (offset::player_array + sizeof(uintptr_t)));
			pointer->persistent_level = read< DWORD_PTR>(pointer->uworld + offset::persistent_level);

			//LocalRelativeLocation = read<Vector3>(read<uint64_t>(pointer->acknowledged_pawn + 0x130) + 0x11C);
			}

			target_dist = FLT_MAX;
			target_entity = NULL;
			desync_target_entity = NULL;

			UpdateCamera();

			float screenCenterY = (height / 2); 
			float screenCenterX = (width / 2);
			if (aimb::show_fov)
			{
				
				ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(width / 2, height / 2), aimb::fov_size, ImColor(0, 0, 0), 64, 3);
				//ImGui::GetBackgroundDrawList()->AddRect(ImVec2(screenCenterX - aimb::fov_size, screenCenterY - aimb::fov_size), ImVec2(screenCenterX + aimb::fov_size, screenCenterY + aimb::fov_size), IM_COL32(0, 0, 0, 255), 1.5f);
			}


			
			for (int i = 0; i < pointer->player_array_size; ++i) {
				
				ImGui::PushFont(GameFont);
				auto player_state = read<uintptr_t>(pointer->player_array + (i * sizeof(uintptr_t)));
				auto current_actor = read<uintptr_t>(player_state + offset::pawn_private);

				if (current_actor == pointer->acknowledged_pawn) continue;
				auto skeletalmesh = read<uintptr_t>(current_actor + offset::skeletal_mesh);
				if (!skeletalmesh) continue;

				auto base_bone = GetBoneLocation(skeletalmesh, bone::HumanBase);
				if (base_bone.x == 0 && base_bone.y == 0 && base_bone.z == 0) continue;

				if (!in_screen(w2s(GetBoneLocation(skeletalmesh, bone::HumanPelvis)))) continue;

				auto is_despawning = (read<char>(current_actor + 0x758) >> 3);

				if (is_despawning) continue;


				if (aimb::team_check) {
					if (pointer->acknowledged_pawn)
					{
						auto team_index = read<int>(player_state + offset::team_index);
						if (pointer->team_index == team_index) continue;
					}
				}

				auto actor_enemy = current_actor;
				auto skeletal_enemy = read<uintptr_t>(current_actor + offset::skeletal_mesh);
				auto root_component_enemy = read<uintptr_t>(current_actor + offset::root_component);
				auto player_state_enemy = read<uintptr_t>(current_actor + offset::player_state);
				auto team_index_enemy = read<int>(player_state_enemy + offset::team_index);
				auto squad_id_enemy = read<int>(player_state_enemy + 0x137c);

				auto root_location = GetBoneLocation(skeletal_enemy, bone::HumanBase);
				auto root_screen = w2s(root_location);
				auto head_location = GetBoneLocation(skeletal_enemy, bone::HumanHead);
				auto head = w2s(head_location);
				auto head_screen = w2s(GetBoneLocation(skeletal_enemy, bone::HumanHead));
				auto head_screen1 = GetBoneLocation(skeletal_enemy, bone::HumanHead);
				auto neck_screen = w2s(GetBoneLocation(skeletal_enemy, bone::HumanNeck));
				auto neck_screen1 = GetBoneLocation(skeletal_enemy, bone::HumanNeck);

				fvector2d head_box = w2s(fvector(head_screen1.x, head_screen1.y, head_screen1.z + 15));
				fvector2d neck_box = w2s(fvector(neck_screen1.x, neck_screen1.y, neck_screen1.z + 15));
				fvector2d head_2d = w2s(fvector(head_location.x, head_location.y, head_location.z + -2));

				float box_height = abs(head_screen.y - root_screen.y);
				float box_width = box_height * 0.50f;
				float distance = camera::location.Distance(root_location) / 100 - 4;

				if (distance > esp::max_visual_distance) continue;

				if (aimb::aimbot) {
					
					auto dx = head_screen.x - (width / 2);
					auto dy = head_screen.y - (height / 2);
					auto dist = sqrtf(dx * dx + dy * dy);

					if (dist < aimb::fov_size && dist < target_dist) {
						target_dist = dist;
						target_entity = current_actor;
					}
				}

				Vector3 hitbox_screen;

				int drX = width / 2;
				int drY = height / 2;

				auto root_box1 = w2s(GetBoneLocation(skeletal_enemy, 0));
				auto foot_box = w2s(GetBoneLocation(skeletal_enemy, bone::HumanLFoot));


				auto goober_root = GetBoneLocation(skeletal_enemy, 0);

				float CornerHeight = abs(head_box.y - root_box1.y);
				float BoxHeight = abs(head_box.y - foot_box.y);
				float CornerWidth = box_height * 0.65f;

				bool is_vis = is_visible(skeletal_enemy);

				int centerX = width / 2;
				int centerY = height / 2;

				float black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
				float YOffset = 0;

				if (esp::rank_esp) {
					
					uintptr_t habenero = read<uintptr_t>(player_state_enemy + 0x9f0); // https://dumpspace.spuckwaffel.com/Games/?hash=6b77eceb&type=classes&idx=AFortPlayerState&member=HabaneroComponent

					int32_t RankProgress = read<int32_t>(habenero + 0xb8 + 0x10);

					std::string ranktype = get_rank(RankProgress);

					std::wstring w_ranktype = string_to_wstring(ranktype);

					std::string final = wstring_to_utf8(w_ranktype);


					ImVec2 text_size = ImGui::CalcTextSize(final.c_str());
					YOffset = YOffset + 13;
					DrawString3(16, head_box.x - (text_size.x / 2), head_box.y - YOffset, get_rank_color(RankProgress), true, true, final.c_str());
				}

				if (esp::distance)
				{
					
					std::string distance_string = patch::to_string((int)distance) + "m";
					ImVec2 text_size = ImGui::CalcTextSize(distance_string.c_str());
					DrawString(16, root_screen.x - (text_size.x / 2), root_screen.y + 25, esp::text_color, true, esp::outline, distance_string.c_str());
				}

				if (esp::box && esp::box_type == 0) //Fill
				{
					
					if (is_vis)
					{
						DrawBox(neck_box.x - (CornerWidth / 2), neck_box.y, CornerWidth, BoxHeight, esp::visible, 2.5);

					}
					else
					{
						DrawBox(neck_box.x - (CornerWidth / 2), neck_box.y, CornerWidth, BoxHeight, esp::invisible, 2.5);

					}
				}
				if (esp::box && esp::box_type == 1) //Cornered
				{
					
					if (is_vis)
					{
						DrawBox(head_box.x - (CornerWidth / 2), head_box.y, CornerWidth, CornerHeight, esp::visible, 2.5);
						if (esp::outline)
						{
							DrawBox(head_box.x - (CornerWidth / 2), head_box.y, CornerWidth, CornerHeight, black, 1.5);
						}
					}
					else
					{
						DrawBox(head_box.x - (CornerWidth / 2), head_box.y, CornerWidth, CornerHeight, esp::invisible, 2.5);
						if (esp::outline)
						{
							DrawBox(head_box.x - (CornerWidth / 2), head_box.y, CornerWidth, CornerHeight, black, 1.5);
						}
					}
				}
				if (esp::box && esp::box_type == 2) //Rounded
				{
					
					if (is_vis)
					{

					}
					else
					{

					}
				}
				if (esp::snapline)
				{
					
					if (esp::snapline_type == 0)
					{
						int topY = 0;
						DrawLine2(root_screen.x, topY, head_2d.x, head_2d.y, esp::text_color, 2);
					}
					else if (esp::snapline_type == 1)
					{
						DrawLine2(width / 2, height / 2, head_2d.x, head_2d.y, esp::text_color, 2);
					}
					else if (esp::snapline_type == 2)
					{
						DrawLine2(centerX, height, root_screen.x, root_screen.y, esp::text_color, 2);
					}
				}
				if (esp::skeleton) {
					
					auto neck = w2s(GetBoneLocation(skeletal_enemy, bone::HumanHead));
					auto chest = w2s(GetBoneLocation(skeletal_enemy, bone::HumanNeck));
					auto left_shoulder = w2s(GetBoneLocation(skeletal_enemy, 9));
					auto left_elbow = w2s(GetBoneLocation(skeletal_enemy, bone::HumanLForearm23));
					auto left_hand = w2s(GetBoneLocation(skeletal_enemy, bone::HumanLHand));
					auto right_shoulder = w2s(GetBoneLocation(skeletal_enemy, 38));
					auto right_elbow = w2s(GetBoneLocation(skeletal_enemy, bone::HumanRForearm23));
					auto right_hand = w2s(GetBoneLocation(skeletal_enemy, bone::HumanRHand));
					auto pelvis = w2s(GetBoneLocation(skeletal_enemy, bone::HumanPelvis));
					auto left_hip = w2s(GetBoneLocation(skeletal_enemy, bone::HumanLThigh1));
					auto left_knee = w2s(GetBoneLocation(skeletal_enemy, bone::HumanLThigh3));
					auto left_foot = w2s(GetBoneLocation(skeletal_enemy, bone::HumanLFoot2));
					auto right_hip = w2s(GetBoneLocation(skeletal_enemy, bone::HumanRThigh1));
					auto right_knee = w2s(GetBoneLocation(skeletal_enemy, bone::HumanRThigh3));
					auto right_foot = w2s(GetBoneLocation(skeletal_enemy, bone::HumanRFoot2));
					auto skeleton_color = is_vis ? esp::visible : esp::invisible;
					auto skeleton_thick = 2.0f;
					DrawLine2(head_screen.x, head_screen.y, neck.x, neck.y, skeleton_color, skeleton_thick);
					DrawLine2(neck.x, neck.y, chest.x, chest.y, skeleton_color, skeleton_thick);
					DrawLine2(chest.x, chest.y, right_shoulder.x, right_shoulder.y, skeleton_color, skeleton_thick);
					DrawLine2(left_shoulder.x, left_shoulder.y, chest.x, chest.y, skeleton_color, skeleton_thick);
					DrawLine2(left_shoulder.x, left_shoulder.y, left_elbow.x, left_elbow.y, skeleton_color, skeleton_thick);
					DrawLine2(left_elbow.x, left_elbow.y, left_hand.x, left_hand.y, skeleton_color, skeleton_thick);
					DrawLine2(right_shoulder.x, right_shoulder.y, right_elbow.x, right_elbow.y, skeleton_color, skeleton_thick);
					DrawLine2(right_elbow.x, right_elbow.y, right_hand.x, right_hand.y, skeleton_color, skeleton_thick);
					DrawLine2(chest.x, chest.y, pelvis.x, pelvis.y, skeleton_color, skeleton_thick);
					DrawLine2(pelvis.x, pelvis.y, left_hip.x, left_hip.y, skeleton_color, skeleton_thick);
					DrawLine2(left_hip.x, left_hip.y, left_knee.x, left_knee.y, skeleton_color, skeleton_thick);
					DrawLine2(left_knee.x, left_knee.y, left_foot.x, left_foot.y, skeleton_color, skeleton_thick);
					DrawLine2(pelvis.x, pelvis.y, right_hip.x, right_hip.y, skeleton_color, skeleton_thick);
					DrawLine2(right_hip.x, right_hip.y, right_knee.x, right_knee.y, skeleton_color, skeleton_thick);
					DrawLine2(right_knee.x, right_knee.y, right_foot.x, right_foot.y, skeleton_color, skeleton_thick);
				}


			}


			if (target_entity && aimb::aimbot) {
				

				auto closest_mesh = read<uint64_t>(target_entity + offset::skeletal_mesh);



				UpdateCamera();
				fvector hitbox = GetBoneLocation(closest_mesh, bone::HumanHead);
				fvector2d hitbox_screen = w2s(hitbox);


				if (hitbox_screen.x != 0 || hitbox_screen.y != 0 && (GetCrossDistance(hitbox_screen.x, hitbox_screen.y, width / 2, height / 2) <= aimb::fov_size))
				{
					
					if (aimb::visible_check ? is_visible(closest_mesh) : true) {
						
						if (GetAsyncKeyState(aimb::aimbot_key))
						{
							
							if (aimb::prediction) {
								

								float projectileSpeed = 60000;
								float projectileGravityScale = 3.5f;


								float distance = camera::location.Distance(hitbox);

								auto test = read<uintptr_t>(target_entity + offset::root_component);

								fvector Velocity = read<fvector>(test + offset::velocity);

								fvector Predictor = Prediction(hitbox, Velocity, distance, projectileSpeed);

								fvector2d hitbox_screen_predict = w2s(Predictor);

								move_aim(hitbox_screen_predict);

							}
							else {
								move_aim(hitbox_screen);
							}
						}
					}
				}

			}
			else {
				
				target_dist = FLT_MAX;
				target_entity = NULL;
			}
		}

	};
} static loop::game* Game = new loop::game();
//memory_event(fvector(-target.y / 5, target.x / 5, 0));