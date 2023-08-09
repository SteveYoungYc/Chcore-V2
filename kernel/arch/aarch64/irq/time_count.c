#include <irq/timer.h>
#include <common/kprint.h>
#include <arch/machine/smp.h>

unsigned long long timestamp_enter;
unsigned long long timestamp_exit;

#define WINDOW_SIZE 1000  // 滑动窗口大小
#define START_SIZE 100

u64 values[WINDOW_SIZE] = {0};  // 初始化窗口数据
int index = 0;
int start_count = START_SIZE;
u64 sum = 0;

void sliding_average(u64 current_value) {
    values[index] = current_value;
    index++;
    sum += current_value;
}

void exit() {
    if (start_count > 0) {
        start_count--;
        return;
    }
    if (index >= WINDOW_SIZE)
        return;
    u64 tick = timestamp_exit - timestamp_enter;
    u32 cpuid = smp_get_cpu_id();
    u64 time = plat_tick_to_time(tick);
    sliding_average(time);
    if (cpuid == 0)
        printk("agv: %d, time: %d, idx: %d\n", sum / index, time, index);
}
