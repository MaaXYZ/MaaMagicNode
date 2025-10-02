/**
 * @file MaaDef.h
 * @author
 * @brief The type definitions.
 *
 * @copyright Copyright (c) 2024
 *
 */

// IWYU pragma: private, include <MaaFramework/MaaAPI.h>

#pragma once

#include <stdint.h>

#include "MaaPort.h" // IWYU pragma: export

typedef uint8_t MaaBool;
typedef uint64_t MaaSize;
#define MaaNullSize UINT64_MAX

typedef int64_t MaaId;
typedef MaaId MaaCtrlId;
typedef MaaId MaaResId;
typedef MaaId MaaTaskId;
typedef MaaId MaaRecoId;
typedef MaaId MaaNodeId;
#define MaaInvalidId ((MaaId)0)

typedef struct MaaStringBuffer MaaStringBuffer;
typedef struct MaaImageBuffer MaaImageBuffer;
typedef struct MaaStringListBuffer MaaStringListBuffer;
typedef struct MaaImageListBuffer MaaImageListBuffer;

typedef struct MaaResource MaaResource;
typedef struct MaaController MaaController;
typedef struct MaaTasker MaaTasker;
typedef struct MaaContext MaaContext;

typedef struct MaaRect
{
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
} MaaRect;

/*
 * See MaaMsg.h
 */
typedef void(MAA_CALL* MaaNotificationCallback)(const char* message, const char* details_json, void* notify_trans_arg);

typedef MaaBool(MAA_CALL* MaaCustomRecognitionCallback)(
    MaaContext* context,
    MaaTaskId task_id,
    const char* node_name,
    const char* custom_recognition_name,
    const char* custom_recognition_param,
    const MaaImageBuffer* image,
    const MaaRect* roi,
    void* trans_arg,
    /* out */ MaaRect* out_box,
    /* out */ MaaStringBuffer* out_detail);

typedef MaaBool(MAA_CALL* MaaCustomActionCallback)(
    MaaContext* context,
    MaaTaskId task_id,
    const char* node_name,
    const char* custom_action_name,
    const char* custom_action_param,
    MaaRecoId reco_id,
    const MaaRect* box,
    void* trans_arg);
