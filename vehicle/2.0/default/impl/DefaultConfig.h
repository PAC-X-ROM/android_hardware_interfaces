/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef android_hardware_vehicle_V2_0_impl_DefaultConfig_H_
#define android_hardware_vehicle_V2_0_impl_DefaultConfig_H_

#include <android/hardware/vehicle/2.0/IVehicle.h>

namespace android {
namespace hardware {
namespace vehicle {
namespace V2_0 {

namespace impl {

const VehiclePropConfig kVehicleProperties[] = {
    {
        .prop = VehicleProperty::INFO_MAKE,
        .access = VehiclePropertyAccess::READ,
        .changeMode = VehiclePropertyChangeMode::STATIC,
        .permissionModel = VehiclePermissionModel::OEM_ONLY,
    },

    {
        .prop = VehicleProperty::HVAC_FAN_SPEED,
        .access = VehiclePropertyAccess::READ_WRITE,
        .changeMode = VehiclePropertyChangeMode::ON_CHANGE,
        .permissionModel = VehiclePermissionModel::NO_RESTRICTION,
        .supportedAreas = static_cast<int32_t>(
            VehicleAreaZone::ROW_1_LEFT | VehicleAreaZone::ROW_1_RIGHT),
        .areaConfigs = init_hidl_vec({
                 VehicleAreaConfig {
                     .areaId = toInt(VehicleAreaZone::ROW_2_LEFT),
                     .minInt32Value = 1,
                     .maxInt32Value = 7},
                 VehicleAreaConfig {
                     .areaId = toInt(VehicleAreaZone::ROW_1_RIGHT),
                     .minInt32Value = 1,
                     .maxInt32Value = 5,
                 }
             }),
    },

    {
        .prop = VehicleProperty::INFO_FUEL_CAPACITY,
        .access = VehiclePropertyAccess::READ,
        .changeMode = VehiclePropertyChangeMode::ON_CHANGE,
        .permissionModel = VehiclePermissionModel::OEM_ONLY,
        .areaConfigs = init_hidl_vec({
                                         VehicleAreaConfig {
                                             .minFloatValue = 0,
                                             .maxFloatValue = 1.0
                                         }
                                     })
    },

    {
        .prop = VehicleProperty::DISPLAY_BRIGHTNESS,
        .access = VehiclePropertyAccess::READ_WRITE,
        .changeMode = VehiclePropertyChangeMode::ON_CHANGE,
        .permissionModel = VehiclePermissionModel::OEM_ONLY,
        .areaConfigs = init_hidl_vec({
                                         VehicleAreaConfig {
                                             .minInt32Value = 0,
                                             .maxInt32Value = 10
                                         }
                                     })
    }
};

}  // impl

}  // namespace V2_0
}  // namespace vehicle
}  // namespace hardware
}  // namespace android

#endif // android_hardware_vehicle_V2_0_impl_DefaultConfig_H_