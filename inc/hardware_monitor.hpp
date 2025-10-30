#pragma once
#include "common.hpp"
#include "thermal_reader.hpp"
#include "codings.hpp"
#include "system_alarm_handler.hpp"

#include <thread>
#include <atomic>

class HardwareMonitor
{
    public:
        HardwareMonitor(ThermalReader& thermal_reader, Codings& codings, SystemAlarmHandler& system_alarm_handler);

        void checkProvidedCoding(int new_value);

        void start();
        void stop();
    
    private:
        ThermalReader &thermal_reader_;
        Codings       &codings_;
        SystemAlarmHandler &system_alarm_handler_;

        std::thread monitor_thread_;
        std::atomic<bool> monitor_running_{false};

        const int monitor_period_ms_{100};
};