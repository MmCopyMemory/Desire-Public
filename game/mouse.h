uintptr_t NetConnection = 0x518; /** The net connection this controller is communicating on, nullptr for local players on server */
uintptr_t RotationInput = NetConnection + 0x8; //size of NetConnection (0x8)

bool memory_event(fvector newpos)
{
    SPOOF_FUNC;
    write<fvector>(pointer->player_controller + RotationInput, newpos); //write Vectors to control rotation
    return true;
}

float RandomFloat(float a, float b)
{
    SPOOF_FUNC;
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

inline void move_aim(fvector2d Head2D) {
    SPOOF_FUNC;
    float x = Head2D.x; float y = Head2D.y;
    float AimSpeed = aimb::smoothing;

    fvector2d ScreenCenter = { (double)width / 2 , (double)height / 2 };
    fvector2d Target;

    if (x != 0)
    {
        if (x > ScreenCenter.x)
        {
            Target.x = -(ScreenCenter.x - x);
            Target.x /= AimSpeed;
            if (Target.x + ScreenCenter.x > ScreenCenter.x * 2) Target.x = 0;
        }

        if (x < ScreenCenter.x)
        {
            Target.x = x - ScreenCenter.x;
            Target.x /= AimSpeed;
            if (Target.x + ScreenCenter.x < 0) Target.x = 0;
        }
    }
    if (y != 0)
    {
        if (y > ScreenCenter.y)
        {
            Target.y = -(ScreenCenter.y - y);
            Target.y /= AimSpeed;
            if (Target.y + ScreenCenter.y > ScreenCenter.y * 2) Target.y = 0;
        }

        if (y < ScreenCenter.y)
        {
            Target.y = y - ScreenCenter.y;
            Target.y /= AimSpeed;
            if (Target.y + ScreenCenter.y < 0) Target.y = 0;
        }
    }
    //if ((int)Target.x != 0 or (int)Target.y != 0);

    if (aimb::use_deadzone) {

        float deadzone_x = aimb::deadzone * ScreenCenter.x / 100.0f;
        float deadzone_y = aimb::deadzone * ScreenCenter.y / 100.0f;

        if (fabs(Target.x) < deadzone_x) {
            Target.x = 0.0f;
        }

        if (fabs(Target.y) < deadzone_y) {
            Target.y = 0.0f;
        }
    }


    if (aimb::human_aim) {
        float targetx_min = Target.x - 1;
        float targetx_max = Target.x + 1;

        float targety_min = Target.y - 1;
        float targety_max = Target.y + 1;

        float offset_x = RandomFloat(targetx_min, targetx_max);
        float offset_y = RandomFloat(targety_min, targety_max);
        if (aimb::aim_type == 0)
            //SonyDriverHelper::api::MouseMove(static_cast<int>((float)offset_x), static_cast<int>((float)offset_y / 1));
            Inject->set_cursor_position(static_cast<int>((float)offset_x), static_cast<int>((float)offset_y / 1));
        else if (aimb::aim_type == 1)
            memory_event(fvector(-Target.y / 5, Target.x / 5, 0));
    }
    if (aimb::aim_type == 0)
        //SonyDriverHelper::api::MouseMove(static_cast<int>((float)Target.x), static_cast<int>((float)Target.y / 1));
        Inject->set_cursor_position(static_cast<int>((float)Target.x), static_cast<int>((float)Target.y / 1));
    else if (aimb::aim_type == 1)
        memory_event(fvector(-Target.y / 5, Target.x / 5, 0));

}