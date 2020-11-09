#pragma once
#include "overlay.h"
#include "overlay_params.h"
#include <functional>
#include <map>
#include <sstream>

class HudElements{
    public:
        struct swapchain_stats *sw_stats;
        struct overlay_params *params;
        float ralign_width;
        float old_scale;
        bool is_vulkan;
        int place;
        std::vector<std::pair<std::string, std::string>> options;
        std::vector<std::pair<void(*)(), std::string >> ordered_functions;
        int min, max, gpu_core_max, gpu_mem_max, cpu_temp_max, gpu_temp_max;
        std::vector<std::string> permitted_params = {
            "gpu_load", "cpu_load", "gpu_core_clock", "gpu_mem_clock",
            "vram", "ram", "cpu_temp", "gpu_temp"
        };
        void sort_elements(std::pair<std::string, std::string> option);
        void legacy_elements();
        static void version();
        static void time();
        static void gpu_stats();
        static void cpu_stats();
        static void core_load();
        static void io_stats();
        static void vram();
        static void ram();
        static void fps();
        static void engine_version();
        static void gpu_name();
        static void vulkan_driver();
        static void arch();
        static void wine();
        static void frame_timing();
        static void media_player();
        static void graphs();
};

extern HudElements HUDElements;