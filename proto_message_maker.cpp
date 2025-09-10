#include "proto_message_maker.h"
#include "tc_message.pb.h"
#include "tc_message_new/proto_converter.h"

namespace tc
{
    std::string ProtoMessageMaker::s_file_conn_token_ = "file_conn_token";
    std::shared_ptr<Data> ProtoMessageMaker::MakeGamepadState(int32_t buttons, int32_t left_trigger, int32_t right_trigger, int32_t thumb_lx,
                                                    int32_t thumb_ly, int32_t thumb_rx, int32_t thumb_ry, const std::string& device_id, const std::string& stream_id) {
        tc::Message msg;
        msg.set_type(tc::MessageType::kGamepadState);
        msg.set_device_id(device_id);
        msg.set_stream_id(stream_id);
        auto gs = msg.mutable_gamepad_state();
        gs->set_buttons(buttons);
        gs->set_left_trigger(left_trigger);
        gs->set_right_trigger(right_trigger);
        gs->set_thumb_lx(thumb_lx);
        gs->set_thumb_ly(thumb_ly);
        gs->set_thumb_rx(thumb_rx);
        gs->set_thumb_ry(thumb_ry);
        auto buffer = ProtoAsData(&msg);
        return buffer;
    }

    std::shared_ptr<Data> ProtoMessageMaker::MakeMouseEventFromTouch(int32_t event, const std::string& mon_name, float x_ratio, float y_ratio, const std::string& device_id, const std::string& stream_id) {
        tc::Message msg;
        msg.set_type(tc::MessageType::kMouseEvent);
        msg.set_device_id(device_id);
        msg.set_stream_id(stream_id);
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
        me->set_monitor_name(mon_name);
        me->set_x_ratio(x_ratio);
        me->set_y_ratio(y_ratio);
        auto buffer = ProtoAsData(&msg);
        return buffer;
    }

    std::shared_ptr<Message> ProtoMessageMaker::MakeGetFileListMsg(const std::string& path) {
        auto tc_msg = std::make_shared<tc::Message>();
        tc_msg->set_type(tc::kFileOperationEvent);
        tc_msg->set_file_conn_token(s_file_conn_token_);
        auto file_oper_msg = new tc::FileOperateionsEvent();
        file_oper_msg->set_path_of_filelist(path);
        file_oper_msg->set_operate_type(tc::FileOperateionsEvent::kGetFilesList);
        tc_msg->set_allocated_file_operateions_event(file_oper_msg);
        return tc_msg;
    }

    std::shared_ptr<Data> ProtoMessageMaker::MakeChangeMonitor(int index, const std::string& name, const std::string& device_id, const std::string& stream_id) {
        tc::Message m;
        m.set_type(tc::kSwitchMonitor);
        m.set_device_id(device_id);
        m.set_stream_id(stream_id);
        m.mutable_switch_monitor()->set_name(name);
        auto buffer = ProtoAsData(&m);
        return buffer;
    }

    // lock the device
    std::shared_ptr<Data> ProtoMessageMaker::MakeLockDevice(const std::string& device_id, const std::string& stream_id) {
        tc::Message m;
        m.set_type(tc::kLockDevice);
        m.set_device_id(device_id);
        m.set_stream_id(stream_id);
        m.mutable_lock_device();
        auto buffer = ProtoAsData(&m);
        return buffer;
    }

    // stop render
    std::shared_ptr<Data> ProtoMessageMaker::MakeStopRender(const std::string& device_id, const std::string& stream_id) {
        tc::Message m;
        m.set_type(tc::kStopRender);
        m.set_device_id(device_id);
        m.set_stream_id(stream_id);
        m.mutable_stop_render();
        auto buffer = ProtoAsData(&m);
        return buffer;
    }

    // ctrl + alt + delete
    std::shared_ptr<Data> ProtoMessageMaker::MakeCtrlAltDelete(const std::string& device_id, const std::string& stream_id) {
        tc::Message m;
        m.set_type(tc::kReqCtrlAltDelete);
        m.set_device_id(device_id);
        m.set_stream_id(stream_id);
        m.mutable_req_ctrl_alt_delete();
        auto buffer = ProtoAsData(&m);
        return buffer;
    }

}
