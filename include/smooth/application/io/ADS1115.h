//
// Created by permal on 9/12/17.
//

#pragma once

#include <smooth/core/io/i2c/I2CMasterDevice.h>

namespace smooth
{
    namespace application
    {
        namespace io
        {
            class ADS1115
                    : public smooth::core::io::i2c::I2CMasterDevice
            {
                public:

                    enum Register
                    {
                        Conversion = 0,
                        Config = 1,
                        LowThresh = 2,
                        HighThresh = 3
                    };

                    enum Multiplexer
                    {
                        Diff_AIN0_AIN1 = 0,
                        Diff_AIN0_AIN3 = 1,
                        Diff_AIN1_AIN3 = 2,
                        Diff_AIN2_AIN3 = 3,
                        Single_AIN0 = 4,
                        Single_AIN1 = 5,
                        Single_AIN2 = 6,
                        Single_AIN3 = 7
                    };

                    enum Range
                    {
                        FSR_6_144 = 0,
                        FSR_4_096 = 1,
                        FSR_2_048 = 2,
                        FSR_1_024 = 3,
                        FSR_0_512 = 4,
                        FSR_0_256 = 5
                    };

                    enum OperationalMode
                    {
                        Continuous,
                        SingleShot
                    };

                    enum DataRate
                    {
                        SPS_8 = 0,
                        SPS_16 = 1,
                        SPS_32 = 2,
                        SPS_64 = 3,
                        SPS_128S = 4,
                        SPS_250S = 5,
                        SPS_475S = 6,
                        SPS_860S = 7
                    };

                    enum ComparatorMode
                    {
                        Traditional = 0,
                        Window = 1
                    };

                    enum Alert_Ready_Polarity
                    {
                        ActiveLow = 0,
                        ActiveHigh
                    };

                    enum LatchingComparator
                    {
                        NonLatching = 0,
                        Latching = 1
                    };

                    enum AssertStrategy
                    {
                        AssertAfterOneConversion = 0,
                        AssertAfterTwoConversions = 1,
                        AssertAfterFourConversion = 2,
                        DisableAssertion = 3,
                    };


                    ADS1115(i2c_port_t port, uint8_t address, core::ipc::Mutex& guard);

                    bool configure(Multiplexer mux,
                                   Range range,
                                   OperationalMode op_mode,
                                   DataRate rate,
                                   ComparatorMode comp_mode,
                                   Alert_Ready_Polarity alert_ready_polarity,
                                   LatchingComparator latching,
                                   AssertStrategy assert_strategy);

                    bool read_conversion(const Multiplexer mux, uint16_t& result);
                private:

                    bool configure(const uint16_t config);

                    uint16_t current_config;
            };
        }
    }
}
