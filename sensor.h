// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef __SENSOR_H
#define __SENSOR_H


#ifdef __cplusplus
extern "C" {
#endif

void initSensor(void);
void getNextSample(float* Temperature, float* Humidity);

#ifdef __cplusplus
}
#endif


#endif//__SENSOR_H

