/* timestamp.h - Unix timestamp with microsecond resolution */
#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint64_t unix_timestamp_us;
    uint32_t sync_tick_ms;
    uint32_t sync_micros;
    bool synchronized;
    uint32_t sync_count;
    uint32_t last_sync_age_ms;
    uint64_t total_runtime_us;
} Timestamp_t;

extern Timestamp_t g_timestamp;

#define TIMESTAMP_SYNC_INTERVAL_MS      (5 * 60 * 1000)
#define TIMESTAMP_MAX_AGE_MS            (10 * 60 * 1000)

extern TIM_HandleTypeDef htim6;

void Timestamp_Init(void);
void Timestamp_Sync(uint64_t unix_timestamp_us);
uint64_t Timestamp_Get_Current_US(void);
uint64_t Timestamp_Get_Current_MS(void);
uint32_t Timestamp_Get_Current_Seconds(void);
uint32_t Timestamp_Get_Sync_Age_MS(void);
bool Timestamp_Is_Valid(void);
bool Timestamp_Sync_Needed(void);
void Timestamp_Get_String(char *buffer);

static inline uint32_t Timestamp_Get_Fractional_US(void)
{
    uint64_t timestamp_us = Timestamp_Get_Current_US();
    return (uint32_t)(timestamp_us % 1000000ULL);
}

#endif /* TIMESTAMP_H */