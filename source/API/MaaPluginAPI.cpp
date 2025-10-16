#include "MaaPluginAPI.h"

#include <utility>

#include <MaaFramework/MaaAPI.h>
#include <meojson/json.hpp>

#include "ResourceEventHandler/ResourceEventHandler.h"

uint32_t GetApiVersion()
{
    constexpr uint32_t kApiVersion = 1;
    return kApiVersion;
}

void OnResourceEvent(void* handle, const char* message, const char* details_json, void* trans_arg)
{
    MaaResource* res = static_cast<MaaResource*>(handle);

    auto jopt = json::parse(details_json);
    if (!jopt) {
        return;
    }

    ResourceEventHandler::get_instance().on_event(res, message, *jopt);
}

void OnControllerEvent(void* handle, const char* message, const char* details_json, void* trans_arg)
{
    MaaController* ctrl = static_cast<MaaController*>(handle);

    std::ignore = ctrl;
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = trans_arg;
}

void OnTaskerEvent(void* handle, const char* message, const char* details_json, void* trans_arg)
{
    MaaController* tasker = static_cast<MaaController*>(handle);

    std::ignore = tasker;
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = trans_arg;
}

void OnContextEvent(void* handle, const char* message, const char* details_json, void* trans_arg)
{
    MaaContext* ctx = static_cast<MaaContext*>(handle);

    std::ignore = ctx;
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = trans_arg;
}
