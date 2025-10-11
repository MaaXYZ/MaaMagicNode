#include "MaaPluginAPI.h"

#include <meojson/json.hpp>

#include <utility>

uint32_t GetApiVersion()
{
    return 1;
}

void OnResourceEvent(void* handle, const char* message, const char* details_json, void* trans_arg)
{
    std::ignore = handle;
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = trans_arg;
}

void OnControllerEvent(void* handle, const char* message, const char* details_json, void* trans_arg)
{
    std::ignore = handle;
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = trans_arg;
}

void OnTaskerEvent(void* handle, const char* message, const char* details_json, void* trans_arg)
{
    std::ignore = handle;
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = trans_arg;
}

void OnContextEvent(void* handle, const char* message, const char* details_json, void* trans_arg)
{
    std::ignore = handle;
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = trans_arg;
}
