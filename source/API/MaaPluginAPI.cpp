#include "MaaPluginAPI.h"

#include <meojson/json.hpp>

#include <utility>

void OnTaskerMessage(const char* message, const char* details_json, void* notify_trans_arg)
{
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = notify_trans_arg;
}

void OnResourceMessage(const char* message, const char* details_json, void* notify_trans_arg)
{
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = notify_trans_arg;
}

void OnControllerMessage(const char* message, const char* details_json, void* notify_trans_arg)
{
    std::ignore = message;
    std::ignore = details_json;
    std::ignore = notify_trans_arg;
}
