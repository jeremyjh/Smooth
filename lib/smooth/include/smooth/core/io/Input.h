/*
Smooth - A C++ framework for embedded programming on top of Espressif's ESP-IDF
Copyright 2019 Per Malmberg (https://gitbub.com/PerMalmberg)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include <driver/gpio.h>

namespace smooth::core::io
{
    class Input
    {
        public:
            explicit Input(gpio_num_t io);

            Input(gpio_num_t io,
                  bool pull_up,
                  bool pull_down,
                  gpio_int_type_t interrupt_type = GPIO_INTR_DISABLE);

            bool read();

            Input(const Input&) = delete;

            Input& operator=(const Input&) = delete;

        protected:
            gpio_num_t io;
    };
}