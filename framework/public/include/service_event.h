/*
 *Licensed to the Apache Software Foundation (ASF) under one
 *or more contributor license agreements.  See the NOTICE file
 *distributed with this work for additional information
 *regarding copyright ownership.  The ASF licenses this file
 *to you under the Apache License, Version 2.0 (the
 *"License"); you may not use this file except in compliance
 *with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing,
 *software distributed under the License is distributed on an
 *"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 *specific language governing permissions and limitations
 *under the License.
 */
/**
 *
 * @defgroup ServiceListener Service Listener
 * @ingroup framework
 * @{
 *
 *  \author    	<a href="mailto:celix-dev@incubator.apache.org">Apache Celix Project Team</a>
 *  \date      	January 11, 2012
 *  \copyright	Apache License, Version 2.0
 */
#ifndef SERVICE_EVENT_H_
#define SERVICE_EVENT_H_

typedef enum serviceEventType SERVICE_EVENT_TYPE;
typedef struct serviceEvent * SERVICE_EVENT;

#include "service_reference.h"

enum serviceEventType
{
	REGISTEREDA = 0x00000001,
	MODIFIED = 0x00000002,
	UNREGISTERING = 0x00000004,
	MODIFIED_ENDMATCH = 0x00000008,
};

struct serviceEvent {
	SERVICE_REFERENCE reference;
	SERVICE_EVENT_TYPE type;
};

#endif /* SERVICE_EVENT_H_ */

/**
 * @}
 */