#include "proto_message_maker.h"
#include "tc_message.pb.h"

namespace tc
{

    std::string ProtoMessageMaker::MakeGamepadState(int32_t buttons, int32_t left_trigger, int32_t right_trigger, int32_t thumb_lx,
                                                    int32_t thumb_ly, int32_t thumb_rx, int32_t thumb_ry) {
        tc::Message msg;
        msg.set_type(tc::MessageType::kGamepadState);
        auto gs = msg.mutable_gamepad_state();
        gs->set_buttons(buttons);
        gs->set_left_trigger(left_trigger);
        gs->set_right_trigger(right_trigger);
        gs->set_thumb_lx(thumb_lx);
        gs->set_thumb_ly(thumb_ly);
        gs->set_thumb_rx(thumb_rx);
        gs->set_thumb_ry(thumb_ry);
        return msg.SerializeAsString();
    }

    std::string ProtoMessageMaker::MakeMouseEventFromTouch(int32_t event, uint32_t mon_idx, float x_ratio, float y_ratio) {
        tc::Message msg;
        msg.set_type(tc::MessageType::kMouseEvent);
        auto me = msg.mutable_mouse_event();
        if (event == 0) { // MotionEvent.ACTION_DOWN
            me->set_button(ButtonFlag::kLeftMouseButtonDown);
            me->set_pressed(true);
        } else if (event == 1) { // MotionEvent.ACTION_UP
            me->set_button(ButtonFlag::kLeftMouseButtonUp);
            me->set_released(true);
        } else if (event == 2) { // MotionEvent.ACTION_MOVE
            me->set_button(ButtonFlag::kMouseMove);
        }
        me->set_monitor_index(mon_idx);
        me->set_x_ratio(x_ratio);
        me->set_y_ratio(y_ratio);
        return msg.SerializeAsString();
    }

}
